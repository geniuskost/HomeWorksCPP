#include <iostream>

using namespace std;

class Figure{
public:
    virtual double GetArea() = 0;
    virtual ~Figure() {}
};
class Rectangle : public Figure {
private:
    double width;
    double height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double GetArea() override {
        return width * height;
    }
};
class Circle : public Figure {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double GetArea() override {
        return 3.14159 * radius * radius;
    }
};
class Triangle : public Figure {
private:
    double base;
    double height;
public:
    Triangle(double b, double h) : base(b), height(h) {}
    double GetArea() override {
        return 0.5 * base * height;
    }
};

int main() {
    int choice;
    while (true) {
        cout << "Menu:\n";
        cout << "1. Rectangle Area\n";
        cout << "2. Circle Area\n";
        cout << "3. Triangle Area\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 0) break;

        Figure* fig = nullptr;
        switch (choice) {
            case 1: {
                double w, h;
                cout << "Enter width and height: ";
                cin >> w >> h;
                fig = new Rectangle(w, h);
                break;
            }
            case 2: {
                double r;
                cout << "Enter radius: ";
                cin >> r;
                fig = new Circle(r);
                break;
            }
            case 3: {
                double b, h;
                cout << "Enter base and height: ";
                cin >> b >> h;
                fig = new Triangle(b, h);
                break;
            }
            default:
                cout << "Invalid choice.\n";
        }
        if (fig) {
            cout << "Area: " << fig->GetArea() << endl;
            delete fig;
        }
    }
    return 0;
}