#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Flight {
public:
    Flight(int id, const std::string& origin, const std::string& destination, const std::string& departureTime, const std::string& arrivalTime, double price)
        : id(id), origin(origin), destination(destination), departureTime(departureTime), arrivalTime(arrivalTime), price(price) {}

    void display() const {
        std::cout << "Flight ID: " << id << "\n"
                  << "Origin: " << origin << "\n"
                  << "Destination: " << destination << "\n"
                  << "Departure Time: " << departureTime << "\n"
                  << "Arrival Time: " << arrivalTime << "\n"
                  << "Price: $" << price << "\n";
    }

    int getId() const { return id; }
    const std::string& getOrigin() const { return origin; }
    const std::string& getDestination() const { return destination; }
    const std::string& getDepartureTime() const { return departureTime; }
    const std::string& getArrivalTime() const { return arrivalTime; }
    double getPrice() const { return price; }

private:
    int id;
    std::string origin;
    std::string destination;
    std::string departureTime;
    std::string arrivalTime;
    double price;
};

class FlightManagementSystem {
public:
    void addFlight(int id, const std::string& origin, const std::string& destination, const std::string& departureTime, const std::string& arrivalTime, double price) {
        flights.emplace_back(id, origin, destination, departureTime, arrivalTime, price);
    }

    void displayFlights() const {
        for (const auto& flight : flights) {
            flight.display();
            std::cout << "-------------------\n";
        }
    }

    void removeFlight(int id) {
        flights.erase(std::remove_if(flights.begin(), flights.end(),
                                     [id](const Flight& flight) { return flight.getId() == id; }),
                      flights.end());
    }

    void searchFlightsByOrigin(const std::string& origin) const {
        for (const auto& flight : flights) {
            if (flight.getOrigin() == origin) {
                flight.display();
                std::cout << "-------------------\n";
            }
        }
    }

    void searchFlightsByDestination(const std::string& destination) const {
        for (const auto& flight : flights) {
            if (flight.getDestination() == destination) {
                flight.display();
                std::cout << "-------------------\n";
            }
        }
    }

    void searchFlightsByPrice(double maxPrice) const {
        for (const auto& flight : flights) {
            if (flight.getPrice() <= maxPrice) {
                flight.display();
                std::cout << "-------------------\n";
            }
        }
    }

private:
    std::vector<Flight> flights;
};

int main() {
    FlightManagementSystem fms;

    fms.addFlight(1, "New York", "Los Angeles", "10:00 AM", "1:00 PM", 300.0);
    fms.addFlight(2, "Chicago", "Miami", "12:00 PM", "4:00 PM", 200.0);
    fms.addFlight(3, "New York", "Miami", "2:00 PM", "6:00 PM", 250.0);

    std::cout << "All Flights:\n";
    fms.displayFlights();

    fms.removeFlight(1);

    std::cout << "After removing flight with ID 1:\n";
    fms.displayFlights();

    std::cout << "Flights from New York:\n";
    fms.searchFlightsByOrigin("New York");

    std::cout << "Flights to Miami:\n";
    fms.searchFlightsByDestination("Miami");

    std::cout << "Flights with price <= 250:\n";
    fms.searchFlightsByPrice(250.0);

    return 0;
}