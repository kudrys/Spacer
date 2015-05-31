#ifndef FIELD_H
#define FIELD_H
#include "lift.h"

class field
{
    public:
        field();
        int height;
        int travel_time;
        int lift_counter;
        lift *l;

        virtual ~field();
    protected:
    private:
};

#endif // FIELD_H
