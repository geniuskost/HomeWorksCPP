#pragma once

class Flat {
    double area;
    double price;
public:
    Flat(double a = 0, double p = 0) : area(a), price(p) {}
    Flat(const Flat& other) : area(other.area), price(other.price) {}

    Flat& operator=(const Flat& other) {
        if (this != &other) {
            area = other.area;
            price = other.price;
        }
        return *this;
    }

    bool operator==(const Flat& other) const {
        return area == other.area;
    }

    bool operator>(const Flat& other) const {
        return price > other.price;
    }

    double& getPrice() { return price; }
    double getArea() const { return area; }
};