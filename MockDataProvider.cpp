#include "MockDataProvider.h"

vector<Supplier> MockDataProvider::loadSuppliers()
{
    
    vector<Supplier> mockSuppliers;
    mockSuppliers.push_back(Supplier("Pil", "Bolivar"));
    
    mockSuppliers.push_back(Supplier("Delizia", "Tarija"));
    
    mockSuppliers.push_back(Supplier("Lazzaroni", "Oruro"));
    
    mockSuppliers.push_back(Supplier("Princesa", "La Paz"));
    
    mockSuppliers.push_back(Supplier("Nestle", "La Paz"));

    //vector<Product> products = loadProducts();
    //mockSuppliers[3].addProduct(&products[6]);
    //mockSuppliers[3].addProduct(&products[7]);
    //mockSuppliers[2].addProduct(&products[4]);
    //mockSuppliers[2].addProduct(&products[5]);
    //mockSuppliers[1].addProduct(&products[2]);
    //mockSuppliers[1].addProduct(&products[3]);
    //mockSuppliers[0].addProduct(&products[0]);
    //mockSuppliers[0].addProduct(&products[1]);
    //mockSuppliers[4].addProduct(&products[8]);
    //mockSuppliers[4].addProduct(&products[9]);

    return mockSuppliers;
}

vector<Product> MockDataProvider::  loadProducts()
{
    vector<Product> mockProducts;
    vector<Supplier> suppliers = loadSuppliers();

    mockProducts.push_back(Product("Leche", &(suppliers[0]), 1, 7, "06/23", 5));
    mockProducts.push_back(Product("Yogurt", &(suppliers[0]), 2, 8.5, "07/23", 8));
    mockProducts.push_back(Product("Dulce de Leche", &(suppliers[1]), 3, 15, "10/23", 15));
    mockProducts.push_back(Product("Mantequilla", &(suppliers[1]), 4, 12, "06/23", 19));
    mockProducts.push_back(Product("Salsa de Tomate", &(suppliers[2]), 5, 22.5, "08/27", 20));
    mockProducts.push_back(Product("Fideo", &(suppliers[2]), 6, 5.5, "06/26", 20));
    mockProducts.push_back(Product("Avena", &(suppliers[3]), 7, 8.9, "12/23", 50));
    mockProducts.push_back(Product("Toddy", &(suppliers[3]), 8, 30, "11/24", 18));
    mockProducts.push_back(Product("Chocapic", &(suppliers[4]), 9, 22.7, "01/27", 78));
    mockProducts.push_back(Product("Nutella", &(suppliers[4]), 10, 100, "05/26", 0));
    return mockProducts;
}

vector<Client> MockDataProvider::loadClients()
{
    vector<Client> mockClients;
    mockClients.push_back(Client("Vilela", 8016404, Clienttype::VIP));
    mockClients.push_back(Client("Rivera", 1382709010, Clienttype::PREMIUM));
    mockClients.push_back(Client("Bustamante", 3515641, Clienttype::VIP));
    mockClients.push_back(Client("Cabrera", 342156));
    mockClients.push_back(Client("Antezana", 8016404));
    mockClients.push_back(Client("Jordan", 764891));
    mockClients.push_back(Client("Roberto Carlos", 903751, Clienttype::VIP));
    mockClients.push_back(Client("Clara Sanchez", 479451, Clienttype::PREMIUM));
    mockClients.push_back(Client("Pepe Mujica", 134468, Clienttype::PREMIUM));
    mockClients.push_back(Client("Pedro Gonzalez", 2455756, Clienttype::VIP));

    return mockClients;
}

vector<Admin> MockDataProvider::loadAdmins()
{
    vector<Admin> mockAdmins;
    mockAdmins.push_back(Admin(1, 2500, "Bernardo Betancourt", "Supervisar,Limpiar"));
    mockAdmins.push_back(Admin(2, 2800, "Rogelio Choque", "Supervisar,Cuadrar cuenta"));
    mockAdmins.push_back(Admin(3, 3500, "Ramiro Lopez", "Supervisar,Limpiar,Cuadra cuenta"));
    mockAdmins.push_back(Admin(4, 3200, "Claudio Vargas", "Supervisar,Firmar papeles"));
    mockAdmins.push_back(Admin(5, 2950.5, "Monica Rocha", "Supervisar,Pedido de Productos"));

    return mockAdmins;
}

vector<Cashier> MockDataProvider::loadCashiers()
{
    vector<Cashier> mockCashiers;
    mockCashiers.push_back(Cashier(11, 2500, "Cesar Vargas", 1));
    mockCashiers.push_back(Cashier(12, 2500, "Patricia Muruchi", 8));
    mockCashiers.push_back(Cashier(13, 2500, "Marcela Heizman", 4));
    mockCashiers.push_back(Cashier(14, 2500, "Douglas Costa", 5));
    mockCashiers.push_back(Cashier(15, 2500, "Andre Fernandez", 2));
    mockCashiers.push_back(Cashier(16, 2500, "Nicolas Martinez"));
    mockCashiers.push_back(Cashier(17, 2500, "Marcelo Hernandez"));
    mockCashiers.push_back(Cashier(18, 2500, "Andres Mercado"));
    mockCashiers.push_back(Cashier(19, 2500, "Lylian Caladio"));
    mockCashiers.push_back(Cashier(111, 2500, "Juan Carlos Claros"));
    mockCashiers.push_back(Cashier(112, 2500, "Claudio Rojas"));

    return mockCashiers;
}

vector<Sale> MockDataProvider::loadSales()
{
    vector<Sale> mockSales;
    vector<Product> products = loadProducts();
    vector<Client> clients = loadClients();
    vector<Cashier> cashiers = loadCashiers();

    vector<Product*> products1;
    products1.push_back(&products[0]);
    products1.push_back(&products[0]);
    products1.push_back(&products[1]);
    mockSales.push_back(Sale(&cashiers[0], &clients[0], products1));

    vector<Product*> products2;
    products2.push_back(&(products[2]));
    products2.push_back(&products[1]);
    products2.push_back(&products[3]);
    mockSales.push_back(Sale(&cashiers[2], &clients[4], products2));

    return mockSales;
}
