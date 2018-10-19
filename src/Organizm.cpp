#include "Organizm.h"
#include <chrono>
#include <random>
#include <iostream>
#define MAP_SIZE 20

Organizm::Organizm()
{
    //ctor
}

void Organizm::relokacja(int sourceX, int sourceY)
{
    int targetX, targetY;
    if((sourceX < 0 || sourceY < 0) && kontener->wolneMiejsce())
    {  // czyli wywolanie przez ctor nowego losowego zwierzaka (nie rozmnozonego)
        do
        {
            targetX = kontener->losowa()%MAP_SIZE; // 0-19
            targetY = kontener->losowa()%MAP_SIZE;
        } while(kontener->zajete(targetX, targetY));
        X = targetX;
        Y = targetY;
    } else
    if(kontener->wolneDookola(sourceX, sourceY))
    {
        do
        {
            targetX = sourceX + (kontener->losowa()%3 - 1); // -1, 0, 1
            targetY = sourceY + (kontener->losowa()%3 - 1);
        } while(targetX >= MAP_SIZE || targetY >= MAP_SIZE || targetX < 0 || targetY < 0 ||
                kontener->zajete(targetX, targetY));
        X = targetX;
        Y = targetY;
    }
}

Organizm::~Organizm()
{
    //dtor
}
