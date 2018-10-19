#include "WilczeJagody.h"

WilczeJagody::WilczeJagody(Swiat* varS, Kontener* varK, int parentX, int parentY)
{
    symbol = 'j';
    swiat = varS;
    kontener = varK;
    sila = 99;
    inicjatywa = 0;
    wiek = 0;

    relokacja(parentX, parentY);
}

void WilczeJagody::kolizja(Organizm* atakujacy)
{
    swiat->dodajDoLoga(atakujacy->getSymbol() + " zjada " + this->symbol +
                       " i ginie na skutek zatrucia!");
    kontener->zabij(this);
    kontener->zabij(atakujacy);
}

WilczeJagody::~WilczeJagody()
{
    //dtor
}
