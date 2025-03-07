#include <iostream>
#include <list>
#include <vector>
using namespace std;

class A
{
public:
    virtual A *f() const = 0;
};

class B : public A
{
};
class C : public B
{
public:
    B *f() const { return new C(); }
};
class D : public B
{
};
class E : public B
{
public:
    A *f() const { return new E(); }
};
class F : public C, public D, public E
{
public:
    D *f() const { return new F(); }
};

list<const D *const> fun(const vector<const B *> &v)
{
    int count = 0;
    list<const D *const> result;
    for (auto it = v.begin(); it != v.end();)
    {
        const B *q = *it;
        if (q)
        {
            if (typeid(C) == typeid(q))
            {
                it = v.erase(it);
            }
        }
    }
}

list<const D *> fun(vector<const B *> &v)
{
    list<const D *> result;
    int removedCount = 0;

    for (auto it = v.begin(); it != v.end();)
    {
        const B *q = *it;

        // Controllo (A)
        if (q != nullptr && typeid(*q) == typeid(C))
        {
            it = v.erase(it);
            removedCount++;
            if (removedCount > 2)
            {
                throw C(); // Eccezione di tipo C se più di 2 elementi vengono rimossi
            }
            continue;
        }

        // Controllo (B)
        if (q == nullptr)
        {
            throw string("nullptr");
        }

        // Invocazione della funzione virtuale
        A *pr = q->f();

        // Controllo (B2): verificare se il tipo dinamico di pr è sottotipo di D* ma non di E*
        if (pr != nullptr)
        {
            if (dynamic_cast<const D *>(pr) != nullptr && dynamic_cast<const E *>(pr) == nullptr)
            {
                result.push_back(dynamic_cast<const D *>(pr));
            }
        }

        ++it;
    }

    return result;
}