

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 23 de agosto de 2024, 08:52 AM
 */

#include <iostream>
#include <iomanip>
#include <cmath>
#define N 15
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
    int n=4,m=5,c=20;
    int bahia1[n]={2,5,6,10};
    int bahia2[n]={7,8,15,3};
    int bahia3[n]={11,9,6,4};
    int cant;
    int suma;
    int combinaciones=pow(2,n);
    int cromo1[N],cromo2[N],cromo3[N];
    int solucion1,solucion2,solucion3;
    for(int i=0;i<combinaciones;i++)
        for(int j=0;j<combinaciones;j++)
            for(int l=0;l<combinaciones;l++){
                cargabin(i,cromo1,n);
                cargabin(j,cromo2,n);
                cargabin(l,cromo3,n);
                cant=0;suma=0;
                for(int k=0;k<n;k++){
                    if(cromo1[k]==1){
                        suma+=bahia1[k];
                        cant++;
                    }
                }
                for(int k=0;k<n;k++){
                    if (cromo2[k] == 1) {
                        suma+=bahia2[k];
                        cant++;
                    }
                }
                for(int k=0;k<n;k++){
                    if (cromo3[k] == 1) {
                        suma+=bahia3[k];
                        cant++;
                    }
                }
                if(cant==m and suma==c){
                    solucion1=i;
                    solucion2=j;
                    solucion3=l;
                }
            }
    
    cargabin(solucion1,cromo1,n);
    cout<<"Bahia 1: ";
    for(int k=0;k<n;k++){
            if(cromo1[k]==1){
                cout<<bahia1[k]<<" ";
            }
    }
    cargabin(solucion2,cromo2,n);
    cout<<"Bahia 2: ";
    for(int k=0;k<n;k++){
            if (cromo2[k] == 1) {
                cout<<bahia2[k]<<" ";
            }
    }
    cargabin(solucion3,cromo3,n);
    cout<<"Bahia 3: ";
    for(int k=0;k<n;k++){
            if (cromo3[k] == 1) {
                cout<<bahia3[k]<<" ";
            }
    }
    
    

    return 0;
}

