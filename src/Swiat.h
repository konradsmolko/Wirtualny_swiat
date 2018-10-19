#ifndef SWIAT_H
#define SWIAT_H
#include "Kontener.h"
#include <vector>

#define MAP_SIZE 20

using namespace std;

class Kontener;
class Organizm;

class Swiat
{
    public:
        Swiat();
        void wykonajTure();
        void rysujSwiat();
        void rysujSwiat(vector<Organizm*> & organizmy);
        virtual ~Swiat();
        void czyscMape();
        void dodajDoLoga(const string & dane);
        void czyscLog();
        void wpiszPole(int x, int y, string symbol);
        void dodaj(char co);
        void dodajLosowe(unsigned int ile);
        void czlowiek(char opcja);
        bool pelnaMapa();
    protected:
    private:
        vector<string>log;
        string mapa[MAP_SIZE][MAP_SIZE];
        Kontener* kontener;
		const unsigned char horiz = 205;
		const unsigned char verti = 186;
		const unsigned char pr_go = 187;
		const unsigned char pr_do = 188;
		const unsigned char lw_go = 201;
		const unsigned char lw_do = 200;
};

#endif // SWIAT_H
