#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#include "Node.h"
#include "UnorderedLinkedListType.h"
#include "Customer.h"
#include "CustomerListType.h"

//LIFO (last in first out)

/*Stack

A data structure in which elements are added
and removed from one end
only.

*/
template<class Type>
class StackType{

	int maxSize;
	int size;
	Node<Type>* head;

public:

	StackType() {

		cout << "Stack size: ";
		cin >> maxSize;
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
		this->size = otherStack.getSize();
		this->maxSize = otherStack.getMaxSize();

		//clear this stack
		for (int i = 0; i < this->size; i++) {
			this->pop();
		}

		for (int i = 0; i < otherStack.getSize(); i++) {
			this->push(otherStack.top());
		}
	}
};

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
	QueueType(){
		this->size = this->maxSize = 0;
		cout << "Queue size: ";
		cin >> maxSize;

		front = 0;
		back = 0;
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
		while (temp->getNext()->getNext() != 0){
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

int main() {

	StackType<int> list;
	StackType<int> secondlist;

	list.push(1);
	list.push(2);
	list.push(3);

	secondlist.reverseStack(list);

	system("Pause");
	return 0;
}

