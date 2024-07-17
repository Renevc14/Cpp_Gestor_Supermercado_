#pragma once
#include"Admin.h"
#include"Cashier.h"
#include"Client.h"
#include"Product.h"
#include"Sale.h"
#include"Supplier.h"
class DataProvider
{
private:
public:
    virtual vector<Sale> loadSales() = 0;
    virtual vector<Supplier> loadSuppliers() = 0;
    virtual vector<Product> loadProducts() = 0;
    virtual vector<Client> loadClients() = 0;
    virtual vector<Admin> loadAdmins() = 0;
    virtual vector<Cashier> loadCashiers() = 0;

};

