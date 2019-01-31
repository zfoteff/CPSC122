/*
Class: CPSC 122-01
Team Member 1: Zac Foteff
Team Member 2: None
Submitted by: Zac Foteff
GU Username: zfoteff
File Name: proj3.cpp
File contains code for functions my_strcpy and my_strcmp

To Build: g++ proj3.cpp -o proj3
To Execute: ./proj3
*/


/*
my_strcmp
pre: user passes two c-strings
post: returns 0 if the c-strings are the same
      returns -1 if c-string 1 is first alphabetically
      returns 1 if c-string 2 is first alphabetically
*/

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
  }
 }

 else if(str1[i] > str2[i]){
  return 1;
  break;
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


/*
my_strcpy
pre: user passes 2 c-strings
    str1's length is greater than str2's length by at least once
post: returns memory address to copied c-string
*/
