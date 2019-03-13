#include <iostream>
#include <string>

#include "restaurant.h"
#define FIRST_DISH  1

// Conctructor.
Restaurant::Restaurant(string name, string location, int phone, int tables, int seatsNumber) {
	this->name = name;
	this->location = location;
	this->phone = phone;
	this->tables = tables;
	this->seatsNumber = seatsNumber;
	income = 0;
	wHead = NULL;
	cHead = NULL;
	tHead = NULL;
	menu = NULL;
}

// Destructor.
// Removes all lists.
Restaurant::~Restaurant() {
	Waiter *w = wHead;

	while (w != NULL) {
		fireWaiter(w);
		w = w->getNext();
	}
	cout << "All waiters romoved" << endl;

	w->removeAllTables();
	cout << "All tables removed" << endl;

	Cook *c = cHead;
	//Cook *prevC = c;
	while (c != NULL) {
		fireCook(c);
		c = c->getNext();
	}
	cout << "All cooks removed" << endl;

	Dish *d = menu;
	while (d != NULL) {
		d = d->getNext();
		delete menu;
		menu = d;
	}

	cout << "All dishes removed" << endl;
	

	Table *t = tHead;
	while (t != NULL && tables > 0) {
		removeTable(t->getSeats());
		t->getNext();
	}
	cout << "All tables removed" << endl;

	wHead = NULL;
	cHead = NULL;
	tHead = NULL;
	menu = NULL;

	cout << "Restaurant " << name << " closed." << endl;
}

void Restaurant::showResturant() {
	cout << "		" << name << endl;
	cout << "Location: " << location << endl;
	cout << "Phone number: " << phone << endl << endl;
}

/****************************************************************
Methods connected to menu.
****************************************************************/

/*
Function creates dishes and add them to the restaurant's menu.
New dish is added at the end of the menu.
*/
void Restaurant::addDish(string dishName, int price) {
	Cook *c = findCook();

	if (c == NULL) {
		cout << "Can not add the dish." << endl;
	}
	else {
		c->addNewDish();
		cout << dishName << " will be prepared by cook of ID: " << c->getID() << endl;
		Dish *current = menu;
		int number = FIRST_DISH;	// Place in the menu.

		if (current == NULL) {
			Dish *d = new Dish(dishName, price, number, c);
			d->setNext(menu);
			menu = d;
		}
		else {
			while (current->getNext() != NULL) {
				number++;
				current = current->getNext();
			}
			number++;

			Dish *d = new Dish(dishName, price, number, c);
			d->setNext(NULL);
			current->setNext(d);
		}
	}
}

/*
Function checks if there already exists such dish in the menu.
*/
bool Restaurant::checkDish(string name) {
	Dish *current = menu;

	while (current != NULL) {
		if (current->getName() == name)
			return true;
	}

	return false;
}



// Function find cook who has at least dishes and return pointer to that cook.

Cook* Restaurant::findCook() {
	if (cHead == NULL) {
		cout << "There are no cooks at the restaurant." << endl;
		return cHead;
	}

	Cook *leastDishes = cHead;
	int least = leastDishes->getNumberOfDishes();
	Cook *current = cHead->getNext();

	while (current != NULL) {
		if (current->getNumberOfDishes() < least) {
			least = current->getNumberOfDishes();
			leastDishes = current;
		}
		current = current->getNext();
	}

	return leastDishes;
}


// Function changes the cook of the dish.

void Restaurant::changeCook(int dishNumber, Cook *c) {
	Dish *current = findDish(dishNumber);

	if (current == NULL) {
		cout << "There is no dish of this number!" << endl;
	}
	else {
		Cook *previousCook = current->getCook();

		if (previousCook != NULL) {
			previousCook->removeDish();
		}

		current->setCook(c);
		c->addNewDish();
		cout << "Cook changed at dish number: " << dishNumber << "." << endl; 
		cout << dishNumber << " will be prepared by the cook of ID: " << c->getID() << endl;
	}
}


// Function searchs for the most suitable cook (who has the least dishes to prepare) and assign it to the dish of dishNumber number.

void Restaurant::changeCook(int dishNumber) {
	Cook *c = findCook();
	changeCook(dishNumber, c);
}

// Function change price of the dish.

void Restaurant::changePrice(int dishNumber, int newPrice) {
	Dish *current = findDish(dishNumber);

	if (current == NULL) {
		cout << "There is no dish of this number!" << endl;
	}
	else {
		current->setPrice(newPrice);
	}

}

