#include "AbstractItem.h"

class MusicAlbum : public AbstractItem
{
public:
    MusicAlbum(const QString &title, const QString &author, const QString &genre, const int &year, const QString &band, QString &record_company) : AbstractItem(title, author, genre, year), band(band), record_company(record_company) {}
    QString getBand();
    QString getRecordCompany();

private:
    QString band;
    QString record_company;
};