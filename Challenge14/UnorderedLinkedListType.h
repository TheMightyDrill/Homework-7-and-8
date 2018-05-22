#pragma once

#include "Node.h"

template <class Type>
class UnorderedLinkedListType {
	int size;
	Node<Type>* head;
	Node<Type>* tail;

public:
	UnorderedLinkedListType() {
		size = 0;
		head = 0;
		tail = 0;
	}

	void insert(Type info) {

		//check if header exists

		if (head == 0) {
			head = new Node<Type>(); //create new node
			head->setInfo(info); //insert info to node
			tail = head;
			size++;
			return;
		}

		//if head exists
		Node<Type>* temp;//create temp node
		temp = new Node<Type>();

		temp->setNext(head);
		temp->setInfo(info);
		head->setPrev(temp);

		head = temp;
		tail->setNext(head);

		size++;

	}

	/*Get*/

	int getSize() {
		return this->size;
	}

	Node<Type>* getHead() {
		return this->head;
	}

	Node<Type>* getTail() {
		return this->tail;
	}

	Node<Type>* getAt(int pos) {
		Node<Type>* temp;
		temp = this->head; //starts at head address position
		for (int i = 0; i < pos; i++) {
			temp = temp->getNext();
		}

		return temp;
	}

	virtual void print() = 0;


};