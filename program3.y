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

%type<ttype> statement
%type<ttype> elem 
%type<ttype> simpleType type varDec
%type<ttype> exp name newexp expstar brackstar
%type<ttype> relop sumop proop unyop

%token<atts> DOT THIS
%token<atts> LBRACK RBRACK DOUBBRACK
%token<atts> INT IDEN 
%token<atts> NUM NLL READ NEW LPAREN RPAREN

%token<atts> DEQ NEQ LEQ GEQ GT LT 
%token<atts> PLUS MINUS OR
%token<atts> MULT DIVD MOD AND
%token<atts> BANG
%token<atts> SEMI EQ

//%precedence EXP

%left DEQ NEQ LEQ GEQ GT LT RO
%left PLUS MINUS OR SO
%left MULT DIVD MOD AND PO

%precedence UO

%% 

// Bison Grammar

start : %empty {}
      | start elem {forest.push_back($2);}
      ;

elem : statement {}
     | varDec {}
     ;

statement : name EQ exp SEMI {$$ = new statementNode();
                              $$->addChild($1);
                              $$->addChild($3);
                              delete $2;
                              delete $4;}; 
     
varDec : type IDEN SEMI {$$ = new varDecNode($2->value);
                         $$->addChild($1);
                         delete $2;
                         delete $3;};
     
type : simpleType 
         {$$ = new typeNode("simpleType");
          $$->addChild($1);}
     | type DOUBBRACK 
         {$$ = new typeNode("type");
          $$->addChild($1);
          delete $2;}
     ;
     
simpleType : INT  {$$ = new simpleTypeNode($1->token, "");
                   delete $1;} 
           | IDEN {$$ = new simpleTypeNode("id", $1->value);
                   delete $1;}
           ;

exp : name 
        {$$ = new expNode("name");
         $$->addChild($1);}
    | NUM
        {$$ = new numNode($1->value);
         delete $1;}
    | NLL
        {$$ = new nullNode();
         delete $1;}
    | name LPAREN RPAREN
        {$$ = new expNode("name paren");
         $$->addChild($1);
         delete $2;
         delete $3;}
    /*| name LPAREN error
        {$$ = new errorNode("Missing ')' after name declaration", $2->lNum);
         delete $2;
         yyerrok;}
    /*| name error RPAREN
        {$$ = new errorNode("Missing '(' after name declaration", $3->lNum);
         delete $3;
         yyerrok;}*/
    | READ LPAREN RPAREN
        {$$ = new expNode("read");
         delete $1;
         delete $2;
         delete $3;}
    | READ LPAREN error
        {cerr << "Missing ')' after read: line " << $1->lNum << endl;
         $$ = new errorNode("<Expression>");
         delete $1;
         delete $2;
         yyerrok;}
    | READ error RPAREN
        {cerr << "Missing '(' after read: line " << $1->lNum << endl;
         $$ = new errorNode("<Expression>");
         delete $1;
         delete $3;
         yyerrok;}
    | newexp
        {$$ = new expNode("newexp");
         $$->addChild($1);}
    | exp relop exp %prec RO
        {$$ = new expNode("relop");
         $$->addChild($1);
         $$->addChild($2);
         $$->addChild($3);}
    | exp sumop exp %prec SO
        {$$ = new expNode("sumop");
         $$->addChild($1);
         $$->addChild($2);
         $$->addChild($3);}
    | exp proop exp %prec PO
        {$$ = new expNode("proop");
         $$->addChild($1);
         $$->addChild($2);
         $$->addChild($3);}
    | unyop exp %prec UO
        {$$ = new expNode("unyop");
         $$->addChild($1);
         $$->addChild($2);}
    | LPAREN exp RPAREN 
        {$$ = new expNode("paren");
         $$->addChild($2);
         delete $1;
         delete $3;}
    ;  
    
newexp : NEW simpleType LPAREN RPAREN 
           {$$ = new newexpNode("parens");
            $$->addChild($2);
            delete $1;
            delete $3;
            delete $4;}
       | NEW simpleType expstar brackstar
           {$$ = new newexpNode("bracks");
            $$->addChild($2);
            $$->addChild($3);
            $$->addChild($4);
            delete $1;}
       ;
       
expstar : %empty
            {$$ = new expstarNode("empty");}
        | expstar LBRACK exp RBRACK 
            {$$ = new expstarNode("rec");
             $$->addChild($1);
             $$->addChild($3);
             delete $2;
             delete $4;}
        ;
    
brackstar : %empty
              {$$ = new brackstarNode("empty");}
          | brackstar DOUBBRACK
              {$$ = new brackstarNode("rec");
               $$->addChild($1);
               delete $2;}
          ;
          
name : THIS  
         {$$ = new nameNode("this", "");
          delete $1;}
     | IDEN 
         {$$ = new nameNode("id", $1->value);
          delete $1;}
     | name DOT IDEN 
         {$$ = new nameNode("dotid", $3->value);
          $$->addChild($1);
          delete $2;
          delete $3;} 
     | name LBRACK exp RBRACK 
         {$$ = new nameNode("exp", "");
          $$->addChild($1);
          $$->addChild($3);
          delete $2;
          delete $4;}
     ;

relop : DEQ   {$$ = new relopNode("==");
               delete $1;}
      | NEQ   {$$ = new relopNode("!=");
               delete $1;}
      | LEQ   {$$ = new relopNode("<=");
               delete $1;}
      | GEQ   {$$ = new relopNode(">=");
               delete $1;}
      | GT    {$$ = new relopNode(">");
               delete $1;}
      | LT    {$$ = new relopNode("<");
               delete $1;}
      ;
      
sumop : PLUS  {$$ = new sumopNode("+");
               delete $1;}
      | MINUS {$$ = new sumopNode("-");
               delete $1;}
      | OR    {$$ = new sumopNode("||");
               delete $1;}
      ;
      
proop : MULT  {$$ = new proopNode("*");
               delete $1;}
      | DIVD  {$$ = new proopNode("/");
               delete $1;}
      | MOD   {$$ = new proopNode("%");
               delete $1;}
      | AND   {$$ = new proopNode("&&");
               delete $1;}
      ;
        
unyop : PLUS  {$$ = new unyopNode("+");
               delete $1;}
      | MINUS {$$ = new unyopNode("-");
               delete $1;}
      | BANG  {$$ = new unyopNode("!");
               delete $1;}
      ;
      
%%
