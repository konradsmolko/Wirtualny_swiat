#ifndef KONTENER_H
#define KONTENER_H
#include <vector>
#include <chrono>
#include <random>
#include <string>
#include "Organizm.h"
#include "Swiat.h"

#define MAP_SIZE 20

using namespace std;

class Swiat;
class Organizm;

class Kontener
{
    public:
        Kontener(Swiat* s);

        bool dodaj(string co, int parentX = -1, int parentY = -1);
        void dodajLosowe(unsigned int ile = 1);
        void zabij(Organizm* cel);
        bool oznaczony(Organizm* test);
        void tura();

        Organizm* wezPoLokacji(int x, int y);
        vector<Organizm*> & getOrganizmy() { return organizmy; }

        bool zajete(int x, int y) { return wezPoLokacji(x, y) != nullptr; }
        bool wolneDookola(int x, int y);
        bool wolneMiejsce();
        int ileZwierzakow() { return organizmy.size(); }

        void czlowiek(char opcja);
        mt19937 losowa;
        virtual ~Kontener();
    protected:
    private:
        void usunTrupy();
        void sortuj();
        vector<Organizm*>organizmy;
        Swiat* uniwersum;
        int ileSkasowac;
        Organizm* doKasacji[MAP_SIZE*MAP_SIZE];
};

#endif // KONTENER_H
