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
    Figure* fig = nullptr;
    int choice;

    cout << "Choose a figure:\n";
    cout << "1. Rectangle\n";
    cout << "2. Circle\n";
    cout << "3. Triangle\n";
    cout << "Your choice: ";
    cin >> choice;

    if (choice == 1) {
        int w, h;
        cout << "Enter width: ";
        cin >> w;
        cout << "Enter height: ";
        cin >> h;
        fig = new Rectangle(w, h);
    } else if (choice == 2) {
        int r;
        cout << "Enter radius: ";
        cin >> r;
        fig = new Circe(r);
    } else if (choice == 3) {
        int b, h;
        cout << "Enter base: ";
        cin >> b;
        cout << "Enter height: ";
        cin >> h;
        fig = new Triangle(b, h);
    } else {
        cout << "Invalid choice!" << endl;
        return 1;
    }

    fig->GetArea();
    delete fig;
    return 0;
}