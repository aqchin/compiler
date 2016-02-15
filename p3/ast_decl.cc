/* File: ast_decl.cc
 * -----------------
 * Implementation of Decl node classes.
 */
#include "ast_decl.h"
#include "ast_type.h"
#include "ast_stmt.h"
#include "errors.h"
         
Decl::Decl(Identifier *n) : Node(*n->GetLocation()) {
    Assert(n != NULL);
    (id=n)->SetParent(this); 
}


VarDecl::VarDecl(Identifier *n, Type *t) : Decl(n) {
    Assert(n != NULL && t != NULL);
    (type=t)->SetParent(this);
}
  
void VarDecl::PrintChildren(int indentLevel) { 
   if (type) type->Print(indentLevel+1);
   if (id) id->Print(indentLevel+1);
}

void VarDecl::Check() {
  int i;
  for(i = st_list->NumElements()-1; i >= 0 ; i--) {
    if(st_list->Nth(i)->exists(this->GetId()->GetName())) {
      ReportError::DeclConflict(this, 
        dynamic_cast<Decl*>(st_list->Nth(i)->lookup(this->id->GetName())));
      break;
    }
  }
  st_list->Nth(st_list->NumElements()-1)->insert(this->id->GetName(), (Node*)this);
}


FnDecl::FnDecl(Identifier *n, Type *r, List<VarDecl*> *d) : Decl(n) {
    Assert(n != NULL && r!= NULL && d != NULL);
    (returnType=r)->SetParent(this);
    (formals=d)->SetParentAll(this);
    body = NULL;
}

void FnDecl::SetFunctionBody(Stmt *b) { 
    (body=b)->SetParent(this);
}

void FnDecl::PrintChildren(int indentLevel) {
    if (returnType) returnType->Print(indentLevel+1, "(return type) ");
    if (id) id->Print(indentLevel+1);
    if (formals) formals->PrintAll(indentLevel+1, "(formals) ");
    if (body) body->Print(indentLevel+1, "(body) ");
}

void FnDecl::Check() {
  if(st_list->Nth(st_list->NumElements()-1)->exists(this->GetId()->GetName())) {
    ReportError::DeclConflict(this,
      dynamic_cast<Decl*>(st_list->Nth(st_list->NumElements()-1)->lookup(
        this->id->GetName())));
  }
  st_list->Nth(st_list->NumElements()-1)->insert(this->id->GetName(), (Node*)this);

  st_list->Append(new Symbol());
  int i;
  for(i = 0; i < formals->NumElements(); i++) {
    if(st_list->Nth(st_list->NumElements()-1)->exists(formals->Nth(i)->GetId()->GetName())) {
      ReportError::DeclConflict(formals->Nth(i), dynamic_cast<Decl*>(
        st_list->Nth(st_list->NumElements()-1)->lookup(formals->Nth(i)->GetId()->GetName())));
    }
    st_list->Nth(st_list->NumElements()-1)->insert(
      formals->Nth(i)->GetId()->GetName(),formals->Nth(i));
  }

    /*if(!(returnType->IsEquivalentTo(Type::voidType))) {
        StmtBlock* sb = dynamic_cast<StmtBlock*>(body);
        bool flag = true;
        for(i = 0; sb->stmts->NumElements(); i++) {
            if(!strcmp("ReturnStmt", sb->stmts->Nth(i)->GetPrintNameForNode()))
                flag = false;
        }
        if(flag)
            ReportError::ReturnMissing(this);
    }*/

  body->Check();
  st_list->RemoveAt(st_list->NumElements()-1);
}
