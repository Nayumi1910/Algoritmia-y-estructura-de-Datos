

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 20 de agosto de 2024, 10:34 PM
 */

#include <iostream>
#include <iomanip>
#include <cmath>
#define N 12
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
/*
 * 
 */
int main(int argc, char** argv) {
    int m=4,n=7,p=20;
    int rotura[N]={1,5,1,10,5,6,2};
    int salario[N]={10,5,5,3,2,1,8};
    
    int combinaciones=pow(2,n);
    int cromo[N];
    int solucion[N],sumaRotura,sumaSalario,roturaMax=9999,roturaT[N];
    int cant, salarioT[N],cantidad[N],cantN=0;
    for(int i=0;i<combinaciones;i++){
        cargabin(i,cromo,n);
        sumaRotura=0;
        sumaSalario=0;
        cant=0;
        for(int j=0;j<n;j++){
            if(cromo[j]==1){
                sumaRotura+=rotura[j];
                sumaSalario+=salario[j];
                cant++;
            }
        }
        if(cant>=m and cant<=n and sumaSalario<=p and
                sumaRotura<roturaMax){
            solucion[cantN]=i;
            roturaT[cantN]=sumaRotura;
            roturaMax=sumaRotura;
            salarioT[cantN]=sumaSalario;
            cantidad[cantN]=cant;
            cantN++;
        }
    }
    for(int j=0;j<cantN;j++){
        cargabin(solucion[j],cromo,n);
        cout<<"Obreros: ";
        for(int i=0;i<n;i++){
            if(cromo[i]==1){
                cout<<i+1<<" ";
            }
        }
        cout<<" Costo de salario: "<< salarioT[j] <<" y rotura promedio "<<(double)roturaT[j]/cantidad[j]<<endl; 
    }
    

    return 0;
}

