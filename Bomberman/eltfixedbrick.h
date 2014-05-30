#ifndef FIXEDBRICKELT_H
#define FIXEDBRICKELT_H

#include "eltbrick.h"
#include <iostream>

class EltFixedBrick: public EltBrick
{
   EltFixedBrick();
public:
   static EltBase* __stdcall Create()
   {
       std::cout << "I";
       return new EltFixedBrick();
   }
};

#endif // FIXEDBRICKELT_H
