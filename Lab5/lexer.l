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

[ \t]+                            {  } ;//(whitespace)
\/\*(.)*\*\/                     { } //(comments)
"int"   {return INT;}
"float" {return FLOAT;}
"boolean" {return BOOL;}
"{"    { return yytext[0]; }
"}"    {  return yytext[0];}
"("    {  return yytext[0];}
")"    { return yytext[0];}
\n           { }
"+"          {  return yytext[0];} 
"*"          { return yytext[0];} 
"/"          { return yytext[0];} 
"-"          {return yytext[0];} 
"="          {  return yytext[0];} 
";"            { return SEMICOLON;}
","            { return COMMA;}
{digit}+       { return INTEGER_CONSTANT;}
"if"           { return IF;}
"elseif"       { return ELSEIF;}
"else"         { return ELSE;}
"while"       {return WHILE;}
"for"         {  return FOR;}
({us}|{letter}){letter_or_digit}*   { strcpy(yylval.vblno,yytext); return ID; }
{digit}+"."{digit}+ { return FLOAT_CONSTANT;}
"&&"|"||"|"!"           { return LOGOP;}
"<"|">"|"<="|">="|"=="|"!="           {  return RELOP;}
"int"|"short"|"float"|"double"|"bool"|"char"|"signed"|"unsigned"|"for"|"while"|"do"|"return"|"void"|"switch"|"break"|"case"|"continue"|"goto"|"long"|"static"|"union"|"default"|"class"|"public"|"private"|"protected" {  } //(keywords)
.            { }
%%
