#pragma once

using namespace std;


// Client means one person or the group of people who came together to the restaurant.

class Client {
	int numberOfPeople;
	bool paid;	// defines if the client is at the restaurant now.

	struct orderList {
		int orderNumber;
		orderList *next;
	};
	orderList *head;

public:
	Client(int numberOfPeople); // head = NULL;
	~Client();	// Deletes orderList. 
	void print();
	void printMyOrders();
	bool isPaid() { return paid; };
	void goToRestaurant() { paid = false; };

	int getPeopleNumber() { return numberOfPeople; };
	void pay();
	void order(int orderNb);
	int getOrder(int counter);
	bool orderListFree();
	void takeOrder();
};