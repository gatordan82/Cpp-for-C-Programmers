/**********************************************************************  Filename:  ch3-ex6.c  Chapter:   3      Functions Pointers and Arrays  Compiler:  Borland C++     Version 5.01      Summer 1998  C++ for C Programmers, Edition 3     By Ira Pohl********************************************************************/#include <stdio.h>#define  N    15#define  MAX  3.5int main(){    int     i;    double  x, cube();    printf("\n\nINTEGERS\n");    for (i = 1; i <= N; ++i)       printf("cube(%d) = %d\n", i, cube(i));    printf("\n\nREALS\n");    for (x = 1; x <= MAX; x += 0.3)       printf("cube(%f) = %f\n", x, cube(x));    scanf("%d", &x);}double cube(x)double  x;{   return (x * x * x);}