#pragma once

#include "staff.h"
#include "table.h"

using namespace std;
//class Staff;

#define WAITERS_SALARY 3000

class Waiter : public Staff {
	int numberOfTables;
	Waiter *next;
	int income;

	struct myTables {
		Table *table;
		myTables *next;
	};
	myTables *head;

public:
	Waiter(string name, int age, int id, int salary = WAITERS_SALARY, bool employed = false);
	~Waiter();

	void printMyTables();
	void addTable(Table *t);

	void removeTable(Table *t);
	void removeAllTables();
	void resign(Restaurant *r);	// Resign from work.

	void setNext(Waiter *w) { next = w; };
	void setTablesNumber() { numberOfTables++; };
	int getTablesNumber() { return numberOfTables; };
	int getIncome() { return income; };
	void resetIncome() { income = 0; };
	bool findTable(Table *t);	// Checks if the waiter has table t in myTables list.
	Waiter* getNext() { return next; };

	bool removeFromHead(myTables *current);
	bool removeFromEnd(myTables *current);
	bool removeElement(myTables *current);
};