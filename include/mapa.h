#ifndef MAPA_H
#define MAPA_H
#include "field.h"

class mapa
{
    public:
        mapa(int,int);
        int x;
        int y;
        field **f_tab;
        void load_map();
        void draw();
        void add_lift(int,int,int,int,int,int);
        void funkk();
        virtual ~mapa();
    protected:
    private:
};

#endif // MAPA_H
