#ifndef ANTYLOPA_H
#define ANTYLOPA_H

#include "Zwierze.h"


class Antylopa : public Zwierze
{
    public:
        Antylopa(Swiat* var, Kontener* varK, int parentX = -1, int parentY = -1);
        ~Antylopa();
        void akcja();
        void kolizja(Organizm* atakujacy);
    protected:
    private:
};

#endif // ANTYLOPA_H
