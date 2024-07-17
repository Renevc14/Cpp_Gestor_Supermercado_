#include "Supermarket.h"
#include <iostream>

Supermarket::Supermarket(DataProvider* dataprovider)
{
    this->dataprovider = dataprovider;
}

void Supermarket::menu()
{
    loadData();
    int op = -1;
    do {
        cout << "---------Menu----------" << endl;
        cout << "Ingrese el número de la opción que desea elegir:" << endl;

        cout << "1. Registrar cliente" << endl;
        cout << "2. Registrar empleado" << endl;
        cout << "3. Registrar producto" << endl;
        cout << "4. Mostrar clientes" << endl;
        cout << "5. Mostrar productos" << endl;
        cout << "6. Mostrar empleados" << endl;
        cout << "7. Registrar venta" << endl;
        cout << "8. Mostrar ventas" << endl;
        cout << "9. Agregar stock de producto" << endl;
        cout << "10. Mostrar historial de compras a proveedores" << endl;

        cin >> op;
        system("cls");
        switch (op)
        {
        case 1:
            registerClient();
            break;
        case 2:
            registerEmployee();
            break;
        case 3:
            registerProduct();
            break;
        case 4:
            showClients();
            break;
        case 5:
            showProducts();
            break;
        case 6:
            showEmployees();
            break;
        case 7:
            registerSale();
            break;
        case 8:
            showSales();
            break;
        case 9:
            buyProductToProvider();
            break;
        case 10:
            purchasesHistory();
        }
        
    } while (op != 0);
}

void Supermarket::registerClient()
{
    string name;
    int nit;
    cout << "Ingrese el nombre completo del cliente:" << endl;
    cin.ignore();
    getline(cin, name);
    cout << "Ingrese el NIT del cliente:" << endl;
    cin >> nit;

    Client c = Client(name, nit);
    clients.push_back(c);
}

void Supermarket::registerEmployee()
{
    int id;
    float salary;
    string name;
    int cashRegister, cargo;
    string duties;
    Admin ad;
    Cashier c;
    cout << "ingrese el ID del empleado" << endl;
    cin >> id;      //exception si el id es repetido
    cout << "ingrese el salario del empleado" << endl;
    cin >> salary;
    cout << "ingrese el nombre" << endl;
    cin >> name;
    cout << "Elija el cargo del empleado" << endl << "[ 1 ] Adminstrador " << endl << "[ 2 ] Cajero" << endl;
    cin >> cargo;
    switch (cargo)
    {
    case 1:
        cout << "Ingrese las tareas que realizará" << endl;
        cin >> duties;
        // setters (id, salary, name, duties);
        ad.setId(id);
        ad.setSalary(salary);
        ad.setName(name);
        ad.setDuties(duties);
        admins.push_back(ad);
        break;
    case 2:
        cout << "Ingrese el número de caja registradora en la que trabajará" << endl;
        cin >> cashRegister;
        // setters (id,salary,name,cashRegister);
        c.setId(id);
        c.setSalary(salary);
        c.setName(name);
        c.setCashRegister(cashRegister);
        cashiers.push_back(c);
        break;
    }
    cout << "EMPLEADO REGISTRADO EXITOSAMENTE" << endl;
    system("pause");
}

void Supermarket::registerProduct()
{
    int id, supplierPos;
    float price;
    string name, experingDate;
    cout << "Ingrese el nombre del producto:" << endl;
    cin.ignore();
    getline(cin, name);
    cout << "Ingrese el ID del producto:" << endl;
    cin >> id;
    cout << "Ingrese el precio del producto:" << endl;
    cin >> price;
    cout << "Ingrese la fecha de vencimiento (string):" << endl;
    cin.ignore();
    getline(cin, experingDate);
    cout << "Ingrese el identificador del proveedor:" << endl;
    for (int i = 0; i < suppliers.size(); i++)
    {
        cout << "[" << i << "] " << suppliers[i].getName() << endl;
    }
    cin >> supplierPos;

    Product p = Product(name, &(suppliers[supplierPos]), id, price, experingDate);
    products.push_back(p);
    cout << "PRODUCTO REGISTRADO EXITOSAMENTE" << endl;
    system("pause");
}

