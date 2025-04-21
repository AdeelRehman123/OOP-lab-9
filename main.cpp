#include "Flight.h"
#include "Passenger.h"

int main() {
    Flight f1("PK101", "Karachi", "Islamabad", 2);
    Flight f2("PK202", "Lahore", "Dubai", 1);

    Passenger p1(1, "Ali");
    Passenger p2(2, "Sara");
    Passenger p3(3, "Omar");

    f1.displayInfo();

    p1.requestBooking(f1);
    p2.requestBooking(f1);
    p3.requestBooking(f1); // Should fail

    p1.requestUpgrade(f1);
    p3.requestUpgrade(f1); // Should fail

    p2.requestCancellation(f1);
    p2.requestCancellation(f1); // Should fail

    f1.displayInfo();

    p1.requestBooking(f2);
    p1.requestBooking(f2); // Should fail due to duplication

    return 0;
}
