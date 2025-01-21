/* 
 * File:   funcionesABB.cpp
 * Author: ANA RONCAL
 * 
 * Created on 13 de noviembre de 2024, 13:50
 */

#include <iostream>
#include <iomanip>
#include "ArbolBB.h"
using namespace std;
#include "funcionesAB.h"
#include "funcionesABB.h"
struct NodoArbol * crearNuevoNodo(struct NodoArbol * izquierda, int elemento,int semana,int cantidad,struct NodoArbol * derecha) {

    struct NodoArbol * nuevo = new struct NodoArbol;
    nuevo->derecha = derecha;
    nuevo->izquierda = izquierda;
    nuevo->elemento = elemento;
    nuevo->semana=semana;
    nuevo->cantidad=cantidad;
    return nuevo;
}
void plantarArbolBinarioBusqueda(struct NodoArbol *& raiz, 
                    struct NodoArbol * izquierda, int elemento,
        int semana, int cantidad,
                    struct NodoArbol * derecha){
    
    struct NodoArbol * nuevoNodo = crearNuevoNodo(izquierda, elemento,semana,cantidad, derecha);
    raiz = nuevoNodo;
}
void construir(struct ArbolBinarioBusqueda & arbol){
    construir(arbol.arbolBinario);
}

void insertar(struct ArbolBinarioBusqueda & arbol, int elemento,
        int semana, int cantidad){
    insertarRecursivo(arbol.arbolBinario.raiz, elemento,
            semana,cantidad);
}

void insertarRecursivo(struct NodoArbol *& raiz, int elemento,
        int semana, int cantidad){
    if(esNodoVacio(raiz))
        plantarArbolBinarioBusqueda(raiz, nullptr, elemento,
                semana, cantidad, nullptr);
    else
        if(raiz->semana > semana)
            insertarRecursivo(raiz->izquierda, elemento,semana
                    ,cantidad);
        else
            if(raiz->semana < semana)
                insertarRecursivo(raiz->derecha, elemento,semana
                        ,cantidad);
            else if(raiz->semana==semana){
                if(raiz->cantidad>cantidad){
                    insertarRecursivo(raiz->izquierda, elemento,semana
                    ,cantidad);
                }else if(raiz->cantidad<cantidad){
                    insertarRecursivo(raiz->derecha, elemento,semana
                        ,cantidad);
                }else if(raiz->cantidad==cantidad){
                    if(raiz->elemento>elemento){
                        insertarRecursivo(raiz->izquierda, elemento,semana
                    ,cantidad);
                    }else if(raiz->elemento<elemento){
                        insertarRecursivo(raiz->derecha, elemento,semana
                        ,cantidad);
                    }else {
                        cout << "El elemento " << elemento << "Ya se encuentra en el árbol" << endl;
                    }
                }
            }
                
}

void enOrden(const struct ArbolBinarioBusqueda & arbol){
    recorrerEnOrden(arbol.arbolBinario);
}

bool buscar(const struct ArbolBinarioBusqueda & arbol, int dato){
    return buscarRecursivo(arbol.arbolBinario.raiz, dato);
}

bool buscarRecursivo(struct NodoArbol * nodo, int dato){
    if(esNodoVacio(nodo))
        return false;
    if(comparaABB(nodo->elemento, dato) == 0)
        return true;
    if(comparaABB(nodo->elemento, dato) == 1)
        return buscarRecursivo(nodo->izquierda, dato);
    else
        if(comparaABB(nodo->elemento, dato) == -1)
            return buscarRecursivo(nodo->derecha, dato);
}

int comparaABB(int elementoA, int elementoB){
    if(elementoA == elementoB) return 0;
    else if(elementoA < elementoB) return -1;
    else if(elementoA > elementoB) return 1;
}

void eliminar(struct ArbolBinarioBusqueda & arbol, int dato){
    arbol.arbolBinario.raiz = eliminarRecursivo(arbol.arbolBinario.raiz, dato);
}

struct NodoArbol * eliminarRecursivo(struct NodoArbol * nodo, int elemento){
    if(esNodoVacio(nodo))
        return nodo;
    //buscamos el nodo a eliminar
    if(nodo->elemento > elemento)
        nodo->izquierda = eliminarRecursivo(nodo->izquierda, elemento);
    else
        if(nodo->elemento < elemento)
            nodo->derecha = eliminarRecursivo(nodo->derecha, elemento);
        else
            /*encontró el elemento*/
            if(esNodoVacio(nodo->izquierda)){
                struct NodoArbol * hijo = nodo->derecha;
                delete nodo;
                return hijo;
            }
            else
                if(esNodoVacio(nodo->derecha)){
                    struct NodoArbol * hijo = nodo->izquierda;
                    delete nodo;
                    return hijo;
                }
                else{
                    /* dos hijos*/
                    struct NodoArbol * minNodo = minimoArbol(nodo->derecha);
                    nodo->elemento = minNodo->elemento;
                    nodo->derecha = eliminarRecursivo(nodo->derecha, minNodo->elemento);
                }
                    
    return nodo;           
    
}

struct NodoArbol * minimoArbol(struct NodoArbol * nodo){
    if(esNodoVacio(nodo))
        return nodo;
    if(esNodoVacio(nodo->izquierda))
        return nodo;
    return minimoArbol(nodo->izquierda);
}