void Supermarket::loadData()
{
    suppliers = dataprovider->loadSuppliers();
    admins = dataprovider->loadAdmins();
    cashiers = dataprovider->loadCashiers();
    products = dataprovider->loadProducts();
    //sales = dataprovider->loadSales();
    clients = dataprovider->loadClients();
}

void Supermarket::showClients()
{
    for (Client c : clients)
    {
        c.showInfo();
    }
    system("pause");
}

void Supermarket::showProducts()
{
    for (int i = 0; i < products.size(); i++)
    {
        products[i].showinfo();
    }
    system("pause");
}

void Supermarket::showEmployees()
{
    cout << "**ADMINS**" << endl;
    for (int i = 0; i < admins.size(); i++)
    {
        admins[i].showInfo();
    }
    cout << endl << endl;
    cout << "**CASHIERS**" << endl;
    for (int i = 0; i < cashiers.size(); i++)
    {
        cashiers[i].showInfo();
    }
}

void Supermarket::registerSale()
{
    int cashierPos, clientPos, productPos;
    vector<Product*> productsAux;
    cout << "---------Registrar Venta-----------" << endl;
    cout << "Ingrese el identificador del cajero que hizo la venta" << endl;
    for (int i = 0; i < cashiers.size(); i++)
    {
        cout << "[ " << i << " ]  " << cashiers[i].getName() << endl;
    }
    cin >> cashierPos;

    cout << "Ingrese el identificador del cliente que realizó la compra" << endl;

    for (int i = 0; i < clients.size(); i++)
    {
        cout << "[ " << i << " ]  " << clients[i].getName() << endl;
    }
    cin >> clientPos;
    system("cls");
    do
    {
        cout << "Ingrese el identificador de los productos que desea agregar al carrito" << endl;
        cout << "para terminar de seleccionar los elementos escriba -1" << endl;
        for (int i = 0; i < products.size(); i++)
        {
            cout << "[ " << i << " ]  " << products[i].getName() << endl;
        }
        cin >> productPos;
        if (productPos != -1)
        {
            productsAux.push_back(&products[productPos]);
        }
        else
        {
            cout << "Fin de la selección" << endl;
        }
        system("cls");
    } while (productPos != -1);

    Sale s(&cashiers[cashierPos], &clients[clientPos], productsAux);
    sales.push_back(s);
    cout << "VENTA REGISTRADA EXITOSAMENTE" << endl;
}

void Supermarket::showSales()
{
    cout << "--------Ventas---------" << endl;
    for (int i = 0; i < sales.size(); i++)
    {
        cout << "Cliente: " << sales[i].getClient()<< endl;
        cout << "Cajero: " << sales[i].getCashier() << endl;
        sales[i].showProducts();
    }
}

void Supermarket::buyProductToProvider()
{
    int supplierPos, productPos;
    Product* product;
    Supplier* supplier;
    int cantidad;
    cout << "Escribe el numero del proveedor del que se realizará la compra" << endl;
    for (int i = 0; i < suppliers.size(); i++)
    {
        cout << "[ " << i << " ]" << suppliers[i].getName()<<endl;
        cout << "Provider" << endl;
    }
    cin >> supplierPos;
    cout << "Escribe el numero del identificador del producto que va a comprar" << endl;
    for (int i = 0; i < products.size(); i++)
    {
        cout << "[ " << i << " ] " << products[i].getName() << endl;
    }
    cin >> productPos;
    cout << "ingrese el numero de unidades que desea adquirir: " << endl;
    cin >> cantidad;
    //terminar cuando tenga clase compras
    Purchase p(&suppliers[supplierPos], &products[productPos], cantidad);
    purchases.push_back(p);
    cout << "COMPRA REGISTRADA EXITOSAMENTE" << endl;
}

void Supermarket::purchasesHistory()
{
    cout << "--------PURCHASES-------" << endl;
    for (int i = 0; i < purchases.size(); i++)
    {
        purchases[i].showPurchase();
    }
}




