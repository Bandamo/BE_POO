#include<iostream>
#include<math.h>
#include "Part2.hpp"

using namespace std;

float f(float dt, float un, float unmoins1){
    return (un-unmoins1)/dt;
};

Filtre::Filtre(){
    cout<<"Entrez Ve : ";
    cin>>ve;
    cout<<endl;
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
    fich=fopen("vs.csv","wt");
    fprintf(fich,"t,vs\n");    

    for (float t = 0; t<tf; t+=dt){
        //MàJ de ve
        synchronize_v0_vs(t);

        vsp = (ve-vs)/(R*C);
        vs += vsp *dt;

        fprintf(fich,"%f,%f \n",t,vs);

    }

    fclose(fich);
    return 0;
}


RD::RD(){
    R=100;
    VBE=0.6;
}

RD::RD(float R_param){
    R=R_param;
    VBE = 0.6;
}

float RD::calcul_vs(float t){
    return 0;
}

int main(){
    RC circuit1(300,0.001);

    circuit1.calcul_vs(0.01);

    return 0;
}