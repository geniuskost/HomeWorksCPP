#include "Reservoir.h"

Reservoir::Reservoir(const std::string& n, double w, double l, double d, ReservoirType t)
    : name(n), width(w), length(l), maxDepth(d), type(t) {}

Reservoir::Reservoir(const Reservoir& other)
    : name(other.name), width(other.width), length(other.length), maxDepth(other.maxDepth), type(other.type) {}

double Reservoir::getVolume() const { return width * length * maxDepth; }
double Reservoir::getArea() const { return width * length; }
ReservoirType Reservoir::getType() const { return type; }
std::string Reservoir::getName() const { return name; }
void Reservoir::setName(const std::string& n) { name = n; }
void Reservoir::setWidth(double w) { width = w; }
void Reservoir::setLength(double l) { length = l; }
void Reservoir::setMaxDepth(double d) { maxDepth = d; }
void Reservoir::setType(ReservoirType t) { type = t; }

bool Reservoir::isSameType(const Reservoir& other) const { return type == other.type; }

int Reservoir::compareArea(const Reservoir& other) const {
    if (!isSameType(other)) return 0;
    if (getArea() > other.getArea()) return 1;
    if (getArea() < other.getArea()) return -1;
    return 0;
}

void Reservoir::print() const {
    std::cout << "Назва: " << name << "\nТип: ";
    switch (type) {
        case ReservoirType::Sea: std::cout << "Море"; break;
        case ReservoirType::Lake: std::cout << "Озеро"; break;
        case ReservoirType::Pond: std::cout << "Ставок"; break;
        case ReservoirType::Pool: std::cout << "Басейн"; break;
        default: std::cout << "Невідомо";
    }
    std::cout << "\nШирина: " << width << "\nДовжина: " << length << "\nМакс. глибина: " << maxDepth
              << "\nПлоща: " << getArea() << "\nОб'єм: " << getVolume() << "\n";
}