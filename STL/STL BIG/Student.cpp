#include "Student.h"
#include <iostream>

Student::Student(const string& name, const vector<int>& grades)
	: name(name), grades(grades) {
}

string Student::getName() const {
	return name;
}

vector<int> Student::getGrades() const {
	return grades;
}

void Student::setName(const string& newName) {
	name = newName;
}

void Student::setGrades(const vector<int>& newGrades) {
	grades = newGrades;
}

void Student::printInfo() const {
	cout << "Name: " << name << ", Grades: ";
	for (int grade : grades) {
		cout << grade << " ";
	}
	cout << endl;
}