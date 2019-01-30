/*
Class: CPSC 122-01
Team Member 1: Zac Foteff
Team Member 2: None
Submitted by: Zac Foteff
GU Username: zfoteff
File Name: strcpyTest.cpp
Programs take user inputted character lists
and calls function my_strcpy

To Build: g++ strcmpTest.cpp -o strcpyTest
To Execute: ./strcpyTest
*/

#include <iostream>
#include <cstring>
using namespace std;

void my_strcpy(char*, char*);

int main(){
  char* userStr1;
  char* userStr2;
  cout<< "Enter a sentence: ";
  cin>> userStr1;

  cout<< "Enter another sentence: ";
  cin>> userStr2;

  my_strcpy(userStr1, userStr2);

  cout<<"Str 1:  "<<userStr1<<endl;
  cout<<"Str 2:  "<<userStr2<<endl;

  delete userStr1, userStr2;
  return 0;
}

void my_strcpy(char* str1, char* str2){
  int i;
  for(i = 0; i< strlen(str1); i++){
    str2[i] = str1[i];
  }
  str2[i] = EOF;
}