/*#include "Supermarket.h"

Supermarket::Supermarket(DataProvider* dataprovider)
{
    this->dataprovider = dataprovider;
}

void Supermarket::menu()
{
    loadData();
    int op = -1;
    do {
        cout << "---------Menu----------" << endl;
        cout << "Ingrese el número de la opción que desea elegir:" << endl;
        cout << "1. Registrar cliente" << endl;
        cout << "2. Registrar empleado" << endl;
        cout << "3. Registrar producto" << endl;
        cout << "4. Mostrar clientes" << endl;
        cout << "5. Mostrar productos" << endl;
        cout << "6. Mostrar admins " << endl;
        cout << "7. Registrar venta" << endl;

        cin >> op;
        system("cls");
        switch (op)
        {
        case 1:
            registerClient();
            break;
        case 2:
            // registerEmployee();
            break;
        case 3:
            registerProduct();
            break;
        case 4:
            showClients();
            break;
        case 5:
            showProducts();
            break;
        case 6:
            showAdmins();
            break;
        case 7:
            registerSale();
                break;
        }
    } while (op != 0);
}

void Supermarket::registerClient()
{
    string name;
    int nit;
    cout << "Ingrese el nombre completo del cliente:" << endl;
    cin.ignore();
    getline(cin, name);
    cout << "Ingrese el NIT del cliente:" << endl;
    cin >> nit;

    Client c = Client(name, nit);
    clients.push_back(c);
}

void Supermarket::registerProduct()
{
    int id, supplierPos;
    float price;
    string name, experingDate;
    cout << "Ingrese el nombre del producto:" << endl;
    cin.ignore();
    getline(cin, name);
    cout << "Ingrese el ID del producto:" << endl;
    cin >> id;
    cout << "Ingrese el precio del producto:" << endl;
    cin >> price;
    cout << "Ingrese la fecha de vencimiento (string):" << endl;
    cin.ignore();
    getline(cin, experingDate);
    cout << "Ingrese el identificador del proveedor:" << endl;
    for (int i = 0; i < suppliers.size(); i++)
    {
        cout << "[" << i << "] " << suppliers[i].getName() << endl;
    }
    cin >> supplierPos;

    Product p = Product(name, &(suppliers[supplierPos]), id, price, experingDate);
    products.push_back(p);
}

void Supermarket::loadData()
{
    suppliers = dataprovider->loadSuppliers();
    admins = dataprovider->loadAdmins();
    cashiers = dataprovider->loadCashiers();
    products = dataprovider->loadProducts();
    //sales = dataprovider->loadSales();
    clients = dataprovider->loadClients();
    
}

void Supermarket::showClients()
{
    for (Client c : clients)
    {
        c.showInfo();
    }
}

void Supermarket::showProducts()
{
    for (int i = 0; i <products.size(); i++)
    {
        products[i].showinfo();
    }
}

void Supermarket::showAdmins()
{
    cout << "***************ADMINS*************" << endl;
    for (int i = 0; i < admins.size();i++)
    {
        
        admins[i].showInfo();
        
    }
    system("pause");
}


void Supermarket::registerSale()
{
    int cashierPos, clientPos, productPos;
    vector <Product*> productsAux;

    cout << "---------Registrar Venta-----------" << endl;
    cout << "Ingrese el identificador del cajero que hizo la venta" << endl;
    for (int i = 0; i < cashiers.size(); i++)
    {
        cout << "[ " << i << " ]  " << cashiers[i].getName()<<endl;
    }
    cin >> cashierPos;

    cout << "Ingrese el identificador del cliente que realizó la compra" << endl;

    for (int i = 0; i < clients.size(); i++)
    {
        cout << "[ " << i << " ]  " << clients[i].getName() << endl;
    }
    cin >> clientPos;
    cout << "Ingrese el identificador de los productos que desea agregar al carrito" << endl;
    cout << "para terminar de seleccionar los elementos escriba -1" << endl;
    do
    {
        for (int i = 0; i < products.size(); i++)
        {
            cout << "[ " << i << " ]  " << products[i].getName()<< endl;
        }
        cin >> productPos;
        if (productPos != -1)
            productsAux.pushback(*products[productPos]);
        else
        {
            cout << "Fin de la selección" << endl
        }
        system("pause");
        system("clear");
    } while (productPos!=-1);

    Sale s = new Sale (cashiers[cashierPos], clients[clientPos], productsAux);
    sales.pushback(s);
}*/