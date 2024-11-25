

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 23 de agosto de 2024, 07:29 AM
 */

#include <iostream>
#include <iomanip>
#include <cmath>
#define MAX 32
using namespace std;

void cargabin(int num,int cromo[MAX],int n){
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
    int m=13,d=7,p=13;
    int capacidad[4]={2,4,6,8};
    int rendimiento[4]={30,25,22,15};
    int costo[4]={1000,17000,27000,35000};
    int tipo[4]={7,3,2,1};
    
    int combinaciones=pow(2,13);
    int cromo[MAX];
    int final_cromo[MAX];
    int solucion, costoMax=99999;
    int sumaCap,sumCosto, acumular;
    int tip;
    for(int i=0;i<combinaciones;i++){
        cargabin(i,cromo,13);
        sumaCap=0;
        sumCosto=0;
        int idx=0;
        for(int j=0;j<4;j++){
            acumular=0;
            for(int k=0;k<tipo[j];k++){
                if(cromo[idx]==1){
                    sumaCap+=capacidad[j];
                    sumCosto+= costo[j]*(7.0/5)+p*(1*d)/rendimiento[j];
                }
                idx++;
            }  
        }
        if(sumaCap>=m and sumCosto<costoMax){
            solucion=i;
            costoMax=sumCosto;
        }
    }
    int idx=0;
    cargabin(solucion,cromo,13);
    for(int i=0;i<4;i++){
        int cant=0;
        for(int k=0;k<tipo[i];k++){
            if(cromo[idx]==1){
                cant++;
            }
            idx++;
        }
        if(cant>0){
           cout<<"Tipo: "<<i+1<<" cantidad: "<<cant<<endl; 
        }
        
    }
    

    return 0;
}

