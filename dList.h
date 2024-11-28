#include <iostream>

using namespace std;

template <class T>
class dList;

template <class T>
class Nodo;

template <class T>
ostream &operator<<(ostream &, Nodo<T> *);

template <class T>
class Nodo
{
    friend class dList<T>;
    friend ostream &operator<< <T>(ostream &, Nodo<T> *);

private:
    T data;
    Nodo *prev;
    Nodo *next;
    Nodo(const T &x, Nodo *p, Nodo *n) : data(x), prev(p), next(n) {}
};

template <class T>
ostream &operator<<(ostream &os, Nodo<T> *p)
{
    if (!p)
        os << "vuoto";
    else
    {
        os << "(" << p->data << ", )";
    }
    return os;
}

template <class T>
ostream &operator<<(ostream &, const dList<T> &);

template <class T>
class dList
{
    friend ostream &operator<< <T>(ostream &, const dList<T> &);

private:
    Nodo<T> *first;

public:
    dList() : first(0) {}
    dList(int k, const T &t) : first(nullptr)
    {
        for (int i = 0; i < k; i++)
        {
            insertFront(t);
        }
    }
    // void insertBack(const T &);
    void insertFront(const T &);
};

template <class T>
ostream &operator<<(ostream &os, const dList<T> &t)
{
    for (int i = 0; t.first != nullptr; i++)
    {
        os << t.first << endl;
    }
    return os;
}

template <class T>
void dList<T>::insertFront(const T &t)
{
    Nodo<T> *newNode = new Nodo<T>(t, nullptr, first);
    if (!first)
    {
        first = newNode;
        newNode->next = nullptr;
    }
    else
    {
        first->next = first;
        first = newNode;
    }
}