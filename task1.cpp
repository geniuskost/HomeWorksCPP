#include <iostream>
using namespace std;

int toInt(const char* s) {
    if (s == 0 || s[0] == '\0') {
        throw "not a number: empty string";
    }
    int sign = 1;
    int i = 0;
    if (s[0] == '+' || s[0] == '-') {
        if (s[1] == '\0') {
            throw "not a number: only sign";
        }
        sign = (s[0] == '-') ? -1 : 1;
        i = 1;
    }
    int value = 0;
    for (; s[i] != '\0'; ++i) {
        char c = s[i];
        if (c < '0' || c > '9') {
            throw "not a number: contains non-digit";
        }
        value = value * 10 + (c - '0');
    }
    return sign * value;
}

int main() {
    cout << "--- Task 1: toInt ---\n";
    try {
        cout << toInt("123") << "\n";
        cout << toInt("-45") << "\n";
        cout << toInt("+7") << "\n";
        cout << toInt("1a") << "\n";
    } catch (const char* msg) {
        cout << "toInt error: " << msg << "\n";
    }
    return 0;
}
