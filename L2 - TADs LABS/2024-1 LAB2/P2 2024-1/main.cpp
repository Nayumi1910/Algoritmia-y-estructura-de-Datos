

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 11 de octubre de 2024, 01:30 AM
 */

#include <iostream>
#include <iomanip>

#include "Lista.h"
#include "funcionesLista.h"
#include "Pila.h"
#include "funcionesPila.h"
#include "Nodo.h"
using namespace std;
void hanoi(int n,Pila &origen,Pila &destino,Pila &aux){
    if(n==1){
        apilar(destino,desapilar(origen));
        return;
    }
    hanoi(n-1,origen,aux,destino);
    apilar(destino,desapilar(origen));
    hanoi(n-1,aux,destino,origen);
}
void apilarRobot(Lista &lista,Pila &principal){
    Pila aux1,aux2,aux3;
    construir(aux1);
    construir(aux2);
    construir(aux3);
    
    int contador=0;
    bool apilado;
    int dato;
    while(!esListaVacia(lista)){
        dato=lista.cabeza->elemento;
        apilar(aux3,dato);
        if(esPilaVacia(principal)){
            dato=desapilar(aux3);
            apilar(principal,dato);
            contador++;
        }else{
            if(cima(aux3)<=cima(principal)){
                dato=desapilar(aux3);
                apilar(principal,dato);
            }else{
                apilado=false;
                for(int i=1;i<=contador;i++){
                    hanoi(i,principal,aux1,aux2);
                    if(cima(aux3)<=cima(principal) or esPilaVacia(principal)){
                        dato=desapilar(aux3);
                        apilar(principal,dato);
                        apilado=true;
                    }
                    hanoi(i,aux1,principal,aux2);
                    if(apilado==true)break;
                    contador++;
                }
            }
        }
        lista.cabeza=lista.cabeza->siguiente;
    }
}
int main(int argc, char** argv) {
    Lista lista;
    construir(lista);
    insertarAlFinal(lista,50);
    insertarAlFinal(lista,100);
    insertarAlFinal(lista,200);
    insertarAlFinal(lista,150);
    insertarAlFinal(lista,50);
    insertarAlFinal(lista,200);
    insertarAlFinal(lista,100);
    cout<<"Lista : ";
    imprime(lista);
    
    Pila principal;
    construir(principal);
    apilarRobot(lista,principal);
    
    cout<<"Pila : ";
    imprimir(principal);

    return 0;
}

