#ifndef WILCZEJAGODY_H
#define WILCZEJAGODY_H

#include "Roslina.h"


class WilczeJagody : public Roslina
{
    public:
        WilczeJagody(Swiat* var, Kontener* varK, int parentX = -1, int parentY = -1);
        virtual ~WilczeJagody();
        void kolizja(Organizm* atakujacy);
    protected:
    private:
};

#endif // WILCZEJAGODY_H
