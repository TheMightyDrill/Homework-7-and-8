#pragma once

#include <string>
#include <iostream>

using namespace std;

class Customer {
	string name;
	int id;
public:
	Customer();

	Customer(string, int);

	/*FUNCTIONS*/
	void newCustomer();

	void displayAllInformation();

	/*SET GET*/
	void setName(string);

	string getName();

	void setId(int id);

	int getId();

	/*PRINT*/
	void print();

};
