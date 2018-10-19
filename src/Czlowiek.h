#ifndef CZLOWIEK_H
#define CZLOWIEK_H

#include "Zwierze.h"


class Czlowiek : public Zwierze
{
    public:
        Czlowiek(Swiat* var, Kontener* varK, int parentX = -1, int parentY = -1);
        virtual ~Czlowiek();
        void akcja();
        void ruch();
        void kolizja(Organizm* atakujacy);
        void ustawOpcje(char val) { opcja = val; }
    protected:
    private:
        char opcja;
        int cooldown;
        bool aktywna;
};

#endif // CZLOWIEK_H
