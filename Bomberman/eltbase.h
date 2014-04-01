#ifndef ELEMENTGRAPHIC_H
#define ELEMENTGRAPHIC_H

#include "eltbase.h"

class EltBase
{
private:
    int mLigne;
    int mColonne;
public:
    EltBase();
    void setLigne(int pLigne){mLigne = pLigne;}
    void setColonne(int pColonne){mColonne = pColonne;}
};

typedef EltBase* (__stdcall *CreateElementFn)(void);

#endif // ELEMENTGRAPHIC_H