void Restaurant::printDish(int dishNumber) {
	Dish *current = findDish(dishNumber);
	current->print();
}

// Function resturns poiter the dish of the given number.

Dish* Restaurant::findDish(int dishNumber) {
	Dish *current = menu;

	while (current != NULL) {
		if (current->getNumber() == dishNumber) {
			return current;
		}
		current = current->getNext();
	}

	return current;
}


void Restaurant::printMenu() {
	if (cHead == NULL) {	// If there are no cooks at the restaurant the menu will sitll be printed but with the additional note.
		cout << "Menu is inaccessible. There are no cooks at the restaurant." << endl;
	}
	if (menu == NULL) {
		cout << "Menu is empty." << endl;
	}
	else {
		Dish *current = menu;

		cout << "~~~~~~~~~~~~~   " << this->name << "'s MENU    ~~~~~~~~~~~~~" << endl;
		while (current != NULL) {
			current->print();
			current = current->getNext();
		}
	}
}

// Function removes dish from the menu and delete it.

void Restaurant::removeDish(int dishNumber) {
	if (dishNumber <= 0) {
		cout << "There is no dish number " << dishNumber << " in the menu." << endl;
	}
	else {
		Dish *current = menu;

		if (current == NULL) {
			cout << "Menu is empty. There is no such dish number " << dishNumber << endl;
		}
		else {
			Cook *c = menu->getCook();
			if (menu->getNumber() == dishNumber) {
				if (c != NULL)
					c->removeDish();

				menu = current->getNext();
				current->setNext(NULL);
				delete current;
				current = NULL;

				cout << "Dish number " << dishNumber << " was removed form menu." << endl;
				changeNumbers();
			}
			else {
				current = menu;
			
				while (current->getNext() != NULL && current->getNext()->getNumber() != dishNumber) {
					current = current->getNext();
				}
				if (current->getNext() == NULL) {
					cout << "There is no dish number " << dishNumber << " in the menu." << endl;
				}
				else {

					if (current->getNext()->getNext() == NULL) {	//checking if the dish to be removed is the least in the menu.
						c = current->getNext()->getCook();
						if (c != NULL)
							c->removeDish();
						current->getNext()->addCook(NULL);
						removeFromEnd(current);
						delete current->getNext();
						//current->setNext(NULL);
					}
					else {
						c = current->getCook();
						if (c != NULL)
							c->removeDish();
						current->getNext()->addCook(NULL);
						removeElement(current);
						delete current->getNext();
						//current->setNext(NULL);
					}

					cout << "Dish number " << dishNumber << " was removed form menu." << endl;
					changeNumbers();	// Changes numbers of dishes as the number of dish represents it possition at the menu.
				}
			}
		}
	}
}

// Function changes number of the dishes so that the number of the dish represents its possition at the menu.

void Restaurant::changeNumbers() {
	Dish *current = menu;
	int possition = FIRST_DISH;

	while (current != NULL) {
		if (current->getNumber() != possition) {
			current->setNumber(possition);
		}
		possition++;
		current = current->getNext();
	}

}



/****************************************************************
Methods connected to waiter.
****************************************************************/

// Function checks if the waiter can be hired - if he exists, does not work at the different restaurant and does not work already at this restaurant.
// Add waiter to the restaurant's waiters list.

void Restaurant::hireWaiter(Waiter *w) {
	if (w != NULL) {
		if (w->isEmployed() == false) {
			if (checkWaiter(w) == false) {
				w->setNext(wHead);
				wHead = w;
				w->changeSatus(true);
				cout << "Waiter hired." << endl;
			}
			else {
				cout << "There already work such waiter." << endl;
			}
		}
		else {
			cout << "Can not hire the waiter. He is a worker of a different restaurant!" << endl;
		}
	}
}


// Function removes waiter from the restaurant's waiters list.

void Restaurant::fireWaiter(Waiter *w) {
	if (w->isEmployed() == true) {
		Waiter *current = wHead;
		int i = 0;

		while (current != w && current != NULL) {
			current = current->getNext();
		}

		if (current == NULL) {
			cout << "There is no waiter of ID: " << w->getID() << " working at the restaurant." << endl;
		}
		else if (wHead == w) {
			addIncome(w);
			wHead = current->getNext();
			current->setNext(NULL);
			w->changeSatus(false);
		}
		else {
			if (w->getTablesNumber() != 0) {
				cout << "The waiter still has tables to serve. Unpossible to fire." << endl;
			}
			else {
				addIncome(w);
				removeStaff(w, wHead);
				w->changeSatus(false);
			}
		}
	}
	else {
		cout << "Waiter is not a worker of the restaurant" << endl;
	}
}

