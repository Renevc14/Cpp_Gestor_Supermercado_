#include "Admin.h"

Admin::Admin(int id, float salary, string name, string duties) :Employee(id, salary, name)
{
	this->duties = duties;
}

Admin::Admin():Employee()
{
}

void Admin::showInfo()
{
	Employee::showInfo();
	cout << "duties:" << duties<<endl;
}

void Admin::setDuties(string duties)
{
	this->duties = duties;
	
}

void Admin::setSalary(float salary)
{
	this->salary = salary;
}

void Admin::setName(string name)
{
	this->name = name;
}

void Admin::setId(int id)
{
	this->id = id;
}
