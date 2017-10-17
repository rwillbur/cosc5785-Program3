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

using namespace std;

attributes *atts;

int main() {
  yyFlexLexer myScanner; 
  int rtn=999;
  
  cout << setw(5) << "Line" 
       << setw(5) << "Coln" 
       << setw(25) << "Token"
       << setw(25) << "Value\n"; 
  
  atts = new attributes{0,0,0,""};
    
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

  return 0 ;
}
