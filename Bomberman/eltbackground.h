#ifndef BACKELT_H
#define BACKELT_H

#include <eltdecor.h>
#include <iostream>

class EltBackground : public EltDecor
{
    EltBackground();
public:
    static EltBase* __stdcall Create()
    {
        std::cout << "B";
        return new EltBackground();
    }
};

#endif // BACKELT_H
