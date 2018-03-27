#include "string.h"
#include "malloc.h"
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
extern int yylineno;

typedef char bool;

bool anyErrors = 0;

int serror(const char *s)
{
    printf("Line:%i Error: \"%s\" \n", yylineno, s);
    anyErrors = 1;
    // exit(1);
}


struct Reference {
    char * name;
    bool indexed;
};

struct IncompleteVar{
    bool initialized;
    char *name; 
};
struct type_struct{
    bool isArray;
    char *typeName;
    bool isConst;
};

struct variable{
    bool isArray;
    char* name;
    bool isConst;
    bool initialized;
};

typedef struct FormalParameter{
    char * name;
    struct type_struct *tp; 
} FormalParameter;

typedef struct Declaration{
    bool isArray;
    struct type_struct* type;
    char* names[20];
    bool initialized[20];
    int count;
} Declaration;

struct local_stack
{
    struct variable vars[100];
    int varcount;
    int problemCount;
    struct Reference * notFound[100];
};

struct function
{
    char *name;
    FormalParameter *arguments[15];
    int argCount;
    bool defined;
    struct type_struct *funcType;
    bool used;
};

struct usr_type
{
    char *name;
    bool defined;
    char *member[50];
    int memberCount;
    bool used;
};


struct variable v_glob[500];
int v_glob_size = 0;

struct function * functions[200];
int functionCount = 0;
struct usr_type * usrTypes[200];
int typeCount = 0;
struct local_stack fStack;

void resetStack(){
    memset(&fStack, 0, sizeof(fStack));
}


bool isVarInList(char* name, struct variable* list, int size){
    for(int i=0; i<size; i++){
        if(strcmp(list[i].name, name)==0)
            return 1;
    }
    return 0;
}

bool isTypeDeclared(char *name)
{
    for (int i = 0; i < typeCount; i++)
    {
        if (strcmp(usrTypes[i]->name, name) == 0)
            return 1;
    }

    return 0;
}

bool isGlobalDeclared(char *name){
    return isVarInList(name, v_glob, v_glob_size);
}

bool isLocalDeclared(char *name){
    return isVarInList(name, fStack.vars, fStack.varcount);
}

struct function* getFunc(char *name){
    for(int i =0; i< functionCount; i++){
        if(strcmp(functions[i]->name, name) == 0)
            return functions[i];
    }
    return NULL;
}

struct function *getFunction(char *name, struct function *start)
{
    int init = 0;
    if (start != NULL)
    {
        for (init = 0; init < functionCount; init++)
            if (functions[init] == start)
                break;
    }
    for (int i = init + 1; i < functionCount; i++)
    {
        if (strcmp(functions[i]->name, name) == 0)
            return functions[i];
    }
    return NULL;
}

bool isFunctionDeclared(char *name){
    return NULL != getFunc(name);
}


void variableDeclaredError(char* name){
    char error[100] = "The variable named ";
    strcat(error, name);
    strcat(error, " is already declared");
    serror(error);
}



void addLocalVar(char * name, bool isConst, bool isArray, bool initialized){
    if(isLocalDeclared(name)){
        variableDeclaredError(name);
    }

    fStack.vars[fStack.varcount].isArray = isArray;
    fStack.vars[fStack.varcount].isConst = isConst;
    fStack.vars[fStack.varcount].name = name;
    fStack.vars[fStack.varcount].initialized = initialized;
    fStack.varcount++;
}

void addGlobalVar(char * name, bool isConst, bool isArray, bool initialized){
    if(isGlobalDeclared(name)){
        variableDeclaredError(name);
    }
    v_glob[v_glob_size].isArray = isArray;
    v_glob[v_glob_size].isConst = isConst;
    v_glob[v_glob_size].name = name;
    v_glob[v_glob_size].initialized=initialized;
    v_glob_size++;

}



void transferFstack(){
    for(int i=0; i<fStack.varcount; i++){
        addGlobalVar(fStack.vars[i].name, fStack.vars[i].isConst, fStack.vars[i].isArray, fStack.vars[i].initialized);
    }
    resetStack();
}

