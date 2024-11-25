

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 20 de agosto de 2024, 09:00 PM
 */

#include <iostream>
#include <iomanip>
#include <cmath>
#define MAX 20
using namespace std;

void cargabin(int cromo[MAX],int n,int num){
    for(int i=0;i<n;i++){
        cromo[i]=0;
    }
    int i=0;
    int aux;
    while(num>0){
        aux=num%2;
        num=num/2;
        cromo[i]=aux;
        i++;
    }
}
int main(int argc, char** argv) {
    
    int rol[MAX]={2,1,3,1,3,2,3};
    int velocidad[MAX]={8,6,13,5,10,9,14};
    int beneficio[MAX]={4,6,2,7,2,3,0};
    int salario[MAX]={16,19,22};
    
    int t=7,mpxh=23;
    
    //primero veo cual es el gasto maximo que se podria pagar
    int pagoMax=0;
    for(int i=0;i<t;i++){
        pagoMax+=salario[rol[i]-1]+velocidad[i]*beneficio[i];
        
    }
    cout<<pagoMax<<endl;
    int pago,meta,metaIni=0;
    int combinaciones=pow(2,t);
    int solucion,cromo[MAX];
    
    for(int i=0;i<combinaciones;i++){
        cargabin(cromo,t,i);
        pago=0;
        meta=0;
        for(int k=0;k<t;k++){
            if(cromo[k]==1){
                meta+=velocidad[k];
                pago+=salario[rol[k]-1]+velocidad[k]*beneficio[k];
            }
        }
        if(meta>=mpxh){
            if((pago<pagoMax) or (pago==pagoMax and meta>metaIni) ){
                solucion=i;
                pagoMax=pago;
                metaIni=meta;
                cout<<pagoMax<<" ";
            }
            
        }
    }
    cargabin(cromo,t,solucion); 
    cout<<"Solucion: "<<endl;
    cout<<"Trabajadores seleccionados: ";
    for(int k=0;k<t;k++){
        if(cromo[k]==1){
            cout<<k+1<<" ";
        }
    }
    cout<<" "<<"Costo minimo: "<<pagoMax<<endl;
    

    return 0;
}

