

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 4 de noviembre de 2024, 10:23 PM
 */

#include <iostream>
#include <iomanip>

#include "ArbolBinario.h"
#include "ArbolBinarioBusqueda.h"
#include "funcionesABB.h"
using namespace std;


int main(int argc, char** argv) {
    ArbolBinarioBusqueda arbol;
    construir(arbol);
    Elemento dato;
    dato.dato=10;
    plantarArbolBB(arbol.arbolBinario.raiz,nullptr,dato,nullptr);
    
    

    return 0;
}

