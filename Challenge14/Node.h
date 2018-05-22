#pragma once

template <class Type>
class Node {
	Type info;
	Node<Type>* next;
	Node<Type>* previous;
public:
	//default constructor
	Node() {
		this->next = 0;
		this->previous = 0;
	}
	//second constructor
	Node(Type info) {
		this->next = 0;
		this->previous = 0;
		this->info = info;
	}

	Type getInfo() {
		return info;
	}

	Node<Type>* getNext() {
		return this->next;
	}

	/*SET*/
	void setNext(Node<Type>* next) {
		this->next = next;
	}

	void setPrev(Node<Type>* prev) {
		this->previous = prev;
	}

	void setInfo(Type info) {
		this->info = info;
	}
	/*SET*/

};