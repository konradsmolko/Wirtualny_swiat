#ifndef ZOLW_H
#define ZOLW_H

#include "Zwierze.h"


class Zolw : public Zwierze
{
    public:
        Zolw(Swiat* var, Kontener* varK, int parentX = -1, int parentY = -1);
        ~Zolw();
        void akcja();
        void kolizja(Organizm* atakujacy);
    protected:
    private:
};

#endif // ZOLW_H
