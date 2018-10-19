#include "Guarana.h"

Guarana::Guarana(Swiat* varS, Kontener* varK, int parentX, int parentY)
{
    symbol = 'g';
    swiat = varS;
    kontener = varK;
    sila = 0;
    inicjatywa = 0;
    wiek = 0;

    relokacja(parentX, parentY);
}

void Guarana::kolizja(Organizm* atakujacy)
{
    swiat->dodajDoLoga(atakujacy->getSymbol() + " zjada " + this->symbol +
                       " i dostaje +1 do sily!");
    atakujacy->setX(X);
    atakujacy->setY(Y);
    atakujacy->setSila(atakujacy->getSila() + 1);
    kontener->zabij(this);
}

Guarana::~Guarana()
{
    //dtor
}
