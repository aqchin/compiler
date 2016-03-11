/* File: ast_expr.cc
 * -----------------
 * Implementation of expression node classes.
 */

#include <string.h>
#include "ast_expr.h"
#include "ast_type.h"
#include "ast_decl.h"


IntConstant::IntConstant(yyltype loc, int val) : Expr(loc) {
    value = val;
}
void IntConstant::PrintChildren(int indentLevel) { 
    printf("%d", value);
}

llvm::Value* IntConstant::Emit() {
  return llvm::ConstantInt::get(irgen->GetIntType(), value);
}

FloatConstant::FloatConstant(yyltype loc, double val) : Expr(loc) {
    value = val;
}
void FloatConstant::PrintChildren(int indentLevel) { 
    printf("%g", value);
}

llvm::Value* FloatConstant::Emit() {
  return llvm::ConstantFP::get(irgen->GetFloatType(), value);
}

BoolConstant::BoolConstant(yyltype loc, bool val) : Expr(loc) {
    value = val;
}
void BoolConstant::PrintChildren(int indentLevel) { 
    printf("%s", value ? "true" : "false");
}

llvm::Value* BoolConstant::Emit() {
  return llvm::ConstantInt::get(irgen->GetBoolType(), value);
}

VarExpr::VarExpr(yyltype loc, Identifier *ident) : Expr(loc) {
    Assert(ident != NULL);
    this->id = ident;
}

void VarExpr::PrintChildren(int indentLevel) {
    id->Print(indentLevel+1);
}

llvm::Value* VarExpr::Emit() {
  llvm::Value *mem = NULL;

  int i;
  for(i = symtab->curIndex(); i >= 0; i--) {
    mem = symtab->at(i)->lookup(this->id->GetName());
    if(mem) break;
  }

  llvm::Twine *tw = new llvm::Twine(this->id->GetName());
  llvm::Value *ret = new llvm::LoadInst(mem, *tw, irgen->GetBasicBlock());

  return ret;
}

llvm::Value* VarExpr::EmitAddress() {
  llvm::Value *mem = NULL;

  int i;
  for(i = symtab->curIndex(); i >= 0; i--) {
    mem = symtab->at(i)->lookup(this->id->GetName());
    if(mem) break;
  }

  return mem;
}

Operator::Operator(yyltype loc, const char *tok) : Node(loc) {
    Assert(tok != NULL);
    strncpy(tokenString, tok, sizeof(tokenString));
}

void Operator::PrintChildren(int indentLevel) {
    printf("%s",tokenString);
}

CompoundExpr::CompoundExpr(Expr *l, Operator *o, Expr *r) 
  : Expr(Join(l->GetLocation(), r->GetLocation())) {
    Assert(l != NULL && o != NULL && r != NULL);
    (op=o)->SetParent(this);
    (left=l)->SetParent(this); 
    (right=r)->SetParent(this);
}

CompoundExpr::CompoundExpr(Operator *o, Expr *r) 
  : Expr(Join(o->GetLocation(), r->GetLocation())) {
    Assert(o != NULL && r != NULL);
    left = NULL; 
    (op=o)->SetParent(this);
    (right=r)->SetParent(this);
}

CompoundExpr::CompoundExpr(Expr *l, Operator *o) 
  : Expr(Join(l->GetLocation(), o->GetLocation())) {
    Assert(l != NULL && o != NULL);
    (left=l)->SetParent(this);
    (op=o)->SetParent(this);
}

void CompoundExpr::PrintChildren(int indentLevel) {
   if (left) left->Print(indentLevel+1);
   op->Print(indentLevel+1);
   if (right) right->Print(indentLevel+1);
}

