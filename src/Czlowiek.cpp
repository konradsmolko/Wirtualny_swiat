#include "Czlowiek.h"
#include <iostream>
#define UPARROW 0x48
#define DOWNARROW 0x50
#define LEFTARROW 0x4b
#define RIGHTARROW 0x4d

Czlowiek::Czlowiek(Swiat* varS, Kontener* varK, int parentX, int parentY)
{
    symbol = '@';
    swiat = varS;
    kontener = varK;
    sila = 5;
    inicjatywa = 4;
    wiek = 0;
    cooldown = 0;
    aktywna = false;

    relokacja(parentX, parentY);
}

void Czlowiek::akcja()
{
    if(cooldown > 0)
    {
        cooldown--;
        if(cooldown < 5)
            aktywna = false;
    }

    switch(opcja)
    {
    case UPARROW:
    case DOWNARROW:
    case LEFTARROW:
    case RIGHTARROW:
        ruch();
        break;
    case 'r':
        if(cooldown == 0)
        {
            aktywna = true;
            cooldown = 10;
            swiat->dodajDoLoga(this->symbol +
                               " aktywowal Tarcze Alzura i odstrasza wszystkie zwierzeta!");
        } else swiat->dodajDoLoga("No sorry, ale cooldown tyka.");
        break;
    default:
        break;
    }

    opcja = ' ';
}

void Czlowiek::ruch()
{
    int targetX = 0;
    int targetY = 0;
    switch(opcja)
    {
    case UPARROW:
        if(Y != 0)
        {
            targetX = X;
            targetY = Y - 1;
        } else return;
        break;
    case DOWNARROW:
        if(Y != MAP_SIZE - 1)
        {
            targetX = X;
            targetY = Y + 1;
        } else return;
        break;
    case LEFTARROW:
        if(X != 0)
        {
            targetX = X - 1;
            targetY = Y;
        } else return;
        break;
    case RIGHTARROW:
        if(X != MAP_SIZE - 1)
        {
            targetX = X + 1;
            targetY = Y;
        } else return;
        break;
    default:
        break;
    }

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

void Czlowiek::kolizja(Organizm* atakujacy)
{
    if(!aktywna)
    {
        Zwierze::kolizja(atakujacy);
    } else
    {
        swiat->dodajDoLoga("Tarcza Alzura przeraza " + atakujacy->getSymbol() + "!");
        atakujacy->relokacja(X, Y);
    }
}

Czlowiek::~Czlowiek()
{
    //dtor
}
