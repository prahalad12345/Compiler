%{
    #include <stdio.h>
    int identifier = 0;
    int largest_identifier = 0;
    int counter=0;
%}
digit [0-9]
letter [a-zA-z]
%%
[ \t]+   {if(largest_identifier<identifier && counter==1)largest_identifier=identifier;counter=0;identifier=0;printf("largest_identifier is %d\n",largest_identifier);} 
{letter} {if(counter==0){counter=1;identifier=1;}else{identifier++;}}
{digit}    {if(counter==0){counter=-1;printf("Not an identifier\n");}else{identifier++;}}
\n       {if(largest_identifier<identifier && counter==1)largest_identifier=identifier;counter=0;identifier=0;printf("largest_identifier is %d\n",largest_identifier);}
%%

int yywrap(){}

int main()
{
    yylex();
    printf("largest_identifier is %d",largest_identifier);
}
