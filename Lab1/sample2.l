%{
    #include <stdio.h>
    int identifier = 0;
    int largest_identifier = 0;
    bool flag=0
%}


% %
^[a - z A - Z _][a - z A - Z 0 - 9 _] * {printf("Valid Identifier");}
^[^a - z A - Z _] {printf("Invalid Identifier");}
.;
% %

int yywrap(){}
 
int main()
{
    yylex();
}