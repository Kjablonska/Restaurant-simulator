# Object Oriented Programming


# RESTAURANT



## Karolina Jabłońska

## Warsaw University of Technology




## The story

```
The concept of this project was to develop an advanced restaurant system.
```
```
When a new client comes to the restaurant, the restaurant finds him a table.
Both one person and the group of people sitting at one table are treated as a one
client.
If the client is more than one person the restaurant searches for a table which can
fit the whole group.
Then, the restaurant searches for a waiter who has the least tables to serve at the
moment and assign the table to him.
Restaurant take order form the client and find the cook responsible for each dish
form the order.
When the order is ready, client’s bill becomes a sum of the price of all ordered
dishes.
Till the client does not pay, the table he is sitting at is seen as taken.
When client pays, the fable becomes free and that table is removed from the
waiter’s list.
Each cook is assigned to the dish (dishes) form menu.
```
Client:

- Client is one person or a group of people sitting at one table.
- Client can go to any restaurant, but can not be at more than one restaurant at the time.
- Each client has his own orders list.

Restaurant:

- Hire staff: waiters and cooks
- Fire staff.
- Finds the table which can fit the client
- Finds a waiter who as the least tables to serve
- Takes orders form clients
- Assign cooks to the orders
- Adds and removes tables. Changes seats numbers in tables.
- Adds and removes dishes form the menu.
- Count total income.
- Promote employee
- There can not be two employees with the same ID number.


### Limits and restrictions

- Maximum number of clients is equal to the number of tables at the
    restaurant.
- Number of clients who want to sit together should be less than number
    of seats at the table.
- If there is no table which can fit the whole group, the client can not go
    to that restaurant.
- The system optimize restaurant work and to each taken table assign the
    waiter who has the least tables to serve.
- Employees (waiters and cooks) can work at one restaurant at the time.
    Although, when someone is fired form the restaurant or leave from the
    work, he can become the employee of any restaurant.
- Client can be at one restaurant at the time.
- Each employee can be promoted (salary rise).
- Number of tables, waiters, dishes and cooks should be at least one.
- Payment is calculated as a sum of all orders from the particular table.
- There is a possibility to count restaurant’s income.
- If the client does not take all seats at the table, the table is seen as
    taken and any other client can be added there.
- Number of dish is set as the number in menu list.

Program is divided into files:

- restaurant.h
- restaurant.cpp
- staff.h
- staff.cpp
- waiter.h
- waiter.cpp
- cook.h
- cook.cpp
- table.h
- table.cpp
- dish.h
- dish.cpp
- client.h
- client.cpp


