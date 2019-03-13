#include <iostream>
#include <string>

//#include "staff.h"
#include "cook.h"
#include "restaurant.h"

using namespace std;


Cook::Cook(string name, int age, int id, int salary, bool employed) : Staff(name, age, id, salary, employed) {
	next = NULL;
	numberOfDishes = 0;
}

Cook::~Cook() {
	numberOfDishes = 0;
}

void Cook::resign(Restaurant *r) {
	if (r == NULL) {
		cout << "There is no such restaurant." << endl;
	}
	else {
		r->fireCook(this);
	}
}