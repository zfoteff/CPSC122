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

Calc::Calc(int numArgs, char* cmdLine[])
{
  stk = NULL;
  Parse(cmdLine, numArgs);
}

void Calc::DisplayInFix()
{
  for(int i = 0; inFix[i] != '\0'; i++)
    cout<<inFix[i];
}

void Calc::Parse(char* cmdLineInp[], int num_cmd_line_args)
{
  //infix expression construction
  size = strlen(cmdLineInp[1]);
  inFix = new char[size];
  int i;
  for(i = 0; i< size; i++)
    inFix[i] = cmdLineInp[1][i];

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

  //hash table construction
  CreateHash(cmdLineInp[]);
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

void Calc::CreateHash(char* myArgv)
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