bool sameSignature(struct function* f1, struct function *f2){
    if(f1->argCount != f2->argCount)
        return 0;
    bool sameNames = 1;
    for(int i=0; i<f1->argCount; i++){
        bool sameType = strcmp(f1->arguments[i]->tp->typeName, f2->arguments[i]->tp->typeName) == 0;
        bool bothArrays = f1->arguments[i]->tp->isArray == f1->arguments[i]->tp->isArray;
        if (!sameType || !bothArrays) return 0;
        if (strcmp(f1->arguments[i]->name, f2->arguments[i]->name) != 0){
            sameNames = 0;
        }
    }
    

    if(strcmp(f1->funcType->typeName, f2->funcType->typeName) != 0 || 
                f1->funcType->isArray != f2->funcType->isArray)
        return -2;
    else if(!sameNames)
        return -1;
    else 
        return 1;
}


struct function * declareFunction(struct function *func)
{
    bool alreadyDeclared = 0;
    struct function* theFunc = getFunction(func->name, NULL);
    while(theFunc != NULL){
        if(sameSignature(func, theFunc)!=0){
            alreadyDeclared = 1;
            break;
        }
        theFunc = getFunction(func->name, theFunc);
    }
    if(alreadyDeclared){
        char error[100] = "Function ";
        strcat(error, func->name);
        strcat(error, " has been already declared");
        serror(error);
        return NULL;
    } else {
    functions[functionCount] = func;
    functionCount++;
    return func;
    }
}

void addDeclVar(char *name, bool initialized, Declaration *decl );

void dereference(char *name);

void declareArguments(struct function * func){
    for(int i=0; i<func->argCount; i++){
            addLocalVar(func->arguments[i]->name, 0, func->arguments[i]->tp->isArray, 1);
    }

    for(int i=0; i<fStack.problemCount; i++){
        dereference(fStack.notFound[i]->name);
    }

    resetStack();
}
void defineFunction(struct function* func){
    struct function* theFunc = getFunction(func->name, NULL);
    while(theFunc != NULL){
        bool comp = sameSignature(func, theFunc);
        if(comp==-1){
            char err[100] = "The definition of function ";
            strcat(err, func->name);
            strcat(err, " has different argument names than it's declaration");
            serror(err);
            return;
        }
        else if(comp==-2){
            char err[100] = "The definition of function ";
            strcat(err, func->name);
            strcat(err, " has different return type than it's declaration");
            serror(err);
            return;
        }
        else if(comp == 1 && theFunc->defined){
                char err[100] = "Function ";
                strcat(err, theFunc->name);
                strcat(err, " has been already defined.");
                serror(err);
                return;
        }
        else if(comp == 1){
            declareArguments(func);
            memcpy(theFunc, func, sizeof(struct function));
            theFunc->defined = 1;
            return;
        }
        theFunc = getFunction(func->name, theFunc);
    }
    declareFunction(func);
    declareArguments(func);
    func->defined = 1;
}

void dereference(char *name){
    if(!isLocalDeclared(name) && !isGlobalDeclared(name)){
        char error[100] = "Variable named ";
        strcat(error, name);
        strcat(error, " doesn't exist");
        serror(error);
    }
}

struct variable * getVar(char * name){
    for(int i=0; i<fStack.varcount; i++){
        if(strcmp(fStack.vars[i].name, name)==0){
            return &fStack.vars[i];
        }
    }
    for(int i=0; i<v_glob_size; i++){
        if(strcmp(v_glob[i].name, name)==0){
            return &v_glob[i];
        }
    }
    return NULL;
}



void rvalDeref(struct Reference * ref){
    bool localDec = isLocalDeclared(ref->name);
    bool globalDec = isGlobalDeclared(ref->name);
    if (!localDec && !globalDec){
        fStack.notFound[fStack.problemCount++] = ref;
    }
    else if(!ref->indexed){
        struct variable *var = getVar(ref->name);
        if (!var->initialized)
        {
            char err[100] = "Variable ";
            strcat(err, ref->name);
            strcat(err, " is used without being initialized");
            serror(err);
        }
    }
}



void assign(char * name, bool indexed){
    dereference(name);
    if(!indexed){
        struct variable * var = getVar(name);
        if(var->isConst){
            char err[100] = "Cannot assign to const variable ";
            strcat(err, name);
            serror(err);
        }
        else
            var->initialized=1;
    }
}

void checkFunction(char *name){
    if (!isLocalDeclared(name) && !isGlobalDeclared(name))
    {
        char error[100] = "Variable named ";
        strcat(error, name);
        strcat(error, " doesn't exist");
        serror(error);
    }
}

