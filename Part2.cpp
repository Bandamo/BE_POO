#include<iostream>
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

RD::RD(float R_param){
    R=R_param;
    VBE = 0.6;
}

int main(){

}