#include "BookDetailView.h"
#include <QVBoxLayout>

BookDetailView::BookDetailView(QWidget *parent) : QWidget(parent)
{
    titleLabel = new QLabel(this);
    authorLabel = new QLabel(this);
    yearLabel = new QLabel(this);

    // TODO: Arrange labels in a layout
    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(titleLabel);
    layout->addWidget(authorLabel);
    layout->addWidget(yearLabel);
}

void BookDetailView::displayBook(const Book &book)
{
    // TODO: Set the text of the labels based on the book details
    titleLabel->setText(book.getTitle());
    authorLabel->setText(book.getAuthor());
    yearLabel->setText(QString::number(book.getYear()));
}
