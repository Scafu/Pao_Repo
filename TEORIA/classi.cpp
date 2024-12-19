//ABSTRACT DATA TYPES
    
//Rispetto a C, C++ permette di definire insieme di dati e le funzioni di un tipo di dato astratto o ADT, consente inoltre di impedire l'accesso ai dettagli dell'implementazione interna, nonchè di garantire che un oggetto venga inizializzato in modo appropriato quando viene creato.
//Gli ADT in C++ sono le classi, una classe include sia variabili membro, che definiscono la rappresentazione dei dati, sia funzioni membro chiamate anche metodi, che operano sui dati.
#include <cstdio>
#include <iostream>
#include <ostream>
#include <string>
class Triangle {
    double a;
    double b;
    double c;
    public:
        Triangle(double a_in, double b_in, double c_in);
        double perimeter() const {
            return this->a + this->b + this->c;
        }
        void scale(double s){
            this->a *= s;
            this->b *= s;
            this->c *= s;
        }
};

int main(){
    Triangle t1(3, 4, 5);
    t1.scale(2);
    std::cout << t1.perimeter() << std::endl;
}

//la funzione membro di una classe non dichiara esplicitamente un puntatore, ma il C++ aggiunge un parametro implicito che é un puntatore all'oggetto su cui stiamo lavorando, questo puntatore è detto *This
//PUNTATORE IMPLICITO THIS->
//Poiché le variabili membro e le funzioni membro sono entrambe situate all'interno dell'ambito di una classe, C++ consente di fare riferimento ai membri dall'interno di un metodo senza la this-> esplicita, il compilatore infatti inserisce automaticamente il deferenziamento del membro per noi

class Triangle2 {
    double a;
    double b;
    double c;
    public:
    Triangle2(double a_in, double b_in, double c_in);
    double perimeter() const {
        return a + b + c; //perché il metodo può accedere direttamente alla parte privata
    }
    void scale(double s){
        this->a *= s;
        this->b *= s;
        this->c *= s;
    }

};

//ACCESSIBILITÀ DEI MEMBRI DI UNA CLASSE
//In C++ fornisce un meccanismo per far rispettare la convenzione degli ADT, dichiarare i membri come privati impedisce l'accesso dall'esterno della classe, mentre dichiararli come pubblici consente l'accesso dall'esterno, quandosi dichiara un livello di accesso quello si applica fino alla prossima dichiarazione di un altro livello.
//Se si omette il livello di accesso quello previsto di default è private
class Employee {
    private:
        int age;
        std::string name;

    public:
        Employee(int age_in, std::string name_in);
        int getAge() const {
            return age;
        }
        std::string getName() const{
            return name;
        }
};

//COSTRUTTORI
//Un costruttore é simile a un metodo, eccetto per il fatto che il suo scopo è inizializzare un oggetto di tipo classe, come un metodo, il costruttore ha il puntatore this implicito che punta all'oggetto che viene inizializzato, //Il C++ fornisce due meccanismi per inizializzare una variabile membro, direttamente nella dichiarazione della variabile, tramite un elenco di inizializzazione dei membri, quest'ultima è una sintassi specifica per un costruttore.
class Game {
    std::string title;
    std::string genre;
    int year;

    public:
        Game(std::string title_in, std::string genre_in, int year_in): title(title_in), genre(genre_in), year(year_in){}
};

//Se un membro é inizializzato sia nella sua dichiarazione sia in un elenco di inizializzatori, quest'ultimo ha la precedenza e l'altro viene ignorato.
//Ogni oggetto in C++ che sia esso classe o meno, viene inizializzato al momento della creazione, se non viene fornita alcuna inizializzazione esplicita, viene usata un'inizializzazion di default, questo tipo di inizializzazione esegue certe operazioni:
//1) I tipi primitivi sono inizializzati di default senza fare nulla, cioè hanno valori undefined
//2) Un array viene inizializzato di default iniziallizzando a sua volta di default i suo elementi, quindi un array di tipi primitivi ha elementi inizializzati con valore undefined
//3) Un oggetto di tipo classe viene inizializzato di default chiamando il costruttore di default che è il costruttore che non accetta argomenti, se tale costruttore non esiste, o è inacessibile si verifica un errore di compilazione
//4) Un array di oggetti di tipo classe viene inizializzato di default chiamando il costruttore di default su ogni elemento, quindi il tipo di elemento deve avere un costruttore di default accessibile per creare un array di quel tipo

