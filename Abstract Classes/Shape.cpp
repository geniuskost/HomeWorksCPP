#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <string>

class Shape {
public:
    virtual ~Shape() {}
    virtual void Show() const = 0;
    virtual void Save(std::ostream& out) const = 0;
    virtual void Load(std::istream& in) = 0;
    virtual std::string Type() const = 0;
};

class Square : public Shape {
    int x, y;
    int side;
public:
    Square(int x = 0, int y = 0, int side = 0) : x(x), y(y), side(side) {}
    void Show() const override {
        std::cout << "Square: left-top=(" << x << "," << y << "), side=" << side << "\n";
    }
    void Save(std::ostream& out) const override {
        out << "Square " << x << " " << y << " " << side << std::endl;
    }
    void Load(std::istream& in) override {
        in >> x >> y >> side;
    }
    std::string Type() const override { return "Square"; }
};

class Rectangle : public Shape {
    int x, y;
    int width, height;
public:
    Rectangle(int x = 0, int y = 0, int w = 0, int h = 0) : x(x), y(y), width(w), height(h) {}
    void Show() const override {
        std::cout << "Rectangle: left-top=(" << x << "," << y << "), width=" << width << ", height=" << height << "\n";
    }
    void Save(std::ostream& out) const override {
        out << "Rectangle " << x << " " << y << " " << width << " " << height << std::endl;
    }
    void Load(std::istream& in) override {
        in >> x >> y >> width >> height;
    }
    std::string Type() const override { return "Rectangle"; }
};

class Circle : public Shape {
    int cx, cy;
    int radius;
public:
    Circle(int cx = 0, int cy = 0, int r = 0) : cx(cx), cy(cy), radius(r) {}
    void Show() const override {
        std::cout << "Circle: center=(" << cx << "," << cy << "), radius=" << radius << "\n";
    }
    void Save(std::ostream& out) const override {
        out << "Circle " << cx << " " << cy << " " << radius << std::endl;
    }
    void Load(std::istream& in) override {
        in >> cx >> cy >> radius;
    }
    std::string Type() const override { return "Circle"; }
};

std::unique_ptr<Shape> CreateShapeByType(const std::string& type) {
    if (type == "Square")      return std::make_unique<Square>();
    else if (type == "Rectangle") return std::make_unique<Rectangle>();
    else if (type == "Circle")    return std::make_unique<Circle>();
    else return nullptr;
}

int main() {
    std::vector<std::unique_ptr<Shape>> figures;
    figures.push_back(std::make_unique<Square>(1, 2, 10));
    figures.push_back(std::make_unique<Rectangle>(3, 4, 7, 5));
    figures.push_back(std::make_unique<Circle>(5, 6, 9));

    std::ofstream fout("figures.txt");
    fout << figures.size() << std::endl;
    for (const auto& f : figures)
        f->Save(fout);
    fout.close();

    std::vector<std::unique_ptr<Shape>> loadedFigures;
    std::ifstream fin("figures.txt");
    size_t n;
    fin >> n;
    for (size_t i = 0; i < n; ++i) {
        std::string type;
        fin >> type;
        auto shape = CreateShapeByType(type);
        if (shape) {
            shape->Load(fin);
            loadedFigures.push_back(std::move(shape));
        }
    }
    fin.close();

    std::cout << "Loaded shapes:\n";
    for (const auto& f : loadedFigures)
        f->Show();

    return 0;
}