/**********************************************************************  Filename:  stl_stak.cpp  Chapter:   7      Templates Generic Programming and STL  Compiler:  Borland C++     Version 5.01      Summer 1998  C++ for C Programmers, Edition 3     By Ira Pohl********************************************************************/#include <iostream>#include <stack>#include <vector>#include <string>using namespace std;//Adapt a stack from a vectorint main(){   stack<string, vector<string> > str_stack;   string quote[3] =    { "The wheel that squeaks the loudest\n",      "Is the one that gets the grease\n",      "Josh Billings\n" };   for (int i =0; i < 3; ++i)      str_stack.push(quote[i]);   while (!str_stack.empty()) {      cout << str_stack.top();      str_stack.pop();   }   int look; cin >> look;}