//All'interno di una classe se una variabile non è inizializzata nè in fase di dichiarazione nè nell'elenco degli inizializzatori, viene inizializzata di default
class Rectangle {
    double a;
    double b;
    public:
        Rectangle() : a(1), b(2) {} //costruttore di default 
        Rectangle(double a_in, double b_in): a(a_in), b(b_in) {}
};
//Una classe può avere costruttori multipli in base a quanti argomenti sono stati forniti, tuttavia è una buona pratica fare il costruttore di default insieme a quello con gli argomenti
//Se una classe non dichiara alcun costruttore, il compilatore fornisce un costruttore implicito di default, il comportamento di queto è come se fosse vuoto, in modo che inizializzi di default ogni variabile membro
class Person {
    std::string name;
    int age;
    bool is_ninja;
    //costruttore di default implicito Person(){}
};
int main2(){
    Person elise;
    std::cout << elise.name;
    std::cout << elise.age;
}
//Se una classe dichiara un costruttore, quello implicito viene reso inacessibile

//INFORMATION HIDING
//Un buon design di astrazione usa il cosiddetto incapsulamento, che raggruppa sia i dati che le funzioni di un ADT, si ottiene l'incapsulamento definendo sia le variabili membro che i metodi, un'astrazione appropriata fornisce l'hiding information cioé la separazione dell'interfaccia dall'implementazione, i livelli come private ci consentono di impedire l'accesso ai dettagli di implementazione dall'esterno, si può inoltre nascondere ulteriormente separando in file diversi la dichiarazione di interfaccia e l'implementazione.

//Square.h

class Square {
    public:
        Square();
        Square(double a_in);
        double perimeter() const;
        void scale(double s);
    private:
        double a;
}

//Square.cpp
#include "Square.h"

Square::Square(): a(1);
Square::Square(double a_in): a(a_in){}
double Square::perimeter() const{
    return a*4;
}
void Square::scale(double s){
    a*=s;
}

//L'ordine di inizializzazione é dato dall'ordine di dichiarazione dei membri nella classe, questo vale anche se l'ordine nella lista di inizializzatori è diverso.
//Si può fare una delega tra costruttori
Triangle(double a_in): Triangle(a_in, a_in, a_in){}


//EREDITARIETÀ
//Il C++ fornisce due fondamentali features, l'ereditarietà cioè l'abilità di una classe di riusare l'interfaccia o le funzionalità di un'altra classe e il polimorfismo cioè l'abilità di usare un oggetto di un tipo più specifico dove un oggetto di un tipo più generale è previsto.
//Supponiamo la classe Uccello dalla quale le classi Pollo e Papera ereditano le funzionalità
class Uccello {
    public:
        Uccello(const std::string &name_in): age(0), name(name_in){std::cout<< "Uccello constructor" <<std::endl}
        std::string get_name() const{
            return name;
        }
        int get_age() const{
            return age;
        }
        void have_birthday(){
            ++age;
        }
        void talk() const{
            std::cout<< "Piu-Piu" <<std::endl;
        }
    private:
        int age;
        std::string name;
};
//Questa é una ereditarietà pubblica dove è parte dell'intergaccia di Pollo da cui deriva Uccello, se avessimo messo private Uccello, sarebbe un'ereditarietà privata cioè un dettagli di implementazione e non parte dell'interfaccia da cui Pollo deriva Uccello.
class Pollo: public Uccello{
    public:
        void cross_road(){
            ++roads_crossed;
        }
        void talk() const {
            std::cout<< "Cocodé" << std::endl;
        }
    private:
        int road_crossed;

}
//I dati privati name e age vengono ereditati da Uccello, tuttavia non sono direttamente accessibili.
//La memoria della classe Pollo consiste in realtà di un pezzo, più i membri di Uccello aggiuntivi.
//La classe derivata non inizializza direttamente i membri ereditati, richiama invece un costruttore di classe base nell'elenco di inizializzazione dei membri dei suoi costruttori, una classe derivata invoca sempre un costruttore per la classe base, se un'invocazione esplicita non appare nell'elenco degli inizializzatori, c'è una chiamata implicita al costruttore di default, se la classe base non ha quest'ultimo allora si verifica un errore.
//Un distruttore viene invocato quando il ciclo di vita di una classe è terminato, si segne con il nome della classe preceduto da ~.
//L'ordine di esecuzione tra costruttori e distruttori avviene così, nel caso di una classe derivata, prima verrà costruito sempre il sotto-oggetto della classe base prima di inizializzare i pezzi della classe derivata, la distruzioneavviene nell'ordine inverso cioè viene eseguito prima il distruttore della classe derivata e poi quello della classe base.

//POLIMORFISMO
//Si intende l'abilità di un pezzo di codice di comportarsi differentemente in base al contesto in cui è usato, ci sono molteplici forme di polimorfismo:
//1) Polimorfismo ad HOC che si riferisce all'overloading di funzione
//2) Polimorfismo parametrico cioè in una forma di template
//3) Polimorfismo di sottotipo che permette a oggetti di classe derivata di essere usati al posto di un oggetto di una classe base

