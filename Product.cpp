#include "Product.h"

Product::Product(string name, Supplier* supplier, int id, float price, string experingDate)
{
	this->name = name;
	this->supplier = supplier;
	this->id = id;
	this->price = price;
	this->experingDate = experingDate;
}

Product::Product(string name, int id, float price, string experingDate, int cantidad)
{
	this->name = name;
	this->id = id;
	this->price = price;
	this->experingDate = experingDate;
	this->cantidad = cantidad;
}

Product::Product(string name, Supplier* supplier, int id, float price, string experingDate, int cantidad)
{
	this->name = name;
	this->supplier = supplier;
	this->id = id;
	this->price = price;
	this->experingDate = experingDate;
	this->cantidad = cantidad;
}

void Product::showinfo()
{
	cout << "Nombre: " << name << endl;
	//cout << supplier->getName() << endl;
	cout << "ID: " << id << endl;
	cout << "Precio: " << price << endl;
	cout << "Fecha de vencimiento: " << experingDate << endl;
	cout << "Cantidad en stock: " << cantidad << endl;

}

string Product::getName()
{
	return name;
}

void Product::addStock(int cant)
{
	cantidad = cantidad + cant;
}
