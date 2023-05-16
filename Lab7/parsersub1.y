%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "parser.tab.h"
int yylex(void);
int yyerror(char *);
char t[10];

FILE *fp;

char number;
int k=0;
int i[20]={0};//20 depth blocks accepted
int l=0;
int id=0;
char adder[100];
int checkexist(char *);
struct Node{
    char vbltable[31][10];
    char varname[31][10];
    struct Node* next;
    struct Node* prev;
};

//tmperory
int tmpid=1;

char *typereturner(struct Node*,char *);

struct Node *typestorer;
struct Node *end;
%}

%token  BOOL INT FLOAT SEMICOLON COMMA FLOAT_CONSTANT IF ELSE LOGOP RELOP FOR WHILE ELSEIF 

%union {
    char vblno[10];
    char number[10];
};

%token <vblno>ID
%token <number>INTEGER_CONSTANT

%%
prog : funcDef 
funcDef : type ID '(' argList ')' '{'{ 
    system("rm output.ll");
    fp = fopen("output.ll", "a") ;
    fputs("define i32 @main() #0 {\n",fp);
    strcpy(adder,"");
}  declList stmtList'}'{fp = fopen("output.ll", "a");
fprintf(fp,"\t ret i32 0\n}");
}
argList : arg COMMA arg | ;
arg : type ID {strcpy(end->vbltable[i[l]],t);strcpy(end->varname[i[l]],$2);i[l]++;};
type : INT  {strcpy(t,"int");}|FLOAT {strcpy(t,"float");}|BOOL {strcpy(t,"boolean");};
declList : decl SEMICOLON declList | ;
decl : type varList;
varList : ID {strcpy(end->vbltable[i[l]],t);
strcpy(end->varname[i[l]],$1);i[l]++;
if(strcmp(t,"int")==0){
    fp = fopen("output.ll", "a") ;
    sprintf(adder,"\t %%%d = alloca i32, align 4\n",tmpid);
    printf("%s",adder);
    tmpid++;
    printf("adding %s to file\n",adder);
    fputs(adder,fp);
    //fprintf(fp,"%s",adder);
}
} COMMA varList | ID {strcpy(end->vbltable[i[l]],t);
strcpy(end->varname[i[l]],$1);
i[l]++;
if(strcmp(t,"int")==0){
    fp = fopen("output.ll", "a") ;
    sprintf(adder,"\t %%%d = alloca i32, align 4\n",tmpid);
    printf("%s",adder);
    tmpid++;
    fprintf(fp,"%s",adder);
}
};
stmtList : stmtList stmt | stmt;
stmt : declrassignStmt | assignStmt| ifStmt | whileStmt | elseifStmt | elseStmt | forStmt ;
assignStmt : ID '=' {printf("ASSIGNMENT\n ");struct Node* cpy=end;
if(!typereturner(cpy,$1))
    printf("\nError: Not declared\n");
else{strcpy(t,typereturner(cpy,$1));
    printf("\nAssignment var %s:%s\n",$1,t);} 
} INTEGER_CONSTANT SEMICOLON {
    if(strcmp(t,"int")==0){
        fp = fopen("output.ll", "a") ;
        sprintf(adder,"\t store i32 %s, ptr %%%d , align 4\n",$4,(checkexist($1)+1));
        fprintf(fp,"%s",adder);
    }
} |  EXP SEMICOLON  ;

declrassignStmt : type ID {struct Node* cpy=end;if(checkexist($2)!=-1){
    printf("\nError : Variable already declared\n");
    strcpy(t,typereturner(cpy,$2));
    }else{
        printf("DECLARING\n");
        strcpy(end->vbltable[i[l]],t);
        strcpy(end->varname[i[l]],$2);
        i[l]++;
    }
} '=' EXP SEMICOLON 
EXP : EXP '+' TERM | EXP '-' TERM | TERM ;
TERM : TERM '*' FACTOR | TERM '/' FACTOR | FACTOR;
FACTOR : ID  {
    //printf("id was revoked\n");
struct Node* cpy=end;
if(strcmp("none",t)==0){
    if(typereturner(cpy,$1)){
        strcpy(t,typereturner(cpy,$1));
    }
}
if(!typereturner(cpy,$1))
printf("\nError: %s Not declared\n",$1);
else if(strcmp(typereturner(cpy,$1),t)!=0)
printf("Warning operation on %s type on type  %s are of two different types\n",$1,t);
}| INTEGER_CONSTANT {if(strcmp("int",t)!=0)printf("Warning operation on int on type  %s are of two different types\n",t);};

