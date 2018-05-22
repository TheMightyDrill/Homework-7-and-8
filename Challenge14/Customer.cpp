#include <string>
#include <iostream>
#include "Customer.h"

using namespace std;

Customer::Customer() {
	name = "NA";
}

Customer::Customer(string name, string director, bool inStock) {
	this->name = name;
}

void Customer::setName(string name) {
	this->name = name;
}

string Customer::getName() {
	return this->name;
}

void Customer::print() {
	cout << "Name: " << this->name << endl;
}