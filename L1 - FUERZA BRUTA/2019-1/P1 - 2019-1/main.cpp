

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 5 de septiembre de 2024, 09:50 PM
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
int main(int argc, char** argv) {
    int m=6,w=25;
    int peso[N]={8,2,10,10,5,5};
    int ganancia[N]={15,20,5,10,8,5};
    
    int cromo[N],solucion, max=0, sumGana, sumaPeso;
    int combinaciones=pow(2,m);
    
    for(int i=0;i<combinaciones;i++){
        cargabin(i,cromo,m);
        sumGana=0;
        sumaPeso=0;
        for(int j=0;j<m;j++){
            if(cromo[j]==1){
                sumGana+=ganancia[j];
                sumaPeso+=peso[j];
            }
        }
        if(max<=sumGana and sumaPeso<=w){
            max=sumGana;
            solucion=i;
        }
    }
    cargabin(solucion,cromo,m);
    cout<<"Articulos: ";
        for(int j=0;j<m;j++){
            if(cromo[j]==1){
                cout<<j+1<<" ";
            }
        }
    cout<<endl;
    cout<<"Ganancia maxima: "<<max<<endl;

    return 0;
}

