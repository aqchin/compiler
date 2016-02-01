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

%code requires {
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

}

%union {
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
    BoolConstant *bConstant;
    FloatConstant *fConstant;
    Case *cas;
    Program *program;

    struct Function func;
    struct FunctionParam funcParam;
    struct NStmtBlock stmtBlk;
    struct ThenElse teStmt;
    struct ForRest tsStmt;
}


/* Tokens
 * ------
 * Here we tell yacc about all the token types that we are using.
 * Bison will assign unique numbers to these and export the #define
 * in the generated y.tab.h header file.
 */
%token   T_Void T_Bool T_Int T_Float 
%token   T_LessEqual T_GreaterEqual T_EqOp T_NotEqual T_Dims
%token   T_And T_Or
%token   T_While T_For T_If T_Else T_Return T_Break
%token   T_Inc T_Dec T_Switch T_Case T_Default

%token   T_UInt T_BVec2 T_BVec3 T_BVec4 T_IVec2 T_IVec3 T_IVec4
%token   T_UVec2 T_UVec3 T_UVec4 T_Vec2 T_Vec3 T_Vec4 T_Struct
%token   T_In T_Out T_InOut T_Const T_Uniform T_Layout T_Continue
%token   T_Do T_TypeName T_Mat2 T_Mat3 T_Mat4
/* %token   T_LeOp T_GeOp T_EqOp T_NeOp T_AndOp T_OrOp T_Dims */
%token   T_MulAssign T_DivAssign T_AddAssign T_SubAssign
%token   T_LeftParen T_RightParen T_LeftBrace T_RightBrace T_Dot
%token   T_Colon T_Equal T_Semicolon T_Dash T_Plus T_Star T_Slash
%token   T_LeftAngle T_RightAngle

%token   <identifier> T_Identifier
%token   <integerConstant> T_IntConstant
%token   <floatConstant> T_FloatConstant
%token   <boolConstant> T_BoolConstant
%token   <identifier> T_FieldSelection


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
%type <ident> Var_Ident
%type <expr> Prim_Expr
%type <expr> Post_Expr
%type <expr> Int_Expr
%type <ident> Fn_Ident
%type <expr> Un_Expr
%type <op> Un_Op
%type <expr> Mult_Expr
%type <expr> Add_Expr
%type <expr> Sh_Expr
%type <expr> Rela_Expr
%type <expr> Eq_Expr
%type <expr> And_Expr
%type <expr> Excl_Or_Expr
%type <expr> Incl_Or_Expr
%type <expr> Log_And_Expr
%type <expr> Log_Xor_Expr
%type <expr> Log_Or_Expr
%type <expr> Cond_Expr
%type <expr> Assign_Expr
%type <op> Assign_Op
%type <expr> Expr
%type <expr> Const_Expr
%type <fnDecl> Fn_Proto
%type <fnDecl> Fn_Declor
%type <funcParam> Fn_Hdr_Param
%type <func> Fn_Hdr
%type <varDecl> Param_Declor
%type <varDecl> Param_Decl
%type <type> Param_T_Spec
%type <varDecl> Init_DeclorList
%type <varDecl> Sing_Decl
%type <type> Full_Spec_T
%type <type> Type_Spec
%type <type> Type_Spec_NArr
%type <expr> Init
/* %type <decl> Decl_Stmt   "not being tested" */
%type <stmt> Stmt
%type <stmt> Stmt_No_Scope
%type <stmt> Stmt_Scope
%type <stmt> Simp_Stmt
%type <stmt> Comp_Stmt_Scope
%type <stmt> Comp_Stmt_No_Scope
%type <stmtBlk> StmtList
%type <expr> Expr_Stmt
%type <ifStmt> Sel_Stmt
%type <teStmt> Sel_Rest_Stmt
%type <expr> Cond
%type <switchStmt> Swi_Stmt /* incomplete */
%type <stmtBlk> Swi_StmtList
%type <intConstant> Case_Lbl
%type <cas> Case_Stmt
%type <loopStmt> Iter_Stmt
%type <expr> For_Init_Stmt
%type <expr> Cond_Op
%type <tsStmt> For_Rest_Stmt
%type <declList> Trans_U
%type <decl> Ext_Decl
%type <fnDecl> Fn_Def
%type <program> Program

