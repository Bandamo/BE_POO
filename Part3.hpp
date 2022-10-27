#include "Part2.hpp"

class CircuitC : public Filtre{
    public:
        CircuitC();
        CircuitC(float R_param, float C_param, float L_param);
        float calcul_vs(float);
    protected:
        float R;
        float C;
        float L;
};



class CircuitD : public Filtre{
    public:
        CircuitD();
        CircuitD(float R_param, float C_param, float L_param);
        float calcul_vs(float);
    protected:
        float R;
        float C;
        float L;
};
