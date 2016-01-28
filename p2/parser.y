/* File: parser.y
 * --------------
 * Bison input file to generate the parser for the compiler.
 *
 * pp2: your job is to write a parser that will construct the parse tree
 *      and if no parse errors were found, print it.  The parser should 
 *      accept the language as described in specification, and as augmented 
 *      in the pp2 handout.
 */

%{

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

%}

/* The section before the first %% is the Definitions section of the yacc
 * input file. Here is where you declare tokens and types, add precedence
 * and associativity options, and so on.
 */
 
/* yylval 
 * ------
 * Here we define the type of the yylval global variable that is used by
 * the scanner to store attibute information about the token just scanned
 * and thus communicate that information to the parser. 
 *
 * pp2: You will need to add new fields to this union as you add different 
 *      attributes to your non-terminal symbols.
 */
%union {
    int integerConstant;
    bool boolConstant;
    char *stringConstant;
    double doubleConstant;
    char identifier[MaxIdentLen+1]; // +1 for terminating null
    Decl *decl;
    List<Decl*> *declList;
}


/* Tokens
 * ------
 * Here we tell yacc about all the token types that we are using.
 * Bison will assign unique numbers to these and export the #define
 * in the generated y.tab.h header file.
 */
%token   T_Void T_Bool T_Int T_Float 
%token   T_LessEqual T_GreaterEqual T_Equal T_NotEqual T_Dims
%token   T_And T_Or 
%token   T_While T_For T_If T_Else T_Return T_Break
%token   T_Inc T_Dec T_Switch T_Case T_Default

%token   T_UInt T_BVec2 T_BVec3 T_BVec4 T_IVec2 T_IVec3 T_IVec4
%token   T_UVec2 T_UVec3 T_UVec4 T_Vec2 T_Vec3 T_Vec4 T_Struct
%token   T_In T_Out T_InOut T_Const T_Uniform T_Layout T_Continue
%token   T_Do T_Type_Name T_Field_Selection T_Mat2 T_Mat3 T_Mat4
%token   T_Mul_Assign T_Div_Assign T_Add_Assign T_Sub_Assign

%token   <identifier> T_Identifier
%token   <integerConstant> T_IntConstant
%token   <floatConstant> T_FloatConstant
%token   <boolConstant> T_BoolConstant


/* Non-terminal types
 * ------------------
 * In order for yacc to assign/access the correct field of $$, $1, we
 * must to declare which field is appropriate for the non-terminal.
 * As an example, this first type declaration establishes that the DeclList
 * non-terminal uses the field named "declList" in the yylval union. This
 * means that when we are setting $$ for a reduction for DeclList ore reading
 * $n which corresponds to a DeclList nonterminal we are accessing the field
 * of the union named "declList" which is of type List<Decl*>.
 * pp2: You'll need to add many of these of your own.
 */
%type <declList>  DeclList 
%type <decl>      Decl

%%
/* Rules
 * -----
 * All productions and actions should be placed between the start and stop
 * %% markers which delimit the Rules section.
	 
 */
Program   :    DeclList            { 
                                      @1; 
                                      /* pp2: The @1 is needed to convince 
                                       * yacc to set up yylloc. You can remove 
                                       * it once you have other uses of @n*/
                                      Program *program = new Program($1);
                                      // if no errors, advance to next phase
                                      if (ReportError::NumErrors() == 0) 
                                          program->Print(0);
                                    }
          ;

DeclList  :    DeclList Decl        { ($$=$1)->Append($2); }
          |    Decl                 { ($$ = new List<Decl*>)->Append($1); }
          ;

Var_Ident :    T_Identifier { }
	  ;

Prim_Expr :    Var_Ident { }
          |    T_IntConstant { }
          |    T_FloatConstant { }
          |    T_BoolConstant { }
          |    '(' Expr ')' { }
          ;

Post_Expr :    Prim_Expr { }
	  |    Post_Expr '[' Int_Expr ']' { }
          |    Fn_Call { }
          |    Post_Expr '.' T_Field_Selection { }
          |    Post_Expr T_Inc { }
          |    Post_Expr T_Dec { }
          ;

Int_Expr  :    Expr { }
          ;

Fn_Call   :    Fn_Call_Hdr_Param ')' { }
          |    Fn_Call_Hdr_NParam ')' { }
          ;

Fn_Call_Hdr_NParam :    Fn_Call_Hdr T_Void { }
                   |    Fn_Call_Hdr { }
                   ;

Fn_Call_Hdr_Param  :    Fn_Call_Hdr Assign_Expr { }
                   |    Fn_Call_Hdr_Param ',' Assign_Expr { }
                   ;

