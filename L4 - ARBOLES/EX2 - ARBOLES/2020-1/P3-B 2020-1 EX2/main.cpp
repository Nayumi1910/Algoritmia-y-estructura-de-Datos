

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 5 de diciembre de 2024, 10:49 AM
 */

#include <iostream>
#include <iomanip>

#include "ArbolB.h"
#include "funcionesAB.h"
using namespace std;

void consultar(NodoArbol *nodo){
    char respuesta;
    imprimirNodo(nodo);
    if(nodo->derecha==nullptr or nodo->izquierda==nullptr)return;
    cin>>respuesta;
    if(respuesta=='S'){
        consultar(nodo->izquierda);
    }else{
        consultar(nodo->derecha);
    }
}

int main(int argc, char** argv) {
    ArbolBinario arbol;
    construir(arbol);
    plantarArbolBinario(arbol.raiz,nullptr,"Tiene tos seca?",50,2,nullptr);
    plantarArbolBinario(arbol.raiz->izquierda,nullptr,"Tiene fiebre?",30,1,nullptr);
    plantarArbolBinario(arbol.raiz->derecha,nullptr,"Tiene tos con flema?",70,0,nullptr);
    plantarArbolBinario(arbol.raiz->izquierda->derecha,nullptr,"Le duele la garganta?",40,0,nullptr);
    plantarArbolBinario(arbol.raiz->izquierda->izquierda,nullptr,"Le falta aire?",20,1,nullptr);
    plantarArbolBinario(arbol.raiz->izquierda->izquierda->izquierda,nullptr,"Riesgo de Covid",10,1,nullptr);
    plantarArbolBinario(arbol.raiz->izquierda->izquierda->derecha,nullptr,"Debe estar en observacion",25,0,nullptr);
    plantarArbolBinario(arbol.raiz->derecha->izquierda,nullptr,"Tiene gripe, cuidese",60,1,nullptr);
    plantarArbolBinario(arbol.raiz->derecha->izquierda,nullptr,"No tiene nada, cuidese",80,0,nullptr);
    plantarArbolBinario(arbol.raiz->izquierda->derecha->izquierda,nullptr,"Debe estar en observacion",35,1,nullptr);
    plantarArbolBinario(arbol.raiz->izquierda->derecha->derecha,nullptr,"No hay riesgo",45,0,nullptr);
    consultar(arbol.raiz);
    return 0;
}

