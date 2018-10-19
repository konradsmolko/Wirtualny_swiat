#ifndef ZWIERZE_H
#define ZWIERZE_H

#include "Organizm.h"


class Zwierze : public Organizm
{
    public:
        Zwierze();
        virtual ~Zwierze();
        virtual void akcja();
        void ruch(int zasieg = 1);
        virtual void kolizja(Organizm* atakujacy);
    protected:
    private:
};

#endif // ZWIERZE_H
