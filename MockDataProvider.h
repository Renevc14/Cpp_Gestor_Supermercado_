#pragma once
#include "DataProvider.h"
class MockDataProvider : public DataProvider
{
private:
    vector<Supplier> suppliers;
    vector<Product> products;
    vector<Product> Clients;
    vector<Product> Cashiers;
public:
    virtual vector<Supplier> loadSuppliers();
    virtual vector<Sale> loadSales();
    virtual vector<Product> loadProducts();
    virtual vector<Client> loadClients();
    virtual vector<Admin> loadAdmins();
    virtual vector<Cashier> loadCashiers();
};

