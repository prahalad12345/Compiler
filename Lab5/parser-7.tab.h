/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     BOOL = 258,
     INT = 259,
     FLOAT = 260,
     SEMICOLON = 261,
     COMMA = 262,
     INTEGER_CONSTANT = 263,
     FLOAT_CONSTANT = 264,
     IF = 265,
     ELSE = 266,
     LOGOP = 267,
     RELOP = 268,
     FOR = 269,
     WHILE = 270,
     ELSEIF = 271,
     ID = 272
   };
#endif
/* Tokens.  */
#define BOOL 258
#define INT 259
#define FLOAT 260
#define SEMICOLON 261
#define COMMA 262
#define INTEGER_CONSTANT 263
#define FLOAT_CONSTANT 264
#define IF 265
#define ELSE 266
#define LOGOP 267
#define RELOP 268
#define FOR 269
#define WHILE 270
#define ELSEIF 271
#define ID 272




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 17 "parser-7.y"
{
    char vblno[10];
}
/* Line 1529 of yacc.c.  */
#line 87 "parser-7.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;
