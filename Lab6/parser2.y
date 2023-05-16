%{
#include <stdio.h>
#include <stdlib.h>
#include "parser.tab.h"
int yylex(void);
int yyerror(char *);
%}


%token id
%%
E : E'+'E | E'*'E | id
%%

int main()
{
    yyparse();
}
