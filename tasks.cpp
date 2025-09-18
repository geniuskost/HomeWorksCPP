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

class AgeException {
public:
	explicit AgeException(int age) : m_age(age) {}
	int age() const { return m_age; }
private:
	int m_age;
};

void vote(const char* candidate, int age) {
	if (age < 18) {
		throw AgeException(age);
	}
	cout << "Voted for: " << candidate << "\n";
}

void doWorkThatThrows() {
	toInt("12x");
}

void process() {
	try {
		doWorkThatThrows();
	} catch (const char* msg) {
		throw;
	}
}

void checkPassword(const char* pass) {
	if (pass == 0) {
		throw "Password is null";
	}
	int len = 0;
	bool hasDigit = false;
	for (int i = 0; pass[i] != '\0'; ++i) {
		char c = pass[i];
		if (c >= '0' && c <= '9') hasDigit = true;
		++len;
	}
	if (len < 8) {
		throw "Password must be at least 8 characters";
	}
	if (!hasDigit) {
		throw "Password must contain at least one digit";
	}
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

	cout << "\n--- Task 2: process (catch + rethrow) ---\n";
	try {
		process();
	} catch (const char* msg) {
		cout << "process rethrew: " << msg << "\n";
	}

	cout << "\n--- Task 3: password check ---\n";
	try {
		checkPassword("qwerty12");
		cout << "pass OK\n";
		checkPassword("short");
	} catch (const char* msg) {
		cout << "password error: " << msg << "\n";
	}
	try {
		checkPassword("NoDigitsHere");
	} catch (const char* msg) {
		cout << "password error: " << msg << "\n";
	}

	cout << "\n--- Task 4: vote ---\n";
	try {
		vote("Alice", 20);
		vote("Bob", 16);
	} catch (const AgeException& e) {
		cout << "vote error: age is too low: " << e.age() << "\n";
	}

	return 0;
}

