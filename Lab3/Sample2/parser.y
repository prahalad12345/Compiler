%{
#include <stdio.h>
#include "parser.tab.h"
int yylex(void);
int yyerror(char *);
%}
%token ID INT_CONST 
%%
prog : funcDef { printf("Accepted\n"); }
funcDef : INT_CONST ID '(' argList ')' '{' declList '}' { printf("1\n"); }
argList : arg ',' arg | { printf("2\n"); };
arg : INT_CONST ID { printf("3\n"); };
declList :  
%%

int main()
{
    yyparse();
}
