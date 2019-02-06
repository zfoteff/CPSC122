/*
Class: CPSC 122-01
Team Member 1: Zac Foteff
Team Member 2: None
Submitted by: Zac Foteff
GU Username: zfoteff
File Name: proj4.cpp
File contains code for functions my_strcpy and my_strcmp

To Build: g++ proj4.cpp -o proj4
To Execute: ./proj4 INPUTFILE.in OUTPUTFILE.out numLines
*/


#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

const int MAX_SIZE = 1000;

void selSort(char**, int);
int my_strcmp(char*, char*);

int main(int argc, char* argv[]){
  char line[MAX_SIZE]; //creates char list that can contain 1000 elements
  int num_lines = atoi(argv[3]); // takes the second argument (num lines) and changes it to an integer from a char strin
  char** lines = new char*[num_lines];

  ifstream fin;
  ofstream fout;
  fin.open(argv[1]);
  fout.open(argv[2]);

  int i = 0;
  while (i < num_lines){
    fin.getline(line,80);

    int len = strlen(line) + 1;
    lines[i] = new char[len]; // creates new char string in the lines char string array at index i
    strcpy(lines[i], line); // copies line into the lines array at index i

    i++;
  }

  selSort(lines, num_lines); //Sorts each line of text from the input file in the lines char-string list

  i = 0;
  while(i < num_lines){
    fout << lines[i] << endl;
    i++;
  }

 fin.close();

 return 0;

}

void selSort(char* arr[], int size){
  for(int i = 0; i< size-1; i++){
    int min_idx = i;
    char* dummy;

    for(int j = i+1; j< size; j++){
      int compare = my_strcmp(arr[i], arr[j]);
      if(compare == 1){ // if the c-string in arr[j] comes before arr[i] alphabetically they will be swapped
        min_idx = j;
      }
    }
    dummy = arr[i];
    arr[i] = arr[min_idx];
    arr[min_idx] = dummy; //swaps the element at min_idx with element at index i
  }
}

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

 //Will iterate through each character in each string till it finds a set where one is
 // alphabetically greater
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

  // If the character stored in index 0 of str1 has a value less than the value stored
  // in index 0 of str2, that means it appears first alphabetically
 else if(str1[0] < str2[0]){
  return -1;
 }

  // If the character stored in index 0 of str1 has a value greater than
  // the value stored in index 0 of str2, that means it appears second alphabetically
 else if(str1[0] > str2[0]){
  return 1;
 }
}
