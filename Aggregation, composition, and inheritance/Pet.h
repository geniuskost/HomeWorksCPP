#pragma once
#include <iostream>
#include <string>

class Pet {
protected:
    std::string name;
    int age;
public:
    Pet(const std::string& n, int a) : name(n), age(a) {}
    virtual void print() const {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }
};

class Dog : public Pet {
    std::string breed;
public:
    Dog(const std::string& n, int a, const std::string& b) : Pet(n, a), breed(b) {}
    void print() const override {
        std::cout << "Dog: "; Pet::print();
        std::cout << "Breed: " << breed << std::endl;
    }
};

class Cat : public Pet {
    std::string color;
public:
    Cat(const std::string& n, int a, const std::string& c) : Pet(n, a), color(c) {}
    void print() const override {
        std::cout << "Cat: "; Pet::print();
        std::cout << "Color: " << color << std::endl;
    }
};

class Parrot : public Pet {
    std::string species;
public:
    Parrot(const std::string& n, int a, const std::string& s) : Pet(n, a), species(s) {}
    void print() const override {
        std::cout << "Parrot: "; Pet::print();
        std::cout << "Species: " << species << std::endl;
    }
};