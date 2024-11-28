#include <iostream>
#include "AlbBinRic.h"
using namespace std;

int main()
{
    AlbBinRic<int> a;
    a.Insert(3);
    a.Insert(2);
    a.Insert(3);
    a.Insert(1);
    a.Insert(6);
    a.Insert(5);

    cout << a;

    cout << "minimo: " << AlbBinRic<int>::Valore(a.Minimo()) << endl;

    cout << "successore minimo: ";
};
