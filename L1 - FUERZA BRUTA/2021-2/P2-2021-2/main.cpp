

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 26 de agosto de 2024, 11:05 PM
 */

#include <iostream>
#include <iomanip>
#include <cmath>
#define N 16
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
    int t=100,p=4,n=6;
    int acciones[N]={30,38,28,35,32,34};
    double comision[N]={0.1,0.02,0.15,0.05,0.08,0.03};
    
    int cromo[N],solucion,ganaMax=0,suma,sumaT,ganancia;
    int combinanciones=pow(2,n);
    
    for(int i=0;i<combinanciones;i++){
        cargabin(i,cromo,n);
        ganancia=0;
        suma=0;
        for(int j=0;j<n;j++){
            if(cromo[j]==1){
                ganancia+=(acciones[j]*p)*comision[j];
                suma+=acciones[j];
            }
        }
        if(ganancia>ganaMax and suma<=t){
            solucion=i;
            ganaMax=ganancia;
            sumaT=suma;
        }
    }
    cout<<"Para este conjunto de datos, una solucion con"
            "la maxima ganancia debido a las comisiones"
            "seria de "<<ganaMax*100<<" dolares por un total "
            "de "<<sumaT*100<<" acciones"<<endl;
    cargabin(solucion,cromo,n);
    for(int i=0;i<n;i++){
        if(cromo[i]==1){
            cout<<"El cliente "<<i+1<<" otorga una"
                    "ganancia de "<<(acciones[i]*p)*comision[i]*100<<
                    " dolares por comprar "<<acciones[i]*100<<endl;
        }
    }
    return 0;
}

