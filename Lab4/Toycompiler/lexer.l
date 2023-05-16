%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.tab.h"


%}

digit [0-9]
letter [a-zA-Z]
letter_or_digit {digit}|{letter}
us     [_]

%%

[ \t]+                            { printf("Whitespace are ignored\n"); } ;//(whitespace)
\/\*(.)*\*\/                     { printf("Comments are ignored\n"); } //(comments)
"int"   {printf("int recognized\n");return INT;}
"float" {printf("float recognized\n");return FLOAT;}
"{"    { printf("Detected %s\n", yytext); return yytext[0]; }
"}"    { printf("Detected %s\n", yytext); return yytext[0];}
"("    { printf("Detected %s\n", yytext); return yytext[0];}
")"    { printf("Detected %s\n", yytext); return yytext[0];}
\n           { printf("A newline is detected\n"); }
"+"          { printf("An operator %s is detected\n", yytext); return yytext[0];} 
"*"          { printf("An operator %s is detected\n", yytext); return yytext[0];} 
"/"          { printf("An operator %s is detected\n", yytext); return yytext[0];} 
"-"          { printf("An operator %s is detected\n", yytext); return yytext[0];} 
"="          { printf("An operator %s is detected\n", yytext); return yytext[0];} 
";"            { printf("Semicolon\n"); return SEMICOLON;}
","            { printf(" Comma\n"); return COMMA;}
{digit}+       { printf("integer constant\n"); return INTEGER_CONSTANT;}
"if"           { printf("If statement"); return IF;}
"elseif"       { printf("elseif statement"); return ELSEIF;}
"else"         { printf("else statement"); return ELSE;}
"while"       { printf("while detetcted"); return WHILE;}
"for"         { printf("for detetcted"); return FOR;}
({us}|{letter}){letter_or_digit}*   { printf("An identifier %s is detected\n", yytext); return ID; }
{digit}+"."{digit}+ { printf("A float constant %s is detected\n", yytext); return FLOAT_CONSTANT;}
"&&"|"||"|"!"           { printf("A Logical Operator"); return LOGOP;}
"<"|">"|"<="|">="|"=="|"!="           { printf("relational operator detected"); return RELOP;}
"int"|"short"|"float"|"double"|"bool"|"char"|"signed"|"unsigned"|"for"|"while"|"do"|"return"|"void"|"switch"|"break"|"case"|"continue"|"goto"|"long"|"static"|"union"|"default"|"class"|"public"|"private"|"protected" { printf("Token: %s is encountered\n", yytext);printf("Keyword : %s is encountered\n", yytext); } //(keywords)
.            { printf("Invalid entry been encountered\n");}
%%
