/*
Class: CPSC 122-01
Zac Foteff
GU Username: zfoteff
Submitted By: Zac Foteff
File Name: Calc.cpp
Function file for class Calc
To Build: g++ CalcTst.cpp Calc.cpp
To Execute: ./a.out
*/

#include "Calc.h"
#include <cstring>
#include <iostream>
using namespace std;

Calc::Calc()
{
  Parse(char* argv[], int argc);
}

void Calc::DisplayInFix()
{}

void Calc::Parse(char* cmdLineInp[], int num_cmd_line_args)
{
  //infix expression construction
  size = strlen(cmdLineInp[1]);
  inFix = new char[size];
  int i;
  for(i = 0; i< size; i++){
    inFix[i] = cmdLineInp[1][i];
  }
  inFix[i] = '\0';

  //balenced parentheses check
  if(!CheckParens())
    cout<<"Please make sure your parentheses are balenced"<<endl;
    exit(0);
}

bool Calc::CheckTokens()
{

}

bool Calc::CheckParens()
{
  /*for(char ch : inFix){
    if(ch == '(')
      stk->Push(ch);
    if(ch == ')')
      stk->Pop();
  }

  return stk->IsEmpty();
  */
}
