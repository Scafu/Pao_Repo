#include "ListViewWidget.h"

ListViewWidget::ListViewWidget(QWidget *parent) : QWidget(parent)
{
    // TODO: Create the list view, line edit, and buttons
    listView = new QListView();
    lineEdit = new QLineEdit();
    addButton = new QPushButton("add item");
    removeButton = new QPushButton("remove item");

    // Create the model and set it to the list view
    model = new QStringListModel(this);
    listView->setModel(model);

    // TODO: Create a vertical layout
    QVBoxLayout *layout = new QVBoxLayout();
    // TODO: Add widgets to the layout
    layout->addWidget(listView);
    layout->addWidget(lineEdit);
    layout->addWidget(addButton);
    layout->addWidget(removeButton);
    // TODO: Connect the addButton's clicked signal to the addItem slot
    connect(addButton, &QPushButton::clicked, this, ListViewWidget::addItem);

    // TODO: Connect the removeButton's clicked signal to the removeItem slot
    connect(removeButton, &QPushButton::clicked, this, ListViewWidget::removeItem);

    setLayout(layout);
}

void ListViewWidget::addItem()
{
    QString item = lineEdit->text();
    if (!item.isEmpty())
    {
        QStringList currentList = model->stringList();
        currentList.append(item);
        model->setStringList(currentList);
        lineEdit->clear();
    }
}

void ListViewWidget::removeItem()
{
    QModelIndex selectedIndex = listView->currentIndex();
    if (selectedIndex.isValid())
    {
        QStringList currentList = model->stringList();
        currentList.removeAt(selectedIndex.row());
        model->setStringList(currentList);
    }
}