//OVERLOAD DI FUNZIONI
//Il concetto è di usare un solo nome per riferirsi a più funzioni in un singolo contesto.
class Base{
    public:
        void foo(int a);
        int foo(std::string b);
}
int main3(){
    Base b;
    b.foo(42);
    b.foo("test");
}
//Quando invochiamo una funzione sovraccaricata, il compilatore risolve la chiamata di funzione confrontando i tipi degli argomenti con i parametri delle funzioni candidate e trovando la corrispondenza migliore infatti riesce a riconoscere quando il tipo é int rispetto a const char *
//L'overload richiede che le firme delle funzioni differiscano per gli argomenti o per i qualificatori.

//POLIMORFISMO DI SOTTOTIPO
//Permette a oggetti di classe derivata di essere usati dove quelli di classe base sono previsti, per evitare tagli di campi per esempio se chiamo Bird bird = chicken dato che la classe chicken ha più parametri rispetto a Bird alcuni campi andranno persi, per evitare ciò si deve fare un indirezione tramite reference o puntatore.
Uccello &uccello_ref = Pollo;
Uccello *uccello_ptr = &Pollo;
//Questi sono upcast impliciti, mentre downcast impliciti nella gerarchia sono vietati
//Si può fare però il downcast esplicito con static_cast
Pollo &pollo_ref = static_cast<Pollo &>(uccello_ref);
Pollo *pollo_ptr = static_cast<Pollo *>(uccello_ptr);
//Dato che sono unchecked a runtime bisogna essere sicuri a priori che l'oggetto sottostante sia un Pollo

void all_talk(Bird *birds[], int length) {
  for (int i = 0; i < length; ++i) {
    array[i]->talk();
  }
}

int main() {
  Chicken c1 = /* ... */;
  Duck d = /* ... */;
  Chicken c2 = /* ... */;
  Bird *array[] = { &c1, &d, &c2 };
  all_talk(array, 3);
}
//Questo Main stampa tweet tweet tweet, questo perchè nell'invocazione array[i]->talk() il tipo dichiarato dal ricevitore é diverso dal tipo di runtime effettivo, il tipo dichiarato statico è Bird, mentre quello dinamico è Pollo quando i==0 questa disparità si può avere solo per indirezione tramite reference o puntatori.
//Il C++ ci offre due soluzioni, o il compilatore decide quale funzione chiamare in base al tipo statico del ricevitore quindi tramite un collegamento statico oppure con un collegamento dinamico dove il programma prende la possibilità che possa esserci un tipo dinamico.
//Per poter considerare anche il tipo dinamico dobbiamo aggiungere prima della funzione talk() la keyword virtual, una classe che ha almeno un metodo virtuale viene chiamata classe polimorfa.
class Bird{
    virtual void talk() const {
        std::cout<< "Tweet" <<std::endl;
    }
};
//Chiamando ora all_talk(), il compilatore usare il tipo dinamico del ricevitore nell'invocazione array[i]->talk(), il main stampa bawwk quack bawwk.

//DYNAMIC_CAST
//Si può considerare un'alternativa al collegamento dinamico dove si fa a fare un check a runtime sul tipo di un oggetto così da chiamare la funzione opportuna, la conversione dynamic_cast fa un check sul tipo dinamico dell'oggetto ricevitore.
Chicken chicken("Myrtle");
Bird *b_ptr = &chicken;
Chicken *c_ptr = dynamic_cast<Chicken *>(b_ptr);
if (c_ptr) {  
}
//Se il tipo dinamico attuale non è chicken, la conversione ritorna un puntatore null, altrimenti il risultato è l'indirizzo dell'oggetto Chicken, possiamo poi fare un check sul null pointer.
//Ci sono però due errori significativi:
//1) Rende il codice non mantenibile e complicato
//2) Può essere usato solo su classi polimorfe

//RICERCA MEMBRI RIVISITATA
//Il compilatore cerca prima nella classe dell'oggetto un membro con quel nome prima di procedere alla sua classe base con l'indirezione succede questo:
//1) Il compilatore cerca il membro nel tipo statico dell'oggetto ricevente, usando il processo di ricerca di cui abbiamo parlato prima (iniziando nella classe stessa, quindi cercando nella classe base se necessario) viene mostrato un errore se viene trovato nessun membro con il nome dato nel tipo statico o nel suo tipo base.
//2) Se un membro viene trovato in una funzione overloaded, allora gli argomenti della chiamata di funzione sono usati per determinare quale overload è stato chiamato.
//3) Se il membro è una variabili o una funzione non virtuale (inclusi le funzioni membro statiche) l'accesso è statisticamente compreso nel tempo di compilazione.
//4) Se il membro è una funzione virtuale, l'accesso usa un accoppiamento dinamico, a runtime il programma cercherà una funzione con la stessa firma, partendo dal tipo dinamico del ricevitore e poi procedendo se necessario per il tipo di base.
//
//L'accoppiamento dinamico richiede due condizioni per usare una funzione con la versione della classe derivata:
//1) Il metodo membro trovato a tempo di compilazione usando il tipo statico deve essere virtuale
//2) La funzione della classe derivata deve avere la stessa firma della funzione trovata a tempo di compilazione
//Quando queste condizioni vengono incontrate la funzione della classe derivata si dice che sovvrascrive quella della classe base e verrà usata quando il tipo dinamico del ricevitore è quello della classe derivata, se queste condizioni invece non vengono incontrate la funzione della classe derivata nasconde quella della classe base e verrà usata se il tipo statico del ricevitore è quello della classe derivata-
class Top {
public:
  int f1() const {
    return 1;
  }

