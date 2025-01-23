#include <QCoreApplication>
#include <QList>
#include <QDebug>

// Reuse the Person class
class Person
{
public:
    Person(QString name_in = "Pippo", int age_in = 0) : name(name_in), age(age_in) {}
    ~Person() {};
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

    // Create a QList to store Person objects
    QList<Person> persons;

    // Add a few Person objects to the list
    persons.append(Person("Gianluca", 13));
    persons.append(Person("Pietro", 14));
    persons.append(Person("Marco", 15));

    // Display all Person objects in the list
    qDebug() << "Initial list of persons:";
    for (const Person &person : persons)
    {
        person.printInfo();
    }

    // Remove a Person object from the list (e.g., "Pietro")
    for (int i = 0; i < persons.size(); ++i)
    {
        if (i == 1)
        {
            persons.removeAt(0);
        }
    }

    // Display the updated list
    qDebug() << "Updated list of persons:";
    for (const Person &person : persons)
    {
        person.printInfo();
    }

    return app.exec();
}
