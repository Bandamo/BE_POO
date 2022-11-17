#include<iostream>
#include<math.h>
#include "Part3.hpp"

using namespace std;

float f(float dt, float un, float unmoins1){
    return (un-unmoins1)/dt;
};

Filtre::Filtre(){
    int type_source;
    cout<<"Entrez Vs : ";
    cin>>vs;
    cout<<endl<<"Entrez type source :\n 1- Creneaux\n 2- Triangulaire\n 3- Sinusoidale\n 4- Echelon\n 5- Rectangle"<<endl;
    cin>>type_source;
    switch (type_source)
    {
    case 1:
        source_pointeur = new Creneau;
        break;
    case 2:
        source_pointeur = new Triangulaire;
        break;
    case 3:
        source_pointeur = new Sinusoidal;
        break;
    case 4:
        source_pointeur = new Echelon;
        break;
    case 5:
        source_pointeur = new Rectangle;
        break;

    default:
        source_pointeur = new Echelon;
        break;
    }
    cout<<endl;
}

float Filtre::synchronize_v0_ve(float t){
    ve = (source_pointeur)->tension(t);
    return ve;
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
        synchronize_v0_ve(t);

        vsp = (ve-vs)/(R*C);
        vs += vsp *dt;

        fprintf(fich,"%f %f %f \n",t,ve,vs);

    }

    fclose(fich);
    return vs;
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
        synchronize_v0_ve(t);
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
    return vs;
}

CircuitC::CircuitC(){
    R=100;
    C=0.001;
    L=0.001;
}

CircuitC::CircuitC(float R_param, float C_param, float L_param){
    R=R_param;
    C=C_param;
    L=L_param;
}



float CircuitC::calcul_vs(float tf){
    float dt = 0.00001;
    float vsp=0;
    float vspp;
    vs=0;

    FILE * fich;
    fich=fopen("vs","wt");   

    for (float t = 0; t<tf; t+=dt){
        //MàJ de ve
        synchronize_v0_ve(t);
        vspp=-R/L*vsp+(ve-vs)/L/C;
        

        vsp += vspp *dt;
        vs += vsp*dt;

        fprintf(fich,"%f %f %f \n",t,ve,vs);
    }
    fclose(fich);
    return vs;
}

CircuitD::CircuitD(){
    R=10000;
    C=0.000008;
    L=791.57;
}

CircuitD::CircuitD(float R_param, float C_param, float L_param){
    R=R_param;
    C=C_param;
    L=L_param;
}

float CircuitD::calcul_vs(float tf){
    float dt = 0.0000001;
    float vsp=0;
    float vspp;
    float vep;
    vs=0;

    FILE * fich;
    fich=fopen("vs","wt");   

    for (float t = 0; t<tf; t+=dt){
        //MàJ de ve
        vep=(synchronize_v0_ve(t+dt)-synchronize_v0_ve(t))/dt;

        /*
        cout<<synchronize_v0_ve(t+dt)<<endl;
        cout<<synchronize_v0_ve(t)<<endl;
        cout << endl;
        */

        vspp=(vep-vsp)/R/C-vs/L/C;

        vsp += vspp *dt;
        vs += vsp*dt;

        fprintf(fich,"%f %f %f %f %f\n",t,ve,vs, vep, vsp);
    }
    fclose(fich);
    return vs;
}

int main(){
    CircuitD d;
    d.calcul_vs(0.5);
    
    return 0;
}

