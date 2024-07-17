#pragma once
#include "Cashier.h"
#include <vector>
#include "Product.h"
#include "Client.h"


class Sale
{
private:
	Cashier* cashier;
	vector <Product*> products;
	Client* client;

public:
	Sale(Cashier* cashier, Client* client, vector<Product*> products);
	void addProduct(Product* products);
	string getClient();
	string getCashier();
	int listSize();
	void showProducts();

};

