%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "parser.tab.h"
int yylex(void);
int yyerror(char *);
char t[10];

FILE *fp;
//FILE *fpcpy
int scope=0;
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
char op[10];


char varid[31];

//tmperory

int tmpid=1;
char varname[31];
char assnvarname[31];
char *typereturner(struct Node*,char *);
int ircheckexist(struct Node*,char*);
struct Node *typestorer;
struct Node *end;
int jumper[10]={0};
int jumpid=0;
int ordering[10]={0};
int orderid=0;
int tablelistid[1000][20];
int tableindex[1000]={0};
char lines[1000][1000];
int linecount=0;
%}

%token  BOOL INT FLOAT SEMICOLON COMMA FLOAT_CONSTANT IF ELSE AND OR NOT GT LT GTE LTE EQ NEQ FOR WHILE ELSEIF 

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
    fclose(fp);
}  declList stmtList'}'{fp = fopen("output.ll", "a");
fprintf(fp,"\t ret i32 0\n}");
fclose(fp);
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
    fclose(fp);
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
    fclose(fp);
}
};
stmtList : stmtList stmt | stmt;
stmt : declrassignStmt | assignStmt| ifStmt | whileStmt | elseifStmt | elseStmt | forStmt ;
assignStmt : ID '=' {printf("ASSIGNMENT\n ");
strcpy(varname,$1);
strcpy(assnvarname,$1);
printf("variable name : %s %d",varname,checkexist(varname));
struct Node* cpy=end;
if(!typereturner(cpy,$1))
    printf("\nError: Not declared\n");
else{strcpy(t,typereturner(cpy,$1));
    printf("\nAssignment var %s:%s\n",$1,t);} 
}  EXP SEMICOLON  ;

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
EXP : EXP '+' TERM 
 {

        struct Node* cpy=end;
        fp = fopen("output.ll", "a") ;
        sprintf(adder,"\t %%%d = add nsw i32 %%%d, %%%d\n",tmpid,tmpid-2,tmpid-1);
        printf("%s",adder);
        fprintf(fp,"%s",adder);
        printf("ASSIGN VAR NAME:%s\n",assnvarname);
        sprintf(adder,"\t store i32 %%%d, ptr %%%d, align 4\n",tmpid,ircheckexist(cpy,assnvarname)+1);
        fprintf(fp,"%s",adder);
        strcpy(adder,"");
        tmpid++;
        fclose(fp);
    }
    | EXP '-' TERM
     {

        struct Node* cpy=end;
        fp = fopen("output.ll", "a") ;
        sprintf(adder,"\t %%%d = sub nsw i32 %%%d, %%%d\n",tmpid,tmpid-2,tmpid-1);
        printf("%s",adder);
        fprintf(fp,"%s",adder);
        printf("ASSIGN VAR NAME:%s\n",assnvarname);
        sprintf(adder,"\t store i32 %%%d, ptr %%%d, align 4\n",tmpid,ircheckexist(cpy,assnvarname)+1);
        fprintf(fp,"%s",adder);
        strcpy(adder,"");
        tmpid++;
        fclose(fp);
    } | TERM ;
TERM : TERM '*' FACTOR {

        struct Node* cpy=end;
        fp = fopen("output.ll", "a") ;
        sprintf(adder,"\t %%%d = mul nsw i32 %%%d, %%%d\n",tmpid,tmpid-2,tmpid-1);
        printf("%s",adder);
        fprintf(fp,"%s",adder);
        printf("ASSIGN VAR NAME:%s\n",assnvarname);
        sprintf(adder,"\t store i32 %%%d, ptr %%%d, align 4\n",tmpid,ircheckexist(cpy,assnvarname)+1);
        fprintf(fp,"%s",adder);
        strcpy(adder,"");
        tmpid++;
        fclose(fp);
    }
    | TERM '/' FACTOR {
    
    struct Node* cpy=end;
    fp = fopen("output.ll", "a") ;
    sprintf(adder,"\t %%%d = sdiv nsw i32 %%%d, %%%d\n",tmpid,tmpid-2,tmpid-1);
    printf("%s",adder);
    fprintf(fp,"%s",adder);
    printf("ASSIGN VAR NAME:%s\n",assnvarname);
    sprintf(adder,"\t store i32 %%%d, ptr %%%d, align 4\n",tmpid,ircheckexist(cpy,assnvarname)+1);
    fprintf(fp,"%s",adder);
    strcpy(adder,"");
    tmpid++;
    fclose(fp);
}| FACTOR;
FACTOR : ID  {
    //printf("id was revoked\n");
struct Node* cpy=end;
if(strcmp("none",t)==0){
    if(typereturner(cpy,$1)){
        strcpy(t,typereturner(cpy,$1));
    }
}

fp = fopen("output.ll", "a") ;

sprintf(adder,"\t %%%d = load i32, i32* %%%d, align 4\n",tmpid,(ircheckexist(cpy,$1)+1));
fprintf(fp,"%s",adder);
tmpid++;
fclose(fp);
if(!typereturner(cpy,$1))
printf("\nError: %s Not declared\n",$1);
else if(strcmp(typereturner(cpy,$1),t)!=0)
printf("Warning operation on %s type on type  %s are of two different types\n",$1,t);
}| INTEGER_CONSTANT {
    if(strcmp("int",t)!=0)
    printf("Warning operation on int on type  %s are of two different types\n",t);
        struct Node* cpy=end;
        fp = fopen("output.ll", "a") ;

        sprintf(adder,"\t store i32 %s, ptr %%%d , align 4\n",$1,(ircheckexist(cpy,varname)+1));
        fprintf(fp,"%s",adder);
        fclose(fp);
};

