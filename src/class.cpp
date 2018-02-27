#include <bits/stdc++.h>

#include "class-defs.h"

using namespace std;
using namespace llvm;

static Module *TheModule = new Module("B compiler",llvm::getGlobalContext());
static LLVMContext &Context = getGlobalContext();
static IRBuilder<> Builder(Context);
static vector<string> FunArgs;
llvm::FunctionType *funcType = llvm::FunctionType::get(Builder.getVoidTy(), false);
llvm::Function *mainFunc = llvm::Function::Create(funcType, llvm::Function::ExternalLinkage, "main", TheModule);
static FunctionPassManager *TheFPM;


struct node{
  string dtype;
  string name;
  string type;
  vector <int> arr;
  unsigned int len;
  class St_list* st_list;
}node;

class Table{
public:
  vector <struct node*> var_list;
  void insert(string datatype,string name,string type,unsigned int l,int k){
    for(int i=0;i<var_list.size();i++){
      if(var_list[i]->name==name){
          cout<<"var "+name+" is redeclared\n";
          exit(0);
      }
    }
    struct node* temp=new struct node();
    temp->dtype=datatype;
    temp->name=name;
    temp->type=type;
    temp->len=l;
    for(int i=0;i<l;i++){
      temp->arr.push_back(k);
    }
    var_list.push_back(temp);
  }

  int lookup(string declType, string name){
    int flag=0;
    for(int i=0;i<var_list.size();i++){
      if(var_list[i]->name==name){
        if((var_list[i]->type).compare(declType)==0){
          flag=1;
          break;
        }
        cout<<declType;
        flag=2;
      }
    }
    if(flag==0)
    {
      cout << "variable '" << name << "' is not declared" << endl;
      exit(0);
    }
    else if(flag==2)
    {
      cout << "variable '" << name << "' : declared as another type" << endl;
      exit(0);
    }
    return flag;
  }
};

class Table table;
/* --------- Constructors ---------*/

Var::Var(string declType, string name){
  this->declType = declType;
  this->name = name;
}

Var::Var(string declType, string name, unsigned int length){
  this->declType = declType;
  this->name = name;
  this->length = length;
}

Decl_data::Decl_data(string dataType, class Var_s* var_s){
  this->dataType = dataType;
  this->var_list = var_s->getVarsList();
  for(int i=0;i<var_list.size();i++){
    var_list[i]->setDataType(dataType);
  }
  for(int i=0;i<var_list.size();i++)
  {
    cout<<var_list[i]->getName()+" ";
  }
}

Assign::Assign(class Vars* var, string oper, class Expr* expr){
  this->var = var;
  this->opr = oper;
  this->expr = expr;
  // this->ftype = assign;
}

Vars::Vars(string var, string Vars_type, class Expr* expr){
  this->var = var;
  this->type = Vars_type;
  this->expr = expr;
  this->etype = "vars";
  // this->etype = Vars;
}

Vars::Vars(string var, string Vars_type){
  this->var = var;
  this->type = Vars_type;
  this->etype = "vars";
  // this->etype = Vars;
}

binExpr::binExpr(class Expr* lhs, string opr, class Expr* rhs){
  this->lhs = lhs;
  this->rhs = rhs;
  this->opr = opr;
  this->etype = "binexpr";
  // this->etype = binary;
}

unExpr::unExpr(string opr, class Expr* expr){
  this->opr = opr;
  this->body = expr;
  this->etype = "unexpr";
  // this->etype = Unexpr;
}

EnclExpr::EnclExpr(class Expr* expr){
  this->expr = expr;
  this->etype = "enclexpr";
  // this->etype = enclExpr;
}

intLiteral::intLiteral(int value){
  this->value = value;
}

binCond::binCond(class Condition* lhs,string opr,class Condition* rhs){
  this->lhs=lhs;
  this->opr=opr;
  this->rhs=rhs;
  // this->ctype=cbinary;
}

enclCond::enclCond(class Condition* cond){
  this->cond=cond;
  // this->ctype=cencl;
}

boolCond::boolCond(class Bool* bool1){
  this->bool1=bool1;
}

