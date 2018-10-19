#ifndef ORGANIZM_H
#define ORGANIZM_H
#include "Swiat.h"
#include "Kontener.h"

using namespace std;

class Swiat;
class Kontener;

class Organizm
{
    public:
        Organizm();
        virtual void akcja() {}
        virtual void kolizja(Organizm* przeciwnik) {}
        void relokacja(int sourceX = -1, int sourceY = -1);

        string getSymbol() { return symbol; }

        int getSila() { return sila; }
        void setSila(int val) { sila = val; }

        int getInicjatywa() { return inicjatywa; }

        int getX() { return X; }
        void setX(int val) { X = val; }

        int getY() { return Y; }
        void setY(int val) { Y = val; }

        int getWiek() { return wiek; }
        void postarz() { wiek++; }

        virtual ~Organizm();
    protected:
        string symbol;
        int sila;
        int inicjatywa;
        int X;
        int Y;
        int wiek;
        Swiat* swiat;
        Kontener* kontener;
    private:
};

#endif // ORGANIZM_H
