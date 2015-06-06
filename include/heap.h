#ifndef HEAP_H
#define HEAP_H
#include "field.h"

class heap
{
    public:
        //heap(*mapa);
        heap();
        int * tab;
        int tabsize;
        int heap_size;
        int width;
        field ** map_tab;
        int get_time(int);
        void add(int, int);
        void sort();
        int remove_first();
        void draw();
        int getx(int);
        int gety(int);
    protected:
    private:
};


#endif // HEAP_H
