#include <iostream>

#include "dList.h"
using namespace std;

int main()
{

    dList<int> list;

    list.insertFront(4);
    list.insertFront(6);

    cout << list;
};