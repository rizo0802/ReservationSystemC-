# Airline Reservation System ✈️

A C++ terminal application that simulates a flight booking process using Object-Oriented Programming principles. 

## Features
* **Smart Booking Logic:** Book, cancel, or seamlessly swap seats between passengers.
* **Budget Checks:** Automatically verifies passenger funds before booking and suggests affordable seat alternatives if the budget is too low.
* **Auto-Generation:** Manually register passengers or randomly generate them with assigned names, ages, weights, and budgets.
* **OOP Architecture:** Built using abstract classes, inheritance, and direct pointer manipulation across four main classes (`Airplane`, `Seat`, `Passenger`, `BasePassenger`).

## How It Works
The program runs in an interactive loop where users navigate a main menu. Through the menu, you can:
1. Register or auto-generate up to 7 passengers.
2. Search for a passenger's seating status by their auto-generated ID or name.
3. Manage the 7 available airplane seats (2 Business, 5 Economy) by booking, swapping, or canceling reservations.

The core logic is handled by the `Airplane` class, which safely connects passenger data to specific seats using C++ pointers.

## Getting Started

### Prerequisites
You will need a C++ compiler installed on your system (such as `g++`).

### Compilation & Execution
To compile and run the program from your terminal, use the following commands:

`g++ main.cpp -o airline`
`./airline`
