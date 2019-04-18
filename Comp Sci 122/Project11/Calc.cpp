/*
Class: CPSC 122-01
Zac Foteff
GU Username: zfoteff
Submitted By: Zac Foteff
File Name: Calc.cpp
Function file for class Calc
To Build: g++ CalcTst.cpp Calc.cpp
To Execute: ./calc "(A+B) 7 12
*/

#include <iostream>
#include <cstring>
#include "Calc.h"
using namespace std;


Calc::Calc(int argCIn, char* argvIn[])
{
  //myArgc now holds the number of command line arguments
  myArgc = argCIn;

  //declare storage for myArgv, a point to an array of pointers to char
  myArgv = new char*[myArgc];

  //copy command line arguments into member variable
  for (int i = 0; i < myArgc; i++)
  {
    //declare storage for argument i
    myArgv[i] = new char[strlen(argvIn[i]) + 1];
    //copy command line argument i to member variable
    strcpy(myArgv[i],argvIn[i]);
  }

  Parse(myArgv, myArgc); // set variables
  InFixToPostFix(); // change infix expression to postfix expression
  DisplayInFix(); //TEST
  DisplayPostFix(); // TEST
  Evaluate(); // evaluate and return result
}

void Calc::DisplayInFix()
{
  for(int i = 0; inFix[i] != '\0'; i++)
    cout<<inFix[i];
  cout<<endl;
}

void Calc::DisplayPostFix()
{
  for(int i = 0; postFix[i] != '\0'; i++)
    cout<<postFix[i];
  cout<<endl;
}

void Calc::InFixToPostFix()
{
  postFix = new char[strlen(inFix)+1];
  int postFixCount = 0;
  int i;
  for(i = 0; inFix[i] != '\0'; i++)
  {

    const char ch = inFix[i]; //operands
    switch(ch)
    {
      case '(': case '+': case '-': case '/': case '*': //operators
          stk->Push(ch);
          break;


      case ')':
          while(!stk->IsEmpty() && stk->Peek() != '(')
          {
            postFix[postFixCount] = stk->Peek();
            stk->Pop();
            postFixCount++;
          }
          break;


      default:
          postFix[postFixCount] = inFix[i];
          postFixCount++;
          break;
    }
  }

  postFix[i] = '\0';
}

void Calc::Evaluate()
{
  stk = new Stack;
  int final;
  for(int i = 0; postFix[i] != '\0'; i++)
  {
    int result = 0;
    if(postFix[i] >= 65 && postFix[i] <= 90) //is operand
      stk->Push(hashTble[postFix[i] % 65]);

    else // is operator
    {
      int op1 = stk->Peek();
      stk->Pop();
      int op2 = stk->Peek();
      stk->Pop();
      char optr = postFix[i];

      if(optr = '+')
        result = (op1)+(op2);
      else if(optr = '-')
        result = (op1)-(op2);
      else if(optr = '/')
        result = (op1)/(op2);
      else if(optr = '*')
        result = (op1)*(op2);

      stk->Push(result);
      cout<<result<<endl;
    }
  }
  final = stk->Peek();
  stk->Pop();
  cout<<"The expression evaluates to "<<final<<endl;
}

void Calc::Parse(char* cmdLineInp[], int num_cmd_line_args)
{

  //inFix expression construction
  int size = strlen(myArgv[1]);
  inFix = new char[size+1];
  int i;

  for(i = 0; i< size; i++)
    inFix[i] = myArgv[1][i];
  inFix[i] = '\0';

  //balenced parentheses check
  if(!CheckParens())
  {
    cout<<"Please make sure your parentheses are balenced"<<endl;
    exit(0);
  }

  //legal token check
  if(!CheckTokens())
    exit(0);

  //hash table constructions
  CreateHash();
}

bool Calc::CheckTokens()
{
  bool ret = true;
  char symbol[6];
  symbol[0] = '(';
  symbol[1] = ')';
  symbol[2] = '+';
  symbol[3] = '-';
  symbol[4] = '/';
  symbol[5] = '*';

  for(int i = 0; i < strlen(inFix); i++)
  {
    for(int j = 0; j < 6; j++)
    {
      if(inFix[i] != symbol[j])
        ret = false;

      else if(inFix[i] == symbol[j])
      {
        ret = true;
        break;
      }
    }
  }

  return ret;
}

bool Calc::CheckParens()
{
  stk = new Stack;
  for(int i = 0; inFix[i] != '\0'; i++)
  {
    if(inFix[i] == '(')
      stk->Push(inFix[i]);
    else
    {
      if(inFix[i] == ')')
      {
        if(!stk->IsEmpty()) // while stk isnt empty
          stk->Pop();
        else //if stack is empty return false immidiately
          return false;
      }
    }
  }
  return stk->IsEmpty();
}

void Calc::CreateHash()
{
  hashTble = new int[26];
  int cmdLineArg = 2;

  for(int i = 0; inFix[i] != '\0'; i++)
  {
    if(inFix[i] >= 65 && inFix[i] <= 90)
    {
      hashTble[inFix[i] % 65] = atoi(myArgv[cmdLineArg]);
      if(cmdLineArg < myArgc)
        cmdLineArg++;
    }
  }
}
