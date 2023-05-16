%{
#include <stdio.h>
#include <stdlib.h>
#include "parser.tab.h"
int yylex(void);
int yyerror(char *);
%}


%token a 
%%
S : A|a 
A : a
%%

int main()
{
    yyparse();
}
