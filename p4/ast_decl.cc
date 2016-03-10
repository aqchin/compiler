/* File: ast_decl.cc
 * -----------------
 * Implementation of Decl node classes.
 */
#include "ast_decl.h"
#include "ast_type.h"
#include "ast_stmt.h"
#include <vector>
        
         
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

void VarDecl::Emit() {
  //symtab->curScope()->insert(this->id->GetName(), (Node*)this);
  
  llvm::Type *ty = irgen->GetIntType();
  if(this->type == Type::floatType)
    ty = irgen->GetFloatType();
  else if(this->type == Type::boolType)
    ty = irgen->GetBoolType();
  
  llvm::Twine *varN = new llvm::Twine::Twine(this->id->GetName());

  if(symtab->curIndex() == 0) {
    llvm::GlobalVariable *gvar = new llvm::GlobalVariable(
    *(irgen->GetOrCreateModule("")),ty,false,llvm::GlobalValue::ExternalLinkage,
    llvm::Constant::getNullValue(ty),*varN,NULL);
    
    symtab->gScope()->insert(this->id->GetName(),gvar);
  } else {
    llvm::AllocaInst *allo = new llvm::AllocaInst(ty,*varN,
    irgen->GetBasicBlock());

    symtab->curScope()->insert(this->id->GetName(),allo);
  }
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

void FnDecl::Emit() {
  //symtab->curScope()->insert(this->id->GetName(), (Node*)this);

  llvm::Type *ty = irgen->GetIntType();
  if(this->returnType == Type::floatType)
    ty = irgen->GetFloatType();
  else if(this->returnType == Type::boolType)
    ty = irgen->GetBoolType();

  std::vector<llvm::Type*> argT;
  for(int i=0; i < formals->NumElements(); i++) {
    Type *tempT = formals->Nth(i)->GetType();
    llvm::Type *parTy = irgen->GetIntType();
    if(tempT == Type::floatType)
      parTy = irgen->GetFloatType();
    else if(tempT == Type::boolType)
      parTy = irgen->GetBoolType();

    argT.push_back(parTy);
  }

  symtab->appendScope();
  //int i;
  //for(i = 0; i < formals->NumElements(); i++) {
    //symtab->curScope()->insert(formals->Nth(i)->GetId()->GetName(), formals->Nth(i));
  //}

  if(body) body->Emit();
  symtab->removeScope();
}
