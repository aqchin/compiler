
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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

/* "%code requires" blocks.  */

/* Line 1676 of yacc.c  */
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




/* Line 1676 of yacc.c  */
#line 71 "y.tab.h"

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

/* Line 1676 of yacc.c  */
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



/* Line 1676 of yacc.c  */
#line 279 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

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

extern YYLTYPE yylloc;

