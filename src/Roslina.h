#ifndef ROSLINA_H
#define ROSLINA_H

#include "Organizm.h"


class Roslina : public Organizm
{
    public:
        Roslina();
        virtual ~Roslina();
        virtual void akcja();
        virtual void rozmnazanie(int proby = 1);
        virtual void kolizja(Organizm* atakujacy);
    protected:
    private:
};

#endif // ROSLINA_H
