#include "MyClass.h"
#include <QDebug>

MyClass::MyClass(QObject *parent) : QObject(parent)
{
    button = new QPushButton("Click me!", nullptr);

    // Connetti il segnale clicked al tuo slot handleClick
    connect(button, &QPushButton::clicked, this, &MyClass::handleClick);
}

void MyClass::showButton()
{
    button->show();
}

void MyClass::handleClick()
{
    // Print a message to the console when the button is clicked
    qDebug() << "Button was clicked!";
}