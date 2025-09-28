#include "Fraction.h"

int Fraction::gcd(int a, int b) {
    while (b) { int t = b; b = a % b; a = t; }
    return a;
}

void Fraction::reduce() {
    int d = gcd(abs(numerator), abs(denominator));
    if (d) { numerator /= d; denominator /= d; }
    if (denominator < 0) { numerator = -numerator; denominator = -denominator; }
}

Fraction::Fraction(int num, int den) : numerator(num), denominator(den) {
    reduce();
}

void Fraction::print() const {
    std::cout << numerator << "/" << denominator << std::endl;
}

Fraction Fraction::add(const Fraction& other) const {
    return Fraction(numerator * other.denominator + other.numerator * denominator, denominator * other.denominator);
}
Fraction Fraction::sub(const Fraction& other) const {
    return Fraction(numerator * other.denominator - other.numerator * denominator, denominator * other.denominator);
}
Fraction Fraction::mul(const Fraction& other) const {
    return Fraction(numerator * other.numerator, denominator * other.denominator);
}
Fraction Fraction::add(int value) const {
    return Fraction(numerator + value * denominator, denominator);
}
Fraction Fraction::sub(int value) const {
    return Fraction(numerator - value * denominator, denominator);
}
Fraction Fraction::mul(int value) const {
    return Fraction(numerator * value, denominator);
}