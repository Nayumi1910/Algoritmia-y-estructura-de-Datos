

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 29 de septiembre de 2024, 10:49 PM
 */

#include <iostream>
#include <iomanip>
#include <cstring>

#include "Nodo.h"
#include "Cola.h"
#include "Pila.h"
#include "funcionesCola.h"
#include "Lista.h"
#include "funcionesLista.h"
#include "funcionesPila.h"
using namespace std;
//PARTE A
void encolarPrioridad(Cola &cola,Elemento dato){
    //creamos el nodo
    Nodo *nodo=crearNodo(dato,nullptr);
    //primero si es cola vacia o no
    if(esColaVacia(cola)){
        //en caso de que sea
        cola.lista.cabeza=nodo;
        cola.lista.cola=nodo;
        if(dato.prioridad==1){
            cola.lista.primer=nodo;
        }
        if(dato.prioridad==2){
            cola.lista.segundo=nodo;
        }
    }else{
        //en caso de que no sea
        //primero vemos a que prioridad corresponde
        if(dato.prioridad==1){
            //en caso de que sea prioridad 1, lo primero que vemos es
            //si existe algo a lo que apunte el nodo primer
            if(cola.lista.primer==nullptr){
                //en caso de que ya haya elementos en la cola
                //pero ni uno d eprioridad 
                nodo->siguiente=cola.lista.cabeza;
                cola.lista.cabeza=nodo;
            }else{
                //en caso de que ya exista algo a lo que apunte
                if(cola.lista.primer->siguiente==nullptr){
                    cola.lista.primer->siguiente=nodo;
                    cola.lista.cola=nodo;
                }else{
                    nodo->siguiente=cola.lista.primer->siguiente;
                    cola.lista.primer->siguiente=nodo; 
                }
            }
            cola.lista.primer=nodo;
        }else if(dato.prioridad==2){
            //si es de prioridad 2, hacemos lo mismo
            //verificamos si es el primer nodp de prio 2
            if(cola.lista.segundo==nullptr){
                //ahora verificamos si la cola es prioridad 1
                if(cola.lista.cola->elemento.prioridad==1){
                    cola.lista.cola->siguiente=nodo;
                    cola.lista.cola=nodo;
                }
                if(cola.lista.cola->elemento.prioridad==3){
                    //no existe priorirdad 1
                    if(cola.lista.primer==nullptr){
                        nodo->siguiente=cola.lista.cabeza->siguiente;
                        cola.lista.cabeza=nodo;
                    }else{
                        //en caso de que si exista
                        nodo->siguiente=cola.lista.primer->siguiente;
                        cola.lista.primer->siguiente=nodo;
                    }
                }
            }else{
                if(cola.lista.segundo==cola.lista.cola){
                    cola.lista.segundo->siguiente=nodo;
                    cola.lista.cola=nodo;
                }else{
                    nodo->siguiente=cola.lista.segundo->siguiente;
                    cola.lista.segundo->siguiente=nodo;
                }
            }
            cola.lista.segundo=nodo;
        }else{
            //si es de prioridad 3
            cola.lista.cola->siguiente=nodo;
            cola.lista.cola=nodo;
        }
    }
    cola.lista.longitud++;
}
//PARTE B

void reordenar(Cola &cola,int n){
    Pila pila;
    construir(pila);
    int i=0;
    while(i<(n/2)){
        apilar(pila,desencolar(cola));
        i++;
    }
    imprime(cola);
    i=0;
    while(i<(n/2)){
        encolar(cola,desapilar(pila));
        i++;
    }
    imprime(cola);
    i=0;
    while(i<(n/2)){
        encolar(cola,desencolar(cola));
        i++;
    }
    imprime(cola);
    i=0;
    while(i<(n/2)){
        apilar(pila,desencolar(cola));
        i++;
    }
    imprime(cola);
    i=0;
    while(i<5){
        encolar(cola,desapilar(pila));
        encolar(cola,desencolar(cola));
        i++;
    }
    cout<<"Cola reordenada: ";
    imprime(cola);
    
}

int main(int argc, char** argv) {
    //PARTE A
    Elemento dato;
    Cola cola;
    construir(cola);
    dato.prioridad=2;
    strcpy(dato.codigo,"ISI001");
    encolarPrioridad(cola,dato);
    dato.prioridad=1;
    strcpy(dato.codigo,"ISI002");
    encolarPrioridad(cola,dato);
    dato.prioridad=1;
    strcpy(dato.codigo,"ISI003");
    encolarPrioridad(cola,dato);
    dato.prioridad=3;
    strcpy(dato.codigo,"ISI0024");
    encolarPrioridad(cola,dato);
    dato.prioridad=2;
    strcpy(dato.codigo,"ISI005");
    encolarPrioridad(cola,dato);
    dato.prioridad=3;
    strcpy(dato.codigo,"ISI006");
    encolarPrioridad(cola,dato);
    dato.prioridad=1;
    strcpy(dato.codigo,"ISI007");
    encolarPrioridad(cola,dato);
    cout<<"Cola: ";
    imprime(cola);
    
    //PARTE B
    Cola cola2;
    
    construir(cola2);
    dato.prioridad=1;
    strcpy(dato.codigo,"PSI001");
    encolar(cola2,dato);
    dato.prioridad=1;
    strcpy(dato.codigo,"PSI002");
    encolar(cola2,dato);
    dato.prioridad=1;
    strcpy(dato.codigo,"PSI003");
    encolar(cola2,dato);
    dato.prioridad=1;
    strcpy(dato.codigo,"PSI004");
    encolar(cola2,dato);
    dato.prioridad=1;
    strcpy(dato.codigo,"PSI005");
    encolar(cola2,dato);
    dato.prioridad=2;
    strcpy(dato.codigo,"PSI006");
    encolar(cola2,dato);
    dato.prioridad=2;
    strcpy(dato.codigo,"PSI007");
    encolar(cola2,dato);
    dato.prioridad=2;
    strcpy(dato.codigo,"PSI008");
    encolar(cola2,dato);
    dato.prioridad=2;
    strcpy(dato.codigo,"PSI009");
    encolar(cola2,dato);
    dato.prioridad=2;
    strcpy(dato.codigo,"PSI010");
    encolar(cola2,dato);
    cout<<"Cola 2: ";
    imprime(cola2);
    int n=10;
    reordenar(cola2,n);
    
    return 0;
}

