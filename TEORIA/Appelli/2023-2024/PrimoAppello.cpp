#include <iostream>

using namespace std;

class A{
    public:
        A() {cout << "A() ";}
        ~A() {cout << "~A ";}
        A(const A& x) { cout<< " Ac "; }
        virtual const A* j() {cout << "A::j() "; return this;}
        virtual void k() {cout << "A::k() "; m();}
        void m() {cout << "A::m() "; j();}
};

class B: virtual public A{
    public:
        B() {cout << "B() ";}
        virtual ~B() {cout << "~B() ";}
        virtual void g() const{cout << "B::g() ";}
        virtual const B* j() {cout << "B::j() "; n(); return this;}
        void k() {cout << "B::k() "; j(); m();}
        void m() {cout << "B::m() "; g(); j();}
        virtual A& n() {cout << "B::n() "; return *this;}
};

class C: virtual public B{
    public:
        C() {cout << "C() ";}
        ~C() {cout << "~C() ";}
        void g() const{cout << "C::g() ";}
        void k() override{cout << "C::k() "; B::n();}
        virtual void m() {cout << "C::m() "; g(); j();}
        B& n() override{cout << "C::n() "; return *this;}
};

class D: virtual public B{
    public:
        D() {cout << "D() ";}
        ~D() {cout << "~D() ";}
        virtual void g() {cout << "D::g() ";}
        const B* j() {cout << "D::j() "; return this;}
        void k() const {cout << "D::k() "; k();}
        void m() {cout << "D::m() "; g(); j();}
};

class E: public C, public D{
    public:
        E() {cout << "E() ";}
        ~E() {cout << "~E() ";}
        E(const E& x) {cout << "Ec ";}
        virtual void g() const{cout << "E::g() ";}
        const E* j() {cout << "E::j() "; return this;}
        void m() {cout << "E::m() "; g(); j();}
        D& n() final{cout << "E::n() "; return *this;}
};

A* p1 = new E();
B* p2 = new C();
A* p3 = new D();
B* p4 = new E(); 
//const A* p5 = new D(); 
//const B* p6 = new E(); 
//const E* p7 = new E();

int main(){
    //(p1->j())->k(); //non compila perché il this ritornato da j() della classe A è marcato const mentre la 
                      //funzione k() non lo è
                      
    (dynamic_cast<const E*>(p1->j())->g()); //stampa E::j() E::g()

    p2->m(); //Viene chiamata la versione di B perchè m() non è dichiarata virtual, quindi stampa B::m(), g() 
             //essendo virtuale in B fa chiamare la versione puntata da p2 cioè quella di C, stampa C::g()
             //anche se j() è virtual non è ridefinita in C quindi chiama quella di B stampa B::j()
             //n() è virtuale quindi chiama il type dinamico puntato quindi la versione di C stampa C::n()
    (p2->j())->g(); //stampa B::j() C::n() C::g()

    p3->k(); //stampa B::k() D::j() B::m() B::g() D::j()

    (p4->n()).m(); // stampa E::n() A::m() E::j()

    ((dynamic_cast<D*>(p4))->n()).k(); //B::n() D::k()


}
