/*
Made by : Mohamed Hany
Course: ECEN204
*/

#include <iostream>
#include <fstream>
# include <string>

using namespace std;

class LinkedList {
    private:
        struct Node_Passenger {
        string name;
        int flightNumber;
        string priority;
        Node_Passenger* next;
        };
        Node_Passenger* head;
    public:
        // constructor to initial the head with null
        LinkedList() : head(nullptr) {}
        // creating a new node for the passenger

        Node_Passenger* createPassenger(string name, int flightNumber, string priority) {
        Node_Passenger* newPassenger = new Node_Passenger;
        newPassenger->name = name;
        newPassenger->flightNumber = flightNumber;
        newPassenger->priority = priority;
        newPassenger->next = nullptr;
        return newPassenger;   // returning a pointer to the new node
        }

        // adding a new passenger

        void addPassenger(LinkedList* queues, int numQueues, string name, int flightNumber, string priority) {
            int priorityIndex;
            if (priority == "regular" || priority == "Regular"){
                priorityIndex = numQueues - 1;    // queues [2] = regular passengers
            }
            else if (priority == "business" || priority == "Business"){
                priorityIndex = 0;                // queues [0] = business passengers
            }
            else if (priority == "special" || priority == "Special"){
                priorityIndex = 1;                // queues [1] = special passengers
            }
            else{
                cout << "incorrect input" << endl;
                return;
            }

            Node_Passenger* newPassenger = createPassenger(name, flightNumber, priority);
            if (queues[priorityIndex].head == nullptr) {
                queues[priorityIndex].head = newPassenger;
            } else {
                Node_Passenger* current = queues[priorityIndex].head;
                while (current->next != nullptr) {
                    current = current->next;
                }
                current->next = newPassenger;
            }
            cout << "Passenger " << name << " added to the queue." << endl;
            logOperation("Added passenger: " + name + "Priority: " + priority);
        }

        // display the linked list
        void displayQueue(LinkedList* queues, int numQueues) {
            for (int i = 0; i < numQueues; ++i) {
                cout << "Priority: " << (i == 2 ? "Regular" : (i == 0 ? "Business" : "Special Needs")) << endl;
                Node_Passenger* current = queues[i].head;
                while (current != nullptr) {
                    cout << "Name: " << current->name << ", Flight Number: " << current->flightNumber << ", Priority: " << current->priority << endl;
                    current = current->next;
                }
                cout << "Done" << endl;
            }
        logOperation("Display Done");
        }

        // remove a passenger

        void removePassenger(LinkedList* queues, int numQueues, string name, int flightNumber) {
            for (int i = 0; i < numQueues; ++i) {
                Node_Passenger* current = queues[i].head;
                Node_Passenger* prev = nullptr;
                while (current != nullptr) {
                    if (current->name == name || current-> flightNumber == flightNumber) {
                        if (prev == nullptr){
                            queues[i].head = current->next;
                        }
                        else{
                        prev->next = current->next;
                        delete current;
                        cout << "Passenger " << name << " removed from the queue.\n";
                        logOperation("Removed passenger: " + name);
                        return;
                        }
                    }
                    prev = current;
                    current = current->next;
                }
            }
            cout << "Passenger " << name << " not found in the queue.\n";
        }

        // search for a passenger

        void searchPassenger(LinkedList* queues, int numQueues, string name, int flightNumber) {
            for (int i = 0; i < numQueues; ++i) {
                Node_Passenger* current = queues[i].head;
                int position = 1;
                while (current != nullptr) {
                    if (current->name == name || current->flightNumber == flightNumber) {
                        cout << "Passenger " << name << " found in the queue at position " << position << endl;
                        logOperation("Found passenger: " + name);
                        int choice;
                        cout << "Do you want to modify the information: \n enter 1 to edit";
                        cin >> choice;
                        if (choice == 1){
                            modifyPassenger (current);
                        }
                        else{
                            return;
                        }
                    }
                    current = current->next;
                    position++;
                }
            }
            cout << "Passenger " << name << " not found in the queue.\n";
            logOperation("Not Found passenger: " + name);

}


        // editing passenger information
        void modifyPassenger(Node_Passenger* passengerToEdit) {
            if (passengerToEdit != nullptr) {
                cout << "Passenger " << passengerToEdit->name << " found in the queue.\n";
                cout << "Enter new details for the passenger:\n";
                cout << "Name: ";
                cin >> passengerToEdit->name;
                cout << "Flight Number: ";
                cin >> passengerToEdit->flightNumber;
                cout << "Priority (regular/business/special needs): ";
                cin >> passengerToEdit->priority;
                cout << "Passenger details updated successfully.\n";
                logOperation("Modified passenger: " + passengerToEdit->name + "Priority" + priority);
            }
        }


