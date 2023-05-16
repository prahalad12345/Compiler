%{
#include <stdio.h>
#include <string.h>
#include "parser.tab.h"
int yylex(void);
int yyerror(char *);
char t[10];
char vbltable[31][10];
char varname[31][10];
int i=0;
char tempp[10];
int checkexist(char *);
%}

%token  BOOL INT FLOAT SEMICOLON COMMA INTEGER_CONSTANT FLOAT_CONSTANT IF ELSE LOGOP RELOP FOR WHILE ELSEIF 

%union {
    char vblno[10];
};

%token <vblno>ID

%%
prog : funcDef { printf("Done\n"); }
funcDef : type ID '(' argList ')' '{' declList stmtList'}'
argList : arg COMMA arg | ;
arg : type ID {strcpy(vbltable[i],t);strcpy(varname[i],$2);i++;};
type : INT  {strcpy(t,"int");printf("YEAHHH int\n");}|FLOAT {strcpy(t,"float");printf("YEAHHH float\n");}|BOOL {strcpy(t,"boolean");printf("YEAHHH boolean\n");};
declList : decl SEMICOLON declList | ;
decl : type varList;
varList : ID COMMA varList {strcpy(vbltable[i],t);strcpy(varname[i],$1);i++;};| ID {strcpy(vbltable[i],t);strcpy(varname[i],$1);i++;};
stmtList : stmtList stmt | stmt;
stmt : assignStmt | ifStmt | whileStmt | ifelseStmt | ifelseifStmt | forStmt ;
assignStmt : ID '=' EXP SEMICOLON {if(checkexist($1)==1)printf("\nWarning: Not declared\n");else strcpy(tempp,vbltable[checkexist($1)]);};
EXP : EXP '+' TERM | EXP '-' TERM | TERM;
TERM : TERM '*' FACTOR | TERM '/' FACTOR | FACTOR;
FACTOR : ID {if(checkexist($1)==1)printf("\nError: %s Not declared\n",$1);else if(strcmp(vbltable[checkexist($1)],tempp)!=0)printf("Warning operation on %s on type  %s are of two different types",$1,tempp);}| INTEGER_CONSTANT {if(strcmp("int",tempp)!=0)printf("Warning operation on int on type  %s are of two different types",tempp);};
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
    for(int j=0;j<i;j++){
        printf("%s %s\n",vbltable[j],varname[j]);
    }
}

int checkexist(char* name){
    printf("Checker %s",name);
    for(int j=0;j<i;j++){
        if(strcmp(name,varname[j])==0){
            return 0;
        }
    }
    return 1;
}


