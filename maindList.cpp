#include <iostream>

#include "dList.h"
using namespace std;

int main()
{

    dList<int> list;
    dList<int> a(10, 2);
    list.insertFront(4);
    list.insertBack(6);
    dList<string> b(10, "negro");
    dList<string> c(10, "sega");

    cout << list;
    cout << a;
    if (b < c)
        cout << "porco dio" << endl;
    else
        cout << "dio merda" << endl;
};