Ifelse::Ifelse(class Condition* cond, class St_list* st1, class St_list* st2){
  this->cond = cond;
  this->if_st = st1;
  this->else_st = st2;
  // this->ftype = ifelse_l;
}

For_l::For_l(string id_var, class Expr* expr1, class Expr* expr2, class Expr* expr3,class St_list* st){
  this->id_var=id_var;
  this->expr1=expr1;
  this->expr2=expr2;
  this->expr3=expr3;
  this->st_list=st;
  // this->ftype = for_l;
}

While_l::While_l(class Condition* cond, class St_list* st_list){
  this->cond=cond;
  this->st_list=st_list;
  // this->ftype = class formType::while_l;
}

binBool::binBool(class Bool* lhs, string opr,class  Bool* rhs){
  this->lhs=lhs;
  this->opr=opr;
  this->rhs=rhs;
  this->btype="binbool";
}

enclBool::enclBool(class Bool* bool1){
  this->bool1=bool1;
  this->btype="enclbool";
}

exprBool::exprBool(class Expr* expr)
{
  this->expr=expr;
  this->btype="expr";
}


Prog::Prog(class Decl_list* decl_list, class St_list* st_list){
  this->st_list = st_list;
  this->decl_list = decl_list;
}

SenPrint::SenPrint(string str){
  this->str=str;
}

VarPrint::VarPrint(class Vars* var){
  this->var=var;
}

NumPrint::NumPrint(int num){
  this->num=num;
}

// recPrint::recPrint(class Printpart* lhs, class Printpart* rhs){
//   this->lhs=lhs;
//   this->rhs=rhs;
// }

Label::Label(string var, class Forms* forms){
  this->forms=forms;
  this->var= var;
}

Goto::Goto(string lab,class Condition* cond){
  this->lab=lab;
  this->cond=cond;
}

/*-------------Methods-------------*/
bool Var::isArray(){
  return (declType.compare("Array")==0);
}

void Var::setDataType(string dataType){
  this->dataType = dataType;
}

void Var_s::push_back(class Var* var){
  var_list.push_back(var);
  int i;
  for(i=0;i<var_list.size();i++)
  {
    cout<<var_list[i]->getName()+"\n";
  }

}

vector <class Var*> Var_s::getVarsList(){
  return var_list;
}

vector <class Var*>Decl_data::getVarsList(){
  return var_list;
}

void Decl_list::push_back(class Decl_data* var){
  decl_data.push_back(var);
}

void St_list::push_back(class Forms* form){
  forms.push_back(form);
}

string Vars::getVar(){
  return var;
}

bool Vars::is_array(){
  return type.compare("Array") == 0;
}

class Expr* Vars::getExpr(){
  return expr;
}

int intLiteral::getValue(){
  return value;
}


/*-----------------traversals--------------*/
void Decl_list::traverse(){
  for(int i=0;i<decl_data.size();i++){
    decl_data[i]->traverse();
  }
}

void Decl_data::traverse(){

  for(int i=0;i<var_list.size();i++){
    var_list[i]->traverse();
  }
}

void Var::traverse(){
  if(declType.compare("Array")==0){
    cout<< "decl name = "+name+" type = "+dataType+" Array of length ";
    cout<<length;
    cout<<"\n";
    table.insert(dataType,name,declType,length,0);
  }
  else{
    table.insert(dataType,name,declType,1,0);
    cout<< "decl name = "+name+" type = "+dataType+"\n";
  }
}

void St_list::traverse(){
  for(int i=0;i<forms.size();i++){
    forms[i]->traverse();
  }
}

void Assign::traverse(){
  cout<<"\n LHS name : "+var->getVar();
  table.lookup(var->getType(),var->getVar());
  if(var->is_array()){
    var->getExpr()->traverse();
  }
  cout<<"\noperation:"+opr;
  expr->traverse();
}

void Vars::traverse(){
  table.lookup(type,var);
  cout<<"\n name:"+var;
  if(is_array()){
    expr->traverse();
  }
  else{
    cout<<"\n";
  }
}

void intLiteral::traverse(){
  cout << "\n integer value : " << value << "\n";
}

