#include "Wilk.h"

Wilk::Wilk(Swiat* varS, Kontener* varK, int parentX, int parentY)
{
    symbol = 'W';
    swiat = varS;
    kontener = varK;
    sila = 9;
    inicjatywa = 5;
    wiek = 0;

    relokacja(parentX, parentY);
}

Wilk::~Wilk()
{
    //dtor
}
