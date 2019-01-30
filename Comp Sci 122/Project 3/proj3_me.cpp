/*
Class: CPSC 122-01
Team Member 1: Zac Foteff
Team Member 2: None
Submitted by: Zac Foteff
GU Username: zfoteff
File Name: proj3.cpp
Programs take user inputted character lists and calls functions my_strcpy and
my_strcmp

To Build: g++ proj3.cpp -o proj3
To Execute: ./proj3
*/

#include <iostream>
#include <cstring>
using namespace std;

int my_strcmp(char*, char*);
char* my_strcpy(char*, char*, int);

int main(){
  char* userString1;
  char* userString2;

//Sentence 1 ---------------
  cout<< "Enter line of text: ";
  cin>> userString1;
  bool hasNums1; // will check if there are any numbers in the string
  for(i = 0; i< userString1.length(); i++){
    if(isalpha(userString1[i])){
      hasNums1 = false;
    }
    else{
      hasNums1 = true;
      break;
    }
  }

  while(hasNums1){ // input validation
    cout<< "One of the characters in the sentence inputted was a number."<<endl;
    cout<< "Please re-enter the string: ";
    cin>> userString1;

    for(i = 0; i< userString1.length(); i++){
      if(isalpha(userString1[i])){
        hasNums1 = false;
      }
      else{
        hasNums1 = true;
        break;
      }
    }
  }

//Sentence 2 -------------
  cout<< "Enter second line of text: ";
  cin>> userString2[];
  bool hasNums2;
  for(i = 0; i< userString2.length(); i++){
    if(isalpha(userString2[i])){
      hasNums2 = true;
    }
    else{
      hasNums2 = false;
      break;
    }
  }

  while(hasNums2){ // input validation
    cout<< "One of the characters in the sentence inputted was a number."<<endl;
    cout<< "Please re-enter the string: ";
    cin>> userString2;

    for(i = 0; i< userString2.length(); i++){
      if(isalpha(userString2[i])){
        hasNums2 = false;
      }
      else{
        hasNums2 = true;
        break;
      }
    }
  }





  delete userString1;
  delete userString2;
  return 0;
}


//String Compare
int my_strcmp(char* str1, char* str2){
  // Makes each string lowercase so they can be more easily compared
  for(int i = 0; i< str1.length(); i++){
    tolower(str1[i]);
  }
  for(int i = 0; i< str2.lenth(); i++){
    tolower(str2[i]);
  }


  if(str1 == str2){
    return 0;
  }

  else if(str1[0] > str2[0]){
    return -1;
  }

  else{
    return 1;
  }
}

//String Copy
char* my_strcpy(char* str1, char* str2, int size){
  for(int i = 0; i< size; i++){
    str2[i] = str[i];
  }
}
