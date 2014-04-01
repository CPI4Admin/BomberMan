#ifndef TEMPBRICKELT_H
#define TEMPBRICKELT_H

#include <eltbrick.h>
#include <iostream>

class EltTempBrick : public EltBrick
{
    EltTempBrick();
public:
    static EltBase* __stdcall Create()
    {
        std::cout << "D";
        return new EltTempBrick();
    }
};

#endif // TEMPBRICKELT_H
