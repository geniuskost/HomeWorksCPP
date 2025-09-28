#include <iostream>
#include "Fraction.h"
#include "Person.h"
using namespace std;

int main() {
    Fraction f1(4, 8), f2(1, 3);
    f1.print();
    f2.print();
    Fraction f3 = f1.add(f2);
    f3.print();
    Fraction f4 = f1.mul(2);
    f4.print();

    Date d(29, 9, 2000);
    Person p(1, "Іванов", "Іван", "Іванович", d);
    p.print();

    cout << "Створено людей: " << Person::getCount() << endl;

    Person p2 = p;
    p2.setName("Петро");
    p2.print();

    cout << "Створено людей: " << Person::getCount() << endl;
    return 0;
}