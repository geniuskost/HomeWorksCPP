#pragma once
#include "Student.h"
class Group {
    std::string groupName;
    Student* students;
    int size;
    int capacity;
public:
    Group(const std::string& name);
    ~Group();
    void addStudent(const Student& s);
    void removeStudent(int index);
    void printStudents() const;
    std::string getName() const;
    void setName(const std::string& name);
    int getSize() const;
};