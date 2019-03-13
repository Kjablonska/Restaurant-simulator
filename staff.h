#pragma once

//#include "restaurant.h"

using namespace std;
class Restaurant;

class Staff {
	string name;
	int age;
	int ID;
	int salary;
	bool employed;

public:
	Staff(string name, int age, int ID, int salary, bool employed);
	~Staff();

	void print();
	int getSalary() { return salary; };
	void changeSalary(int salary) { this->salary = salary; };
	bool isEmployed() { return employed; }	// Changed status of employment to true.
	void changeSatus(bool employed) { this->employed = employed; };
	int getID() { return ID; };
};