llvm::Value* ArithmeticExpr::Emit() {
  llvm::Value *l = NULL;
  llvm::Value *r = right->Emit();
  llvm::Value *ret = NULL;

  if(left) l = left->Emit();

  string str = op->toString();
  if(!str.compare("+"))
    ret = llvm::BinaryOperator::CreateAdd(l, r, "", irgen->GetBasicBlock());
  
  else if(!str.compare("-"))
    ret = llvm::BinaryOperator::CreateSub(l, r, "", irgen->GetBasicBlock());

  else if(!str.compare("*"))
    ret = llvm::BinaryOperator::CreateMul(l, r, "", irgen->GetBasicBlock());

  else if(!str.compare("/"))
    ret = llvm::BinaryOperator::CreateUDiv(l, r, "", irgen->GetBasicBlock());

  else if(!str.compare("++")) {
    llvm::Value *inc = llvm::ConstantInt::get(irgen->GetIntType(), 1);
    ret = llvm::BinaryOperator::CreateAdd(r, inc, "", irgen->GetBasicBlock());

    VarExpr* r_var = dynamic_cast<VarExpr*>(right);
    new llvm::StoreInst(ret, r_var->EmitAddress(), irgen->GetBasicBlock());

  } else if(!str.compare("--")) {
    llvm::Value *dec = llvm::ConstantInt::get(irgen->GetIntType(), 1);
    ret = llvm::BinaryOperator::CreateSub(r, dec, "", irgen->GetBasicBlock());

    VarExpr* r_var = dynamic_cast<VarExpr*>(right);
    new llvm::StoreInst(ret, r_var->EmitAddress(), irgen->GetBasicBlock());
  }

  return ret;
}

llvm::Value* RelationalExpr::Emit() {
  llvm::Value *l = left->Emit();
  llvm::Value *r = right->Emit();
  llvm::Type *ty = l->getType();

  bool FTy = (ty == (llvm::Type*)irgen->GetFloatType());
  llvm::CmpInst::OtherOps o = FTy ? llvm::CmpInst::FCmp : llvm::CmpInst::ICmp;
  llvm::CmpInst::Predicate p = llvm::CmpInst::FCMP_FALSE;

  string str = op->toString();
  if(!str.compare("<"))
    p = FTy ? llvm::CmpInst::FCMP_OLT : llvm::ICmpInst::ICMP_SLT;
  
  else if(!str.compare(">"))
    p = FTy ? llvm::CmpInst::FCMP_OGT : llvm::ICmpInst::ICMP_SGT;
  
  else if(!str.compare("<="))
    p = FTy ? llvm::CmpInst::FCMP_OLE : llvm::ICmpInst::ICMP_SLE;
  
  else if(!str.compare(">="))
    p = FTy ? llvm::CmpInst::FCMP_OGE : llvm::ICmpInst::ICMP_SGE;
  
  return llvm::CmpInst::Create(o, p, l, r, "", irgen->GetBasicBlock());
}

llvm::Value* EqualityExpr::Emit() {
  llvm::Value *l = left->Emit();
  llvm::Value *r = right->Emit();
  llvm::Type *ty = l->getType();

  bool FTy = (ty == (llvm::Type*)irgen->GetFloatType());
  llvm::CmpInst::OtherOps o = FTy ? llvm::CmpInst::FCmp : llvm::CmpInst::ICmp;
  llvm::CmpInst::Predicate p = llvm::CmpInst::FCMP_FALSE;

  string str = op->toString();
  if(!str.compare("=="))
    p = FTy ? llvm::CmpInst::FCMP_OEQ : llvm::ICmpInst::ICMP_EQ;

  else if(!str.compare("!="))
    p = FTy ? llvm::CmpInst::FCMP_ONE : llvm::ICmpInst::ICMP_NE;

  return llvm::CmpInst::Create(o, p, l, r, "", irgen->GetBasicBlock());
}

llvm::Value* LogicalExpr::Emit() {
  llvm::Value *l = left->Emit();
  llvm::Value *r = right->Emit();
  llvm::Value *ret = NULL;

  bool l_bool = !(((llvm::ConstantInt*)l)->isZero());
  bool r_bool = !(((llvm::ConstantInt*)r)->isZero());

  string str = op->toString();
  if(!str.compare("&&")) {
    if(l_bool && r_bool)
      ret = l;
    else if(!l_bool)
      ret = l;
    else
      ret = r;
  
  } else if(!str.compare("||")) {
    if(l_bool)
      ret = l;
    else if(r_bool)
      ret = r;
    else
      ret = l;
  }

  return ret;
}

