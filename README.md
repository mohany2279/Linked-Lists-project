# Airport Security Check Queue Management System || ECEN 204 Course

## Overview
The Airport Security Check Queue Management System is a program designed to simulate the management of passengers lining up for security checks at an airport. It utilizes linked list data structures to manage the order of passengers as they await security screening. This project provides functionalities such as adding and removing passengers from the queue, managing priority passengers, searching for specific passengers, viewing queue statistics, displaying the queue, and sorting passengers by flight number.

## Features
- Add Passenger: Insert a new passenger into the queue.
- Remove Passenger: Dequeue passengers from the front of the queue.
- Priority Handling: Automatically adjust the queue to allow fast track for priority passengers.
- Search Passenger: Locate a specific passenger in the queue by name or flight number.
- View Statistics: Provide statistics such as the total number of passengers, number of priority passengers, and average wait time.
- Display Queue: Show all passengers currently in the queue along with their details.
- Sort by Flight Number: Sort passengers in each priority queue by their flight number.

## Implementation
- Implemented in C++ using linked list data structure.
- Interactive command-line interface for user interaction.
- Logging system records each operation performed on the queue in a text file named `queue_log.txt`.

## How to Run
1. Compile the program using a C++ compiler.
2. Run the executable file generated.
3. Follow the on-screen instructions to perform various operations on the queue.

## Usage
- Upon running the program, a menu is displayed where users can choose from various options.
- Users can add passengers, remove passengers, search for passengers (and edit information if needed), view statistics, display the queue, and sort passengers by flight number.
- Passengers can be added with their name, flight number, and priority status (regular, business, special needs).

## Functions Used
- **addPassenger**: Adds a new passenger to the queue with provided name, flight number, and priority.
- **removePassenger**: Removes a passenger from the queue by name or flight number.
- **searchPassenger**: Searches for a passenger in the queue by name or flight number and provides the option to modify their information.
- **modifyPassenger**: Modifies the information of a passenger in the queue.
- **queueStatistics**: Calculates and displays statistics such as total number of passengers, number of priority passengers, and average wait time.
- **displayQueue**: Displays all passengers currently in the queue along with their details.
- **sortPassengers**: Sorts passengers in each priority queue by their flight number.
- **displayMenu**: Displays the main menu and handles user input to execute different functionalities.
- **logOperation**: Logs each operation performed on the queue to a text file for auditing purposes.

## Author
Mohamed Hany Mohamed Gamal Farag Ahmed
