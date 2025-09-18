#pragma once
#include <vector>
#include "Student.h"

using namespace std;

class Group {
private: 
	string GroupName;
	vector<Student> students;
public:
	Group(const string& name);
	~Group();
	void addStudent(const Student& student);
	void removeStudent(const string& studentName);
	void printStudents() const;
	string getGroupName() const;
	void setGroupName(const string& newName);
};