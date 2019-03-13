#pragma once
#include <string>
#include "cook.h"

using std::cout;
using std::endl;
using namespace std;

class Dish {
	std::string dish;
	int number;	// Number is dishes possition at the menu.
	int price;

	Cook *cook;
	Dish *next;

public:
	Dish(string dish, int price, int number, Cook *cook);
	~Dish();

	void addCook(Cook *c) { cook = c; };
	void print();
	Dish* getNext() { return next; };
	string getName() { return dish; };
	int getPrice() { return price; };
	Cook *getCook() { return cook; };
	int getNumber() { return number; };
	void setNext(Dish *d) { next = d; };
	void setCook(Cook *c) { cook = c; };
	void setPrice(int newPrice) { price = newPrice; };
	void setNumber(int number) { this->number = number; };
};