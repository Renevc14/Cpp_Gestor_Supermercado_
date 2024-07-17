#pragma once
#include "Employee.h"
#include <iostream>


using namespace std;


class CashRegister;
class Cashier :
    public Employee
{
private:

    int cashRegister;

public:
    Cashier(int id, int salary, string name, int cashRegister);
    Cashier(int id, int salary, string name);
    Cashier();
    string getName();
    void setCashRegister(int cashRegister);
    void setId(int id);
    void setSalary(float salary);
    void setName(string name);
    
};