void binBool::traverse(){
  cout<<"\nboolean lhs: ";
  lhs->traverse();
  cout<<"\noperator: "+opr;
  rhs->traverse();
}

void enclBool::traverse(){
  bool1->traverse();
}

void exprBool::traverse(){
  expr->traverse();
}

void EnclExpr::traverse(){
  expr->traverse();
}

void binExpr::traverse(){
  cout << "\n binary_expression type :" << opr <<"\n";
  lhs->traverse();
  rhs->traverse();
}

void unExpr::traverse(){
  string operation  = " Unary Negitive";
  if(opr == "!"){
    operation = " Unary NOT";
  }
  cout << "\n unary_expression type:" << operation << "\n";
  body->traverse();
}

void binCond::traverse(){
  cout<<"\nlhs condition: ";
  lhs->traverse();
  cout<<" \noperator: "+opr;
  rhs->traverse();
}

void enclCond::traverse(){
  cout<<" \nbody cond: ";
  cond->traverse();
}

void boolCond::traverse(){
  cout<<"\nbool: ";
  bool1->traverse();
}

void For_l::traverse(){
  cout<<"\n For Loop initialization : ";
  expr1->traverse();
  cout<<"\n ending : ";
  expr2->traverse();
  if(expr3!=NULL){
    cout<<"\n condition : ";
    expr3->traverse();
  }
  cout<<"\n statement_list:";
  st_list->traverse();
  cout<<"\n";
}

void Ifelse::traverse(){
  cout<<"\n If condition:";
  cond->traverse();
  cout<<"\n statements:";
  if_st->traverse();
  if(else_st!=NULL){
    cout<<"\n else statement:";
    else_st->traverse();
  }
  cout<<"\n";
}

void While_l::traverse(){
  cout<<"\n While condition: " ;
  cond->traverse();
  cout<<")";
  cout<<"\n statement body:";
  st_list->traverse();
}


void VarPrint::traverse(){
  cout<<"\nPrinting:";
  var->traverse();
}

void SenPrint::traverse(){
  cout<<"\nPrinting: ";
  cout<<str;
}

void recPrint::traverse(){
  for(int i=0;i<parts.size();i++){
    parts[i]->traverse();
  }
}

void NumPrint::traverse(){
  cout<<"\nPrinting: ";
  cout<<num;
}

void Label::traverse(){
  cout<<"\n label name:"+var;
  forms->traverse();
}

void Goto::traverse(){
  if(cond!=NULL){
    cout<<"\nGoto if condition: ";
    cond->traverse();
  }
  cout<<"\nlabel name: "+lab;
}

void Prog::traverse(){
  cout<<"\n********************AST TREE************************\n\n";
  decl_list->traverse();
  llvm::BasicBlock *entry = llvm::BasicBlock::Create(Context, "entrypoint", mainFunc);
  Builder.SetInsertPoint(entry);
  st_list->traverse();
  cout<<"\n";
}

/*---------------------Interpreter-----------------*/

// class Interpreterchild : public Interpreter{
//   class Prog *root;
// public:
//   Interpretchild(class Prog *root){
//     this->root=root;
//   }
//
//   void begin_intrpt(){
//     this->interpret(root);
//   }
//
//   void interpret(class Prog* node){
//     node->decl_list->interpret(this);
//     node->st_list->interpret(this);
//   }
//
//   void interpret(class Decl_list *node){
//     for(int i=0;i<decl_data.size();i++){
//       node->decl_data[i]->interpret(this);
//     }
//   }





/*-------------------CodeGen-----------------------*/

Value* Decl_data::codegen(){
  for(int i=0;i<var_list.size();i++){
    class Var* var=var_list[i];
    llvm::Type *ty;
    ty=Type::getInt32Ty(Context);
    if(var->isArray()){
      ArrayType* arrType= ArrayType::get(ty,var->getLength());
      // PointerType* PointerTy_1 = PointerType::get(ArrayType::get(ty,var->getLength()),0);
      TheModule->getOrInsertGlobal(var->getName(),arrType);
      GlobalVariable *gv = TheModule->getNamedGlobal(var->getName());
      gv->setLinkage(GlobalValue::ExternalLinkage);
      gv->setInitializer(ConstantAggregateZero::get(arrType));
    }
    else{
     TheModule->getOrInsertGlobal(var->getName(),Builder.getInt32Ty());
     PointerType* ptrTy = PointerType::get(ty,0);
     GlobalVariable* gv = TheModule->getNamedGlobal(var->getName());
     gv->setLinkage(GlobalValue::CommonLinkage);
     ConstantInt* const_int_val = ConstantInt::get(Context, APInt(32,0));
     gv->setInitializer(const_int_val);

   }
  }
  Value* v = ConstantInt::get(getGlobalContext(), APInt(32,1));
  return v;
}

