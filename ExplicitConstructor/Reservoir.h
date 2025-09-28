#pragma once
#include <string>
#include <iostream>

enum class ReservoirType { Sea, Lake, Pond, Pool, Unknown };

class Reservoir {
    std::string name;
    double width;
    double length;
    double maxDepth;
    ReservoirType type;
public:
    explicit Reservoir(const std::string& n = "", double w = 0, double l = 0, double d = 0, ReservoirType t = ReservoirType::Unknown);
    Reservoir(const Reservoir& other);
    ~Reservoir() = default;

    double getVolume() const;
    double getArea() const;
    ReservoirType getType() const;
    std::string getName() const;
    double getWidth() const { return width; }
    double getLength() const { return length; }
    double getMaxDepth() const { return maxDepth; }
    void setName(const std::string& n);
    void setWidth(double w);
    void setLength(double l);
    void setMaxDepth(double d);
    void setType(ReservoirType t);

    bool isSameType(const Reservoir& other) const;
    int compareArea(const Reservoir& other) const; // 1: this>other, -1: this<other, 0: equal

    void print() const;
};