%{
   #include "class-defs.h"
   #include <bits/stdc++.h>
   extern "C" int yylex();
   extern "C" int yyparse();
   extern "C" FILE *yyin;
   extern "C" int line_num;
   extern union Node yylval;
   extern "C" int errors;
   void yyerror (char const *s);
   class Prog* start = NULL;
%}



%token <value>STRING
%token <number> NUMBER
%token FOR
%token WHILE
%token IF
%token ELSE
%token GOTO
%token declblock
%token codeblock
%token <value> IDENTIFIER
%token ETOK
%token <value> SENTENCE
%token <value> INT
%token COUT
%token '['
%token ']'
%token '}'
%token '{'
%token '('
%token ')'
%left OO
%left AA
%token '&'
%token ':'
%token '|'
%token '"'
%token ','
%left '-' '+' ADDEQ SUBEQ
%left '*' '/' '%'
%left '^'
%left '!' '='
%left '<'
%left '>'
%left NE
%left EE
%left LE
%left GE
%left LS
%left RS
%start Program
/*----------Non terminals---------------*/
%type <prog> Program;
%type <decl_list> Declaration_list;
%type <decl_data> Data_declaration;
%type <var_s> Variables;
%type <var> Variable;


%type <st_list> Statement_list;
%type <forms> Forms;
%type <for_l> For;
%type <while_l> While;
%type <label> Label;
%type <if_l> If;
%type <goto_l> Goto;

%type <assign> Assign;
%type <vars> Vars;
%type <expression> Expr;
%type <cond> Condition;
%type <bool_s> Bool_s;
%type <recPrint> Printparts;
%type <Printpart> Printpart;

/*----------End of Non terminals---------------*/

%%
Program : declblock '{' Declaration_list '}' codeblock '{' Statement_list '}'
          {
            $$=new Prog($3,$7);
            start=$$;
          };
/*----------decl block------------------*/

Declaration_list  : Data_declaration { $$=new Decl_list();$$->push_back($1);}
                  |  Declaration_list Data_declaration {$$->push_back($2);};

Data_declaration : INT Variables ';' {$$=new Decl_data(string($1),$2);} | STRING Variables ';'{$$=new Decl_data(string($1),$2);} ;

Variables :   Variable{$$=new Var_s();$$->push_back($1);} | Variables ',' Variable {$$->push_back($3);};

Variable : IDENTIFIER{$$=new Var(string("Normal"),$1);}
         | IDENTIFIER '[' NUMBER ']' {$$=new Var(string("Array"),string($1),$3);} ;

/*--------------End of declaration block--------------*/



/*Code block*/

Label : IDENTIFIER ':' Forms {$$=new Label($1,$3);};

Statement_list :  Statement_list Forms {$$->push_back($2);}
               | Forms {$$=new St_list();$$->push_back($1);} ;
Forms : While {$$=$1;}
      | For   {$$=$1;}
      | Assign {$$=$1;}
      | If {$$=$1;}
      | Goto {$$=$1;}
      | Label {$$=$1;}
      | COUT Printparts ';'{$$=$2;};


Printparts : Printparts ',' Printpart {$$->push_back($3);}
           | Printpart {$$=new recPrint(); $$->push_back($1);}

Printpart  : Vars {printf("scanner\n");$$=new VarPrint($1);}
           | SENTENCE {printf("scanner111\n");$$=new SenPrint($1);}
           | NUMBER {$$=new NumPrint($1);} ;


Vars : IDENTIFIER {$$=new Vars(string($1),string("Normal"));} ;
     | IDENTIFIER '[' Expr ']'{$$=new Vars(string($1),string("Array"),$3);};

/*-------Expression language-----------*/

Assign : Vars '=' Expr ';' {$$=new Assign($1,string("="),$3);}
       | Vars ADDEQ Expr ';' {$$=new Assign($1,string("+="),$3);}
       | Vars SUBEQ Expr ';' {$$=new Assign($1,string("-="),$3);};
       | Vars '*' '=' Expr ';' {$$=new Assign($1,string("*="),$4);}
       | Vars '/' '=' Expr ';' {$$=new Assign($1,string("/="),$4);}


Expr : Expr '+' Expr {$$=new binExpr($1,string("+"),$3);}
      |Expr '-' Expr {$$=new binExpr($1,string("-"),$3);}
      |Expr '*' Expr {$$=new binExpr($1,string("*"),$3);}
      |Expr '/' Expr {$$=new binExpr($1,string("/"),$3);}
      |Expr RS Expr {$$=new binExpr($1,string(">>"),$3);}
      |Expr '%' Expr {$$=new binExpr($1,string("%"),$3);}
      |Expr LS Expr {$$=new binExpr($1,string("<<"),$3);}
      |Expr '^' Expr {$$=new binExpr($1,string("^"),$3);}
      | Vars {$$ = $1;}
      | NUMBER {$$ = new intLiteral($1);}
      |'-' Expr {$$=new unExpr(string("-"),$2);}
      |'!' Expr {$$=new unExpr(string("!"),$2);}
      | '(' Expr ')'{$$=new EnclExpr($2);};

/*--------End Expression language--------*/



For : FOR IDENTIFIER '=' Expr ',' Expr '{' Statement_list '}'
      {$$=new For_l($2,$4,$6,NULL,$8);}
    | FOR IDENTIFIER '=' Expr ',' Expr ',' Expr '{' Statement_list '}'
      {$$=new For_l($2,$4,$6,$8,$10);}

Condition : Condition AA Condition {$$=new binCond($1,string("&&"),$3);}
          | Condition OO Condition {$$=new binCond($1,string("||"),$3);}
          | Bool_s {$$=new boolCond($1);}
          | '(' Condition ')' {$$=new enclCond($2);};
Bool_s : Bool_s '<' Bool_s {$$=new class binBool($1,string("<"),$3);}
     | Bool_s '>' Bool_s {$$=new class binBool($1,string(">"),$3);}
     | Bool_s GE Bool_s  {$$=new class binBool($1,string(">="),$3);}
     | Bool_s LE Bool_s  {$$=new class binBool($1,string("<="),$3);}
     | Bool_s EE Bool_s  {$$=new class binBool($1,string("=="),$3);}
     | Bool_s NE Bool_s  {$$=new class binBool($1,string("!="),$3);}
     | Expr          {$$=new class exprBool($1);};

While : WHILE Condition '{' Statement_list '}' {$$=new While_l($2,$4);};

If : IF  Condition  '{' Statement_list '}' {$$=new Ifelse($2,$4,NULL);}
   | IF Condition '{' Statement_list '}' ELSE '{' Statement_list '}'{$$=new Ifelse($2,$4,$8);};


Goto : GOTO IDENTIFIER IF Condition ';' {$$=new class Goto($2,$4);}
     | GOTO IDENTIFIER  ';' {$$=new class Goto($2,NULL);};


%%

void yyerror (char const *s)
{
       fprintf (stderr, "%s\n", s);
}

int main(int argc, char *argv[])
{
	if (argc == 1 ) {
		fprintf(stderr, "Correct usage: bcc filename\n");
		exit(1);
	}

	if (argc > 2) {
		fprintf(stderr, "Passing more arguments than necessary.\n");
		fprintf(stderr, "Correct usage: bcc filename\n");
	}

	yyin = fopen(argv[1], "r");

	yyparse();
  if(start){
      start->traverse();
      start->codegen();
      start->generateCode();
  }
}
