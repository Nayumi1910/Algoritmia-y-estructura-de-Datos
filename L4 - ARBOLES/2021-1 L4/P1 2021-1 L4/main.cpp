

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 13 de noviembre de 2024, 12:24 PM
 */

#include <iostream>
#include <iomanip>

#include "ArbolBinarioBusqueda.h"
#include "funcionesABB.h"
#include "funcionesArbolesBinarios.h"
using namespace std;


int main(int argc, char** argv) {
    ArbolBinarioBusqueda arbol;
    construir(arbol);
    Elemento dato;
    dato.dato=10;
    dato.cant=8;
    insertar(arbol,dato);
    dato.dato=9;
    dato.cant=10;
    insertar(arbol,dato);
    dato.dato=15;
    dato.cant=20;
    insertar(arbol,dato);
    dato.dato=6;
    dato.cant=10;
    insertar(arbol,dato);
    dato.dato=12;
    dato.cant=10;
    insertar(arbol,dato);
    dato.dato=18;
    dato.cant=10;
    insertar(arbol,dato);
    dato.dato=5;
    dato.cant=20;
    insertar(arbol,dato);
    dato.dato=8;
    dato.cant=20;
    insertar(arbol,dato);
    cout<<"Arbol inicial: ";
    recorrerPreOrden(arbol.arbolBinario);
    cout<<endl;
    return 0;
}

