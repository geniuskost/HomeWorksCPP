
#include <iostream>
using namespace std;

// Власна функція для знаходження довжини рядка
int mystrlen(const char* str) {
    int len = 0;
    while (str[len] != '\0') ++len;
    return len;
}

// 1. Видалити символ із заданим номером
void removeCharAt(char* str, int pos) {
    int len = mystrlen(str);
    if (pos < 0 || pos >= len) return;
    for (int i = pos; i < len; ++i) {
        str[i] = str[i+1];
    }
}

// 2. Видалити всі входження заданого символу
void removeAllChar(char* str, char ch) {
    int j = 0;
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] != ch) str[j++] = str[i];
    }
    str[j] = '\0';
}

// 3. Вставити символ у вказану позицію
void insertCharAt(char* str, int pos, char ch) {
    int len = mystrlen(str);
    if (pos < 0 || pos > len) return;
    for (int i = len; i >= pos; --i) {
        str[i+1] = str[i];
    }
    str[pos] = ch;
}

// 4. Замінити всі '.' на '!'
void replaceDotWithExcl(char* str) {
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] == '.') str[i] = '!';
    }
}

// 5. Порахувати кількість входжень символу
int countChar(const char* str, char ch) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] == ch) ++count;
    }
    return count;
}

// 6. Визначити кількість літер, цифр, інших символів
bool isAlpha(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}
bool isDigit(char c) {
    return (c >= '0' && c <= '9');
}
void countTypes(const char* str, int& letters, int& digits, int& others) {
    letters = digits = others = 0;
    for (int i = 0; str[i] != '\0'; ++i) {
        if (isAlpha(str[i])) ++letters;
        else if (isDigit(str[i])) ++digits;
        else ++others;
    }
}

// 7. mystrcmp
int mystrcmp(const char* str1, const char* str2) {
    int i = 0;
    while (str1[i] && str2[i]) {
        if (str1[i] != str2[i])
            return (str1[i] > str2[i]) ? 1 : -1;
        ++i;
    }
    if (str1[i] == str2[i]) return 0;
    return (str1[i] > str2[i]) ? 1 : -1;
}

// 7. StringToNumber
int StringToNumber(char* str) {
    int res = 0, i = 0, sign = 1;
    if (str[0] == '-') { sign = -1; i = 1; }
    for (; str[i] != '\0'; ++i) {
        if (isDigit(str[i])) res = res * 10 + (str[i] - '0');
        else break;
    }
    return res * sign;
}

// 7. NumberToString
char* NumberToString(int number) {
    static char buf[20];
    int i = 0, sign = 0;
    if (number < 0) { sign = 1; number = -number; }
    do {
        buf[i++] = (number % 10) + '0';
        number /= 10;
    } while (number > 0);
    if (sign) buf[i++] = '-';
    buf[i] = '\0';
    // reverse
    for (int j = 0; j < i/2; ++j) {
        char t = buf[j]; buf[j] = buf[i-1-j]; buf[i-1-j] = t;
    }
    return buf;
}

// 7. Uppercase
char* Uppercase(char* str1) {
    for (int i = 0; str1[i] != '\0'; ++i) {
        if (str1[i] >= 'a' && str1[i] <= 'z') str1[i] = str1[i] - 'a' + 'A';
    }
    return str1;
}

// 7. Lowercase
char* Lowercase(char* str1) {
    for (int i = 0; str1[i] != '\0'; ++i) {
        if (str1[i] >= 'A' && str1[i] <= 'Z') str1[i] = str1[i] - 'A' + 'a';
    }
    return str1;
}

// 7. mystrrev
char* mystrrev(char* str) {
    int len = mystrlen(str);
    for (int i = 0; i < len/2; ++i) {
        char t = str[i];
        str[i] = str[len-1-i];
        str[len-1-i] = t;
    }
    return str;
}

int main() {
    char str[100];
    cout << "Введіть рядок: ";
    cin.getline(str, 100);

    // Приклад використання функцій
    removeCharAt(str, 2); // видалити 3-й символ
    cout << "Після видалення 3-го символу: " << str << endl;

    removeAllChar(str, 'a'); // видалити всі 'a'
    cout << "Після видалення всіх 'a': " << str << endl;

    insertCharAt(str, 1, 'X'); // вставити 'X' у 2-у позицію
    cout << "Після вставки 'X': " << str << endl;

    replaceDotWithExcl(str); // замінити '.' на '!'
    cout << "Після заміни '.' на '!': " << str << endl;

    cout << "Введіть шуканий символ: ";
    char ch;
    cin >> ch;
    cout << "Кількість входжень: " << countChar(str, ch) << endl;

    int letters, digits, others;
    countTypes(str, letters, digits, others);
    cout << "Літер: " << letters << ", Цифр: " << digits << ", Інших: " << others << endl;

    // mystrcmp
    cout << "Порівняння 'abc' і 'abd': " << mystrcmp("abc", "abd") << endl;

    // StringToNumber
    cout << "Конвертація '1234' у число: " << StringToNumber((char*)"1234") << endl;

    // NumberToString
    cout << "Конвертація 5678 у рядок: " << NumberToString(5678) << endl;

    // Uppercase
    char up[20] = "hello";
    cout << "Верхній регістр: " << Uppercase(up) << endl;

    // Lowercase
    char low[20] = "WORLD";
    cout << "Нижній регістр: " << Lowercase(low) << endl;

    // mystrrev
    char rev[20] = "reverse";
    cout << "Реверс: " << mystrrev(rev) << endl;

    return 0;
}

