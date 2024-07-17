#pragma once
#include "Employee.h"
#include <iostream>
#include <string>

using namespace std;

class Admin :
    public Employee
{
private:
    string duties;


public:
    Admin(int id, float salary, string name, string duties);
    Admin();
    void showInfo();
    void setDuties(string duties);
    void setId(int id);
    void setSalary(float salary);
    void setName(string name);


};