#pragma once
#include <iostream>

class DoublyLinkedList {
    struct Node {
        int value;
        Node* prev;
        Node* next;
        Node(int v) : value(v), prev(nullptr), next(nullptr) {}
    };
    Node* head;
    Node* tail;
    int count;
public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), count(0) {}
    ~DoublyLinkedList() { clear(); }

    void push_front(int value) {
        Node* node = new Node(value);
        node->next = head;
        if (head) head->prev = node;
        head = node;
        if (!tail) tail = node;
        ++count;
    }

    void push_back(int value) {
        Node* node = new Node(value);
        node->prev = tail;
        if (tail) tail->next = node;
        tail = node;
        if (!head) head = node;
        ++count;
    }

    void pop_front() {
        if (!head) return;
        Node* tmp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr;
        delete tmp;
        --count;
    }

    void pop_back() {
        if (!tail) return;
        Node* tmp = tail;
        tail = tail->prev;
        if (tail) tail->next = nullptr;
        else head = nullptr;
        delete tmp;
        --count;
    }

    void insert(int pos, int value) {
        if (pos <= 0) { push_front(value); return; }
        if (pos >= count) { push_back(value); return; }
        Node* cur = head;
        for (int i = 0; i < pos; ++i) cur = cur->next;
        Node* node = new Node(value);
        node->prev = cur->prev;
        node->next = cur;
        cur->prev->next = node;
        cur->prev = node;
        ++count;
    }

    void erase(int pos) {
        if (pos < 0 || pos >= count) return;
        Node* cur = head;
        for (int i = 0; i < pos; ++i) cur = cur->next;
        if (cur->prev) cur->prev->next = cur->next;
        else head = cur->next;
        if (cur->next) cur->next->prev = cur->prev;
        else tail = cur->prev;
        delete cur;
        --count;
    }

    int find(int value) const {
        Node* cur = head;
        int idx = 0;
        while (cur) {
            if (cur->value == value) return idx;
            cur = cur->next;
            ++idx;
        }
        return -1;
    }

    void clear() {
        while (head) pop_front();
    }

    int size() const { return count; }
    bool empty() const { return count == 0; }

    void print_forward() const {
        Node* cur = head;
        while (cur) {
            std::cout << cur->value << " ";
            cur = cur->next;
        }
        std::cout << std::endl;
    }

    void print_backward() const {
        Node* cur = tail;
        while (cur) {
            std::cout << cur->value << " ";
            cur = cur->prev;
        }
        std::cout << std::endl;
    }
};