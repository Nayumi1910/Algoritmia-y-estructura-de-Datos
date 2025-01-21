

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 1 de diciembre de 2024, 06:32 PM
 */

#include <iostream>
#include <iomanip>
#include <cstring>
#include "ArbolB.h"
#include "funcionesAB.h"
#include "funcionesCola.h"
#include "Cola.h"
using namespace std;
NodoArbol * crearNuevoNodo(const char* titulo, int relevancia) 
{
    NodoArbol * nuevo = new struct NodoArbol;
    nuevo->izquierda = nullptr;
    nuevo->derecha = nullptr;
    strcpy(nuevo->titulo, titulo);
    nuevo->relevancia = relevancia;
    return nuevo;
}
int imprimirAmplitud(ArbolBinario &arbol){
    Cola cola;
    construir(cola);
    encolar(cola,arbol.raiz);
    int nivel=0,resultado=0;
    while(!esColaVacia(cola)){
        int n=longitud(cola);
        cout<<"Nivel "<<nivel<<" : ";
        for(int i=0;i<n;i++){
            NodoArbol *aux=desencolar(cola);
            imprimirNodo(aux);
            if(aux->izquierda!=nullptr){
                encolar(cola,aux->izquierda);
            }
            if(aux->derecha!=nullptr){
                encolar(cola,aux->derecha);
            }
            if(aux->relevancia==10)resultado=nivel;
        }
        nivel++;
        cout<<endl;
    }
    return resultado;
}
void eliminarNodos(NodoArbol *nodo){
    if(nodo==nullptr)return ;
    eliminarNodos(nodo->izquierda);
    eliminarNodos(nodo->derecha);
    delete nodo;
}
void eliminarSubArbol(NodoArbol *nodo,int numNodo,int dir){
    if(nodo==nullptr)return;
    if(nodo->relevancia==numNodo){
        if(dir==1){
            eliminarNodos(nodo->derecha);
            nodo->derecha=nullptr;
        }
        if(dir==0){
            eliminarNodos(nodo->izquierda);
            nodo->izquierda=nullptr;
        }
    }
    eliminarSubArbol(nodo->izquierda,numNodo,dir);
    eliminarSubArbol(nodo->derecha,numNodo,dir);
}
int main(int argc, char** argv) {
    ArbolBinario arbol;
    construir(arbol);arbol.raiz = crearNuevoNodo("Titulo", 7);
    
    arbol.raiz->izquierda = crearNuevoNodo("Capitulo1", 8);
    arbol.raiz->derecha = crearNuevoNodo("Capitulo2", 5);
    
    arbol.raiz->izquierda->izquierda = crearNuevoNodo("Seccion1.1", 6);
    arbol.raiz->izquierda->derecha = crearNuevoNodo("Principal", 10);

    arbol.raiz->derecha->izquierda = crearNuevoNodo("Seccion2.1", 3);
    arbol.raiz->derecha->derecha = crearNuevoNodo("Seccion2.2", 4);

    arbol.raiz->izquierda->izquierda->izquierda = crearNuevoNodo("Seccion1.1.1", 4);
    arbol.raiz->izquierda->izquierda->derecha = crearNuevoNodo("Seccion1.1.2", 2);
    cout<<"Arbol: ";
    recorrerPreOrden(arbol);
    cout<<endl;
    cout<<endl;
    int nivel=imprimirAmplitud(arbol);
    cout<<"Nivel: "<<nivel<<endl;
    cout<<endl;
    int numNodo=7,der=1;
    eliminarSubArbol(arbol.raiz,numNodo,1);
    cout<<"Arbol nuevo: "<<endl;
    imprimirAmplitud(arbol);
    cout<<endl;
    return 0;
}

