#include "TxtDataProvider.h"
#include<fstream>
vector<Supplier> TxtDataProvider::loadSuppliers()
{
	vector<Supplier> suppliers;
	ifstream file("supplier.txt");
	string name;
	string address;

	while (file.good())
	{
		file >> name;
		file >> address;
		//getline(file, name);
		//getline(file, name);


		suppliers.push_back(Supplier(name, address));
	}

	return suppliers;
}



vector<Product> TxtDataProvider::loadProducts()
{
	vector<Product> products;
	ifstream file("products.txt");
	int id, cantidad;
	float price;
	string name, experingDate;

	while (file.good())
	{
		file >> id;
		file >> price;
		file >> name;
		file >> experingDate;
		file >> cantidad;

		products.push_back(Product(name, id, price, experingDate, cantidad));
	}

	return products;
}

vector<Client> TxtDataProvider::loadClients()
{
	vector<Client> clients;
	ifstream file("client.txt");
	string name;
	int nit;
	while (file.good())
	{
		file >> name;
		file >> nit;
		//getline(file, name);
		//getline(file, name);


		clients.push_back(Client(name, nit));
	}

	return clients;
}

vector<Admin> TxtDataProvider::loadAdmins()
{
	
	vector<Admin> admins;
	ifstream file("admin.txt");
	int  id;
	float salary;
	string name;
	string duties;

	while (file.good())
	{
		file >> id;
		file >> salary;
		file >> name;
		file >> duties;
		//getline(file, name);
		//getline(file, name);


		admins.push_back(Admin(id, salary, name, duties));
	}

	return admins;
}

vector<Cashier> TxtDataProvider::loadCashiers()
{
	vector<Cashier> cashiers;
	ifstream file("cashier.txt");
	int  id;
	float salary;
	string name;
	int cashier;

	while (file.good())
	{
		file >> id;
		file >> salary;
		file >> name;
		file >> cashier;
		//getline(file, name);
		//getline(file, name);


		cashiers.push_back(Cashier(id, salary, name, cashier));
	}

	return cashiers;
}
vector<Sale> TxtDataProvider::loadSales()
{
	vector<Sale> sales;/*
	ifstream file("sale.txt");
	string name;
	string address;

	while (file.good())
	{
		file >> name;
		file >> address;
		//getline(file, name);
		//getline(file, name);


		sales.push_back(Sale(name, address));
	}
	*/
	return sales;
}