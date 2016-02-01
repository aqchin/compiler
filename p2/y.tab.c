
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 1



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 11 "parser.y"


/* Just like lex, the text within this first region delimited by %{ and %}
 * is assumed to be C/C++ code and will be copied verbatim to the y.tab.c
 * file ahead of the definitions of the yyparse() function. Add other header
 * file inclusions or C++ variable declarations/prototypes that are needed
 * by your code here.
 */
#include "scanner.h" // for yylex
#include "parser.h"
#include "errors.h"

void yyerror(const char *msg); // standard error-handling routine



/* Line 189 of yacc.c  */
#line 90 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
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

/* "%code requires" blocks.  */

/* Line 209 of yacc.c  */
#line 42 "parser.y"

    struct Function {
        Type *tp;
        Identifier *id;
    };
    
    struct FunctionParam {
        Type *tp;
        Identifier *id;
        List<VarDecl*> *pList;
    };
    
    struct NStmtBlock {
        List<VarDecl*> *vList;
        List<Stmt*> *sList;
    };
    
    struct ThenElse {
        Stmt *thenB;
        Stmt *elseB;
    };
    
    struct ForRest {
        Expr *test;
        Expr *step;
    };




/* Line 209 of yacc.c  */
#line 145 "y.tab.c"

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     T_Void = 258,
     T_Bool = 259,
     T_Int = 260,
     T_Float = 261,
     T_LessEqual = 262,
     T_GreaterEqual = 263,
     T_EqOp = 264,
     T_NotEqual = 265,
     T_Dims = 266,
     T_And = 267,
     T_Or = 268,
     T_While = 269,
     T_For = 270,
     T_If = 271,
     T_Else = 272,
     T_Return = 273,
     T_Break = 274,
     T_Inc = 275,
     T_Dec = 276,
     T_Switch = 277,
     T_Case = 278,
     T_Default = 279,
     T_UInt = 280,
     T_BVec2 = 281,
     T_BVec3 = 282,
     T_BVec4 = 283,
     T_IVec2 = 284,
     T_IVec3 = 285,
     T_IVec4 = 286,
     T_UVec2 = 287,
     T_UVec3 = 288,
     T_UVec4 = 289,
     T_Vec2 = 290,
     T_Vec3 = 291,
     T_Vec4 = 292,
     T_Struct = 293,
     T_In = 294,
     T_Out = 295,
     T_InOut = 296,
     T_Const = 297,
     T_Uniform = 298,
     T_Layout = 299,
     T_Continue = 300,
     T_Do = 301,
     T_TypeName = 302,
     T_FieldSelection = 303,
     T_Mat2 = 304,
     T_Mat3 = 305,
     T_Mat4 = 306,
     T_MulAssign = 307,
     T_DivAssign = 308,
     T_AddAssign = 309,
     T_SubAssign = 310,
     T_LeftParen = 311,
     T_RightParen = 312,
     T_LeftBrace = 313,
     T_RightBrace = 314,
     T_Dot = 315,
     T_Colon = 316,
     T_Equal = 317,
     T_Semicolon = 318,
     T_Dash = 319,
     T_Plus = 320,
     T_Star = 321,
     T_Slash = 322,
     T_LeftAngle = 323,
     T_RightAngle = 324,
     T_Identifier = 325,
     T_IntConstant = 326,
     T_FloatConstant = 327,
     T_BoolConstant = 328,
     T_Field_Selection = 329,
     NOELSE = 330,
     T_ELSE = 331
   };
#endif
/* Tokens.  */
#define T_Void 258
#define T_Bool 259
#define T_Int 260
#define T_Float 261
#define T_LessEqual 262
#define T_GreaterEqual 263
#define T_EqOp 264
#define T_NotEqual 265
#define T_Dims 266
#define T_And 267
#define T_Or 268
#define T_While 269
#define T_For 270
#define T_If 271
#define T_Else 272
#define T_Return 273
#define T_Break 274
#define T_Inc 275
#define T_Dec 276
#define T_Switch 277
#define T_Case 278
#define T_Default 279
#define T_UInt 280
#define T_BVec2 281
#define T_BVec3 282
#define T_BVec4 283
#define T_IVec2 284
#define T_IVec3 285
#define T_IVec4 286
#define T_UVec2 287
#define T_UVec3 288
#define T_UVec4 289
#define T_Vec2 290
#define T_Vec3 291
#define T_Vec4 292
#define T_Struct 293
#define T_In 294
#define T_Out 295
#define T_InOut 296
#define T_Const 297
#define T_Uniform 298
#define T_Layout 299
#define T_Continue 300
#define T_Do 301
#define T_TypeName 302
#define T_FieldSelection 303
#define T_Mat2 304
#define T_Mat3 305
#define T_Mat4 306
#define T_MulAssign 307
#define T_DivAssign 308
#define T_AddAssign 309
#define T_SubAssign 310
#define T_LeftParen 311
#define T_RightParen 312
#define T_LeftBrace 313
#define T_RightBrace 314
#define T_Dot 315
#define T_Colon 316
#define T_Equal 317
#define T_Semicolon 318
#define T_Dash 319
#define T_Plus 320
#define T_Star 321
#define T_Slash 322
#define T_LeftAngle 323
#define T_RightAngle 324
#define T_Identifier 325
#define T_IntConstant 326
#define T_FloatConstant 327
#define T_BoolConstant 328
#define T_Field_Selection 329
#define NOELSE 330
#define T_ELSE 331




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 71 "parser.y"

    int integerConstant;
    bool boolConstant;
    char *stringConstant;
    double doubleConstant;
    float floatConstant;
    char identifier[MaxIdentLen+1]; // +1 for terminating null
    Decl *decl;
    List<Decl*> *declList;
    VarDecl *varDecl;
    Type *type;
    Identifier *ident;
    Expr *expr;
    FnDecl *fnDecl;
    Operator *op;
    Stmt *stmt;
    AssignExpr *assignExpr;
    LoopStmt *loopStmt;
    ForStmt *forStmt;
    WhileStmt *whileStmt;
    IfStmt *ifStmt;
    SwitchStmt *switchStmt;
    IntConstant *intConstant;
    Case *cas;
    Program *program;

    struct Function func;
    
    struct FunctionParam funcParam;
    
    struct NStmtBlock stmtBlk;
    
    struct ThenElse teStmt;
    
    struct ForRest tsStmt;



