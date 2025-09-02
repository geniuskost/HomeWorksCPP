#include <iostream>
using namespace std;

// Minimal helpers without extra headers
int mystrlen(const char* str) {
	int len = 0;
	while (str[len] != '\0') ++len;
	return len;
}

bool isAlpha(char c) {
	return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}
bool isDigit(char c) {
	return (c >= '0' && c <= '9');
}

// 1. Delete char by position
void removeCharAt(char* str, int pos) {
	int len = mystrlen(str);
	if (pos < 0 || pos >= len) return;
	for (int i = pos; i < len; ++i) str[i] = str[i+1];
}

// 2. Delete all occurrences of a given char
void removeAllChar(char* str, char ch) {
	int j = 0;
	for (int i = 0; str[i] != '\0'; ++i) if (str[i] != ch) str[j++] = str[i];
	str[j] = '\0';
}

// 3. Insert char at position
void insertCharAt(char* str, int pos, char ch) {
	int len = mystrlen(str);
	if (pos < 0 || pos > len) return;
	for (int i = len; i >= pos; --i) str[i+1] = str[i];
	str[pos] = ch;
}

// 4. Replace '.' with '!'
void replaceDotWithExcl(char* str) {
	for (int i = 0; str[i] != '\0'; ++i) if (str[i] == '.') str[i] = '!';
}

// 5. Count occurrences of a char
int countChar(const char* str, char ch) {
	int count = 0;
	for (int i = 0; str[i] != '\0'; ++i) if (str[i] == ch) ++count;
	return count;
}

// 6. Count letters, digits, others
void countTypes(const char* str, int& letters, int& digits, int& others) {
	letters = digits = others = 0;
	for (int i = 0; str[i] != '\0'; ++i) {
		if (isAlpha(str[i])) ++letters;
		else if (isDigit(str[i])) ++digits;
		else ++others;
	}
}

// 7a. mystrcmp
int mystrcmp(const char* a, const char* b) {
	int i = 0;
	while (a[i] && b[i]) {
		if (a[i] != b[i]) return (a[i] > b[i]) ? 1 : -1;
		++i;
	}
	if (a[i] == b[i]) return 0;
	return (a[i] > b[i]) ? 1 : -1;
}

// 7b. StringToNumber
int StringToNumber(char* str) {
	int res = 0, i = 0, sign = 1;
	if (str[0] == '-') { sign = -1; i = 1; }
	for (; str[i] != '\0'; ++i) {
		if (isDigit(str[i])) res = res * 10 + (str[i] - '0');
		else break;
	}
	return res * sign;
}

// 7c. NumberToString
char* NumberToString(int number) {
	static char buf[20];
	int i = 0; bool neg = false;
	if (number == 0) { buf[0] = '0'; buf[1] = '\0'; return buf; }
	if (number < 0) { neg = true; number = -number; }
	while (number > 0) { buf[i++] = char('0' + (number % 10)); number /= 10; }
	if (neg) buf[i++] = '-';
	buf[i] = '\0';
	// reverse
	for (int l = 0, r = i - 1; l < r; ++l, --r) { char t = buf[l]; buf[l] = buf[r]; buf[r] = t; }
	return buf;
}

// 7d. Uppercase
char* Uppercase(char* s) {
	for (int i = 0; s[i] != '\0'; ++i) if (s[i] >= 'a' && s[i] <= 'z') s[i] = char(s[i] - 'a' + 'A');
	return s;
}

// 7e. Lowercase
char* Lowercase(char* s) {
	for (int i = 0; s[i] != '\0'; ++i) if (s[i] >= 'A' && s[i] <= 'Z') s[i] = char(s[i] - 'A' + 'a');
	return s;
}

// 7f. mystrrev
char* mystrrev(char* s) {
	int len = mystrlen(s);
	for (int i = 0; i < len/2; ++i) { char t = s[i]; s[i] = s[len-1-i]; s[len-1-i] = t; }
	return s;
}

int main() {
	char str[100];
	cout << "Введіть рядок: ";
	cin.getline(str, 100);

	removeCharAt(str, 2);
	cout << "Після видалення 3-го символу: " << str << '\n';

	removeAllChar(str, 'a');
	cout << "Після видалення всіх 'a': " << str << '\n';

	insertCharAt(str, 1, 'X');
	cout << "Після вставки 'X': " << str << '\n';

	replaceDotWithExcl(str);
	cout << "Після заміни '.' на '!': " << str << '\n';

	cout << "Введіть шуканий символ: ";
	char ch; cin >> ch;
	cout << "Кількість входжень: " << countChar(str, ch) << '\n';

	int letters, digits, others;
	countTypes(str, letters, digits, others);
	cout << "Літер: " << letters << ", Цифр: " << digits << ", Інших: " << others << '\n';

	cout << "Порівняння 'abc' і 'abd': " << mystrcmp("abc", "abd") << '\n';
	cout << "Конвертація '1234' у число: " << StringToNumber((char*)"1234") << '\n';
	cout << "Конвертація 5678 у рядок: " << NumberToString(5678) << '\n';

	char up[20] = "hello"; cout << "Верхній регістр: " << Uppercase(up) << '\n';
	char low[20] = "WORLD"; cout << "Нижній регістр: " << Lowercase(low) << '\n';
	char rev[20] = "reverse"; cout << "Реверс: " << mystrrev(rev) << '\n';

	return 0;
}
