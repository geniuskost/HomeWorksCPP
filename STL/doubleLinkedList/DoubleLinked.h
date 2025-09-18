#pragma once
#include <iostream>
#include <memory>

template <typename T>
class DoubleLinkedList {
private:
	struct Node {
		T data;
		shared_ptr<Node> next;
		weak_ptr<Node> prev;
		Node(const T& value) : data(value), next(nullptr), prev() {}
	};

	shared_ptr<Node> head;
	shared_ptr<Node> tail;
	size_t size;

public:
	DoubleLinkedList();
	~DoubleLinkedList();

	void push_front(const T& value);
	void push_back(const T& value);
	void pop_front();
	void pop_back();
	void print_forward() const;
	void print_backward() const;
	size_t get_size() const;
	bool empty() const;

};
#include "DoubleLinkedList.cpp"