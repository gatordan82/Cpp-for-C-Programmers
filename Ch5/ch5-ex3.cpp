/**********************************************************************  Filename:  ch5-ex3.cpp  Chapter:   5      Constructors and Destructors  Compiler:  Borland C++     Version 5.01      Summer 1998  C++ for C Programmers, Edition 3     By Ira Pohl********************************************************************/#include <iostream>//using namespace std;//Constructors and destructors invokedclass A {public:   A(int n) : xx(n)     { cout << "A(int " << n << ") called" << endl;}   A(double y) : xx(y + 0.5)     { cout << "A(fl " << y << ") called" << endl; }   ~A()     { cout << "~A() with A::xx = " << xx << endl; }private:   int  xx;};int main(){   cout << "enter main\n";   int    x = 14;   float  y = 17.3;   A      z(11), zz(11.5), zzz(0);   cout << "\nOBJECT ALLOCATION LAYOUT\n";   cout << "\nx is at " << &x;   cout << "\ny is at " << &y;   cout << "\nz is at " << &z;   cout << "\nzz is at " << &zz;   cout << "\nzzz is at " << &zzz;   cout << "\n_____________________________\n";   zzz = A(x);    zzz = A(y);   cout << "exit main" << endl;   int look; cin >> look;}