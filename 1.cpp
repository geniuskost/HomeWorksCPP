#include <iostream>

using namespace std;

class Figure{
protected:
    int width, height;
public:
    virtual void GetArea() = 0;
    Figure(int w, int h) : width(w), height(h) {}
};
class Rectangle : public Figure {
public:
    Rectangle(int w, int h) : Figure(w, h) {}
    void GetArea() override {
        cout << "Rectangle area: " << width * height << endl;
    }
};
class Circe : public Figure {
public:
    Circe(int r) : Figure(r, r) {}
    void GetArea() override {
        cout << "Circle area: " << 3.14 * width * width << endl;
    }
};
class Triangle : public Figure {
public:
    Triangle(int b, int h) : Figure(b, h) {}
    void GetArea() override {
        cout << "Triangle area: " << 0.5 * width * height << endl;
    }
};

int main() {

}