  virtual int f2() const {
    return 2;
  }
};

class Middle : public Top {
public:
  int f1() const {
    return 3;
  }

  virtual int f2() const {
    return 4;
  }
};

class Bottom : public Middle {
public:
  int f1() const {
    return 5;
  }

  virtual int f2() const {
    return 6;
  }
};

//Ogni classe a un membro f1() non virtuale, dato che la funzione non è virtuale, la versione derivata nasconde quella di base, la f2() è virtuale quindi le versioni derivate la sovvrascrivono.
int main6() {
  Top top;
  Middle mid;
  Bottom bot;
  Top *top_ptr = &bot;
  Middle *mid_ptr = &mid;

  cout << top.f2() << endl;       // prints 2
  cout << mid.f1() << endl;       // prints 3
  cout << top_ptr->f1() << endl;  // prints 1
  cout << top_ptr->f2() << endl;  // prints 6
  cout << mid_ptr->f2() << endl;  // prints 4
  mid_ptr = &bot;
  cout << mid_ptr->f1() << endl;  // prints 3
  cout << mid_ptr->f2() << endl;  // prints 6
}

//1) Non c'è nessuna indirezione nelle prime due chiamate quindi non ci sono differenze tra tipo statico e dinamico del ricevitore, le chiamate seguono i metodi presenti nelle rispettive classi.
//2) Il tipo statico del ricevitore in top_ptr->f1() e top_ptr->f2() é Top mentre quello dinamico è Bottom, dato che f1() non è virtuale, viene chiamata la funzione della classe base, mentre f2() essendo virtuale chiama la versione derivata in Bottom.
//3) Nella prima chiamata a mid_ptr->f2() sia il tipo statico sia quello dinamico del ricevcitore è Middle, quindi verra usata la versione di Middle anche se f2() è virtuale.
//4) L'Assegnamento mid_ptr = &bot cambia il tipo dinamico del ricevitore a Bottom quando si chiama su mid_ptr, il tipo statico rimane Middle quindi la chiamata mid_ptr->f1() stampa appunto 3 la seconda chiamata mid_ptr->f2() usa la versione di Bottom quindi stampa 6.

//CLASSI E INTERFACCE ASTRATTE
//In alcuni casi non ci sono informazioni insufficienti in una classe base per definire un particolare metodo, ma si vuole comunque che esso faccia parte dell'interfaccia fornita dalle classi derivate.
class Bird {
  ...
  virtual int get_wingspan() const = 0;
};

//In questo caso la funzione non ha un valore di default perchè ogni uccello ha una grandezza alare differente, allora possiamo definire la funzione come funzione virtuale pura senza avere un implementazione nella classe base.
//La sintassi prevede di aggiungere un = 0 alla fine della firma, questa cosa è puramente sintassi non si sta definendo un valore.
//Dato che la classe base ora essendo astratta manca di qualche implementazione non si può più creare un oggetto di tipo Bird, possiamo tuttavia ancora dichiarare puntatori e riferimenti ad oggetti Bird, tuttavia questi non creano un oggetto Bird.
Bird bird("Big Bird");      // ERROR: Bird is abstract
Chicken chicken("Myrtle");  // OK, as long as Chicken is not abstract
Bird &bird_ref = chicken;   // OK
Bird *bird_ptr = &chicken;  // OK

//Per non avere anche la classe derivata astratta, deve avere l'implementazione della funzione virtuale pura.
//Un metodo virtuale dà la possibilità di fare override, mentre un metodo virtuale pure richiede necessariamente l'override da parte delle classi derivate, se una classe derivata fallisce nel creare l'implementazione diventa anch'essa astratta e si porta tutte le conseguenze di essere tale.
//Si può definire un interfaccia, cioè una classe che contiene solo metodi virtuali puri, dato che questa non ha implementazione definisce l'interfaccia che dovrà essere sovrascritta dalle classi derivate.
