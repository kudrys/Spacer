#ifndef LIFT_H
#define LIFT_H


class lift
{
    public:
        //lift();
        lift(int,int,int,int);
        int x_destination;
        int y_destination;
        int time_travel;
        int travel_period;
        lift* next;
        void add_lift();
        void delete_lift();
        virtual ~lift();
    protected:
    private:
};

#endif // LIFT_H
