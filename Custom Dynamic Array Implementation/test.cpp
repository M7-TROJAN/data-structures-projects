#include <iostream>
#include "clsDynamicArray.h"
using namespace std;

int main()
{
    clsDynamicArray<int> MyArray(10);

    MyArray[0] = 1;
    MyArray[1] = 2;
    MyArray[2] = 3;
    MyArray[3] = 4;
    MyArray[4] = 5;
    MyArray[5] = 6;
    MyArray[6] = 7;
    MyArray[7] = 8;
    MyArray[8] = 9;
    MyArray[9] = 10;

    MyArray.print();

    MyArray.reverse();

    MyArray.print();

    if(MyArray.find(8) != -1)
        cout << "find " << MyArray[MyArray.find(8)] << endl;
    
    MyArray.deleteItem(8);
    if(MyArray.find(8) != -1)
        cout << "find " << MyArray[MyArray.find(8)] << endl;

    MyArray.insertAt(4,500);
    MyArray.print();

    cout << MyArray.size() << endl;

    MyArray.insertAt(8,1000);
    MyArray.print();
    cout << MyArray.size() << endl;

    MyArray.insertAt(7,2000);
    MyArray.print();
    cout << MyArray.size() << endl;

    cout << "--------------------------------------\n";

    MyArray.insertAtBeginning(99);
    MyArray.print();
    cout << MyArray.size() << endl;

    MyArray.insertAtEnd(99);
    MyArray.print();
    cout << MyArray.size() << endl;

    MyArray.insertAfter(0,444);
    MyArray.print();
    cout << MyArray.size() << endl;

    MyArray.insertBefore(7,444);
    MyArray.print();
    cout << MyArray.size() << endl;


   

    // cout << MyArray.getItem(0) << endl;
    // cout << MyArray.getItem(1) << endl;
    // cout << MyArray.getItem(2) << endl;
    // cout << MyArray.getItem(3) << endl;
    // cout << MyArray.getItem(10) << endl;

    // cout << MyArray.size() << endl;
    // MyArray.print();

    // MyArray.ReSize(0);

    // cout << MyArray.size() << endl;

    // MyArray.print();


}