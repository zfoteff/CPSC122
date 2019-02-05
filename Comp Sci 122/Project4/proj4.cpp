/*
Class: CPSC 122-01
Team Member 1: Zac Foteff
Team Member 2: None
Submitted by: Zac Foteff
GU Username: zfoteff
File Name: proj4.cpp
File contains code for functions my_strcpy and my_strcmp

To Build: g++ proj3.cpp -o proj3
To Execute: ./proj3
*/


#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

char* sort(ifstream, int);

int main(int argc, char* argv[]){
  char line[80];
  int num_lines = atoi(argv[2]);
  char** lines = new char*[num_lines];

  ifstream fin;
  fin.open(argv[1]);

  int i = 0;
  while (i < num_lines){
    fin.getline(line,80);

    int len = strlen(line) + 1;
    lines[i] = new char[len];
    strcpy(lines[i],line);

    i++;
  }

  i = 0;
  while(i < num_lines){
    cout << lines[i] << endl;
    i++;
  }

 fin.close();

 return 0;

}

char* sort(ifstream )
