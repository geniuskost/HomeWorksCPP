#include "MyString.h"

MyString::MyString() : str(nullptr), length(0) {}

MyString::MyString(size_t len) : str(new char[len + 1]), length(len) {
    str[0] = '\0';
}

MyString::MyString(const char* s) : length(strlen(s)), str(new char[length + 1]) {
    strcpy_s(str, length + 1, s);
}

MyString::MyString(const MyString& other) : length(other.length), str(new char[other.length + 1]) {
    strcpy_s(str, length + 1, other.str ? other.str : "");
}

MyString::MyString(MyString&& other) noexcept : str(other.str), length(other.length) {
    other.str = nullptr;
    other.length = 0;
}

MyString::~MyString() {
    delete[] str;
}

MyString& MyString::operator=(const MyString& other) {
    if (this != &other) {
        delete[] str;
        length = other.length;
        str = new char[length + 1];
        strcpy_s(str, length + 1, other.str ? other.str : "");
    }
    return *this;
}

MyString& MyString::operator=(MyString&& other) noexcept {
    if (this != &other) {
        delete[] str;
        str = other.str;
        length = other.length;
        other.str = nullptr;
        other.length = 0;
    }
    return *this;
}

MyString MyString::operator+(const MyString& other) const {
    MyString result(length + other.length);
    strcpy_s(result.str, length + 1, str ? str : "");
    strcat_s(result.str, result.length + 1, other.str ? other.str : "");
    return result;
}

char& MyString::operator[](size_t idx) { return str[idx]; }
const char& MyString::operator[](size_t idx) const { return str[idx]; }

size_t MyString::getLength() const { return length; }

std::ostream& operator<<(std::ostream& os, const MyString& s) {
    os << (s.str ? s.str : "");
    return os;
}

std::istream& operator>>(std::istream& is, MyString& s) {
    char buf[1024];
    is >> buf;
    s = MyString(buf);
    return is;
}