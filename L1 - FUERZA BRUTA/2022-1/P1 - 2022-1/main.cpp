

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 26 de agosto de 2024, 11:24 PM
 */

#include <iostream>
#include <iomanip>
#include <cmath>
#define N 10
using namespace std;

void cargabin(int num,int cromo[N],int n){
    for(int i=0;i<n;i++){
        cromo[i]=0;
    }
    int i=0,aux;
    while(num>0){
        aux=num%2;
        num=num/2;
        cromo[i]=aux;
        i++;
    }
}
int main(int argc, char** argv) {
    int p=50,n=9;
    int publicidad[N]={30,14,18,9,15,10,21,15,20};
    double roas[N]={1.2,2.8,1.4,2.5,1.3,2,1.2,2.5,1.1};
    int marca[N]={2000,3000,1200,400,700,800,1300,1000,200};
    
    int cromo[N],solucion, sumaMarca,sumaPubli;
    int combinaciones=pow(2,n);
    double ingresos;
    int recordacion=0,ingresoT=0,publicidadT=0;
    for(int i=0;i<combinaciones;i++){
        cargabin(i,cromo,n);
        ingresos=0;
        sumaMarca=0;
        sumaPubli=0;
        for(int j=0;j<n;j++){
            if(cromo[j]==1){
                ingresos+=roas[j]*publicidad[j];
                sumaPubli+=publicidad[j];
                sumaMarca+=marca[j];
            }
        }
        if(sumaPubli<=p and ingresoT<ingresos and sumaMarca>recordacion){
            solucion=i;
            publicidadT=sumaPubli;
            ingresoT=ingresos;
            recordacion=sumaMarca;
        }
    }
    cout<<"El nivel maximo de recordacion es de "<<recordacion
            <<" con una inversion total en publicidad de "<<publicidadT*1000
            <<" y un ingreso de "<<ingresoT*1000<<" dolares"<<endl;
    cargabin(solucion,cromo,n);
    for(int i=0;i<n;i++){
        if(cromo[i]==1){
            cout<<"Canal - "<<i+1<<endl;
        }
    }
    return 0;
}

