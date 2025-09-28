#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    string name;
    int age;
    string university;
};

class Book {
public:
    string title;
    string author;
    int year;
};

class Firm {
public:
    string name;
    string address;
    int employees;
};

class Phone {
public:
    string brand;
    string model;
    int year;
};

class Car {
public:
    string brand;
    string model;
    int year;
};

int main() {
    Student s;
    s.name = "Ivan";
    s.age = 20;
    s.university = "KPI";
    cout << "Student: " << s.name << ", " << s.age << ", " << s.university << endl;

    Book b;
    b.title = "C++ Basics";
    b.author = "Bjarne Stroustrup";
    b.year = 2013;
    cout << "Book: " << b.title << ", " << b.author << ", " << b.year << endl;

    Firm f;
    f.name = "TechCorp";
    f.address = "Kyiv";
    f.employees = 100;
    cout << "Firm: " << f.name << ", " << f.address << ", " << f.employees << endl;

    Phone p;
    p.brand = "Samsung";
    p.model = "Galaxy S21";
    p.year = 2021;
    cout << "Phone: " << p.brand << ", " << p.model << ", " << p.year << endl;

    Car c;
    c.brand = "Toyota";
    c.model = "Camry";
    c.year = 2020;
    cout << "Car: " << c.brand << ", " << c.model << ", " << c.year << endl;

    return 0;
}