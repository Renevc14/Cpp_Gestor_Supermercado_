#include "Employee.h"

Employee::Employee(int id, float salary, string name)
{
	this->id = id;
	this->salary = salary;
	this->name = name;

}

Employee::Employee()
{
}

void Employee::showInfo()
{
	cout << "ID: " << id << endl;
	cout << "Salary: " << salary << endl;
	cout << "Name: " << name << endl;
	return;
}
