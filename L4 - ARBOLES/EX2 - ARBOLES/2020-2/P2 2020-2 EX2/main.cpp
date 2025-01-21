

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 5 de diciembre de 2024, 11:26 AM
 */

#include <iostream>
#include <iomanip>

#include "ArbolBB.h"
#include "funcionesABB.h"
#include "Cola.h"
#include "funcionesCola.h"
#include "funcionesAB.h"
#define P 100000
#define N 10
using namespace std;
void imprimirNodoNew(struct NodoArbol * raiz){
    cout<<setw(5)<<"("<<raiz->elemento<<"-"<<raiz->semana<<"-"<<
            raiz->cantidad<<")";
}
void imprimirAmplitud(ArbolBinarioBusqueda &arbol){
    Cola cola;
    encolar(cola,arbol.arbolBinario.raiz);
    NodoArbol *recorre=arbol.arbolBinario.raiz;
    int cant=0;
    while(!esColaVacia(cola)){
        int n=longitud(cola);
        cout<<"Nivel "<<cant<<" : ";
        for(int i=0;i<n;i++){
            NodoArbol *aux=desencolar(cola);
            imprimirNodoNew(aux);
            if(recorre->izquierda!=nullptr){
                encolar(cola,recorre->izquierda);
            }
            if(recorre->derecha!=nullptr){
                encolar(cola,recorre->derecha);
            }
        }
        cant++;
    }
}
int main(int argc, char** argv) {
    ArbolBinarioBusqueda arbol;
    construir(arbol);
    int n=5,p=40;
    insertar(arbol,1,3,2);
    insertar(arbol,2,3,3);
    insertar(arbol,3,3,4);
    insertar(arbol,4,3,0);
    insertar(arbol,5,3,0);
    insertar(arbol,1,4,0);
    insertar(arbol,2,4,3);
    insertar(arbol,3,4,2);
    insertar(arbol,4,4,0);
    insertar(arbol,5,4,0);
    insertar(arbol,1,1,4);
    insertar(arbol,2,1,2);
    insertar(arbol,3,1,8);
    insertar(arbol,4,1,0);
    insertar(arbol,5,1,2);
    insertar(arbol,1,2,0);
    insertar(arbol,2,2,0);
    insertar(arbol,3,2,0);
    insertar(arbol,4,2,3);
    insertar(arbol,5,2,2);
    
    imprimirAmplitud(arbol);

    
    return 0;
}

