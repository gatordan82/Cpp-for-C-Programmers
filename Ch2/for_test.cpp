/**********************************************************************  Filename:  for_test.cpp  Chapter:   2      Native Types and Statements  Compiler:  Borland C++     Version 5.01      Summer 1998  C++ for C Programmers, Edition 3     By Ira Pohl********************************************************************/#include <iostream>#include <string>using namespace std;#define MAX 5int main(){   int i = 0, sum = 0; double x;   char c;   sum = 0;   for (i = 1; i <= 10; ++i)      sum += i;   cout << "\nSum for i = " << i << " is " << sum;   for (i = 0; i < 10; ++i) {      cout << "\nEnter a positive number for square root: ";      cin >> x;      if (x < 0.0) {         cout << "All done" << endl;         break;        //exit loop if value is negative      }      cout << sqrt(x) << endl;   }   cout << "\n Number of square roots " << i << endl;   for (i = 0; i < MAX; ++i) {      cin.get(c);      if (isdigit(c))         continue;      cout << "\nNot a digit: " << c;   }   //continue jumps to here   int look; cin >> look;}