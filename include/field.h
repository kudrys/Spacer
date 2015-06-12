#ifndef FIELD_H
#define FIELD_H
#include "../include/lift.h"

class field
{
    public:
        field();
        int height;
        int travel_time;
        int lift_counter;
        bool marked;
        int compute_from(field*);
        void add_lift();
        lift *l;

        virtual ~field();
    protected:
    private:
};

#endif // FIELD_H
