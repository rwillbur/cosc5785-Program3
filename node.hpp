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
using std::vector;

// Base Class
class Node 
{
  public:
  // Constructor
  Node() {
    reset();
    ival = 0;
    dval = 0;
  }

  // Destructor
  virtual ~Node() {
    while(!children.empty()) {
      children.pop_back();
    }
  }

  // Get Functions
  int    getint() const { return ival; }

  double getdbl() const { return dval; }

  string getstr() const { return sval; }

  // Set Functions
  void setval(int i)          { ival = i; }

  void setval(double d)       { dval = d; }

  void setval(const string s) { sval = s; }

  void setval(const char * c) { sval = c; }

  // Reset
  void reset() {
    lnum = 1;
    cnum = 1;
    sval.clear();
  } 
  
  // Get a Child
  Node* getChild(unsigned index) {
    return children[index];
  }

  // Set a Child
  void setChild(Node *c, unsigned index){
    children[index] = c;
    return;
  }

  // Print Node
  virtual void printNode(ostream * out = 0) {
    *out << sval;
    for(unsigned i = 0; i < children.size(); i++) {
      children[i]->printNode(out);
    }
    return;
  }

  protected:
    int lnum;
    int cnum;

    int ival;
    double dval;
    string sval;

    vector<Node*> children;
};

// Node Types
class nodeClass : public Node 
{
  public:
    nodeClass() : Node () {} 

    virtual void printNode(ostream * out = 0) {
      // Some stuff
    }
}; 


#endif
