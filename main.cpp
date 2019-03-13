#include <iostream>
#include <string>


#include "waiter.h"
#include "cook.h"
#include "client.h"
#include "dish.h"
#include "table.h"
#include "restaurant.h"
//#include "staff.h"


using namespace std;
using std::endl;


int main() {
	Restaurant *r = new Restaurant("MEAT", "Warsaw", 12345678);
	r->showResturant();
	r->createRestaurant();

	r->countIncome();	// Should be 0.

	Restaurant *v = new Restaurant("VEGE", "Cracow", 87654321);
	v->createRestaurant();
	v->showResturant();

	/**
	cout << endl << "	TESTING METHIDS CONNECTED TO TABLES" << endl;
	r->printTables();

	r->changeNumberOfAllSeats(5);
	r->printTables();

	r->addTables(2, 3);
	r->printTables();

	r->removeTable(3);
	r->printTables();
	*/

	/**
	cout << endl << "	CHECKING METHDS CONNECTED TO HIRING/ FIRING STAFF" << endl << endl;
	r->printWaitersList();	// Should be empty.
	r->printCooksList();	// Should be empty.

	cout << endl << "*********** WAITERS ***********" << endl << endl;
	Waiter *w1 = new Waiter("Bob", 33, 1234);
	r->hireWaiter(w1);
	r->changeSalary(w1, 4000);

	r->printWaitersList();
	r->hireWaiter(w1);	// Should not be added.
	r->printWaitersList();	// There should be w1 once on the list.

	r->fireWaiter(w1);
	r->printWaitersList();	// Should be empty.
	r->hireWaiter(w1);	// Hiring the w1 again.
	r->printWaitersList();

	w1->resign(r);	// Should be removed from the list.
	r->printWaitersList();	// Should be empty.


	r->hireWaiter(w1);

	Waiter *w2 = new Waiter("Andy", 19, 3028);
	r->hireWaiter(w2);

	Waiter *w3 = new Waiter("Alex", 21, 5417);
	r->hireWaiter(w3);

	r->printWaitersList();	// Should contain w1, w2 and w3.

	r->fireWaiter(w2);	// Remvoing from the middle of the list.
	r->fireWaiter(w1);	// Removing from the end;
	r->fireWaiter(w3);	// Removing from the head.

	r->printWaitersList();	// Should be empty.

	v->hireWaiter(w1);
	r->hireWaiter(w1);	// Shoud not be hired.

	cout << endl << "*********** COOKS ***********" << endl << endl;

	Cook *c1 = new Cook("Ben", 34, 4789);

	r->hireCook(c1);

	r->printCooksList();
	r->hireCook(c1);	// Should not be added.
	r->printCooksList();	// There should be w1 once on the list.

	r->fireCook(c1);
	r->printCooksList();	// Should be empty.
	r->hireCook(c1);	// Hiring the w1 again.
	r->printCooksList();

	c1->resign(r);	// Should be removed from the list.
	r->printCooksList();	// Should be empty.
	
	
	r->hireCook(c1);
	Cook *c2 = new Cook("Mat", 37, 56789);
	r->hireCook(c2);

	Cook *c3 = new Cook("Max", 35, 7892);
	r->hireCook(c3);

	r->printCooksList();	// Shoud contain c1, c2 and c3.

	r->fireCook(c2);	// Removing cook from the middle of the list.
	r->fireCook(c1);	// Removing cook from the end of the list.
	r->fireCook(c3);	// Removing from the head.

	r->printCooksList();	// Should be empty.

	v->hireCook(c1);
	r->hireCook(c1);	// Shoud not be hired.
	
	*/
	
	/**
	cout << endl << "		CHECKING METHIDS CONNECTED TO THE MENU." << endl << endl;
	Cook *c1 = new Cook("Ben", 34, 4789);
	r->hireCook(c1);

	r->addDish("vege", 18);
	r->addDish("meat", 16);

	r->printMenu();

	r->printMenu();
	
	Cook *c2 = new Cook("Mat", 37, 56789);
	r->hireCook(c2);	// One of the dishes should be now prepared by c2.

	r->fireCook(c1);

	r->removeDish(1);

	r->printMenu();

	r->removeDish(1);	// All dishes removed from the menu.

	r->printMenu();
	
	r->fireCook(c2);	// Now the resturant has no cooks.

	
	r->printMenu();	// Menu should be inaccessible, but still should be printed of there are any dishes.
	r->hireCook(c1);	// Dishes shoud be assigned to the cook c1

	delete r;
	
	*/
	
	/**
	cout << endl << "		CHECKING METHIDS CONNECTED TO THE CLIENT. " << endl << endl;

	cout << endl << "***************   TEST 1    ***************" << endl << endl;

	r->removeTable(4);	// Removing all tables.

	Client *c = new Client(3);
	r->addNewClient(c);	// Should not be added because there are no tables at the restaurant.
	r->addDefaultTables(4);	// Adding 4 tables.

	r->addNewClient(c);
	

	cout << endl << "****************************************" << endl << endl;
	Waiter *w4 = new Waiter("Dave", 21, 4207);
	r->hireWaiter(w4);

	Waiter *w5 = new Waiter("Adam", 30, 5190);
	r->hireWaiter(w5);
	cout << endl << "****************************************" << endl << endl;
	r->countIncome();	// Should be zero.

	r->printWaitersList();

	Cook *c4 = new Cook("Walt", 35, 2805);
	r->hireCook(c4);

	r->addDish("chicken", 19);
	r->addDish("soda", 8);
	r->addDish("beef", 26);

	r->printMenu();
	Cook *c6 = new Cook("Alex", 55, 4901);
	v->hireCook(c6);

	Waiter *w6 = new Waiter("Reachel", 23, 1029);
	v->hireWaiter(w6);

	v->printWaitersList();

	cout << endl << "***************   TEST 2   ***************" << endl << endl;

	v->addNewClient(c);	// Should be added.
	r->addNewClient(c);	// Should not be added because c is a client of v at the moment.

	r->takeOrder(c);	// c is not a client of r! 

	v->takeOrder(c);
	v->takePayment(c);

	r->addNewClient(c);	// c left v restaurant, so r can take him now.

	c->order(2);
	c->order(3);
	
	r->takePayment(c);	// Can not take payment if the client did not get his orders.

	r->takeOrder(c);
	r->takePayment(c);

	Client *b = new Client(2);
	r->addNewClient(b);

	b->order(1);
	r->takeOrder(b);
	r->takePayment(b);

	r->countIncome();

	r->countIncome();

	cout << endl << "***************   TEST 3   ***************" << endl << endl;
	Client *p = new Client(2);
	r->addNewClient(p);	// Should be added.

	p->order(1);

	r->fireCook(c4);	// Fire cook responsible for dish number 1.

	r->takeOrder(p);
	r->takePayment(p);

	r->countIncome();
	
	r->hireCook(c4);	// c4 should be responsible for all dishes at the menu now.
	r->takeOrder(p);	// p should get his order.

	p->printMyOrders();	// Should be empty.

	p->order(2);
	p->order(3);



	r->takeOrder(p);	// Taking more than one order.
	p->printMyOrders();	// Should be empty.

	p->order(7);	// There is no such dish at the menu.
	r->takeOrder(p);
	r->takePayment(p);
	
	cout << endl << "***************   TEST 4   ***************" << endl << endl;
	
	// Adding client who has more people than the biggest table at the restaurant.

	Client *e = new Client(6);
	r->addNewClient(e);	// Should not be added.

	r->addTables(1, 6);
	r->printTables();

	r->addNewClient(e);	// Should be added.


	cout << endl << "***************   TEST 5   ***************" << endl << endl;


	Client *f = new Client(1);
	r->addNewClient(f);

	Client *g = new Client(3);
	r->addNewClient(g);

	Client *h = new Client(3);
	r->addNewClient(h);

	Client *i = new Client(4);
	r->addNewClient(i);	// Shoud not be added. There are no free tables.

	r->countIncome();
	
	e->order(1);
	f->order(1);
	g->order(2);
	h->order(2);
	i->order(1);

	r->takeOrder(e);
	r->takeOrder(f);
	r->takeOrder(g);
	r->takeOrder(h);

	r->takeOrder(i);	// Should not be done. i is not a client of r.


	r->takePayment(e);
	r->takePayment(f);
	r->takePayment(g);
	r->takePayment(h);

	r->takePayment(i);	// Should not be done. i is not a client of r.

	r->takeOrder(e);	// Should not be done. e is not a client of r now.
	

	cout << "INCOME OF THE RESTAURANT" << endl;
	r->countIncome();

	*/

	return 0;
}