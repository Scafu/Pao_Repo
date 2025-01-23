#include <QCoreApplication>
#include <QDebug>

// Reuse the Person class from the previous exercise
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

    // TODO: Dynamically create a Person object
    // Use the constructor to initialize the object
    Person *person = new Person("Gianluca", 13);

    // TODO: Call the printInfo method to display the person's details
    person->printInfo();
    // TODO: Deallocate the memory used by the Person object
    delete person;
    return app.exec();
}