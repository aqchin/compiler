/* File: ast_decl.h
 * ----------------
 * In our parse tree, Decl nodes are used to represent and
 * manage declarations. There are 4 subclasses of the base class,
 * specialized for declarations of variables, functions, classes,
 * and interfaces.
 *
 * pp3: You will need to extend the Decl classes to implement
 * semantic processing including detection of declaration conflicts
 * and managing scoping issues.
 */

#ifndef _H_ast_decl
#define _H_ast_decl

#include "ast.h"
#include "list.h"

class Type;
class NamedType;
class Identifier;
class Stmt;

void yyerror(const char *msg);

class Decl : public Node 
{
  protected:
    Identifier *id;
  
  public:
    Decl() : id(NULL) {}
    Decl(Identifier *name);
    friend ostream& operator<<(ostream& out, Decl *d) { return out << d->id; }
    Identifier* GetId() { return id; }

    virtual void Check() = 0;
};

class VarDecl : public Decl 
{
  protected:
    Type *type;
    
  public:
    VarDecl() : type(NULL) {}
    VarDecl(Identifier *name, Type *type);
    const char *GetPrintNameForNode() { return "VarDecl"; }
    void PrintChildren(int indentLevel);
    
    Type* GetType() { return type; }
    void Check();
};

class VarDeclError : public VarDecl
{
  public:
    VarDeclError() : VarDecl() { yyerror(this->GetPrintNameForNode()); };
    const char *GetPrintNameForNode() { return "VarDeclError"; }

    void Check() {}
};

class FnDecl : public Decl 
{
  protected:
    List<VarDecl*> *formals;
    Type *returnType;
    Stmt *body;
    
  public:
    FnDecl() : Decl(), formals(NULL), returnType(NULL), body(NULL) {}
    FnDecl(Identifier *name, Type *returnType, List<VarDecl*> *formals);
    void SetFunctionBody(Stmt *b);
    const char *GetPrintNameForNode() { return "FnDecl"; }
    Type* GetRetType() { return returnType; }
    void PrintChildren(int indentLevel);

    void Check();
};

class FormalsError : public FnDecl
{
  public:
    FormalsError() : FnDecl() { yyerror(this->GetPrintNameForNode()); }
    const char *GetPrintNameForNode() { return "FormalsError"; }

    void Check() {}
};

#endif
