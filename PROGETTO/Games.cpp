#include "Games.h"

Games::Games(const QString &title, const QString &author, const QString &genre, const int &year, const QString &publisher, const std::vector<QString> &platforms) : AbstractItem(title, author, genre, year), publisher(publisher), platforms(platforms) {}

QString Games::getPublisher()
{
    return publisher;
}

std::vector<QString> Games::getPlatforms()
{
    if (platforms.empty())
    {

        throw std::runtime_error("Piattaforme non disponibili");
    }
    return platforms;
}

void Acce