

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 16 de septiembre de 2024, 08:59 PM
 */

#include <iostream>
#include <iomanip>
#include "Cola.h"
#include "Lista.h"
#include "Nodo.h"
#include "funcionesCola.h"
#include "funcionesLista.h"
using namespace std;

int retornarPiso(Cola &cola){
    Elemento e;
    e=retornaCabeza(cola.lista);
    return e.piso;
}
void encolarOrdenardo(Cola &cola,Elemento e){
    Nodo *nodo=crearNodo(e,nullptr);
    if(e.mov==1){
        if(cola.lista.subida==nullptr){
            cola.lista.cabeza=nodo;
            cola.lista.subida=nodo;
        }else{
            if(e.piso>cola.lista.subida->elemento.piso){
                cola.lista.subida->siguiente=nodo;
                cola.lista.subida=nodo;
            }else{
                Nodo *recorrer=cola.lista.cabeza;
                Nodo *ant=nullptr;
                while(recorrer!=nullptr and recorrer->elemento.piso<e.piso){
                    ant=recorrer;
                    recorrer=recorrer->siguiente;
                }
                nodo->siguiente=recorrer;
                if(ant!=nullptr){
                    ant->siguiente=nodo; 
                }else{
                    cola.lista.cabeza=nodo;
                } 
            }
        }
        
    }else {
        if(cola.lista.bajada==nullptr){
            cola.lista.bajada=nodo;
            cola.lista.subida->siguiente=nodo;
        }else{
            if(e.piso<cola.lista.bajada->elemento.piso){
                nodo->siguiente=cola.lista.bajada;
                cola.lista.bajada=nodo;
            }else{
                Nodo *recorrer=cola.lista.bajada;
                Nodo *ant=nullptr;
                while(recorrer!=nullptr and recorrer->elemento.piso<e.piso){
                    ant=recorrer;
                    recorrer=recorrer->siguiente;
                }
                nodo->siguiente=recorrer;
                if(ant!=nullptr){
                    ant->siguiente=nodo; 
                }  
            }
            
        }
    }
    cola.lista.longitud++;
}
void reasignar(Cola &cola,Cola &subida,Cola &bajada){
    while(!esColaVacia(cola)){
        Elemento e=desencolar(cola);
        if(e.mov==1){
            encolarOrdenardo(subida,e);
        }else{
            encolar(bajada,e);
        }
    }
}
int main(int argc, char** argv) {
    int n;
    Cola cola, subida, bajada;
    construir(cola);
    construir(subida);
    construir(bajada);
    Elemento e;
    
    if(esColaVacia(cola)){
        e.mov=1;
        e.piso=1;
        encolar(cola,e);
        if(e.mov==1)cola.lista.subida=cola.lista.cabeza;
        if(e.mov==0)cola.lista.bajada=cola.lista.cabeza;
        encolar(subida,e);
        encolar(bajada,e);
    }
    cout<<"La cola general de solicitudes tienen: "<<endl;
    imprime(cola);
    cout<<"Luego de asignar las solicitudes a cada ascensor se tiene: "<<endl;
    cout<<"Cola 1: ";
    imprime(bajada);
    cout<<"Cola 2 : ";
    imprime(subida);
    cout<<"El ascensor 1 esta en el piso: "<<retornarPiso(bajada)<<endl;
    cout<<"El ascensor 2 esta en el piso: "<<retornarPiso(subida)<<endl;
    
    Elemento aux=desencolar(cola);
    aux=desencolar(subida);
    aux=desencolar(bajada);
    
    int cantSoli=5;
    e.mov=1;
    e.piso=3;
    encolar(cola,e);
    e.mov=1;
    e.piso=6;
    encolar(cola,e);
    e.mov=1;
    e.piso=2;
    encolar(cola,e);
    e.mov=1;
    e.piso=4;
    encolar(cola,e);
    e.mov=0;
    e.piso=7;
    encolar(cola,e);
    
    cout<<"La cola general de solicitudes tienen: "<<endl;
    imprime(cola);
    //funcion de reasignar
    reasignar(cola,subida,bajada);
    //
    cout<<"Luego de asignar las solicitudes a cada ascensor se tiene: "<<endl;
    cout<<"Cola 1: ";
    imprime(bajada);
    cout<<"Cola 2 : ";
    imprime(subida);
    cout<<"El ascensor 1 esta en el piso: "<<retornarPiso(bajada)<<endl;
    cout<<"El ascensor 2 esta en el piso: "<<retornarPiso(subida)<<endl;
    
    return 0;
}

