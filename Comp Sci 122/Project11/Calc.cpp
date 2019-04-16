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

  Parse(myArgv, myArgc);
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
  postFix = "";
}

void Calc::Evaluate()
{}

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
  CreateHash(hashTble, inFix, myArgc, myArgv);
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
    for(char ch: symbol)
    {
      if(inFix[i] != ch)
      {
        if(inFix[i] >= 65 && inFix[i] <= 90)
          ret = true;
        else
        {
          cout<<inFix[i]<<" is not a valid character."<<endl;
          return false;
        }
      }
    }
  }

  return ret;
}

bool Calc::CheckParens()
{
  for(int i = 0; inFix[i] != '\0'; i++)
  {
    if(inFix[i] == '(')
      stk->Push(inFix[i]);
    if(inFix[i] == ')')
      stk->Pop();
  }
  return stk->IsEmpty();
}

void Calc::CreateHash(int* hashTable, char* exp, int numArgs, char* cmdLine[])
{
  hashTble = new int[26];
  int cmdLineArg = 2;
  for(int i = 0; inFix[i] != '\0'; i++)
  {
    if(inFix[i] >= 65 && inFix[i] <= 90)
    { // while the character is a capital letter A-Z
      hashTable[inFix[i] % 65] = atoi(cmdLine[cmdLineArg]);
      cmdLineArg++;
    }
  }
}
