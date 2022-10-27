#ifndef PART2_H_INCLUDED
#define PART2_H_INCLUDED


#include<iostream>
#include "Part1.cpp"

using namespace std;

class Filtre{
    public:
        Filtre();
        virtual float calcul_vs(float) = 0;
        float synchronize_v0_ve(float t);
    protected:
        Source* source_pointeur;
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
        RD(float R1_param,float R2_param,float C_param);
        float calcul_vs(float);
    protected:
        float R1;
        float VBE;
        float R2;
        float C;
};

#endif