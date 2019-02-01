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
#include <cstdio>
using namespace std;

char* my_strcpy(char*, char*);

int main(){
  const int MAX_SIZE = 100;
  char userStr1[25];
  char userStr2[25];

  cout<< "Enter a sentence: ";
  cin.getline(userStr1, MAX_SIZE); // sets userStr1 = user input
  cout<<"zac";
  cout<< "Enter another sentence: ";
  cin.getline(userStr2, MAX_SIZE); // sets userStr2 = user input

  //input validation to make sure that str1 > str2 by at least 1
  while(strlen(userStr1) < strlen(userStr2)+1){
    cout<< "Please let sentence one be at least one character longer than character 2"<<endl;

    cout<< "Enter sentence 1: ";
    cin.getline(userStr1, MAX_SIZE);
    cout<< "Enter sentence 2: ";
    cin.getline(userStr2, MAX_SIZE);
  }


  char* copy = my_strcpy(userStr1, userStr2);
  cout<< "\nCopied sentence: "<<copy<<endl;

  //delete userStr1, userStr2;
  return 0;
}

/*
pre: user passes 2 c-strings
    str1's length is greater than str2's length by at least once
post: str2 is copied to str1 and returns memory address to copied c-string
*/
char* my_strcpy(char* str1, char* str2){
  int i;
  for(i = 0; i< strlen(str1); i++){
    str1[i] = str2[i];
  }
  str1[i] = '\0'; // adds escape character as soon as the str2 is copied into
                  // str1 so if it is outputted it stops here instead of contining
                  // to empty indexes when it is outputted
  return str1;
}
