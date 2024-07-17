#pragma once
#include <iostream>
using namespace std;
class Employee
{
protected:
	int id;
	float salary;
	string name;
public:
	Employee(int id, float salary, string name);
	Employee();
	void showInfo();

};