Value* Decl_list::codegen(){
  for(int i = 0; i < decl_data.size(); i++){
    decl_data[i]->codegen();
  }
  Value* v = ConstantInt::get(getGlobalContext(), APInt(32,1));
  return v;
}

Value* Prog::codegen(){
  llvm::Value *V = ConstantInt::get(getGlobalContext(), APInt(32,0));
  V = decl_list->codegen();
  V = st_list->codegen();
  cout<<"ending here\n";
  Builder.CreateRetVoid();
  return V;
}

Value* St_list::codegen(){
  for(int i=0;i<forms.size();i++){
    forms[i]->codegen();
  }
  Value* v = ConstantInt::get(getGlobalContext(), APInt(32,1));
  return v;
}

Value* Assign::codegen(){
  Value* var1 = var->codegen();
  Value* expr1 =expr->codegen();
  if(expr->getEtype()=="vars"){
    expr1=Builder.CreateLoad(expr1);
  }
  return Builder.CreateStore(expr1,var1);
}

Value* Vars::codegen(){
  Value* va = TheModule->getGlobalVariable(var);
  if(va==0){
    cout<<"Variable not found "+var;
  }
  if (type!="Array"){
    return va;
  }
  if(expr != NULL){
    Value* index = expr->codegen();
    if(expr->getEtype()=="vars"){
      index = Builder.CreateLoad(index);
    }
    if(index==0){
      cout<<"Invalid array index";
    }
    vector<Value*> array_index;
    array_index.push_back(Builder.getInt32(0));
    array_index.push_back(index);
    va = Builder.CreateGEP(va, array_index, var+"_Index");
    return va;
  }
}

Value* EnclExpr::codegen(){
  return expr->codegen();
}

Value* unExpr::codegen(){
  Value* v = body->codegen();
  if(body->getEtype() == "vars"){
    v = Builder.CreateLoad(v);
  }
  if(opr == "-"){
    return Builder.CreateNeg(v,"negtmp");
  }
  else if (opr == "!"){
    return Builder.CreateNot(v,"nottmp");
  }
}

Value* binExpr::codegen(){
  Value* left = lhs->codegen();
  Value* right = rhs->codegen();
  if(lhs->getEtype() == "vars"){
    left = Builder.CreateLoad(left);
  }
  if(rhs->getEtype() == "vars"){
    right = Builder.CreateLoad(right);
  }
  if(left == 0){
    cout<<"Error in left operand of " + opr;
  }
  else if(right == 0){
    cout<<"Error in right operand of " + opr;
  }
  Value* v;
  if(opr == "+"){
    v = Builder.CreateAdd(left,right,"addtmp");
  }
  else if (opr == "-"){
    v = Builder.CreateSub(left,right,"subtmp");
  }
  else if (opr == "*"){
    v = Builder.CreateMul(left,right,"multmp");
  }
  else if (opr == "/"){
    v = Builder.CreateUDiv(left,right,"divtmp");
  }
  else if(opr == "%"){
    v = Builder.CreateURem(left,right,"modtmp");
  }
  return v;
}

Value* intLiteral::codegen(){
  Value* v = ConstantInt::get(getGlobalContext(), llvm::APInt(32,value));
  return v;
}

