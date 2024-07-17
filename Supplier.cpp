#include "Supplier.h"
#include "Product.h"

Supplier::Supplier(string name, string address)
{
	this->name = name;
	this->address = address;
	this->product = nullptr;
}

Supplier::Supplier(string name, string address, Product* product)
{
	this->product = product;
}

string Supplier::getName()
{
	return name;
}

void Supplier::addProduct(Product* producto)
{
	this->product = producto;
}
