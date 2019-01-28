/*
Class: CPSC 122-01
Team Member 1: Zac Foteff
Team Member 2: n/a
Submitted by: Zac Foteff
GU Username: zfoteff
File Name: cReview.cpp
Program displays user defined amount of prime numbers calculated by program

To Build: g++ cReview.cpp -o cReview
To Execute: ./cReview
*/



#include <iostream>
using namespace std;

void display(int, int);
bool isPrime(int);

int main(){
int P, N; // prime numbers to be generated, number of columns

//primes
cout<< "How many prime numbers do you want printed out? ";
cin>> P;

while (P <= 1){
	cout<<"Please enter a number greater than 1: ";
	cin>> P;
}

//number of cols
cout<< "How many columns should the numbers be outputted in: ";
cin>> N;

while (N <= 0){
	cout<< "Please enter a number greater than 0: ";
	cin>> N;
}
//makes sure cols doesn't exceeed number of primes
while (N > P){
	cout<< "Please enter fewer columns than numbers: ";
	cin>> N;
}

display(P, N);


cout<<endl;
return 0;
}



void display(int numPrimes, int numCols){
	int counter = 0; // value that helps exit the loop
	int x = 2;
	
	while(counter< numPrimes){
		
		if(isPrime(x)){
			cout<< x<< '\t';
			if(counter % numCols == numCols - 1){
				cout<<endl;
			}
			counter++;
		}
		
		x++;
	}
}

 
bool isPrime(int x){
	bool ret = false;
	
	if (x == 2){
		return true;
	}
	if (x< 2){
		return false;
	}
	
	
	//covers the 2 most common devisors
	else if(x % 2 == 0){
		return false;
	}
	else if(x % 5 == 0){
		return false;
	}
	
	// since all enven numbers are elimanated, this will increment through all odd numbers up to the specified number
	for (int i = 3; i< x; i+= 2){
		if(x % i != 0){
			ret = true;
		}
		else{
			ret = false;
		}
	}
	
	return ret;
}