Value* binBool::codegen(){
  Value* left = lhs->codegen();
  if(lhs->getbtype()=="expr"){
    class Expr* expr=lhs->getExpr();
    if(expr->getEtype()=="vars"){
        left = Builder.CreateLoad(left);
    }
  }
  Value* right = rhs->codegen();
  if(rhs->getbtype()=="expr"){
    class Expr* expr=rhs->getExpr();
    if(expr->getEtype()=="vars"){
        right = Builder.CreateLoad(right);
    }
  }
  cout<<"before condition\n";
  cout<<opr<<endl;
  if(left == 0){
    cout<<"Error in left operand of " + opr;
  }
  else if(right == 0){
    cout<<"Error in right operand of " + opr;
  }
  Value* v;
  if (opr == "<"){
    v = Builder.CreateICmpULT(left,right,"ltcomparetmp");
  }
  else if (opr == ">"){
    v = Builder.CreateICmpUGT(left,right,"gtcomparetmp");
  }
  else if (opr == "<="){
    v = Builder.CreateICmpULE(left,right,"lecomparetmp");
  }
  else if (opr == ">="){
    v = Builder.CreateICmpUGE(left,right,"gecomparetmp");
  }
  else if (opr == "=="){
    v = Builder.CreateICmpEQ(left,right,"equalcomparetmp");
  }
  else if (opr == "!="){
    v = Builder.CreateICmpNE(left,right,"notequalcomparetmp");
  }
  return v;
}

Value* enclBool::codegen(){
  return bool1->codegen();
}

Value* exprBool::codegen(){
  return expr->codegen();
}

Value* enclCond::codegen(){
  return cond->codegen();
}

Value* binCond::codegen(){
  Value* left = lhs->codegen();
  Value* right = rhs->codegen();
  if(left == 0){
    cout<<"Error in left operand of " + opr;
  }
  else if(right == 0){
    cout<<"Error in right operand of " + opr;
  }
  Value* v;
  if (opr == "&&"){
    v = Builder.CreateAnd(left, right, "andtmp");
  }
  if(opr=="||"){
    v = Builder.CreateOr(left,right,"ortmp");
  }
  return v;
}

Value* boolCond::codegen(){
  cout<<"here";
  return bool1->codegen();
}

Value* For_l::codegen(){
   Value* start = expr1->codegen();
   if(expr1->getEtype()=="vars"){
     start=Builder.CreateLoad(start);
   }
   Value* increment = ConstantInt::get(getGlobalContext(), APInt(32,1));
   if(expr3!=NULL){
   increment = expr3->codegen();
   if(expr3->getEtype()=="vars"){
     increment=Builder.CreateLoad(increment);
    }
  }
   Value* va = TheModule->getGlobalVariable(id_var);
   Builder.CreateStore(start,va);
   BasicBlock *preheaderBB = Builder.GetInsertBlock();
   BasicBlock* loop_body = BasicBlock::Create(getGlobalContext(), "loop", mainFunc);
   BasicBlock *afterBB = BasicBlock::Create(getGlobalContext(), "afterloop", mainFunc);
   Value* cond = expr2->codegen();
   if(expr2->getEtype()=="vars"){
     cond=Builder.CreateLoad(cond);
   }
   cond = Builder.CreateICmpULT(start, cond, "loopcondition");
   Builder.CreateCondBr(cond, loop_body, afterBB);
   Builder.SetInsertPoint(loop_body);
   PHINode *Variable = Builder.CreatePHI(Type::getInt32Ty(llvm::getGlobalContext()), 2, id_var);
   Variable->addIncoming(start, preheaderBB);
   cond = expr2->codegen();
   if(expr2->getEtype()=="vars"){
     cond=Builder.CreateLoad(cond);
   }
   Value* forv =  st_list->codegen();
   BasicBlock *loopEndBlock = Builder.GetInsertBlock();
   Value* x = TheModule->getNamedGlobal(id_var);
   x = Builder.CreateLoad(x);
   Value* nextval =  Builder.CreateAdd(x,increment,"add");
   Value* y = TheModule->getNamedGlobal(id_var);
  //  y = Builder.CreateLoad(y);
   Value* z = Builder.CreateStore(nextval,y);
   cond = Builder.CreateICmpULT(nextval, cond, "loopcondition");
   Builder.CreateCondBr(cond, loop_body, afterBB);
   Builder.SetInsertPoint(afterBB);
   Variable->addIncoming(nextval, loopEndBlock);
   llvm::Value *V = ConstantInt::get(getGlobalContext(), APInt(32,1));
   return V;
}

