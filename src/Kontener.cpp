#include "Kontener.h"

#include <algorithm>
#include <chrono>
#include <random>
#include <iostream>

#include "Czlowiek.h"       /// @
#include "Antylopa.h"       /// A
#include "Lis.h"            /// F
#include "Owca.h"           /// Q
#include "Wilk.h"           /// W
#include "Zolw.h"           /// Z
#include "Guarana.h"        /// g
#include "Mlecz.h"          /// m
#include "Trawa.h"          /// w
#include "WilczeJagody.h"   /// j

using namespace std;

Kontener::Kontener(Swiat* s)
{
    uniwersum = s;
    ileSkasowac = 0;

    losowa.seed(chrono::system_clock::now().time_since_epoch().count());
}

bool Kontener::dodaj(string co, int parentX, int parentY)
{
    if((parentX >= 0 && parentY >= 0 && parentX < MAP_SIZE &&
        parentY < MAP_SIZE && wolneDookola(parentX, parentY)) || // jezeli mamy sytuacje rozmnazania i jest miejsce wokol rodzica
       (parentX == -1 && parentY == -1 && wolneMiejsce())) // lub jezeli tworzymy calkowicie nowy organizm i jest miejsce na mapie
    {
        bool jest = false;
        switch(co[0])
        {
        case '@':
            for(unsigned int i = 0; i < organizmy.size(); i++)
                if(organizmy[i]->getSymbol() == "@")
                {
                    jest = true;
                    break;
                }
            if(!jest) organizmy.push_back(new Czlowiek(uniwersum, this, parentX, parentY));
            break;
        case 'A':
            organizmy.push_back(new Antylopa(uniwersum, this, parentX, parentY));
            break;
        case 'F':
            organizmy.push_back(new Lis(uniwersum, this, parentX, parentY));
            break;
        case 'Q':
            organizmy.push_back(new Owca(uniwersum, this, parentX, parentY));
            break;
        case 'W':
            organizmy.push_back(new Wilk(uniwersum, this, parentX, parentY));
            break;
        case 'Z':
            organizmy.push_back(new Zolw(uniwersum, this, parentX, parentY));
            break;
        case 'g':
            organizmy.push_back(new Guarana(uniwersum, this, parentX, parentY));
            break;
        case 'm':
            organizmy.push_back(new Mlecz(uniwersum, this, parentX, parentY));
            break;
        case 'w':
            organizmy.push_back(new Trawa(uniwersum, this, parentX, parentY));
            break;
        case 'j':
            organizmy.push_back(new WilczeJagody(uniwersum, this, parentX, parentY));
            break;
        default:
            break;
        }
        return true;
    } else return false;
}

void Kontener::dodajLosowe(unsigned int ile)
{
    if(ile == 0) ile = 1;
    for(unsigned int i = 0; i < ile; i++)
    {
        if(!wolneMiejsce()) break;

        switch(losowa()%9 + 1)
        {
        case 1:
            dodaj("A");
            break;
        case 2:
            dodaj("F");
            break;
        case 3:
            dodaj("Q");
            break;
        case 4:
            dodaj("W");
            break;
        case 5:
            dodaj("Z");
            break;
        case 6:
            dodaj("g");
            break;
        case 7:
            dodaj("m");
            break;
        case 8:
            dodaj("w");
            break;
        case 9:
            dodaj("j");
            break;
        }
    }
}

void Kontener::zabij(Organizm* cel)
{
    doKasacji[ileSkasowac] = cel;
    ileSkasowac++;
}

void Kontener::usunTrupy()
{
    for(int j = 0; j < ileSkasowac; j++)
    {
        for(unsigned int i = 0; i < organizmy.size(); i++)
        {
            if(organizmy[i] == doKasacji[j])
            {
                delete organizmy[i];
                organizmy.erase(organizmy.begin() + i);
                break;
            }
        }
    }
    ileSkasowac = 0;

}

bool Kontener::oznaczony(Organizm* test)
{
     return find(doKasacji, doKasacji+ileSkasowac, test) != doKasacji+ileSkasowac;
}

