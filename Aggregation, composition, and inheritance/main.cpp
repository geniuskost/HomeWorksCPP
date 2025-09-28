#include "Pet.h"
#include "String.h"
using namespace std;

int main() {
    Dog d("Rex", 5, "Shepherd");
    Cat c("Murka", 3, "Black");
    Parrot p("Kesha", 2, "Ara");
    d.print(); c.print(); p.print();

    String s1("Hello"), s2("World");
    String s3 = s1 + s2;
    cout << (s1 == s2 ? "Equal" : "Not equal") << endl;
    s3.clear();

    BitString b1("10101"), b2("111");
    BitString b3 = b1 + b2;
    cout << (b1 == b2 ? "Equal" : "Not equal") << endl;
    b1.changeSign();
    return 0;
}