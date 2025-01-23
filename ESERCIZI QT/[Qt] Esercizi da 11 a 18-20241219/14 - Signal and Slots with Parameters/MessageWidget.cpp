#include "MessageWidget.h"
#include <QVBoxLayout>

MessageWidget::MessageWidget(QWidget *parent) : QWidget(parent)
{
    // TODO: Create label, line edit (text input), and button
    label = new QLabel();
    lineEdit = new QLineEdit();
    button = new QPushButton();
    // TODO: Create a vertical layout
    QVBoxLayout *layout = new QVBoxLayout();
    // TODO: Add widgets to the layout
    layout->addWidget(label);
    layout->addWidget(lineEdit);
    layout->addWidget(button);
    // TODO: Connect the button's clicked signal to the updateLabel slot
    connect(button, &QPushButton::clicked, this, MessageWidget::updateLabel);

    setLayout(layout);
}

void MessageWidget::updateLabel()
{
    // TODO: Get the text from lineEdit and set it as the label text
    QString text = lineEdit->text();
    label->setText(text);
}
