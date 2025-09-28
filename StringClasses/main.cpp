#include <iostream>
#include "Array.h"
using namespace std;

int main() {
    Array<int> arr(5, 5);
    arr.Add(1);
    arr.Add(2);
    arr.Add(3);
    arr.InsertAt(1, 99);
    arr.RemoveAt(2);
    for (int i = 0; i <= arr.GetUpperBound(); ++i)
        cout << arr[i] << " ";
    cout << endl;

    Array<int> arr2;
    arr2.Append(arr);
    arr2.Add(100);
    for (int i = 0; i <= arr2.GetUpperBound(); ++i)
        cout << arr2.GetAt(i) << " ";
    cout << endl;

    cout << "Size: " << arr2.GetSize() << endl;
    cout << "IsEmpty: " << arr2.IsEmpty() << endl;
    arr2.FreeExtra();
    cout << "Size after FreeExtra: " << arr2.GetSize() << endl;
    arr2.RemoveAll();
    cout << "IsEmpty after RemoveAll: " << arr2.IsEmpty() << endl;
    return 0;
}