#include<iostream>
#include<math.h>
#include "Part2.hpp"

using namespace std;

float f(float dt, float un, float unmoins1){
    return (un-unmoins1)/dt;
};

Filtre::Filtre(){
    cout<<"Entrez Vs : ";
    cin>>vs;
    cout<<endl;
}

void Filtre::synchronize_v0_vs(float t){
    ve = tension(t);
}

RC::RC(float R_param, float C_param){
    R = R_param;
    C = C_param;
}

RC::RC(){
    R=1000;
    C=0.000001;
}

float RC::calcul_vs(float tf){
    float dt = 0.00001;
    float vsp;

    FILE * fich;
    fich=fopen("vs","wt");   

    for (float t = 0; t<tf; t+=dt){
        //MàJ de ve
        synchronize_v0_vs(t);

        vsp = (ve-vs)/(R*C);
        vs += vsp *dt;

        fprintf(fich,"%f %f %f \n",t,ve,vs);

    }

    fclose(fich);
    return 0;
}


RD::RD(){
    R1=100;
    VBE=0.6;
    R2 = 300;
    C=0.0001;
}

RD::RD(float R1_param,float R2_param, float C_param){
    R1=R1_param;
    VBE = 0.6;
    R2 = R2_param;
    C = C_param;
}



float RD::calcul_vs(float tf){
    float dt = 0.00001;
    float vsp;

    FILE * fich;
    fich=fopen("vs","wt");   

    for (float t = 0; t<tf; t+=dt){
        //MàJ de ve
        synchronize_v0_vs(t);
        if (ve>VBE){
            vsp=-(1/(R1*C)+(1/(R2*C)))*vs+(ve-VBE)/((R1*C));
        } 
        else{
            vsp=-vs/(R2*C);
        }

        vs += vsp *dt;

        fprintf(fich,"%f %f %f \n",t,ve,vs);

    }

    fclose(fich);
    return 0;
}

int main(){
    RD circuit1;

    circuit1.calcul_vs(3);

    return 0;
}

