#pragma once

//#include "staff.h"
#include "waiter.h"
#include "cook.h"
#include "client.h"
#include "dish.h"
#include "table.h"

using namespace std;
//using std::endl;

#define DEFAULT_TABLES 4
#define DEFAULT_SEATS 4

class Restaurant {
	string name;
	string location;
	int phone;
	int tables;	// defines number of tables.
	int seatsNumber;
	int income;

	Waiter *wHead;	// List of all waiters
	Cook *cHead;	// List of all cooks
	Table *tHead;	// List of all tables
	Dish *menu;	// Menu list

private:
	Table * findFreeTable();
	Table* findTable(Client *c);	// Finds free table with enough numer of seats at it.
	bool findWaiter(Table *t);	// Finds waiter who has the least tables to serve.
	Dish* findDish(int dishNumber);	//private.
	Cook* findCook();
	void freeWaiter(Table *t);
	bool checkDish(string name);
	Table* checkClient(Client *c);
	void changeNumbers();	//changing numbers of dishes after removing a dish.


public:
	Restaurant(string name, string location, int phone, int tables = DEFAULT_TABLES, int seatsNumber = DEFAULT_SEATS);
	~Restaurant();	// Deletes all lists. 

	void showResturant();	// Prints info about the restaurant.

	// Methods connected to tables.

	void createRestaurant();	// Create tables (amout = tables, seats number at the table = seatsNumber);
	void addDefaultTables(int amount);	// Adds tables with number of seats = seatsNumber 
	void addTables(int amount, int seats);	// Adds "amout" number of tables of "seats" number of seats.
	void removeTable(int seats);	// Remove table with particular number of seats.
	void printTables();

	void changeNumberOfAllSeats(int seats);	// Change number of seats at all tables to "seats".

	// Methods conneted to client.
	void addNewClient(Client *c);	// Adds new client to the restaurant.
	
	void takeOrder(Client *c);	// Prepare client's oreders.

	void takePayment(Client *client);
	int checkOrder(int number);	// Checks if ordered dish is in the restaurant's menu.

	// Methods connected to menu. 
	void changeCook(int dishNumber, Cook *c);	// Changes cook of dish number "dishNumber" into "c".
	void changeCook(int dish);

	void changePrice(int dishNumber, int newPrice);	// Change price of dish number "dishNumber" into "newPrice".
	
	void printMenu();
	void printDish(int dishNumber);
	void removeDish(int dishNumber);

	void addDish(string dishName, int price);	// Creates new dish of name = "dishName" and price = "price" and adds it into menu.

	void hireWaiter(Waiter *w);
	bool checkWaiter(Waiter *w);	// Checks if there is such waiter working at the restaurant.

	void hireCook(Cook *c);
	bool checkCook(Cook *c);	// Checks if there is such cook working at the restaurant.

	void fireWaiter(Waiter *w);
	void fireCook(Cook *c);

	bool checkWaiter(int ID);
	bool checkCook(int ID);

	void printWaitersList();
	void printCooksList();

	void addIncome(Waiter *w);	// Adds w's income into restaurant's income and reset w's income then.
	void countIncome();	// Count total income of all waiters.

	// Template to change salary of cook and waiter.
	template <class T>
	void changeSalary(T *worker, int salary);

	// Tamplates to remove elemant form list.

	template <class T>
	void removeFromHead(T *head);

	template <class T>
	bool  removeFromEnd(T *toRemove);

	template <class T>
	bool removeElement(T *toRemove);

	template <class T>
	void removeStaff(T *employee, T *shead);
};
