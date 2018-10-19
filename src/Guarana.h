#ifndef GUARANA_H
#define GUARANA_H

#include "Roslina.h"


class Guarana : public Roslina
{
    public:
        Guarana(Swiat* var, Kontener* varK, int parentX = -1, int parentY = -1);
        ~Guarana();
        void kolizja(Organizm* atakujacy);
    protected:
    private:
};

#endif // GUARANA_H
