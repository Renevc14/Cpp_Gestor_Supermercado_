
#include "Sale.h"

Sale::Sale(Cashier* cashier, Client* client, vector<Product*> products)
{
    this->cashier = cashier;
    this->client = client;
    this->products = products;
}

void Sale::addProduct(Product* product)
{
    products.push_back(product);
}

string Sale::getClient()
{
    return client->getName();
}

string Sale::getCashier()
{
    return cashier->getName();
}

int Sale::listSize()
{
    return products.size();
}

void Sale::showProducts()
{
    cout << "------PRODUCTOS-------" << endl;
    for (int i = 0; i < products.size(); i++)
    {
        cout <<products[i]->getName()<<endl;
    }
    cout << "FIN DE LA LISTA." << endl;
}
