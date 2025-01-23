#include <ios>
#include <ostream>
#include <istream>
#include <fstream>
#include <vector>
using namespace std;

vector<fstream *> Fun(const vector<const ios *> &v)
{
    vector<fstream *> result;
    for (auto q : v)
    {
        istream *n = dynamic_cast<istream *>(const_cast<ios *>(q));
        ostream *o = dynamic_cast<ostream *>(const_cast<ios *>(q));
        if (n && o)
            if (n->tellg() > o->tellp())
            {
                n->setstate(ios::goodbit);
            }
        fstream *f = dynamic_cast<fstream *>(const_cast<ios *>(q));
        if (f->rdstate() == 0 && f->is_open() == true)
        {
            f->close();
            result.push_back(f);
        }
        else
        {
            throw exception();
        }
    }

    return result;
}