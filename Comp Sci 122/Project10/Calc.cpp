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
  if(!CheckTokens(inFix))
    exit(0);

  //hash table construction
  CreateHash(symbolTble, inFix, num_cmd_line_args, cmdLineInp);
}

bool Calc::CheckTokens(char* exp)
{
  bool ret = true;
  char symbol[6];
  symbol[0] = '(';
  symbol[1] = ')';
  symbol[2] = '+';
  symbol[3] = '-';
  symbol[4] = '/';
  symbol[5] = '*';

  for(int i = 0; i < size; i++)
  {
    for(char ch: symbol)
    {
      if(exp[i] != ch)
      {
        if(exp[i] >= 65 && exp[i] <= 90)
          ret = true;
        else{
          cout<<exp[i]<<" is not a valid character."<<endl;
          return false;
        }
      }
    }
  }

  return ret;
}

bool Calc::CheckParens()
{
  for(int i = 0; inFix[i] != '\0'; i++){
    if(inFix[i] == '(')
      stk->Push(inFix[i]);
    if(inFix[i] == ')')
      stk->Pop();
  }
  return stk->IsEmpty();
}

void Calc::CreateHash(int* hashTable, char* exp, int numArgs, char* cmdLine[])
{
  symbolTble = new int[26];
  int cmdLineArg = 2;
  for(int i = 0; exp[i] != '\0'; i++){
    if(exp[i] >= 65 && exp[i] <= 90){ // while the character is a capital letter A-Z
      hashTable[exp[i] % 65] = atoi(cmdLine[cmdLineArg]);
      cmdLineArg++;
    }
  }
}