// 1. Видалити символ із заданим номером
void removeCharAt(char* str, int pos) {
    int len = strlen(str);
    if (pos < 0 || pos >= len) return;
    for (int i = pos; i < len; ++i) {
        str[i] = str[i+1];
    }
}

// 2. Видалити всі входження заданого символу
void removeAllChar(char* str, char ch) {
    int len = strlen(str), j = 0;
    for (int i = 0; i < len; ++i) {
        if (str[i] != ch) str[j++] = str[i];
    }
    str[j] = '\0';
}

// 3. Вставити символ у вказану позицію
void insertCharAt(char* str, int pos, char ch) {
    int len = strlen(str);
    if (pos < 0 || pos > len) return;
    for (int i = len; i >= pos; --i) {
        str[i+1] = str[i];
    }
    str[pos] = ch;
}

// 4. Замінити всі '.' на '!'
void replaceDotWithExcl(char* str) {
    for (int i = 0; str[i]; ++i) {
        if (str[i] == '.') str[i] = '!';
    }
}

// 5. Порахувати кількість входжень символу
int countChar(const char* str, char ch) {
    int count = 0;
    for (int i = 0; str[i]; ++i) {
        if (str[i] == ch) ++count;
    }
    return count;
}

// 6. Визначити кількість літер, цифр, інших символів
void countTypes(const char* str, int& letters, int& digits, int& others) {
    letters = digits = others = 0;
    for (int i = 0; str[i]; ++i) {
        if (isalpha(str[i])) ++letters;
        else if (isdigit(str[i])) ++digits;
        else ++others;
    }
}

// 7. mystrcmp
int mystrcmp(const char* str1, const char* str2) {
    int cmp = strcmp(str1, str2);
    if (cmp == 0) return 0;
    return (cmp > 0) ? 1 : -1;
}

// 7. StringToNumber
int StringToNumber(char* str) {
    return atoi(str);
}

// 7. NumberToString
char* NumberToString(int number) {
    static char buf[20];
    sprintf(buf, "%d", number);
    return buf;
}

// 7. Uppercase
char* Uppercase(char* str1) {
    for (int i = 0; str1[i]; ++i) str1[i] = toupper(str1[i]);
    return str1;
}

// 7. Lowercase
char* Lowercase(char* str1) {
    for (int i = 0; str1[i]; ++i) str1[i] = tolower(str1[i]);
    return str1;
}

// 7. mystrrev
char* mystrrev(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len/2; ++i) {
        char t = str[i];
        str[i] = str[len-1-i];
        str[len-1-i] = t;
    }
    return str;
}

int main() {
    char str[100];
    cout << "Введіть рядок: ";
    cin.getline(str, 100);

    // Приклад використання функцій
    removeCharAt(str, 2); // видалити 3-й символ
    cout << "Після видалення 3-го символу: " << str << endl;

    removeAllChar(str, 'a'); // видалити всі 'a'
    cout << "Після видалення всіх 'a': " << str << endl;

    insertCharAt(str, 1, 'X'); // вставити 'X' у 2-у позицію
    cout << "Після вставки 'X': " << str << endl;

    replaceDotWithExcl(str); // замінити '.' на '!'
    cout << "Після заміни '.' на '!': " << str << endl;

    cout << "Введіть шуканий символ: ";
    char ch;
    cin >> ch;
    cout << "Кількість входжень: " << countChar(str, ch) << endl;

    int letters, digits, others;
    countTypes(str, letters, digits, others);
    cout << "Літер: " << letters << ", Цифр: " << digits << ", Інших: " << others << endl;

    // mystrcmp
    cout << "Порівняння 'abc' і 'abd': " << mystrcmp("abc", "abd") << endl;

    // StringToNumber
    cout << "Конвертація '1234' у число: " << StringToNumber((char*)"1234") << endl;

    // NumberToString
    cout << "Конвертація 5678 у рядок: " << NumberToString(5678) << endl;

    // Uppercase
    char up[20] = "hello";
    cout << "Верхній регістр: " << Uppercase(up) << endl;

    // Lowercase
    char low[20] = "WORLD";
    cout << "Нижній регістр: " << Lowercase(low) << endl;

    // mystrrev
    char rev[20] = "reverse";
    cout << "Реверс: " << mystrrev(rev) << endl;

    return 0;
}
