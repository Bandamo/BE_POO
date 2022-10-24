#ifndef PART1_H_INCLUDED
#define PART1_H_INCLUDED

#include <iostream>



class Source{
    public:
        Source();
        virtual float tension(float) = 0;
    protected:
        float V0;
        float phi;
};

class Periodic:public Source{
    public:
        Periodic();
    protected:
        float P;

};

class Creneau:public Periodic{
    public:
        Creneau();
        float tension(float);
    protected:
        float T;
};

class Triangulaire:public Periodic{
    public:
        float tension(float);
};

class Sinusoidal:public Periodic{
    public:
        float tension(float);
};

class Echelon:public Source{
    public:
        float tension(float);
};

class Rectangle:public Source{
    public:
        Rectangle();
        float tension(float);
    protected:
        float T;
};
#endif