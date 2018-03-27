%{
#include <stdio.h>
#include <string.h>
#include "limbaj.tab.h"
#include "utility.h"
extern  int yyerror (char *error);
extern  int  yylex ();
%}
%option noyywrap
%s STR
DIGITS     [0-9]*

%%
"<="                                  {clearChars(yytext,2); return LTE;}
">="                                  {clearChars(yytext,2); return GTE;}
"=="                                  {clearChars(yytext,2); return EQ;}
"!="                                  {clearChars(yytext,2); return NEQ;}
"||"                                  {clearChars(yytext,2); return OR;}
"&&"                                  {clearChars(yytext, 2); return AND;}
"return"                              {return RETURN;}
"continue"                            {return CONTINUE;}
"break"                               {return BREAK;}
"int"|"float"|"bool"                  {yylval.str = copyString(yytext); return TIP_PRED;}
"for"                                 {return FOR;}
"if"                                  {return IF;}
"else"                                {return ELSE;}
"struct"|"class"                      {return STRUCT;}
"while"                               {return WHILE;}
"do"                                  {return DO;}
"print"                               {return PRINT;}
"const"                               {return CONST;}
0|[1-9]{DIGITS}                         {yylval.str=copyString(yytext); return INT_L;}
(0|[1-9]{DIGITS})"."{DIGITS}              {yylval.str=copyString(yytext); return FLOAT_L;}
[_a-zA-Z][_a-zA-Z0-9]*                {yylval.str =copyString(yytext); return ID;}
[ \t]                                 {clearChars(yytext, 1);}
\n {yylineno++;}
.                                     {char r = *yytext; *yytext = '\0'; return r;}

 
