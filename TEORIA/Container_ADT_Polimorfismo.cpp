//OVERLOADING DI OPERATORI
//Un overload di un operatore richiede almeno un operando di essere del tipo della classe, il comportamento di operatori su operatori atomici come operazioni su int ecc non può essere sovrascritto.
//Quando il compilatore incontra un operatore dove almeno un operando ha il tipo della classe, cerca una funzione con il nome operator seguito dal simbolo dell'effettivo operatore.
//Operatori sovrascritti possono prendere come argomenti puntatori o riferimenti, é consigliabile la seconda opzione per evitari inutili copie.
//Anche se la maggior parte degli operatori possono essere sovrascritti come top-level o metodi ci sono alcuni casi in cui bisogna per forza definirli come top-level:
//1) Il primo operando è atomico, infatti tipi atomici non sono classi quindi non hanno metodi come membri.
//2) Il primo operando è di tipo class, ma non si ha accesso alla definizione della classe, quindi non si può definire un nuovo metodo membro.
//Un esempio è l'operatore << di stream dove non si ha accesso alla definizione di ostream:

std::ostream & operator<<(std::ostream &os, const IntSet &set) {
  set.print(os);
  return os;
}

//Il nostro overload dato che viene restituito lo stream deve ritornare un oggetto come reference, infatti gli stream non possono copiati, quindi il codice non compilerebbe se non è ritornato uno stream per valore, anche se lo stream potesse essere copiato vorremmo restituire l'effettivo stream e non una copia, anche se una copia potesse funzionare, si finirebbe con un taglio dell'oggetto, dato che os si riferirebbe ad un oggetto della classe che deriva da ostream.
//Se un overload necessita di accedere a membri privati dovrà essere contrassegnato con la keyword Friend nella classe da cui vuole prendere i membri privati.
//Alcuni operatori possono essere sovrascritti solo come metodi, l'assegnamento =, l'operatore di chiamata di funzione (), l'operatore di sottoscrizione [], l'operatore di indirizzamento ->.


//TEMPLATE
//Quando si vuole cambiare tipo di oggetto ma usando la stessa definizione, non ha senso creare una duplicazione del codice per ogni tipo, in questo allora ci aiuta il tipo template.
//Un template è un modello di codice di produzione, cioè una versione generica, parametrica con uno o più parametri template, il compilatore poi instanzia una specifica versione del codice sostituendo gli argomenti per i parametri e compilando il codice risultante, il codice template non è codice compilabile, quindi non verrà mai eseguito direttamente.
//Si specifica un template e i suoi parametri aggiungendo la keyword template prima dell'entità che stiamo definendo.

template <class T>
class UnsortedSet {
  ...
};

//Si aggiunge poi tra < >, la keyword typename o class che indica che il parametro è un parametro tipato, il nome di esso poi segue, si sceglie il nome T dato che non si hanno informazioni riguardo al tipo.
//Un template può avere più di un parametro e può avere parametri con tipo integrale, ad esempio:

template <typename T, std::size_t N>
class array;

//Prende due argomenti uno il tipo degli elementi e l'altra la size del container, che dovrà essere costante a tempo di compilazione, per creare un oggetto di quel tipo della classe si deve scrivere il nome della classe template seguito dal tipo che scegliamo dell'array all'interno di < >.

template <typename T>
class UnsortedSet {
public:
  // Maximum size of a set.
  static const int MAX_SIZE = 10;

  // EFFECTS:  Initializes this set to be empty.
  UnsortedSet();

  // REQUIRES: size() < MAX_SIZE
  // MODIFIES: *this
  // EFFECTS:  Adds value to the set, if it isn't already in the set.
  void insert(const T &value);

  // MODIFIES: *this
  // EFFECTS:  Removes value from the set, if it is in the set.
  void remove(const T &value);

  // EFFECTS:  Returns whether value is in the set.
  bool contains(const T &value) const;

  // EFFECTS:  Returns the number of elements.
  int size() const;

  // EFFECTS:  Prints out the set in an arbitrary order.
  void print(std::ostream &os) const;

private:
  T elements[MAX_SIZE];
  int num_elements;
  // INVARIANTS:
  // 0 <= num_elements && num_elements <= MAX_SIZE
  // the first num_elements items in elements are the items in the set
  // the first num_elements items in elements contain no duplicates
};

UnsortedSet<char> char_set;
char_set.insert('e');
char_set.insert('a');
char_set.insert('e');
cout << char_set << endl;   // prints { e, a }

//Risulta conveniente passare gli oggetti di parametri template per riferimento al posto di valore per evitare di creare copie di oggetti possibilmente molto grandi.
//Si possono definire anche funzioni template:

template <typename T>
T max(const T &value1, const T &value2) {
  return value2 > value1 ? value2 : value1;
}

//Il compilatore é in grado di dedurre l'argomenti del template dagli argomenti della chiamata di funzione, se usiamo tipi di argomenti non conformi con l'operazione che viene eseguita nel template riceviamo un errore.
//Il compilatore inoltre dato che instanzia la definizione di ogni set di argormenti di template deve avere accesso alla completa definizione del template, per fornire al compilatore l'accesso completo si deve creare un header file che contiene la definizione completa, è di buona pratica inserire la definizione dei template in un file .hpp e l'implementazione in un file .tpp e poi nel main includere il file .hpp.
//
