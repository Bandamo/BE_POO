#include<iostream>
#include<math.h>
#include "Part2.h"

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


RC::RC(float R_param, float C_param){
    R = R_param;
    C = C_param;
}

RC::RC(){
    R=1000;
    C=pow(10,-6);
}

float RC::calcul_vs(float tf){
    vs=0;
    float dt = 0.001;
    float vsp = 0;

    FILE * fich;
    fich=fopen("vs.csv","wt");
    

    for (float t = 0; t<tf; t+=dt){
        //MàJ de ve

        vsp = (ve-vs)/(R*C);
        vs += vsp *dt;

        fprintf(fich,"%f %f \n",t,vs);

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
    RC circuit1;

    circuit1.calcul_vs(15);

    return 0;
}