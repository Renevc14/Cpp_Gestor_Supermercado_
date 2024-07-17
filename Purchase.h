#pragma once
#include "Supplier.h"
#include <iostream>
#include <vector>
#include "Product.h"


using namespace std;

class Purchase
{
private:
	Supplier* supplier;
	Product* product;
	int cantidad;

public:
	Purchase(Supplier* supplier, Product* product, int cantidad)
	{
		this->supplier = supplier;
		this->product = product;
		this->cantidad = cantidad;
		this->addProd(cantidad);
	}

	void addProd(int cantidad)
	{
		product->addStock(cantidad);
	}

	void showPurchase()
	{
		cout << "-----------------------------------------" << endl;
		cout << "Proveedor: " << supplier->getName()<<endl;
		cout << "Producto: " << product->getName();
		cout << "Stock agregado: " << cantidad << endl;
		cout << "-----------------------------------------" << endl;
	}

};