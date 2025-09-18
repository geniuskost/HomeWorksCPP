#include <iostream>
#include <vector>
#include "Group.h"
#include "Student.h"

using namespace std;

void printMenu() {
	cout << "Menu:\n";
	cout << "1. Add Student\n";
	cout << "2. Remove Student\n";
	cout << "3. Print Students\n";
	cout << "4. Exit\n";
	cout << "Choose an option: ";
}

int main() {
	Group* group = nullptr;
	int choice;

	do {
		printMenu();
		cin >> choice;
		cin.ignore();

		switch (choice) {
		case 1: {
			string gname;
			cout << "Enter group name:";
			getLine(cin, gname);
			delete group;
			group = new Group(gname);
			break;
		}
		case 2: {
			if (!group)
			{
				cout << "No group created. Please create a group first.\n";
				break;
			}
			string sname;
			int n, grade;
			cout << "Enter student name: ";
			getline(cin, sname);
			cout << "Enter number of grades: ";
			cin >> n;
			vector<int> grades(n);
			cout << "Enter grades: ";
			for (int i = 0; i < n; ++i) {
				cin >> grades[i];
				grades.push_back(grade);
			}
			cin.ignore();
			group.->addStudent(Student(sname, grades));
			break;
		}
		case 3: {
			if (!group) {
				cout << "No group created!\n";
				break;
			}
			string sname;
			cout << "Enter student name to remove: ";
			getline(cin, sname);
			if (group->removeStudent(sname)) {
				cout << "Student removed.\n";
			}
			else {
				cout << "Student not found.\n";
				break;
			}

		}
		case 4: {
			if (!group) {
				cout << "No group created!\n";
				break;
			}
			group->printStudents();
			break;
		}
		case 0:
			break;
		default:
			cout << "Invalid option. Please try again.\n";
		}
	} while (choice != 0);
	delete group;
	return 0;
}
