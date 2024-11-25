

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 27 de agosto de 2024, 03:44 PM
 */
#include <iostream>
#include <cmath>

#define N 10
#define M 10

using namespace std;

void cargabin(int num,int cromo[N],int n, int m){
	for(int i=0;i<n;i++){
		cromo[i]=0;
	}
	int digito, indice=0;
	while(num>0){
		digito=num%m;
		num=num/m;
		cromo[indice]=digito;
		indice++;
	}
}

int main (){
    int capacidades[N]={100,100,100};
    int paquetes[N]={50,20,30,50};
    int n=4,m=3;
    int cromo[N],camion[N];
    int combinaciones=pow(m,n);
    int pesoMax,pesoMin, pesoValido,dif=99999,solucion;
    for(int i=0;i<combinaciones;i++){
        cargabin(i,cromo,n,m);
        pesoValido=1;
        pesoMax=0;
        pesoMin=9999;
        for(int k=0;k<m;k++){
            camion[k]=0;
        }
        for(int j=0;j<n;j++){
            camion[cromo[j]]+=paquetes[j];    
        }
        for(int l=0;l<m;l++){
            if(capacidades[l]-camion[l]<0){
                pesoValido=0;
            }
            if(camion[l]<=pesoMin){
                pesoMin=camion[l];
            }
            if(camion[l]>=pesoMax){
                pesoMax=camion[l];
            }
        }
        if(abs(pesoMax-pesoMin)<dif and pesoValido){
                dif=abs(pesoMax-pesoMin);
                solucion=i;
            }
        
    }
    //imprimir
    cargabin(solucion,cromo,n,m);
    for(int i=0;i<n;i++){
        cout<<"paquete"<<i+1<<"-"<<"camion"<<cromo[i]+1<<endl;
    }

	
	return 0;
} 
