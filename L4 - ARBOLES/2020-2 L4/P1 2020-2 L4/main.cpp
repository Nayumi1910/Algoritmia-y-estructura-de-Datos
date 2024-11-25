

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 6 de noviembre de 2024, 03:38 PM
 */

#include <iostream>
#include <iomanip>

#include "ArbolBinario.h"
#include "funcionesArbolesBinarios.h"
using namespace std;
void despacharArboles(NodoArbol *nodo,int &num){
    if(esNodoVacio(nodo) or num<=0)return;
    despacharArboles(nodo->izquierda,num);
    if(num>0){
        if(nodo->elemento.cant<=num){
            num-=nodo->elemento.cant;
            nodo->elemento.cant=0;
        }else{
            nodo->elemento.cant-=num;
            num=0;
        }
    }
//    cout<<num<<endl;
    despacharArboles(nodo->derecha,num);
}
void despachar(ArbolBinario &arbol,int num){
    despacharArboles(arbol.raiz,num);
}
void incrementarArbol(NodoArbol *nodo,int lote,int cant){
    if(esNodoVacio(nodo)){
        return;
    }
    incrementarArbol(nodo->izquierda,lote,cant);
    if(nodo->elemento.dato==lote){
        nodo->elemento.cant+=cant;
    }
    incrementarArbol(nodo->derecha,lote,cant);
}
int existeNodo(NodoArbol *nodo,int lote){
    if(esNodoVacio(nodo)){
        return 0;
    }
    existeNodo(nodo->izquierda,lote);
    if(nodo->elemento.dato==lote){
        return 1;
    }
    existeNodo(nodo->derecha,lote);
}
void insertarNodo(ArbolBinario &arbol,NodoArbol *nodo){
//    if(esNodoVacio(nodo)){
//        return;
//    }
    NodoArbol *aux=arbol.raiz;
    NodoArbol *ant=nullptr;
    while(aux!=nullptr){
        if(aux->elemento.cant>nodo->elemento.cant){
            ant=aux;
            aux=aux->derecha;
        }else{
            ant=aux;
            aux=aux->izquierda;
        }
    }
    if(ant->elemento.cant>nodo->elemento.cant){
        ant->derecha=nodo;
    }else{
        ant->izquierda=nodo;
    }
    
}
void ordenarArbol(ArbolBinario &arbol){
    NodoArbol *aux=arbol.raiz;
    NodoArbol *aux2;
    NodoArbol *ant=nullptr;
    if(aux->elemento.cant<aux->izquierda->elemento.cant){
        while(aux!=nullptr){
            if(aux->izquierda!=nullptr){
                ant=aux;
                aux=aux->izquierda;
            }else{
                ant=aux;
                aux=aux->derecha;
            }
        }
    }else{
        while(aux!=nullptr){
            if(aux->derecha!=nullptr){
                ant=aux;
                aux=aux->derecha;
            }else{
                ant=aux;
                aux=aux->izquierda;
            }
        }
    }
    Elemento auxDato=ant->elemento;
    ant->elemento.cant=arbol.raiz->elemento.cant;
    ant->elemento.dato=arbol.raiz->elemento.dato;
    arbol.raiz->elemento.cant=auxDato.cant;
    arbol.raiz->elemento.dato=auxDato.dato;

}
void incrementar(ArbolBinario &arbol,int lote,int cant){
    if(existeNodo(arbol.raiz,lote)){
        incrementarArbol(arbol.raiz,lote,cant);
        ordenarArbol(arbol);
    }else{
        Elemento dato;
        dato.dato=lote;
        dato.cant=cant;
        NodoArbol *nodo=crearNuevoNodoArbol(nullptr,dato,nullptr);
        insertarNodo(arbol,nodo);
    }
    
    
}
//void equilibrar(ArbolBinario &arbol){
//    
//}
int main(int argc, char** argv) {
    ArbolBinario arbol;
    construir(arbol);
    NodoArbol *a,*b,*c,*d,*e;
    Elemento dato;
    dato.cant=10;
    dato.dato=4;
    a=crearNuevoNodoArbol(nullptr,dato,nullptr);
    dato.cant=14;
    dato.dato=7;
    b=crearNuevoNodoArbol(a,dato,nullptr);
    dato.cant=15;
    dato.dato=3;
    c=crearNuevoNodoArbol(b,dato,nullptr);   
    dato.cant=8;
    dato.dato=6;
    d=crearNuevoNodoArbol(nullptr,dato,nullptr);
    dato.cant=3;
    dato.dato=5;
    e=crearNuevoNodoArbol(nullptr,dato,d);
    dato.cant=10;
    dato.dato=1;
    plantarArbolBinario(arbol,e,dato,c);
    cout<<"Arbol inicial: ";
    recorrerPreOrden(arbol);
    cout<<endl;
//    despachar(arbol,12);
//    cout<<"Arbol despachado: ";
//    recorrerPreOrden(arbol);
//    cout<<endl;
//    incrementar(arbol,1,6);
//    cout<<"Arbol incrementado: ";
//    recorrerPreOrden(arbol);
//    cout<<endl;
//    equilibrar(arbol);
//    cout<<"Arbol equilibrado: ";
//    recorrerPreOrden(arbol);
//    cout<<endl;
    
    return 0;
}

