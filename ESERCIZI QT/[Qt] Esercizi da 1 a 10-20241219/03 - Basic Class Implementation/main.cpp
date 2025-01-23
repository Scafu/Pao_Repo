#include <QCoreApplication>
#include <QDebug>
#include <QTextStream>

// Definizione della classe Person
class Person
{
public:
    void setName(const QString &name_in) { this->name = name_in; }
    void setAge(int age_in) { this->age = age_in; }
    void printInfo() const
    {
        qDebug() << "Nome:" << name;
        qDebug() << "Età:" << age;
    }

private:
    QString name;
    int age;
};

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    QTextStream output(stdout);
    QTextStream input(stdin);

    // Creazione di un oggetto Person
    Person person_in;

    // Input del nome
    output << "Ciao!" << Qt::endl;
    output << "Inserisci un nome: " << Qt::endl;
    QString nameInput = input.readLine();
    person_in.setName(nameInput);

    // Input dell'età
    output << "Inserisci l'età: " << Qt::endl;
    QString ageInput = input.readLine();
    bool ok;
    int age = ageInput.toInt(&ok);
    if (!ok || age < 0)
    {
        output << "Errore: Inserire un numero valido per l'età.\n";
        return -1; // Esci con errore
    }
    person_in.setAge(age);

    // Visualizzazione delle informazioni
    person_in.printInfo();

    return app.exec();
}
