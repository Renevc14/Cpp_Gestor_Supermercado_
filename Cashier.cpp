#include "Cashier.h"

Cashier::Cashier(int id, int salary, string name, int cashRegister) :Employee(id, salary, name)
{
	this->cashRegister = cashRegister;
}

Cashier::Cashier(int id, int salary, string name) :Employee(id, salary, name)
{
}

Cashier::Cashier():Employee()
{
}

string Cashier::getName()
{
	return name;
}

void Cashier::setCashRegister(int cashRegister)
{
	this->cashRegister = cashRegister;
}

void Cashier::setId(int id)
{
	this->id = id;
}

void Cashier::setSalary(float salary)
{
	this->salary = salary;
}

void Cashier::setName(string name)
{
	this->name = name;
}
