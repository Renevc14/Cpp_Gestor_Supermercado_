#include "Client.h"

Client::Client(string name, int nit, Clienttype type)
{
	this->nit = nit;
	this->name = name;
	this->type = type;
}
Client::Client(string name, int nit)
{
	this->nit = nit;
	this->name = name;
	this->type = Clienttype::REGULAR;
}

void Client::showInfo()
{

	cout << "****CLIENTE****" << endl;
	cout << "Nombre:" << name << endl;
	cout << "NIT:" << nit << endl;

}

string Client::getName()
{
	return name;
}
