#include <iostream>
#include <string>

#include "client.h"

Client::Client(int numberOfPeople) {
	this->numberOfPeople = numberOfPeople;
	paid = true;
	head = NULL;
}

Client::~Client() {
	orderList *current = head;

	while (current) {
		current = current->next;
		delete head;
		head = current;
	}

	head = NULL;
}

void Client::print() {
	cout << "		Client" << endl;
	cout << "Number of people: " << numberOfPeople << endl;
}

void Client::printMyOrders() {
	orderList *current = head;

	if (head != NULL) {
		cout << "	Client's orders" << endl;

		while (current != NULL) {
			cout << current->orderNumber << "	";
			current = current->next;
			
		}
		cout << endl;
	}
	else {
		cout << "Client has no orders." << endl;
	}
}


// Jesli coœ zosta³o nieprzygotowane nie mo¿na zap³aciæ (orderList musi byæ pusta).
void Client::pay() {
	paid = true;
}

void Client::order(int orderNb) {
	orderList *current = new orderList;
	current->orderNumber = orderNb;
	current->next = head;
	head = current;
	paid = false;
	cout << "You have ordered dish number: " << orderNb << endl;
}

int Client::getOrder(int counter) {
	int i = 0;
	orderList *current = head;

	while (current != NULL && i < counter) {
		current = current->next;
		i++;
	}

	if (current == NULL) {
		return -1;
	}

	return current->orderNumber;
}

bool Client::orderListFree() {
	if (head == NULL) {
		return true;
	}
	return false;
}

// Removes orders form myOrders list. Bill is increased.
void Client::takeOrder() {
	orderList *current = head;

	while (current) {
		current = current->next;
		delete head;
		head = current;
	}
}