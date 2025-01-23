#ifndef ITEMWIDGET_H
#define ITEMWIDGET_H

#include "Visitor.h"

class Games;
class Film;

class itemWidget : public Visitor
{
    virtual void visit(Games &games);
    virtual void visit(Film &games);
};

#endif