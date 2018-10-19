#ifndef LIS_H
#define LIS_H

#include "Zwierze.h"


class Lis : public Zwierze
{
    public:
        Lis(Swiat* var, Kontener* varK, int parentX = -1, int parentY = -1);
        ~Lis();
        void akcja();
    protected:
    private:
};

#endif // LIS_H
