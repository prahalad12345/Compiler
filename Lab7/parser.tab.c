/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



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
     FLOAT_CONSTANT = 263,
     IF = 264,
     ELSE = 265,
     AND = 266,
     OR = 267,
     NOT = 268,
     GT = 269,
     LT = 270,
     GTE = 271,
     LTE = 272,
     EQ = 273,
     NEQ = 274,
     FOR = 275,
     WHILE = 276,
     ELSEIF = 277,
     ID = 278,
     INTEGER_CONSTANT = 279
   };
#endif
/* Tokens.  */
#define BOOL 258
#define INT 259
#define FLOAT 260
#define SEMICOLON 261
#define COMMA 262
#define FLOAT_CONSTANT 263
#define IF 264
#define ELSE 265
#define AND 266
#define OR 267
#define NOT 268
#define GT 269
#define LT 270
#define GTE 271
#define LTE 272
#define EQ 273
#define NEQ 274
#define FOR 275
#define WHILE 276
#define ELSEIF 277
#define ID 278
#define INTEGER_CONSTANT 279




/* Copy the first part of user declarations.  */
#line 1 "parser.y"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "parser.tab.h"
int yylex(void);
int yyerror(char *);
char t[10];

FILE *fp;
//FILE *fpcpy
int scope=0;
char number;
int k=0;
int i[20]={0};//20 depth blocks accepted
int l=0;
int id=0;
char adder[100];
int checkexist(char *);
struct Node{
    char vbltable[31][10];
    char varname[31][10];
    struct Node* next;
    struct Node* prev;
};
char op[10];


char varid[31];

//tmperory

