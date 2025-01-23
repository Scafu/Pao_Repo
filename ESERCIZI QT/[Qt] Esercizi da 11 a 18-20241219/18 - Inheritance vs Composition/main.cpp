#include <QApplication>
#include <QTabWidget>
#include <QVBoxLayout>
#include "CounterButtonInheritance.h"
#include "CounterWidgetComposition.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Creazione di QTabWidget
    QTabWidget tabWidget;
    tabWidget.setWindowTitle("Tabs with Counters");

    // Prima scheda: CounterButtonInheritance
    CounterButtonInheritance *counterButton = new CounterButtonInheritance();
    QWidget *tab1 = new QWidget();
    QVBoxLayout *tab1Layout = new QVBoxLayout(tab1);
    tab1Layout->addWidget(counterButton);          // Aggiungi il pulsante al layout della scheda
    tabWidget.addTab(tab1, "Inheritance Counter"); // Aggiungi la scheda al QTabWidget

    // Seconda scheda: CounterWidgetComposition
    CounterWidgetComposition *counterWidget = new CounterWidgetComposition();
    QWidget *tab2 = new QWidget();
    QVBoxLayout *tab2Layout = new QVBoxLayout(tab2);
    tab2Layout->addWidget(counterWidget);          // Aggiungi il widget al layout della scheda
    tabWidget.addTab(tab2, "Composition Counter"); // Aggiungi la scheda al QTabWidget

    // Mostra il QTabWidget
    tabWidget.resize(400, 300); // Imposta dimensioni della finestra
    tabWidget.show();

    return app.exec();
}
