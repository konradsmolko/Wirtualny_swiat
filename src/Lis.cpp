#include "Lis.h"
#include <iostream>

using namespace std;

Lis::Lis(Swiat* varS, Kontener* varK, int parentX, int parentY)
{
    symbol = 'F';
    swiat = varS;
    kontener = varK;
    sila = 3;
    inicjatywa = 7;
    wiek = 0;

    relokacja(parentX, parentY);
}

void Lis::akcja()
{
    int target_X;
    int target_Y;

    do
    {
        do
        {
            target_X = X + (kontener->losowa()%3 - 1);
        } while(target_X < 0 || target_X >= MAP_SIZE);

        do
        {
            target_Y = Y + (kontener->losowa()%3 - 1);
        } while(target_Y < 0 || target_Y >= MAP_SIZE);
    } while(target_X == X && target_Y == Y);

    if(kontener->zajete(target_X, target_Y))
    {
        if(!kontener->oznaczony(kontener->wezPoLokacji(target_X, target_Y)))
        {
            if(this->sila >= kontener->wezPoLokacji(target_X, target_Y)->getSila())
               kontener->wezPoLokacji(target_X, target_Y)->kolizja(this);
        } else
        {
            X = target_X;
            Y = target_Y;
        }
    } else
    {
        X = target_X;
        Y = target_Y;
    }
}

Lis::~Lis()
{
    //dtor
}
