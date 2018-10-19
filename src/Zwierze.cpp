#include "Zwierze.h"
#include <chrono>
#include <iostream>
#include <random>
#define MAP_SIZE 20

Zwierze::Zwierze()
{
    //ctor
}

void Zwierze::akcja()
{
    ruch();
}

void Zwierze::ruch(int zasieg)
{
    int targetX;
    int targetY;

    do
    {
        do
        {
            targetX = X + (kontener->losowa()%(zasieg*2 + 1) - zasieg);
        } while(targetX < 0 || targetX >= MAP_SIZE);

        do
        {
            targetY = Y + (kontener->losowa()%(zasieg*2 + 1) - zasieg);
        } while(targetY < 0 || targetY >= MAP_SIZE);
    } while(targetX == X && targetY == Y);

    if(kontener->zajete(targetX, targetY))
    {
        if(!kontener->oznaczony(kontener->wezPoLokacji(targetX, targetY)))
        {
            kontener->wezPoLokacji(targetX, targetY)->kolizja(this);
        } else
        {
            X = targetX;
            Y = targetY;
        }
    } else
    {
        X = targetX;
        Y = targetY;
    }
}

void Zwierze::kolizja(Organizm* atakujacy) // this się broni!
{
    if(this->symbol == atakujacy->getSymbol())
    {
        if(kontener->dodaj(this->symbol, this->X, this->Y))
            swiat->dodajDoLoga(this->symbol + " sie rodzi!");
    } else if(this->sila <= atakujacy->getSila())
    {
        atakujacy->setX(X);
        atakujacy->setY(Y);
        kontener->zabij(this);
        swiat->dodajDoLoga(this->symbol + " zostaje zabity/a przez " + atakujacy->getSymbol());
    } else
    {
        kontener->zabij(atakujacy);
        swiat->dodajDoLoga(atakujacy->getSymbol() + " zostaje zabity/a przez " + this->symbol + " w wyniku samoobrony");
    }
}

Zwierze::~Zwierze()
{
    //dtor
}