Fn_Call_Hdr        :    Fn_Ident '(' { }
                   ;

Fn_Ident  :    Type_Spec { }
          |    Post_Expr { }
          ;

Un_Expr   :    Post_Expr { }
          |    T_Inc Un_Expr { }
          |    T_Dec Un_Expr { }
          |    Un_Op Un_Expr { }
          ;

Un_Op     :    '+' { }
          |    '-' { }
          ;

Mult_Expr :    Un_Expr { }
          |    Mult_Expr '*' Un_Expr { }
          |    Mult_Expr '/' Un_Expr { }
          ;

Add_Expr  :    Mult_Expr { }
          |    Add_Expr '+' Mult_Expr { }
          |    Add_Expr '-' Mult_Expr { }
          ;

Sh_Expr   :    Add_Expr { }
          ;

Rela_Expr :    Sh_Expr { }
          |    Rela_Expr '<' Sh_Expr { }
          |    Rela_Expr '>' Sh_Expr { }
          |    Rela_Expr T_LessEqual Sh_Expr { }
          |    Rela_Expr T_GreaterEqual Sh_Expr { }
          ;

Eq_Expr   :    Rela_Expr { }
          |    Eq_Expr T_Equal Rela_Expr { }
          |    Eq_Expr T_NotEqual Rela_Expr { }
          ;

And_Expr  :    Eq_Expr { }
	  ;

Excl_Or_Expr  :    And_Expr { }
	      ;

Incl_Or_Expr  :    Excl_Or_Expr { }
	      ;

Log_And_Expr  :    Incl_Or_Expr { }
              |    Log_And_Expr T_And Incl_Or_Expr { }
              ;

Log_Xor_Expr  :    Log_And_Expr { }
	      ;

Log_Or_Expr   :    Log_Xor_Expr { }
              |    Log_Or_Expr T_Or Log_Xor_Expr { }
              ;

Cond_Expr :    Log_Or_Expr { }
          ;

Assign_Expr   :    Cond_Expr { }
              |    Un_Expr Assign_Op Assign_Expr { }
              ;

Assign_Op :    '=' { }
          |    T_Mul_Assign { }
          |    T_Div_Assign { }
          |    T_Add_Assign { }
          |    T_Sub_Assign { }
          ;

Expr      :    Assign_Expr { }
          |    Expr ',' Assign_Expr { }
          ;

Const_Expr    :    Cond_Expr { }
              ;

Decl      :    Init_DeclorList ';' { }
          |    Type_Qual ';' { }
          |    Type_Qual T_Identifier ';' { }
          |    Type_Qual T_Identifier Ident_List ';' { }
          ;

Ident_List    :    ',' T_Identifier { }
              |    Ident_List ',' T_Identifier { }
              ;

Fn_Proto  :    Fn_Declor ')' { }
          ;

Fn_Declor :    Fn_Hdr { }
          |    Fn_Hdr_Param { }
          ;

Fn_Hdr_Param  :    Fn_Hdr Param_Decl { }
              |    Fn_Hdr_Param ',' Param_Decl { }
              ;

Fn_Hdr    :    Full_Spec_T  T_Identifier '(' { }
          ;

Param_Declor  :    Type_Spec T_Identifier { }
              |    Type_Spec T_Identifier Arr_Spec { }
              ;

Param_Decl    :    Type_Qual Param_Declor { }
              |    Param_Declor { }
              |    Type_Qual Param_T_Spec { }
              |    Param_T_Spec { }
              ;

Param_T_Spec  :    Type_Spec { }
              ;

Init_DeclorList    :    Sing_Decl { }
                   |    Init_DeclorList ',' T_Identifier { }
                   |    Init_DeclorList ',' T_Identifier Arr_Spec { }
                   |    Init_DeclorList ',' T_Identifier Arr_Spec '=' Init { }
                   |    Init_DeclorList ',' T_Identifier '=' Init { }
                   ;

Sing_Decl :    Full_Spec_T { }
          |    Full_Spec_T T_Identifier { }
          |    Full_Spec_T T_Identifier Arr_Spec { }
          |    Full_Spec_T T_Identifier Arr_Spec '=' Init { }
          |    Full_Spec_T T_Identifier '=' Init { }
          ;

Full_Spec_T   :    Type_Spec { }
              |    Type_Qual Type_Spec { }
              ;

LO_Qual   :    T_Layout '(' LO_IDList ')' { }
          ;

LO_IDList :    LO_ID { }
          |    LO_IDList ',' LO_ID { }
          ;

LO_ID     :    T_Identifier { }
          |    T_Identifier '=' T_IntConstant { }
          ;

