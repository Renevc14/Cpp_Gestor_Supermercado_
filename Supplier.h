#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Product;

class Supplier
{
private:
	Product* product;
	string name, address;
public:
	Supplier(string name, string address);
	Supplier(string name, string address, Product* product);

	string getName();

	void addProduct(Product* producto);
};


