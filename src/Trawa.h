#ifndef TRAWA_H
#define TRAWA_H

#include "Roslina.h"


class Trawa : public Roslina
{
    public:
        Trawa(Swiat* var, Kontener* varK, int parentX = -1, int parentY = -1);
        virtual ~Trawa();
    protected:
    private:
};

#endif // TRAWA_H
