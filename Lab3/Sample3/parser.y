%{
#include <stdio.h>
#include <stdlib.h>
#include "parser.tab.h"
int yylex(void);
int yyerror(char *);
%}


%token ID INT_CONST 
%%
S : ID '=' E   { printf("The rule with equal to operator is triggered\n"); }
F : INT_CONST {printf("constant");}
E : T  {printf("E to T");}
E : E '+' T { printf("The rule with plus operator is triggered\n"); }
T : F  {printf("T to F");}
T : T '*' F { printf("The rule * operator is triggered\n"); }
F : ID { printf("The rule with ID is triggered\n"); }
%%

int main()
{
    yyparse();
}
