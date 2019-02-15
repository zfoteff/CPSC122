/*
Class: CPSC 122-01
Team Member 1: Zac Foteff
Team Member 2: None
Submitted by: Zac Foteff
GU Username: zfoteff
File Name: proj4.cpp
User uses command line arguments, a selection sort algorithm, and file i/o
to sort a file of c-strings into alphabetical order, then output the sorted
list to a file

To Build: g++ proj4.cpp -o proj4
To Execute: ./proj4 INPUTFILE.in OUTPUTFILE.out numLines
*/


#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

const int MAX_SIZE = 1000; // acts as both the largest one line can be, and how
                           // many things can be stores in the c-string array

void selSort(char**, int);
int my_strcmp(char*, char*);

int main(int argc, char* argv[])
{
  char line[MAX_SIZE]; //creates char list that can contain up to 1000 elements
  int numLines = atoi(argv[3]); // takes the second argument (num lines) and changes
                                // it to an integer from a char string
  char** lines = new char*[numLines];

  ifstream fin;
  ofstream fout;
  fin.open(argv[1]);
  fout.open(argv[2]);

  int i = 0;
  while (i < numLines)
  {
    fin.getline(line,MAX_SIZE); // stores each line into the line array

    int len = strlen(line) + 1;
    lines[i] = new char[len]; // creates new char string in the lines char string array at index i
    strcpy(lines[i], line);   // copies c-string stored in line into the lines array at index i

    i++;
  }

  selSort(lines, numLines);   //Sorts each line of text from the input file in the lines char-string list

  i = 0;
  while(i < numLines)
  {
    fout << lines[i] << endl;
    i++;
  }

 fin.close();

 return 0;

}


/*
Variation on selection sort algorithm using c-strings
pre: user inputs c-string pointer array arr and it's size
post: uses selection sort algorithm and my_strcmp to
      re arrainge the contents of arr to alphabetical order
*/
void selSort(char* arr[], int size)
{
  for(int i = 0; i< size-1; i++){
    int min_idx = i;
    char* dummy;

    for(int j = i+1; j< size; j++)
    {
      int compare = my_strcmp(arr[min_idx], arr[j]);
      if(compare == 1){ // if the c-string in arr[j] comes before arr[i]
                        // alphabetically they will be swapped
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
int my_strcmp(char* str1, char* str2)
{
  int l1 = strlen(str1);
  int l2 = strlen(str2);
  int size;
  if(l1 < l2)
  {
    size = l1;
  }
  else
  {
    size = l2;
  }

 for(int i = 0; i< size; i++)
 {
  tolower(str1[i]);
  tolower(str2[i]);

  if(str1[i] < str2[i]){
    return -1;
  }
  if(str1[i] > str2[i]){
    return 1;
  }

  if(l1 == l2)
  {
    return 0;
  }
  if(l1 < l2)
  {
    return -1;
  }
  if(l1 > l2){
    return 1;
  }
 }
}