        // view the statistic
        void queueStatistics(LinkedList* queues, int numQueues) {
            int totalPassengers = 0;
            int totalPriorityPassengers = 0;
            double totalWaitTime = 0.0;

            for (int i = 0; i < numQueues; ++i) {
                Node_Passenger* current = queues[i].head;
                while (current != nullptr) {
                    totalPassengers++;
                    if (i != numQueues - 1) // If not regular queue, queues [2] = regular
                        totalPriorityPassengers++;
                    current = current->next;
                }
            }

            // Calculate average wait time
            totalWaitTime = totalPassengers * 5; // assuming each one takes 5 minutes

            // Display statistics
            cout << "Queue Statistics:\n";
            cout << "Total number of passengers: " << totalPassengers << endl;
            cout << "Number of priority passengers: " << totalPriorityPassengers << endl;
            cout << "Average wait time: " << totalWaitTime << " minutes" << endl;
            logOperation("Statistics Viewed");

        }

        // sorting according the flight number

        void sortPassengers(LinkedList* queues, int numQueues) {
            for (int i = 0; i < numQueues; ++i) {
                Node_Passenger* current = queues[i].head;
                if (current == nullptr || current->next == nullptr) {
                    // If the queue is empty or has only one passenger, it is already sorted
                    continue;
                }

                Node_Passenger* nextPassenger = nullptr;

                while (current != nullptr) {
                    nextPassenger = current->next;
                    while (nextPassenger != nullptr) {
                        if (current->flightNumber > nextPassenger->flightNumber) {
                            // Swap passenger data
                            swap(current->name, nextPassenger->name);
                            swap(current->flightNumber, nextPassenger->flightNumber);
                        }
                        nextPassenger = nextPassenger->next;
                    }
                    current = current->next;
                }
                cout << "Passengers in priority queue " << i << " sorted by flight number successfully.\n";
            }
            logOperation("Sorted with flight number");

        }



        // display menu to the user
        void displayMenu(LinkedList* queues, int numQueues) {
            int choice;
            string name, priority;
            int flightNumber;

            while (true) {
                cout << "\nAirport Security Check Queue Management System\n";
                cout << "1. Add Passenger\n";
                cout << "2. Remove Passenger\n";
                cout << "3. Search Passenger\n";
                cout << "4. View Statistics\n";
                cout << "5. Display Queue\n";
                cout << "6. Sort by Flight Number\n";
                cout << "7. Exit\n";
                cout << "Enter your choice: ";
                cin >> choice;

                switch (choice) {
                    case 1:
                        cout << "Enter passenger details:\n";
                        cout << "Name: ";
                        cin >> name;
                        cout << "Flight Number: ";
                        cin >> flightNumber;
                        cout << "Priority (regular/business/special): ";
                        cin >> priority;
                        addPassenger(queues, numQueues, name, flightNumber, priority);
                        break;
                    case 2:
                        cout << "Enter name of passenger to remove: ";
                        cin >> name;
                        cout << "Flight Number: : ";
                        cin >> flightNumber;
                        removePassenger(queues, numQueues, name, flightNumber);
                        break;
                    case 3:
                        cout << "Enter name of passenger to search: ";
                        cin >> name;
                        cout << "Flight Number: : ";
                        cin >> flightNumber;
                        searchPassenger(queues, numQueues, name, flightNumber);
                        break;
                    case 4:
                        queueStatistics(queues, numQueues);
                        break;
                    case 5:
                        displayQueue(queues, numQueues);
                        break;
                    case 6:
                        sortPassengers(queues, numQueues);
                        break;
                    case 7:
                        cout << "Exiting...\n";
                        return;
                    default:
                        cout << "Invalid choice. Please try again.\n";
                }
            }
        }

        // Recording the user operations
        void logOperation(const string& operation) {
            ofstream logFile("queue_log.txt", ios::app); // Open log file in append mode
            if (logFile.is_open()) {
                logFile << operation << endl; // Write operation to log file
                logFile.close();
            } else {
                cout << "Unable to open log file." << endl;
            }
        }


        // destructor to destroy the linked list
        ~LinkedList() {
            Node_Passenger* current = head;
            while (current != nullptr) {
                Node_Passenger* next = current->next;
                delete current;
                current = next;
            }
        }


};


int main()
{
    ofstream logFile("queue_log.txt", ios::app);
    logFile.close();

    const int numQueues = 3; // Business, Special Needs, Regular
    LinkedList queues[numQueues];    // array of linked lists queues [3]

    for (int i = 0; i < numQueues; ++i) {
        queues[i] = LinkedList();      // initializing each head in the array with null
    }
    queues[numQueues].displayMenu(queues, numQueues);
    return 0;
}
