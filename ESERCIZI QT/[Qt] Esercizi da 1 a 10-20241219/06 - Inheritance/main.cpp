#include <QCoreApplication>
#include <QDebug>

// TODO: Define the Person class (reuse from previous exercises)
class Person
{
public:
    Person(QString name_in = "Pippo", int age_in = 0) : name(name_in), age(age_in) {}
    virtual ~Person() {};
    void setName(const QString &name_in) { this->name = name_in; }
    void setAge(int age_in) { this->age = age_in; }
    virtual void printInfo() const
    {
        qDebug() << "Name:" << name << ", Age:" << age;
    }

protected:
    QString name;
    int age;
};

// TODO: Define the Student class
class Student : public Person
{
public:
    Student(QString name_in, int age_in, QString university_in) : Person(name_in, age_in), university(university_in) {}
    void printInfo() const override
    {
        qDebug() << "Name:" << name << ", Age:" << age << ", University:" << university;
    }

private:
    QString university;
};
// The class should:
// - Inherit from Person
// - Have a private attribute `university` (QString)
// - Include a constructor to initialize the name, age, and university
// - Have a method `printInfo` that overrides the base class method
//   to display all details (name, age, and university)

main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    // TODO: Create a Student object
    // TODO: Call the printInfo method to display the student's details

    return app.exec();
}