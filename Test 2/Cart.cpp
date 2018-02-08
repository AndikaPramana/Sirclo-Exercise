
#include "Product.cpp"

class Cart
{
	public:
		Cart (); 
		
		void addProduct(string, int );
		void removeProduct(string);
		void showCart();

	private:
		string productCode;
		int quantity;
		Product temp_product;
		vector<Product> listofproduct;
		
		   	   
};

Cart::Cart(){
	
}

// function to add a product to cart
void Cart::addProduct(string productCode, int quantity){
	
	temp_product = Product (productCode, quantity);
	bool check=false;
	
	// skip checking if cart empty
	if(listofproduct.empty()){
		
		
	}
	else{
	
	// check each item in cart for same product code
	for (int i=0; i < listofproduct.size(); i++){
	
		// if same item found, add more quantity of that item
        if(!listofproduct[i].getproductcode().compare(temp_product.getproductcode()))
		{
		   listofproduct[i].addquantity(quantity);
		   check=true;   
		}	    
    }
	}
	
	// if check=false, means new item added
	// add that product to cart. 
	if (check==false){
		listofproduct.push_back(temp_product);
	}
	
}

void Cart::removeProduct(string productCode){

	
	// skip checking if cart empty
	if(listofproduct.empty()){
		
		
	}
	else{
	// check each item in cart for the product that we want to remove
	for (int i=0; i < listofproduct.size(); i++){
        if(!listofproduct[i].getproductcode().compare(productCode))
		{
		   // if found, remove that product
		   listofproduct.erase(listofproduct.begin()+i);   
		}	 
		//else, just ignore the product (product have not been added to cart before)
    }
	}
	
}

void Cart::showCart(){
	// for each item in cart, list the product
	for (int i=0; i < listofproduct.size(); i++){
       cout << listofproduct[i].getproductcode() << " (" << listofproduct[i].getquantity() << ")" << endl;	    
    }
	
}

