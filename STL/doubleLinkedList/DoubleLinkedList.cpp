#pragma once
#include "DoubleLinkedList.h"

template <typename T>
DoubleLinkedList<T>::DoubleLinkedList() : head(nullptr), tail(nullptr), size(0) {}

template <typename T>
DoubleLinkedList<T>::~DoubleLinkedList() {
	while (head) {
		pop_front();
	}
}

template <typename T>
void DoubleLinkedList<T>::push_front(const T& value) {
	auto newNode = make_shared<Node>(value);
	if (head) {
		head->prev = newNode;
	}
	head = newNode;
	if (!tail) tail = head;
	size++;
}

template <typename T>
void DoubleLinkedList<T>::push_back(const T& value) {
    auto newNode = std::make_shared<Node>(value);
    newNode->prev = tail;
    if (tail) {
        tail->next = newNode;
    }
    tail = newNode;
    if (!head) head = tail;
    ++size;
}

template <typename T>
void DoubleLinkedList<T>::pop_front() {
    if (!head) return;
    head = head->next;
    if (head)
        head->prev.reset();
    else
        tail.reset();
    --size;
}

template <typename T>
void DoubleLinkedList<T>::pop_back() {
    if (!tail) return;
    auto prev = tail->prev.lock();
    if (prev) {
        prev->next.reset();
        tail = prev;
    } else {
        head.reset();
        tail.reset();
    }
    --size;
}

template <typename T>
void DoubleLinkedList<T>::print_forward() const {
    auto current = head;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

template <typename T>
void DoubleLinkedList<T>::print_backward() const {
    auto current = tail;
    while (current) {
        std::cout << current->data << " ";
        current = current->prev.lock();
    }
    std::cout << std::endl;
}

template <typename T>
size_t DoubleLinkedList<T>::get_size() const {
    return size;
}

template <typename T>
bool DoubleLinkedList<T>::empty() const {
    return size == 0;
}