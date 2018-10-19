#include "Antylopa.h"
#include <chrono>
#include <random>
#include <iostream>

Antylopa::Antylopa(Swiat* varS, Kontener* varK, int parentX, int parentY)
{
    symbol = 'A'; // Antylopa.
    swiat = varS;
    kontener = varK;
    sila = 4;
    inicjatywa = 4;
    wiek = 0;

    relokacja(parentX, parentY);
}

void Antylopa::akcja()
{
    ruch(2);
}

void Antylopa::kolizja(Organizm* atakujacy)
{
    if(this->symbol == atakujacy->getSymbol()) // rozmnozenie
    {
        if(kontener->dodaj(this->symbol, this->X, this->Y))
            swiat->dodajDoLoga(this->symbol + " sie rodzi!");
    }
    else if((kontener->losowa()%100 + 1) <= 50 && kontener->wolneDookola(X, Y)) // ucieczka
    {
        atakujacy->setX(X);
        atakujacy->setY(Y);
        relokacja(X, Y);
        swiat->dodajDoLoga(this->symbol + " ucieka przed atakiem " + atakujacy->getSymbol());
    } else if(this->sila <= atakujacy->getSila()) // smierc w wyniku ataku (walka rowniez gdy antylopa nie ma gdzie ucuec)
    {
        atakujacy->setX(X);
        atakujacy->setY(Y);
        kontener->zabij(this);
        swiat->dodajDoLoga(this->symbol + " zostaje zabity/a przez " + atakujacy->getSymbol());
    } else
    {
        kontener->zabij(atakujacy); // smierc atakujacego w wyniku samoobrony
        swiat->dodajDoLoga(atakujacy->getSymbol() + " zostaje zabity/a przez " + this->symbol + " w wyniku samoobrony");
    }
}

Antylopa::~Antylopa()
{
    //dtor
}
