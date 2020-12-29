/*
Class: CPSC 122-01
Team Member 1: Zac Foteff
Team Member 2: None
Submitted by: Zac Foteff
GU Username: zfoteff
File Name: strcmpTest.cpp
Programs take user inputted character lists
and calls function my_strcmp

To Build: g++ strcmpTest.cpp -o strcmpTest
To Execute: ./strcmpTest "str1" "str2"
*/

#include <iostream>
#include <cstring>
using namespace std;

int my_strcmp(char*, char*);

int main(int argc, char* argv[]){
  char* userstr1 = argv[1];
  char* userstr2 = argv[2];

  int x = my_strcmp(userstr1, userstr2);

  cout<<x<<endl;

}

int my_strcmp(char* str1, char* str2){
  for(int i = 0; i< strlen(str1); i++){
    tolower(str1[i]);
  }
  for(int i = 0; i< strlen(str2); i++){
    tolower(str2[i]);
  }
  //These two for loops change all characters in the strings to lowercase so they can be compared more easily


  if(str1 == str2){
    return 0;
  }

  //This is to check alphabetical order
  //Will iterate through each character in each string till it finds a set where one is alphabetically greater  
  else if(str1[0] == str2[0]){
    for(int i = 1; i< strlen(str1); i++){
      if(str1[i] < str2[i]){
        return -1;
        break;
      }

      else if(str1[i] > str2[i]){
        return 1;
        break;
      }
    }
  }

  // If the character stored in index 0 of str1 has a value less than the value stored in index 0 of str2, that means it appears first alphabetically
  else if(str1[0] < str2[0]){
    return -1;
  }

  // If the character stored in index 0 of str1 has a value greater than the value stored in index 0 of str2, that means it appears second alphabetically
  else if(str1[0] > str2[0]){
    return 1;
  }
}
