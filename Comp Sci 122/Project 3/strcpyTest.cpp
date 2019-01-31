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

char* my_strcpy(char*, char*);

int main(){
  const int MAX_SIZE = 100;

  char* userStr1 = NULL;
  char* userStr2 = NULL;
  cout<< "Enter a sentence: ";
  cin.getline(userStr1, MAX_SIZE);

  cout<< "Enter another sentence: ";
  cin.getline(userStr2, MAX_SIZE);

  char* copy = my_strcpy(userStr1, userStr2);
  cout<< "\nCopied sentence: "<<copy<<endl;

  delete userStr1, userStr2;
  return 0;
}

char* my_strcpy(char* str1, char* str2){
  int i;
  for(i = 0; i< strlen(str2); i++){
    str2[i] = str1[i];
  }
  str2[i] = '\0';
  return str2;
}
