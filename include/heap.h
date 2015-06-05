#ifndef HEAP_H
#define HEAP_H
#include "mapa.h"

class heap
{
    public:
        heap(*mapa );
        int * tab;
        int tabsize;
        int heap_size;
        int width;
        mapa * m;
        int get_time(int);
        void add(int, int);
        void sort();
        void remove_first();
    protected:
    private:
};

#endif // HEAP_H