Type_Qual :    Sing_T_Qual { }
          |    Type_Qual Sing_T_Qual { }
          ;

Sing_T_Qual   :    Stor_Qual { }
              |    LO_Qual { }
              ;

Stor_Qual :    T_Const { }
          |    T_In { }
          |    T_Out { }
          |    T_InOut { }
          |    T_Uniform { }
          ;

Type_Spec :    Type_Spec_NArr { }
          |    Type_Spec_NArr Arr_Spec { }
          ;

Arr_Spec  :    '[' ']' { }
          |    '[' Const_Expr ']' { }
          |    Arr_Spec '[' ']' { }
          |    Arr_Spec '[' Const_Expr ']' { }
          ;

Type_Spec_NArr :    T_Void { }
               |    T_Float { }
               |    T_Int { }
               |    T_Bool { }
               |    T_Vec2 { }
               |    T_Vec3 { }
               |    T_Vec4 { }
               |    T_BVec2 { }
               |    T_BVec3 { }
               |    T_BVec4 { }
               |    T_IVec2 { }
               |    T_IVec3 { }
               |    T_IVec4 { }
               |    T_UVec2 { }
               |    T_UVec3 { }
               |    T_UVec4 { }
               |    T_Mat2 { }
               |    T_Mat3 { }
               |    T_Mat4 { }
               |    Str_Spec { }

Str_Spec  :    T_Struct T_Identifier '{' Str_DeclList '}' { }
          |    T_Struct '{' Str_DeclList '}' { }
          ;

Str_DeclList   :    Str_Decl { }
               |    Str_DeclList Str_Decl { }
               ;

Str_Decl  :    Type_Spec Str_DeclorList ';' { }
          |    Type_Qual Type_Spec Str_DeclorList ';' { }
          ;

Str_DeclorList :    Str_Declor { }
               |    Str_DeclorList ',' Str_Declor { }
               ;

Str_Declor     :    T_Identifier { }
               |    T_Identifier Arr_Spec { }
               ;

Init      :    Assign_Expr { }
          ;

Decl_Stmt :    Decl { }
          ;

Stmt      :    Comp_Stmt_Scope { }
          |    Simp_Stmt { }
          ;

Stmt_No_Scope  : Comp_Stmt_No_Scope { }
	       | Simp_Stmt { }
	       ;

Stmt_Scope     : Comp_Stmt_No_Scope { }
	       | Simp_Stmt { }
	       ;

Simp_Stmt    :    Decl_Stmt { }
               |    Expr_Stmt { }
               |    Sel_Stmt { }
               |    Swi_Stmt { }
               |    Case_Lbl { }
               |    Iter_Stmt { }
               |    Jump_Stmt { }
               ;

Comp_Stmt_Scope    : '{' '}' { }
                   | '{' StmtList '}' { }
                   ;

Comp_Stmt_No_Scope : '{' '}' {}
		   | '{' StmtList '}' { }
		   ;

StmtList  :    Stmt { }
          |    StmtList Stmt { }
          ;

Expr_Stmt :   ';' { }
          |    Expr ';' { }
          ;

Sel_Stmt  :    T_If '(' Expr ')' Sel_Rest_Stmt { }
          ;

Sel_Rest_Stmt  :    Stmt_Scope T_Else Stmt_Scope { }
               |    Stmt_Scope { }
               ;

Cond      :    Expr { }
          |    Full_Spec_T T_Identifier T_Equal Init { }
          ;

Swi_Stmt  :    T_Switch '(' Expr ')' '{' Swi_StmtList '}' { }
          ;

Swi_StmtList   :    StmtList { }
               ;

Case_Lbl  :    T_Case Expr ':' { }
          |    T_Default ':' { }
          ;

Iter_Stmt :    T_While '(' Cond ')' Stmt { }
          |    T_Do Stmt T_While '(' Expr ')' ';' { }
          |    T_For '(' For_Init_Stmt For_Rest_Stmt ')' Stmt_No_Scope { }
          ;

For_Init_Stmt  :    Expr_Stmt { }
               |    Decl_Stmt { }
               ;

Cond_Op   :    Cond { }
	  ;

For_Rest_Stmt  :    Cond_Op ';' { }
               |    Cond_Op ';' Expr { }
               ;

Jump_Stmt :    T_Continue ';' { }
          |    T_Break ';' { }
          |    T_Return ';' { }
          |    T_Return Expr ';' { }
          ;

Tran_U    :    Tran_U Ext_Decl { }
          |    Ext_Decl { }
          ;

Ext_Decl  :    Fn_Def { }
          |    Decl { }
          ;

Fn_Def    :    Fn_Proto Comp_Stmt_No_Scope { }


%%

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
