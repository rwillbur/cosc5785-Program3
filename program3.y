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

using namespace std;
//using std::cerr;
//using std::cout;
//using std::endl;

// externs defined in program3.cpp 
extern Node *tree;
extern yyFlexLexer myScanner;

// Make C++ scanner play nice with C parser
#define yylex() myScanner.yylex()

// Parser function prototype
void yyerror(const char *);

%}

%union {
  Node *ttype;
}
// Bison Declarations

%token DEQ NEQ LEQ GEQ GT LT


%% 

// Bison Grammar
relop : DEQ //{cout << "DEQ" << endl;}
      | NEQ //{cout << "NEQ" << endl;}
      | LEQ //{cout << "LEQ" << endl;}
      | GEQ //{cout << "GEQ" << endl;}
      | GT  //{cout << "GT" << endl;}
      | LT  //{cout << "LT" << endl;}
      ;
        
%%