struct type_struct *newTypeStruct(char *name, bool isArray)
{
    struct type_struct* res = (struct type_struct*) calloc(1, sizeof(struct type_struct));
    res->typeName = name;
    res->isArray=isArray;
    return res;
}

struct function *newFunc(){
    struct function *res = (struct function*)calloc(1, sizeof(struct function));
    res->argCount=0;
    res->used =0;
    res->defined = 0;
    return res;
}

struct usr_type *newUsrType(){
    struct usr_type *res = (struct usr_type*)calloc(1, sizeof(struct usr_type));
    res->memberCount=0;
    res->used =0;
    res->defined = 0;
    return res;
}

void declareUsrType(char * name){
    if(isTypeDeclared(name)){
        char error[100] = "Struct ";
        strcat(error, name);
        strcat(error, " has been already declared");
        serror(error);
        return;
    }
    struct usr_type* newT = newUsrType();
    newT->name = name;
    newT->defined=0;
    usrTypes[typeCount] = newT;
    typeCount ++;
}

struct usr_type * getType(char * name){
    for(int i=0; i<typeCount; i++){
        if(strcmp(usrTypes[i]->name, name)==0){
            return usrTypes[i];
        }
    }
    return NULL;
}

void typeCheck(char * name){
    struct usr_type * tp = getType(name);
    if(tp!=NULL){
        tp->used=1;
    }
    else{
        char arr[100] = "Unknown type ";
        strcat(arr, name);
        serror(arr);
    }
}

void defineUsrType(char * name){
    struct usr_type * search = getType(name);

    if(search == NULL){
        search = newUsrType();
        
        search->name=name;
        search->used=0;
        usrTypes[typeCount] = search;
        typeCount++;
    }
    else if(search->defined){
        char  error[100] = "Struct ";
        strcat(error, name);
        strcat(error, " has been already defined");
        serror(error);
    }
    search->defined = 1;
}

void addDeclVar(char *name, bool initialized, Declaration *decl )
{
    decl->names[decl->count] = name;
    decl->initialized[decl->count] = initialized;
    decl->count++;
}

void executeDeclGlobal(Declaration *decl)
{
    for (int i = 0; i < decl->count; i++)
    {
        addGlobalVar(decl->names[i], decl->type->isConst, decl->isArray, decl->initialized[i]);
    }
}

void executeDeclLocal(Declaration *decl)
{
    for (int i = 0; i < decl->count; i++)
    {
        addLocalVar(decl->names[i], decl->type->isConst, decl->isArray, decl->initialized[i]);
    }
}

void addParam(FormalParameter *param, struct function* func){
    for(int i=0; i<func->argCount; i++){
        if(strcmp(func->arguments[i]->name, param->name)==0){
            serror("Function already has a parameter with the same name.");
            return;
        }
    }
    func->arguments[func->argCount] = param;
    func->argCount++;
}



void callFunction(char * name, int nr_args){
    struct function *f = getFunction(name, NULL);
    if (!f)
    {
        char error[100] = "Function ";
         strcat(error, name);
        strcat(error, " hasn't been declared.");
        serror(error);
        return;
    }
    bool noMatch = 1;
    while(f){
        if(f->argCount==nr_args){
            noMatch = 0;
            break;
        }
        f = getFunction(name, f);
    }
    
    if(noMatch)
    {
        char error[100] = "Function ";
        strcat(error, name);
        strcat(error, " was called with wrong number of actual parameters.");
        serror(error);
    }
    else
        f->used = 1;
}

struct IncompleteVar * newIncompleteVar(char * name, bool init){

    struct IncompleteVar *res = (struct IncompleteVar*)malloc(sizeof(struct IncompleteVar));
    res->name = name;
    res->initialized = init;
    return res;
}

void checkUndefinedFunctions(){
    for (int i =0; i<functionCount; i++){
        if(functions[i]->used && !functions[i]->defined){
            char err[100] = "Function ";
            strcat(err, functions[i]->name);
            strcat(err, " was called but not defined.");
            printf("ERROR: %s\n", err);
            anyErrors = 1;
        }
    }
}

void checkUndefinedTypes()
{
    for (int i = 0; i < typeCount; i++)
    {
        if (usrTypes[i]->used && !usrTypes[i]->defined)
        {
            char err[100] = "Type ";
            strcat(err, usrTypes[i]->name);
            strcat(err, " was used but not defined.");
            printf("ERROR: %s\n", err);
            anyErrors = 1;
        }
    }
}