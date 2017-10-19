// Shaya Wolf
// COSC5785 - Compilers   
// Program 3
// program3.cpp
// 10/20/2017

#include<FlexLexer.h>

#include<stdio.h>
#include<iostream>
#include<fstream>
#include<string.h>
#include<iomanip>

#include "attributes.h"
#include "node.hpp"
#include "program3.tab.h"

using namespace std;

attributes *atts;
yyFlexLexer myScanner;
vector<Node*> forest;

int main() { 
/*  int rtn=999;
  
  cout << setw(5) << "Line" 
       << setw(5) << "Coln" 
       << setw(25) << "Token"
       << setw(25) << "Value\n"; 
*/
  
  atts = new attributes{0,0,0,""};
    
/*
  while (((rtn = myScanner.yylex()) != 0)) {
    if(rtn == MAXERR) {
      cout << "\nMAX ERRORS REACHED";
      break; 
    } 
    if(rtn != WSPC && rtn != COMM) {
      cout << setw(5) << atts->lNum 
           << setw(5) << atts->cNum
           << setw(25) << atts->token
           << setw(25) << atts->value 
           << "\n";
    } 
  }
  
  cout << "\n";
*/
  yyparse();
  
  // I'm going to print a stupid tree
  for(unsigned int i = 0; i < forest.size(); i++) {
    forest[i]->printNode();
  }

  return 0 ;
}
