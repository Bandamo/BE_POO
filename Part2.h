#include<iostream>

using namespace std;

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