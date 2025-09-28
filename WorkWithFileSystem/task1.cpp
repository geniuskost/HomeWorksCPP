#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream file1("file1.txt"), file2("file2.txt");
    string line1, line2;
    bool identical = true;
    while (getline(file1, line1) && getline(file2, line2)) {
        if (line1 != line2) {
            cout << "Не совпадает:\n" << line1 << "\n" << line2 << endl;
            identical = false;
        }
    }
    while (getline(file1, line1)) {
        cout << "В первом файле лишняя строка:\n" << line1 << endl;
        identical = false;
    }
    while (getline(file2, line2)) {
        cout << "Во втором файле лишняя строка:\n" << line2 << endl;
        identical = false;
    }
    if (identical) cout << "Файлы совпадают построчно." << endl;
    return 0;
}