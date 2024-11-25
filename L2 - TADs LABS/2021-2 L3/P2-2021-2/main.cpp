

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 20 de septiembre de 2024, 01:49 PM
 */

#include <iostream>
#include <iomanip>
#include "Cola.h"
#include "funcionesCola.h"
#include "Pila.h"
#include "funcionesPila.h"
using namespace std;
void ordenarBurbuja(int lista[],int num){
    for(int i=0;i<=num-2;i++){
////        cout<<endl;
        for(int j=0;j<num-2-i;j++){
            if(lista[j+1]<lista[j]){
                int temp=lista[j];
                lista[j]=lista[j+1];
                lista[j+1]=temp;
            }
//            cout<<lista[j]<<" ";
        }
    }
}
void hanoi(int n,Pila &origen,Pila &destino,Pila &aux){
    if(n==1){
        apilar(destino,desapilar(origen));
        return;
    }
    hanoi(n-1,origen,aux,destino);
    apilar(destino,desapilar(origen));
    hanoi(n-1,aux,destino,origen);
}
void apilarPilas(Cola &cola,Pila &origen,Pila &destino,Pila &aux){
    int dato,cont=0,num=0;
    int lista[100];
    while(!esColaVacia(cola)){
        dato=desencolar(cola);
        cont =num;
        for(int i=0;i<num;i++){
            if(dato<lista[i]){
                cont=i;
                break;
            }
        }
        if(esPilaVacia(origen) or dato<cima(origen)){
            apilar(origen,dato);
        }else{
            hanoi(cont,origen,destino,aux);
//            imprimir(origen);
//            imprimir(destino);
//            imprimir(aux);
            apilar(origen,dato);
            hanoi(cont,destino,origen,aux);
//            imprimir(origen);
        }
        lista[num]=dato;
        num++;
        ordenarBurbuja(lista,num);
    }
}
int main(int argc, char** argv) {
    Cola cola;
    construir(cola);
    encolar(cola,2);
    encolar(cola,8);
    encolar(cola,10);
    encolar(cola,8);
    encolar(cola,5);
    encolar(cola,3);
    cout<<"Cola: ";
    imprime(cola);
//    int n=longitud(cola);
    Pila principal,aux,aux2;
    construir(principal);
    construir(aux);
    construir(aux2);
    apilarPilas(cola,principal,aux,aux2);
    cout<<"Pila destino: ";
    imprimir(principal);
    return 0;
}

