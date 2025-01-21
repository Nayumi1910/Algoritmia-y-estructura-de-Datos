

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 5 de diciembre de 2024, 10:27 AM
 */

#include <iostream>
#include <iomanip>

#include "ArbolBB.h"
#include "funcionesABB.h"
#include "funcionesAB.h"
using namespace std;

double cancularDensidad(ArbolBinarioBusqueda &arbol){
    int alt=altura(arbol.arbolBinario);
    int num=numeroNodos(arbol.arbolBinario);
    return (double)(num)/alt;
}
int main(int argc, char** argv) {
    ArbolBinarioBusqueda arbol;
    construir(arbol);
    insertar(arbol,2);
    insertar(arbol,5);
    insertar(arbol,8);
    insertar(arbol,1);
    insertar(arbol,6);
    
    double densidad=cancularDensidad(arbol);
    cout<<"La densidad es: "<<densidad<<endl;

    return 0;
}

