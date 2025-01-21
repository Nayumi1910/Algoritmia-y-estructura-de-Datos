

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 1 de diciembre de 2024, 10:37 PM
 */

#include <iostream>
#include <iomanip>

#include "ArbolBinario.h"
#include "funcionesArbolesBinarios.h"
#include "Cola.h"
#include "funcionesCola.h"
using namespace std;
struct NodoArbol * crearNuevoNodoArbol_New(struct NodoArbol * arbolIzquierdo, 
                               int elemento, char servidor, struct NodoArbol * arbolDerecho){
    struct NodoArbol * nuevoNodo = new struct NodoArbol;
    nuevoNodo->elemento = elemento;
    nuevoNodo->servidor = servidor;
    nuevoNodo->izquierda = arbolIzquierdo;
    nuevoNodo->derecha = arbolDerecho;
    return nuevoNodo;
}

void plantarArbolBinario_New(struct NodoArbol *&raiz, struct NodoArbol * arbolIzquierdo,
                         int elemento, char servidor, struct NodoArbol * arbolDerecho){
    struct NodoArbol * nuevoNodo = crearNuevoNodoArbol_New(arbolIzquierdo, elemento, servidor, arbolDerecho);
    raiz = nuevoNodo;
}
int seEncuentraSkynerd(ArbolBinario &arbol){
    Cola cola;
    construir(cola);
    encolarNew(cola,arbol.raiz);
    int nivel=0,resultado=-1;
    while(!esColaVacia(cola)){
        int n=longitud(cola);
        cout<<"Nivel "<<nivel<<" : ";
        for(int i=0;i<n;i++){
            NodoArbol *nodo=desencolarNew(cola);
            imprimeNodo(nodo);
            if (nodo->elemento==200){
            /*Vamos a evaluar si uno de los hijos es Skynerd*/
                if (!esNodoVacio(nodo->izquierda)){
                    if (nodo->izquierda->servidor=='S' && nodo->izquierda->elemento==200){
                        resultado=nivel+1;
                    }
                    else {
                       encolarNew(cola,nodo->izquierda); 
                    }
                }
                if (!esNodoVacio(nodo->derecha)){
                    if (nodo->derecha->servidor=='S' && nodo->derecha->elemento==200){
                        resultado=nivel+1;
                    }
                    else {
                       encolarNew(cola, nodo->derecha); 
                    }
                }
            }
            if(nodo->izquierda!=nullptr){
                encolarNew(cola,nodo->izquierda);
            }
            if(nodo->derecha!=nullptr){
                encolarNew(cola,nodo->derecha);
            }

        }
        nivel++;
        cout<<endl;
    }
    return resultado;
}
int main(int argc, char** argv) {
    ArbolBinario arbol;
    construir(arbol);
    plantarArbolBinario_New(arbol.raiz,nullptr,100,'Z',nullptr);
    plantarArbolBinario_New(arbol.raiz->izquierda,nullptr,50,'Z',nullptr);
    plantarArbolBinario_New(arbol.raiz->derecha,nullptr,200,'E',nullptr);
    plantarArbolBinario_New(arbol.raiz->izquierda->izquierda,nullptr,100,'E',nullptr);
    plantarArbolBinario_New(arbol.raiz->izquierda->derecha,nullptr,50,'S',nullptr);
    plantarArbolBinario_New(arbol.raiz->derecha->izquierda,nullptr,200,'S',nullptr);
    plantarArbolBinario_New(arbol.raiz->derecha->derecha,nullptr,150,'S',nullptr);
    plantarArbolBinario_New(arbol.raiz->izquierda->izquierda->izquierda,nullptr,50,'S',nullptr);
    plantarArbolBinario_New(arbol.raiz->izquierda->izquierda->derecha,nullptr,200,'Z',nullptr);
    plantarArbolBinario_New(arbol.raiz->derecha->izquierda->izquierda,nullptr,100,'S',nullptr);
    plantarArbolBinario_New(arbol.raiz->derecha->izquierda->derecha,nullptr,200,'E',nullptr);
    plantarArbolBinario_New(arbol.raiz->izquierda->izquierda->izquierda->izquierda,nullptr,50,'E',nullptr);
    plantarArbolBinario_New(arbol.raiz->izquierda->izquierda->derecha->izquierda,nullptr,100,'E',nullptr);
    int nivel=seEncuentraSkynerd(arbol);
    if(nivel!=-1)cout<<"Se encuentras en el nivel: "<<nivel<<endl;
    else cout<<"No se encuentra"<<endl;
    return 0;
}

