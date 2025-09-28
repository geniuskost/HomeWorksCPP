#include "Person.h"

int Person::count = 0;

Person::Person(int id, const char* s, const char* n, const char* p, const Date& b)
    : id(id), birth(b) {
    surname = new char[strlen(s) + 1];
    strcpy_s(surname, strlen(s) + 1, s);
    name = new char[strlen(n) + 1];
    strcpy_s(name, strlen(n) + 1, n);
    patronymic = new char[strlen(p) + 1];
    strcpy_s(patronymic, strlen(p) + 1, p);
    count++;
}

Person::Person(const Person& other) : id(other.id), birth(other.birth) {
    surname = new char[strlen(other.surname) + 1];
    strcpy_s(surname, strlen(other.surname) + 1, other.surname);
    name = new char[strlen(other.name) + 1];
    strcpy_s(name, strlen(other.name) + 1, other.name);
    patronymic = new char[strlen(other.patronymic) + 1];
    strcpy_s(patronymic, strlen(other.patronymic) + 1, other.patronymic);
    count++;
}

Person::~Person() {
    delete[] surname;
    delete[] name;
    delete[] patronymic;
    count--;
}

int Person::getCount() { return count; }
void Person::setId(int id) { this->id = id; }
void Person::setSurname(const char* s) {
    delete[] surname;
    surname = new char[strlen(s) + 1];
    strcpy_s(surname, strlen(s) + 1, s);
}
void Person::setName(const char* n) {
    delete[] name;
    name = new char[strlen(n) + 1];
    strcpy_s(name, strlen(n) + 1, n);
}
void Person::setPatronymic(const char* p) {
    delete[] patronymic;
    patronymic = new char[strlen(p) + 1];
    strcpy_s(patronymic, strlen(p) + 1, p);
}
void Person::setBirth(const Date& b) { birth = b; }
int Person::getId() const { return id; }
const char* Person::getSurname() const { return surname; }
const char* Person::getName() const { return name; }
const char* Person::getPatronymic() const { return patronymic; }
Date Person::getBirth() const { return birth; }
void Person::print() const {
    std::cout << "ID: " << id << "\nПІБ: " << surname << " " << name << " " << patronymic << "\nДата народження: ";
    birth.print();
    std::cout << std::endl;
}