/* Line 214 of yacc.c  */
#line 353 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 378 "y.tab.c"

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
# if YYENABLE_NLS
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
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
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
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  24
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   354

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  92
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  58
/* YYNRULES -- Number of rules.  */
#define YYNRULES  116
/* YYNRULES -- Number of states.  */
#define YYNSTATES  176

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   331

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      77,    78,    82,    80,    88,    81,    79,    83,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    91,    87,
      84,    86,    85,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    89,     2,    90,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    11,    13,    15,    19,
      21,    25,    28,    31,    33,    36,    39,    42,    44,    46,
      48,    52,    56,    58,    62,    66,    68,    70,    74,    78,
      82,    86,    88,    92,    96,    98,   100,   102,   104,   108,
     110,   112,   116,   118,   120,   124,   126,   128,   130,   132,
     134,   136,   139,   142,   145,   147,   149,   152,   156,   160,
     163,   165,   167,   169,   171,   174,   176,   178,   180,   182,
     184,   186,   188,   190,   192,   194,   196,   198,   200,   202,
     204,   206,   208,   210,   212,   214,   216,   218,   220,   223,
     227,   230,   234,   236,   239,   241,   244,   250,   254,   256,
     258,   263,   271,   273,   277,   280,   283,   289,   296,   298,
     300,   303,   307,   310,   312,   314,   316
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      93,     0,    -1,   147,    -1,    70,    -1,    94,    -1,    71,
      -1,    72,    -1,    73,    -1,    77,   113,    78,    -1,    95,
      -1,    96,    79,    74,    -1,    96,    20,    -1,    96,    21,
      -1,    96,    -1,    20,    97,    -1,    21,    97,    -1,    98,
      97,    -1,    80,    -1,    81,    -1,    97,    -1,    99,    82,
      97,    -1,    99,    83,    97,    -1,    99,    -1,   100,    80,
      99,    -1,   100,    81,    99,    -1,   100,    -1,   101,    -1,
     102,    84,   101,    -1,   102,    85,   101,    -1,   102,     7,
     101,    -1,   102,     8,   101,    -1,   102,    -1,   103,     9,
     102,    -1,   103,    10,   102,    -1,   103,    -1,   104,    -1,
     105,    -1,   106,    -1,   107,    12,   106,    -1,   107,    -1,
     108,    -1,   109,    13,   108,    -1,   109,    -1,   110,    -1,
      97,   112,   111,    -1,    86,    -1,    52,    -1,    53,    -1,
      54,    -1,    55,    -1,   111,    -1,   115,    87,    -1,   122,
      87,    -1,   116,    78,    -1,   118,    -1,   117,    -1,   118,
     120,    -1,   117,    88,   120,    -1,   124,    70,    77,    -1,
     125,    70,    -1,   119,    -1,   121,    -1,   125,    -1,   123,
      -1,   124,    70,    -1,   125,    -1,   126,    -1,     3,    -1,
       6,    -1,     5,    -1,    35,    -1,    36,    -1,    37,    -1,
      49,    -1,    50,    -1,    51,    -1,   111,    -1,   132,    -1,
     131,    -1,   133,    -1,   131,    -1,   133,    -1,   131,    -1,
     135,    -1,   136,    -1,   139,    -1,   142,    -1,   143,    -1,
      89,    90,    -1,    89,   134,    90,    -1,    89,    90,    -1,
      89,   134,    90,    -1,   128,    -1,   134,   128,    -1,    87,
      -1,   113,    87,    -1,    16,    77,   113,    78,   137,    -1,
     130,    17,   130,    -1,   130,    -1,   113,    -1,   124,    70,
       9,   127,    -1,    22,    77,   113,    78,    89,   140,    90,
      -1,   134,    -1,    23,    71,    91,    -1,    24,    91,    -1,
     141,   140,    -1,    14,    77,   138,    78,   128,    -1,    15,
      77,   144,   146,    78,   129,    -1,   135,    -1,   138,    -1,
     145,    87,    -1,   145,    87,   113,    -1,   147,   148,    -1,
     148,    -1,   149,    -1,   114,    -1,   115,   133,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   222,   222,   238,   241,   242,   243,   244,   245,   248,
     249,   250,   251,   261,   262,   263,   264,   267,   268,   271,
     272,   273,   276,   277,   278,   281,   284,   285,   286,   287,
     288,   291,   292,   293,   296,   299,   302,   305,   306,   309,
     312,   313,   316,   319,   320,   323,   324,   325,   326,   327,
     330,   336,   337,   340,   343,   344,   347,   351,   355,   360,
     363,   364,   367,   370,   373,   376,   379,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   393,   399,   400,   403,
     404,   407,   408,   411,   412,   413,   414,   415,   418,   419,
     422,   423,   426,   429,   434,   435,   438,   441,   444,   449,
     450,   455,   458,   461,   462,   465,   468,   469,   472,   475,
     478,   481,   486,   487,   490,   491,   494
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_Void", "T_Bool", "T_Int", "T_Float",
  "T_LessEqual", "T_GreaterEqual", "T_EqOp", "T_NotEqual", "T_Dims",
  "T_And", "T_Or", "T_While", "T_For", "T_If", "T_Else", "T_Return",
  "T_Break", "T_Inc", "T_Dec", "T_Switch", "T_Case", "T_Default", "T_UInt",
  "T_BVec2", "T_BVec3", "T_BVec4", "T_IVec2", "T_IVec3", "T_IVec4",
  "T_UVec2", "T_UVec3", "T_UVec4", "T_Vec2", "T_Vec3", "T_Vec4",
  "T_Struct", "T_In", "T_Out", "T_InOut", "T_Const", "T_Uniform",
  "T_Layout", "T_Continue", "T_Do", "T_TypeName", "T_FieldSelection",
  "T_Mat2", "T_Mat3", "T_Mat4", "T_MulAssign", "T_DivAssign",
  "T_AddAssign", "T_SubAssign", "T_LeftParen", "T_RightParen",
  "T_LeftBrace", "T_RightBrace", "T_Dot", "T_Colon", "T_Equal",
  "T_Semicolon", "T_Dash", "T_Plus", "T_Star", "T_Slash", "T_LeftAngle",
  "T_RightAngle", "T_Identifier", "T_IntConstant", "T_FloatConstant",
  "T_BoolConstant", "T_Field_Selection", "NOELSE", "T_ELSE", "'('", "')'",
  "'.'", "'+'", "'-'", "'*'", "'/'", "'<'", "'>'", "'='", "';'", "','",
  "'{'", "'}'", "':'", "$accept", "Program", "Var_Ident", "Prim_Expr",
  "Post_Expr", "Un_Expr", "Un_Op", "Mult_Expr", "Add_Expr", "Sh_Expr",
  "Rela_Expr", "Eq_Expr", "And_Expr", "Excl_Or_Expr", "Incl_Or_Expr",
  "Log_And_Expr", "Log_Xor_Expr", "Log_Or_Expr", "Cond_Expr",
  "Assign_Expr", "Assign_Op", "Expr", "Decl", "Fn_Proto", "Fn_Declor",
  "Fn_Hdr_Param", "Fn_Hdr", "Param_Declor", "Param_Decl", "Param_T_Spec",
  "Init_DeclorList", "Sing_Decl", "Full_Spec_T", "Type_Spec",
  "Type_Spec_NArr", "Init", "Stmt", "Stmt_No_Scope", "Stmt_Scope",
  "Simp_Stmt", "Comp_Stmt_Scope", "Comp_Stmt_No_Scope", "StmtList",
  "Expr_Stmt", "Sel_Stmt", "Sel_Rest_Stmt", "Cond", "Swi_Stmt",
  "Swi_StmtList", "Case_Lbl", "Case_Stmt", "Iter_Stmt", "For_Init_Stmt",
  "Cond_Op", "For_Rest_Stmt", "Trans_U", "Ext_Decl", "Fn_Def", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,    40,    41,    46,
      43,    45,    42,    47,    60,    62,    61,    59,    44,   123,
     125,    58
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    92,    93,    94,    95,    95,    95,    95,    95,    96,
      96,    96,    96,    97,    97,    97,    97,    98,    98,    99,
      99,    99,   100,   100,   100,   101,   102,   102,   102,   102,
     102,   103,   103,   103,   104,   105,   106,   107,   107,   108,
     109,   109,   110,   111,   111,   112,   112,   112,   112,   112,
     113,   114,   114,   115,   116,   116,   117,   117,   118,   119,
     120,   120,   121,   122,   123,   124,   125,   126,   126,   126,
     126,   126,   126,   126,   126,   126,   127,   128,   128,   129,
     129,   130,   130,   131,   131,   131,   131,   131,   132,   132,
     133,   133,   134,   134,   135,   135,   136,   137,   137,   138,
     138,   139,   140,   141,   141,   142,   143,   143,   144,   145,
     146,   146,   147,   147,   148,   148,   149
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     3,     1,
       3,     2,     2,     1,     2,     2,     2,     1,     1,     1,
       3,     3,     1,     3,     3,     1,     1,     3,     3,     3,
       3,     1,     3,     3,     1,     1,     1,     1,     3,     1,
       1,     3,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     2,     2,     2,     1,     1,     2,     3,     3,     2,
       1,     1,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     3,
       2,     3,     1,     2,     1,     2,     5,     3,     1,     1,
       4,     7,     1,     3,     2,     2,     5,     6,     1,     1,
       2,     3,     2,     1,     1,     1,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    67,    69,    68,    70,    71,    72,    73,    74,    75,
       0,   115,     0,     0,    55,    54,     0,    63,     0,    65,
      66,     2,   113,   114,     1,    51,     0,   116,    53,     0,
      60,    56,    61,    62,    52,    64,   112,     0,     0,     0,
       0,     0,     0,     0,     0,     3,     5,     6,     7,     0,
      17,    18,    94,     0,    90,     4,     9,    13,    19,     0,
      22,    25,    26,    31,    34,    35,    36,    37,    39,    40,
      42,    43,    50,     0,    92,    78,    77,     0,    83,    84,
      85,     0,    86,    87,    57,    59,    58,     0,     0,     0,
      14,    15,     0,     0,   104,     0,    88,     0,    11,    12,
       0,    46,    47,    48,    49,    45,     0,    16,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      95,    91,    93,   102,   105,    99,     0,     0,   108,     0,
       0,     0,   103,     8,    89,    10,    44,    20,    21,    19,
      23,    24,    29,    30,    27,    28,    32,    33,    38,    41,
       0,     0,   109,     0,     0,     0,     0,     0,   106,   110,
       0,    98,    82,    81,    96,     0,    76,   100,   111,   107,
      80,    79,     0,     0,    97,   101
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    10,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
     106,    73,    11,    12,    13,    14,    15,    30,    31,    32,
      16,    17,    18,    19,    20,   167,    74,   169,   161,    75,
      76,   163,   123,    78,    79,   164,   127,    80,   124,    81,
      82,    83,   129,   153,   154,    21,    22,    23
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -135
static const yytype_int16 yypact[] =
{
     303,  -135,  -135,  -135,  -135,  -135,  -135,  -135,  -135,  -135,
      12,  -135,   -65,   -53,   -56,   303,   -47,  -135,    -6,  -135,
    -135,   303,  -135,  -135,  -135,  -135,    37,  -135,  -135,   303,
    -135,  -135,  -135,    -2,  -135,   -21,  -135,    22,    23,    35,
     230,   230,    36,    44,    25,  -135,  -135,  -135,  -135,   230,
    -135,  -135,  -135,    82,  -135,  -135,  -135,   -14,   -44,   230,
     -37,   -18,  -135,    10,    57,  -135,  -135,  -135,   107,  -135,
     108,  -135,  -135,    33,  -135,  -135,  -135,   114,  -135,  -135,
    -135,   191,  -135,  -135,  -135,  -135,  -135,    -1,   217,   230,
    -135,  -135,   230,    31,  -135,    45,  -135,   159,  -135,  -135,
      51,  -135,  -135,  -135,  -135,  -135,   230,  -135,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
    -135,  -135,  -135,   191,  -135,  -135,    61,    54,  -135,    -1,
      55,    62,  -135,  -135,  -135,  -135,  -135,  -135,  -135,  -135,
     -37,   -37,  -135,  -135,  -135,  -135,    10,    10,  -135,  -135,
     130,   191,  -135,    56,    63,   204,    53,   230,  -135,   230,
     204,   127,  -135,  -135,  -135,   191,  -135,  -135,  -135,  -135,
    -135,  -135,   204,    59,  -135,  -135
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -135,  -135,  -135,  -135,  -135,   -26,  -135,   -36,  -135,   -84,
     -39,  -135,  -135,  -135,    27,  -135,    28,  -135,  -135,  -103,
    -135,   -48,  -135,  -135,  -135,  -135,  -135,  -135,   117,  -135,
    -135,  -135,   -74,     8,  -135,  -135,   -50,  -135,   -22,  -134,
    -135,   -12,   -10,    68,  -135,  -135,    29,  -135,    -8,  -135,
    -135,  -135,  -135,  -135,  -135,  -135,   139,  -135
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      27,    95,     1,   136,     2,     3,    98,    99,   101,   102,
     103,   104,    24,   126,    90,    91,    77,   112,   113,    40,
      41,   162,    25,    33,    26,    28,   170,   122,   142,   143,
     144,   145,    29,   107,     4,     5,     6,    33,   162,   125,
      34,   130,   105,    97,   131,   108,   109,   122,     7,     8,
       9,    37,    38,    39,   166,   126,    86,    40,    41,    42,
      43,    44,   110,   111,    35,   100,   116,   117,    85,    45,
      46,    47,    48,   122,   140,   141,    49,   146,   147,    50,
      51,   125,   137,   138,   139,   139,   139,   139,   139,   139,
     139,   139,   139,   139,   114,   115,    37,    38,    39,    87,
      88,   158,    40,    41,    42,    43,    44,    45,    46,    47,
      48,   168,    89,    92,    49,    93,    94,    50,    51,   118,
     120,   119,   132,   133,    52,   135,    53,    54,    37,    38,
      39,   150,   151,   155,    40,    41,    42,    43,    44,   157,
     156,   160,   165,   159,   172,   148,    84,   149,   171,   175,
     174,     0,    45,    46,    47,    48,   128,   173,   152,    49,
      36,     0,    50,    51,     0,     0,     0,     0,     0,    52,
       0,    53,    96,    37,    38,    39,     0,     0,     0,    40,
      41,    42,    43,    44,    45,    46,    47,    48,     0,     0,
       0,    49,     0,     0,    50,    51,     0,     0,     0,     0,
       0,    52,     0,    53,   121,    37,    38,    39,     0,     0,
       0,    40,    41,    42,    43,    44,     0,     0,    37,    38,
      39,     0,     0,     0,    40,    41,    42,    43,    44,    45,
      46,    47,    48,     0,     0,     0,    49,    40,    41,    50,
      51,     0,     0,     0,     0,     0,    52,     0,    53,   134,
      40,    41,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    45,    46,    47,    48,     0,     0,     0,    49,     0,
       0,    50,    51,     0,    45,    46,    47,    48,    52,     0,
      53,    49,     0,     0,    50,    51,     0,    45,    46,    47,
      48,    52,     0,    26,    49,     0,     0,    50,    51,     0,
      45,    46,    47,    48,    52,     0,     1,    49,     2,     3,
      50,    51,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     4,     5,
       6,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     7,     8,     9
};

