#include <iostream>

template <class T>
class AlbBinRic;
template <class T>
class Nodo;
template <class T>
std::ostream &operator<<(std::ostream &, Nodo<T> *);

template <class T>
class Nodo
{
    friend class AlbBinRic<T>;
    friend std::ostream &operator<< <T>(std::ostream &, Nodo<T> *);

private:
    T info;
    Nodo *left, *right, *ancestor;
    Nodo(const T &v, Nodo *p = 0, Nodo *s = 0, Nodo *d = 0) : info(v), ancestor(p), left(s), right(d) {}
};

template <class T>
std::ostream &operator<<(std::ostream &os, Nodo<T> *p)
{
    if (!p)
        os << '@';
    else
    {
        os << "(" << p->info << ", " << p->left << ", " << p->right << ")";
    }
    return os;
}

template <class T>
std::ostream &operator<<(std::ostream &, const AlbBinRic<T> &);
template <class T>
class AlbBinRic
{

    friend std::ostream &operator<< <T>(std::ostream &, const AlbBinRic<T> &);

public:
    AlbBinRic() : radice(0) {}
    Nodo<T> *Find(T) const;
    Nodo<T> *Minimo() const;
    Nodo<T> *Massimo() const;
    Nodo<T> *Succ(Nodo<T> *) const;
    Nodo<T> *Pred(Nodo<T> *) const;
    void Insert(T);
    static T Valore(Nodo<T> *p) { return p->info; }

private:
    Nodo<T> *radice;
    static Nodo<T> *FindRic(Nodo<T> *, T);
    static Nodo<T> *MinimoRic(Nodo<T> *);
    static Nodo<T> *MassimoRic(Nodo<T> *);
    static void InsertRic(Nodo<T> *, T);
};
template <class T>
std::ostream &operator<<(std::ostream &os, const AlbBinRic<T> &A)
{
    os << A.radice << std::endl;
    return os;
}
template <class T>
Nodo<T> *AlbBinRic<T>::Find(T x) const
{
    return FindRic(radice, x);
}

template <class T>
Nodo<T> *AlbBinRic<T>::FindRic(Nodo<T> *x, T v)
{
    if (!x)
        return x;
    if (x->info == v)
        return x;
    if (v < x->info)
        return FindRic(x->left, v);
    else
        return FindRic(x->right, v);
}

template <class T>
Nodo<T> *AlbBinRic<T>::Minimo() const
{
    if (!radice)
        return 0;
    return MinimoRic(radice);
}

template <class T>
Nodo<T> *AlbBinRic<T>::MinimoRic(Nodo<T> *x)
{
    if (!(x->left))
        return x;
    else
        return MinimoRic(x->left);
}

template <class T>
Nodo<T> *AlbBinRic<T>::Massimo() const
{
    if (!radice)
        return 0;
    return MassimoRic(radice);
}

template <class T>
Nodo<T> *AlbBinRic<T>::MassimoRic(Nodo<T> *x)
{
    if (!(x->right))
        return x;
    else
        return MassimoRic(x->right);
}

template <class T>
Nodo<T> *AlbBinRic<T>::Pred(Nodo<T> *x) const
{
    if (!x)
        return 0;
    if (x->left)
        return MassimoRic(x->left);
    while (x->ancestor && x->ancestor->left == x)
        x = x->ancestor;
    return x->ancestor;
}

template <class T>
Nodo<T> *AlbBinRic<T>::Succ(Nodo<T> *x) const
{
    if (!x)
        return 0;
    if (x->right)
        return MinimoRic(x->right);
    while (x->ancestor && x->ancestor->right == x)
        x = x->ancestor;
    return x->ancestor;
}

template <class T>
void AlbBinRic<T>::Insert(T v)
{
    if (!radice)
        radice = new Nodo<T>(v);
    else
        InsertRic(radice, v);
}

template <class T>
void AlbBinRic<T>::InsertRic(Nodo<T> *x, T v)
{
    if (v < x->info)
        if (x->left == 0)
            x->left = new Nodo<T>(v, x);
        else
            InsertRic(x->left, v);
    else if (x->right == 0)
        x->right = new Nodo<T>(v, x);
    else
        InsertRic(x->right, v);
}
