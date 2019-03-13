#include <iostream>
#include <string>

#include "staff.h"
//#include "restaurant.h"

using namespace std;


Staff::Staff(string name, int age, int ID, int salary, bool employed = false) {
	this->name = name;
	this->age = age;
	this->ID = ID;
	this->salary = salary;
	this->employed = employed;
}

Staff::~Staff() {

}

void Staff::print() {
	cout << "Name: " << name << endl;
	cout << "Age: " << age << endl;
	cout << "ID: " << ID << endl;
	cout << "Salary: " << salary << endl << endl;
}