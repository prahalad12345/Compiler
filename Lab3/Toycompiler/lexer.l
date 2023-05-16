%{
    #include <stdio.h>
    #include "parser.tab.h"
    char sym_tab[50][31];
    int length[50];
    int count=0;
    int largest_identifier=0;
    void add_sym_tab(char name[], int len);
%}

digit [0-9]
letter [a-zA-Z]
letter_or_digit {digit}|{letter}
us     [_]



%%
[ \t]+                            { printf("Whitespace are ignored\n"); } ;//(whitespace)
\/\*(.)*\*\/                     { printf("Comments are ignored\n"); } //(comments)

";" {printf("semicolon is detected\n"); return SEMICOLON;}
"," {printf("comma is detected\n"); return COMMA;}
"=" {printf("Assignment operator\n");return ASSIGN;}
"if" {printf("if \n");return IF;}
"else" {printf("else \n");return ELSE;}
"&&" {printf("and\n");return AND;}
"!" {printf("not\n");return NOT;}
"==" {printf("equals\n");return EQ;}
">=" {printf("greater equals\n");return GE;}
"int"|"short"|"float"|"double"|"bool"|"char"|"signed"|"unsigned"|"for"|"while"|"do"|"return"|"void"|"switch"|"break"|"case"|"continue"|"goto"|"long"|"static"|"union"|"default"|"class"|"public"|"private"|"protected" { printf("Token: %s is encountered\n", yytext);printf("Keyword : %s is encountered\n", yytext); } //(keywords)
({us}|{letter}){letter_or_digit}* { printf("Token: %s is encountered\n", yytext);printf("Identifier : %s is encountered\n", yytext); if(yyleng<=31){add_sym_tab(yytext, yyleng);}else{printf("The length of the variable is greater than 31\n");}  return ID;} //(identifier and adding to the symbol table)
{digit}+ { printf("Token: %s is encountered\n", yytext);printf("Integer Constant : %s is encountered\n", yytext); return INTEGER_CONSTANT} //(Integer Constant)
{digit}+"."{digit}+  { printf("Token: %s is encountered\n", yytext);printf("Floating point Constant : %s is encountered\n", yytext); return FLOATING_CONSTANT} //(FLoating Point Constant)
"+"|"-"|"*"|"/"|"="|"+="|"−="|"∗="|"/=" { printf("Token: %s is encountered\n", yytext);printf("An Arithematic operator : %s is encountered\n", yytext); } //(Arithematic operator)
"<"|">"|"<="|">="|"== " { printf("Token: %s is encountered\n", yytext);printf("A Relational operator : %s is encountered\n", yytext); } //(Relational Operator)
";"|"("|")"|","|"["|"]"|"{"|"}" { printf("Token: %s is encountered\n", yytext);printf("A Special Symbol : %s is encountered\n", yytext); return yytext[0];} //(Special Symbol)
. { printf("Invalid entry been encountered\n");}
%%

void add_sym_tab(char *name, int len)
{
    for(int j=0;j<count;j++){
        if(strcmp(sym_tab[j],name)==0)
            return;
    }
    strcpy(sym_tab[count], name);
    length[count]=len;
    count++;
}

