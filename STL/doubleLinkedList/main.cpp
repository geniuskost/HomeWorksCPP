#include "DoubleLinked.h"
#include <iostream>

using namespace std;

int main() {
	DoubleLinked<int> list;
	list.push_back(10);
	list.push_back(20);
	list.push_front(5);
	list.print_forward();
	list.print_backward();

	list.pop_front();
	list.pop_back();

	list.pop_back();
	list.print_forward();

	DoubleLinkedList<string> strList;
	strList.push_back("Hello");
	strList.push_front("World");
	strList.print_forward();

	return 0;

}