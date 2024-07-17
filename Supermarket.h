#pragma once
#include <iostream>
#include "Supplier.h"
#include "Client.h"
#include "Product.h"
#include "Sale.h"
#include "Employee.h"
#include"Admin.h"
#include"Cashier.h"
#include "Dataprovider.h"
#include "MockDataProvider.h"
#include <vector>
#include <string>
#include "Purchase.h"

using namespace std;


class Supermarket
{
private:

	vector<Supplier> suppliers;
	vector<Client> clients;
	vector<Admin> admins;
	vector<Cashier> cashiers;
	vector<Product> products;
	vector<Sale> sales;
	vector<Employee> employee;
	vector <Purchase> purchases;
	DataProvider* dataprovider= new MockDataProvider;

public:
	Supermarket(DataProvider* dataprovider);
	void menu();
	void registerClient();
	void registerEmployee();
	void registerProduct();
	void loadData();
	void showClients();
	void showProducts();
	void showEmployees();
	void registerSale();
	void showSales();
	void buyProductToProvider();
	void purchasesHistory();
};

