#include "DAIBase.h"
#include <iostream>
using namespace std;

int main() {
    DAIBase db;
    db.addViolation("AA1234BB", "Speeding");
    db.addViolation("AA1234BB", "No seatbelt");
    db.addViolation("AB5678CD", "Red light");
    db.addViolation("AC9999ZZ", "Parking");

    cout << "All database:\n";
    db.printAll();

    cout << "\nBy number AA1234BB:\n";
    db.printByNumber("AA1234BB");

    cout << "\nBy range AB0000AA - AC9999ZZ:\n";
    db.printByRange("AB0000AA", "AC9999ZZ");
    return 0;
}