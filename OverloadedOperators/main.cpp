#include <iostream>
#include "Overcoat.h"
#include "Flat.h"
using namespace std;

int main() {
    Overcoat o1("Пальто", 1000), o2("Пальто", 1200), o3("Куртка", 800);
    cout << (o1 == o2 ? "Типи однакові\n" : "Типи різні\n");
    cout << (o2 > o1 ? "o2 дорожче\n" : "o2 не дорожче\n");
    o1 = o3;
    cout << "o1 тип: " << o1.getType() << ", ціна: " << o1.getPrice() << endl;

    Flat f1(50, 50000), f2(50, 60000), f3(60, 70000);
    cout << (f1 == f2 ? "Площі однакові\n" : "Площі різні\n");
    cout << (f2 > f1 ? "f2 дорожча\n" : "f2 не дорожча\n");
    f1 = f3;
    cout << "f1 площа: " << f1.getArea() << ", ціна: " << f1.getPrice() << endl;

    return 0;
}