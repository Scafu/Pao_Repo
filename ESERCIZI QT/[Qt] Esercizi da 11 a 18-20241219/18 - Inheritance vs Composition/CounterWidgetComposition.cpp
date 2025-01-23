#include "CounterWidgetComposition.h"
#include <QVBoxLayout>

CounterWidgetComposition::CounterWidgetComposition(QWidget *parent)
    : QWidget(parent), counter(0)
{
    // Inizializza il pulsante
    button = new QPushButton("Increment", this);

    // Inizializza l'etichetta
    label = new QLabel("Count: 0", this);

    // Crea un layout verticale e aggiungi i widget
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(label);
    layout->addWidget(button);
    setLayout(layout);

    // Collega il segnale clicked del pulsante allo slot incrementCounter
    connect(button, &QPushButton::clicked, this, &CounterWidgetComposition::incrementCounter);
}

void CounterWidgetComposition::incrementCounter()
{
    // Incrementa il contatore e aggiorna il testo dell'etichetta
    ++counter;
    label->setText("Count: " + QString::number(counter));
}
