/* File: ast_expr.cc
 * -----------------
 * Implementation of expression node classes.
 */

#include <string.h>
#include "ast_expr.h"
#include "ast_type.h"
#include "ast_decl.h"

#include "errors.h"
#define MAX_SWIZZLE_LEN 4

IntConstant::IntConstant(yyltype loc, int val) : Expr(loc) {
    value = val;
}
void IntConstant::PrintChildren(int indentLevel) { 
    printf("%d", value);
}

FloatConstant::FloatConstant(yyltype loc, double val) : Expr(loc) {
    value = val;
}
void FloatConstant::PrintChildren(int indentLevel) { 
    printf("%g", value);
}

BoolConstant::BoolConstant(yyltype loc, bool val) : Expr(loc) {
    value = val;
}
void BoolConstant::PrintChildren(int indentLevel) { 
    printf("%s", value ? "true" : "false");
}

VarExpr::VarExpr(yyltype loc, Identifier *ident) : Expr(loc) {
    Assert(ident != NULL);
    this->id = ident;
}

void VarExpr::PrintChildren(int indentLevel) {
    id->Print(indentLevel+1);
}

Type* VarExpr::GetType() {
  VarDecl* v = dynamic_cast<VarDecl*>(
    st_list->Nth(st_list->NumElements()-1)->lookup(id->GetName()) );

  if(v) return v->GetType();
  else return Type::errorType;
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

/*
Expr* CompoundExpr::GetTypeOf(Expr* e) {
  ComoundExpr* ce = dynamic_cast<CompoundExpr*>(e);
  if(ce) {
    if(ce->left) {
      Expr* l = GetTypeOf(ce->left);
      Expr* r = GetTypeOf(ce->right);

      string str_l(l->GetPrintNameForNode());
      string str_r(r->GetPrintNameForNode());

      if(strcmp(str_l, str_r) != 0) {
        ReportError::IncompatibleOperands(ce->op, 
        return new ExprError();
      }
      else return l; // Return one of them, we only care about types
    }
    else return GetTypeOf(ce->right);
  }
  else return e;
}
*/

Type* CompoundExpr::GetType() {
  Type* l;
  Type* r = right->GetType();

  if(left) {
    l = left->GetType();

    if(l->IsEquivalentTo(r)) return l;
    else {
      return Type::errorType;
    }
  }
  return r;
}

void ArithmeticExpr::Check() {
  Type* r = right->GetType();

  if(left) {
    Type* l = left->GetType();

    if(!(l->IsEquivalentTo(r)) ||
       !(l->IsEquivalentTo(Type::intType)) ||
       !(l->IsEquivalentTo(Type::floatType)) )
      ReportError::IncompatibleOperands(op, l, r);
  }
  else {
    if(!( (r->IsEquivalentTo(Type::intType)) ||
          (r->IsEquivalentTo(Type::floatType)) ))
      ReportError::IncompatibleOperand(op, r);
  }
}

void RelationalExpr::Check() {
  Type* r = right->GetType();
  Type* l = left->GetType();

  if(!(l->IsEquivalentTo(r)) ||
     !(l->IsEquivalentTo(Type::boolType)) ||
     !(r->IsEquivalentTo(Type::boolType)) )
    ReportError::IncompatibleOperands(op, l, r);
}

void EqualityExpr::Check() {
  Type* r = right->GetType();
  Type* l = left->GetType();

  if(!(l->IsEquivalentTo(r)) ||
     !(l->IsEquivalentTo(Type::boolType)) ||
     !(r->IsEquivalentTo(Type::boolType)) )
    ReportError::IncompatibleOperands(op, l, r);
}

void LogicalExpr::Check() {
  Type* r = right->GetType();
  Type* l = left->GetType();

  if(!(l->IsEquivalentTo(r)) ||
     !(l->IsEquivalentTo(Type::boolType)) ||
     !(r->IsEquivalentTo(Type::boolType)) )
    ReportError::IncompatibleOperands(op, l, r);
}

void AssignExpr::Check() {

}

void PostfixExpr::Check() {
  Type* l = left->GetType();

  if(!( (l->IsEquivalentTo(Type::intType)) ||
        (l->IsEquivalentTo(Type::floatType)) ))
    ReportError::IncompatibleOperand(op, l);
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

void FieldAccess::Check() {
  char* swizzle = field->GetName();
  Type* b = base->GetType();
  const int len = strlen(swizzle);
  
  if(!( (b->IsEquivalentTo(Type::vec2Type)) ||
        (b->IsEquivalentTo(Type::vec3Type)) ||
	(b->IsEquivalentTo(Type::vec4Type)) )) {
    ReportError::InaccessibleSwizzle(field, base);
    return;
  }

  int i;
  for(i = 0; i < len; i++) {
    if(swizzle[i] != 'x' || swizzle[i] != 'y' ||
       swizzle[i] != 'z' || swizzle[i] != 'w') {
      ReportError::InvalidSwizzle(field, base);
      return;
    }
  }

  for(i = 0; i < len; i++) {
    if(swizzle[i] == 'z' && b->IsEquivalentTo(Type::vec2Type)) {
      ReportError::SwizzleOutOfBound(field, base);
      return;
    }
    else if(swizzle[i] == 'w' && (b->IsEquivalentTo(Type::vec2Type) ||
            b->IsEquivalentTo(Type::vec3Type)))
      ReportError::SwizzleOutOfBound(field, base);
      return;
  }

  if(len > MAX_SWIZZLE_LEN)
    ReportError::OversizedVector(field, base);
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
 
