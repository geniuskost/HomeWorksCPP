#include <iostream>
#include "MyString.h"
using namespace std;

int main() {
    MyString s1("Hello"), s2("World");
    MyString s3 = s1 + MyString(" ") + s2;
    cout << "Concatenation: " << s3 << endl;

    MyString s4;
    cout << "Enter string: ";
    cin >> s4;
    cout << "You entered: " << s4 << endl;

    cout << "Length: " << s4.getLength() << endl;
    if (s4.getLength() > 0) cout << "First char: " << s4[0] << endl;

    MyString s5 = std::move(s4);
    cout << "Moved string: " << s5 << endl;

    return 0;
}