#include <bits/stdc++.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/Type.h>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/Target/TargetMachine.h>
#include <llvm/IR/PassManager.h>
#include <llvm/IR/Instructions.h>
#include <llvm/IR/CallingConv.h>
#include <llvm/Bitcode/ReaderWriter.h>
#include <llvm/IR/Verifier.h>
//#include <llvm/Assembly/PrintModulePass.h>
#include <llvm/IR/IRBuilder.h>
//#include <llvm/ModuleProvider.h>
#include <llvm/Support/TargetSelect.h>
#include <llvm/ExecutionEngine/GenericValue.h>
#include <llvm/ExecutionEngine/MCJIT.h>
#include <llvm/Support/raw_ostream.h>

using namespace std;
using namespace llvm;

enum exprType { binary = 1, location = 2, enclExpr = 3 , Unexpr = 4};

enum cType { cbinary=1, cencl=2 };

enum formType {assign=1 , for_l=2, print_l=3, ifelse_l=4, goto_l=5, while_l=6};

enum boolType { binBool=1, enclBool=2 };

union Node{
  int number;
  char* value;
  class Prog* prog;
  class Decl_list* decl_list;
  class Decl_data* decl_data;
  class Var_s* var_s;
  class Var* var;

  class St_list* st_list;
  class Forms* forms;
  class For_l* for_l;
  class While_l* while_l;
  class Ifelse* if_l;
  class Goto* goto_l;
  class Label* label;

  class Assign* assign;
  class Vars* vars;
  class Expr* expression;
  class Condition* cond;
  class Bool* bool_s;
  class recPrint* recPrint;
  class Printpart* Printpart;

  Node(){
		number = 0;
		value = NULL;
		}
~Node(){};
};
typedef union Node YYSTYPE;
#define YYSTYPE_IS_DECLARED 1

class astNode{
};

class Prog:public astNode{
private:
  class Decl_list* decl_list;
  class St_list* st_list;
public:
  Prog(class Decl_list*,class St_list*);
  void traverse();
  //void interpret(Interpreter *v){ return v->interpret(this);};
  void generateCode();
  llvm::Value* codegen();
};

class Decl_list:public astNode{
private:
	vector<class Decl_data*> decl_data;
	int cnt;
public:
	Decl_list(){};
	void push_back(class Decl_data*);
  //void interpret(Interpreter *v){ return v->interpret(this);};
  llvm::Value* codegen();
	void traverse();
};

class Decl_data:public astNode{
private:
	string dataType;
	vector<class Var*> var_list;
public:
	Decl_data(string,class Var_s*);
	vector<class Var*> getVarsList();
  //void interpret(Interpreter *v){ return v->interpret(this);};
  llvm::Value* codegen();
	void traverse();
};

class Var_s:public astNode{
private:
	vector<class Var*> var_list;
public:
	Var_s(){}
	void push_back(class Var*);
  //void interpret(Interpreter *v){ return v->interpret(this);};
	vector<class Var*> getVarsList();
  llvm::Value* codegen();
	void traverse();
};

class Var:public astNode{
private:
	string declType;
	string name;
	string dataType;
	unsigned int length;
public:
	Var(string,string,unsigned int);
	Var(string,string);
  //void interpret(Interpreter *v){ return v->interpret(this);};
	bool isArray();
	void setDataType(string);
  llvm::Value* codegen();
	void traverse();
	string getName(){return name;};
	int getLength(){return length;};
};

class St_list:public astNode{
private:
	vector<class Forms*> forms;
	int cnt;
public:
	St_list(){}
	void push_back(class Forms*);
  //void interpret(Interpreter *v){ return v->interpret(this);};
	void traverse();
  Value* codegen();
};

class Forms:public astNode{
protected:
  // formType ftype;
public:
  // void setFtype(formType x){ftype=x;}
  // formType getFtype(){return ftype;}
  // virtualvoid interpret(Interpreter *v)=0;
  virtual void traverse(){};
  virtual Value* codegen(){};
};


class Expr:public astNode{
protected:
	// exprType etype; /* Binary or unary or literal or location */
  string etype;
public:
  Expr(){
    // void virtual traverse();
  }
  void virtual traverse(){};
  // virtualvoid interpret(Interpreter *v)=0;
  virtual Value* codegen(){};
	// void setEtype(exprType x){etype = x;}
	string getEtype(){return etype;}
	// virtual string toString(){}
	// virtual void traverse(){}
};


class Assign:public Forms{
private:
	class Vars* var;
	class Expr* expr;
	string opr;
public:
	Assign(class Vars*, string, class Expr*);
  //void interpret(Interpreter *v){ return v->interpret(this);};
	void traverse();
  Value* codegen();
};


class Vars:public Expr{
private:
	string var;
  string type;
  class Expr* expr;
public:
  Vars(string,string,class Expr*);
  Vars(string,string);
  //void interpret(Interpreter *v){ return v->interpret(this);};
  void traverse();
  Value* codegen();
  string getType(){return type;};
  string getVar();/* returns the var name */
  bool is_array(); /* tells if its array or not */
  class Expr* getExpr();
};

class EnclExpr:public Expr{
private:
	class Expr* expr;
public:
	EnclExpr(class Expr*);
  //void interpret(Interpreter *v){ return v->interpret(this);};
  Value* codegen();
	void traverse();
};

class unExpr:public Expr{
private:
	class Expr* body; /* body of expression */
	string opr; /* Unary Expression */
public:
	unExpr(string,class Expr*);
  //void interpret(Interpreter *v){ return v->interpret(this);};
  Value* codegen();
	void traverse();
};

