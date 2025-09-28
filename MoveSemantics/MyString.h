#pragma once
#include <iostream>
#include <cstring>

class MyString {
    char* str;
    size_t length;
public:
    MyString();
    explicit MyString(size_t len);
    MyString(const char* s);
    MyString(const MyString& other);
    MyString(MyString&& other) noexcept;
    ~MyString();

    MyString& operator=(const MyString& other);
    MyString& operator=(MyString&& other) noexcept;

    MyString operator+(const MyString& other) const;
    char& operator[](size_t idx);
    const char& operator[](size_t idx) const;

    size_t getLength() const;

    friend std::ostream& operator<<(std::ostream& os, const MyString& s);
    friend std::istream& operator>>(std::istream& is, MyString& s);
};