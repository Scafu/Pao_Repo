#ifndef BOOKVIEWMANAGER_H
#define BOOKVIEWMANAGER_H

#include <QWidget>
#include <QComboBox>
#include <QStackedWidget>
#include "BookListView.h"
#include "BookDetailView.h"
#include "Book.h"

class BookViewManager : public QWidget
{
    Q_OBJECT

public:
    explicit BookViewManager(QWidget *parent = nullptr);

    void setBooks(const QVector<Book> &books);

private:
    QComboBox *viewSelector;    // ComboBox per selezionare la vista
    QStackedWidget *viewStack;  // StackedWidget per contenere diverse viste
    BookListView *listView;     // Vista elenco libri
    BookDetailView *detailView; // Vista dettagli libro

private slots:
    void switchView(int index);           // Cambia la vista selezionata
    void updateDetailView(int bookIndex); // Aggiorna i dettagli del libro selezionato
};

#endif // BOOKVIEWMANAGER_H
