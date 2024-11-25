

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 28 de septiembre de 2024, 10:57 AM
 */

#include <iostream>
#include <iomanip>
#include "Pila.h"
#include "funcionesPila.h"
#define N 10
using namespace std;

int matriz[N][N]={{0,0,0,0,0,0,0},
                    {10,0,20,30,0,20,40},
                    {0,0,0,0,0,100,0},
                    {0,0,0,0,0,80,0},
                    {50,10,5,10,0,100,4},
                    {100,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0}};
//int encuentraSkynerd(int n){
//    Pila pila;
//    int posible,a,b;
//    construir(pila);
//    
//    //apilamos todos los serves
//    for(int i=0;i<n;i++)apilar(pila,i);
//    
//    //buscamos desapilando cada uno
//    while(pila.lista.longitud>1){
//        a=desapilar(pila);
//        b=desapilar(pila);
//        if(matriz[a][b]!=0){
//            apilar(pila,a);
//        }else{
//            apilar(pila,b);
//        }
//    }
//    posible=desapilar(pila);
//    for(int i=0;i<n;i++){
//        if((i!=posible)and (matriz[i][posible] and matriz[posible][i])){
//            return -1;
//        }
//    }
//    return posible;
//}

int encuentraSkynerd(int n,int *max){
    Pila pila;
    construir(pila);
    int a,b,posible;
    
    for(int i=0;i<n;i++)apilar(pila,i);
    
    while(pila.lista.longitud>1){
        a=desapilar(pila);
        b=desapilar(pila);
        if(matriz[a][b]!=0){
            apilar(pila,a);
        }else{
            apilar(pila,b);
        }
    }
    posible=desapilar(pila);
    for(int i=0;i<n;i++){
        if((*max)<matriz[posible][i]){
            *max=matriz[posible][i];
        }
        if(i!=posible and (matriz[posible][i] and matriz[i][posible])){
            return -1;
        }
        
    }
    return posible;
}
int main(int argc, char** argv) {
    int n=7,max=0;
    int servidor=encuentraSkynerd(n,&max);
    if(servidor==-1){
        cout<<"No se encuentra"<<endl;
    }else{
        cout<<"El servidor es: "<<servidor+1<<endl;
        cout<<"Maximo: "<<max<<endl;
    }
    
    return 0;
}

