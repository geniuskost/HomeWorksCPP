#pragma once
#include <string>
class Student {
public:
    std::string name;
    int age;
    std::string university;

    Student();
    Student(const std::string& n, int a, const std::string& u);
};