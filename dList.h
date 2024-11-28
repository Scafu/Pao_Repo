#include <iostream>

using namespace std;

template <class T>
class dList;

template <class T>
class Nodo;

template <class T>
ostream &operator<<(ostream &, Nodo<T> *);
template <class T>
bool operator<(const dList<T> &, const dList<T> &);
template <class T>
class Nodo
{
    friend class dList<T>;
    friend ostream &operator<< <T>(ostream &, Nodo<T> *);
    friend bool operator< <T>(const dList<T> &, const dList<T> &);

private:
    T data;
    Nodo *prev;
    Nodo *next;
    Nodo(const T &x, Nodo *p = nullptr, Nodo *n = nullptr) : data(x), prev(p), next(n) {}
};

template <class T>
ostream &operator<<(ostream &os, Nodo<T> *p)
{
    os << "(";
    while (p)
    {
        os << p->data;
        if (p->next)
            os << ","; // Indica il collegamento tra i nodi
        p = p->next;
    }
    os << ")" << endl;
    return os;
}

template <class T>
ostream &operator<<(ostream &, const dList<T> &);

template <class T>
class dList
{
    friend ostream &operator<< <T>(ostream &, const dList<T> &);
    friend bool operator< <T>(const dList<T> &, const dList<T> &);

private:
    Nodo<T> *first;
    Nodo<T> *last; // Manteniamo un puntatore all'ultimo nodo per rendere `insertBack` efficiente
    size_t size;   // Numero di elementi nella lista

    // Funzione helper per liberare la memoria
    void clear()
    {
        Nodo<T> *current = first;
        while (current)
        {
            Nodo<T> *toDelete = current;
            current = current->next;
            delete toDelete;
        }
        first = last = nullptr;
        size = 0;
    }

public:
    dList() : first(nullptr), last(nullptr), size(0) {}

    // Costruttore per creare una lista con `k` nodi contenenti il valore `t`
    dList(int k, const T &t) : first(nullptr), last(nullptr), size(0)
    {
        for (int i = 0; i < k; ++i)
        {
            insertBack(t);
        }
    }

    ~dList()
    {
        clear();
    }

    // Inserimento in testa
    void insertFront(const T &t)
    {
        Nodo<T> *newNode = new Nodo<T>(t, nullptr, first);
        if (!first) // Lista vuota
        {
            first = last = newNode;
        }
        else
        {
            first->prev = newNode;
            first = newNode;
        }
        ++size;
    }

    // Inserimento in coda
    void insertBack(const T &t)
    {
        Nodo<T> *newNode = new Nodo<T>(t, last, nullptr);
        if (!last) // Lista vuota
        {
            first = last = newNode;
        }
        else
        {
            last->next = newNode;
            last = newNode;
        }
        ++size;
    }
};

// Overload dell'operatore `<<` per stampare la lista
template <class T>
ostream &operator<<(ostream &os, const dList<T> &t)
{
    os << t.first;
    return os;
}

// Overload dell'operatore `<` per confronto lessicografico
template <class T>
bool operator<(const dList<T> &t, const dList<T> &s)
{
    Nodo<T> *current1 = t.first;
    Nodo<T> *current2 = s.first;
    while (current1 && current2)
    {
        if (current1->data < current2->data)
            return true;
        if (current1->data > current2->data)
            return false;

        current1 = current1->next;
        current2 = current2->next;
    }

    if (!current1 && current2)
        return true;
    if (current1 && !current2)
        return false;

    return false;
}
