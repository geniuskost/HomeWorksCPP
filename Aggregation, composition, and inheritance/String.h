#pragma once
#include <iostream>
#include <cstring>

class String {
protected:
    char* str;
    size_t len;
public:
    String() : str(nullptr), len(0) {}
    String(const char* s) : len(strlen(s)), str(new char[len + 1]) { strcpy_s(str, len + 1, s); }
    String(const String& other) : len(other.len), str(new char[len + 1]) { strcpy_s(str, len + 1, other.str ? other.str : ""); }
    String& operator=(const String& other) {
        if (this != &other) {
            delete[] str;
            len = other.len;
            str = new char[len + 1];
            strcpy_s(str, len + 1, other.str ? other.str : "");
        }
        return *this;
    }
    size_t length() const { return len; }
    void clear() { delete[] str; str = nullptr; len = 0; }
    ~String() { delete[] str; }
    String operator+(const String& other) const {
        String res;
        res.len = len + other.len;
        res.str = new char[res.len + 1];
        strcpy_s(res.str, len + 1, str ? str : "");
        strcat_s(res.str, res.len + 1, other.str ? other.str : "");
        return res;
    }
    String& operator+=(const String& other) {
        *this = *this + other;
        return *this;
    }
    bool operator==(const String& other) const { return strcmp(str, other.str) == 0; }
    bool operator!=(const String& other) const { return !(*this == other); }
};

class BitString : public String {
public:
    BitString() : String() {}
    BitString(const char* s) : String() {
        bool valid = true;
        for (size_t i = 0; i < strlen(s); ++i)
            if (s[i] != '0' && s[i] != '1') { valid = false; break; }
        if (valid) {
            len = strlen(s);
            str = new char[len + 1];
            strcpy_s(str, len + 1, s);
        } else {
            str = nullptr;
            len = 0;
        }
    }
    BitString(const BitString& other) : String(other) {}
    BitString& operator=(const BitString& other) {
        String::operator=(other);
        return *this;
    }
    ~BitString() {}

    void changeSign() {
        if (!str || len == 0) return;
        // Инвертируем все биты кроме знакового
        for (size_t i = 1; i < len; ++i)
            str[i] = (str[i] == '0') ? '1' : '0';
        // Прибавляем 1 (доп. код)
        for (int i = len - 1; i > 0; --i) {
            if (str[i] == '0') { str[i] = '1'; break; }
            else str[i] = '0';
        }
        str[0] = (str[0] == '0') ? '1' : '0'; // меняем знак
    }
    BitString operator+(const BitString& other) const {
        // Просто конкатенация, не арифметика
        BitString res;
        res.len = len + other.len;
        res.str = new char[res.len + 1];
        strcpy_s(res.str, len + 1, str ? str : "");
        strcat_s(res.str, res.len + 1, other.str ? other.str : "");
        return res;
    }
    BitString& operator+=(const BitString& other) {
        *this = *this + other;
        return *this;
    }
    bool operator==(const BitString& other) const { return strcmp(str, other.str) == 0; }
    bool operator!=(const BitString& other) const { return !(*this == other); }
};