Value* While_l::codegen(){
  Value *v = ConstantInt::get(getGlobalContext(), APInt(32,0));
  Value* c = cond->codegen();

  BasicBlock *whilebl = BasicBlock::Create(getGlobalContext(),"while",mainFunc);
  BasicBlock *nextblock = BasicBlock::Create(getGlobalContext(),"nextblock",mainFunc);

  Builder.CreateCondBr(c,whilebl,nextblock);
  Builder.SetInsertPoint(whilebl);

  Value* whilev = st_list->codegen();
  c = cond->codegen();
  Builder.CreateCondBr(c,whilebl,nextblock);
  Builder.SetInsertPoint(nextblock);
  return v;
}

Value* Ifelse::codegen(){
  Value *condition = cond->codegen();
  cout<<"after condition\n";
  if(condition == 0){
    cout<<"Invalid Expression in the IF";
  }

  BasicBlock *ifBlock = BasicBlock::Create(getGlobalContext(), "if", mainFunc);
  BasicBlock *elseBlock = BasicBlock::Create(getGlobalContext(), "else", mainFunc);
  BasicBlock *nextBlock = BasicBlock::Create(getGlobalContext(), "ifcont", mainFunc);
  Builder.CreateCondBr(condition, ifBlock, elseBlock);
  Builder.SetInsertPoint(ifBlock);

  Value* ifval  = if_st->codegen();
  Builder.CreateBr(nextBlock);
  ifBlock = Builder.GetInsertBlock();

  Builder.SetInsertPoint(elseBlock);
  Value* elseval;
  if(else_st != NULL)
  elseval = else_st->codegen();
  Builder.CreateBr(nextBlock);
  elseBlock = Builder.GetInsertBlock();
  Builder.SetInsertPoint(nextBlock);
  cout<<"after condition22\n";

  Value *V = ConstantInt::get(getGlobalContext(), APInt(32,0));
  return V;
}

Value* recPrint::codegen(){
  Value* v;
  string s="";
  vector<Value*>args;
  vector<Type *>type;
  for(int i=0;i<parts.size();i++){
    cout<<"print paar\n";
    if(parts[i]->Ptype()=="sen"){
      cout<<parts[i]->Ptype();
      s=s+parts[i]->getString();
    }
    else {
      s=s+"%d";
    }
  }
  cout<<s<<endl;
  Value* x = Builder.CreateGlobalStringPtr(s);
  args.push_back(x);
  type.push_back(x->getType());
  for(int i=0;i<parts.size();i++){
    if(parts[i]->Ptype()=="var"){
      cout<<"array booth\n";
      v = parts[i]->codegen();
      // v = Builder.CreateLoad(v);
      args.push_back(v);
      llvm::Type *ty;
      ty = Type::getInt32Ty(Context);
      type.push_back(v->getType());
    }
  }
  llvm::ArrayRef<Type*> typeargs(type);
  llvm::ArrayRef<Value*> refargs(args);
  llvm::FunctionType *FType = FunctionType::get(Type::getInt32Ty(Context), typeargs, false);
  Constant* printfunc = TheModule->getOrInsertFunction("printf", FType);
  return Builder.CreateCall(printfunc,refargs);
}

Value* SenPrint::codegen(){
}

Value* VarPrint::codegen(){
  Value* v = TheModule->getNamedGlobal(var->getVar());
  if(var->is_array()==0){
    v = Builder.CreateLoad(v);
    return v;
  }
  else{
      Value* pos = var->getExpr()->codegen();
      if(var->getExpr()->getEtype()=="vars"){
        pos = Builder.CreateLoad(pos);
      }
      vector<Value*> arrpos;
      arrpos.push_back(Builder.getInt32(0));
      arrpos.push_back(pos);
      v = Builder.CreateGEP(v,arrpos,"Pos");
      v = Builder.CreateLoad(v);
      return v;
  }
}

Value* NumPrint::codegen(){

}

Value* Label::codegen(){

}

Value* Goto::codegen(){

}

void Prog::generateCode(){
  cout << "Generating LLVM IR Code\n";
  TheModule->dump();
}
