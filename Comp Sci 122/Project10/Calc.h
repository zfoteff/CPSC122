/*
Class: CPSC 122-01
Zac Foteff
GU Username: zfoteff
Submitted By: Zac Foteff
File Name: Calc.h
Header file for class Calc
To Build: g++ CalcTst.cpp Calc.cpp
To Execute: ./a.out
*/

#ifndef CALC_H
#define CALC_H

#include "stack2.h"

class Calc
{
  public:
  /*
  pre: none
  post: instance of calculator created. valid in-fix expression stored in
        inFix. symbolTlble created
        symbolTble created
  */
  Calc(int numArgs, char* cmdLine[]);

  /*
  pre: instance of calculator exists.
  post: displays the infix expression
 */
  void DisplayInFix();


 private:
  /*
  pre:  invoked from constructor
  post: 1) command line input has been a) checked for balanced parentheses
        b) checked for valid input. 2) symbolTble has been constructed
	3) inFix holds a valid in fix expression
  */
  void Parse(char* cmdLineInp[], int num_cmd_line_args);

  /*
  pre:  instance of calculator exists
  post: return true if all characters in the infix expression are legal,
        false otherwise  Legal characters are ')', '(', '+','-','*','/',
        'A' ... 'Z'
  */
  bool CheckTokens(char* exp);

  /*
   pre:  instance of calculator exists and all input tokens are legal
   post: Using the technique discussed in class, returns true if parentheses
         are balanced, false otherwise
  */
  bool CheckParens();

  /*
  pre: instance of calculator exists, the parentheses are balenced, and all
       tokens are legal
  post: a hash table is constructed using the variables in exp
  */
  void CreateHash(int* hashTable, char* exp);

  Stack* stk;
  char* inFix;    //null-terminated string that holds infix expression
  char* postFix;  //null-terminated string that holds the post-fix
  int* symbolTble; //pointer to symbolTable holding expression values
  int size; //integer value for the size of the expression
};
#endif
