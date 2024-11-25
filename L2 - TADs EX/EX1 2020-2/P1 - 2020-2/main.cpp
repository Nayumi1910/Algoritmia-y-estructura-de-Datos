

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 23 de septiembre de 2024, 05:50 PM
 */

#include <iostream>
#include <iomanip>
#include "Cola.h"
#include "Nodo.h"
#include "funcionesCola.h"
#include "Pila.h"
#include "funcionesPila.h"
using namespace std;

void reordenar(Cola &cola,Pila &pila){
    //usamos dos nodos, uno que recorrera la cola
    //y otro que sera el anterior
    Nodo *recorrer=cola.lista.cabeza,*ant=nullptr;
    //primero eliminamos todo lo de C=3
    while(recorrer!=nullptr){
        //en caso de encontrar los C=3
        if(recorrer->elemento/10==3){
            //verificamos si es o no la primera en la cola
            if(recorrer==cola.lista.cabeza){
                cola.lista.cabeza=recorrer->siguiente;
                recorrer=cola.lista.cabeza;
            }else{
                ant->siguiente=recorrer->siguiente;
                recorrer=ant->siguiente;
            }
        }
        //en caso de que no, sigue recorriendo la cola
        else{
            ant=recorrer;
            recorrer=recorrer->siguiente;
        }
        
    }
    cola.lista.cola=ant;
    
    imprime(cola);
    
    //despues de eliminar ello, procemos a reordenar la cola
    //con ayuda de la pila
    
    //primero apilamos los valores de A=1
    while(cola.lista.cabeza->elemento/10!=2){
        apilar(pila,desencolar(cola));
    }
    imprimir(pila);
    
    //despues de apilar, encolamos todo de nuevo
    while(pila.lista.cabeza!=nullptr){
        encolar(cola,desapilar(pila));
    }
    imprime(cola);
    //volvemos a apilar, pero esta vez los B=2
    while(cola.lista.cabeza->elemento/10!=1){
        apilar(pila,desencolar(cola));
    }
    imprimir(pila);
    
    //ahora apilamos y encolamos
    while(pila.lista.cabeza!=nullptr){
        encolar(cola,desencolar(cola));
        encolar(cola,desapilar(pila));
    }
    
}
int main(int argc, char** argv) {
    Cola original;
    construir(original);
    Pila aux;
    construir(aux);
    //Ingresamoslos datos, para este caso, se usará A=1, B=2, C =3
    encolar(original,11);
    encolar(original,12);
    encolar(original,13);
    encolar(original,14);
    encolar(original,21);
    encolar(original,22);
    encolar(original,23);
    encolar(original,24);
    encolar(original,31);
    encolar(original,32);
    encolar(original,33);
    encolar(original,34);
    
    //Despues de encolar procedemos a imprimir
    imprime(original);
    
    reordenar(original,aux);
    //Despues de reordenar procedemos a imprimir
    imprime(original);
    return 0;
}

