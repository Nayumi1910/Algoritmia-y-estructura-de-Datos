

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 5 de septiembre de 2024, 08:48 PM
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
int verificar(int requisitos[N],int control[N],int n){
    int cumple=0;
    if(requisitos[0]==0){
        return 1;
    }
    else{
        for(int i=0;i<3;i++){
            if(requisitos[i]==0 or (requisitos[i]!=0 and control[requisitos[i]-1]!=0)){
                cumple=1;
            }
            cumple=0;
        }
        
    }
    return cumple;
    
     
}
int main(int argc, char** argv) {
    int p=100, n=8;
    int inversion[N]={32,8,40,40,20,4,16,16};
    int beneficio[N]={60,32,120,60,32,20,48,60};
    int requisitos[n][3]={{0,0,0},{0,0,0},
    {1,2,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}};
    
    int cromo[n],solucion[n],cant=0, max=0,sumBene,sumaInversion;
    int combinaciones=pow(2,n);
    int control[n]={0};
    for(int i=0;i<combinaciones;i++){
        cargabin(i,cromo,n);
        sumaInversion=0;
        sumBene=0;
        for(int j=0;j<n;j++){
            if(cromo[j]==1){
                if(verificar(requisitos[j],control,n)){
                    sumaInversion+=inversion[j];
                    sumBene+=beneficio[j];
                    control[j]=1;
                }
            }
        }
        if(max<sumBene and p==sumaInversion){
            max=sumBene;
            solucion[cant]=i;
            cant++;
        }
    }
    for(int i=0;i<cant;i++){
        cargabin(solucion[i],cromo,n);
        cout<<"Solucion "<<i+1<<": "<<endl;
        cout<<"Control "<<i+1<<": ";
        for(int j=0;j<n;j++){
            if(cromo[j]==1){
                cout<<j+1<<" ";
            }
        }
        cout<<endl;
    }
    cout<<"Beneficio Maximo: "<<max<<endl;
    
    return 0;
}

