#include <iostream>
#include "Group.h"
using namespace std;

int main() {
    Group* group = nullptr;
    while (true) {
        cout << "1. Створити групу\n2. Додати студента\n3. Видалити студента\n4. Вивести студентів\n0. Вихід\nВаш вибір: ";
        int choice; cin >> choice;
        if (choice == 0) break;
        if (choice == 1) {
            string name;
            cout << "Введіть ім'я групи: ";
            cin.ignore();
            getline(cin, name);
            delete group;
            group = new Group(name);
        } else if (choice == 2 && group) {
            string n, u; int a;
            cout << "Ім'я: "; cin.ignore(); getline(cin, n);
            cout << "Вік: "; cin >> a;
            cout << "Університет: "; cin.ignore(); getline(cin, u);
            group->addStudent(Student(n, a, u));
        } else if (choice == 3 && group) {
            int idx;
            cout << "Номер студента для видалення: "; cin >> idx;
            group->removeStudent(idx - 1);
        } else if (choice == 4 && group) {
            group->printStudents();
        } else {
            cout << "Спочатку створіть групу!\n";
        }
    }
    delete group;
    return 0;
}