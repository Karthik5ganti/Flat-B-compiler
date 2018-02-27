#include <bits/stdc++.h>

#include "class-defs.h"

using namespace std;

class Interpreter{
public:
  virtual void interpret(class Prog*)=0;
  virtual void interpret(class Decl_list*)=0;
  virtual void interpret(class St_list*)=0;

  virtual void interpret(class Var_s*)=0;
  virtual void interpret(class Var*)=0;

  virtual void interpret(class For_l*)=0;
  virtual void interpret(class While_l*)=0;
  virtual void interpret(class Ifelse*)=0;
  virtual void interpret(class Goto*)=0;
  virtual void interpret(class Label*)=0;

  virtual void interpret(class Assign*)=0;
  virtual void interpret(class Vars*)=0;

  virtual void interpret(class EnclExpr*)=0;
  virtual void interpret(class unExpr*)=0;
  virtual void interpret(class binExpr*)=0;
  virtual void interpret(class intLiteral*)=0;

  virtual void interpret(class binCond*)=0;
  virtual void interpret(class enclCond*)=0;
  virtual void interpret(class boolCond*)=0;

  virtual void interpret(class binBool*)=0;
  virtual void interpret(class enclBool*)=0;
  virtual void interpret(class exprBool*)=0;

  virtual void interpret(class Printpart*)=0;
  virtual void interpret(class recPrint*)=0;
  virtual void interpret(class SenPrint*)=0;
  virtual void interpret(class VarPrint*)=0;
  virtual void interpret(class NumPrint*)=0;
}
