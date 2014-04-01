#ifndef BOMBELT_H
#define BOMBELT_H

#include <eltmobil.h>
#include <iostream>

class EltBomb : public EltMobil
{
    EltBomb();
public:
    static EltBase* __stdcall Create()
    {
        std::cout << "T";
        return new EltBomb();
    }
};

#endif // BOMBELT_H
