/**********************************************************************  Filename:  array_mx.cpp  Chapter:   3      Functions Pointers and Arrays  Compiler:  Borland C++     Version 5.01      Summer 1998  C++ for C Programmers, Edition 3     By Ira Pohl********************************************************************/#include <iostream>//using namespace std;//C++ but not Cint max(int c[], int size){   cout << "array size is " << size << endl;   int  comp = c[0];                   //declare comp   for (int i = 1; i < size; ++i)      //declare i      if (c[i] > comp)         comp = c[i];   return comp;}int main (){   int  ar1[] = {1, 2, 3};   int  ar2[] = {3, 4, 5, 6};   cout << "Max element for array 1 is " << max(ar1, 3) << endl;   cout << "Max element for array 2 is " << max(ar2, 4) << endl;   int look; cin >> look;}