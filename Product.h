#pragma once
#include <string>
#include <iostream>
#include "Supplier.h"
using namespace std;

class Product
{
private:
	Supplier* supplier;
	int id, cantidad;
	float price;
	string name, experingDate;
public:
	Product(string name, Supplier* supplier, int id, float price, string experingDate);
	Product(string name, int id, float price, string experingDate, int cantidad);
	Product(string name, Supplier* supplier, int id, float price, string experingDate, int cantidad);
	void showinfo();
	string getName();
	void addStock(int cant);
};

