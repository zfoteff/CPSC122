//This is an example of how pointers and their syntax work

#include <iostream>
using namespace std;

int main(){
	
	int userInt; // user defined int value
	int* myPtr = 0; // Pointer to an integer. Is entirely its own variable not associated with anything yet
	
	cout<<"Enter any integer: ";
	cin>> userInt;
	
	cout<< "_________________"<<endl;
	cout<< "userInt: "<<userInt<<endl;
	cout<< "userInt memory address: "<<&userInt<<endl;
	cout<<endl;
	
	myPtr = &userInt;
	
	cout<< "myPtr: "<<myPtr<<endl;
	cout<< "contents referenced by myPtr: "<<*myPtr<<endl;
	cout<< "_________________"<<endl;
	
	return 0;
	
	
	
	
}