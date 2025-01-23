
#include <QString>

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

private:
    QString title;
    QString author;
    QString genre;
    int year;
};