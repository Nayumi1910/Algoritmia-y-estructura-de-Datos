

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 27 de agosto de 2024, 02:35 PM
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
    int m=4,p=19;
    int precio[N]={4,5,4,2,6,3,4,1};
    int cantidadH[N]={3,2,1,1,3,3,2,4};
    int n=8;
    int combinaciones=pow(2,8);
    int cromo[N],soluciones[N],cant=0;
    int sumaPrecio,monto[N],cantHer[N], tipo;
    int cantidad;
    for(int i=0;i<combinaciones;i++){
        cargabin(i,cromo,n);
        sumaPrecio=0;
        cantidad=0;
        tipo=0;
        for(int j=0;j<n;j++){
            if(cromo[j]==1){
                sumaPrecio+=precio[j];
                cantidad+=cantidadH[j];
                tipo++;
            }
        }
        if(sumaPrecio==p and m==tipo){
            monto[cant]=sumaPrecio;
            soluciones[cant]=i;
            cantHer[cant]=cantidad;
            cant++;
        }
    }
    for(int i=0;i<cant;i++){
        cargabin(soluciones[i],cromo,n);
        cout<<"Solucion "<<i+1<<": ";
        for(int j=0;j<n;j++){
            if(cromo[j]==1){
                cout<<j+1<<" ";
            }
        }
        cout<<"Monto total: "<<monto[i]
                <<" Cantidad de herramientas: "<<cantHer[i]<<endl;
    }
    return 0;
}

