#include <iostream>
#include <fstream>
#include <vector>
#include <memory>

using namespace std;

class Shape {
public
	virtual ~Shape() {}
	virtual void Show() const = 0;
	virtual void Save(ostream& out) const = 0;
	virtual void Load(istream& in) = 0;
	virtual string Type() const = 0;
};

Class Square : public Shape{
	int x,y, side;
public:
	Square(int x = 0, int y = 0, int side = 0) : x(x), y(y), side(side) {}
	void Show() const override {
		cout << "Square: (" << x << "," << y << "), side=" << side << endl;
	}
	void Save(ostream& out) const override {
		out << Type() << " " << x << " " << y << " " << side << endl;
	}
	void Load(istream& in) override {
		in >> x >> y >> side;
	}
	string Type() const override {
		return "Square";
	}
};

class Rectangle : public Shape {
	int x, y, width, height;
public:
	Rectangle(int x = 0, int y = 0, int width = 0, int height = 0) : x(x), y(y), width(width), height(height) {}
	void Show() const override {
		cout << "Rectangle: (" << x << "," << y << "), width=" << width << ", height=" << height << endl;
	}
	void Save(ostream& out) const override {
		out << Type() << " " << x << " " << y << " " << width << " " << height << endl;
	}
	void Load(istream& in) override {
		in >> x >> y >> width >> height;
	}
	string Type() const override {
		return "Rectangle";
	}
};

class Circle : public Shape {
	int cx, cy, radius;
public:
	Circle(int cx = 0, int cy = 0, int radius = 0) : cx(cx), cy(cy), radius(radius) {}
	void Show() const override {
		cout << "Circle: (" << cx << "," << cy << "), radius=" << radius << endl;
	}
	void Save(ostream& out) const override {
		out << Type() << " " << cx << " " << cy << " " << radius << endl;
	}
	void Load(istream& in) override {
		in >> cx >> cy >> radius;
	}
	string Type() const override {
		return "Circle";
	}

};

int main() {
	vector<unique_ptr<Shape>> figures;
	figures.push_back(make_unique<Square>(1, 2, 10));
	figures.push_back(make_unique<Rectangle>(3, 4, 20, 15));
	figures.push_back(make_unique<Circle>(5, 6, 7));

	ofstream fout("figures.txt");
	fout << figures.size() << endl;
	for (const auto& fig : figures) {
		fig->Save(fout);
		fout.close();
	}

	vector<unique_ptr<Shape>> loadedFigures;
	ifstream fin("figures.txt");
	size_t n;
	fin >> n;
	for(size_t i = 0; i < n; i++) 
	{
		string type;
		fin >> type;
		auto shape = CreateShapeByType(type);
		if (shape) {
			shape->Load(fin);
			loadedFigures.push_back(move(shape));
		}

	}
	fin.close();

	cout << "Loaded Figures:" << endl;
	for (const auto& fig : loadedFigures) {
		fig->Show();
	}
}
