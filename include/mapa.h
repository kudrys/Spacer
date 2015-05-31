#ifndef MAPA_H
#define MAPA_H
#include "field.h"

class mapa
{
    public:
        mapa();
        int x;
        int y;
        void create_map();
        virtual ~mapa();
    protected:
    private:
};

#endif // MAPA_H