ifStmt : IF '(' bExp ')' '{'{
    l++;
    struct Node *newnode;
    newnode=NULL;
    newnode = (struct Node*)malloc(sizeof(struct Node));
    end->next=newnode;
    newnode->prev=end;
    newnode->next=NULL;
    end=newnode;
} stmtList '}'{
    printf("BLOCK Variables:\n");
    for(int j=0;j<i[l];j++){
        printf("%s %s\n",end->vbltable[j],end->varname[j]);
    }
    i[l]=0;
    l--;
    end=end->prev;
    end->next=NULL;
    strcpy(t,"none");
} ;
elseifStmt : ELSEIF '(' bExp ')' '{'{
    l++;
    struct Node *newnode;
    newnode=NULL;
    newnode = (struct Node*)malloc(sizeof(struct Node));
    end->next=newnode;
    newnode->prev=end;
    newnode->next=NULL;
    end=newnode;
}  stmtList '}'{
    printf("BLOCK Variables:\n");
    for(int j=0;j<i[l];j++){
        printf("%s %s\n",end->vbltable[j],end->varname[j]);
    }
    i[l]=0;
    l--;
    end=end->prev;
    end->next=NULL;
    strcpy(t,"none");
} ;
elseStmt : ELSE '{'{
    l++;
    struct Node *newnode;
    newnode=NULL;
    newnode = (struct Node*)malloc(sizeof(struct Node));
    end->next=newnode;
    newnode->prev=end;
    newnode->next=NULL;
    end=newnode;
}  stmtList '}'{
    printf("BLOCK Variables:\n");
    for(int j=0;j<i[l];j++){
        printf("%s %s\n",end->vbltable[j],end->varname[j]);
    }
    i[l]=0;
    l--;
    end=end->prev;
    end->next=NULL;
    strcpy(t,"none");
} ;
bExp : EXP RELOP EXP | EXP LOGOP EXP ;
whileStmt : WHILE '(' bExp ')' '{'{
    l++;
    struct Node *newnode;
    newnode=NULL;
    newnode = (struct Node*)malloc(sizeof(struct Node));
    end->next=newnode;
    newnode->prev=end;
    newnode->next=NULL;
    end=newnode;
}  stmtList '}' {
    printf("BLOCK Variables:\n");
    for(int j=0;j<i[l];j++){
        printf("%s %s\n",end->vbltable[j],end->varname[j]);
    }
    i[l]=0;
    l--;
    end=end->prev;
    end->next=NULL;
    strcpy(t,"none");
} ;
forStmt : FOR '(' ID '=' EXP SEMICOLON bExp SEMICOLON ID '=' EXP')' '{'{
    l++;
    struct Node *newnode;
    newnode=NULL;
    newnode = (struct Node*)malloc(sizeof(struct Node));
    end->next=newnode;
    newnode->prev=end;
    newnode->next=NULL;
    end=newnode;
} stmtList '}' {
    printf("BLOCK Variables:\n");
    for(int j=0;j<i[l];j++){
        printf("%s %s\n",end->vbltable[j],end->varname[j]);
    }
    i[l]=0;
    l--;
    end=end->prev;
    end->next=NULL;
    strcpy(t,"none");
} ;
%%

int main()
{
    typestorer=NULL;
    end=NULL;
    typestorer = (struct Node*)malloc(sizeof(struct Node));
    typestorer->prev=NULL;
    typestorer->next=NULL;
    end = typestorer;
    yyparse();
    for(int j=0;j<i[0];j++){
        printf("%s %s\n",end->vbltable[j],end->varname[j]);
    }
    
}

int checkexist(char* name){
    printf("Checker %s\n",name);
    for(int j=0;j<i[0];j++){
        if(strcmp(name,end->varname[j])==0){
            return j;
        }
    }
    return -1;
}

char* typereturner(struct Node* check,char* name){
    int kcpy=l;
    struct Node* checkcpy=check;
    while(checkcpy!=NULL){
        for(int j=0;j<i[kcpy];j++){
            if(strcmp(name,checkcpy->varname[j])==0){
                return checkcpy->vbltable[j];
            }
        }
        kcpy--;
        checkcpy=checkcpy->prev;
    }
    return NULL;
}



