#include "CustomerListType.h"
#include "UnorderedLinkedListType.h"

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void CustomerListType::createCustList() {
	int numOfCustomers;
	string tempName;
	tempCust = new Customer();

	inputfile.open(fileName);

	inputfile >> numOfCustomers;
	inputfile << endl;

	for (int i = 0; i < numOfCustomers; i++) {

		inputfile >> tempName;
		tempCust->setName(tempName);
		this->insert(*tempCust);
		inputfile << endl;
	}

	inputfile.close();

	cout << "Customers added" << endl;
	cout << endl;
	delete tempCust;
	tempCust = 0;
}

void CustomerListType::addCustomer() {
	string tempName;
	tempCust = new Customer();

	cout << "New Customer name: ";
	cin.clear();
	getline(cin, tempName);

	tempCust->setName(tempName);

	this->insert(*tempCust);

	cout << "Customer added" << endl;
	cout << endl;

	numberOfCustomers++;
	delete tempCust;
	tempCust = 0;

	//add to new file

	outputfile.open(outputFileName);
	outputfile << numberOfCustomers << endl;

	for (int i = 0; i < numberOfCustomers; i++) {
		outputfile << this->getAt(i)->getInfo().getName();
		outputfile << endl;
	}

	outputfile.close();

}