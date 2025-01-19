#include <iostream>
#include <string>
using namespace std;

// Constants
const int MAX_FLIGHTS = 100;
const int MAX_BOOKINGS = 100;

// Flight details
int flightNumbers[MAX_FLIGHTS];
string destinations[MAX_FLIGHTS];
int totalSeats[MAX_FLIGHTS];
int bookedSeats[MAX_FLIGHTS];
int flightCount = 0;

// Booking details
int bookingIDs[MAX_BOOKINGS];
string passengerNames[MAX_BOOKINGS];
int bookedFlightNumbers[MAX_BOOKINGS];
int bookingCount = 0;
int nextBookingID = 1;

// Function to add a new flight
void addFlight() {
    if (flightCount >= MAX_FLIGHTS) {
    	cout << endl << "\t ________________________________________________" << endl;
        cout << "\t| Flight limit reached. Cannot add more flights. |\n";
        cout << "\t|________________________________________________|";
        return;
    }
    cout << "\tEnter Flight Number: ";
    cin >> flightNumbers[flightCount];
    cout << "\tEnter Destination: ";
    cin.ignore();
    getline(cin, destinations[flightCount]);
    cout << "\tEnter Total Seats: ";
    cin >> totalSeats[flightCount];
    bookedSeats[flightCount] = 0; // Initialize booked seats to 0
    flightCount++;
    cout << endl << "\t ______________________________________________" << endl;
    cout << "\t|         Flight Added Successfully.           |\n";
    cout << "\t|______________________________________________|" << endl;
}

// Function to view all flights
void viewFlights() {
    if (flightCount == 0) {
        cout << endl << "\t ______________________________________________" << endl;
	    cout << "\t|            No Flights Available!.            |\n";
    	cout << "\t|______________________________________________|" << endl;
		return;
    }
    cout<<endl<<"\t"<<" *_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*";
	cout<<endl<<"\t"<<"*|                             |*";
	cout<<endl<<"\t"<<"*|      AVAILABLE FLIGHTS      |*";
	cout<<endl<<"\t"<<"*|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _|*";
	cout<<endl<<"\t"<<" * * * * * * * * * * * * * * * *" <<endl<<endl;
    for (int i = 0; i < flightCount; i++) {
        cout << "\tFlight Number: " << flightNumbers[i] << endl
             << "\tDestination: " << destinations[i] << endl
             << "\tSeats Available: " << (totalSeats[i] - bookedSeats[i]) << "\n";
    }
}

// Function to book a ticket
void bookTicket() {
    if (bookingCount >= MAX_BOOKINGS) {
        cout << endl << "\t __________________________________________________" << endl;
	    cout << "\t| Booking limit reached. Cannot book more tickets. |\n";
    	cout << "\t|__________________________________________________|" << endl;
        return;
    }
    int flightNumber;
    string passengerName;

    cin.ignore();
    getline(cin, passengerName);
    cin >> passengerName;
    cout << "\tEnter flight number to book: ";
    cin >> flightNumber;

    // Find the flight
    for (int i = 0; i < flightCount; i++) {
        if (flightNumbers[i] == flightNumber) {
            if (bookedSeats[i] < totalSeats[i]) {
                bookedSeats[i]++;
                bookingIDs[bookingCount] = nextBookingID++;
                passengerNames[bookingCount] = passengerName;
                bookedFlightNumbers[bookingCount] = flightNumber;
                bookingCount++;
                cout << endl << "\t __________________________________________________" << endl;
	    		cout << "\t| Ticket booked successfully! Your Booking ID is " << nextBookingID - 1 << " |\n";
		    	cout << "\t|__________________________________________________|" << endl;
                return;
            } else {
            	cout << endl << "\t ______________________________________________" << endl;
	    		cout << "\t|   Sorry, no seats available on this flight.  |\n";
    			cout << "\t|______________________________________________|" << endl;
                return;
            }
        }
    }
    cout << endl << "\t ______________________________________________" << endl;
	cout << "\t|             Flight not found.                |\n";
    cout << "\t|______________________________________________|" << endl;
}

// Function to cancel a ticket
void cancelTicket() {
    int bookingID;
    cout << "\tEnter your Booking ID: ";
    cin >> bookingID;

    for (int i = 0; i < bookingCount; i++) {
        if (bookingIDs[i] == bookingID) {
            int flightNumber = bookedFlightNumbers[i];
            // Remove the booking by shifting elements
            for (int j = i; j < bookingCount - 1; j++) {
                bookingIDs[j] = bookingIDs[j + 1];
                passengerNames[j] = passengerNames[j + 1];
                bookedFlightNumbers[j] = bookedFlightNumbers[j + 1];
            }
            bookingCount--;

            // Update flight seat availability
            for (int j = 0; j < flightCount; j++) {
                if (flightNumbers[j] == flightNumber) {
                    bookedSeats[j]--;
                    break;
                }
            }
            cout << endl << "\t ______________________________________________" << endl;
			cout << "\t|       Booking cancelled successfully.        |\n";
    		cout << "\t|______________________________________________|" << endl;
            return;
        }
    }
    cout << endl << "\t ______________________________________________" << endl;
	cout << "\t|           Booking ID not found.              |\n";
    cout << "\t|______________________________________________|" << endl;        
}

