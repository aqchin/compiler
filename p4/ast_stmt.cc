/* File: ast_stmt.cc
 * -----------------
 * Implementation of statement node classes.
 */
#include "ast_stmt.h"
#include "ast_type.h"
#include "ast_decl.h"
#include "ast_expr.h"

#include "irgen.h"
#include "llvm/Bitcode/ReaderWriter.h"
#include "llvm/Support/raw_ostream.h"

Program::Program(List<Decl*> *d) {
    Assert(d != NULL);
    (decls=d)->SetParentAll(this);
}

void Program::PrintChildren(int indentLevel) {
    decls->PrintAll(indentLevel+1);
    printf("\n");
}

void Program::Emit() {
    // TODO:
    // This is just a reference for you to get started
    //
    // You can use this as a template and create Emit() function
    // for individual node to fill in the module structure and instructions.
    //
    //IRGenerator irgen;
    llvm::Module *mod = irgen->GetOrCreateModule("foo.bc");

    symtab->appendScope();

    int i;
    for(i = 0; i < decls->NumElements(); i++)
      decls->Nth(i)->Emit();

    // create a function signature
    /*std::vector<llvm::Type *> argTypes;
    llvm::Type *intTy = irgen->GetIntType();
    argTypes.push_back(intTy);
    llvm::ArrayRef<llvm::Type *> argArray(argTypes);
    llvm::FunctionType *funcTy = llvm::FunctionType::get(intTy, argArray, false);
*/
    // llvm::Function *f = llvm::cast<llvm::Function>(mod->getOrInsertFunction("foo", intTy, intTy, (Type *)0));
    /*llvm::Function *f = llvm::cast<llvm::Function>(mod->getOrInsertFunction("foo", funcTy));
    llvm::Argument *arg = f->arg_begin();
    arg->setName("x");*/

    // insert a block into the runction
    /*llvm::LLVMContext *context = irgen->GetContext();
    llvm::BasicBlock *bb = llvm::BasicBlock::Create(*context, "entry", f);*/

    // create a return instruction
    /*llvm::Value *val = llvm::ConstantInt::get(intTy, 1);
    llvm::Value *sum = llvm::BinaryOperator::CreateAdd(arg, val, "", bb);
    llvm::ReturnInst::Create(*context, sum, bb);*/

    mod->dump();

    // write the BC into standard output
    llvm::WriteBitcodeToFile(mod, llvm::outs());
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

llvm::Value *StmtBlock::Emit() {
  int i;
  for(i = 0; i < stmts->NumElements(); i++) {
    if(!(irgen->GetBasicBlock()->getTerminator())) {
      if(strcmp("StmtBlock", stmts->Nth(i)->GetPrintNameForNode()))
        stmts->Nth(i)->Emit();
      else {
        symtab->appendScope();
        stmts->Nth(i)->Emit();
        symtab->removeScope();
      }
    }
  }
  
  return NULL;
}

DeclStmt::DeclStmt(Decl *d) {
    Assert(d != NULL);
    (decl=d)->SetParent(this);
}

void DeclStmt::PrintChildren(int indentLevel) {
    decl->Print(indentLevel+1);
}

llvm::Value *DeclStmt::Emit() {
  //symtab->curScope()->insert(decl->GetId()->GetName(), (Node*)this);
  decl->Emit();

  return NULL;
}

ConditionalStmt::ConditionalStmt(Expr *t, Stmt *b) { 
    Assert(t != NULL && b != NULL);
    (test=t)->SetParent(this); 
    (body=b)->SetParent(this);
}

llvm::Value *ConditionalStmt::Emit() {
  test->Emit();
  body->Emit();

  return NULL;
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

llvm::Value *ForStmt::Emit() {
  llvm::LLVMContext *con = irgen->GetContext();
  llvm::Function *f = irgen->GetFunction();
  llvm::BasicBlock *footBB = llvm::BasicBlock::Create(*con,"footer",f);
  llvm::BasicBlock *stepBB = llvm::BasicBlock::Create(*con,"stepBB",f);
  llvm::BasicBlock *bodyBB = llvm::BasicBlock::Create(*con,"bodyBB",f);
  llvm::BasicBlock *headBB = llvm::BasicBlock::Create(*con,"header",f);

  init->Emit();

  llvm::BranchInst::Create(headBB, irgen->GetBasicBlock());
  irgen->SetBasicBlock(headBB);
  llvm::Value *cond = test->Emit();

  llvm::BranchInst::Create(bodyBB,footBB,cond,headBB);

  symtab->appendScope();
  irgen->SetBasicBlock(bodyBB);
  body->Emit();
  if(bodyBB->getTerminator() == NULL)
    llvm::BranchInst::Create(stepBB,bodyBB);
  symtab->removeScope();

  irgen->SetBasicBlock(stepBB);
  step->Emit();
  llvm::BranchInst::Create(headBB,stepBB);

  irgen->SetBasicBlock(footBB);

  return NULL;
}

void WhileStmt::PrintChildren(int indentLevel) {
    test->Print(indentLevel+1, "(test) ");
    body->Print(indentLevel+1, "(body) ");
}

llvm::Value *WhileStmt::Emit() {
  llvm::LLVMContext *con = irgen->GetContext();
  llvm::Function *f = irgen->GetFunction();
  llvm::BasicBlock *footBB = llvm::BasicBlock::Create(*con,"footer",f);
  llvm::BasicBlock *bodyBB = llvm::BasicBlock::Create(*con,"bodyBB",f);
  llvm::BasicBlock *headBB = llvm::BasicBlock::Create(*con,"header",f);
  
  llvm::BranchInst::Create(headBB, irgen->GetBasicBlock());
  irgen->SetBasicBlock(headBB);
  llvm::Value *cond = test->Emit();

  llvm::BranchInst::Create(bodyBB,footBB,cond,headBB);

  symtab->appendScope();
  irgen->SetBasicBlock(bodyBB);
  body->Emit();
  if(bodyBB->getTerminator() == NULL)
    llvm::BranchInst::Create(headBB,bodyBB);
  symtab->removeScope();

  irgen->SetBasicBlock(footBB);

  return NULL;  
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

llvm::Value *IfStmt::Emit() {
  //ConditionalStmt::Emit();
  llvm::Value *cond = test->Emit();
  
  llvm::LLVMContext *con = irgen->GetContext();
  llvm::Function *f = irgen->GetFunction();
  llvm::BasicBlock *footBB = llvm::BasicBlock::Create(*con,"footer",f);
  llvm::BasicBlock *elseBB = NULL;
  if(elseBody)
    elseBB = llvm::BasicBlock::Create(*con,"elseBB",f);
  llvm::BasicBlock *thenBB = llvm::BasicBlock::Create(*con,"thenBB",f);
  llvm::BasicBlock *curBB = irgen->GetBasicBlock();

  llvm::BranchInst::Create(thenBB,elseBody?elseBB:footBB,cond,curBB);

  symtab->appendScope();
  irgen->SetBasicBlock(thenBB);
  body->Emit();
  if(irgen->GetBasicBlock()->getTerminator() == NULL)
    new llvm::UnreachableInst(*(irgen->GetContext()),irgen->GetBasicBlock());
  symtab->removeScope();

  irgen->SetBasicBlock(footBB);

  if(elseBody) {
    symtab->appendScope();
    irgen->SetBasicBlock(elseBB);
    elseBody->Emit();
    if(irgen->GetBasicBlock()->getTerminator() == NULL)
      new llvm::UnreachableInst(*(irgen->GetContext()),irgen->GetBasicBlock());
    symtab->removeScope();
    irgen->SetBasicBlock(footBB);
  }

  return NULL;
}

llvm::Value *BreakStmt::Emit() {
  
  return NULL;
}

llvm::Value *ContinueStmt::Emit() {

  return NULL;
}

ReturnStmt::ReturnStmt(yyltype loc, Expr *e) : Stmt(loc) { 
    expr = e;
    if (e != NULL) expr->SetParent(this);
}

void ReturnStmt::PrintChildren(int indentLevel) {
    if ( expr ) 
      expr->Print(indentLevel+1);
}

llvm::Value *ReturnStmt::Emit() {
  if(expr) {
    llvm::Value *retV = expr->Emit();
    llvm::ReturnInst::Create(*(irgen->GetContext()),retV,irgen->GetBasicBlock());
  } //else {
    llvm::ReturnInst::Create(*(irgen->GetContext()),irgen->GetBasicBlock());
  //}

  return NULL;
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

llvm::Value *SwitchLabel::Emit() {
  label->Emit();

  symtab->appendScope();
  stmt->Emit();
  symtab->removeScope();

  return NULL;
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

llvm::Value *SwitchStmt::Emit() {
  if(expr) expr->Emit();

  if(cases) {
    int i;
    for(i = 0; i < cases->NumElements(); i++)
      cases->Nth(i)->Emit();
  }

  if(def) def->Emit();

  return NULL;
}
