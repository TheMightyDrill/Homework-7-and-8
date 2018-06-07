//LIFO (last in first out)

/*Stack

A data structure in which elements are added
and removed from one end
only.

*/

#include "Node.h"

template<class Type>
class StackType {

	int maxSize;
	int size;
	Node<Type>* head;

public:

	StackType() {

		this->maxSize = 99; //default

		cout << "Creating stack..." << endl;
		system("pause");
		system("CLS");
		initializeStack();
	}

	StackType(const StackType<Type>* otherStack) {
		copyStack();
	}

	void initializeStack() {
		this->head = 0;
		size = 0;
	}

	//push (add)
	void push(Type info) {
		if (this->size <= this->maxSize) {
			Node<Type>* temp = new Node<Type>();

			temp->setInfo(info);
			temp->setNext(this->head);
			this->head = temp;

			size++;
		}
		else {
			cout << "Stack is full..." << endl;
			system("pause");
		}
	}
	//push (other stack info) (only works with 1 I believe...
	void push(Node<Type>* info) {
		if (this->size <= this->maxSize) {

			info->setNext(this->head);
			this->head = info;

			size++;
		}
		else {
			cout << "Stack is full..." << endl;
			system("pause");
		}
	}

	//pop (remove top element)
	void pop() {

		if (this->head != NULL) {
			Node<Type>* temp = head;
			if (head->getNext() != NULL) {
				this->head = head->getNext();
			}
			else {
				this->head = 0;
			}
			//delete temp; /*Try to fix this at some point...*/
			size--;
		}

	}
	//isFullstack (checks if full)
	bool isFullStack() {
		if (this->size == this->maxSize) {
			return true;
		}
		else {
			return false;
		}

		return false;
	}
	//isEmptyStack (checks if empty)
	bool isEmptyStack() {
		if (this->size == 0) {
			return true;
		}

		return false;
	}

	int getSize() {
		return this->size;
	}
	int getMaxSize() {
		return this->maxSize;
	}
	//returns address of top item in stack
	Node<Type>* top() {
		return this->head;
	}

	//copies other stack into this one
	void copyStack(StackType<Type>& otherStack) {

		int x = this->size;

		//delete current stack info
		for (int i = 0; i < x; i++) {
			this->pop();
		}

		this->head = 0;

		this->size = otherStack.getSize();
		this->maxSize = otherStack.getMaxSize();


		Node<Type>* temp;
		temp = otherStack.top();

		this->head = temp;

	}

	StackType<Type>& operator=(StackType<Type>& oStack) {
		if (this == &oStack) {
			return *this;
		}

		copyStack(oStack);
	}

	//Challenge #3 function operation

	void reverseStack(StackType<Type> &otherStack) {
		this->maxSize = otherStack.getMaxSize();

		//clear this stack
		for (int i = 0; i < this->size; i++) {
			this->pop();
		}

		for (int i = 0; i < otherStack.getSize(); i++) {


			Node<Type>* temp;
			Node<Type>* getInf;

			getInf = otherStack.top(); //getInfo holds the address of the otherstack's head
			for (int j = i; j > 0; j--) {
				getInf = getInf->getNext();
			}//this loop should run through the linked list of the other stack...

			temp = new Node<Type>(getInf->getInfo()); //creates a new ptr that holds the address of the info from the old ptr


													  //pushes the ptr into this objects linked list thing
			this->push(temp);


		}
	}
};
#pragma once
