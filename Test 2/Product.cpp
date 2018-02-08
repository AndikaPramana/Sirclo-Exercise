#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

class Product
{
	public:
		Product (); 
		Product(string, int);
		
		string getproductcode();
		int getquantity();
		void addquantity(int);
	private:
		string productCode;
		int quantity;
		
		   	   
};

Product::Product(){
	
}


Product::Product(string aproductCode, int aQuantity){
	this->productCode = aproductCode;
	this->quantity= aQuantity;
}

string Product::getproductcode(){
	return this->productCode;
}

int Product::getquantity(){
	return this->quantity;
}


void Product::addquantity(int aQuantity){
	this->quantity += aQuantity;
}



