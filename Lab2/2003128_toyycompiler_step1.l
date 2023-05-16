%{
    #include <stdio.h>
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
"int"|"short"|"float"|"double"|"bool"|"char"|"signed"|"unsigned"|"for"|"while"|"do"|"return"|"void"|"switch"|"break"|"case"|"continue"|"goto"|"long"|"static"|"union"|"default"|"class"|"public"|"private"|"protected" { printf("Token: %s is encountered\n", yytext);printf("Keyword : %s is encountered\n", yytext); } //(keywords)
({us}|{letter}){letter_or_digit}* { printf("Token: %s is encountered\n", yytext);printf("Identifier : %s is encountered\n", yytext); if(yyleng<=31){add_sym_tab(yytext, yyleng);}else{printf("The length of the variable is greater than 31\n");}  } //(identifier and adding to the symbol table)
{digit}+ { printf("Token: %s is encountered\n", yytext);printf("Integer Constant : %s is encountered\n", yytext); } //(Integer Constant)
{digit}+"."{digit}+  { printf("Token: %s is encountered\n", yytext);printf("Floating point Constant : %s is encountered\n", yytext); } //(FLoating Point Constant)
"+"|"-"|"*"|"/"|"="|"+="|"−="|"∗="|"/=" { printf("Token: %s is encountered\n", yytext);printf("An Arithematic operator : %s is encountered\n", yytext); } //(Arithematic operator)
"<"|">"|"<="|">="|"== " { printf("Token: %s is encountered\n", yytext);printf("A Relational operator : %s is encountered\n", yytext); } //(Relational Operator)
";"|"("|")"|","|"["|"]"|"{"|"}" { printf("Token: %s is encountered\n", yytext);printf("A Special Symbol : %s is encountered\n", yytext); } //(Special Symbol)
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

int main()
{
    //yytext is to extract the whole string
    yylex();
    for(int i=0;i<count;i++){
        printf("%s : %d\n",sym_tab[i],length[i]);
    }
}
