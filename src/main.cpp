#include <iostream>
#include <conio.h>
#include "include\Swiat.h"
#include "include/Wyjatek.h"

#define MAP_SIZE 20

#define UPARROW 0x48
#define DOWNARROW 0x50
#define LEFTARROW 0x4b
#define RIGHTARROW 0x4d

using namespace std;

int main()
{
    char option = ' ';
    Swiat world = Swiat();
    int ile;

    world.rysujSwiat();

    while(option != 'q')
    {
        switch(option)
        {
        case 'n':
            try
            {
                if(world.pelnaMapa()) throw Wyjatek("Nie mozna juz dodac organizmow!");
                cin >> ile;
                world.dodajLosowe(ile);
                world.rysujSwiat();
            }
            catch(Wyjatek & w)
            {
                cout << "Zlapany wyjatek: " << w.text << "\n";
            }
            break;
        case UPARROW:
        case DOWNARROW:
        case LEFTARROW:
        case RIGHTARROW:
        case 'r':
            world.czlowiek(option);
            world.wykonajTure();
            break;
        case '@':
        case 'Q':
        case 'W':
        case 'A':
        case 'F':
        case 'Z':
        case 'g':
        case 'w':
        case 'j':
        case 'm':
            try
            {
                if(world.pelnaMapa()) throw Wyjatek("Nie mozna juz dodac organizmow!");
                world.dodaj(option);
                world.rysujSwiat();
            }
            catch(Wyjatek & w)
            {
                cout << "Zlapany wyjatek: " << w.text << "\n";
            }
            break;
        case '.':
            world.wykonajTure();
            break;
        default:
            break;
        }
        option = getch();
    }
    return 0;
}
