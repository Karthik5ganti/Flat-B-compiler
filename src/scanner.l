%{
#include "class-defs.h"
#include "parser.tab.h"
#define YY_DECL extern "C" int yylex()
	extern union Node yylval;
	using namespace std;
	int line_num = 0;
%}

%%
"declblock"		return declblock;
"codeblock"		return codeblock;
"int" {yylval.value=strdup(yytext);return INT;};
"for" return FOR;
"if" return IF;
"else" return ELSE;
"println" return COUT;
"goto" return GOTO;
"while" return WHILE;
"print" return COUT;
"string" {yylval.value=strdup(yytext);return STRING;};
[0-9][0-9]*	{
			printf("Token type: Number, Lexeme/Token Value: %s\n", yytext);
			yylval.number = atoi(yytext);
			return NUMBER;
                };

[a-zA-Z][a-zA-Z0-9]* {
			printf("Token type: Identifier, Lexeme/Token Value: %s\n", yytext);
			yylval.value = strdup(yytext);
			return IDENTIFIER;
		     };
"+=" { yylval.value = strdup(yytext);return ADDEQ; }
"-=" { yylval.value = strdup(yytext);return SUBEQ; }
","   return ',';
"""   return '"';
":"   return ':';
"["   return '[';
"]"   return ']';
";"   return ';' ;
"{"		return '{' ;
"}"		return '}' ;
"="   return '=' ;
"!"   return '!' ;
"<"   return '<' ;
">"   return '>' ;
"("   return '(' ;
")"   return ')' ;
"."   return '.';
"+"   return '+';
"-"   return '-';
"*"   return '*';
"/"   return '/';
"&"   return '&';
"^"   return '^';
"|"   return '|';
"%"   return '%';
">="  return GE;
"<="  return LE;
"&&"  return AA;
">>"  return RS;
"<<"  return LS;
"!="  return NE;
"=="  return EE;
"||"  return OO;
["].*["] {
yylval.value=strdup(yytext);
return SENTENCE;
}

[ \t]		{ /* Do nothing */ }
.		{
		  printf("Unexpected token encountered: %s\n", yytext);
		  return ETOK;
		}

%%
