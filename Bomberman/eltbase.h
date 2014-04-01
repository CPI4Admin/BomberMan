#ifndef ELEMENTGRAPHIC_H
#define ELEMENTGRAPHIC_H

#include <eltbase.h>

class EltBase
{
public:
    EltBase();
};

typedef EltBase* (__stdcall *CreateElementFn)(void);

#endif // ELEMENTGRAPHIC_H
