

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 26 de agosto de 2024, 10:46 PM
 */

#include <iostream>
#include <iomanip>
#include <cmath>
#define M 16
using namespace std;

void cargabin(int i,int cromo[M],int n){
    for(int k=0;k<n;k++){
        cromo[k]=0;
    }
    int j=0,aux;
    while(i>0){
        aux=i%2;
        i=i/2;
        cromo[j]=aux;
        j++;
    }
}
int main(int argc, char** argv) {
    int almacen[M]={7,17,14,19,9,12,11,8,8,6,10,12,18,
    7,15,11};
    int precio[M]={10,10,10,5,15,10,10,10,
    10,20,10,5,10,10,5,10};
    int n=16,peso=23;
    int cromo[M],solucion,cant=0,suma, ganaMax=0,ganancia;
    int combinaciones=pow(2,n);
    
    for(int i=0;i<combinaciones;i++){
        cargabin(i,cromo,n);
        suma=0;
        ganancia=0;
        for(int j=0;j<n;j++){
            if(cromo[j]==1){
                suma+=almacen[j];
                ganancia+=precio[j];
            }
        }
        if((suma<=peso) and (ganancia>ganaMax)){
            solucion=i;
            ganaMax=ganancia;
        }
    }
    cout<<"Ganancia: "<<ganaMax<<" ";
    cargabin(solucion,cromo,n);
    cout<<" Resultado: ";
    for(int i=0;i<n;i++){
        if(cromo[i]==1){
            cout<<almacen[i]<<"k ";
        }
    }
    cout<<"Ubicaciones: ";
    for(int i=0;i<n;i++){
        if(cromo[i]==1){
            if(i/8==0){
                cout<<"I";
            }else{
                cout<<"D";
            }
            if((i/4)%2==0){
                cout<<"A";
            }else{
                cout<<"B";
            }
            cout<<(i%4)+1<<" ";
        }
    }
    return 0;
}

