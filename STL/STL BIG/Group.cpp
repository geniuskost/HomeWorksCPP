#include "Group.h"
#include <iostream>

using namespace std;

Group::Group(const string& name) : groupName(name) {}

Group::~Group() {}

void Group::addStudent(const Student& student) {
	students.push_back(student);
}

bool Group::removeStudent(const string& studentName) {
	for (auto it = students.begin(); it != students.end(); ++it) {
		if (it->getName() == studentName) {
			students.erase(it);
			return true;
		}
	}
	return false;
}

void Group::printStudents() const {
	cout << "Group: " << groupName << endl;
	for (const auto& student : students) {
		student.printInfo();
	}
	for (const auto& student : students) {
		student.printInfo();
	}
}
string Group::getGroupName() const {
	return groupName;
}

void Group::setGroupName(const string& newName) {
	groupName = newName;
}