#include "Roslina.h"
#include <chrono>
#include <random>

#define SZANSA 10

Roslina::Roslina()
{

}

void Roslina::akcja()
{
    rozmnazanie();
}

void Roslina::rozmnazanie(int proby)
{
    do
    {
        if((kontener->losowa()%100 + 1) <= SZANSA) // 10% szans na rozsianie w kazdej probie
            if(kontener->dodaj(this->symbol, X, Y))
                swiat->dodajDoLoga(this->symbol + " sie rozprzestrzenia");
    } while(--proby > 0);
}

void Roslina::kolizja(Organizm* atakujacy)
{
    swiat->dodajDoLoga(atakujacy->getSymbol() + " zjada " + this->symbol);
    atakujacy->setX(X);
    atakujacy->setY(Y);
    kontener->zabij(this);
}

Roslina::~Roslina()
{
    //dtor
}
