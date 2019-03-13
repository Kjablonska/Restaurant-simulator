#include <iostream>
#include <string>

//#include "staff.h"
#include "waiter.h"
#include "restaurant.h"

using namespace std;

Waiter::Waiter(string name, int age, int id, int salary, bool employed) : Staff(name, age, id, salary, employed) {
	numberOfTables = 0;
	income = 0;
	head = NULL;
	next = NULL;
}

Waiter::~Waiter() {
	next = NULL;
	numberOfTables = 0;

	myTables *current = head;
	while (current) {
		current = current->next;
		delete head;
		head = current;
	}

	head = NULL;
}

void Waiter::addTable(Table *t) {
	myTables *newTable = new myTables;
	newTable->table = t;
	newTable->next = head;
	head = newTable;
	numberOfTables++;
}

bool Waiter::findTable(Table *t) {
	myTables *current = head;

	while (current != NULL) {
		if (current->table == t) {
			return true;
		}
		current = current->next;
	}

	return false;
}

void Waiter::removeTable(Table *t) {
	
	if (head == NULL) {
		cout << "The waiter has no tables to serve. Can not remove any table." << endl;
	}
	else {
		myTables *current = head;
		bool removed = false;
		income += current->table->getBill();	// Increasing income.

		if (current->table == t) {
			removed = removeFromHead(current);
		}
		else {
			if (current != NULL) {
				while (current->next != NULL && removed == false) {
					if (current->next->table == t) {
						// Removing from the end.
						if (current->next->next == NULL) {
							removed = removeFromEnd(current);
						}
						// Removing element somewhere in the middle.
						else if (current->next->next != NULL) {
							removed = removeElement(current);
						}
					}
					else {
						current = current->next;
					}
				}
			}
		}

		if (removed == true) {
			cout << "Table removed from waiter " << getID() << " list." << endl;
		}
	}
}

void Waiter::removeAllTables() {
	myTables *current = head;
	while (current) {
		current = current->next;
		delete head;
		head = current;
	}

	head = NULL;
}

bool Waiter::removeFromHead(myTables *current) {
	if (current->next != NULL) {
		head = current->next;
	}
	else {
		head = NULL;
	}
	current->next = NULL;
	delete current;

	return true;
}

bool Waiter::removeFromEnd(myTables *current) {
	myTables *nextEl = current->next;
	nextEl->next = NULL;
	delete nextEl;

	current->next = NULL;

	return true;
}


bool Waiter::removeElement(myTables *current) {
	myTables *nextEl = current->next;
	myTables *nextNextEl = nextEl->next;

	current->next = nextNextEl;
	nextEl->next = NULL;
	delete nextEl;
	nextEl = NULL;

	return true;
}

void Waiter::resign(Restaurant *r) {
	if (r == NULL) {
		cout << "There is no such restaurant." << endl;
	}
	else {
		r->fireWaiter(this);
	}
}


void Waiter::printMyTables() {
	myTables *current = head;

	while (current != NULL) {
		current->table->print();
		current = current->next;
	}
}