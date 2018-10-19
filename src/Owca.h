#ifndef OWCA_H
#define OWCA_H

#include "Zwierze.h"


class Owca : public Zwierze
{
    public:
        Owca(Swiat* var, Kontener* varK, int parentX = -1, int parentY = -1);
        virtual ~Owca();
    protected:
    private:
};

#endif // OWCA_H
