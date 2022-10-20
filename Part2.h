#include<iostream>
#include"Part1.h"

class Filtre{
    public:
        Filtre();
        virtual float calcul_vs(float) = 0;
    protected:
        float ve;
        float vs;
};

class RC : public Filtre{
    public:
        RC(float,float);
        float calcul_vs(float);
    protected:
        float R;
        float C;
};

class RD : public Filtre{
    public:
        RD(float);
        float calcul_vs(float);
    protected:
        float R;
        float VBE;
};