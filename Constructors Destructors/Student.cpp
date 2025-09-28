#include "Student.h"
Student::Student() : name(""), age(0), university("") {}
Student::Student(const std::string& n, int a, const std::string& u)
    : name(n), age(a), university(u) {}