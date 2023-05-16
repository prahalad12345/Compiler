%{
#include <stdio.h>
#include "parser.tab.h"
int yylex(void);
int yyerror(char *);
%}

%token ID INT FLOAT SEMICOLON COMMA INTEGER_CONSTANT FLOAT_CONSTANT IF ELSE LOGOP RELOP FOR WHILE ELSEIF 

%%
prog : funcDef { printf("Done\n"); }
funcDef : type ID '(' argList ')' '{' declList stmtList'}'
argList : arg ',' arg | ;
arg : type ID;
type : INT|FLOAT;
declList : decl SEMICOLON declList | ;
decl : type varList;
varList : ID COMMA varList | ID;
stmtList : stmtList stmt | stmt;
stmt : assignStmt | ifStmt | whileStmt | ifelseStmt | ifelseifStmt | forStmt ;
assignStmt : ID '=' EXP SEMICOLON;
EXP : EXP '+' TERM | EXP '-' TERM | TERM;
TERM : TERM '*' FACTOR | TERM '/' FACTOR | FACTOR;
FACTOR : ID | INTEGER_CONSTANT;
ifStmt : IF '(' bExp ')' '{' stmtList '}' {printf("if detected\n");};
ifelseStmt : IF '(' bExp ')' '{' stmtList '}' ELSE '{' stmtList '}' {printf("if else detected\n");};
ifelseifStmt : IF '(' bExp ')' '{' stmtList '}' ELSEIF '(' bExp ')' '{' stmtList '}' ELSE '{' stmtList '}' {printf("if else if detected\n");};
bExp : EXP RELOP EXP | EXP LOGOP EXP {printf("Expression detected\n");};
whileStmt : WHILE '(' bExp ')' '{' stmtList '}' ; 
forStmt : FOR '(' ID '=' EXP SEMICOLON bExp SEMICOLON ID '=' EXP')' '{' stmtList '}' {printf("for loop\n");} 
%%

int main()
{
    yyparse();
}
