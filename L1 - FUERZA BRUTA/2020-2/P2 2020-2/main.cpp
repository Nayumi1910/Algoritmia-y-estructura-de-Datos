

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 22 de agosto de 2024, 02:11 PM
 */

#include <iostream>
#include <iomanip>
#include <cmath>
#define N 10
using namespace std;

void cargabin(int num,int cromo[N], int n){
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
    int n=8,p=250;
    int costo[N]={40,20,100,100,50,10,50,50};
    int ganancia[N]={150,80,300,150,80,50,120,150};
    int tipo[N]={1,1,2,2,2,3,3,3};
    
    int combinaciones=pow(2,n);
    int cromo[N],solucion[N],costoTotal[N],gananciaTotal[N];
    int sumaCosto,sumaGanancia, ganMax=0;
    int tp1,tp2,tp3,cant=0;
    
    for(int i=0;i<combinaciones;i++){
        cargabin(i,cromo,n);
        sumaCosto=0;
        sumaGanancia=0;
        tp1=0;
        tp2=0;
        tp3=0;
        for(int j=0;j<n;j++){
            if(cromo[j]==1){
                sumaGanancia+=ganancia[j];
                sumaCosto+=costo[j];
                if(tipo[j]==1) tp1++;
                else if (tipo[j]==2) tp2++;
                else tp3++;
                
            }
        }
        if((tp1>0 and tp2>0 and tp3>0) and 
                sumaGanancia>ganMax and sumaCosto<=p){
            ganMax=sumaGanancia;
            solucion[cant]=i;
            gananciaTotal[cant]=sumaGanancia;
            costoTotal[cant]=sumaCosto;
            cant++;
            
        }
    }

    for(int j=0;j<cant;j++){
        
        cargabin(solucion[j],cromo,n);
        cout<<"Maquinas: ";
        for(int k=0;k<n;k++){
            if(cromo[k]==1){
                cout<<k+1<<" "; 
            }
        }
        cout<<" Costo de maquinas: "<<costoTotal[j]
                <<" y una ganancia de "<<gananciaTotal[j]<<endl;
    }
    
    return 0;
}

