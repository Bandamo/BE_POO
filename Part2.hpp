#ifndef PART2_H_INCLUDED
#define PART2_H_INCLUDED


#include<iostream>
#include "Part1.hpp"

using namespace std;

class Filtre : public Sinusoidal{
    public:
        Filtre();
        virtual float calcul_vs(float) = 0;
        void synchronize_v0_vs(float t);
    protected:
        float ve;
        float vs;
};

class RC : public Filtre{
    public:
        RC();
        RC(float R_param, float C_param);
        float calcul_vs(float);
    protected:
        float R;
        float C;
};

class RD : public Filtre{
    public:
        RD();
        RD(float R_param);
        float calcul_vs(float);
    protected:
        float R;
        float VBE;
};

#endif