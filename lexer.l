%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.tab.h"


%}

%%

[ \t]+       { printf("White space is encountered\n");}
"{"    { printf("Detected %s\n", yytext); return yytext[0]; }
"}"    { printf("Detected %s\n", yytext); return yytext[0];}
"("    { printf("Detected %s\n", yytext); return yytext[0];}
")"    { printf("Detected %s\n", yytext); return yytext[0];}
\n           { printf("A newline is detected\n"); }
"+"          { printf("An operator %s is detected\n", yytext); return yytext[0];} 
"*"          { printf("An operator %s is detected\n", yytext); return yytext[0];} 
"="          { printf("An operator %s is detected\n", yytext); return yytext[0];} 
[0-9]+       { printf("An integer constant %s is detected\n", yytext); return INT_CONST;}
"int"          { printf("An int data type was detected\n"); return INT;}
"float"        { printf("A float data type was detected"); return FLOAT;}
"if"           { printf("An If statement was detected"); return IF;}
"else"         { printf("An Else statement was detected"); return ELSE;}
"while"       { printf("A while statement was detetcted"); return WHILE;}
"for"         { printf("A for statement was detetcted"); return FOR;}
"return"      { printf("A return statement was detetcted"); return RETURN;}
[A-Za-z]+    { printf("An identifier %s is detected\n", yytext); return ID; }
[0-9]+\.[0-9]+ { printf("A float constant %s is detected\n", yytext); return FLOAT_CONST;}
";"            { printf("A Semicolon was detected"); return SEMICOLON;}
","            { printf("A Comma was detected"); return COMMA;}
"&&"           { printf("A Logical And && was detected"); return AND;}
"||"           { printf("A Logical Or || was detected"); return OR;}
"!"           { printf("A Logical Not ! was detected"); return NOT;}
"=="           { printf("An Equality == was detected"); return EQ;}
">="           { printf("A Greater than Equal >= was detected"); return GE;}
"<="           { printf("A Leasser than Equal <= was detected"); return LE;}
"<"           { printf("A Lesser than < was detected"); return LT;}
">"           { printf("A Greater than > was detected"); return GT;}
"!="          { printf("A Not equal != was detected"); return NE;}
.            { printf("Other character %s is detected\n", yytext); return yytext[0];}
%%
