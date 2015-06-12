#ifndef MAPA_H
#define MAPA_H
#include "field.h"
#include "heap.h"

class mapa
{
    public:
        mapa(int,int);
        int x;
        int y;
        heap h;
        int travel_start_x;
        int travel_start_y;
        int travel_destination_x;
        int travel_destination_y;
        int lift_counter;
        field **f_tab;
        void load_map();
        void draw();
        void draw_times();
        void draw_times(int,int);
        int time_count(field*,field*);
        void flood();
        void add_lift();
        void compute_lifts(int, int);
        void compute_near(int, int);
        void compute_routes(int, int);
        void funkk();
        virtual ~mapa();
    protected:
    private:
};

#endif // MAPA_H
