#ifndef MAPA_H
#define MAPA_H
#include "field.h"

class mapa
{
    public:
        mapa(int,int);
        int x;
        int y;
        int travel_start_x;
        int travel_start_y;
        int travel_destination_x;
        int travel_destination_y;
        int lift_counter;
        field **f_tab;
        void load_map();
        void draw();
        int time_count(field,field);
        void flood();
        void add_lift(int,int,int,int,int,int);
        void funkk();
        virtual ~mapa();
    protected:
    private:
};

#endif // MAPA_H
