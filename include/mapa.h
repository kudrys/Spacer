#ifndef MAPA_H
#define MAPA_H
#include "field.h"

class mapa
{
    public:
        mapa(int,int);
        int x;
        int y;
        field *f_tab;
        virtual ~mapa();
    protected:
    private:
};

#endif // MAPA_H