class binExpr:public Expr{
private:
	class Expr* lhs; /* left hand side */
	class Expr* rhs; /* right hand side */
	string opr; /* operator in between */
public:
	binExpr(class Expr*, string, class Expr*);
  //void interpret(Interpreter *v){ return v->interpret(this);};
  Value* codegen();
	void traverse();
};

class intLiteral:public Expr{
private:
	int value;
public:
	intLiteral(int);
  //void interpret(Interpreter *v){ return v->interpret(this);};
	int getValue();
	// string toString();
  Value* codegen();
  void traverse();
};

class Bool:public astNode{
protected:
  string btype;
  class Expr* expr;
public:
	string getbtype(){return btype;}
  // virtualvoid interpret(Interpreter *v)=0;
  virtual class Expr* getExpr(){};
	virtual string toString(){}
	virtual void traverse(){}
  virtual Value* codegen(){}
};

class binBool:public Bool{
private:
  class Bool* lhs;
  class Bool* rhs;
  string opr;
  class Expr* expr;

public:
  binBool(class Bool*,string,class Bool*);
  void traverse();
  class Expr* getExpr(){return NULL;};
  //void interpret(Interpreter *v){ return v->interpret(this);};
  Value* codegen();
};

class enclBool:public Bool{
private:
  class Bool* bool1;
  class Expr* expr;
public:
  enclBool(class Bool*);
  Value* codegen();
  class Expr* getExpr(){return NULL;};
  //void interpret(Interpreter *v){ return v->interpret(this);};
  void traverse();
};

class exprBool:public Bool{
private:
  class Expr* expr;
public:
  exprBool(class Expr* expr);
  //void interpret(Interpreter *v){ return v->interpret(this);};
  Value* codegen();
  class Expr* getExpr(){return expr;};
  void traverse();
};

class Condition:public astNode{
protected:
  // cType ctype;
public:
  // void setctype(cType x){ctype = x;}
	// cType getctype(){return ctype;}
	virtual void traverse(){}
  // virtualvoid interpret(Interpreter *v)=0;
  virtual Value* codegen(){};
};

class binCond:public Condition{
private:
  class Condition* lhs;
  class Condition* rhs;
  string opr;
public:
  binCond(class Condition*,string,class Condition*);
  //void interpret(Interpreter *v){ return v->interpret(this);};
  Value* codegen();
  void traverse();
};

class enclCond:public Condition{
private:
  class Condition* cond;
public:
  enclCond(class Condition*);
  Value* codegen();
  //void interpret(Interpreter *v){ return v->interpret(this);};
  void traverse();
};

class boolCond:public Condition{
private:
  class Bool* bool1;
public:
  boolCond(class Bool*);
  //void interpret(Interpreter *v){ return v->interpret(this);};
  Value* codegen();
  void traverse();
};

class For_l:public Forms{
private:
  string id_var;
  class Expr* expr1;
  class Expr* expr2;
  class Expr* expr3;
  class St_list* st_list;
public:
  For_l(string,class Expr*,class Expr*,class Expr*,class St_list*);
  Value* codegen();
  //void interpret(Interpreter *v){ return v->interpret(this);};
  void traverse();
};

class While_l:public Forms{
private:
  class Condition* cond;
  class St_list* st_list;
public:
  While_l(class Condition*,class St_list*);
  Value* codegen();
  //void interpret(Interpreter *v){ return v->interpret(this);};
  void traverse();
};

class Ifelse:public Forms{
private:
  class Condition* cond;
  class St_list* if_st;
  class St_list* else_st;
public:
  Ifelse(class Condition*,class St_list*,class St_list*);
  //void interpret(Interpreter *v){ return v->interpret(this);};
  Value* codegen();
  void traverse();
};

class recPrint:public Forms {
private:
  vector<class Printpart*> parts;
  // class Printpart* lhs;
  // class Printpart* rhs;
public:
  //void interpret(Interpreter *v){ return v->interpret(this);};
  // string getString(){};
  recPrint(){};
  void push_back(class Printpart* var){parts.push_back(var);}
  Value* codegen();
  void traverse();
};



class Printpart:public Forms{
private:
  string type;
public:
  virtual string Ptype(){};
  virtual string getString(){};
  // virtualvoid interpret(Interpreter *v)=0;
  virtual void traverse(){};
  virtual Value* codegen(){};
};

class SenPrint:public Printpart{
private:
  string str;
  string type="sen";
public:
  string getString(){return str;};
  string Ptype(){return "sen";};
  SenPrint(string);
  //void interpret(Interpreter *v){ return v->interpret(this);};
  Value* codegen();
  void traverse();
};

class VarPrint:public Printpart{
private:
  class Vars *var;
  string type = "var";
public:
  string getString(){return "none";}
  string Ptype(){return "var";}
  VarPrint(class Vars*);
  //void interpret(Interpreter *v){ return v->interpret(this);};
  Value* codegen();
  void traverse();
};

class NumPrint:public Printpart{
private:
  int num;
  string type = "num";
public:
  NumPrint(int);
  //void interpret(Interpreter *v){ return v->interpret(this);};
  Value* codegen();
  void traverse();
};

class Label:public Forms{
private:
  string var;
  class Forms* forms;
public:
  //void interpret(Interpreter *v){ return v->interpret(this);};
  Label(string,class Forms*);
  string getLab(){return var;};
  Value* codegen();
  void traverse();
};

class Goto:public Forms{
private:
  string lab;
  class Condition* cond;
public:
  //void interpret(Interpreter *v){ return v->interpret(this);};
  Goto(string,class Condition*);
  Value* codegen();
  void traverse();
};
