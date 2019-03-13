#include <iostream>
#include <string>

#include "table.h"

// Constructor
Table::Table(int number, int numberOfSeats) {
	seats = numberOfSeats;
	bill = 0;
	tableNumber = number;	// Number of the table is equal to its possition at the tables list.
	next = NULL;
	client = NULL;
}

Table::~Table() {
	cout << "Table number " << tableNumber << " destroyed." << endl;
	next = NULL;
	client = NULL;
}

void Table::addClient(Client *client) {
	if (this->client == NULL) {
		this->client = client;
		cout << "Table found." << endl;
	}
	else {
		cout << "This table is taken. Can not add client." << endl;
	}
}

void Table::removeClient() {
	if (this->client != NULL) {
		client = NULL;
		bill = 0;
	}
	else {
		cout << "There is no client at the table." << endl;
	}
}

bool Table::isTaken() {
	if (client == NULL)
		return false;
	return true;
}

void Table::print() {
	cout << "Table number: " << tableNumber << endl;
	cout << "Number of seats: " << seats << endl;

	if (client == NULL) {
		cout << "Free." << endl;
	}
	else {
		cout << "Taken." << endl;
		cout << "Bill: " << bill << endl;
	}
}