// Function to view all bookings
void viewBookings() {
    if (bookingCount == 0) {
        cout << endl << "\t ______________________________________________" << endl;
		cout << "\t|           No bookings made yet.              |\n";
    	cout << "\t|______________________________________________|" << endl;
        return;
    }
    cout << endl << "\t" << " *_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*";
	cout << endl << "\t" << "*|                             |*";
	cout << endl << "\t" << "*|       YOUR BOOKINGS         |*";
	cout << endl << "\t" << "*|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _|*";
	cout << endl << "\t" << " * * * * * * * * * * * * * * * *" <<endl<<endl;
    for (int i = 0; i < bookingCount; i++) {
        cout << "\tBooking ID: " << bookingIDs[i] << endl
             << "\tPassenger Name: " << passengerNames[i] << endl
             << "\tFlight Number: " << bookedFlightNumbers[i] << "\n";
    }
}

// Main function
int main() {
    int choice;
    
    cout<<endl<<"\t\t\t"<<" *_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_* ";
	cout<<endl<<"\t\t\t"<<"*|                                                                               |*";
	cout<<endl<<"\t\t\t"<<"*|                             WELCOME TO AIRLINES                               |*";
	cout<<endl<<"\t\t\t"<<"*|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|*";
	cout<<endl<<"\t\t\t"<<" * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" <<endl<<endl;

	cout << endl << "\t" << "    _____  ___   _____ ____        __   __  _______";
	cout << endl << "\t" << "   /  __/ /  /  /_  _// ___\\      / /  / / /__  __/";
	cout << endl << "\t" << "  /  /_  /  /    / / / /  ____   / /__/ /    / /";
	cout << endl << "\t" << " /  __/ /  /_  _/ /_ \\ \\_/_| |  /  __  /    / /";
	cout << endl << "\t" << "/__/   /____/ /____/  \\___/|_| /_/  /_/    /_/";

	cout << endl << "\t\t" << "    ____     _____   ____  _____  ____    __  __  ___   _______  _____   _______  __      __";
	cout << endl << "\t\t" << "   / __ \\   / ___/  / __/ / ___/ / __ \   / / / / / _ \\ /__  __/ /_  _/  / ___  / /  \\    / /";
	cout << endl << "\t\t" << "  / /_/_/  / /___   \\ \\  / /__  / /_/_/ / / / / / /_\\ \\  / /     / /   / /  / / / /\\ \\  / /";
	cout << endl << "\t\t" << " / /\\ \\   / /___  __/ / / /__  / /\\ \\   \\ \\/ / / /  / / / /    _/ /_  / /__/ / / /  \\ \\/ /";
	cout << endl << "\t\t" << "/_/  \\_\\ /_____/ /___/ /____/ /_/  \\_\\   \\__/ /_/  /_/ /_/    /____/ /______/ /_/    \\__/" << endl;

	cout << endl << "\t\t\t" << "   ____  __  __ ____  _______ _____  _    ____";
	cout << endl << "\t\t\t" << "  / __/ / / / // __/ /__  __// ___/ / \\  / /| |";
	cout << endl << "\t\t\t" << "  \\ \\_ / \\_/ / \\ \\_    / /  / /__  / _ \\/ / / /";
	cout << endl << "\t\t\t" << " __\\ /  \\_  / __\\ /   / /  / /__  / / \\__/ / /";
	cout << endl << "\t\t\t" << "/___/    /_/ /___/   /_/  /____/ /_/      /_/";
	cout << endl;
	cout << endl;
    do {
        cout<<"\t _______________________________________________________"<<endl;
		cout<<"\t|\t                                                |"<<endl;	
		cout<<"\t|\t   Press 1 to Add a Flight  \t\t\t| "<<endl;
		cout<<"\t|\t   Press 2 to View Flights        \t\t| "<<endl;
		cout<<"\t|\t   Press 3 to Book a Ticket        \t\t| "<<endl;
		cout<<"\t|\t   Press 4 to Cancel a Ticket        \t\t| "<<endl;
		cout<<"\t|\t   Press 5 to View Booking Details        \t| "<<endl;
		cout<<"\t|\t   Press 6 to Exit                       \t| "<<endl;
		cout<<"\t|_______________________________________________________|\n"<<endl;
        while (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\tInvalid input. Please enter a number: ";
        }
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addFlight();
                break;
            case 2:
                viewFlights();
                break;
            case 3:
                bookTicket();
                break;
            case 4:
                cancelTicket();
                break;
            case 5:
                viewBookings();
                break;
            case 6:
                cout << endl << endl << "\t\t\t" << " *_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_* ";
				cout << endl << "\t\t\t" << "*|                                                                               |*";
				cout << endl << "\t\t\t" << "*|                             THANKS FOR VISITING                               |*";
				cout << endl << "\t\t\t" << "*|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|*";
				cout <<endl << "\t\t\t" << " * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" <<endl<<endl;
			    break;
            default:
                cout << endl << "\t ______________________________________________" << endl;
				cout << "\t|       Invalid choice. Please try again.      |\n";
    			cout << "\t|______________________________________________|" << endl;
    			goto reEnter;
        }
    } while (choice != 6);

    return 0;
}
