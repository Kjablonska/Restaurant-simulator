#include <iostream>
#include <string>

#include "dish.h"

using std::cout;
using std::endl;
using namespace std;


Dish::Dish(string dish, int price, int number, Cook *cook) {
	this->number = number;
	this->dish = dish;
	this->price = price;
	this->cook = cook;
	this->next = NULL;
}

Dish::~Dish() {
	cook = NULL;
	next = NULL;
}

void Dish::print() {
	cout << number << ". " << dish << endl;
	cout << "Price: " << price << endl;
}