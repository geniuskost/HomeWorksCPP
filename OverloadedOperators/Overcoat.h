#pragma once
#include <string>

class Overcoat {
    std::string type;
    double price;
public:
    Overcoat(const std::string& t = "", double p = 0) : type(t), price(p) {}
    Overcoat(const Overcoat& other) : type(other.type), price(other.price) {}

    Overcoat& operator=(const Overcoat& other) {
        if (this != &other) {
            type = other.type;
            price = other.price;
        }
        return *this;
    }

    bool operator==(const Overcoat& other) const {
        return type == other.type;
    }

    bool operator>(const Overcoat& other) const {
        return type == other.type && price > other.price;
    }

    double& getPrice() { return price; }
    std::string getType() const { return type; }
};