int tmpid=1;
char varname[31];
char assnvarname[31];
char *typereturner(struct Node*,char *);
int ircheckexist(struct Node*,char*);
struct Node *typestorer;
struct Node *end;
int jumper[10]={0};
int jumpid=0;
int ordering[10]={0};
int orderid=0;
int tablelistid[1000][20];
int tableindex[1000]={0};
char lines[1000][1000];
int linecount=0;


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 52 "parser.y"
{
    char vblno[10];
    char number[10];
}
/* Line 193 of yacc.c.  */
#line 198 "parser.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 211 "parser.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   203

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  34
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  61
/* YYNRULES -- Number of states.  */
#define YYNSTATES  126

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   279

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      25,    26,    32,    30,     2,    31,     2,    33,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    29,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    27,     2,    28,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     6,    17,    21,    22,    25,    27,
      29,    31,    35,    36,    39,    40,    45,    47,    50,    52,
      54,    56,    58,    60,    62,    64,    66,    67,    73,    74,
      81,    85,    89,    91,    95,    99,   101,   103,   105,   106,
     115,   116,   125,   126,   132,   134,   136,   138,   140,   142,
     144,   146,   148,   150,   154,   158,   160,   161,   166,   167,
     176,   177
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      35,     0,    -1,    36,    -1,    -1,    40,    23,    25,    38,
      26,    27,    37,    41,    45,    28,    -1,    39,     7,    39,
      -1,    -1,    40,    23,    -1,     4,    -1,     5,    -1,     3,
      -1,    42,     6,    41,    -1,    -1,    40,    43,    -1,    -1,
      23,    44,     7,    43,    -1,    23,    -1,    45,    46,    -1,
      46,    -1,    49,    -1,    47,    -1,    54,    -1,    65,    -1,
      56,    -1,    58,    -1,    67,    -1,    -1,    23,    29,    48,
      51,     6,    -1,    -1,    40,    23,    50,    29,    51,     6,
      -1,    51,    30,    52,    -1,    51,    31,    52,    -1,    52,
      -1,    52,    32,    53,    -1,    52,    33,    53,    -1,    53,
      -1,    23,    -1,    24,    -1,    -1,     9,    25,    63,    26,
      27,    55,    45,    28,    -1,    -1,    22,    25,    63,    26,
      27,    57,    45,    28,    -1,    -1,    10,    27,    59,    45,
      28,    -1,    15,    -1,    14,    -1,    17,    -1,    16,    -1,
      18,    -1,    19,    -1,    11,    -1,    12,    -1,    13,    -1,
      51,    60,    51,    -1,    51,    61,    51,    -1,    62,    -1,
      -1,    62,    64,    61,    62,    -1,    -1,    21,    25,    62,
      26,    27,    66,    45,    28,    -1,    -1,    20,    25,    23,
      29,    51,     6,    62,     6,    23,    29,    51,    26,    27,
      68,    45,    28,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    61,    61,    62,    62,    72,    72,    73,    74,    74,
      74,    75,    75,    76,    77,    77,    89,   101,   101,   102,
     102,   102,   102,   102,   102,   102,   103,   103,   114,   114,
     124,   139,   153,   154,   168,   181,   182,   201,   212,   212,
     243,   243,   263,   263,   347,   347,   347,   347,   347,   347,
     348,   348,   348,   349,   355,   356,   369,   369,   393,   393,
     413,   413
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "BOOL", "INT", "FLOAT", "SEMICOLON",
  "COMMA", "FLOAT_CONSTANT", "IF", "ELSE", "AND", "OR", "NOT", "GT", "LT",
  "GTE", "LTE", "EQ", "NEQ", "FOR", "WHILE", "ELSEIF", "ID",
  "INTEGER_CONSTANT", "'('", "')'", "'{'", "'}'", "'='", "'+'", "'-'",
  "'*'", "'/'", "$accept", "prog", "funcDef", "@1", "argList", "arg",
  "type", "declList", "decl", "varList", "@2", "stmtList", "stmt",
  "assignStmt", "@3", "declrassignStmt", "@4", "EXP", "TERM", "FACTOR",
  "ifStmt", "@5", "elseifStmt", "@6", "elseStmt", "@7", "RELOP", "LOGOP",
  "bExp", "cExp", "@8", "whileStmt", "@9", "forStmt", "@10", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,    40,    41,   123,   125,    61,
      43,    45,    42,    47
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    34,    35,    37,    36,    38,    38,    39,    40,    40,
      40,    41,    41,    42,    44,    43,    43,    45,    45,    46,
      46,    46,    46,    46,    46,    46,    48,    47,    50,    49,
      51,    51,    51,    52,    52,    52,    53,    53,    55,    54,
      57,    56,    59,    58,    60,    60,    60,    60,    60,    60,
      61,    61,    61,    62,    62,    63,    64,    63,    66,    65,
      68,    67
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,    10,     3,     0,     2,     1,     1,
       1,     3,     0,     2,     0,     4,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     5,     0,     6,
       3,     3,     1,     3,     3,     1,     1,     1,     0,     8,
       0,     8,     0,     5,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     3,     1,     0,     4,     0,     8,
       0,    16
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    10,     8,     9,     0,     2,     0,     1,     0,     6,
       0,     0,     0,     0,     0,     7,     3,     5,    12,     0,
       0,     0,    14,    13,     0,     0,     0,     0,     0,     0,
       0,     0,    18,    20,    19,    21,    23,    24,    22,    25,
      12,     0,     0,    42,     0,     0,     0,    26,    28,     4,
      17,    11,     0,    36,    37,     0,    32,    35,    56,     0,
       0,     0,     0,     0,     0,     0,    15,    50,    51,    52,
      45,    44,    47,    46,    48,    49,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      30,    31,    53,    54,    33,    34,     0,    38,    43,     0,
      58,    40,    27,     0,    57,     0,     0,     0,     0,    29,
       0,     0,     0,     0,    39,     0,    59,    41,     0,     0,
       0,     0,    60,     0,     0,    61
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,    18,    10,    11,    30,    20,    21,    23,
      41,    31,    32,    33,    64,    34,    65,    55,    56,    57,
      35,   105,    36,   108,    37,    60,    78,    79,    58,    59,
      82,    38,   107,    39,   123
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -63
static const yytype_int16 yypact[] =
{
      17,   -63,   -63,   -63,     6,   -63,   -20,   -63,   -14,    17,
      -8,    37,    22,    20,    17,   -63,   -63,   -63,    17,    28,
     180,    46,    48,   -63,    31,    32,    33,    35,    36,    34,
      39,    63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,   -63,
      17,    62,    -9,   -63,    47,    -9,    -9,   -63,   -63,   -63,
     -63,   -63,    28,   -63,   -63,   163,    -7,   -63,    45,    49,
     180,    51,    50,    52,    -9,    58,   -63,   -63,   -63,   -63,
     -63,   -63,   -63,   -63,   -63,   -63,    -9,    -9,    -9,    -9,
      -9,    -9,    24,    65,    85,    -9,    69,    73,    -1,    -9,
      -7,    -7,     8,     8,   -63,   -63,    -9,   -63,   -63,     1,
     -63,   -63,   -63,     3,   -63,   180,    -9,   180,   180,   -63,
      94,    68,   115,   124,   -63,    54,   -63,   -63,    72,    -9,
     -18,    75,   -63,   180,   145,   -63
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -63,   -63,   -63,   -63,   -63,    95,    10,    70,   -63,    59,
     -63,   -59,   -31,   -63,   -63,   -63,   -63,   -62,   -36,   -38,
     -63,   -63,   -63,   -63,   -63,   -63,   -63,    30,   -41,    77,
     -63,   -63,   -63,   -63,   -63
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -56
static const yytype_int8 yytable[] =
{
      50,    84,    88,     8,    62,   102,     7,   106,   121,   109,
       6,     9,    76,    77,    53,    54,    92,    93,    13,    12,
       1,     2,     3,    99,    12,    80,    81,   103,    19,    76,
      77,    76,    77,    76,    77,    67,    68,    69,    76,    77,
      90,    91,    94,    95,    14,    15,   110,    16,   112,   113,
      19,    22,    40,    50,   -16,   104,    42,   120,    44,    43,
      45,    46,    48,    47,   124,   111,     1,     2,     3,    52,
      61,   -55,    24,    25,   115,    83,    86,   118,    87,    50,
      85,    50,    50,    26,    27,    28,    29,    89,     1,     2,
       3,    49,    97,    50,    24,    25,   100,     1,     2,     3,
     101,   119,   122,    24,    25,    26,    27,    28,    29,    17,
      51,    66,    96,    98,    26,    27,    28,    29,     1,     2,
       3,     0,   114,    63,    24,    25,     0,     1,     2,     3,
       0,     0,     0,    24,    25,    26,    27,    28,    29,     0,
       0,     0,     0,   116,    26,    27,    28,    29,     1,     2,
       3,     0,   117,     0,    24,    25,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    26,    27,    28,    29,     0,
       0,     0,     0,   125,    67,    68,    69,    70,    71,    72,
      73,    74,    75,     1,     2,     3,     0,     0,     0,    24,
      25,     0,     0,    76,    77,     0,     0,     0,     0,     0,
      26,    27,    28,    29
};

static const yytype_int8 yycheck[] =
{
      31,    60,    64,    23,    45,     6,     0,     6,    26,     6,
       0,    25,    30,    31,    23,    24,    78,    79,    26,     9,
       3,     4,     5,    85,    14,    32,    33,    89,    18,    30,
      31,    30,    31,    30,    31,    11,    12,    13,    30,    31,
      76,    77,    80,    81,     7,    23,   105,    27,   107,   108,
      40,    23,     6,    84,     6,    96,    25,   119,    25,    27,
      25,    25,    23,    29,   123,   106,     3,     4,     5,     7,
      23,    26,     9,    10,     6,    26,    26,    23,    26,   110,
      29,   112,   113,    20,    21,    22,    23,    29,     3,     4,
       5,    28,    27,   124,     9,    10,    27,     3,     4,     5,
      27,    29,    27,     9,    10,    20,    21,    22,    23,    14,
      40,    52,    82,    28,    20,    21,    22,    23,     3,     4,
       5,    -1,    28,    46,     9,    10,    -1,     3,     4,     5,
      -1,    -1,    -1,     9,    10,    20,    21,    22,    23,    -1,
      -1,    -1,    -1,    28,    20,    21,    22,    23,     3,     4,
       5,    -1,    28,    -1,     9,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    20,    21,    22,    23,    -1,
      -1,    -1,    -1,    28,    11,    12,    13,    14,    15,    16,
      17,    18,    19,     3,     4,     5,    -1,    -1,    -1,     9,
      10,    -1,    -1,    30,    31,    -1,    -1,    -1,    -1,    -1,
      20,    21,    22,    23
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,    35,    36,    40,     0,    23,    25,
      38,    39,    40,    26,     7,    23,    27,    39,    37,    40,
      41,    42,    23,    43,     9,    10,    20,    21,    22,    23,
      40,    45,    46,    47,    49,    54,    56,    58,    65,    67,
       6,    44,    25,    27,    25,    25,    25,    29,    23,    28,
      46,    41,     7,    23,    24,    51,    52,    53,    62,    63,
      59,    23,    62,    63,    48,    50,    43,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    30,    31,    60,    61,
      32,    33,    64,    26,    45,    29,    26,    26,    51,    29,
      52,    52,    51,    51,    53,    53,    61,    27,    28,    51,
      27,    27,     6,    51,    62,    55,     6,    66,    57,     6,
      45,    62,    45,    45,    28,     6,    28,    28,    23,    29,
      51,    26,    27,    68,    45,    28
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 3:
#line 62 "parser.y"
    { 
    system("rm output.ll");
    fp = fopen("output.ll", "a") ;
    fputs("define i32 @main() #0 {\n",fp);
    strcpy(adder,"");
    fclose(fp);
;}
    break;

  case 4:
#line 68 "parser.y"
    {fp = fopen("output.ll", "a");
fprintf(fp,"\t ret i32 0\n}");
fclose(fp);
;}
    break;

  case 7:
#line 73 "parser.y"
    {strcpy(end->vbltable[i[l]],t);strcpy(end->varname[i[l]],(yyvsp[(2) - (2)].vblno));i[l]++;;}
    break;

  case 8:
#line 74 "parser.y"
    {strcpy(t,"int");;}
    break;

  case 9:
#line 74 "parser.y"
    {strcpy(t,"float");;}
    break;

  case 10:
#line 74 "parser.y"
    {strcpy(t,"boolean");;}
    break;

  case 14:
#line 77 "parser.y"
    {strcpy(end->vbltable[i[l]],t);
strcpy(end->varname[i[l]],(yyvsp[(1) - (1)].vblno));i[l]++;
if(strcmp(t,"int")==0){
    fp = fopen("output.ll", "a") ;
    sprintf(adder,"\t %%%d = alloca i32, align 4\n",tmpid);
    printf("%s",adder);
    tmpid++;
    printf("adding %s to file\n",adder);
    fputs(adder,fp);
    fclose(fp);
    //fprintf(fp,"%s",adder);
}
;}
    break;

  case 16:
#line 89 "parser.y"
    {strcpy(end->vbltable[i[l]],t);
strcpy(end->varname[i[l]],(yyvsp[(1) - (1)].vblno));
i[l]++;
if(strcmp(t,"int")==0){
    fp = fopen("output.ll", "a") ;
    sprintf(adder,"\t %%%d = alloca i32, align 4\n",tmpid);
    printf("%s",adder);
    tmpid++;
    fprintf(fp,"%s",adder);
    fclose(fp);
}
;}
    break;

  case 26:
#line 103 "parser.y"
    {printf("ASSIGNMENT\n ");
strcpy(varname,(yyvsp[(1) - (2)].vblno));
strcpy(assnvarname,(yyvsp[(1) - (2)].vblno));
printf("variable name : %s %d",varname,checkexist(varname));
struct Node* cpy=end;
if(!typereturner(cpy,(yyvsp[(1) - (2)].vblno)))
    printf("\nError: Not declared\n");
else{strcpy(t,typereturner(cpy,(yyvsp[(1) - (2)].vblno)));
    printf("\nAssignment var %s:%s\n",(yyvsp[(1) - (2)].vblno),t);} 
;}
    break;

  case 28:
#line 114 "parser.y"
    {struct Node* cpy=end;if(checkexist((yyvsp[(2) - (2)].vblno))!=-1){
    printf("\nError : Variable already declared\n");
    strcpy(t,typereturner(cpy,(yyvsp[(2) - (2)].vblno)));
    }else{
        printf("DECLARING\n");
        strcpy(end->vbltable[i[l]],t);
        strcpy(end->varname[i[l]],(yyvsp[(2) - (2)].vblno));
        i[l]++;
    }
;}
    break;

  case 30:
#line 125 "parser.y"
    {

        struct Node* cpy=end;
        fp = fopen("output.ll", "a") ;
        sprintf(adder,"\t %%%d = add nsw i32 %%%d, %%%d\n",tmpid,tmpid-2,tmpid-1);
        printf("%s",adder);
        fprintf(fp,"%s",adder);
        printf("ASSIGN VAR NAME:%s\n",assnvarname);
        sprintf(adder,"\t store i32 %%%d, ptr %%%d, align 4\n",tmpid,ircheckexist(cpy,assnvarname)+1);
        fprintf(fp,"%s",adder);
        strcpy(adder,"");
        tmpid++;
        fclose(fp);
    ;}
    break;

  case 31:
#line 140 "parser.y"
    {

        struct Node* cpy=end;
        fp = fopen("output.ll", "a") ;
        sprintf(adder,"\t %%%d = sub nsw i32 %%%d, %%%d\n",tmpid,tmpid-2,tmpid-1);
        printf("%s",adder);
        fprintf(fp,"%s",adder);
        printf("ASSIGN VAR NAME:%s\n",assnvarname);
        sprintf(adder,"\t store i32 %%%d, ptr %%%d, align 4\n",tmpid,ircheckexist(cpy,assnvarname)+1);
        fprintf(fp,"%s",adder);
        strcpy(adder,"");
        tmpid++;
        fclose(fp);
    ;}
    break;

  case 33:
#line 154 "parser.y"
    {

        struct Node* cpy=end;
        fp = fopen("output.ll", "a") ;
        sprintf(adder,"\t %%%d = mul nsw i32 %%%d, %%%d\n",tmpid,tmpid-2,tmpid-1);
        printf("%s",adder);
        fprintf(fp,"%s",adder);
        printf("ASSIGN VAR NAME:%s\n",assnvarname);
        sprintf(adder,"\t store i32 %%%d, ptr %%%d, align 4\n",tmpid,ircheckexist(cpy,assnvarname)+1);
        fprintf(fp,"%s",adder);
        strcpy(adder,"");
        tmpid++;
        fclose(fp);
    ;}
    break;

  case 34:
#line 168 "parser.y"
    {
    
    struct Node* cpy=end;
    fp = fopen("output.ll", "a") ;
    sprintf(adder,"\t %%%d = sdiv nsw i32 %%%d, %%%d\n",tmpid,tmpid-2,tmpid-1);
    printf("%s",adder);
    fprintf(fp,"%s",adder);
    printf("ASSIGN VAR NAME:%s\n",assnvarname);
    sprintf(adder,"\t store i32 %%%d, ptr %%%d, align 4\n",tmpid,ircheckexist(cpy,assnvarname)+1);
    fprintf(fp,"%s",adder);
    strcpy(adder,"");
    tmpid++;
    fclose(fp);
;}
    break;

  case 36:
#line 182 "parser.y"
    {
    //printf("id was revoked\n");
struct Node* cpy=end;
if(strcmp("none",t)==0){
    if(typereturner(cpy,(yyvsp[(1) - (1)].vblno))){
        strcpy(t,typereturner(cpy,(yyvsp[(1) - (1)].vblno)));
    }
}

fp = fopen("output.ll", "a") ;

sprintf(adder,"\t %%%d = load i32, i32* %%%d, align 4\n",tmpid,(ircheckexist(cpy,(yyvsp[(1) - (1)].vblno))+1));
fprintf(fp,"%s",adder);
tmpid++;
fclose(fp);
if(!typereturner(cpy,(yyvsp[(1) - (1)].vblno)))
printf("\nError: %s Not declared\n",(yyvsp[(1) - (1)].vblno));
else if(strcmp(typereturner(cpy,(yyvsp[(1) - (1)].vblno)),t)!=0)
printf("Warning operation on %s type on type  %s are of two different types\n",(yyvsp[(1) - (1)].vblno),t);
;}
    break;

  case 37:
#line 201 "parser.y"
    {
    if(strcmp("int",t)!=0)
    printf("Warning operation on int on type  %s are of two different types\n",t);
        struct Node* cpy=end;
        fp = fopen("output.ll", "a") ;

        sprintf(adder,"\t store i32 %s, ptr %%%d , align 4\n",(yyvsp[(1) - (1)].number),(ircheckexist(cpy,varname)+1));
        fprintf(fp,"%s",adder);
        fclose(fp);
;}
    break;

  case 38:
#line 212 "parser.y"
    {
    l++;
    struct Node *newnode;
    newnode=NULL;
    newnode = (struct Node*)malloc(sizeof(struct Node));
    end->next=newnode;
    newnode->prev=end;
    newnode->next=NULL;
    end=newnode;
;}
    break;

  case 39:
#line 221 "parser.y"
    {
    printf("BLOCK Variables:\n");
    for(int j=0;j<i[l];j++){
        printf("%s %s\n",end->vbltable[j],end->varname[j]);
    }
    i[l]=0;
    l--;
    end=end->prev;
    end->next=NULL;
    strcpy(t,"none");
    fp = fopen("output.ll", "a") ;
    strcpy(adder,"");
    sprintf(adder,"\t br label &&&\n");
    fprintf(fp,"%s\n",adder);
    strcpy(adder,"");
    sprintf(adder,"%d:",tmpid);
    jumper[jumpid]=tmpid;
    jumpid++;
    fprintf(fp,"%s\n",adder);
    tmpid++;
    fclose(fp);
;}
    break;

  case 40:
#line 243 "parser.y"
    {
    l++;
    struct Node *newnode;
    newnode=NULL;
    newnode = (struct Node*)malloc(sizeof(struct Node));
    end->next=newnode;
    newnode->prev=end;
    newnode->next=NULL;
    end=newnode;
;}
    break;

  case 41:
#line 252 "parser.y"
    {
    printf("BLOCK Variables:\n");
    for(int j=0;j<i[l];j++){
        printf("%s %s\n",end->vbltable[j],end->varname[j]);
    }
    i[l]=0;
    l--;
    end=end->prev;
    end->next=NULL;
    strcpy(t,"none");
;}
    break;

  case 42:
#line 263 "parser.y"
    {
    l++;
    struct Node *newnode;
    newnode=NULL;
    newnode = (struct Node*)malloc(sizeof(struct Node));
    end->next=newnode;
    newnode->prev=end;
    newnode->next=NULL;
    end=newnode;
;}
    break;

  case 43:
#line 272 "parser.y"
    {
    printf("BLOCK Variables:\n");
    for(int j=0;j<i[l];j++){
        printf("%s %s\n",end->vbltable[j],end->varname[j]);
    }
    i[l]=0;
    l--;
    end=end->prev;
    end->next=NULL;
    strcpy(t,"none");
    fp = fopen("output.ll", "a") ;
    strcpy(adder,"");
    strcpy(adder,"");
    sprintf(adder,"\t br label %%%d\n",tmpid);
    fprintf(fp,"%s\n",adder);
    sprintf(adder,"%d:",tmpid);
    jumper[jumpid]=tmpid;
    jumpid++;
    fprintf(fp,"%s\n",adder);
    tmpid++;
    fclose(fp);
    FILE *fpcpy;
    
    printf("HELLO\n");
    fpcpy=fopen("output.ll","r");
    printf("THE LINES IN THE FILE\n");
    
    while(fgets(lines[linecount],1000,fpcpy)){
        lines[linecount][strlen(lines[linecount])-1]='\0';
        linecount++;
    }
    fclose(fpcpy);
    for(int j=0;j<linecount;j++){
        for(int k=0;k<strlen(lines[j]);k++){
            if(lines[j][k]=='_'){
                sprintf(adder,"%%%d",jumper[0]);
                lines[j][k]=adder[0];
                lines[j][k+1]=adder[1];
                if(strlen(adder)>1)
                    lines[j][k+2]=adder[2];
                else 
                    lines[j][k+2]=' ';
            }
            else if(lines[j][k]=='@' && lines[j][k+1]=='@'){
                sprintf(adder,"%%%d",jumper[1]);
                lines[j][k]=adder[0];
                lines[j][k+1]=adder[1];
                if(strlen(adder)>1)
                    lines[j][k+2]=adder[2];
                else 
                    lines[j][k+2]=' ';
            }
            else if(lines[j][k]=='&'){
                sprintf(adder,"%%%d",jumper[2]);
                lines[j][k]=adder[0];
                lines[j][k+1]=adder[1];
                if(strlen(adder)>1)
                    lines[j][k+2]=adder[2];
                else 
                    lines[j][k+2]=' ';
            }
        }
        //printf("\n");
        strcpy(adder,"");
    }
    system("rm output.ll");
    fp = fopen("output.ll", "a") ;
    for(int j=0;j<linecount;j++){
        printf("%s\n",lines[j]);
        fprintf(fp,"%s\n",lines[j]);
    }
    linecount=0;
    jumpid=0;
    fclose(fp);
;}
    break;

  case 45:
#line 347 "parser.y"
    {strcpy(op,"sgt");;}
    break;

  case 53:
#line 349 "parser.y"
    {
    fp = fopen("output.ll", "a") ;
    sprintf(adder,"\t %%%d = icmp %s i32 %%%d , %%%d\n",tmpid,op,tmpid-2,tmpid-1);
    tmpid++;
    fprintf(fp,"%s\n",adder);
    fclose(fp);
;}
    break;

  case 55:
#line 356 "parser.y"
    {
    fp = fopen("output.ll", "a") ;
    tmpid--;
    sprintf(adder,"\t br i1 %%%d, label %%%d, label @@@ \n",tmpid,tmpid+1);
    tmpid++;
    fprintf(fp,"%s\n",adder);
    strcpy(adder,"");
    sprintf(adder,"%d:",tmpid);
    jumper[jumpid]=tmpid;
    jumpid++;
    fprintf(fp,"%s\n",adder);
    tmpid++;
    fclose(fp);
;}
    break;

  case 56:
#line 369 "parser.y"
    {
    fp = fopen("output.ll", "a") ;
    tmpid--;
    sprintf(adder,"\t br i1 %%%d, label ___, label %%%d\n",tmpid,tmpid+1);
    tmpid++;
    fprintf(fp,"%s",adder);
    strcpy(adder,"");
    sprintf(adder,"%d:",tmpid);
    fprintf(fp,"%s\n",adder);
    tmpid++;
    fclose(fp);
;}
    break;

  case 57:
#line 380 "parser.y"
    {
    fp = fopen("output.ll", "a") ;
    tmpid--;
    sprintf(adder,"\t br i1 %%%d, label %%%d, label @@@\n",tmpid,tmpid+1);
    tmpid++;
    fprintf(fp,"%s\n",adder);
    sprintf(adder,"%d:",tmpid);
    jumper[jumpid]=tmpid;
    jumpid++;
    fprintf(fp,"%s\n",adder);
    tmpid++;
    fclose(fp);
;}
    break;

  case 58:
#line 393 "parser.y"
    {
    l++;
    struct Node *newnode;
    newnode=NULL;
    newnode = (struct Node*)malloc(sizeof(struct Node));
    end->next=newnode;
    newnode->prev=end;
    newnode->next=NULL;
    end=newnode;
;}
    break;

  case 59:
#line 402 "parser.y"
    {
    printf("BLOCK Variables:\n");
    for(int j=0;j<i[l];j++){
        printf("%s %s\n",end->vbltable[j],end->varname[j]);
    }
    i[l]=0;
    l--;
    end=end->prev;
    end->next=NULL;
    strcpy(t,"none");
;}
    break;

  case 60:
#line 413 "parser.y"
    {
    l++;
    struct Node *newnode;
    newnode=NULL;
    newnode = (struct Node*)malloc(sizeof(struct Node));
    end->next=newnode;
    newnode->prev=end;
    newnode->next=NULL;
    end=newnode;
;}
    break;

  case 61:
#line 422 "parser.y"
    {
    printf("BLOCK Variables:\n");
    for(int j=0;j<i[l];j++){
        printf("%s %s\n",end->vbltable[j],end->varname[j]);
    }
    i[l]=0;
    l--;
    end=end->prev;
    end->next=NULL;
    strcpy(t,"none");
;}
    break;


/* Line 1267 of yacc.c.  */
#line 2024 "parser.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 433 "parser.y"


int main()
{
    typestorer=NULL;
    end=NULL;
    typestorer = (struct Node*)malloc(sizeof(struct Node));
    typestorer->prev=NULL;
    typestorer->next=NULL;
    end = typestorer;
    yyparse();
    for(int j=0;j<i[0];j++){
        printf("%s %s\n",end->vbltable[j],end->varname[j]);
    }
    for(int j=0;j<jumpid;j++)
        printf("%d\n",jumper[j]);
}

int checkexist(char* name){
    printf("Checker %s\n",name);
    for(int j=0;j<i[0];j++){
        if(strcmp(name,end->varname[j])==0){
            return j;
        }
    }
    return -1;
}

char* typereturner(struct Node* check,char* name){
    int kcpy=l;
    struct Node* checkcpy=check;
    while(checkcpy!=NULL){
        for(int j=0;j<i[kcpy];j++){
            if(strcmp(name,checkcpy->varname[j])==0){
                return checkcpy->vbltable[j];
            }
        }
        kcpy--;
        checkcpy=checkcpy->prev;
    }
    return NULL;
}

int ircheckexist(struct Node* check,char* name){
    int kcpy=l;
    int returner=0;
    int total=0;
    int flag=0;
    struct Node* checkcpy=check;
    while(checkcpy!=NULL){
        for(int j=0;j<i[kcpy];j++){
            if(strcmp(name,checkcpy->varname[j])==0){
                flag=1;
            }
            if(flag==0)
                returner++;
        }
        kcpy--;
        checkcpy=checkcpy->prev;
    }
    return returner;
}


