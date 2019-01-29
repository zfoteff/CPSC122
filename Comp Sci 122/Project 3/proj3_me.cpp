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


int my_strcmp(char*, char*);
char* my_strcpy(char*, char*, int);

int main(){
  char* userString1;
  char* userString2;

  cout<< "Enter line of text: ";
  cin>> userString1[];
  cout<< "Enter second line of text: ";
  cin>> userString2[];






  delete userString1;
  delete userString2;
  return 0;
}



int my_strcmp(char* str1, char* str2){

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

char* my_strcpy(char* str1, char* str2, int size){
  for(int i = 0; i< size; i++){
    str2[i] = str[i];
  }

}
