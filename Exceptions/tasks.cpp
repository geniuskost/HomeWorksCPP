#include <iostream>
#include <fstream>

using namespace std;


int toInt(const string& s) {
	if (s.empty()) throw invalid_argument("Empty string");
	size_t idx = 0;
	int sign = 1;
	if (s[0] == '-') {
		sign = -1;
		idx = 1;
	}
	int res = 0;
	for (; idx < s.size(); ++idx) {
		if (s[idx] < '0' || s[idx] > '9') throw invalid_argument("Invalid character in string");
		res = res * 10 + (s[idx] - '0');
	}
	return sign * res;
}

void process() {
	try {
		
		throw runtime_error("Runtime error occurred");
	}
	catch (const exception& e) {
		ofstream fout("exception.txt");
		if (fout) fout << e.what() << endl;
		else
			cerr << "Failed to open exception.txt for writing" << endl;
		throw;
	}
}

void checkPassword(const string& password) {
	if (password.length() < 8) throw length_error("Password too short");
	bool hasDigit = false;
	for (char c : password) {
		if (isdigit(c)) {
			hasDigit = true;
			break;
		}
	}
	if (!hasDigit) throw invalid_argument("Password must contain at least one digit");
}

class AgeException : public exception {
	int age_;
	string msg_;
public;
AgeException(int age) : age_(age) {
	msg_ = "Invalid age: " + to_string(age_);
}
const char* what() const noexcept override {
	return msg_.c_str();
}
};

void vote(string& candidate, int age) {
	if (age < 18 || age > 120) throw AgeException(age);
	cout << "You are eligible to vote." << endl;
}

int main() {
	try {
		cout << toInt("1234") << endl;
		cout << toInt("-5678") << endl;
		cout << toInt("abc") << endl;
	}
	catch (const invalid_argument& e) {
		cerr << "Conversion error: " << e.what() << endl;
	}

	try {
		process();
	}
	catch (const exception& e) {
		cerr << "Caught exception from process: " << e.what() << endl;
	}
	try {
		checkPassword("pass");
		checkPassword("password1");
		checkPassword("nopass");
	}
	catch (const exception& e) {
		cerr << "Password error: " << e.what() << endl;
	}
	try {
		vote("Alice", 15);
		vote("Bob", 25);
	}
	catch (const AgeException& e) {
		cerr << "Age error: " << e.what() << endl;
	}

	return 0;
}
