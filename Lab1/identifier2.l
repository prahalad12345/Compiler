%{
    #include <stdio.h>
    int length= 0;
    int maxlen= 0;
    int largest_identifier=0;
%}
digit [0-9]
letter [a-zA-z]
%%
end return 0;
({digit}({digit}|{letter})*)    {printf("%s is not an identifier",yytext);}
({letter}({digit}|{letter})*)   { printf("%s: Identifier detected \n", yytext); length = strlen(yytext); if(length > maxlen) maxlen = length;printf("length of largest identifier %d\n",maxlen);}
%%


int main()
{
    //yytext is to extract the whole string
    yylex();
    printf("largest_identifier is %d",largest_identifier);
}
