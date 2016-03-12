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
  
  if(DEBUG) fprintf(stderr, "VarDecl start\n");

  llvm::Type *ty = llvm::Type::getVoidTy(*(irgen->GetContext()));
  if(this->type == Type::intType)
    ty = irgen->GetIntType();
  else if(this->type == Type::floatType)
    ty = irgen->GetFloatType();
  else if(this->type == Type::boolType)
    ty = irgen->GetBoolType();
  
  llvm::Twine *varN = new llvm::Twine(this->id->GetName());

  if(DEBUG) fprintf(stderr, "Type and Name Made\n");

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

  if(DEBUG) fprintf(stderr, "Finish VarDecl\n");
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

  llvm::Type *ty = llvm::Type::getVoidTy(*(irgen->GetContext()));
  if(this->returnType == Type::intType)
    ty = irgen->GetIntType();
  else if(this->returnType == Type::floatType)
    ty = irgen->GetFloatType();
  else if(this->returnType == Type::boolType)
    ty = irgen->GetBoolType();

  std::vector<llvm::Type*> argT;
  for(int i=0; i < formals->NumElements(); i++) {
    Type *tempT = formals->Nth(i)->GetType();

    llvm::Type *parTy = llvm::Type::getVoidTy(*(irgen->GetContext()));
    if(tempT == Type::intType)
      parTy = irgen->GetIntType();
    else if(tempT == Type::floatType)
      parTy = irgen->GetFloatType();
    else if(tempT == Type::boolType)
      parTy = irgen->GetBoolType();

    argT.push_back(parTy);
  }

  llvm::ArrayRef<llvm::Type*> argR(argT);
  llvm::FunctionType *funTy = llvm::FunctionType::get(ty,argR,false);

  llvm::Function *funct = llvm::cast<llvm::Function>(
  irgen->GetOrCreateModule("")->getOrInsertFunction(
  llvm::StringRef(this->id->GetName()),funTy));

  irgen->SetFunction(funct);

  llvm::Function::arg_iterator argIter = funct->arg_begin();
  for(int i = 0; i < formals->NumElements(); i++) {
    argIter->setName(formals->Nth(i)->GetID()->GetName());
    ++argIter;
  }

  //irgen->SetFunction(funct);
  llvm::LLVMContext *cont = irgen->GetContext();
  llvm::BasicBlock *bb = llvm::BasicBlock::Create(*cont,"entry",funct);
  irgen->SetBasicBlock(bb);

  symtab->appendScope();

  
  llvm::Function::arg_iterator locIter = funct->arg_begin();
  int i;
  for(i = 0; i < formals->NumElements(); i++) {
    llvm::Type *locT = llvm::Type::getVoidTy(*(irgen->GetContext()));
    if(formals->Nth(i)->GetType() == Type::intType)
      locT = irgen->GetIntType();
    else if(formals->Nth(i)->GetType() == Type::floatType)
      locT = irgen->GetFloatType();
    else if(formals->Nth(i)->GetType() == Type::boolType)
      locT = irgen->GetBoolType();

    llvm::Twine *locN = new llvm::Twine(formals->Nth(i)->GetID()->GetName());

    llvm::AllocaInst *locAllo = new llvm::AllocaInst(locT,*locN,
    irgen->GetBasicBlock());

    symtab->curScope()->insert(formals->Nth(i)->GetID()->GetName(),locAllo);
    new llvm::StoreInst(locIter,locAllo,irgen->GetBasicBlock());

    ++locIter;
  }

  if(DEBUG) fprintf(stderr, "Create Function Body\n");

  if(body) {
    llvm::BasicBlock *bn = llvm::BasicBlock::Create(*cont,"next",funct);
    llvm::BranchInst::Create(bn,bb);
    irgen->SetBasicBlock(bn);
    body->Emit();
  }
  symtab->removeScope();

  if(irgen->GetBasicBlock()->getTerminator() == NULL) {
    new llvm::UnreachableInst(*(irgen->GetContext()),irgen->GetBasicBlock());
  }

  //symtab->removeScope();
}
