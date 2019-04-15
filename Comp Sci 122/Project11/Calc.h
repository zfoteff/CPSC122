/*
Class: CPSC 122-01
Paul De Palma
GU Username: depalma
Submitted By: Paul De Palma
GU Username: depalma
File Name: proj10.h
To Execute: ./calc "(A+B) 7 12
*/

#ifndef CALC_H
#define CALC_H

#include "stack2.h"

class Calc
{
  public:
  /*
  pre: none
  post:
       Part 1
       1. Command line arguments have been copied to memory pointed to by
          member variables
       2. inFix points to newly allocated memory holding infix expression
       3. inFix expression has been checked for legal tokens
       4. inFix epression has been checked for balanced parentheses
       Part 2
       1. Hash table has been created
  */
  Calc(int argcIn, char* argvIn[]);

  /*
  pre: instance of calculator exists.
  post: postfix expression displayed
 */
  void DisplayInFix(); // DONE

  /*
  pre: instance of calculator exists and infix expression has been transformed
       to postfix
  post: postfix exression displayed
 */
  void DisplayPostFix(); //DONE

  /*
  pre: instance of calculator exists.
  post: infix expression transformed to postfix and stored in memory pointed to
        by the member variable postfix
 */
  void InFixToPostFix();

  /*
  pre: instance of calculator exists. valid postfix expr. has been created
  post: post fix expression has been evaluated and displayed on the screen
 */
  void Evaluate();

 private:
  /*
  optional function
  pre:  invoked from constructor
  post: processes raw input
  */
  void Parse(char* cmdLineInp[], int num_cmd_line_args);

  /*
  pre:  instance of calculator exists
  post: returns true if all characters in the infix expression are legal,
        false otherwise  Legal characters are ')', '(', '+','-','*','/',
        'A' ... 'Z'
  */
  bool CheckTokens(); //DONE

  /*
   pre:  instance of calculator exists and all input tokens are legal
   post: Using the technique discussed in class, returns true if parentheses
         are balanced, false otherwise
  */
  bool CheckParens(); //DONE

  /*
  pre: instance of calculator exists, the parentheses are balenced, and all
       tokens are legal
  post: a hash table is constructed using the variables in exp
  */
  void CreateHash(int* hashTable, char* exp, int numArgs, char* cmdLine[]); // DONE

  Stack* stk;
  char*  inFix;    //null-terminated string that holds infix expression
  char*  postFix;  //null-terminated string that holds the post-fix
  int*   hashTble; //pointer to hash table holding expression values
  int    myArgc;   //number of command line arguments
  char** myArgv;  //command line arguments
};
#endif
