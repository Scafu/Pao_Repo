//Un iteratore è un oggetto di tipo classe che ha la stessa interfaccia di un puntatore, quindi si forniscono le stesse interfacce sovrascrivendo gli operatori necessari:

template <typename T>
class Iterator {
public:
  T & operator*() const;

  Iterator &operator++();

  bool operator==(Iterator rhs) const;

  bool operator!=(Iterator rhs) const;
};

//L'operatore unario * è sovrascritto per ritornare l'elemento a cui l'iteratore punta tramite reference, il prefisso ++ muove l'iteratore che poi punta all'elemento successivo nella sequenza e ritorna l'iteratore stesso tramite reference, questo permette di poter fare una catena di operatore ++.
//L'operatore di uguaglianza serve per determinare se il ricevitore punta allo stesso elemento dell'iteratore rhs, si passa l'iteratore per valore, è una pratica standard dato che generalmente sono piccoli fare copie non è dispendioso.
//La rappresentazione di un iteratore è specifico ad un particolare tipo di contenitore, per una lista linked, l'attraversamento tramite iteratore è un astrazione del print().
//Un iteratore di una lista è un astrazione di un puntatore al nodo, la chiamata list.begin() riturna un iteratore costruito da first, list.end() ritorna un null pointer, confrontare due interatori confronta i loro puntatori al nodo, incrementare un iteratore muove il suo puntatore nodo a quello successivo usando il membro next del nodo originale, deferenziare l'iteratore fa ottenere il membro datum del nodo sottostante.

template <typename T>
class Iterator {
  ...
private:
  Node *node_ptr;
};

//Ci sono tuttavia dei problemi nella definizione, Nodo non è un tipo superiore, ma un membro del template della classe lista, quindi non può essere chiamato da fuori senza lo scooping, la struttura nodo è privata quindi non può essere accessibile dall'esterno, il tipo iteratore è associato alla lista, quindi dovrebbe essere incapsulato all'interno del template list, si può risolvere tutto ciò definendo l'iteratore come membro del template list.

template <typename T>
class List {
  ...
private:
  struct Node {
    int datum;
    Node *next;
  };

public:
  class Iterator {
  public:
    T & operator*() const;

    Iterator &operator++();

    bool operator==(Iterator rhs) const;

    bool operator!=(Iterator rhs) const;
  private:
    Node *node_ptr;
  };

private:
  Node *first;
  Node *last;
};

//Si deve definire l'iteratore dopo la definizione della struct Node così che Nodo nel blocco quando è riferito è nella classe iteratore.
//
