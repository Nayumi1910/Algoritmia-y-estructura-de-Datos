/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 30 de mayo de 2025, 05:05 PM
 */

#include <iostream>
#include "ArbolBinarioBusqueda.h"
using namespace std;
#include "funcionesABB.h"

/*
 * ESTRUCTURA ÁRBOL BINARIO 2024-1
 */
int main(int argc, char** argv) {

    struct ArbolBinarioBusqueda arbol;

    construir(arbol);
    Elemento dato;
    dato.dato=100;
    insertar(arbol, dato);
    dato.dato=50;
    insertar(arbol, dato);
    dato.dato=200;
    insertar(arbol, dato);
    dato.dato=30;
    insertar(arbol, dato);
    dato.dato=75;
    insertar(arbol, dato);
    dato.dato=201;
    insertar(arbol, dato);
    dato.dato=1500;
    insertar(arbol, dato);
    dato.dato=150;
    insertar(arbol, dato);
    
    enOrden(arbol);
    cout << endl;
    dato.dato=201;
    cout <<"Se encuentra 201 en el árbol: "<<buscaArbol(arbol, dato)<<endl;
    dato.dato=100;
    eliminarNodo(arbol, dato);
    cout <<"Se encuentra 100 en el árbol: "<<buscaArbol(arbol, dato)<<endl;
    enOrden(arbol);
    
    destruirArbolBB(arbol);
   
    return 0;
}

