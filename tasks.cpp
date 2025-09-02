#include <iostream>
using namespace std;
int toInt(double x) {
	return static_cast<int>(x);
}
struct Shape {
	virtual ~Shape() {}
	virtual void draw() const { cout << "Shape::draw()\n"; }
};

struct Circle : public Shape {
	void draw() const override { cout << "Circle::draw()\n"; }
};
char* voidToChar(void* p) {
	return static_cast<char*>(p);
}
struct Vehicle {
	virtual ~Vehicle() {}
	virtual void move() const { cout << "Vehicle moving\n"; }
};

struct Car : public Vehicle {
	void move() const override { cout << "Car driving\n"; }
};

struct Bicycle : public Vehicle {
	void move() const override { cout << "Bicycle pedaling\n"; }
};
void useAsCar(Vehicle& v) {
	try {
		Car& c = dynamic_cast<Car&>(v);
		cout << "Downcast to Car& success. ";
		c.move();
	} catch (const bad_cast&) {
		cout << "Downcast to Car& failed (std::bad_cast).\n";
	}
}

int main() {
	cout << "=== Task 1 ===\n";
	double dx = 42.9;
	int ix = toInt(dx);
	cout << "double " << dx << " -> int " << ix << "\n\n";

	cout << "=== Task 2 ===\n";
	Circle c;
	Shape* sPtr = &c;
	sPtr->draw();
	Circle* cBack = static_cast<Circle*>(sPtr);
	cBack->draw();
	cout << "\n";

	cout << "=== Task 3 ===\n";
	char buffer[] = "Hello from void* -> char*";
	void* vp = buffer;
	char* cp = voidToChar(vp);
	cout << cp << "\n\n";

	cout << "=== Task 4 ===\n";
	Vehicle* garage[4];
	garage[0] = new Car();
	garage[1] = new Bicycle();
	garage[2] = new Car();
	garage[3] = new Bicycle();

	for (int i = 0; i < 4; ++i) {
		if (Car* asCar = dynamic_cast<Car*>(garage[i])) {
			cout << "Index " << i << ": Car -> ";
			asCar->move();
		} else if (Bicycle* asBike = dynamic_cast<Bicycle*>(garage[i])) {
			cout << "Index " << i << ": Bicycle -> ";
			asBike->move();
		} else {
			cout << "Index " << i << ": Unknown Vehicle\n";
		}
	}
	cout << "\n";

	cout << "=== Task 5 ===\n";
	Car realCar;
	Bicycle realBike;
	useAsCar(realCar);
	useAsCar(realBike);
	for (int i = 0; i < 4; ++i) {
		delete garage[i];
	}

	return 0;
}

