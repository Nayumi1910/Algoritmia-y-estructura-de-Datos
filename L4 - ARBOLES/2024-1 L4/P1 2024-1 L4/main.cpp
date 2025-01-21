

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 1 de diciembre de 2024, 03:24 PM
 */

#include <iostream>
#include <iomanip>

#include "ArbolB.h"
#include "ArbolBB.h"
#include "funcionesAB.h"
#include "funcionesABB.h"
using namespace std;
struct NodoArbol * crearNuevoNodoN(struct NodoArbol * izquierda, int elemento,
        struct NodoArbol * derecha) {

    struct NodoArbol * nuevo = new struct NodoArbol;
    nuevo->derecha = derecha;
    nuevo->izquierda = izquierda;
    nuevo->elemento = elemento;
    return nuevo;
}
void aplicarArbolResultante(NodoArbol *paquete, NodoArbol *sistema,
        NodoArbol *&resultado){
    if(paquete==nullptr or sistema==nullptr)return;
    int num=numeroHojasRecursivo(sistema);
    int result;
    result=paquete->elemento+numeroNodosRecursivo(sistema)-num;
    resultado=crearNuevoNodoN(nullptr,result,nullptr);
    aplicarArbolResultante(paquete->izquierda,sistema->izquierda,
            resultado->izquierda);
    aplicarArbolResultante(paquete->derecha,sistema->derecha,
            resultado->derecha);
    
}
ArbolBinario aplicar_arbol(ArbolBinarioBusqueda &arbol_paquetes,
            ArbolBinario &arbol_sistema){
    ArbolBinario resultado;
    aplicarArbolResultante(arbol_paquetes.arbolBinario.raiz,
            arbol_sistema.raiz,resultado.raiz);
    return resultado;
}
int esABB(NodoArbol *nodo, int min=-10000, int max=10000){
    if(nodo==nullptr)return 1;
    if(nodo->elemento<=min and nodo->elemento>=max)return 0;
    return esABB(nodo->izquierda,min,nodo->elemento)and
            esABB(nodo->derecha,nodo->elemento,max);
    
}
int sumaNodos(NodoArbol *nodo){
    if(nodo==nullptr)return 0;
    return nodo->elemento+sumaNodos(nodo->derecha) + sumaNodos(nodo->izquierda);
}
int determinar_anomalia(ArbolBinario &arbol){
    if(esArbolVacio(arbol))return 0;
    return esABB(arbol.raiz) and (sumaNodos(arbol.raiz)%2==0);
}
int main(int argc, char** argv) {
    ArbolBinarioBusqueda arbol_paquetes;
    construir(arbol_paquetes);
    ArbolBinario arbol_sistema,arboles[4];
    for(int i=0;i<4;i++)construir(arboles[i]);
    construir(arbol_sistema);
    //arboles de paquetes
    insertar(arbol_paquetes,6);
    insertar(arbol_paquetes,3);
    insertar(arbol_paquetes,9);
    cout<<"Arbol de paquetes: ";
    recorrerPreOrden(arbol_paquetes.arbolBinario);
    cout<<endl;
    //arboles de sistema
    plantarArbolBinario(arboles[0],nullptr,2,nullptr);
    plantarArbolBinario(arboles[1],nullptr,3,nullptr);
    plantarArbolBinario(arboles[2],arboles[0],7,arboles[1]);
    plantarArbolBinario(arboles[3],nullptr,8,nullptr);
    plantarArbolBinario(arbol_sistema,arboles[2],1,arboles[3]);
    cout<<"Arboles de sistema: ";
    recorrerPreOrden(arbol_sistema);
    cout<<endl;
    ArbolBinario arbol_resultado=aplicar_arbol(arbol_paquetes,
            arbol_sistema);
    cout<<"Arbol resultado: ";
    recorrerPreOrden(arbol_resultado);
    cout<<endl;
    if(!determinar_anomalia(arbol_resultado)){
        cout<<"Anomalia detectada"<<endl;
    }else{
        cout<<"Sin eventos sospechosos"<<endl;
    }
    return 0;
}

