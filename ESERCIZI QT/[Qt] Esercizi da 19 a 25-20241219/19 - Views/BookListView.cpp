#include "BookListView.h"

BookListView::BookListView(QWidget *parent) : QWidget(parent)
{
    listWidget = new QListWidget(this);

    // TODO: Connect the listWidget's itemClicked signal to emit bookSelected with the correct index
    connect(listWidget, &QListWidget::itemClicked, this, [this](QListWidgetItem *item)
            {int index = listWidget->row(item); emit bookSelected(index); });
}

void BookListView::setBooks(const QVector<Book> &books)
{
    // TODO: Populate the listWidget with book titles
    listWidget->clear(); // Pulisce la lista precedente
    for (const Book &book : books)
    {
        listWidget->addItem(book.getTitle()); // Usa il titolo del libro
    }
}
