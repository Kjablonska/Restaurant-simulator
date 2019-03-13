#pragma once

#include "staff.h"

using namespace std;
//class Staff;

#define COOKS_SALARY 3000

class Cook : public Staff {
	Cook *next;
	int numberOfDishes;

public:
	Cook(string name, int age, int id, int salary = COOKS_SALARY, bool employed = false);
	~Cook();
	void setNext(Cook *c) { next = c; };
	Cook* getNext() { return next; };
	int getNumberOfDishes() { return numberOfDishes; };
	void addNewDish() { numberOfDishes++; };
	void removeDish() { numberOfDishes--; };

	void resign(Restaurant *r);	// Resign from work at the given restaurant. 
};