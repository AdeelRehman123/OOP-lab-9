#include "Flight.h"
#include "Passenger.h"

Flight::Flight(std::string fNum, std::string dep, std::string arr, int cap)
    : flightNumber(fNum), departure(dep), arrival(arr), capacity(cap) {}

bool Flight::bookSeat(const Passenger& passenger) {
    if (bookedSeats.size() >= capacity) {
        std::cout << "Booking failed for Passenger " << passenger.getID() << ": Flight Full.\n";
        return false;
    }
    if (bookedSeats.count(passenger.getID())) {
        std::cout << "Passenger " << passenger.getID() << " already booked.\n";
        return false;
    }
    bookedSeats.insert(passenger.getID());
    std::cout << "Booking successful for Passenger " << passenger.getID() << "\n";
    return true;
}

bool Flight::cancelSeat(const Passenger& passenger) {
    if (bookedSeats.erase(passenger.getID())) {
        std::cout << "Cancellation successful for Passenger " << passenger.getID() << "\n";
        return true;
    }
    std::cout << "Cancellation failed: No booking found for Passenger " << passenger.getID() << "\n";
    return false;
}

bool Flight::upgradeSeat(const Passenger& passenger) {
    if (bookedSeats.count(passenger.getID())) {
        std::cout << "Seat upgraded for Passenger " << passenger.getID() << "\n";
        return true;
    }
    std::cout << "Upgrade failed: No booking found for Passenger " << passenger.getID() << "\n";
    return false;
}

void Flight::displayInfo() const {
    std::cout << "Flight " << flightNumber << " from " << departure << " to " << arrival << "\n";
    std::cout << "Seats booked: " << bookedSeats.size() << " / " << capacity << "\n";
}