void Kontener::tura()
{
    sortuj();

    unsigned int rozmiar = organizmy.size(); // to po to, zeby nie brac pod uwage nowonarodzonych organizmow

    for(unsigned int i = 0; i < rozmiar; i++)
    {
        if(!oznaczony(organizmy[i]))
        {
            organizmy[i]->akcja(); // jesli dany organizm nie jest na lodzi Charona, wykonaj akcje
        }
    }

    usunTrupy();

    for(unsigned int i = 0; i < organizmy.size(); i++)
        organizmy[i]->postarz();

    uniwersum->rysujSwiat(organizmy);
}

void Kontener::sortuj()
{
    sort(organizmy.begin(), organizmy.end(), [](Organizm* v1, Organizm* v2)
    {
        if(v1->getInicjatywa() != v2->getInicjatywa())
        {
            return v1->getInicjatywa() > v2->getInicjatywa();
        } else
        {
            return v1->getWiek() > v2->getWiek();
        }
    });
}

Organizm* Kontener::wezPoLokacji(int x, int y)
{
    for(unsigned int i = 0; i < organizmy.size(); i++)
        if(organizmy[i]->getX() == x && organizmy[i]->getY() == y)
        {
            return organizmy[i];
        }
    return nullptr;
}

bool Kontener::wolneDookola(int x, int y)
{
    if((x > 0 && x < MAP_SIZE - 1)&& (y > 0 && y < MAP_SIZE - 1)) // srodkowa czesc mapy bez krawedzi i rogow
    {
        if( !zajete(x - 1, y - 1) || !zajete(x, y - 1) || !zajete(x + 1, y - 1) ||
            !zajete(x - 1, y    ) || /* org sprawdzaj. */ !zajete(x + 1, y    ) ||
            !zajete(x - 1, y + 1) || !zajete(x, y + 1) || !zajete(x + 1, y + 1)   )
        return true;
        else return false;
    } else if(x == 0)
    {
        if(y == 0)                  return (!zajete(x, y + 1) || !zajete(x + 1, y) || !zajete(x + 1, y + 1));   // LG naroznik
        else if(y == MAP_SIZE - 1)  return (!zajete(x, y - 1) || !zajete(x + 1, y) || !zajete(x + 1, y - 1));   // LD naroznik
        else                        return (!zajete(x, y - 1) || !zajete(x + 1, y - 1) || !zajete(x + 1, y) ||  // lewa krawedz
                                            !zajete(x, y + 1) || !zajete(x + 1, y + 1));
    } else if(x == MAP_SIZE - 1)
    {
        if(y == 0)                  return (!zajete(x - 1, y) || !zajete(x - 1, y + 1) || !zajete(x, y + 1));   // PG naroznik
        else if(y == MAP_SIZE - 1)  return (!zajete(x - 1, y - 1) || !zajete(x, y - 1) || !zajete(x - 1, y));   // PD naroznik
        else                        return (!zajete(x - 1, y - 1) || !zajete(x, y - 1) || !zajete(x - 1, y) ||  // prawa krawedz
                                            !zajete(x - 1, y + 1) || !zajete(x, y + 1));
    } else if(y == 0)               return (!zajete(x - 1, y) || !zajete(x + 1, y) || !zajete(x - 1, y + 1) ||  // gorna krawedz
                                            !zajete(x, y + 1) || !zajete(x + 1, y + 1));
    else                            return (!zajete(x - 1, y - 1) || !zajete(x, y - 1) || !zajete(x + 1, y - 1) || // dolna krawedz
                                            !zajete(x - 1, y) || !zajete(x + 1, y));

}

bool Kontener::wolneMiejsce()
{
    for(int y = 0; y < MAP_SIZE; y++)
        for(int x = 0; x < MAP_SIZE; x++)
            if(!zajete(x, y)) return true;

    return false;
}

void Kontener::czlowiek(char opcja)
{
    for(unsigned int i = 0; i < organizmy.size(); i++)
    {
        if(organizmy[i]->getSymbol() == "@")
        {
            ((Czlowiek*)organizmy[i])->ustawOpcje(opcja);
            break;
        }
    }
}

Kontener::~Kontener()
{
    for(unsigned int i = 0; i < organizmy.size(); i++)
        delete organizmy[i];
    organizmy.clear();
}
