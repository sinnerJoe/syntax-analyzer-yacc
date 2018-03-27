%{
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include "state.h"
#include "print.h"
extern FILE* yyin;
extern char* yytext;
extern int yylineno;
int yyerror(char *s)
{
    printf("Line:%i Error: \"%s\" \n", yylineno, s);
    anyErrors = 1;
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
progr: declaratii 
     ;

bloc_declaratii: '{' declaratii '}'
               ;

declaratii: decl_or_def                  
          | decl_or_def declaratii        
          ; 

decl_membri: declaratie_var ';'                            
            | declaratie_var ';' decl_membri         
            ; 

data_type: ID                         {
             typeCheck($1);
             $$=newTypeStruct($1, 0);
            }   
         | TIP_PRED                   {
             $$=newTypeStruct($1, 0);
            }
         | TIP_PRED '<' INT_L '>'     {
             if(atoi($3) == 0) 
                yyerror("Cannot declare null-sized arrays");
             $$=newTypeStruct($1, 1);
            }
         | ID  '<' INT_L '>'          {
             typeCheck($1);
             if(atoi($3) == 0) 
                yyerror("Cannot declare null-sized arrays");
             $$=newTypeStruct($1, 1);
            }
         ;

decl_or_def: declaratie ';'  
           | definitie       
           ;



declaratie: declaratie_var  { executeDeclGlobal($1); }
          | declaratie_const          { executeDeclGlobal($1);  }
          | data_type ID formal_args  {
              struct function* f = $3;
              f->name = $2;
              f->funcType = $1;
              declareFunction(f);
            }
          | STRUCT ID                 {
              declareUsrType($2);
            }
          ;


declaratie_var: data_type indecl_elems  
                {   //$$-Declaratie
                    $2->type = $1;
                    $2->type->isConst = 0;
                    $$=$2;
                }
              ;

declaratie_const: CONST data_type const_indecl_elems        { //$$-declaratie
                    $3->type = $2;
                    $3->type->isConst = 1;
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
                    }
                  | const_indecl_elem ',' const_indecl_elems  {
                        $$=$3;
                        addDeclVar($1, (bool)1, $$);
                  }
                  ;

indecl_elem: ID                 { $$=newIncompleteVar($1, 0); /*inc*/ }                     
           | ID '=' EXPR        {  $$=newIncompleteVar($1, 1); }
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
                $$ = newFunc();
            }
           | '(' lista_param ')'    {
               $$ = $2;
           }
           ;

definitie:  data_type ID formal_args bloc           {
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
                callFunction($1, $3);
            }
         | ID '(' ')'{ 
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

nested_ref: reference { $$ = $1; }
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
         | PRINT '(' CT_EXPR ')' ';'               { addToPrintQueue($3); }
         | IF '(' EXPR ')' bloc_or_instr
         | IF '(' EXPR ')' bloc_or_instr ELSE bloc_or_instr
         | while_line bloc_or_instr
         | DO bloc while_line ';'
         | FOR '(' declaratie_var ';' EXPR ';' assignment ')' bloc_or_instr 
                {
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


EXPR: nested_ref    { rvalDeref($1);}
    | EXPR '>' EXPR
    | EXPR '<' EXPR                       
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
if(!anyErrors){
    printEverything();
}
} 