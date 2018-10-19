#ifndef MLECZ_H
#define MLECZ_H

#include "Roslina.h"


class Mlecz : public Roslina
{
    public:
        Mlecz(Swiat* var, Kontener* varK, int parentX = -1, int parentY = -1);
        virtual ~Mlecz();
        void akcja();
    protected:
    private:
};

#endif // MLECZ_H
