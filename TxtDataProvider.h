#pragma once
#include "DataProvider.h"

class TxtDataProvider : public DataProvider
{
private:
public:
    virtual vector<Supplier> loadSuppliers();
    virtual vector<Sale> loadSales();
    virtual vector<Product> loadProducts();
    virtual vector<Client> loadClients();
    virtual vector<Admin> loadAdmins();
    virtual vector<Cashier> loadCashiers();
};

