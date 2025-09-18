#include <iostream>

void printCharFromInt(int num) {
	char c = *reinterpret_cast<char*>(&num);
	cout << "Char:" << c << endl;
}