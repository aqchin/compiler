/* operator assignment expressions
   Note: Identifiers may be FieldAccess or VarExpr. Either is acceptable.
 */

void foo() {
  int i;
  int i2;

  i *= 2;
  i *= i2;

  i /= 3;
  i /= i2;

  i += 1;
  i += i2;

  i -= 1;
  i -= i2;
}