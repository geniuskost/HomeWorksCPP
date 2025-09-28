#include "Date.h"
#include <iostream>
void Date::print() const {
    std::cout << day << "." << month << "." << year;
}