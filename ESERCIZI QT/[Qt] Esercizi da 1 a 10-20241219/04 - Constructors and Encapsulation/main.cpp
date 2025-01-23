#include <QCoreApplication>
#include <QDebug>

// TODO: Define the Person class
class Person
{
public:
    Person(QString name_in = "Pippo", int age_in = 0) : name(name_in), age(age_in) {}
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
// The class should have:
// - A private attribute `name` (QString)
// - A private attribute `age` (int)
// - A public constructor that initializes `name` and `age`
// - A public method `getName` that returns the name
// - A public method `getAge` that returns the age
// - A public method `printInfo` to display the person's details using qDebug()

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    Person person_generic;
    // TODO: Create a Person object using the constructor
    // TODO: Display the person's details by calling `printInfo`

    person_generic.printInfo();
    return app.exec();
}