// Function checks if there already works such waiter at the restaurant.

bool Restaurant::checkWaiter(Waiter *w) {
	Waiter *current = wHead;
	
	if (w->isEmployed() == false) {
		return false;
	}

	while (current != NULL && current != w) {
		current = current->getNext();
	}

	if (current == NULL)
		return false;

	return true;
}


void Restaurant::printWaitersList() {
	if (wHead == NULL) {
		cout << "Waiters list is empty." << endl;
	}
	else {
		Waiter *current = wHead;

		cout << name << "'s waiters list:" << endl;
		while (current != NULL) {
			current->print();
			current = current->getNext();
		}
	}
}

// Function searches for the waiter who has the least tables to serve and add to his list given table.

bool Restaurant::findWaiter(Table *t) {
	if (wHead == NULL) {
		cout << "There are no waiters at the restaurant!" << endl;
		return false;
	}
	else {
		Waiter *theBest = wHead;
		Waiter *current = theBest->getNext();

		while (current != NULL) {
			if (current->getTablesNumber() < theBest->getTablesNumber()) {
				theBest = current;
			}
			current = current->getNext();
		}
		cout << "New client will be served by waiter of ID: " << theBest->getID() << endl;
		theBest->addTable(t);
		return true;
	}
}

// Checks if there already works waiter of given ID at the restaurant.

bool Restaurant::checkWaiter(int ID) {
	Waiter *current = wHead;

	while (current != NULL) {
		if (current->getID() == ID)
			return true;
		current = current->getNext();
	}

	return false;
}



/****************************************************************
Methods connected to cook.
****************************************************************/
void Restaurant::hireCook(Cook *c) {
	if (c->isEmployed() == false) {
		if (checkCook(c) == false) {
			c->setNext(cHead);
			cHead = c;
			c->changeSatus(true);
			cout << "Cook hired." << endl;

			// If there are dishes at the menu but all cooks were fired those dishes are assigned to the new cook.
			if (c->getNext() == NULL) {
				Dish *current = menu;
				while (current != NULL) {
					changeCook(current->getNumber(), c);
					current = current->getNext();
				}
			}

			// If there are already working cooks at the restaurant.
			// Finding the cook who has more than 1 dish to make and assign this dish to the new cook.
			else {
				Dish *current = menu;
				while (current != NULL) {
					if (current->getCook()->getNumberOfDishes() > 1) {
						changeCook(current->getNumber());
						break;
					}
					current = current->getNext();
				}
			}

		}
		else {
			cout << "There already work such cook." << endl;
		}
	}
	else {
		cout << "Can not hire the cook. He is a worker of a different restaurant!" << endl;
	}
}

void Restaurant::fireCook(Cook *c) {
	if (checkCook(c) == true) {
		Dish *current = menu;


		if (c->getNumberOfDishes() > 0) {
			while (current != NULL) {
				if (current->getCook() == c) {
					current->addCook(NULL);
				}
				current = current->getNext();
			}
		}

		if (c == cHead) {
			Cook *curr = cHead;
			cHead = curr->getNext();
			curr->setNext(NULL);
			c->changeSatus(false);
		}
		else {
			removeStaff(c, cHead);
			c->changeSatus(false);

			current = menu;
			while (current != NULL) {

				if (current->getCook() == NULL) {
					changeCook(current->getNumber());
				}
				current = current->getNext();
			}
		}
	}
	else {
		cout << "There is no such cook working at the restaurant." << endl;
	}

}



bool Restaurant::checkCook(Cook *c) {
	int id = c->getID();
	Cook *current = cHead;

	while (current != NULL) {
		if (current->getID() == id) {
			return true;
		}
		current = current->getNext();
	}

	return false;
}

void Restaurant::printCooksList() {
	if (cHead == NULL) {
		cout << "Cooks list is empty." << endl;
	}
	else {
		Cook *current = cHead;
		
		cout << name << "'s cooks list:" << endl;
		while (current != NULL) {
			current->print();
			current = current->getNext();
		}
	}
}

bool Restaurant::checkCook(int ID) {
	Cook *current = cHead;

	while (current != NULL) {
		if (current->getID() == ID)
			return true;
		current = current->getNext();
	}

	return false;
}



