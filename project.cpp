#include <iostream>
#include <iomanip>
#include <string>
#include <queue>

using namespace std;

class Bus {
    string bus_number;
    string bus_driver;
    string bus_arrival;
    string bus_depart;
    string b_from;
    string b_to;
    priority_queue<int, vector<int>, greater<int>> seatPriorityQueue; // Priority queue to manage seat reservations

public:
    void addNewBus();
    void makeReservation();
    void clearSeats();
    void viewBusDetails();
    void showAvailableBuses(Bus buses[]);
    void showSeatAvailability();
    void displayLine(char ch);
};

void Bus::addNewBus() {
    cout << "Enter Bus Number: ";
    cin >> bus_number;

    cout << "\nEnter Driver's Name: ";
    cin >> bus_driver;

    cout << "\nArrival Time: ";
    cin >> bus_arrival;

    cout << "\nDeparture Time: ";
    cin >> bus_depart;

    cout << "\nFrom: ";
    cin >> b_from;

    cout << "\nTo: ";
    cin >> b_to;

    clearSeats();
    cout << "\nNew Bus Added Successfully.\n";
}

void Bus::makeReservation() {
    showSeatAvailability();

    if (!seatPriorityQueue.empty()) {
        int seatNumber = seatPriorityQueue.top();
        seatPriorityQueue.pop();
        cout << "Reservation Successful! Seat Number: " << seatNumber << "\n";
    } else {
        cout << "All seats are reserved. Sorry!\n";
    }
}

void Bus::clearSeats() {
    // Clear any existing reservations
    while (!seatPriorityQueue.empty()) {
        seatPriorityQueue.pop();
    }
    // Initialize the queue with seat numbers
    for (int i = 1; i <= 32; ++i) {
        seatPriorityQueue.push(i);
    }
}

void Bus::viewBusDetails() {
    displayLine('*');
    cout << "Bus Number: \t" << bus_number
        << "\nDriver: \t" << bus_driver << "\t\tArrival Time: \t"
        << bus_arrival << "\tDeparture Time:" << bus_depart
        << "\nFrom: \t\t" << b_from << "\t\tTo: \t\t" << b_to << "\n";
    displayLine('*');

    showSeatAvailability();
}

void Bus::showAvailableBuses(Bus buses[]) {
    displayLine('*');
    cout << "Available Buses:\n";
    for (int i = 0; i < 5; i++) {
        if (!buses[i].bus_number.empty()) {
            cout << "Bus Number: " << buses[i].bus_number << "\tDriver: " << buses[i].bus_driver
                << "\tFrom: " << buses[i].b_from << "\tTo: " << buses[i].b_to << "\n";
        }
    }
    displayLine('_');
}

void Bus::showSeatAvailability() {
    cout << "Seat Availability:\n";
    priority_queue<int, vector<int>, greater<int>> tempQueue = seatPriorityQueue;
    while (!tempQueue.empty()) {
        cout << tempQueue.top() << ". ";
        tempQueue.pop();
    }
    cout << endl;
}

void Bus::displayLine(char ch) {
    for (int x = 80; x > 0; x--) {
        cout << ch;
    }
    cout << '\n';
}

int main() {
    const int MAX_BUSES = 5;
    Bus buses[MAX_BUSES];

    int choice;

    while (true) {
        cout << "\n\n";
        cout << "\t\t***SIMPLE BUS RESERVATION SYSTEM***";
        cout << "\n\n";
        cout << "\t\t\t1. Add New Bus\n\t\t\t"
            << "2. Make Reservation\n\t\t\t"
            << "3. View Reservation\n\t\t\t"
            << "4. Show Available Buses\n\t\t\t"
            << "5. Exit";
        cout << "\n\t\t\tEnter your Choice: ";

        cin >> choice;

        switch (choice) {
        case 1:
            for (int i = 0; i < MAX_BUSES; ++i) {
                buses[0].showAvailableBuses(buses); {
                    buses[i].addNewBus();
                    break;
                }
            }
            break;

        case 2:
            int busIndex;
            cout << "Enter Bus Index: ";
            cin >> busIndex;
            if (busIndex >= 0 && busIndex < MAX_BUSES) {
                buses[busIndex].makeReservation();
            }
            else {
                cout << "Invalid Bus Index.\n";
            }
            break;

        case 3:
            cout << "Enter Bus Index: ";
            cin >> busIndex;
            if (busIndex >= 0 && busIndex < MAX_BUSES) {
                buses[busIndex].viewBusDetails();
            }
            else {
                cout << "Invalid Bus Index.\n";
            }
            break;

        case 4:
            buses[0].showAvailableBuses(buses);
            break;

        case 5:
            cout << "Exiting the program. Thank you!\n";
            return 0;

        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
