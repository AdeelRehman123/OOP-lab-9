#include "Passenger.h"
#include "Flight.h"
#include <iostream>

Passenger::Passenger(int id, std::string name) : id(id), name(name) {}

int Passenger::getID() const {
    return id;
}

void Passenger::requestBooking(Flight& flight) {
    flight.bookSeat(*this);
}

void Passenger::requestCancellation(Flight& flight) {
    flight.cancelSeat(*this);
}

void Passenger::requestUpgrade(Flight& flight) {
    flight.upgradeSeat(*this);
}
