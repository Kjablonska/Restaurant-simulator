#pragma once
#include <string.h>
#include "client.h"

using namespace std;

class Table {
	Client *client;
	int tableNumber;
	int seats;
	int bill;

	Table *next;

public:
	Table(int number, int numberOfSeats);
	~Table();
	void increaseBill(int price) { bill += price; };
	int getBill() { return bill; };
	void addClient(Client *client);
	void removeClient();
	bool isTaken();
	Table* getNext() { return next; };
	void setNext(Table *t) { next = t; };
	int getSeats() { return seats; };
	void changeSeats(int newSeats) { seats = newSeats; };
	void print();
	Client* getClient() { return client; };
};