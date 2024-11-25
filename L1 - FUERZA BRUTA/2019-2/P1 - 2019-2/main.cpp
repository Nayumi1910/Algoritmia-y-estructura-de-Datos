

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 6 de septiembre de 2024, 08:34 AM
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
int verificar(int predecesores[3],int control[N],int n){
    if(predecesores[0]==0){
        return 1;
    }
    for(int i=0;i<n;i++){
        if(predecesores[i]==0 or (predecesores[i]!=0 and 
                control[predecesores[i]]==1)){
            return 1;
        }
        return 0;
    }
}
int main(int argc, char** argv) {
    int costo[N]={80,20,100,100,50,10,50,50};
    int ganancia[N]={150,80,300,150,80,50,120,150};
    int predecesores[N][3]={{0,0,0},{0,0,0,},
                            {1,2,0},{0,0,0},
                            {0,0,0},{2,0,0},
                            {6,0,0},{6,0,0}};
    int n=8,p=250;
    
    int combinaciones=pow(2,n);
    int cromo[N],solucion,max=0,sumaGana,sumaCosto;
    int control[N]={0};
    for(int i=0;i<combinaciones;i++){
        cargabin(i,cromo,n);
        sumaCosto=0;
        sumaGana=0;
        for(int j=0;j<n;j++){
            if(cromo[j]==1){
                if(verificar(predecesores[j],control,n)){
                    sumaCosto+=costo[j];
                    sumaGana+=ganancia[j];
                    control[j]=1;
                }
            }
        }
        if(max<sumaGana and sumaCosto<=p){
            solucion=i;
            max=sumaGana;
        }
    }
    cargabin(solucion,cromo,n);  
    for(int j=0;j<n;j++){
        if(cromo[j]==1){
            cout<<j+1<<" ";
        }
    }
    cout<<endl;
    cout<<"Ganancia Maxima: "<<max;

    return 0;
}

