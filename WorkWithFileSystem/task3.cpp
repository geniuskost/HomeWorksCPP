#include <iostream>
#include <fstream>
#include <string>
using namespace std;

char caesar(char c, int key) {
    // Для латиницы
    if (c >= 'A' && c <= 'Z') return 'A' + (c - 'A' + key) % 26;
    if (c >= 'a' && c <= 'z') return 'a' + (c - 'a' + key) % 26;
    if (c >= 'А' && c <= 'Я') return 'А' + (c - 'А' + key) % 32;
    if (c >= 'а' && c <= 'я') return 'а' + (c - 'а' + key) % 32;
    return c;
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int key = 3;
    string line;
    while (getline(fin, line)) {
        for (char &c : line) {
            c = caesar(c, key);
        }
        fout << line << endl;
    }
    return 0;
}