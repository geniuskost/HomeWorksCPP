#include <iostream>
#include <typeinfo>

template <typename T>
void printTypeName(const T& value) {
	std::cout << "Type: " << typeid(value).name() << std::endl;
}