#include "Owca.h"

Owca::Owca(Swiat* varS, Kontener* varK, int parentX, int parentY)
{
    symbol = 'Q'; // Qwca :)
    swiat = varS;
    kontener = varK;
    sila = 4;
    inicjatywa = 4;
    wiek = 0;

    relokacja(parentX, parentY);
}

Owca::~Owca()
{
    //dtor
}
