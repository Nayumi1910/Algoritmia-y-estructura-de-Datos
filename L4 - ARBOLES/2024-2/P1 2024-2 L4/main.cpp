

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 6 de diciembre de 2024, 05:56 PM
 */

#include <iostream>
#include <iomanip>

#include "ArbolB.h"
#include "funcionesAB.h"
using namespace std;

void imprimirPalabras(NodoArbol *nodo,char *palabraActual,int pos){
    if(nodo==nullptr)return;
    palabraActual[pos]=nodo->elemento;
    pos++;
    if(nodo->izquierda==nullptr and nodo->derecha==nullptr){
        palabraActual[pos]='\0';
        cout<<palabraActual<<endl;
        return;
    }
    imprimirPalabras(nodo->izquierda,palabraActual,pos);
    imprimirPalabras(nodo->derecha,palabraActual,pos);
}

int main(int argc, char** argv) {
    ArbolBinario arbol, arboles[18];
    construir(arbol);
    for(int i=0;i<18;i++)construir(arboles[i]);
    //PARTE A
    //Se insertara los nodos
    plantarArbolBinario(arboles[0],nullptr,'O',nullptr);
    plantarArbolBinario(arboles[1],nullptr,'S',nullptr);
    plantarArbolBinario(arboles[2],nullptr,'S',nullptr);
    plantarArbolBinario(arboles[3],arboles[0].raiz,'A',nullptr);
    plantarArbolBinario(arboles[4],nullptr,'A',nullptr);
    plantarArbolBinario(arboles[5],nullptr,'O',arboles[1].raiz);
    plantarArbolBinario(arboles[6],nullptr,'A',nullptr);
    plantarArbolBinario(arboles[7],nullptr,'O',arboles[2].raiz);
    plantarArbolBinario(arboles[8],nullptr,'N',nullptr);
    plantarArbolBinario(arboles[9],arboles[3].raiz,'B',nullptr);
    plantarArbolBinario(arboles[10],arboles[4].raiz,'N',arboles[5].raiz);
    plantarArbolBinario(arboles[11],arboles[6].raiz,'R',arboles[7].raiz);
    plantarArbolBinario(arboles[12],arboles[8].raiz,'E',nullptr);
    plantarArbolBinario(arboles[13],arboles[9].raiz,'L',nullptr);
    plantarArbolBinario(arboles[14],arboles[10].raiz,'E',nullptr);
    plantarArbolBinario(arboles[15],nullptr,'R',arboles[11].raiz);
    plantarArbolBinario(arboles[16],arboles[12].raiz,'I',arboles[13].raiz);
    plantarArbolBinario(arboles[17],arboles[14].raiz,'U',arboles[15].raiz);
    plantarArbolBinario(arbol,arboles[16].raiz,'B',arboles[17].raiz);
    char palabra[10];
    int pos;
    imprimirPalabras(arbol.raiz,palabra,0);

    return 0;
}

