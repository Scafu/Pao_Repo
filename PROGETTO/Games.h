#include "AbstractItem.h"
#include <vector>

class Games : public AbstractItem
{
public:
    Games(const QString &title, const QString &author, const QString &genre, const int &year, const QString &publisher, const std::vector<QString> &platforms);
    QString getPublisher();
    std::vector<QString> getPlatforms();
    virtual void accept(Visitor *visitor);

private:
    QString publisher;
    std::vector<QString> platforms;
};