# Airline Reservation System

A C++ terminal-based application built to simulate an airline booking system. This project was developed to practice and demonstrate core Object-Oriented Programming (OOP) principles, focusing specifically on class hierarchies, memory management, and pointer manipulation.

## Technical Highlights

Instead of just storing data in basic arrays, this system uses a structured OOP approach:

* [cite_start]**Abstract Classes & Polymorphism:** Utilizes an abstract `BasePassenger` class as an interface, containing pure virtual functions for passenger attributes[cite: 7, 8]. [cite_start]The `Passenger` class inherits and overrides these functions[cite: 10, 117].
* [cite_start]**Safe Memory Management:** Implements virtual destructors in the base class to ensure proper cleanup and prevent memory leaks when derived objects are deleted[cite: 9, 113].
* [cite_start]**Direct Pointer Manipulation:** The `Seat` class manages seat occupancy using pointers (`BasePassenger*`) rather than copying data[cite: 16, 127]. [cite_start]This allows for highly efficient status updates, seat assignments, and seat swapping between passengers[cite: 27, 144].

## Features

[cite_start]The interactive CLI allows users to manage a flight with both Business and Economy class seating[cite: 36, 162]. Features include:

* [cite_start]**Passenger Registration:** Manually register passengers with specific budgets and details, or auto-generate passengers with randomized stats[cite: 51, 55, 82, 86].
* [cite_start]**Seat Booking & Budget Checking:** Assign passengers to specific seats[cite: 20, 95]. [cite_start]If a passenger cannot afford a selected seat, the system automatically calculates and suggests available lower-priced alternatives[cite: 24, 99].
* [cite_start]**Dynamic Seat Swapping:** Swap the seat assignments of two booked passengers using pointer memory address swaps[cite: 27, 106, 144].
* [cite_start]**Booking Cancellation:** Clear a seat's status and automatically update the associated passenger's seating state[cite: 30, 67, 146].
* [cite_start]**Database Search:** Query registered passengers by their auto-generated ID or their Name to check their current seating status[cite: 31, 59, 148, 153].

## Getting Started

### Prerequisites
You just need a standard C++ compiler (like GCC or Clang) installed on your system.

### Compilation & Execution
To compile and run the project from your terminal:

```bash
# Compile the code
g++ main.cpp -o airline_system

# Run the executable (Linux/macOS)
./airline_system

# Run the executable (Windows)
airline_system.exe
