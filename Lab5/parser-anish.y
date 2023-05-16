%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.tab.h"
int yylex(void);
int yyerror(char *);
#define MAX 30
char t[MAX];
char sym_tab[MAX][2][MAX];
int count = 0;
void add_sym_tab(char name[], char type[]);
int look_up(char name[]);
char lhs[MAX];
%}

%union {
    char str[5];
};

%token<str> ID
%token INT_CONST BOOLEAN FLOAT_CONST INT FLOAT SEMICOLON COMMA ASSIGN IF ELSE AND OR NOT EQ GE LE LT GT NE WHILE RETURN FOR ELSE_IF
%%
prog : funcDef { printf("Accepted count: %d\n", count); }
funcDef : type ID '(' argList ')' '{' declList stmtList'}' 
argList : arg ',' arg | arg | ;
arg : type ID { printf("arg \n"); printf("id name %s\n", $2); add_sym_tab($2, t); printf("arg \n");}
type : INT {strcpy(t, "INT"); }|FLOAT {strcpy(t, "FLOAT");  } | BOOLEAN {strcpy(t, "BOOLEAN"); }
declList : decl SEMICOLON declList | ;
decl : type varList;
varList : ID COMMA varList {add_sym_tab($1, t);}| ID {add_sym_tab($1, t);};
stmtList : stmtList stmt | stmt;
stmt : assignStmt | ifStmt | whileStmt | elseStmt | forStmt | elseifStmt;
assignStmt : ID {strcpy(lhs, $1); printf("lhs is %s\n", $1);} '=' EXP {printf("YES\n");} SEMICOLON ; 
EXP : EXP '+' TERM  | EXP '-' TERM  | TERM;
TERM : TERM '*' FACTOR  | TERM '/' FACTOR | FACTOR;
FACTOR : ID {if(look_up($1)==-1) printf("ERROR: undeclared variable found\n"); else if(strcmp(sym_tab[look_up($1)][1], sym_tab[look_up(lhs)][1])!=0) printf("ERROR: found type %s when expecting %s \n", sym_tab[look_up($1)][1], sym_tab[look_up(lhs)][1]); }| INT_CONST ;
ifStmt : IF '(' bExp ')' '{'{printf("YES\n");} stmtList '}';
elseifStmt : ELSE_IF '(' bExp ')' '{' stmtList '}';
elseStmt : ELSE '{' stmtList '}';
bExp : EXP RELOP EXP;
bExp : bExp LOGOP bExp;
LOGOP : AND | OR | NOT;
RELOP : EQ | GE | LE | LT | GT | NE;
whileStmt : WHILE '(' bExp ')' '{' stmtList '}' ; 
forStmt : FOR '(' ID '=' EXP SEMICOLON bExp SEMICOLON ID '=' EXP')' '{' stmtList '}' 
%%

int main()
{
    yyparse();
    for(int i=0; i<count; i++) {
        printf("name: %s type: %s\n", sym_tab[i][0], sym_tab[i][1]);
    }
}

int yyerror(char *s)
{
    printf(stderr, "Error in the parser : %s\n", s);
}

void add_sym_tab(char *name, char *type)
{
    if(look_up(name) != -1){
        printf("found in %s symtable\n", name);
    }
    else{
        printf("not found, added %s to sym table\n", name);
    strcpy(sym_tab[count][0], name);
    strcpy(sym_tab[count][1], type);
    count++;
    }
}

int look_up(char *name){
    for(int i=0; i<count; i++) {
        if(strcmp(name, sym_tab[i][0]) == 0) {
            return i;
        }
    }
    return -1;
}
