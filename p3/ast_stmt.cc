/* File: ast_stmt.cc
 * -----------------
 * Implementation of statement node classes.
 */
#include "ast_stmt.h"
#include "ast_type.h"
#include "ast_decl.h"
#include "ast_expr.h"
#include "errors.h"

Program::Program(List<Decl*> *d) {
    Assert(d != NULL);
    (decls=d)->SetParentAll(this);
}

void Program::PrintChildren(int indentLevel) {
    decls->PrintAll(indentLevel+1);
    printf("\n");
}

void Program::Check() {
    /* pp3: here is where the semantic analyzer is kicked off.
     *      The general idea is perform a tree traversal of the
     *      entire program, examining all constructs for compliance
     *      with the semantic rules.  Each node can have its own way of
     *      checking itself, which makes for a great use of inheritance
     *      and polymorphism in the node classes.
     */
    st_list->Append(new Symbol());

    int i;
    for(i = 0; i < decls->NumElements(); i++) {
      decls->Nth(i)->Check();
    }

    // sample test - not the actual working code
    // replace it with your own implementation
    if ( decls->NumElements() >= 2 ) {
      // Decl *newDecl  = decls->Nth(1);
      // Decl *prevDecl = decls->Nth(0);
      // ReportError::DeclConflict(newDecl, prevDecl);
    }
}

StmtBlock::StmtBlock(List<VarDecl*> *d, List<Stmt*> *s) {
    Assert(d != NULL && s != NULL);
    (decls=d)->SetParentAll(this);
    (stmts=s)->SetParentAll(this);
}

void StmtBlock::PrintChildren(int indentLevel) {
    decls->PrintAll(indentLevel+1);
    stmts->PrintAll(indentLevel+1);
}

void StmtBlock::Check() {
    FnDecl* funcDecl = NULL;
    Node* curr = this;
    bool need2ret = false;
    while(curr->GetParent()) {
        if(strcmp("FnDecl",curr->GetParent()->GetPrintNameForNode())==0) {
            funcDecl = dynamic_cast<FnDecl*>(curr->GetParent());
            break;
        }
        curr = curr->GetParent();
    }
    if(funcDecl && !(funcDecl->GetRetType()->IsEquivalentTo(Type::voidType)))
        need2ret = true;
    int i;
    for(i = 0; i < stmts->NumElements(); i++) {
        if(strcmp("StmtBlock", stmts->Nth(i)->GetPrintNameForNode())) {
            stmts->Nth(i)->Check();
            if(need2ret && dynamic_cast<ReturnStmt*>(stmts->Nth(i)))
                need2ret = false;
        }
        else {
            st_list->Append(new Symbol());
            stmts->Nth(i)->Check();
            if(need2ret && dynamic_cast<ReturnStmt*>(stmts->Nth(i)))
                need2ret = false;
            st_list->RemoveAt(st_list->NumElements()-1);
        }
    }
    
    if(need2ret)
        ReportError::ReturnMissing(funcDecl);
}

DeclStmt::DeclStmt(Decl *d) {
    Assert(d != NULL);
    (decl=d)->SetParent(this);
}

void DeclStmt::PrintChildren(int indentLevel) {
    decl->Print(indentLevel+1);
}

void DeclStmt::Check() {
    char* ident = decl->GetId()->GetName();
    if(st_list->Nth(st_list->NumElements()-1)->exists(ident)) {
        Decl* origin;
        if(strcmp(st_list->Nth(st_list->NumElements()-1)->lookup(ident)->
                  GetPrintNameForNode(),"DeclStmt")!=0) {
            origin = dynamic_cast<Decl*> (st_list->Nth(st_list->NumElements()-1)->lookup(ident));
        } else {
            DeclStmt* temp = dynamic_cast<DeclStmt*> (st_list->Nth(st_list->NumElements()-1)->lookup(ident));
            origin = temp->decl;
        }
        
        ReportError::DeclConflict(decl,origin);
    }
    
    st_list->Nth(st_list->NumElements()-1)->insert(ident,this);
}

ConditionalStmt::ConditionalStmt(Expr *t, Stmt *b) { 
    Assert(t != NULL && b != NULL);
    (test=t)->SetParent(this); 
    (body=b)->SetParent(this);
}

void ConditionalStmt::Check() {
    test->Check();
    if(!(test->GetType()->IsEquivalentTo(Type::boolType)))
        ReportError::TestNotBoolean(test);
    body->Check();
}

ForStmt::ForStmt(Expr *i, Expr *t, Expr *s, Stmt *b): LoopStmt(t, b) { 
    Assert(i != NULL && t != NULL && b != NULL);
    (init=i)->SetParent(this);
    step = s;
    if ( s )
      (step=s)->SetParent(this);
}

