#include "AbstractItem.h"

class Film : public AbstractItem
{
public:
    Film(const QString &title, const QString &author, const QString &genre, const int &year, const QString &director, QString &protagonist) : AbstractItem(title, author, genre, year), director(director), protagonist(protagonist) {}
    QString getDirector();
    QString getProtagonist();

private:
    QString director;
    QString protagonist;
};