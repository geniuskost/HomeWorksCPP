#pragma once
#include <string>
#include <vector>

using namespace std;

class Student {
private:
	string name;
	vector<int> grades;
public:
	Student(const string& name, const vector<int>& grades);
	string getName() const;
	vector<int> getName() const;
	void setName(const string& newName);
	void setGrades(const vector<int>& newGrades);
	void printInfo() const;
	void printInfo() const;