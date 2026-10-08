#include <iostream>
#include "DynamicArray.h"

using namespace std;

int main()
{
    srand(42);

    DynamicArray a(5);
    a.Input(1, 15);
    cout << "Array a:\n";
    a.Output();

    cout << "\nReSize(8):\n";
    a.ReSize(8);
    a.Output();

    cout << "\nReSize(3):\n";
    a.ReSize(3);
    a.Output();

    DynamicArray arr(6);
    arr.Input(1, 30);
    cout << "\nBefore Sort:\n";
    arr.Output();
    arr.Sort();
    cout << "After Sort:\n";
    arr.Output();

    int target = arr.GetPointer()[2];
    cout << "\nSearch(" << target << "):\n";
    int idx = arr.Search(target);
    if (idx != -1)
        cout << "Found at index " << idx << "\n";
    else
        cout << "Not found\n";

    cout << "\nSearch(999):\n";
    int idx2 = arr.Search(999);
    if (idx2 != -1)
        cout << "Found at index " << idx2 << "\n";
    else
        cout << "Not found, returned -1\n";

    cout << "\nBefore Reverse:\n";
    arr.Output();
    arr.Reverse();
    cout << "After Reverse:\n";
    arr.Output();

    DynamicArray b(4);
    b.Input(1, 10);
    cout << "\na:\n";
    b.Output();

    DynamicArray rez = b + 10;
    cout << "rez = a + 10:\n";
    rez.Output();

    DynamicArray rez1 = b - 2;
    cout << "rez1 = a - 2:\n";
    rez1.Output();

    DynamicArray rez2 = b * 2;
    cout << "rez2 = a * 2:\n";
    rez2.Output();

    DynamicArray c(3);
    c.Input(50, 60);
    cout << "\nb:\n";
    c.Output();
    DynamicArray rez4 = b + c;
    cout << "rez4 = a + b:\n";
    rez4.Output();

    DynamicArray rez5(3);
    rez5.Input(1, 5);
    cout << "\nBefore ++rez:\n";
    rez5.Output();
    ++rez5;
    cout << "After ++rez:\n";
    rez5.Output();

    cout << "\nBefore --rez:\n";
    rez5.Output();
    --rez5;
    cout << "After --rez:\n";
    rez5.Output();

    return 0;
}
