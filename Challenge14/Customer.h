#pragma once

#include <string>
#include <iostream>
#include "QueueType.h"

using namespace std;

class Customer {
	string name;
	int id;
	QueueType<string> rentedVideos;
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

	/*QUEUE MANIPULATION*/

	void rent(string name) {
		rentedVideos.add(name);
	}

	void displayRentedVideos() {
		rentedVideos.print();
	}

	/*PRINT*/
	void print();

};
