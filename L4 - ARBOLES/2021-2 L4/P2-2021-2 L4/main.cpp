

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 25 de noviembre de 2024, 07:32 PM
 */

#include <iostream>
#include <iomanip>

#include "ArbolBinarioBusqueda.h"
#include "funcionesArbolesBB.h"
#include "funcionesArbolesBinarios.h"
using namespace std;

ArbolBinarioBusqueda rotarDerecha(ArbolBinarioBusqueda &arbol){
    ArbolBinarioBusqueda izq;
    izq.arbolBinario.raiz=arbol.arbolBinario.raiz->izquierda;
    arbol.arbolBinario.raiz->izquierda=izq.arbolBinario.raiz->derecha;
    izq.arbolBinario.raiz->derecha=arbol.arbolBinario.raiz;
    return izq;
}
ArbolBinarioBusqueda rotarIzquierda(ArbolBinarioBusqueda &arbol) {
    ArbolBinarioBusqueda der;
    der.arbolBinario.raiz = arbol.arbolBinario.raiz->derecha;
    arbol.arbolBinario.raiz->derecha = der.arbolBinario.raiz->izquierda;
    der.arbolBinario.raiz->izquierda = arbol.arbolBinario.raiz;
    return der;
}
int alturaRecursivoN(NodoArbol* nodo) {
    if (nodo == nullptr)
        return 0;
    return 1 + max(alturaRecursivo(nodo->izquierda), alturaRecursivo(nodo->derecha));
}

bool esEquilibradoRecursivoN(NodoArbol* nodo, int& altura) {
    if (nodo == nullptr) {
        altura = 0;
        return true;
    }

    int alturaIzquierda = 0, alturaDerecha = 0;
    bool equilibradoIzquierda = esEquilibradoRecursivoN(nodo->izquierda, alturaIzquierda);
    bool equilibradoDerecha = esEquilibradoRecursivoN(nodo->derecha, alturaDerecha);

    altura = 1 + max(alturaIzquierda, alturaDerecha);
    return equilibradoIzquierda && equilibradoDerecha && abs(alturaIzquierda - alturaDerecha) <= 1;
}

int esEquilibradoN(const ArbolBinario& arbol) {
    int altura = 0;
    return esEquilibradoRecursivoN(arbol.raiz, altura);
}

int alturaN(const ArbolBinario& arbol) {
    return alturaRecursivoN(arbol.raiz);
}
ArbolBinarioBusqueda balancear(ArbolBinarioBusqueda &arbol){
    ArbolBinarioBusqueda origen,pariente;
    int esBalanceado=0,menorNivel=0;
    origen=arbol;
    while(!esBalanceado){
        if(esEquilibradoN(arbol.arbolBinario)>1 or 
                (esEquilibradoN(arbol.arbolBinario)==1 and 
                numeroNodosRecursivo(arbol.arbolBinario.raiz->izquierda)
                >numeroNodosRecursivo(arbol.arbolBinario.raiz->derecha))){
            arbol=rotarDerecha(arbol);
            if(!menorNivel){
                origen=arbol;
            }else{
                pariente.arbolBinario.raiz->izquierda=arbol.arbolBinario.raiz;
            }
            if(esEquilibradoN(origen.arbolBinario)==0){
                esBalanceado=1;
            }
        }else if(esEquilibradoN(arbol.arbolBinario)<-1 or
                (esEquilibradoN(arbol.arbolBinario)==-1 and
        numeroNodosRecursivo(arbol.arbolBinario.raiz->derecha)>
        numeroNodosRecursivo(arbol.arbolBinario.raiz->izquierda))){
            arbol=rotarIzquierda(arbol);
            if(!menorNivel){
                origen=arbol;
            }else{
                pariente.arbolBinario.raiz->derecha=arbol.arbolBinario.raiz;
            }
            if(esEquilibradoN(arbol.arbolBinario)==0){
                esBalanceado=1;
            }
        }else if(esEquilibradoN(arbol.arbolBinario)==-1 and 
                (numeroNodosRecursivo(arbol.arbolBinario.raiz->izquierda)
                ==numeroNodosRecursivo(arbol.arbolBinario.raiz->derecha))){
            pariente=arbol;
            arbol.arbolBinario.raiz=arbol.arbolBinario.raiz->derecha;
            menorNivel=1;
        }
    }
    arbol=origen;
    return arbol;
}

//ArbolBinarioBusqueda balancearRecursivo(ArbolBinarioBusqueda &arbol) {
//    if (esNodoVacio(arbol.arbolBinario.raiz)) return arbol;
//
//    // Balancear subárbol izquierdo y derecho
//    ArbolBinarioBusqueda subIzq, subDer;
//    subIzq.arbolBinario.raiz = arbol.arbolBinario.raiz->izquierda;
//    subDer.arbolBinario.raiz = arbol.arbolBinario.raiz->derecha;
//
//    subIzq = balancearRecursivo(subIzq);
//    subDer = balancearRecursivo(subDer);
//
//    arbol.arbolBinario.raiz->izquierda = subIzq.arbolBinario.raiz;
//    arbol.arbolBinario.raiz->derecha = subDer.arbolBinario.raiz;
//
//    // Calcular equilibrio
//    int balance = alturaN(subIzq.arbolBinario) - alturaN(subDer.arbolBinario);
//
//    // Caso 1: Rotación derecha
//    if (balance > 1 && alturaRecursivoN(subIzq.arbolBinario.raiz->izquierda) >= alturaRecursivoN(subIzq.arbolBinario.raiz->derecha)) {
//        return rotarDerecha(arbol);
//    }
//    // Caso 2: Rotación izquierda
//    if (balance < -1 && alturaRecursivoN(subDer.arbolBinario.raiz->derecha) >= alturaRecursivoN(subDer.arbolBinario.raiz->izquierda)) {
//        return rotarIzquierda(arbol);
//    }
//    // Caso 3: Rotación doble derecha-izquierda
//    if (balance > 1 && alturaRecursivoN(subIzq.arbolBinario.raiz->izquierda) < alturaRecursivoN(subIzq.arbolBinario.raiz->derecha)) {
//        subIzq = rotarIzquierda(subIzq);
//        arbol.arbolBinario.raiz->izquierda = subIzq.arbolBinario.raiz;
//        return rotarDerecha(arbol);
//    }
//    // Caso 4: Rotación doble izquierda-derecha
//    if (balance < -1 && alturaRecursivoN(subDer.arbolBinario.raiz->derecha) < alturaRecursivoN(subDer.arbolBinario.raiz->izquierda)) {
//        subDer = rotarDerecha(subDer);
//        arbol.arbolBinario.raiz->derecha = subDer.arbolBinario.raiz;
//        return rotarIzquierda(arbol);
//    }
//
//    return arbol; // Ya está balanceado
//}
//
//// Función general para balancear un árbol
//ArbolBinarioBusqueda balancear(ArbolBinarioBusqueda &arbol) {
//    return balancearRecursivo(arbol);
//}

int main(int argc, char** argv) {
    ArbolBinarioBusqueda arbol;
    construir(arbol);
    insertar(arbol,190,'A');
    insertar(arbol,180,'C');
    insertar(arbol,150,'G');
    insertar(arbol,100,'M');
    insertar(arbol,20,'Q');
    insertar(arbol,140,'P');
    insertar(arbol,210,'B');
    cout<<"Arbol inicial: ";
    recorrerPreOrden(arbol.arbolBinario);
    cout<<endl;
    arbol=balancear(arbol);
    cout<<"Arbol balanceado: ";
    recorrerPreOrden(arbol.arbolBinario);
    return 0;
}