void ForStmt::PrintChildren(int indentLevel) {
    init->Print(indentLevel+1, "(init) ");
    test->Print(indentLevel+1, "(test) ");
    if ( step )
      step->Print(indentLevel+1, "(step) ");
    body->Print(indentLevel+1, "(body) ");
}

void ForStmt::Check() {
    st_list->Append(new Symbol());
    
    init->Check();
    step->Check();
    ConditionalStmt::Check();
    
    st_list->RemoveAt(st_list->NumElements()-1);
}

void WhileStmt::PrintChildren(int indentLevel) {
    test->Print(indentLevel+1, "(test) ");
    body->Print(indentLevel+1, "(body) ");
}

void WhileStmt::Check() {
    st_list->Append(new Symbol());
    
    ConditionalStmt::Check();
    
    st_list->RemoveAt(st_list->NumElements()-1);
}

IfStmt::IfStmt(Expr *t, Stmt *tb, Stmt *eb): ConditionalStmt(t, tb) { 
    Assert(t != NULL && tb != NULL); // else can be NULL
    elseBody = eb;
    if (elseBody) elseBody->SetParent(this);
}

void IfStmt::PrintChildren(int indentLevel) {
    if (test) test->Print(indentLevel+1, "(test) ");
    if (body) body->Print(indentLevel+1, "(then) ");
    if (elseBody) elseBody->Print(indentLevel+1, "(else) ");
}

void IfStmt::Check() {
    ConditionalStmt::Check();
    if(elseBody) elseBody->Check();
}

void BreakStmt::Check() {
    Node* curr = this;
    while(curr->GetParent()) {
        if(strcmp("ForStmt",curr->GetParent()->GetPrintNameForNode())==0 ||
           strcmp("WhileStmt",curr->GetParent()->GetPrintNameForNode())==0) {
            st_list->RemoveAt(st_list->NumElements()-1);
            return;
        }
        curr = curr->GetParent();
    }
    
    ReportError::BreakOutsideLoop(this);
}

void ContinueStmt::Check() {
    Node* curr = this;
    while(curr->GetParent()) {
        if(strcmp("ForStmt",curr->GetParent()->GetPrintNameForNode())==0 ||
           strcmp("WhileStmt",curr->GetParent()->GetPrintNameForNode())==0) {
            return;
        }
        curr = curr->GetParent();
    }
    
    ReportError::ContinueOutsideLoop(this);
}

ReturnStmt::ReturnStmt(yyltype loc, Expr *e) : Stmt(loc) { 
    expr = e;
    if (e != NULL) expr->SetParent(this);
}

void ReturnStmt::PrintChildren(int indentLevel) {
    if ( expr ) 
      expr->Print(indentLevel+1);
}

void ReturnStmt::Check() {
    Type* tomatch;
    Node* curr = this;
    while(curr->GetParent()) {
        if(strcmp("FnDecl",curr->GetParent()->GetPrintNameForNode())==0) {
            tomatch = dynamic_cast<FnDecl*>(curr->GetParent())->GetRetType();
            break;
        }
        curr = curr->GetParent();
    }
    if(expr) {
        expr->Check();
        Type* etype = expr->GetType();
        if(!(tomatch->IsEquivalentTo(etype)))
            ReportError::ReturnMismatch(this, etype, tomatch);
    } else if (!(tomatch->IsEquivalentTo(Type::voidType))) {
        ReportError::ReturnMismatch(this, Type::voidType, tomatch);
    }
}
  
SwitchLabel::SwitchLabel(Expr *l, Stmt *s) {
    Assert(l != NULL && s != NULL);
    (label=l)->SetParent(this);
    (stmt=s)->SetParent(this);
}

SwitchLabel::SwitchLabel(Stmt *s) {
    Assert(s != NULL);
    label = NULL;
    (stmt=s)->SetParent(this);
}

void SwitchLabel::PrintChildren(int indentLevel) {
    if (label) label->Print(indentLevel+1);
    if (stmt)  stmt->Print(indentLevel+1);
}

void SwitchLabel::Check() {
    label->Check();
    st_list->Append(new Symbol());
    stmt->Check();
    st_list->RemoveAt(st_list->NumElements()-1);
}

SwitchStmt::SwitchStmt(Expr *e, List<Stmt *> *c, Default *d) {
    Assert(e != NULL && c != NULL && c->NumElements() != 0 );
    (expr=e)->SetParent(this);
    (cases=c)->SetParentAll(this);
    def = d;
    if (def) def->SetParent(this);
}

void SwitchStmt::PrintChildren(int indentLevel) {
    if (expr) expr->Print(indentLevel+1);
    if (cases) cases->PrintAll(indentLevel+1);
    if (def) def->Print(indentLevel+1);
}

void SwitchStmt::Check() {
    if(expr) expr->Check();
    if(cases) {
        for(int i = 0; i < cases->NumElements(); i++) {
            cases->Nth(i)->Check();
        }
    }
    if(def) def->Check();
}

