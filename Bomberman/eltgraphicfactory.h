#ifndef ELTGRAPHICFACTORY_H
#define ELTGRAPHICFACTORY_H

#include <eltbase.h>
#include <map>

// Factory for creating instances of IAnimal
class EltFactory
{
private:
    EltFactory();
    EltFactory(const EltFactory &) { }
    EltFactory &operator=(const EltFactory &) { return *this; }

    typedef std::map<char, CreateElementFn> FactoryMap;
    typedef FactoryMap::value_type FactoryMapValue;
    FactoryMap m_FactoryMap;

public:
    virtual ~EltFactory() { m_FactoryMap.clear(); }

    static EltFactory *Get()
    {
        static EltFactory instance;
        return &instance;
    }

    void Register(char elt, CreateElementFn pfnCreate);
    EltBase *CreateElement(char elt);
};

#endif // ELTGRAPHICFACTORY_H
