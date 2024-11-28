/*
Si consideri il seguente modello di realtà concernente i file audio memorizzati in un riproduttore audio digitale iZod.

(A) Definire la seguente gerarchia di classi.

1. Definire una classe base polimorfa astratta FileAudio i cui oggetti rappresentano un file audio memorizzabile in un iZod. Ogni FileAudio  e' caratterizzato dal titolo (una stringa) e dalla propria dimensione in MB. La classe è astratta in quanto prevede i seguenti metodi virtuali puri:

• un metodo di “clonazione”;

• un metodo bool qualita() con il seguente contratto: f->qualita() ritorna true se il file audio *f è considerato di
qualità, altrimenti ritorna false.

2. Definire una classe concreta Mp3 derivata da FileAudio i cui oggetti rappresentano un file audio in formato mp3. Ogni oggetto Mp3 è caratterizzato dal proprio bitrate espresso in Kbit/s. La classe Mp3 implementa i metodi virtuali puri di FileAudio come segue:

• implementazione canonica del metodo di clonazione;

• per ogni puntatore p a Mp3, p->qualita() ritorna true se il bitrate di *p è ≥ 192 Kbit/s, altrimenti ritorna false.

3. Definire una classe concreta WAV derivata da FileAudio i cui oggetti rappresentano un file audio in formato WAV. Ogni oggetto WAV è caratterizzato dalla propria frequenza di campionamento espressa in kHz e dall’essere lossless oppure no (cioè con compressione senza perdita oppure con perdita). La classe WAV implementa i metodi virtuali puri di FileAudio come segue:

• implementazione canonica del metodo di clonazione;

• per ogni puntatore p a WAV, p->qualita() ritorna true se la frequenza di campionamento di *p è ≥ 96 kHz, altrimenti
ritorna false.
*/

#include <iostream>
#include <string>

class FileAudio
{
private:
    double MB;
    std::string title;

public:
    virtual ~FileAudio() = default;
    virtual FileAudio *clonazione() const = 0;
    virtual bool qualità() const = 0;
    double getSize() const { return MB; }
    virtual bool operator==(const FileAudio &fa) const { return typeid(*this) == typeid(fa) && title == fa.title && MB == fa.MB; }
};

class Mp3 : public FileAudio
{
private:
    unsigned int bitrate;
    static unsigned int br_threshold;

public:
    Mp3 *clonazione() const override;
    bool qualità() const override;
    unsigned int getBitrate() const;
    bool operator==(const FileAudio &fa) const override
    {
        return this->FileAudio::operator==(fa) && bitrate == static_cast<const Mp3 &>(fa).bitrate;
    }
};
unsigned int Mp3::br_threshold = 192;
Mp3 *Mp3::clonazione() const
{
    return new Mp3(*this);
}
bool Mp3::qualità() const
{
    return bitrate >= 192;
}
unsigned int Mp3::getBitrate() const
{
    return bitrate;
}
typedef int kHz;
class WAV : public FileAudio
{
private:
    kHz frequency;
    bool lossless;
    static unsigned int fr_threshold;

public:
    WAV *clonazione() const override;
    bool qualità() const override;
    bool isLossLess() const;
    bool operator==(const FileAudio &fa) const override
    {
        return this->FileAudio::operator==(fa) && frequency == static_cast<const WAV &>(fa).frequency && lossless == static_cast<const WAV &>(fa).lossless;
    }
};

WAV *WAV::clonazione() const
{
    return new WAV(*this);
}
bool WAV::qualità() const
{
    return frequency >= 96;
}
bool WAV::isLossLess() const
{
    return lossless;
}
unsigned int WAV::fr_threshold = 96;
/*(B) Definire una classe iZod i cui oggetti rappresentano i brani memorizzati in un iZod. La classe iZod deve soddisfare le seguenti specifiche:
`
1. E definita una classe annidata Brano i cui oggetti rappresentano un brano memorizzato nell’iZod. Ogni oggetto Brano è
rappresentato da un puntatore (super)polimorfo ad un FileAudio.

• La classe Brano deve essere dotata di un opportuno costruttore Brano(FileAudio*) con il seguente comportamento:
Brano(p) costruisce un oggetto Brano il cui puntatore polimorfo punta ad una copia dell’oggetto *p.

• La classe Brano ridefinisce costruttore di copia profonda, assegnazione profonda e distruttore profondo.

2. Un oggetto di iZod è quindi caratterizzato da un vector di oggetti di tipo Brano che contiene tutti i brani memorizzati nell’iZod.

3. La classe iZod rende disponibili i seguenti metodi:

• Un metodo vector<Mp3> mp3(double, int) con il seguente comportamento: una invocazione iz.mp3(dim,br) ritorna un vector di oggetti Mp3 contenente tutti e soli i file audio in formato mp3 memorizzati nell’iZod iz che: (i) hanno una dimensione ≥ dim e (ii) hanno un bitrate ≥ br.

• Un metodo vector<FileAudio*> braniQual() con il seguente comportamento: una invocazione iz.braniQual() ritorna il vector dei puntatori ai FileAudio memorizzati nell’iZod iz che: (i) sono considerati di qualità e (ii) se sono dei file audio WAV allora devono essere lossless.

• Un metodo void insert(Mp3*) con il seguente comportamento: una invocazione iz.insert(p) inserisce il nuovo oggetto Brano(p) nel vector dei brani memorizzati nell’iZod iz se il file audio mp3 *p non è già memorizzato in iz, mentre se il file audio *p risulta già memorizzato non provoca alcun effetto.
*/
#include <vector>

class iZod
{
private:
    class Brano
    {
    public:
        FileAudio *p;
        Brano(FileAudio *p = nullptr) : p(p->clonazione()) {}
        ~Brano() { delete p; }
        Brano(const Brano &br) : p((br.p)->clonazione()) {}
        Brano &operator=(const Brano &b)
        {
            if (this != &b)
            {
                delete p;
                p = (b.p)->clonazione();
            }
            return *this;
        }
    };
    std::vector<Brano> brani;

public:
    std::vector<Mp3> mp3(double, int) const;
    std::vector<FileAudio *> braniQual() const;
    void insert(Mp3 *);
};

std::vector<Mp3> iZod::mp3(double dim, int bitrate) const
{
    std::vector<Mp3> braniToSave;
    for (std::vector<Brano>::const_iterator cit = brani.begin(); cit != brani.end(); cit++)
        if (dynamic_cast<Mp3 *>(cit->p) && (cit->p)->getSize() >= dim && (static_cast<Mp3 *>(cit->p)->getBitrate() >= bitrate))
            braniToSave.push_back(*(static_cast<Mp3 *>(cit->p)));
    return braniToSave;
}

std::vector<FileAudio *> iZod::braniQual() const
{
    std::vector<FileAudio *> w;
    for (std::vector<Brano>::const_iterator cit = brani.begin(); cit != brani.end(); ++cit)
    {
        WAV *p = dynamic_cast<WAV *>(cit->p);
        if (cit->p && (cit->p)->qualità() && (!p || p->isLossLess()))
            w.push_back(p);
    }
    return w;
}

void iZod::insert(Mp3 *p)
{
    if (p)
    {
        bool found = false;
        for (unsigned int i = 0; !found && i < brani.size(); ++i)
            if (brani[i].p && *(brani[i].p) == *p)
                found = true;
        if (!found)
            brani.push_back(p);
    }
}