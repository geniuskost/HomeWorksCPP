#pragma once
#include "Date.h"
#include <iostream>
#include <cstring>

class Person {
private:
    int id;
    char* surname;
    char* name;
    char* patronymic;
    Date birth;
    static int count;
public:
    Person(int id, const char* s, const char* n, const char* p, const Date& b);
    Person() : Person(0, "", "", "", Date()) {}
    Person(const Person& other);
    ~Person();
    static int getCount();
    void setId(int id);
    void setSurname(const char* s);
    void setName(const char* n);
    void setPatronymic(const char* p);
    void setBirth(const Date& b);
    int getId() const;
    const char* getSurname() const;
    const char* getName() const;
    const char* getPatronymic() const;
    Date getBirth() const;
    void print() const;
};