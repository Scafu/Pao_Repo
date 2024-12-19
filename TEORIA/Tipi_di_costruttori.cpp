//COSTRUTTORE DI COPIA
//L'inizializzazione di copia di un oggetto di tipo classe invoca un costruttore, in particolare il costruttore di copia per quella classe:

class Example {
public:
  Example(int x_in, double y_in)
    : x(x_in), y(y_in) {}

  Example(const Example &other)
    : x(other.x), y(other.y) {
    cout << "Example copy ctor: " << x << ", " << y << endl;
  }

  int get_x() const {
    return x;
  }

  double get_y() const {
    return y;
  }

private:
  int x;
  double y;
};

//Il secondo costruttore è quello di copia e prende un riferimento ad un oggetto esistente come parametro, il parametro deve essere passato come riferimento, altrimenti verrebbe effettuata una copia per inizializzarlo che allora vuoldire un ulteriore invocazione del costruttore di copia e così via.

int main() {
  Example e1(2, -1.3);
  Example e2 = e1;
}

//Il programma stampa Example copy ctor: 2, -1.3, il programma invoca il costruttore di copia per inizializzare e2 a partire da e1, il compilatore fornisce un costruttore di copia definito implicito, questo fa una copia membro per membro

//OPERATORE DI ASSEGNAMENTO
//L'assegnamento è un'altra situazione in cui un oggetto è copiato, diversamente dall'inizializzazione, l'assegnazione copia in un oggetto esistente invece che in uno nuovo.

//COPIA PROFONDA 
//Per la maggior parte delle classi la normale copia è sufficiente, tuttavia per alcuni tipi che gestiscono risorse dinamiche, la copia membro a membro risulta in condivisione errata di una risorsa, infatti in situazioni con puntatori a variabili per esempio in array, la copia normale copia il puntatore e non quello a cui punta cioè l'array nella sua totalità, ci serve quindi una copia detta profonda, dove si fa una copia della risorsa sottostante che avere sue set della stessa risorsa, per ottenere una copia profonda ci serve una implementazione custom della copia normale, ci serve nel caso dell'assegnazione anche in questo caso una versione custom
