

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 5 de septiembre de 2024, 01:03 PM
 */

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void cargabin(int num,int cromo[],int n){
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
    int p=100,n=4;
    int num=n*n;
//    int pesos[N][N]={{20,20,20,20},
//                     {10,30,10,30},
//                     {10,10,10,10},
//                     {15,15,15,15}};
//    int valores[N][N]={{10,10,10,50},
//                     {80,10,10,20},
//                     {20,20,20,20},
//                     {50,50,50,50}};
    int cromo[num];
    int solucion,suma, valor, max=0;
    int combinaciones=pow(2,num);
    int pesos[num]={20,20,20,20,10,30,10,30,10,10,10,10,
    15,15,15,15};
    int valores[num]={10,10,10,50,80,10,10,20,20,20,20,20,
    50,50,50,50};
    for(int i=0;i<combinaciones;i++){
        cargabin(i,cromo,num);
        suma=0;
        valor=0;
        for(int j=0;j<num;j++){
            if(cromo[j]==1){
              suma+=pesos[j];
              valor+=valores[j];
            }
        }
        if(valor>max and suma<=p){
            max=valor;
            solucion=i;
        }
    }
    //para imprimir
    cout<<"Solucion:"<<endl;
    cargabin(solucion,cromo,num);
    for(int i=0;i<num;i++){
        if(cromo[i]==1){
            cout<<" "<<pesos[i]<<" ";
        }else{
            cout<<" 0 ";
        }
        if(i!=0 and (i+1)%4==0){
            cout<<endl;	
	}

    }
    cout<<endl;
    
    for(int i=0;i<num;i++){
        if(cromo[i]==1){
            cout<<" "<<valores[i]<<" ";
        }else{
            cout<<" 0 ";
        }
        if(i!=0 and (i+1)%4==0){
            cout<<endl;	
	}
    }
    cout<<endl;
    cout<<"Valor Maximo: "<<max<<" (en miles de USD)"<<endl;
    return 0;
}