/****************************************************************
Methods connected to tables.
****************************************************************/
/*
Function creates tables and adds them to the restaurant's tables list.
Number of tables and number od seats at the table are defined by restaurant's constructor.
*/
void Restaurant::createRestaurant() {
	int number = tables;

	while (number != 0) {
		Table *newTable = new Table(number, seatsNumber);
		newTable->setNext(tHead);
		tHead = newTable;
		number--;
		cout << "Table added" << endl;
	}

}

void Restaurant::addDefaultTables(int amount) {
	addTables(amount, seatsNumber);
}


void Restaurant::addTables(int amount, int seats) {
	int counter = amount;
	int number = tables + 1;

	if (amount != 0) {
		tables += amount;
		// seatsNumber means the most seats at the table. 
		// If to be add table has more seats then seatsNumber it must be changed.
		if (seats > seatsNumber) {
			seatsNumber = seats;
		}

		while (counter != 0) {
			Table *newTable = new Table(number, seatsNumber);
			newTable->setNext(tHead);
			tHead = newTable;
			counter--;
			number++;
			cout << "Table added" << endl;
		}
	}

}


void Restaurant::printTables() {
	Table *current = tHead;

	while (current != NULL) {
		current->print();
		current = current->getNext();
	}
}

// Function searches for the table that could fit the client and has the most suitable seats for the client.

Table* Restaurant::findTable(Client *c) {

	if (tHead == NULL) {
		cout << "There are no tables at the restaurant" << endl;
		return NULL;
	}
	else {
		int seats = c->getPeopleNumber();
		int currSeats;
		Table *theBest = findFreeTable();

		if (theBest == NULL) {
			cout << "There are no free tables." << endl;
			return NULL;
		}

		Table *current = theBest->getNext();

		while (current != NULL) {
			currSeats = current->getSeats();
			if (currSeats == seats) {
				return  current;
			}
			if (currSeats > seats) {
				if (currSeats < theBest->getSeats()) {
					if (current->isTaken() == false)
						theBest = current;
				}
			}
			current = current->getNext();
		}

		if (theBest->getSeats() < seats) {
			cout << "There is no table that could fit the client." << endl;
			return NULL;
		}

		return theBest;
	}
}

// Function finds first free table and returns pointer to it.

Table* Restaurant::findFreeTable() {
	Table *current = tHead;

	while (current != NULL) {
		if (current->isTaken() == false) {
			return current;
		}
		current = current->getNext();
	}

	return NULL;
}


// Function removes table from the restaurant (remove from the list and delete).

void Restaurant::removeTable(int seats) {
	Table *current = tHead;
	Table *roRemove = current;
	
	while (current != NULL) {
		if (tHead->getSeats() == seats) {
			current = current->getNext();
			delete tHead;
			tHead = current;
			tables--;
		}
		else
			break;
	}

	if (current != NULL) {
		while (current->getNext() != NULL) {
			if (current->getNext()->getSeats() == seats) {
				if (current->getNext()->getNext() == NULL) {
					if (current->getClient() == NULL) {
						removeFromEnd(current);
						delete current->getNext();
						tables--;
					}
				}
				else if (current->getNext()->getNext() != NULL) {
					if (current->getClient() == NULL) {
						removeElement(current);
						delete current->getNext();
						tables--;
					}
				}
			}
			current = current->getNext();
		}
	}
}



// Change number of seats at all tables.

void Restaurant::changeNumberOfAllSeats(int seats) {
	Table *current = tHead;
	int number = tables;

	while (number != 0) {
		current->changeSeats(seats);
		current = current->getNext();
		number--;
	}
}


/****************************************************************
Methods connected to client.
****************************************************************/

// Function finds the client table and waiter.

void Restaurant::addNewClient(Client *c) {
	if (c->isPaid() == false) {
		cout << "Can not add this client. He is a client of a different restaurant." << endl;
	}
	else {
		if (tHead != NULL) {
			Table *t = findTable(c);
			if (t != NULL) {
				if (findWaiter(t) == true) {
					c->goToRestaurant();
					t->addClient(c);
					cout << "Client added" << endl;
				}
				else {
					cout << "Can not add client." << endl;
				}
			}
		}
	}
}


// Function checks if given client is at the restuarant. Checks his orders and remove them for client's orders list increasing the bill.

