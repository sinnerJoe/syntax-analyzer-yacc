%{
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include "state.h"
extern FILE* yyin;
extern char* yytext;
extern int yylineno;
int yyerror(char *s)
{
    printf("Line:%i Error: \"%s\" \n", yylineno, s);
}
int  yylex ();
%}

%union{
    struct variable* var;
    struct function* func;
    struct usr_type* tp;
    char* str;
    struct FormalParameter *fp;
    struct Declaration* decl;
    int ival;
    struct IncompleteVar* inc;
    struct Reference *ref;
    float fl;
};


%token ID FOR WHILE DO FLOAT_L INT_L STRUCT ELSE EQ LTE GTE AND OR IF PRINT NEQ
%token TIP_PRED
%token BREAK CONTINUE RETURN CONST
%nonassoc ';'
%right '=' ','
%left '.'
%left OR  
%left AND
%left LTE GTE '>' '<' EQ  
%nonassoc '!'
%left '+' '-' 
%left '*' '/' '%'
%nonassoc UMINUS
%token PAR
%nonassoc PAR
%start progr
%type <str> ID TIP_PRED INT_L FLOAT_L
%type <func> lista_param formal_args
// %type <var> 
%type <tp> data_type 
%type <fp> param
%type <decl> decl_membri declaratie_var declaratie_const indecl_elems 
%type <decl> const_indecl_elems
%type <ival> lista_apel
%type <str> const_indecl_elem
%type <inc> indecl_elem 
%type <ref> reference nested_ref assignment
%type <fl> CT_EXPR number
%%
progr: declaratii {printf("program corect sintactic\n");}
     ;

bloc_declaratii: '{' declaratii '}'
               ;

declaratii: decl_or_def                    {/*printf("decl_Or_def");*/}
          | decl_or_def declaratii         {/*printf("declaratii\n");*/}
          ; 

decl_membri: declaratie_var ';'                            
            | declaratie_var ';' decl_membri         
            ; 

data_type: ID                         {
             typeCheck($1);
             printf("Type %s", $1); 
             $$=newTypeStruct($1, 0);
            }   
         | TIP_PRED                   {
             printf("Type %s", $1); 
             $$=newTypeStruct($1, 0);
            }
         | TIP_PRED '<' INT_L '>'     {
             printf("Array of type %s and size %s\n", $1, $3);
             printf("cond=%i\n", $3[strlen($3)] == '\0');
             if(atoi($3) == 0) 
                yyerror("Cannot declare null-sized arrays");
             printf("after if\n");
             $$=newTypeStruct($1, 1);
            }
         | ID  '<' INT_L '>'          {
             typeCheck($1);
             printf("Array of type %s and size %s\n", $1, $3);
             if(atoi($3) == 0) 
                yyerror("Cannot declare null-sized arrays");
             printf("after if\n");
             $$=newTypeStruct($1, 1);
            }
         ;

decl_or_def: declaratie ';'   { /*printf(" -> decl \n"); */  }
           | definitie        { /*printf(" -> def \n");  */  }
           ;



declaratie: declaratie_var  {
                            printf("declaratie_var\n");
                            executeDeclGlobal($1);
                            printf(" afterdecl\n");
                }
          | declaratie_const          {
                            printf("declaratie_const\n");
                            executeDeclGlobal($1);
                            printf("afterdecl\n");

                }
          | data_type ID formal_args  {
              printf("declaratie_func\n");
              struct function* f = $3;
              printf("decl func paramCount = %i\n", $3->argCount);
              f->name = $2;
              f->funcType = $1;
              declareFunction(f);
            }
          | STRUCT ID                 {
              printf("struct %s\n", $2);
              declareUsrType($2);
            }
          ;


declaratie_var: data_type indecl_elems  
                {   //$$-Declaratie
                    printf("declaratie_var");
                    $2->type = $1;
                    $2->type->isConst = 0;
                    $$=$2;
                }
              ;

declaratie_const: CONST data_type const_indecl_elems        { //$$-declaratie
                    $3->type = $2;
                    $3->type->isConst = 1;
                    printf(" $3->type->isConst = %i", $3->type->isConst);
                    $$=$3;
}
                ;
                
const_indecl_elem: ID '=' EXPR {
                    $$=$1;
                 }
                 ;

const_indecl_elems: const_indecl_elem   {
                        $$ = calloc(1, sizeof(Declaration));
                        addDeclVar($1, (bool)1, $$);
                        printf("c_i_e: Count: %i", $$->count);
                    }
                  | const_indecl_elem ',' const_indecl_elems  {
                        $$=$3;
                        addDeclVar($1, (bool)1, $$);
                        printf("c_i_e,c_i_es: Count: %i", $$->count);
                  }
                  ;

indecl_elem: ID                     { 
                    
                    $$=newIncompleteVar($1, 0); /*inc*/ printf("indecl_elem: %s ", $1);
                    }                     
           | ID '=' EXPR            { 
                    $$=newIncompleteVar($1, 1); printf("%s = EXPR\n", $1); }
           ;

indecl_elems: indecl_elem { //$$-declaration
                $$ = calloc(1, sizeof(Declaration));
                addDeclVar($1->name, (bool)$1->initialized, $$);
            }
            | indecl_elem  ',' indecl_elems     {
                addDeclVar($1->name, (bool)$1->initialized, $3);
                $$=$3;
            }
            ;

