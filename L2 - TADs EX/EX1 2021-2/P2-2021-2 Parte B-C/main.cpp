

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 5 de octubre de 2024, 12:34 PM
 */

#include <iostream>
#include <iomanip>
#include "Lista.h"
#include "funcionesLista.h"
#include "Cola.h"
#include "funcionesPila.h"
#include "funcionesCola.h"
#include "Pila.h"
#include "Nodo.h"
using namespace std;
#define M 10
void cargar(Lista &lista,int arr[M][2],int n){
    for(int i=0;i<n;i++){
        if(arr[i][0]==1){
            insertarAlFinal(lista,arr[i][1]);
        }
    }
}
void seleccionCola(Lista &lista,Cola &cola){
    int max=3;
    Pila p1,p2,p3;
    construir(p1);
    construir(p2);
    construir(p3);
    int cant=0;
    while(!esListaVacia(lista)){
        int valor=retornaCabeza(lista);
        if(valor==1){
            if(longitud(p1)<=max){
                apilar(p1,valor);
            }
        }
        if(valor==2){
            if(longitud(p2)<=max){
                apilar(p2,valor);
            }

        }
        if(valor==3){
            if(longitud(p3)<=max){
                apilar(p3,valor);
            }

        }
        if(longitud(p1)>=1 and longitud(p2)>=1 and longitud(p3)>=1){
            encolar(cola,desapilar(p1));
            encolar(cola,desapilar(p2));
            encolar(cola,desapilar(p3));
            cant++;
        }
        lista.cabeza=lista.cabeza->siguiente;
    }
    cout<<"Pila 1: ";
    imprimir(p1);
    cout<<"Pila 2: ";
    imprimir(p2);
    cout<<"Pila 3: ";
    imprimir(p3);
    cout<<"La cantidad de combos son: "<<cant<<endl;
}
int main(int argc, char** argv) {
    int banjeda4[M][2]={{0,3},{0,1},{1,3},{1,2},{1,3},{1,3},{1,1}};
    int banjeda3[M][2]={{1,1},{1,2},{1,1},{1,1},{1,3},{0,1},{0,2}};
    int banjeda2[M][2]={{1,1},{1,2},{1,3},{1,3},{1,3},{1,2},{0,1}};
    int banjeda1[M][2]={{1,2},{1,1},{1,3},{0,2},{0,3},{0,1},{0,1}};
    int n=7;
    Lista lista;
    construir(lista);
    cargar(lista,banjeda1,n);
    cargar(lista,banjeda2,n);
    cargar(lista,banjeda3,n);
    cargar(lista,banjeda4,n);
    cout<<"Lista: ";
    imprime(lista);
    Cola cola;
    construir(cola);
    seleccionCola(lista,cola);
    cout<<"Combos: ";
    imprime(cola);
    
    return 0;
}

