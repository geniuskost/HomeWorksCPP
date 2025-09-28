#pragma once
#include <iostream>
#include <cstring>

template <typename T>
class Array {
    T* data;
    int size;
    int count;
    int grow;
public:
    Array(int sz = 0, int gr = 1) : size(sz), count(0), grow(gr) {
        data = size > 0 ? new T[size] : nullptr;
    }
    Array(const Array& other) : size(other.size), count(other.count), grow(other.grow) {
        data = size > 0 ? new T[size] : nullptr;
        for (int i = 0; i < count; ++i) data[i] = other.data[i];
    }
    ~Array() { delete[] data; }

    int GetSize() const { return size; }
    void SetSize(int newSize, int newGrow = 1) {
        if (newSize == size) return;
        T* newData = newSize > 0 ? new T[newSize] : nullptr;
        int minCount = (newSize < count) ? newSize : count;
        for (int i = 0; i < minCount; ++i) newData[i] = data[i];
        delete[] data;
        data = newData;
        size = newSize;
        grow = newGrow;
        if (count > size) count = size;
    }
    int GetUpperBound() const { return count - 1; }
    bool IsEmpty() const { return count == 0; }
    void FreeExtra() {
        if (count < size) SetSize(count, grow);
    }
    void RemoveAll() {
        delete[] data;
        data = nullptr;
        size = 0;
        count = 0;
    }
    T& GetAt(int idx) { return data[idx]; }
    const T& GetAt(int idx) const { return data[idx]; }
    void SetAt(int idx, const T& value) {
        if (idx < size) data[idx] = value;
        if (idx >= count) count = idx + 1;
    }
    T& operator[](int idx) { return data[idx]; }
    const T& operator[](int idx) const { return data[idx]; }
    void Add(const T& value) {
        if (count >= size) SetSize(size + grow, grow);
        data[count++] = value;
    }
    void Append(const Array& other) {
        for (int i = 0; i < other.count; ++i) Add(other.data[i]);
    }
    Array& operator=(const Array& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            count = other.count;
            grow = other.grow;
            data = size > 0 ? new T[size] : nullptr;
            for (int i = 0; i < count; ++i) data[i] = other.data[i];
        }
        return *this;
    }
    T* GetData() { return data; }
    void InsertAt(int idx, const T& value) {
        if (count >= size) SetSize(size + grow, grow);
        for (int i = count; i > idx; --i) data[i] = data[i - 1];
        data[idx] = value;
        ++count;
    }
    void RemoveAt(int idx, int num = 1) {
        for (int i = idx; i < count - num; ++i) data[i] = data[i + num];
        count -= num;
        if (count < 0) count = 0;
    }
};