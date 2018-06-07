#include <string>
#include <iostream>
#include "Customer.h"

using namespace std;

Customer::Customer() {
	name = "NA";
	id = -1;
}

Customer::Customer(string name, int id) {
	this->name = name;
	this->id = id;
}

void Customer::newCustomer() {
	system("CLS");
	cout << "~~Creating new customer~~" << endl;
	string name = "";
	int id = -1;

	cout << "Name: ";
	cin >> name;
	cin.clear();

	cout << "Id: ";
	cin >> id;

	this->name = name;
	this->id = id;
	cout << "Customer created..." << endl;
	system("Pause");
}

void Customer::displayAllInformation() {
	cout << "Name: " << this->name << endl;
	cout << "Id: " << this->id << endl;
	system("pause");
}

void Customer::setName(string name) {
	this->name = name;
}

string Customer::getName() {
	return this->name;
}

void Customer::setId(int id) {
	this->id = id;
}

int Customer::getId() {
	return this->id;
}

void Customer::print() {
	cout << "Name: " << this->name << endl;
}