#include <QString>
#include "visitor.h"

class AbstractItem
{
public:
    AbstractItem(const QString &title, const QString &author, const QString &genre, const int &year) : title(title), author(author), genre(genre), year(year) {};
    virtual ~AbstractItem();
    QString getTitle();
    QString getAuthor();
    QString getGenre();
    int getYear();

    void setTitle(const QString &name);
    void setAuthor(const QString &author);
    void setYear(const int &year);
    void setGenre(const QString &genre);

    virtual void accept(Visitor *visitor) = 0;

private:
    QString title;
    QString author;
    QString genre;
    int year;
};