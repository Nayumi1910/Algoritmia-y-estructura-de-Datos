

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 27 de agosto de 2024, 02:55 PM
 */

#include <iostream>
#include <iomanip>
#include <cmath>
#define MAX 10
using namespace std;

//void cargabin(int num,int cromo[MAX], int n){
//    for(int i=0;i<n;i++){
//        cromo[i]=0;
//    }
//    int i=0,aux;
//    while(num>0){
//        aux=num%2;
//        num=num/2;
//        cromo[i]=aux;
//        i++;
//    }
//}
int main(int argc, char** argv) {
    int n=10;
    char letra[MAX]={'G','O','L','A','R','L','A','O','G','H'};
    char palabra[3]={'G','O','L'};
    
    int cromo[3][MAX], cant[3]={0};
    for(int i=0;i<n;i++){
        if(letra[i]==palabra[0]){
            cromo[0][cant[0]]=i+1;
            cant[0]++;
        }else if(letra[i]==palabra[1]){
            cromo[1][cant[1]]=i+1;
            cant[1]++;
        }else if(letra[i]==palabra[2]){
            cromo[2][cant[2]]=i+1;
            cant[2]++;
        }
    }
    int i, j, k, casos = 0, centinela = 1;
    i = j = k = 0;
	 while (centinela <= cant[0]) {
        // Impresi n de los casos posibles
        cout << "Caso : " << casos <<endl;
        cout << palabra[0] << " = " << cromo[0][i]<<endl;
        cout << palabra[1] << " = " << cromo[1][j] <<endl;
    	cout << palabra[2] << " = " << cromo[2][k] <<endl;
        casos++;
        // Algoritmo, para poder imprimir todas las formas validas
        k++;
        if (k >= cant[2]) {
            k = 0;
            j++;
        }
        if (j >= cant[1]) {
            j = 0;
            i++;
            centinela++;
            casos++;
        }
    }

//    int combinaciones=pow(2,n);
//    
//    for(int i=0;i<combinaciones;i++){
//        cargabin(i,cromo,n);
//        for(int j=0;j<n;j++){
//            
//        }
//    }
    return 0;
}

