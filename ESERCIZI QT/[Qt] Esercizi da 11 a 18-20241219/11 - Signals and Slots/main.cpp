#include <QApplication>
#include "MyClass.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Create an instance of MyClass
    MyClass myObject;

    // Show the button
    myObject.showButton();

    return app.exec();
}