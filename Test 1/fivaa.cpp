// first exercise (SIRCLO)
// fivaa
// By Andika Pramana 

// declare some library required
#include <iostream>
using namespace std;

void fivaa(int);

int main ()
{
	///declare variable to be inputted
	int anumber;
		
	cout << "Please input some number : ";	  	  
	cin >> anumber;
	
	// run the function after user input a number
	fivaa(anumber);
	
}

void fivaa(int anumber)
{
	// declare temp variable
	int first_sequence = 0;
	int second_sequence =0;
	
	// using for loop to print out message
	for(int i=anumber; i > 0; i--){
	
		// calculate the first 2 numbers in sequence
		first_sequence = i-1;
		
		// calculate the rest of numbers in sequence
		second_sequence = i+1;
		
		// print out first 2 numbers
		for(int j=0;j<2;j++){
			cout << first_sequence;
		}
		
		// print out the rest of the numbers
		for(int k=i-1; k>=0; k--){
			cout << second_sequence;
		}
		
		cout << endl;
	} 
}

