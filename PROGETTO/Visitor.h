#include "Games.h"
#include "Film.h"

class Visitor
{
public:
    virtual void visit(Games &games) = 0;
    virtual void visit(Film &film) = 0;
};