#include "proj5.h"
#include <cstring>
#include <iostream>
using namespace std;

MyString::MyString(char const* strIn){
  str = new char[strlen(strIn) + 1];
  strcpy(str,strIn);
}

MyString::~MyString(){
  delete [] str; // deletes MyString object from memory
}

void MyString::MyStrDisplay(){
  cout << str << endl;
}

int MyString::MyStrlen(){
  char comp;
  int i;

  for(i = 0; comp != '\0'; i++){
    comp = str[i];
  }

  return i;
}

void MyString::MyStrcpy(char const* strIn){
  int i;
  for(i = 0; i< str->MyStrlen(); i++){
    str[i] = strIn[i];
  }
  str[i] = '\0';
}

int MyString::MyStrcmp(char const* strIn){
  // if str comes before strIn alphabetically
  if(str[0] < strIn[0]){
    return -1;
  }

  //if both start with same character
  else if(str[0] = strIn[0]){
    return 0;
  }

  //if strIn comes before str alphabetically
  else if(str[0] > strIn[0]){
    return 1;
  }
}

int MyString::Find(char const* strIn){
  int i;

  for(i = 0; i< str.MyStrlen(); i++){
    if(str[i] == strIn[0]){
      for(int j = 0; j < strIn.MyStrlen(); j++){
        if(str[i+j] != str[j]){
          return -1;
        }
      }
    }
  }
  return i; // returns index of substring
}
