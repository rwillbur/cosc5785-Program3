// Shaya Wolf
// Program 3
// cosc5785 - Compilers
// 10/20/2017
// Based on node.hpp in Dr.Buckners
//   example on WyoCourses

#ifndef NODE_HPP
#define NODE_HPP
#include<iostream>
#include<string>
#include<vector>

using std::string;
using std::endl;
using std::ostream;

class Node 
{
  public:
  // Constructor
  
  // Destructor
  
  // Get Functions

  // Set Functions
  
  // Reset
  
  // Get a Child
  
  // Set a Child

  protected:
    int lnum;
    int cnum;

    int ival;
    double dval;
    string sval;

    vector<node*> children;
};



#endif