ifStmt : IF '(' cExp ')' '{'{
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
    fp = fopen("output.ll", "a") ;
    strcpy(adder,"");
    sprintf(adder,"\t br label &&&\n");
    fprintf(fp,"%s\n",adder);
    strcpy(adder,"");
    sprintf(adder,"%d:",tmpid);
    jumper[jumpid]=tmpid;
    jumpid++;
    fprintf(fp,"%s\n",adder);
    tmpid++;
    fclose(fp);
} ;
elseifStmt : ELSEIF '(' cExp ')' '{'{
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
    fp = fopen("output.ll", "a") ;
    strcpy(adder,"");
    strcpy(adder,"");
    sprintf(adder,"\t br label %%%d\n",tmpid);
    fprintf(fp,"%s\n",adder);
    sprintf(adder,"%d:",tmpid);
    jumper[jumpid]=tmpid;
    jumpid++;
    fprintf(fp,"%s\n",adder);
    tmpid++;
    fclose(fp);
    FILE *fpcpy;
    
    printf("HELLO\n");
    fpcpy=fopen("output.ll","r");
    printf("THE LINES IN THE FILE\n");
    
    while(fgets(lines[linecount],1000,fpcpy)){
        lines[linecount][strlen(lines[linecount])-1]='\0';
        linecount++;
    }
    fclose(fpcpy);
    for(int j=0;j<linecount;j++){
        for(int k=0;k<strlen(lines[j]);k++){
            if(lines[j][k]=='_'){
                sprintf(adder,"%%%d",jumper[0]);
                lines[j][k]=adder[0];
                lines[j][k+1]=adder[1];
                if(strlen(adder)>1)
                    lines[j][k+2]=adder[2];
                else 
                    lines[j][k+2]=' ';
            }
            else if(lines[j][k]=='@' && lines[j][k+1]=='@'){
                sprintf(adder,"%%%d",jumper[1]);
                lines[j][k]=adder[0];
                lines[j][k+1]=adder[1];
                if(strlen(adder)>1)
                    lines[j][k+2]=adder[2];
                else 
                    lines[j][k+2]=' ';
            }
            else if(lines[j][k]=='&'){
                sprintf(adder,"%%%d",jumper[2]);
                lines[j][k]=adder[0];
                lines[j][k+1]=adder[1];
                if(strlen(adder)>1)
                    lines[j][k+2]=adder[2];
                else 
                    lines[j][k+2]=' ';
            }
        }
        //printf("\n");
        strcpy(adder,"");
    }
    system("rm output.ll");
    fp = fopen("output.ll", "a") ;
    for(int j=0;j<linecount;j++){
        printf("%s\n",lines[j]);
        fprintf(fp,"%s\n",lines[j]);
    }
    linecount=0;
    jumpid=0;
    fclose(fp);
} ;
RELOP : LT | GT {strcpy(op,"sgt");} | LTE | GTE | EQ | NEQ 
LOGOP : AND | OR | NOT
bExp : EXP RELOP EXP {
    fp = fopen("output.ll", "a") ;
    sprintf(adder,"\t %%%d = icmp %s i32 %%%d , %%%d\n",tmpid,op,tmpid-2,tmpid-1);
    tmpid++;
    fprintf(fp,"%s\n",adder);
    fclose(fp);
} | EXP LOGOP EXP ;
cExp : bExp {
    fp = fopen("output.ll", "a") ;
    tmpid--;
    sprintf(adder,"\t br i1 %%%d, label %%%d, label @@@ \n",tmpid,tmpid+1);
    tmpid++;
    fprintf(fp,"%s\n",adder);
    strcpy(adder,"");
    sprintf(adder,"%d:",tmpid);
    jumper[jumpid]=tmpid;
    jumpid++;
    fprintf(fp,"%s\n",adder);
    tmpid++;
    fclose(fp);
}| bExp {
    fp = fopen("output.ll", "a") ;
    tmpid--;
    sprintf(adder,"\t br i1 %%%d, label ___, label %%%d\n",tmpid,tmpid+1);
    tmpid++;
    fprintf(fp,"%s",adder);
    strcpy(adder,"");
    sprintf(adder,"%d:",tmpid);
    fprintf(fp,"%s\n",adder);
    tmpid++;
    fclose(fp);
} LOGOP bExp {
    fp = fopen("output.ll", "a") ;
    tmpid--;
    sprintf(adder,"\t br i1 %%%d, label %%%d, label @@@\n",tmpid,tmpid+1);
    tmpid++;
    fprintf(fp,"%s\n",adder);
    sprintf(adder,"%d:",tmpid);
    jumper[jumpid]=tmpid;
    jumpid++;
    fprintf(fp,"%s\n",adder);
    tmpid++;
    fclose(fp);
}
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
    for(int j=0;j<jumpid;j++)
        printf("%d\n",jumper[j]);
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

int ircheckexist(struct Node* check,char* name){
    int kcpy=l;
    int returner=0;
    int total=0;
    int flag=0;
    struct Node* checkcpy=check;
    while(checkcpy!=NULL){
        for(int j=0;j<i[kcpy];j++){
            if(strcmp(name,checkcpy->varname[j])==0){
                flag=1;
            }
            if(flag==0)
                returner++;
        }
        kcpy--;
        checkcpy=checkcpy->prev;
    }
    return returner;
}

