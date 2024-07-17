#pragma once
#include <iostream>

using namespace std;

enum Clienttype {
	REGULAR,
	PREMIUM,
	VIP
};



class Client
{
private:
	string name;
	Clienttype type;
	int nit;
public:
	Client(string name, int nit, Clienttype type);
	Client(string name, int nit);
	void showInfo();
	string getName();
};

