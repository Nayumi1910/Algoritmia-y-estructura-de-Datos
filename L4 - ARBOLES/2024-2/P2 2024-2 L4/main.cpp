

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 6 de diciembre de 2024, 06:26 PM
 */

#include <iostream>
#include <iomanip>

#include "ArbolBB.h"
#include "funcionesABB.h"
#include "Cola.h"
#include "funcionesCola.h"
using namespace std;
int existe(NodoArbol *nodo,int time,int cant){
    if(nodo==nullptr)return 0;
    if(nodo->elemento==time){
        nodo->cantidad+=cant;
        return 1;
    }
    if(nodo->elemento>time){
        return existe(nodo->izquierda,time,cant);
    }else{
        return existe(nodo->derecha,time,cant);
    }
}
void ingresar_lote(ArbolBinarioBusqueda &lotes,int time,int cant){
    if(lotes.arbolBinario.raiz==nullptr){
        insertar(lotes,time,cant);
    }
    if(existe(lotes.arbolBinario.raiz,time,cant)==0){
        insertar(lotes,time,cant);
    }
}
NodoArbol *buscarNodoActual(NodoArbol *nodo,Elemento dato){
    if(nodo==nullptr)return nullptr;
    if(nodo->elemento==dato.age){
        return nodo;
    }
    if(nodo->elemento>dato.age){
        return buscarNodoActual(nodo->izquierda,dato);
    }else{
        return buscarNodoActual(nodo->derecha,dato);
    }
}
void imprimirAmplitud(NodoArbol *nodo){
    Cola cola;
    construir(cola);
    Elemento dato;
    dato.age=nodo->elemento;
    dato.cant=nodo->cantidad;
    encolar(cola,dato);
    int cant=0;
    while(!esColaVacia(cola)){
        int n=longitud(cola);
        Elemento aux1,aux2;
        cout<<"Nivel "<<cant<<" :";
        for(int i=0;i<n;i++){
            dato=desencolar(cola);
            NodoArbol *nodoActual=buscarNodoActual(nodo,dato);
            cout<<dato.age<<"-"<<dato.cant<<" ";
            if(nodoActual->izquierda!=nullptr){
                aux1.age=nodoActual->izquierda->elemento;
                aux1.cant=nodoActual->izquierda->cantidad;
                encolar(cola,aux1);
            }
            if(nodoActual->derecha!=nullptr){
                aux2.age=nodoActual->derecha->elemento;
                aux2.cant=nodoActual->derecha->cantidad;
                encolar(cola,aux2);
            }
        }
        cout<<endl;
        cant++;
    }
    
}
void ImprimirDescendente(NodoArbol *nodo){
    Cola cola;
    construir(cola);
    Elemento dato;
    NodoArbol *actual=nodo;
    while(actual!=nullptr or !esColaVacia(cola)){
        if(actual!=nullptr){
            dato.age=actual->elemento;
            dato.cant=actual->cantidad;
            encolar(cola,dato);
            actual=actual->derecha;
        }else{
            dato=desencolar(cola);
            actual=buscarNodoActual(nodo,dato);
            cout<<dato.age<<"-"<<dato.cant<<" ";
            actual=actual->izquierda;
        }
    }
    cout<<endl;
}
int main(int argc, char** argv) {
    ArbolBinarioBusqueda lotes;
    construir(lotes);
    //arbol inicial
    ingresar_lote(lotes,2018,100);
    ingresar_lote(lotes,2011,150);
    ingresar_lote(lotes,2022,50);
    ingresar_lote(lotes,2010,175);
    ingresar_lote(lotes,2017,25);
    ingresar_lote(lotes,2022,50);
    ingresar_lote(lotes,2019,125);
    ingresar_lote(lotes,2023,200);
    ingresar_lote(lotes,2020,75);
    imprimirAmplitud(lotes.arbolBinario.raiz);
    ImprimirDescendente(lotes.arbolBinario.raiz);
    return 0;
}

