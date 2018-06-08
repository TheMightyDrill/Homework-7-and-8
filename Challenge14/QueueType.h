#pragma once

#include "Node.h"



//FIFO (First in firsto out)
//elements are added at one end (back, rear)
//elements are deleted (front)
template<class Type>
class QueueType {

	int size;
	int maxSize;
	Node<Type>* front;
	Node<Type>* back;

public:

	//constructor
	QueueType() {
		this->size = this->maxSize = 0;
		
		maxSize = 15; //default size

		front = 0;
		back = 0;
	}

	//prints entire queue
	void print() {

		Node<Type>* temp;
		temp = back;

		while (temp != 0) {

			cout << temp->getInfo() << endl;

			temp = temp->getNext();
		}

		delete temp; //no leaks
	}

	//addQueue (Adds new element to the rear of que)
	void add(Type info) {

		if (this->back == 0) {
			back = new Node<Type>(info);
			this->front = back;
			size++;
			return;
		}

		Node<Type>* temp = new Node<Type>(info);

		//this->front = back;
		temp->setNext(this->back);
		this->back = temp;//temp address is the new element at the rear of the line
		size++;
	}
	//deleteQueue (queue must exist, and not be empty. Removes front element)
	void deleteFront() {

		Node<Type>* temp = this->back;
		while (temp->getNext()!= 0) {
			temp = temp->getNext();
		}

		front = temp; //sets last element as the temp address which should be 1 before the last...

		temp = temp->getNext(); //last element

		delete temp; //removes last element address

		front->setNext(0);

		size--; //updates counter
	}
	//isEmptyQueue (returns bool, the que is full or not)
	bool isEmptyQueue() {
		if (this->size == 0) {
			return true;
		}

		return false;
	}
	//isFullQueue (returns bool, the que is full or not)
	bool isFullQueue() {
		if (this->size == maxSize) {
			return true;
		}

		return false;
	}
	//initializeQueue (initializes que into empty state)
	void initializeQueue() {
		this->front = 0;
		this->back = 0;
		size = 0;
		maxSize = 99; //default size

	}

	//front (recieves front of que)
	Node<Type>* returnFront() {
		return this->front;
	}
	//back (recieves back of que)
	Node<Type>* returnBack() {
		return this->back;
	}

	//

};
