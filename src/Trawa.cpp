#include "Trawa.h"

Trawa::Trawa(Swiat* varS, Kontener* varK, int parentX, int parentY)
{
    symbol = 'w';
    swiat = varS;
    kontener = varK;
    sila = 0;
    inicjatywa = 0;
    wiek = 0;

    relokacja(parentX, parentY);
}

Trawa::~Trawa()
{
    //dtor
}
