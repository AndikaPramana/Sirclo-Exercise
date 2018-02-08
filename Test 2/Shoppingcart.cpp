// Second Exercise (SIRCLO)
// Shopping Cart

// By Andika Pramana

#include  "Cart.cpp"


int main ()
{
	Cart *cart = new Cart();
	cart->addProduct("Baju Merah Mantap", 1);
	cart->addProduct("Baju Merah Mantap", 1);
	cart->addProduct("Bukuku", 3);
	cart->removeProduct("Bukuku");
	cart->addProduct("Singlet Hijau", 1);
	cart->removeProduct("ProdukBohongan");
	cart->showCart();
	
}


