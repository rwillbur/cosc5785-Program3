/* 
 * Shaya Wolf
 * cosc5785 - Compilers
 * Program3
 * program3.y
 * 10/20/2017
 * Based on Dr.Buckner's Example
 */

%{

#include <iostream>
#include <FlexLexer.h>
#include "node.hpp"
#include "attributes.h"

using namespace std;
//using std::cerr;
//using std::cout;
//using std::endl;

// externs defined in program3.cpp 
extern vector<Node*> forest;
extern yyFlexLexer myScanner;

// Make C++ scanner play nice with C parser
#define yylex() myScanner.yylex()

// Parser function prototype
void yyerror(const char *);

%}

%union {
  Node *ttype;
  struct attributes* atts;
}
// Bison Declarations

%type<ttype> elem 
%type<ttype> exp
%type<ttype> relop
%token<atts> NUM
%token DEQ NEQ LEQ GEQ GT LT 
%left DEQ NEQ LEQ GEQ GT LT RE

%% 

// Bison Grammar

elem : %empty {}
     | elem exp {forest.push_back($2);}
     ;

exp : NUM
        {$$ = new numNode($1->value);
        delete $1;}
    | exp relop exp %prec RE 
        {$$ = new expNode("relop");
         $$->addChild($1);
         $$->addChild($2);
         $$->addChild($3);}
    ;
      

relop : DEQ {$$ = new relopNode("==");}
      | NEQ {$$ = new relopNode("!=");}
      | LEQ {$$ = new relopNode("<=");}
      | GEQ {$$ = new relopNode(">=");}
      | GT  {$$ = new relopNode(">");}
      | LT  {$$ = new relopNode("<");}
      ;
        
%%