%nonassoc NOELSE
%nonassoc T_ELSE

%%
/* Rules
 * -----
 * All productions and actions should be placed between the start and stop
 * %% markers which delimit the Rules section.
	 
 */
Program   :    Trans_U              {
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

Var_Ident :    T_Identifier { $$ = new Identifier(@1,$1); }
	      ;

Prim_Expr :    Var_Ident { $$ = new VarExpr(@1,$1); }
          |    T_IntConstant { $$ = new IntConstant(@1,$1); }
          |    T_FloatConstant { $$ = new FloatConstant(@1,$1); }
          |    T_BoolConstant { $$ = new BoolConstant(@1,$1); }
          |    T_LeftParen Expr T_RightParen { $$ = $2; }
          ;

Post_Expr :    Prim_Expr { $$ = $1; }
          |    Post_Expr T_Dot T_FieldSelection { $$ = new FieldAccess($1,new Identifier(@3,$3)); }
          |    Post_Expr T_Inc { $$ = new PostfixExpr($1,new Operator(@2,"++")); }
          |    Post_Expr T_Dec { $$ = new PostfixExpr($1,new Operator(@2,"--")); }
          ;

Int_Expr  :    Expr { $$ = $1; }
          ;

Fn_Ident  :    Type_Spec { $$ = new Identifier(@1,$1->getTypeName()); }
          |    Post_Expr { $$ = $1; }
          ;

Un_Expr   :    Post_Expr { $$ = $1; }
          |    T_Inc Un_Expr { $$ = new ArithmeticExpr(new Operator(@1,"++"),$2); }
          |    T_Dec Un_Expr { $$ = new ArithmeticExpr(new Operator(@1,"--"),$2); }
          |    Un_Op Un_Expr { $$ = new ArithmeticExpr($1,$2); }
          ;

Un_Op     :    T_Plus { $$ = new Operator(@1,"+"); }
          |    T_Dash { $$ = new Operator(@1,"-"); }
          ;

Mult_Expr :    Un_Expr { $$ = $1; }
          |    Mult_Expr T_Star Un_Expr { $$ = new ArithmeticExpr($1,new Operator(@2,"*"),$3); }
          |    Mult_Expr T_Slash Un_Expr { $$ = new ArithmeticExpr($1,new Operator(@2,"/"),$3); }
          ;

Add_Expr  :    Mult_Expr { $$ = $1; }
          |    Add_Expr T_Plus Mult_Expr { $$ = new ArithmeticExpr($1,new Operator(@2,"+"),$3); }
          |    Add_Expr T_Dash Mult_Expr { $$ = new ArithmeticExpr($1,new Operator(@2,"-"),$3); }
          ;

Sh_Expr   :    Add_Expr { $$ = $1; }
          ;

Rela_Expr :    Sh_Expr { $$ = $1; }
          |    Rela_Expr T_LeftAngle Sh_Expr { $$ = new RelationalExpr($1,new Operator(@2,"<"),$3); }
          |    Rela_Expr T_RightAngle Sh_Expr { $$ = new RelationalExpr($1,new Operator(@2,">"),$3); }
          |    Rela_Expr T_LessEqual Sh_Expr { $$ = new RelationalExpr($1,new Operator(@2,"<="),$3); }
          |    Rela_Expr T_GreaterEqual Sh_Expr { $$ = new RelationalExpr($1,new Operator(@2,">="),$3); }
          ;

Eq_Expr   :    Rela_Expr { $$ = $1; }
          |    Eq_Expr T_EqOp Rela_Expr { $$ = new EqualityExpr($1,new Operator(@2,"=="),$3); }
          |    Eq_Expr T_NotEqual Rela_Expr { $$ = new EqualityExpr($1,new Operator(@2,"!="),$3); }
          ;

And_Expr  :    Eq_Expr { $$ = $1; }
          ;

Excl_Or_Expr  :    And_Expr { $$ = $1; }
              ;

Incl_Or_Expr  :    Excl_Or_Expr { $$ = $1; }
              ;

Log_And_Expr  :    Incl_Or_Expr { $$ = $1; }
              |    Log_And_Expr T_And Incl_Or_Expr { $$ = new LogicalExpr($1,new Operator(@2,"&&"),$3); }
              ;

Log_Xor_Expr  :    Log_And_Expr { $$ = $1; }
	      ;

Log_Or_Expr   :    Log_Xor_Expr { $$ = $1; }
              |    Log_Or_Expr T_Or Log_Xor_Expr { $$ = new LogicalExpr($1,new Operator(@2,"||"),$3); }
              ;

Cond_Expr :    Log_Or_Expr { $$ = $1; }
          ;

Assign_Expr   :    Cond_Expr { $$ = $1; }
              |    Un_Expr Assign_Op Assign_Expr { $$ = new AssignExpr($1,$2,$3); }
	      |    Un_Expr Assign_Op Type_Spec T_LeftParen Cond_Expr T_RightParen {
	             List<Expr*> *callList = new List<Expr*>();
                     callList->Append($5);
                     $$ = new AssignExpr($1,$2,new Call(@5,NULL,new Identifier(@3,$3->getTypeName()),callList)); }
              ;

Assign_Op :    T_Equal { $$ = new Operator(@1,"="); }
          |    T_MulAssign { $$ = new Operator(@1,"*="); }
          |    T_DivAssign { $$ = new Operator(@1,"/="); }
          |    T_AddAssign { $$ = new Operator(@1,"+="); }
          |    T_SubAssign { $$ = new Operator(@1,"-="); }
          ;

Expr      :    Assign_Expr { $$ = $1; }
          ;

Const_Expr    :    Cond_Expr { $$ = $1; }
              ;

Decl      :    Fn_Proto T_Semicolon { $$ = $1; }
          |    Init_DeclorList { $$ = $1; }
          ;

Fn_Proto  :    Fn_Declor T_RightParen { $$ = $1; }
          ;

Fn_Declor :    Fn_Hdr { $$ = new FnDecl($1.id,$1.tp,new List<VarDecl*>()); }
          |    Fn_Hdr_Param { $$ = new FnDecl($1.id, $1.tp, $1.pList); }
          ;

Fn_Hdr_Param  :    Fn_Hdr Param_Decl {
                    $$.tp = $1.tp;
                    $$.id = $1.id;
                    ($$.pList = new List<VarDecl*>())->Append($2);}
              |    Fn_Hdr_Param ',' Param_Decl { $$ = $1;
                    $$.pList->Append($3); }
              ;

Fn_Hdr    :    Full_Spec_T  T_Identifier T_LeftParen {
                    $$.tp = $1;
                    $$.id = new Identifier(@2,$2),$1;}
          ;

Param_Declor  :    Type_Spec T_Identifier { $$ = new VarDecl(new Identifier(@2,$2),$1); }
              ;

Param_Decl    :    Param_Declor { $$ = $1; }
              |    Param_T_Spec { $$ = new VarDecl(new Identifier(@1,""),$1); }
              ;

Param_T_Spec  :    Type_Spec { $$ = $1; }
              ;

Init_DeclorList    :    Sing_Decl T_Semicolon { $$ = $1; }
                   ;

Sing_Decl :    Full_Spec_T T_Identifier { $$ = new VarDecl(new Identifier(@2,$2),$1); }
          ;

Full_Spec_T   :    Type_Spec { $$ = $1; }
              ;

Type_Spec :    Type_Spec_NArr { $$ = $1; }
          ;

Type_Spec_NArr :    T_Void { $$ = Type::voidType; }
               |    T_Float { $$ = Type::floatType; }
               |    T_Int { $$ = Type::intType; }
	       |    T_Bool { $$ = Type::boolType; }
               |    T_Vec2 { $$ = Type::vec2Type; }
               |    T_Vec3 { $$ = Type::vec3Type; }
               |    T_Vec4 { $$ = Type::vec4Type; }
               |    T_Mat2 { $$ = Type::mat2Type; }
               |    T_Mat3 { $$ = Type::mat3Type; }
               |    T_Mat4 { $$ = Type::mat4Type; }
               ;

Init      :    Assign_Expr { $$ = $1; }
          ;

/*Decl_Stmt :    Decl { }*/
/*          ;*/

Stmt      :    Comp_Stmt_Scope { $$ = $1; }
          |    Simp_Stmt { $$ = $1; }
          ;

Stmt_No_Scope : Comp_Stmt_No_Scope { $$ = $1; }
              | Simp_Stmt { $$ = $1; }
              ;

Stmt_Scope    : Comp_Stmt_No_Scope { $$ = $1; }
              | Simp_Stmt { $$ = $1; }
              ;

Simp_Stmt     :    Expr_Stmt { $$ = $1; }
              |    Sel_Stmt { $$ = $1; }
              |    Swi_Stmt { $$ = $1; }
              |    Case_Stmt { $$ = $1; }
              |    Iter_Stmt { $$ = $1; }
              ;

Comp_Stmt_Scope   : T_LeftBrace T_RightBrace { $$ = new StmtBlock(new List<VarDecl*>(),new List<Stmt*>()); }
                  | T_LeftBrace StmtList T_RightBrace { $$ = new StmtBlock($2.vList,$2.sList); }
                  ;

Comp_Stmt_No_Scope : T_LeftBrace T_RightBrace { $$ = new StmtBlock(new List<VarDecl*>(),new List<Stmt*>()); }
		   | T_LeftBrace StmtList T_RightBrace { $$ = new StmtBlock($2.vList,$2.sList); }
		   ;

StmtList  :    Stmt {
                $$.vList = new List<VarDecl*>();
                ($$.sList = new List<Stmt*>())->Append($1); }
          |    StmtList Stmt {
                $$ = $1;
                $$.sList->Append($2); }
	  | Init_DeclorList { $$.sList = new List<Stmt*>(); ($$.vList = new List<VarDecl*>)->Append($1); }
	  | StmtList Init_DeclorList { $$ = $1; $$.vList->Append($2); }
          ;

Expr_Stmt :    T_Semicolon { $$ = new EmptyExpr(); }
          |    Expr T_Semicolon { $$ = $1; }
          ;

Sel_Stmt  :    T_If T_LeftParen Expr T_RightParen Sel_Rest_Stmt { $$ = new IfStmt($3,$5.thenB,$5.elseB); }
          ;

Sel_Rest_Stmt  :    Stmt_Scope T_Else Stmt_Scope {
                        $$.thenB = $1;
                        $$.elseB = $3; }
               |    Stmt_Scope %prec NOELSE {
                        $$.thenB = $1;
                        $$.elseB = NULL; }
               ;

Cond      :    Expr { $$ = $1; }
          |    Full_Spec_T T_Identifier T_EqOp Init {
                    /*VarExpr* given = new VarExpr(@2,new Identifier(@2,$2)); */
                    $$ = new AssignExpr(new VarExpr(@2,new Identifier(@2,$2)), new Operator(@3,"=="),$4); }
          ;

Swi_Stmt  :    T_Switch T_LeftParen Expr T_RightParen T_LeftBrace Swi_StmtList T_RightBrace { }
          ;

Swi_StmtList   :    StmtList { $$ = $1; }
               ;

Case_Lbl  :    T_Case T_IntConstant T_Colon { $$ = new IntConstant(@2,$2); }
          |    T_Default T_Colon { }
          ;

Case_Stmt :    Case_Lbl Swi_StmtList { $$ = new Case($1,$2.sList); }
          ;

Iter_Stmt :    T_While T_LeftParen Cond T_RightParen Stmt { $$ = new WhileStmt($3,$5); }
          |    T_For T_LeftParen For_Init_Stmt For_Rest_Stmt T_RightParen Stmt_No_Scope { $$ = new ForStmt($3,$4.test,$4.step,$6); }
          ;

For_Init_Stmt  :    Expr_Stmt { $$ = $1; }
               ;

Cond_Op   :    Cond { $$ = $1; }
          ;

For_Rest_Stmt  :    Cond_Op T_Semicolon {
                        $$.test = $1;
                        $$.step = NULL; }
               |    Cond_Op T_Semicolon Expr {
                        $$.test = $1;
                        $$.step = $3; }
               ;

Trans_U   :    Trans_U Ext_Decl { ($$=$1)->Append($2); }
          |    Ext_Decl { ($$=new List<Decl*>)->Append($1); }
          ;

Ext_Decl  :    Fn_Def { $$ = $1; }
          |    Decl { $$ = $1; }
          ;

Fn_Def    :    Fn_Proto Comp_Stmt_No_Scope {
                    $$ = $1;
                    if($2) $$->SetFunctionBody($2);}


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
