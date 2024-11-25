

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 6 de septiembre de 2024, 08:57 AM
 */

#include <iostream>
#include <iomanip>
#include <cmath>
#define N 12
#define M 24
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
    int prioridad[N]={4,2,3,1,3,1,4,2,3,2,1,4};
    int hora[N]={8,10,12,13,15,10,16,8,14,18,18,14};
    int tiempo[N]={2,2,2,2,1,2,1,2,1,2,2,2};
    int n=24;
    int cromo[N],horario[M],solucion;
    int combinaciones=pow(2,N),cumple;
    int p1,p2,p3,p4;
    for(int i=0;i<combinaciones;i++){
        cargabin(i,cromo,N);
        p1=0;
        p2=0;
        p3=0;
        p4=0;
        for(int k=0;k<n;k++){
            horario[k]=0;
        }
        cumple=0;
        for(int j=0;j<N;j++){
            if(cromo[j]==1){
                if(prioridad[j]==1)p1++;
                else if(prioridad[j]==2)p2++;
                else if(prioridad[j]==3)p3++;
                else if(prioridad[j]==4)p4++;
                for(int l=hora[j];l<hora[j]+tiempo[j];l++){
                    if(horario[l]==0){
                        horario[l]=1;
                    }else{
                        cumple=1;
                        break;
                    }
                }
            }
        }
        if(p1==2 and p2==2 and p3==1 and p4==1 and cumple==0){
            solucion=i;
            break;
        }
    }
    cargabin(solucion,cromo,N);
    cout<<"Solucion: "<<endl;
    for(int j=0;j<N;j++){
        if(cromo[j]==1){
            cout<<j+100<<" "<<prioridad[j]<<endl;
        }
    }

    return 0;
}

