#ifndef PLAYERELT_H
#define PLAYERELT_H

#include <eltmobil.h>
#include <iostream>

class EltPlayer : public EltMobil
{
    EltPlayer();
 public:
    static EltBase* __stdcall Create()
    {
        std::cout << "P";
        return new EltPlayer();
    }
};

#endif // PLAYERELT_H
