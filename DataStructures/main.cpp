#include <iostream>
#include "DoublyLinkedList.h"
using namespace std;

int main() {
    DoublyLinkedList list;
    list.push_back(1);
    list.push_back(2);
    list.push_front(0);
    list.insert(1, 99);
    list.print_forward();    // 0 99 1 2
    list.print_backward();   // 2 1 99 0
    cout << "Find 99: " << list.find(99) << endl;
    list.erase(1);
    list.print_forward();    // 0 1 2
    list.pop_front();
    list.pop_back();
    list.print_forward();    // 1
    cout << "Size: " << list.size() << endl;
    cout << "Empty: " << list.empty() << endl;
    list.clear();
    cout << "Empty after clear: " << list.empty() << endl;
    return 0;
}