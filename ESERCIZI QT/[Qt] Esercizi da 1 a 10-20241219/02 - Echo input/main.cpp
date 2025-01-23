#include <QCoreApplication>
#include <QTextStream>
#include <iostream>
int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    QTextStream input(stdin);   // Stream per leggere da console
    QTextStream output(stdout); // Stream per scrivere su console

    output << "Inserisci il tuo nome: " << Qt::endl;
    QString name = input.readLine(); // Legge una riga dall'input

    output << "Ciao, " << name << "!" << Qt::endl;

    return 0;
}