void Restaurant::takeOrder(Client *c) {
	// Checking if client is at the restaurant.
	if (cHead == NULL) {
		cout << "Can not take order. The restaurant has no cooks!" << endl;
	}
	else {
		if (c->isPaid() == true) {
			cout << "Client has no orders." << endl;
		}
		else {
			Table *table = checkClient(c);

			int counter = 0;

			if (table == NULL) {
				cout << "There is no such client at the resturant. Can not take order." << endl;
			}
			else {
				int orderNumber = c->getOrder(counter);
				int price = 0;

				while (orderNumber != -1) {
					//price = checkOrder(orderNumber);
					table->increaseBill(checkOrder(orderNumber));
					counter++;
					orderNumber = c->getOrder(counter);
				}

				c->takeOrder();	// Deletes prepared orders. 

				cout << "Order prepared." << endl;
			}
		}
	}

}


// Removes client from the restaurant - remove him form the table and the table from the waiter's list.
// Increases waiter's income.

void Restaurant::takePayment(Client *c) {
	Table *current = checkClient(c);

	if (current != NULL) {
		if (c->orderListFree() == true) {
			cout << "Your bill is " << current->getBill() << endl;
			freeWaiter(current);
			c->pay();
			current->removeClient();
			cout << "Thanks for visiting our restaurant!" << endl;
		}
		else {
			cout << "The client did not get the order yet!" << endl;
		}
	}
	else {
		cout << "Can not take the payment." << endl;
	}
}


// Function finds waiter that serves given table and remove it from his list.

void Restaurant::freeWaiter(Table *t) {
	Waiter *current = wHead;
	bool found = false;

	// Finding the waiter that keeps table t.
	while (current != NULL && found == false) {
		found = current->findTable(t);
		if (found == false)
			current = current->getNext();
	}
	if (current != NULL) {
		current->removeTable(t);
	}
	else {
		cout << "There is no such waiter that keeps the table." << endl;
	}
	
}

// Function checks if the client is not at the different restaurant now. If yes, he can not be added to another restaurant.

Table* Restaurant::checkClient(Client *c) {
	Table *current = tHead;

	while (current != NULL) {
		if (current->getClient() == c) {
			return current;
		}
		current = current->getNext();
	}
	
	return NULL;
}

// Function checks if order of given number is at the menu.

int Restaurant::checkOrder(int number) {
	Dish *current = menu;
	int counter = 1;

	while (current != NULL && counter < number) {
		counter++;
		current = current->getNext();
	}

	if (current != NULL) {
		return current->getPrice();
	}
	else {
		cout << "There is no dish number " << number << " in the menu." << endl;
		return 0;
	}
}

// Function count income of all given waiters and then reset waiter's income.
void Restaurant::addIncome(Waiter *w) {
	income += w->getIncome();
	w->resetIncome();	// waiter's income = 0
}

// Function count income of all waiters and reset waiters' income.
void Restaurant::countIncome() {
	Waiter *current = wHead;

	while (current != NULL) {
		addIncome(current);
		current = current->getNext();
	}

	cout << name << "'s income = " << income << endl;
}

// TEMPLATES.

// Template to change worker's (cook's or waiter's) salary.

template <class T>
void Restaurant::changeSalary(T *worker, int salary) {
	if (worker->getSalary() > salary) {
		cout << "Worker od ID: " << worker->getID() << " has lower salary now." << endl;
	}
	else {
		cout << "Worker od ID: " << worker->getID() << " is promoted." << endl;
	}
	worker->changeSalary(salary);
}



// Tamplates for removing element from lists but not deleting it. 

// Function removes element from the head.
template <class T>
void Restaurant::removeFromHead(T *head) {
	T *current = head;
	head = current->getNext();
	current->setNext(NULL);
}

// Function removes element from the end.
template <class T>
bool Restaurant::removeFromEnd(T *toRemove) {
	T *next = toRemove->getNext();
	next->setNext(NULL);
	toRemove->setNext(NULL);

	return true;
}

// Function removes element form anywhere except head and end.
template <class T>
bool Restaurant::removeElement(T *toRemove) {
	T *next = toRemove->getNext();
	T *nextNext = next->getNext();

	toRemove->setNext(nextNext);
	next->setNext(NULL);

	return true;
}


// Function removes given employee form list. 

template <class T>
void Restaurant::removeStaff(T *employee, T *shead) {
	T *current = shead;
	bool removed = false;

	if (employee == shead) {
		removeFromHead(shead);
	}
	else {
		while (current->getNext() != NULL && removed == false) {
			if (current->getNext() == employee) {
				if (current->getNext()->getNext() == NULL) {
					removed = removeFromEnd(current);
				}
				else if (current->getNext()->getNext() != NULL) {
					removed = removeElement(current);
				}
				else {
					current = current->getNext();
				}
			}
		}


		if (removed == true) {
			cout << "Employee fired. " << endl;
		}
	}
}