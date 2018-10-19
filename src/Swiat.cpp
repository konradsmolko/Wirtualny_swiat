#include "Swiat.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Swiat::Swiat()
{
    czyscMape();

    kontener = new Kontener(this);
    //kontener->dodajLosowe(5); /// tu zmieniac stan poczatkowy gry!
}

void Swiat::wykonajTure()
{
    kontener->tura();
}

void Swiat::rysujSwiat()
{
    rysujSwiat(kontener->getOrganizmy());
}

void Swiat::rysujSwiat(std::vector<Organizm*> & organizmy)
{
    czyscMape();
    system("cls");
    for(unsigned int i = 0; i < organizmy.size(); i++)
    {
        wpiszPole(organizmy[i]->getX(), organizmy[i]->getY(), organizmy[i]->getSymbol());
    }

    if(log.size() < MAP_SIZE)
        for(int i = log.size(); i < MAP_SIZE; i++)
            log.push_back("");

    // Czesc gorna obrysu mapy
    cout << lw_go;
    for(int i = 0; i < MAP_SIZE; i++)
        cout << horiz;
    cout << pr_go << " Log:\n";

    // Wypisanie mapy z krawedziami po bokach i logiem
    for(int y = 0; y < MAP_SIZE; y++)
    {
        cout << verti;
        for(int x = 0; x < MAP_SIZE; x++)
        {
            cout << mapa[y][x];
        }
        cout << verti << " " << log[y] << "\n";
    }

    // Czesc dolna obrysu mapy
    cout << lw_do;
    for (int i = 0; i < MAP_SIZE; i++)
        cout << horiz;
    cout << pr_do << "\n";

    czyscLog();
}

void Swiat::czyscMape()
{
    for(int y = 0; y < MAP_SIZE; y++)
        for(int x = 0; x < MAP_SIZE; x++)
            mapa[y][x] = '.';
}

void Swiat::dodajDoLoga(const string & dane)
{
    if(log.size() < 20)
        log.push_back(dane);
}

void Swiat::czyscLog()
{
    log.erase(log.begin(), log.end());
}

void Swiat::wpiszPole(int x, int y, string symbol)
{
    mapa[y][x] = symbol;
}

void Swiat::dodaj(char co)
{
    kontener->dodaj(&co);
}

void Swiat::dodajLosowe(unsigned int ile)
{
    kontener->dodajLosowe(ile);
}

void Swiat::czlowiek(char opcja)
{
    kontener->czlowiek(opcja);
}

bool Swiat::pelnaMapa()
{
    return !kontener->wolneMiejsce();
}

Swiat::~Swiat()
{
    delete kontener;
}
