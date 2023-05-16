%{
#include <stdio.h>
#include "parser.tab.h"
int yylex(void);
int yyerror(char *);
%}

%token ID INT FLOAT SEMICOLON COMMA  INTEGER_CONSTANT FLOAT_CONSTANT ASSIGN IF ELSE AND NOT EQ GE L LT GT NE WHILE RETURN 

%%
prog : funcDef ;
funcDef : type ID '(' argList ')' '{' declList  stmtList'}'  ;
argList : arg COMMA arg | ;
arg : type ID ;
declList : decl SEMICOLON declList | ;
decl : type varList ; 
varList : ID COMMA varList | ID ; 
type : INT | FLOAT ;          
stmtList : ;
%%

int main()
{
    yyparse();
}
