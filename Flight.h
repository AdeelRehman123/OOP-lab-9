#ifndef FLIGHT_H
#define FLIGHT_H

#include <string>
#include <unordered_set>
#include <iostream>

class Passenger;

class Flight {
private:
    std::string flightNumber;
    std::string departure;
    std::string arrival;
    int capacity;
    std::unordered_set<int> bookedSeats; // Stores passenger IDs for simplicity

public:
    Flight(std::string fNum, std::string dep, std::string arr, int cap);

    bool bookSeat(const Passenger& passenger);
    bool cancelSeat(const Passenger& passenger);
    bool upgradeSeat(const Passenger& passenger);

    void displayInfo() const;

    // Disallow direct manipulation of capacity and seat list
};

#endif
