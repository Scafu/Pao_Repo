#include "BookViewManager.h"
#include <QVBoxLayout>

BookViewManager::BookViewManager(QWidget *parent) : QWidget(parent)
{
    // Creazione dei widget per la selezione della vista e del contenitore delle viste
    viewSelector = new QComboBox(this);
    viewStack = new QStackedWidget(this);

    // Creazione delle viste per l'elenco dei libri e i dettagli
    listView = new BookListView(this);
    detailView = new BookDetailView(this);

    // Aggiungi le viste allo stacked widget
    viewStack->addWidget(listView);
    viewStack->addWidget(detailView);

    // Aggiungi le opzioni al combobox per selezionare la vista
    viewSelector->addItem("List View");
    viewSelector->addItem("Detail View");

    // Connessione del combobox per cambiare vista
    connect(viewSelector, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &BookViewManager::switchView);

    // Connessione del segnale bookSelected per aggiornare i dettagli del libro
    connect(listView, &BookListView::bookSelected, this, &BookViewManager::updateDetailView);

    // Creazione del layout per disporre i widget
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(viewSelector); // Combobox in cima
    layout->addWidget(viewStack);    // Stacked widget sotto

    setLayout(layout);
}

void BookViewManager::setBooks(const QVector<Book> &books)
{
    // Impostare i libri per la vista elenco e dettagli
    listView->setBooks(books);
    detailView->setBooks(books);
}

void BookViewManager::switchView(int index)
{
    // Cambia la vista in base alla selezione del combobox
    viewStack->setCurrentIndex(index);
}

void BookViewManager::updateDetailView(int bookIndex)
{
    // Aggiorna la vista dei dettagli con il libro selezionato
    detailView->displayBookDetails(bookIndex);
}
