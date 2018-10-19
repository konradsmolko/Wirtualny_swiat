#include "Mlecz.h"

Mlecz::Mlecz(Swiat* varS, Kontener* varK, int parentX, int parentY)
{
    symbol = 'm';
    swiat = varS;
    kontener = varK;
    sila = 0;
    inicjatywa = 0;
    wiek = 0;

    relokacja(parentX, parentY);
}

void Mlecz::akcja()
{
    rozmnazanie(3);
}

Mlecz::~Mlecz()
{
    //dtor
}
