#include "Group.h"
#include <iostream>
Group::Group(const std::string& name) : groupName(name), size(0), capacity(5) {
    students = new Student[capacity];
}
Group::~Group() {
    delete[] students;
}
void Group::addStudent(const Student& s) {
    if (size == capacity) {
        capacity *= 2;
        Student* newArr = new Student[capacity];
        for (int i = 0; i < size; ++i) newArr[i] = students[i];
        delete[] students;
        students = newArr;
    }
    students[size++] = s;
}
void Group::removeStudent(int index) {
    if (index < 0 || index >= size) return;
    for (int i = index; i < size - 1; ++i) students[i] = students[i + 1];
    --size;
}
void Group::printStudents() const {
    std::cout << "Group: " << groupName << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << i + 1 << ". " << students[i].name << ", " << students[i].age << ", " << students[i].university << std::endl;
    }
}
std::string Group::getName() const { return groupName; }
void Group::setName(const std::string& name) { groupName = name; }
int Group::getSize() const { return size; }