static const yytype_int16 yycheck[] =
{
      12,    49,     3,   106,     5,     6,    20,    21,    52,    53,
      54,    55,     0,    87,    40,    41,    26,     7,     8,    20,
      21,   155,    87,    15,    89,    78,   160,    77,   112,   113,
     114,   115,    88,    59,    35,    36,    37,    29,   172,    87,
      87,    89,    86,    53,    92,    82,    83,    97,    49,    50,
      51,    14,    15,    16,   157,   129,    77,    20,    21,    22,
      23,    24,    80,    81,    70,    79,     9,    10,    70,    70,
      71,    72,    73,   123,   110,   111,    77,   116,   117,    80,
      81,   129,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,    84,    85,    14,    15,    16,    77,
      77,   151,    20,    21,    22,    23,    24,    70,    71,    72,
      73,   159,    77,    77,    77,    71,    91,    80,    81,    12,
      87,    13,    91,    78,    87,    74,    89,    90,    14,    15,
      16,    70,    78,    78,    20,    21,    22,    23,    24,     9,
      78,    78,    89,    87,    17,   118,    29,   119,   160,    90,
     172,    -1,    70,    71,    72,    73,    88,   165,   129,    77,
      21,    -1,    80,    81,    -1,    -1,    -1,    -1,    -1,    87,
      -1,    89,    90,    14,    15,    16,    -1,    -1,    -1,    20,
      21,    22,    23,    24,    70,    71,    72,    73,    -1,    -1,
      -1,    77,    -1,    -1,    80,    81,    -1,    -1,    -1,    -1,
      -1,    87,    -1,    89,    90,    14,    15,    16,    -1,    -1,
      -1,    20,    21,    22,    23,    24,    -1,    -1,    14,    15,
      16,    -1,    -1,    -1,    20,    21,    22,    23,    24,    70,
      71,    72,    73,    -1,    -1,    -1,    77,    20,    21,    80,
      81,    -1,    -1,    -1,    -1,    -1,    87,    -1,    89,    90,
      20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    -1,    -1,    -1,    77,    -1,
      -1,    80,    81,    -1,    70,    71,    72,    73,    87,    -1,
      89,    77,    -1,    -1,    80,    81,    -1,    70,    71,    72,
      73,    87,    -1,    89,    77,    -1,    -1,    80,    81,    -1,
      70,    71,    72,    73,    87,    -1,     3,    77,     5,     6,
      80,    81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    36,
      37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    49,    50,    51
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     5,     6,    35,    36,    37,    49,    50,    51,
      93,   114,   115,   116,   117,   118,   122,   123,   124,   125,
     126,   147,   148,   149,     0,    87,    89,   133,    78,    88,
     119,   120,   121,   125,    87,    70,   148,    14,    15,    16,
      20,    21,    22,    23,    24,    70,    71,    72,    73,    77,
      80,    81,    87,    89,    90,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   113,   128,   131,   132,   134,   135,   136,
     139,   141,   142,   143,   120,    70,    77,    77,    77,    77,
      97,    97,    77,    71,    91,   113,    90,   134,    20,    21,
      79,    52,    53,    54,    55,    86,   112,    97,    82,    83,
      80,    81,     7,     8,    84,    85,     9,    10,    12,    13,
      87,    90,   128,   134,   140,   113,   124,   138,   135,   144,
     113,   113,    91,    78,    90,    74,   111,    97,    97,    97,
      99,    99,   101,   101,   101,   101,   102,   102,   106,   108,
      70,    78,   138,   145,   146,    78,    78,     9,   128,    87,
      78,   130,   131,   133,   137,    89,   111,   127,   113,   129,
     131,   133,    17,   140,   130,    90
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
# if YYLTYPE_IS_TRIVIAL
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
		  Type, Value, Location); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
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
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Location data for the lookahead symbol.  */
YYLTYPE yylloc;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.
       `yyls': related to locations.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[2];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;
  yylsp = yyls;

#if YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 1;
#endif

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
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);

	yyls = yyls1;
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
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
	YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
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

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;
  *++yylsp = yylloc;
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 222 "parser.y"
    {
                                      (yylsp[(1) - (1)]);
                                      /* pp2: The @1 is needed to convince
                                       * yacc to set up yylloc. You can remove
                                       * it once you have other uses of @n*/
                                      Program *program = new Program((yyvsp[(1) - (1)].declList));
                                      // if no errors, advance to next phase
                                      if (ReportError::NumErrors() == 0) 
                                          program->Print(0);
                                    }
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 238 "parser.y"
    { (yyval.ident) = new Identifier((yylsp[(1) - (1)]),(yyvsp[(1) - (1)].identifier)); }
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 241 "parser.y"
    { (yyval.expr) = new VarExpr((yylsp[(1) - (1)]),(yyvsp[(1) - (1)].ident)); }
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 242 "parser.y"
    { (yyval.expr) = new IntConstant((yylsp[(1) - (1)]),(yyvsp[(1) - (1)].integerConstant)); }
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 243 "parser.y"
    { (yyval.expr) = new FloatConstant((yylsp[(1) - (1)]),(yyvsp[(1) - (1)].floatConstant)); }
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 244 "parser.y"
    { (yyval.expr) = new BoolConstant((yylsp[(1) - (1)]),(yyvsp[(1) - (1)].boolConstant)); }
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 245 "parser.y"
    { (yyval.expr) = (yyvsp[(2) - (3)].expr); }
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 248 "parser.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); }
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 249 "parser.y"
    { (yyval.expr) = new FieldAccess((yyvsp[(1) - (3)].expr),new Identifier((yylsp[(3) - (3)]),(yyvsp[(3) - (3)].identifier))); }
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 250 "parser.y"
    { (yyval.expr) = new PostfixExpr((yyvsp[(1) - (2)].expr),new Operator((yylsp[(2) - (2)]),"++")); }
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 251 "parser.y"
    { (yyval.expr) = new PostfixExpr((yyvsp[(1) - (2)].expr),new Operator((yylsp[(2) - (2)]),"--")); }
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 261 "parser.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); }
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 262 "parser.y"
    { (yyval.expr) = new ArithmeticExpr(new Operator((yylsp[(1) - (2)]),"++"),(yyvsp[(2) - (2)].expr)); }
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 263 "parser.y"
    { (yyval.expr) = new ArithmeticExpr(new Operator((yylsp[(1) - (2)]),"--"),(yyvsp[(2) - (2)].expr)); }
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 264 "parser.y"
    { (yyval.expr) = new ArithmeticExpr((yyvsp[(1) - (2)].op),(yyvsp[(2) - (2)].expr)); }
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 267 "parser.y"
    { (yyval.op) = new Operator((yylsp[(1) - (1)]),"+"); }
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 268 "parser.y"
    { (yyval.op) = new Operator((yylsp[(1) - (1)]),"-"); }
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 271 "parser.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); }
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 272 "parser.y"
    { (yyval.expr) = new ArithmeticExpr((yyvsp[(1) - (3)].expr),new Operator((yylsp[(2) - (3)]),"*"),(yyvsp[(3) - (3)].expr)); }
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 273 "parser.y"
    { (yyval.expr) = new ArithmeticExpr((yyvsp[(1) - (3)].expr),new Operator((yylsp[(2) - (3)]),"/"),(yyvsp[(3) - (3)].expr)); }
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 276 "parser.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); }
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 277 "parser.y"
    { (yyval.expr) = new ArithmeticExpr((yyvsp[(1) - (3)].expr),new Operator((yylsp[(2) - (3)]),"+"),(yyvsp[(3) - (3)].expr)); }
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 278 "parser.y"
    { (yyval.expr) = new ArithmeticExpr((yyvsp[(1) - (3)].expr),new Operator((yylsp[(2) - (3)]),"-"),(yyvsp[(3) - (3)].expr)); }
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 281 "parser.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); }
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 284 "parser.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); }
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 285 "parser.y"
    { (yyval.expr) = new RelationalExpr((yyvsp[(1) - (3)].expr),new Operator((yylsp[(2) - (3)]),"<"),(yyvsp[(3) - (3)].expr)); }
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 286 "parser.y"
    { (yyval.expr) = new RelationalExpr((yyvsp[(1) - (3)].expr),new Operator((yylsp[(2) - (3)]),">"),(yyvsp[(3) - (3)].expr)); }
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 287 "parser.y"
    { (yyval.expr) = new RelationalExpr((yyvsp[(1) - (3)].expr),new Operator((yylsp[(2) - (3)]),"<="),(yyvsp[(3) - (3)].expr)); }
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 288 "parser.y"
    { (yyval.expr) = new RelationalExpr((yyvsp[(1) - (3)].expr),new Operator((yylsp[(2) - (3)]),">="),(yyvsp[(3) - (3)].expr)); }
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 291 "parser.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); }
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 292 "parser.y"
    { (yyval.expr) = new EqualityExpr((yyvsp[(1) - (3)].expr),new Operator((yylsp[(2) - (3)]),"=="),(yyvsp[(3) - (3)].expr)); }
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 293 "parser.y"
    { (yyval.expr) = new EqualityExpr((yyvsp[(1) - (3)].expr),new Operator((yylsp[(2) - (3)]),"!="),(yyvsp[(3) - (3)].expr)); }
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 296 "parser.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); }
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 299 "parser.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); }
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 302 "parser.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); }
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 305 "parser.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); }
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 306 "parser.y"
    { (yyval.expr) = new LogicalExpr((yyvsp[(1) - (3)].expr),new Operator((yylsp[(2) - (3)]),"&&"),(yyvsp[(3) - (3)].expr)); }
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 309 "parser.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); }
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 312 "parser.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); }
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 313 "parser.y"
    { (yyval.expr) = new LogicalExpr((yyvsp[(1) - (3)].expr),new Operator((yylsp[(2) - (3)]),"||"),(yyvsp[(3) - (3)].expr)); }
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 316 "parser.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); }
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 319 "parser.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); }
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 320 "parser.y"
    { (yyval.expr) = new AssignExpr((yyvsp[(1) - (3)].expr),(yyvsp[(2) - (3)].op),(yyvsp[(3) - (3)].expr)); }
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 323 "parser.y"
    { (yyval.op) = new Operator((yylsp[(1) - (1)]),"="); }
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 324 "parser.y"
    { (yyval.op) = new Operator((yylsp[(1) - (1)]),"*="); }
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 325 "parser.y"
    { (yyval.op) = new Operator((yylsp[(1) - (1)]),"/="); }
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 326 "parser.y"
    { (yyval.op) = new Operator((yylsp[(1) - (1)]),"+="); }
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 327 "parser.y"
    { (yyval.op) = new Operator((yylsp[(1) - (1)]),"-="); }
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 330 "parser.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); }
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 336 "parser.y"
    { (yyval.decl) = (yyvsp[(1) - (2)].fnDecl); }
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 337 "parser.y"
    { (yyval.decl) = (yyvsp[(1) - (2)].varDecl); }
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 340 "parser.y"
    { (yyval.fnDecl) = (yyvsp[(1) - (2)].fnDecl); }
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 343 "parser.y"
    { (yyval.fnDecl) = new FnDecl((yyvsp[(1) - (1)].func).id,(yyvsp[(1) - (1)].func).tp,new List<VarDecl*>()); }
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 344 "parser.y"
    { (yyval.fnDecl) = new FnDecl((yyvsp[(1) - (1)].funcParam).id, (yyvsp[(1) - (1)].funcParam).tp, (yyvsp[(1) - (1)].funcParam).pList); }
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 347 "parser.y"
    {
                    (yyval.funcParam).tp = (yyvsp[(1) - (2)].func).tp;
                    (yyval.funcParam).id = (yyvsp[(1) - (2)].func).id;
                    ((yyval.funcParam).pList = new List<VarDecl*>())->Append((yyvsp[(2) - (2)].varDecl));}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 351 "parser.y"
    { (yyval.funcParam) = (yyvsp[(1) - (3)].funcParam);
                    (yyval.funcParam).pList->Append((yyvsp[(3) - (3)].varDecl)); }
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 355 "parser.y"
    {
                    (yyval.func).tp = (yyvsp[(1) - (3)].type);
                    (yyval.func).id = new Identifier((yylsp[(2) - (3)]),(yyvsp[(2) - (3)].identifier)),(yyvsp[(1) - (3)].type);}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 360 "parser.y"
    { (yyval.varDecl) = new VarDecl(new Identifier((yylsp[(2) - (2)]),(yyvsp[(2) - (2)].identifier)),(yyvsp[(1) - (2)].type)); }
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 363 "parser.y"
    { (yyval.varDecl) = (yyvsp[(1) - (1)].varDecl); }
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 364 "parser.y"
    { (yyval.varDecl) = new VarDecl(new Identifier((yylsp[(1) - (1)]),""),(yyvsp[(1) - (1)].type)); }
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 367 "parser.y"
    { (yyval.type) = (yyvsp[(1) - (1)].type); }
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 370 "parser.y"
    { (yyval.varDecl) = (yyvsp[(1) - (1)].varDecl); }
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 373 "parser.y"
    { (yyval.varDecl) = new VarDecl(new Identifier((yylsp[(2) - (2)]),(yyvsp[(2) - (2)].identifier)),(yyvsp[(1) - (2)].type)); }
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 376 "parser.y"
    { (yyval.type) = (yyvsp[(1) - (1)].type); }
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 379 "parser.y"
    { (yyval.type) = (yyvsp[(1) - (1)].type); }
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 382 "parser.y"
    { (yyval.type) = Type::voidType; }
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 383 "parser.y"
    { (yyval.type) = Type::floatType; }
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 384 "parser.y"
    { (yyval.type) = Type::intType; }
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 385 "parser.y"
    { (yyval.type) = Type::vec2Type; }
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 386 "parser.y"
    { (yyval.type) = Type::vec3Type; }
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 387 "parser.y"
    { (yyval.type) = Type::vec4Type; }
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 388 "parser.y"
    { (yyval.type) = Type::mat2Type; }
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 389 "parser.y"
    { (yyval.type) = Type::mat3Type; }
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 390 "parser.y"
    { (yyval.type) = Type::mat4Type; }
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 393 "parser.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); }
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 399 "parser.y"
    { (yyval.stmt) = (yyvsp[(1) - (1)].stmt); }
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 400 "parser.y"
    { (yyval.stmt) = (yyvsp[(1) - (1)].stmt); }
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 403 "parser.y"
    { (yyval.stmt) = (yyvsp[(1) - (1)].stmt); }
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 404 "parser.y"
    { (yyval.stmt) = (yyvsp[(1) - (1)].stmt); }
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 407 "parser.y"
    { (yyval.stmt) = (yyvsp[(1) - (1)].stmt); }
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 408 "parser.y"
    { (yyval.stmt) = (yyvsp[(1) - (1)].stmt); }
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 411 "parser.y"
    { (yyval.stmt) = (yyvsp[(1) - (1)].expr); }
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 412 "parser.y"
    { (yyval.stmt) = (yyvsp[(1) - (1)].ifStmt); }
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 413 "parser.y"
    { (yyval.stmt) = (yyvsp[(1) - (1)].switchStmt); }
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 414 "parser.y"
    { (yyval.stmt) = (yyvsp[(1) - (1)].cas); }
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 415 "parser.y"
    { (yyval.stmt) = (yyvsp[(1) - (1)].loopStmt); }
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 418 "parser.y"
    { (yyval.stmt) = NULL; }
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 419 "parser.y"
    { (yyval.stmt) = new StmtBlock((yyvsp[(2) - (3)].stmtBlk).vList,(yyvsp[(2) - (3)].stmtBlk).sList); }
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 422 "parser.y"
    { (yyval.stmt) = NULL; }
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 423 "parser.y"
    { (yyval.stmt) = new StmtBlock((yyvsp[(2) - (3)].stmtBlk).vList,(yyvsp[(2) - (3)].stmtBlk).sList); }
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 426 "parser.y"
    {
                (yyval.stmtBlk).vList = new List<VarDecl*>();
                ((yyval.stmtBlk).sList = new List<Stmt*>())->Append((yyvsp[(1) - (1)].stmt)); }
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 429 "parser.y"
    {
                (yyval.stmtBlk) = (yyvsp[(1) - (2)].stmtBlk);
                (yyval.stmtBlk).sList->Append((yyvsp[(2) - (2)].stmt)); }
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 434 "parser.y"
    { (yyval.expr) = new EmptyExpr(); }
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 435 "parser.y"
    { (yyval.expr) = (yyvsp[(1) - (2)].expr); }
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 438 "parser.y"
    { (yyval.ifStmt) = new IfStmt((yyvsp[(3) - (5)].expr),(yyvsp[(5) - (5)].teStmt).thenB,(yyvsp[(5) - (5)].teStmt).elseB); }
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 441 "parser.y"
    {
                        (yyval.teStmt).thenB = (yyvsp[(1) - (3)].stmt);
                        (yyval.teStmt).elseB = (yyvsp[(3) - (3)].stmt); }
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 444 "parser.y"
    {
                        (yyval.teStmt).thenB = (yyvsp[(1) - (1)].stmt);
                        (yyval.teStmt).elseB = NULL; }
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 449 "parser.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); }
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 450 "parser.y"
    {
                    /*VarExpr* given = new VarExpr(@2,new Identifier(@2,$2)); */
                    (yyval.expr) = new AssignExpr(new VarExpr((yylsp[(2) - (4)]),new Identifier((yylsp[(2) - (4)]),(yyvsp[(2) - (4)].identifier))), new Operator((yylsp[(3) - (4)]),"=="),(yyvsp[(4) - (4)].expr)); }
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 455 "parser.y"
    { }
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 458 "parser.y"
    { (yyval.stmtBlk) = (yyvsp[(1) - (1)].stmtBlk); }
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 461 "parser.y"
    { (yyval.intConstant) = new IntConstant((yylsp[(2) - (3)]),(yyvsp[(2) - (3)].integerConstant)); }
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 462 "parser.y"
    { }
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 465 "parser.y"
    { (yyval.cas) = new Case((yyvsp[(1) - (2)].intConstant),(yyvsp[(2) - (2)].stmtBlk).sList); }
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 468 "parser.y"
    { (yyval.loopStmt) = new WhileStmt((yyvsp[(3) - (5)].expr),(yyvsp[(5) - (5)].stmt)); }
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 469 "parser.y"
    { (yyval.loopStmt) = new ForStmt((yyvsp[(3) - (6)].expr),(yyvsp[(4) - (6)].tsStmt).test,(yyvsp[(4) - (6)].tsStmt).step,(yyvsp[(6) - (6)].stmt)); }
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 472 "parser.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); }
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 475 "parser.y"
    { (yyval.expr) = (yyvsp[(1) - (1)].expr); }
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 478 "parser.y"
    {
                        (yyval.tsStmt).test = (yyvsp[(1) - (2)].expr);
                        (yyval.tsStmt).step = NULL; }
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 481 "parser.y"
    {
                        (yyval.tsStmt).test = (yyvsp[(1) - (3)].expr);
                        (yyval.tsStmt).step = (yyvsp[(3) - (3)].expr); }
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 486 "parser.y"
    { ((yyval.declList)=(yyvsp[(1) - (2)].declList))->Append((yyvsp[(2) - (2)].decl)); }
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 487 "parser.y"
    { ((yyval.declList)=new List<Decl*>)->Append((yyvsp[(1) - (1)].decl)); }
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 490 "parser.y"
    { (yyval.decl) = (yyvsp[(1) - (1)].fnDecl); }
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 491 "parser.y"
    { (yyval.decl) = (yyvsp[(1) - (1)].decl); }
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 494 "parser.y"
    {
                    (yyval.fnDecl) = (yyvsp[(1) - (2)].fnDecl);
                    if((yyvsp[(2) - (2)].stmt)) (yyval.fnDecl)->SetFunctionBody((yyvsp[(2) - (2)].stmt));}
    break;



/* Line 1455 of yacc.c  */
#line 2676 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

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

  yyerror_range[0] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
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
		      yytoken, &yylval, &yylloc);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
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

  yyerror_range[0] = yylsp[1-yylen];
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

      yyerror_range[0] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;

  yyerror_range[1] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
  *++yylsp = yyloc;

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

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, &yylloc);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp);
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



/* Line 1675 of yacc.c  */
#line 499 "parser.y"


/* The closing %% above marks the end of the Rules section and the beginning
 * of the User Subroutines section. All text from here to the end of the
 * file is copied verbatim to the end of the generated y.tab.c file.
 * This section is where you put definitions of helper functions.
 */

/* Function: InitParser
 * --------------------
 * This function will be called before any calls to yyparse().  It is designed
 * to give you an opportunity to do anything that must be done to initialize
 * the parser (set global variables, configure starting state, etc.). One
 * thing it already does for you is assign the value of the global variable
 * yydebug that controls whether yacc prints debugging information about
 * parser actions (shift/reduce) and contents of state stack during parser.
 * If set to false, no information is printed. Setting it to true will give
 * you a running trail that might be helpful when debugging your parser.
 * Please be sure the variable is set to false when submitting your final
 * version.
 */
void InitParser()
{
   PrintDebug("parser", "Initializing parser");
   yydebug = false;
}

