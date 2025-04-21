#ifndef PASSENGER_H
#define PASSENGER_H

#include <string>
class Flight;

class Passenger {
private:
    int id;
    std::string name;

public:
    Passenger(int id, std::string name);
    int getID() const;

    void requestBooking(Flight& flight);
    void requestCancellation(Flight& flight);
    void requestUpgrade(Flight& flight);
};

#endif
