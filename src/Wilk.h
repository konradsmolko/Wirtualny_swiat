#ifndef WILK_H
#define WILK_H

#include "Zwierze.h"


class Wilk : public Zwierze
{
    public:
        Wilk(Swiat* var, Kontener* varK, int parentX = -1, int parentY = -1);
        virtual ~Wilk();
    protected:
    private:
};

#endif // WILK_H