llvm::Value* AssignExpr::Emit() {
  VarExpr* l_var = dynamic_cast<VarExpr*>(left);
  llvm::Value *l_addr = l_var->EmitAddress();
  llvm::Value *r = right->Emit();
  if(dynamic_cast<llvm::StoreInst*>(r))
    r = ((llvm::StoreInst*)r)->getValueOperand();
  llvm::Value *l;
  llvm::Value *ret = NULL;

  string str = op->toString();
  if(!str.compare("=")) {
    ret = new llvm::StoreInst(r, l_addr, irgen->GetBasicBlock());
  
  } else if(!str.compare("+=")) {
    l = left->Emit();
    llvm::Value *res = llvm::BinaryOperator::CreateAdd(l, r, "", irgen->GetBasicBlock());

    ret = new llvm::StoreInst(res, l_addr, irgen->GetBasicBlock());
  
  } else if(!str.compare("-=")) {
    l = left->Emit();
    llvm::Value *res = llvm::BinaryOperator::CreateSub(l, r, "", irgen->GetBasicBlock());

    ret = new llvm::StoreInst(res, l_addr, irgen->GetBasicBlock());
  
  } else if(!str.compare("*=")) {
    l = left->Emit();
    llvm::Value *res = llvm::BinaryOperator::CreateMul(l, r, "", irgen->GetBasicBlock());

    ret = new llvm::StoreInst(res, l_addr, irgen->GetBasicBlock());
  
  } else if(!str.compare("/=")) {
    l = left->Emit();
    llvm::Value *res = llvm::BinaryOperator::CreateUDiv(l, r, "", irgen->GetBasicBlock());

    ret = new llvm::StoreInst(res, l_addr, irgen->GetBasicBlock());
  }

  return ret;
}

llvm::Value* PostfixExpr::Emit() {
  VarExpr* l_var = dynamic_cast<VarExpr*>(left);
  llvm::Value *l_addr = l_var->EmitAddress();
  llvm::Value *i = llvm::ConstantInt::get(irgen->GetIntType(), 1);
  llvm::Value *l = left->Emit();
  llvm::Value *ret = NULL;

  string str = op->toString();
  if(!str.compare("++"))
    ret = llvm::BinaryOperator::CreateAdd(l, i, "", irgen->GetBasicBlock());

  else if(!str.compare("--"))
    ret = llvm::BinaryOperator::CreateSub(l, i, "", irgen->GetBasicBlock());

  new llvm::StoreInst(ret, l_addr, irgen->GetBasicBlock());

  return ret;
}
  
ArrayAccess::ArrayAccess(yyltype loc, Expr *b, Expr *s) : LValue(loc) {
    (base=b)->SetParent(this); 
    (subscript=s)->SetParent(this);
}

void ArrayAccess::PrintChildren(int indentLevel) {
    base->Print(indentLevel+1);
    subscript->Print(indentLevel+1, "(subscript) ");
  }
     
FieldAccess::FieldAccess(Expr *b, Identifier *f) 
  : LValue(b? Join(b->GetLocation(), f->GetLocation()) : *f->GetLocation()) {
    Assert(f != NULL); // b can be be NULL (just means no explicit base)
    base = b; 
    if (base) base->SetParent(this); 
    (field=f)->SetParent(this);
}


  void FieldAccess::PrintChildren(int indentLevel) {
    if (base) base->Print(indentLevel+1);
    field->Print(indentLevel+1);
  }

llvm::Value* FieldAccess::Emit() {
  return NULL;
}

Call::Call(yyltype loc, Expr *b, Identifier *f, List<Expr*> *a) : Expr(loc)  {
    Assert(f != NULL && a != NULL); // b can be be NULL (just means no explicit base)
    base = b;
    if (base) base->SetParent(this);
    (field=f)->SetParent(this);
    (actuals=a)->SetParentAll(this);
}

 void Call::PrintChildren(int indentLevel) {
    if (base) base->Print(indentLevel+1);
    if (field) field->Print(indentLevel+1);
    if (actuals) actuals->PrintAll(indentLevel+1, "(actuals) ");
  }
 
