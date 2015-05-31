#ifndef LIFT_H
#define LIFT_H


class lift
{
    public:
        lift(int,int,int,int);
        int x_destination;
        int y_destination;
        int time_travel;
        int travel_period;
        virtual ~lift();
    protected:
    private:
};

#endif // LIFT_H
