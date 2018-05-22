#pragma once

#include <string>
#include <iostream>

using namespace std;

class Customer {
	string name;
public:
	Customer();

	Customer(string, string, bool);

	void setName(string);

	string getName();

	void print();

};
