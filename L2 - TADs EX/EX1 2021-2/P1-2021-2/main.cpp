

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 5 de octubre de 2024, 02:25 PM
 */

#include <iostream>
#include <iomanip>

#include "Cola.h"
#include "funcionesCola.h"
#include "funcionesLista.h"
#define N 10
using namespace std;

int retornarPiso(Cola &cola){
    return retornaCabeza(cola.lista);
}

Nodo * obtenerAnterior(Cola &cola,int piso, int dir){
    Nodo *ant=nullptr,*actual=cola.lista.cabeza;
    while(actual!=nullptr){
        if(actual->piso==piso and actual->direccion==dir){
            break;
        }
        ant=actual;
        actual=actual->siguiente;
    }
    return ant;
}


void encolarOrden(Cola &cola,int piso,int dir){
    Nodo *nodo = crearNodo(piso, dir, nullptr);

    if (dir == 0) { // Caso de bajada: ordenar de mayor a menor
        if (cola.lista.bajada == nullptr) {  // Si no hay nodos de bajada
            cola.lista.bajada = nodo;  // El nodo actual es el primer nodo de bajada
            cola.lista.subida->siguiente = nodo;  // Conectar la subida a la bajada
        } else {
            if (piso < cola.lista.bajada->piso) {  // Si el nuevo nodo tiene un piso menor (mayor prioridad en bajada)
                nodo->siguiente = cola.lista.bajada;
                cola.lista.bajada = nodo;
            } else {
                Nodo *actual = cola.lista.bajada;
                Nodo *anterior = nullptr;

                while (actual != nullptr && actual->piso < piso) {
                    anterior = actual;
                    actual = actual->siguiente;
                }

                nodo->siguiente = actual;
                if (anterior != nullptr) {
                    anterior->siguiente = nodo;
                }
            }
        }
    } else {  // Caso de subida: ordenar de menor a mayor
        if (cola.lista.subida == nullptr) {  // Si no hay nodos de subida
            cola.lista.cabeza = nodo;  // El nodo actual es la cabeza y el primer nodo de subida
            cola.lista.subida = nodo;
        } else {
            if (piso > cola.lista.subida->piso) {  // Si el nuevo nodo tiene un piso menor (se inserta al principio)
                cola.lista.subida->siguiente=nodo;
                cola.lista.subida = nodo;
            } else {
                Nodo *actual = cola.lista.cabeza;
                Nodo *anterior = nullptr;

                while (actual != cola.lista.subida->siguiente && actual->piso < piso) {
                    anterior = actual;
                    actual = actual->siguiente;
                }

                nodo->siguiente = actual;
                if (anterior != nullptr) {
                    anterior->siguiente = nodo;
                } else {
                    cola.lista.cabeza = nodo;  // Si anterior es nullptr, el nodo es la nueva cabeza
                }
            }
        }
    }
}
int main(int argc, char** argv) {
    int n=7;
    Cola cola;
    construir(cola);
    int dir=1;
    if(esColaVacia(cola)){
        encolar(cola,1,dir);
        if(dir==1)cola.lista.subida=cola.lista.cabeza;
        if(dir==0)cola.lista.bajada=cola.lista.cabeza;
    }
    encolarOrden(cola,3,1);
    encolarOrden(cola,6,1);
    encolarOrden(cola,2,1);
    encolarOrden(cola,4,1);
    
    int pisoActual=retornarPiso(cola);
    cout<<"Cola: ";
    imprime(cola);
    cout<<"Piso actual: "<<pisoActual<<endl;
    
    int aux=desencolar(cola);
    
    pisoActual=retornarPiso(cola);
    cout<<"Cola: ";
    imprime(cola);
    cout<<"Piso actual: "<<pisoActual<<endl;
    encolarOrden(cola,5,1);
    encolarOrden(cola,1,0);
    aux=desencolar(cola);
    pisoActual=retornarPiso(cola);
    cout<<"Cola: ";
    imprime(cola);
    cout<<"Piso actual: "<<pisoActual<<endl;
    return 0;
}

