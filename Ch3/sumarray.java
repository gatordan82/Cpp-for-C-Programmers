// **********************************************************************////  Filename:  SumArray.java//  Compiler:  Borland C++     Version 5.01       Spring 1998//  C++ for C Programmers edition 3    By Ira Pohl//// ********************************************************************/class ArraySum {   public static void main(String[] args)   {      int[] data = {1, 2, 3, 4, 5, 6, 7};      int sum = 0;      double average;      for (int i = 0; i < 7; ++i) {         sum = sum + data[i];         System.out.print(data[i] + ", ");      }      average = sum / 7.0;      System.out.println("\n\n sum = " + sum         + " average = " + average);   }}