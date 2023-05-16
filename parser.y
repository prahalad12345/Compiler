%{
#include <stdio.h>
#include <string.h>
#include "parser.tab.h"
int yylex(void);
int yyerror(char *);
char t[10];
char vbltable[31][10];
char varname[31][10];
char lines[70][31][10];
int k=0;
int i=0;
int id=0;
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
stmt : declrassignStmt {k++;id=0;} | assignStmt {k++;id=0;}| ifStmt {k++;id=0;}| whileStmt {k++;id=0;}| ifelseStmt {k++;id=0;}| ifelseifStmt {k++;id=0;}| forStmt {k++;id=0;};
assignStmt : ID '=' EXP SEMICOLON {if(checkexist($1)==-1)printf("\nError: Not declared\n");else{strcpy(lines[k][id],varname[checkexist($1)]);id++;strcpy(lines[k][id],vbltable[checkexist($1)]);id++;}};
declrassignStmt : type ID '=' EXP SEMICOLON {if(checkexist($2)==-1)printf("\nError: Not declared\n");else{strcpy(lines[k][id],varname[checkexist($2)]);id++;strcpy(lines[k][id],vbltable[checkexist($2)]);id++;}};
EXP : EXP '+' TERM | EXP '-' TERM | TERM;
TERM : TERM '*' FACTOR | TERM '/' FACTOR | FACTOR;
FACTOR : ID {if(checkexist($1)==-1)printf("\nError: %s Not declared\n",$1);else{strcpy(lines[k][id],varname[checkexist($1)]);id++;strcpy(lines[k][id],vbltable[checkexist($1)]);id++;}}| INTEGER_CONSTANT;
ifStmt : IF '(' bExp ')' '{' stmtList '}' {printf("if detected\n");};
ifelseStmt : IF '(' bExp ')' '{' stmtList '}' ELSE '{' stmtList '}' {printf("if else detected\n");};
ifelseifStmt : IF '(' bExp ')' '{' stmtList '}' ELSEIF '(' bExp ')' '{' stmtList '}' ELSE '{' stmtList '}' {printf("if else if detected\n");};
bExp : EXP RELOP EXP {k++;id=0;}| EXP LOGOP EXP {printf("Expression detected\n");k++;id=0;};
whileStmt : WHILE '(' bExp ')' '{' stmtList '}' ; 
forStmt : FOR '(' ID '=' EXP SEMICOLON bExp SEMICOLON ID '=' EXP')' '{' stmtList '}' {printf("for loop\n");} 
%%

int main()
{
    yyparse();
    for(int j=0;j<i;j++){
        printf("%s %s\n",vbltable[j],varname[j]);
    }
    for(int j=0;j<=k;j++){
        for(int m=1;lines[j][m][0]!='\0';m+=2){
            printf("%s %s ",lines[j][m-1],lines[j][m]);
            if(strcmp(lines[j][1],lines[j][m])!=0){
                //printf("%d Warning: performing operation on %s , %s . %s %s are different types\n",j,lines[j][0],lines[j][m-1],lines[j][1],lines[j][m]);
            }
        }
        printf("\n");
    }
    for(int j=0;j<=k;j++){
        for(int m=1;lines[j][m][0]!='\0';m+=2){
            if(strcmp(lines[j][1],lines[j][m])!=0){
                printf("%d Warning: performing operation on %s , %s . %s %s are different types\n",j,lines[j][0],lines[j][m-1],lines[j][1],lines[j][m]);
            }
        }
        printf("\n");
    }
}

int checkexist(char* name){
    printf("Checker %s",name);
    for(int j=0;j<i;j++){
        if(strcmp(name,varname[j])==0){
            return j;
        }
    }
    return -1;
}


