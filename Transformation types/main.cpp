#include <iostream>
#include <typeinfo>

using namespace std;

template <typename T>
void printTypeName(const T& value) {
	cout << "Type: " << typeid(value).name() << endl;
}

void printCharFromInt(int num) {
	char c = *reinterpret_cast<char*>(&num);
	cout << "Char: " << c << endl;
}
int main() {
	int a = 97;
	double b = 3.14;
	string s = "test";

	printTypeName(a);
	printTypeName(b);
	printTypeName(s);

	printCharFromInt(65);
	printCharFromInt(98);

	return 0;
}