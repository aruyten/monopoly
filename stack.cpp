#include "stack.hpp"


stack::stack() {

	tos = new Node;
	bottom = tos;
}


stack::stack(const stack& actual) {

	Node* temp = actual.tos;

	tos = 0;


	tos = new Node(temp->data, temp->name);
	bottom = tos;
	temp = temp->next;

	while (temp != actual.tos) {
		bottom->next = new Node(temp->data, temp->name);
		bottom = bottom->next;
		temp = temp->next;
	}
	bottom->next = tos;
}


stack::~stack() {

	Node* temp;

	while (tos != 0) {

		temp = tos;
		tos = tos->next;
		delete temp;
	}
}



void stack::swap(stack& actual) {

	Node* temp = tos;
	tos = actual.tos;
	actual.tos = temp;

	temp = bottom;
	bottom = actual.bottom;
	actual.bottom = temp;
}




stack& stack::operator=(stack actual) {
	swap(actual);
	return*this;
}




bool stack::empty() const {

	if (tos->next == 0)
		return true;
	return false;
}



bool stack::full() const {

	Node* ptr = new Node;

	if (ptr == 0)
		return true;

	delete ptr;
	return false;
}



Node* stack::top() const {
	return tos;

}

int stack::pop() {

	int temp = tos->data;
	Node* hold = tos;
	tos = tos->next;
	delete hold;

	bottom->next = tos;
	return temp;
}


void stack::push(const int& value) {

	Node* temp;

	new Node;
	temp = new Node(value);

	temp->next = tos;
	tos = temp;
	bottom->next = tos;
}


void stack::push(const int& value, const std::string str) {

	Node* temp;

	new Node;
	temp = new Node(value, str);

	temp->next = tos;
	tos = temp;
	bottom->next = tos;
}


int stack::value(Node* node) const {
	return node->data;
}


std::string stack::name(Node* node) const {
	return node->name;
}


void stack::addValue(Node* node) {
	node->data = node->data + 1;
}