formal_args: '(' ')'    {
                printf("void parameters\n");
                $$ = newFunc();
            }
           | '(' lista_param ')'    {
               $$ = $2;
               printf("lista_param %i\n", $2->argCount);
           }
           ;

definitie:  data_type ID formal_args bloc           {
                printf("def func\n");
                struct function* f = $3;
                f->name = $2;
                f->funcType = $1;
                defineFunction(f);
                }
         |  STRUCT ID '{' decl_membri '}' ';'       {
             defineUsrType($2);
         }
         ; 




lista_param: param  { //function
                struct function * func =  newFunc();
                addParam($1, func);
                $$=func;
            }
           | param ','  lista_param {
               addParam($1, $3);
               $$=$3;
           }
           ;

param: data_type ID { // FormalParameter
        printf("param\n");
        $$ = calloc(1, sizeof(FormalParameter));
        $$->name = $2;
        $$->tp = $1;
     }
     ; 
      
/* bloc */
bloc: '{' lista_instr '}'
    ;

bloc_or_instr: statement
             | bloc
             ;


     
/* lista instructiuni */
lista_instr: statement 
           | lista_instr statement 
           ;

apel_func: ID '(' lista_apel ')'{
                printf("apel %s cu %i par\n", $1, $3);
                callFunction($1, $3);
            }
         | ID '(' ')'{ 
             printf("apel %s fara par\n", $1);
             callFunction($1, 0);
         }
         ;

lista_apel: EXPR    {$$=1;}
          | EXPR ',' lista_apel   {$$=$3+1;}
          ;

while_line: WHILE '(' EXPR ')'
          ;

reference: ID { $$ = malloc(sizeof(struct Reference)); $$->name = $1;  $$->indexed = 0; }
         | ID '[' EXPR ']' { $$ = malloc(sizeof(struct Reference)); $$->name = $1;  $$->indexed = 1;}
         ;

nested_ref: reference  { $$ = $1; }
          | reference '.' nested_ref {
            $$=$1;
          }
          ;

/* instructiune */
statement: EXPR ';'
         | declaratie_var ';'                    { 
             executeDeclLocal($1);                }
         | apel_func ';'
         | assignment ';' { assign($1->name, $1->indexed); }
         | PRINT '(' CT_EXPR ')' ';'               { printf("PRINT: %.2f\n", $3); }
         | IF '(' EXPR ')' bloc_or_instr
         | IF '(' EXPR ')' bloc_or_instr ELSE bloc_or_instr
         | while_line bloc_or_instr
         | DO bloc while_line ';'
         | FOR '(' declaratie_var ';' EXPR ';' assignment ')' bloc_or_instr 
                {
                    printf("FOR LOOP\n");
                    executeDeclLocal($3);
                    assign($7->name, $7->indexed);
                }
         | BREAK ';'
         | CONTINUE ';'
         | RETURN ';'
         | RETURN EXPR ';'
         ;

assignment: nested_ref '=' EXPR {
                $$=$1;
            }
          ;


EXPR: nested_ref    { rvalDeref($1); printf("After deref\n"); }
    | EXPR '>' EXPR
    | EXPR '<' EXPR                        { printf("Less than\n"); }
    | EXPR LTE EXPR
    | EXPR GTE EXPR
    | EXPR EQ EXPR
    | EXPR OR EXPR
    | EXPR AND EXPR
    | number
    | apel_func
    | '(' EXPR ')' %prec PAR
    | '!' EXPR
    | EXPR '+' EXPR
    | '-' EXPR %prec UMINUS
    | EXPR '-' EXPR
    | EXPR '*' EXPR
    | EXPR '/' EXPR
    | EXPR '%' EXPR
    ;

CT_EXPR:CT_EXPR '>' CT_EXPR         {$$ =  $1 > $3;}
    | CT_EXPR '<' CT_EXPR           {$$ = $1 < $3; }
    | CT_EXPR LTE CT_EXPR           {$$ = $1 <= $3; }
    | CT_EXPR GTE CT_EXPR           {$$ = $1 >= $3; }
    | CT_EXPR EQ CT_EXPR            {$$ = $1 == $3; }
    | CT_EXPR OR CT_EXPR            {$$ = ($1!=0) || ($3!=0); }
    | CT_EXPR AND CT_EXPR           {$$ = ($1!=0) && ($3!=0); }
    | number                        {$$ = $1;}
    | '(' CT_EXPR ')'               {$$ = $2;}
    | '!' CT_EXPR                   {$$ = $2==0;}
    | CT_EXPR '+' CT_EXPR           {$$ = $1 + $3;}
    | '-' CT_EXPR %prec UMINUS      {$$ = -$2;}
    | CT_EXPR '-' CT_EXPR           {$$ = $1 - $3;}
    | CT_EXPR '*' CT_EXPR           {$$ = $1 * $3;}
    | CT_EXPR '/' CT_EXPR           {$$ = $1 / $3;}
    | CT_EXPR '%' CT_EXPR           {$$ = (int)$1 % (int)$3;}
    ;

number: INT_L {$$ = atoi($1);}
      | FLOAT_L  {$$ = atof($1);}
      ;


%%


int main(int argc, char** argv){
yyin=fopen(argv[1],"r");
yyparse();
checkUndefinedFunctions();
checkUndefinedTypes();
} 