#include "Zolw.h"

Zolw::Zolw(Swiat* varS, Kontener* varK, int parentX, int parentY)
{
    symbol = 'Z';
    swiat = varS;
    kontener = varK;
    sila = 2;
    inicjatywa = 1;
    wiek = 0;

    relokacja(parentX, parentY);
}

void Zolw::akcja()
{
    if(kontener->losowa()%100 - 1 <= 25)
        ruch();
}

void Zolw::kolizja(Organizm* atakujacy)
{
    if(this->symbol == atakujacy->getSymbol()) // rozmnozenie
    {
        if(kontener->dodaj(this->symbol, this->X, this->Y))
            swiat->dodajDoLoga(this->symbol + " sie rodzi!");
    } else if(atakujacy->getSila() > 5) // specyfika kolizji zolwia
    {
        atakujacy->setX(X);
        atakujacy->setY(Y);
        kontener->zabij(this);
        swiat->dodajDoLoga(this->symbol + " zostaje zabity/a przez " + atakujacy->getSymbol());
    } else
    {
        swiat->dodajDoLoga(atakujacy->getSymbol() + " zostaje odpedzony/a przez " + this->symbol);
    }

    //cout << "Koniec kolizji\n";
}

Zolw::~Zolw()
{
    //dtor
}
