// -*- C++ -*-

/* 
 * File:   funcionesABB.h
 * Author: ANA RONCAL
 *
 * Created on 30 de mayo de 2024, 15:54
 */

#ifndef FUNCIONESABB_H
#define FUNCIONESABB_H
#include "NodoArbol.h"
#include "Nodo.h"
void construir(struct ArbolBinarioBusqueda & arbol);
void insertar(struct ArbolBinarioBusqueda & arbol, Elemento elemento);
void insertarRecursivo(struct NodoArbol *& nodo, Elemento elemento);
void enOrden(const struct ArbolBinarioBusqueda & arbol);
void plantarArbolBB(struct NodoArbol *& nodo, struct NodoArbol * arbolIzquierdo,
         Elemento elemento, struct NodoArbol * arbolDerecha);
bool buscaArbol(const struct ArbolBinarioBusqueda & arbol, Elemento dato);
bool buscaArbolRecursivo(struct NodoArbol * nodo, Elemento dato);
int comparaABB(Elemento elementoA, Elemento elementoB);
void eliminarNodo(struct ArbolBinarioBusqueda & arbol, Elemento dato);
struct NodoArbol * eliminarNodoRecursivo(struct NodoArbol * nodo, Elemento elemento);
void destruirArbolBB(struct ArbolBinarioBusqueda & arbol);
#endif /* FUNCIONESABB_H */