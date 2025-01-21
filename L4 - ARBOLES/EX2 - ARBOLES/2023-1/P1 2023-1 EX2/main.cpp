

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 6 de diciembre de 2024, 11:54 AM
 */

#include <iostream>
#include <iomanip>

#include "ArbolB.h"
#include "ArbolBB.h"
#include "funcionesAB.h"
#include "funcionesABB.h"
using namespace std;
int existe(NodoArbol *nodo,int num){
    if(nodo==nullptr)return 0;
    if(nodo->elemento==num){
        return 1;
    }
    if(nodo->elemento>num){
        return existe(nodo->izquierda,num);
    }else{
        return existe(nodo->derecha,num);
    }
}
int buscarMayor(NodoArbol *nodo){
    if(esNodoVacio(nodo))
        return nodo->elemento;
    if(esNodoVacio(nodo->derecha))
        return nodo->elemento;
    return buscarMayor(nodo->derecha);
}
void insertarArbol(ArbolBinarioBusqueda &arbol,int grupo[],int n){
    for(int i=0;i<n;i++){
        if(!existe(arbol.arbolBinario.raiz,grupo[i])){
            insertar(arbol,grupo[i]);
        }else{
            int mayor=buscarMayor(arbol.arbolBinario.raiz);
            insertar(arbol,grupo[i]+mayor);
        }
    }
}
NodoArbol *rotarDerecha(NodoArbol *nodo){
    NodoArbol *aux=nodo->izquierda;
    nodo->izquierda=aux->derecha;
    aux->derecha=nodo;
    return aux;
}
NodoArbol *rotarIzquierda(NodoArbol *nodo){
    NodoArbol *aux=nodo->derecha;
    nodo->derecha=aux->izquierda;
    aux->izquierda=nodo;
    return aux;
}
NodoArbol *rotarDobleDerecha(NodoArbol *nodo){
    nodo->izquierda=rotarIzquierda(nodo->izquierda);
    return rotarDerecha(nodo);
}

NodoArbol *rotarDobleIzquierda(NodoArbol *nodo){
    nodo->derecha=rotarDerecha(nodo->derecha);
    return rotarIzquierda(nodo);
}
NodoArbol *balancearNodo(NodoArbol *nodo){
    int alturaIzq=alturaRecursivo(nodo->izquierda);
    int alturaDer=alturaRecursivo(nodo->derecha);
    int diferencia=alturaIzq-alturaDer;
    
    if(diferencia>1){
        if(alturaRecursivo(nodo->izquierda->izquierda)
                >=alturaRecursivo(nodo->izquierda->derecha)){
            nodo=rotarDerecha(nodo);
        }else{
            nodo=rotarDobleDerecha(nodo);
        }
    }else if(diferencia<-1){
        if(alturaRecursivo(nodo->derecha->derecha)>=
                alturaRecursivo(nodo->derecha->izquierda)){
            nodo=rotarIzquierda(nodo);
        }else{
            nodo=rotarDobleIzquierda(nodo);
        }
    }
    return nodo;
}
NodoArbol *balanceo(NodoArbol *nodo){
    if(nodo==nullptr)return nullptr;
    nodo->izquierda=balanceo(nodo->izquierda);
    nodo->derecha=balanceo(nodo->derecha);
    nodo=balancearNodo(nodo);
    return nodo;
    
}
void sumarArboles(NodoArbol *token,NodoArbol *sistema){
    if(sistema==nullptr)return;
    if(token==nullptr and sistema!=nullptr){
        insertarRecursivo(token,sistema->elemento);
    }
    token->elemento+=sistema->elemento;
    sumarArboles(token->izquierda,sistema->izquierda);
    sumarArboles(token->derecha,sistema->derecha);
}
int main(int argc, char** argv) {
    int grupo[8]={2,5,2,1,5,6,3,4};
    ArbolBinarioBusqueda arbol;
    construir(arbol);
    insertarArbol(arbol,grupo,8);
    cout<<"Arbol token: ";
    recorrerPreOrden(arbol.arbolBinario);
    cout<<endl;
    arbol.arbolBinario.raiz=balanceo(arbol.arbolBinario.raiz);
    cout<<"Arbol balanceado: ";
    recorrerPreOrden(arbol.arbolBinario);
    cout<<endl;
    ArbolBinarioBusqueda sistema;
    construir(sistema);
    insertar(sistema,3);
    insertar(sistema,1);
    insertar(sistema,5);
    insertar(sistema,2);
    insertar(sistema,4);
    insertar(sistema,6);
    insertar(sistema,7);
    sumarArboles(arbol.arbolBinario.raiz,sistema.arbolBinario.raiz);
    cout<<"Arbol sistema: ";
    recorrerPreOrden(sistema.arbolBinario);
    cout<<endl;
    cout<<"Arbol sumado: ";
    recorrerPreOrden(arbol.arbolBinario);
    return 0;
}

