#pragma once
#include <iostream>

class Fraction {
private:
    int numerator;
    int denominator;
    void reduce();
    int gcd(int a, int b);
public:
    Fraction(int num, int den);
    Fraction() : Fraction(0, 1) {}
    void print() const;
    Fraction add(const Fraction& other) const;
    Fraction sub(const Fraction& other) const;
    Fraction mul(const Fraction& other) const;
    Fraction add(int value) const;
    Fraction sub(int value) const;
    Fraction mul(int value) const;
};