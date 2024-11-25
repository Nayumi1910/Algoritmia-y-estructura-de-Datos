

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 6 de octubre de 2024, 10:02 AM
 */

#include <iostream>
#include <iomanip>

#include "Cola.h"
#include "funcionesCola.h"
#include "Pila.h"
#include "funcionesPila.h"
#include "Nodo.h"
using namespace std;

void reordenar(Cola &cola){
    Pila aux;
    construir(aux);
    //primero elimno la clase C=3
    Nodo *recorrer=cola.lista.cabeza;
    Nodo *ant=nullptr;
    while(recorrer!=nullptr){
        if(recorrer->elemento/10==3){
            cola.lista.cola=ant;
            ant->siguiente=nullptr;
            break;
        }
        ant=recorrer;
        recorrer=recorrer->siguiente;
    }
    imprime(cola);
   //despues de eliminar ello, procedemos a ordenar
    //procedemos a poner todos los A en la pila
    
    while(cola.lista.cabeza->elemento/10!=2){
        apilar(aux,desencolar(cola));
    }
    imprime(cola);
    while(!esPilaVacia(aux)){
        encolar(cola,desapilar(aux));
    }
    while(cola.lista.cabeza->elemento/10!=1){
        encolar(cola,desencolar(cola));
    }
    while(cola.lista.cabeza->elemento/10!=2){
        apilar(aux,desencolar(cola));
    }
    while(!esPilaVacia(aux)){
        encolar(cola,desapilar(aux));
        encolar(cola,desencolar(cola));
    }
}

int main(int argc, char** argv) {
    //A=1 B=2 C=3
    Cola cola;
    construir(cola);
    encolar(cola,11);
    encolar(cola,12);
    encolar(cola,13);
    encolar(cola,14);
    encolar(cola,21);
    encolar(cola,22);
    encolar(cola,23);
    encolar(cola,24);
    encolar(cola,31);
    encolar(cola,32);
    encolar(cola,33);
    encolar(cola,34);
    cout<<"Cola original: ";
    imprime(cola);
    reordenar(cola);
    cout<<"Cola nueva:";
    imprime(cola);
    return 0;
}

