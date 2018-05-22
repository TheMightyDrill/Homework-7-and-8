#pragma once

#include "UnorderedLinkedListType.h"
#include "Customer.h"

#include <fstream>

class CustomerListType : public UnorderedLinkedListType<Customer>
{
	Customer* tempCust;
	int numberOfCustomers;
	string fileName;
	string outputFileName;
	fstream inputfile;
	ofstream outputfile;

public:

	CustomerListType(string fileName, string outputFileName) : UnorderedLinkedListType() {

		this->fileName = fileName;
		inputfile.open(fileName);
		inputfile >> numberOfCustomers;
		inputfile.close();

		this->outputFileName = outputFileName;

		cout << "Customer List Created" << endl;
		system("pause");
	}

	void createCustList();

	void addCustomer();

	virtual void print() {

		for (int i = 0; i < this->getSize(); i++) {
			getAt(i)->getInfo().print();
		}
	}
};
