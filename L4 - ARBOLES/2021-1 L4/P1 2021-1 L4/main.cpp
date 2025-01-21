

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
#include "Lista.h"
#include "funcionesLista.h"
#include "Nodo.h"
using namespace std;
NodoArbol *obtenerNodoMenor(NodoArbol *arbol){
    while(arbol!=nullptr and (arbol->izquierda!=nullptr or arbol->derecha!=nullptr)){
        if(arbol->izquierda!=nullptr){
            arbol=arbol->izquierda;
        }else{
            arbol=arbol->derecha;
        }
    }
    return arbol;
}
void despacharLote(ArbolBinarioBusqueda &arbol,int n, Lista &lista){
    int i=0;
    while(i<n){
        NodoArbol *nodoMenor=obtenerNodoMenor(arbol.arbolBinario.raiz);
        if(nodoMenor==nullptr){
            break;
        }
        insertarAlFinal(lista,nodoMenor->elemento);
        eliminarNodo(arbol,nodoMenor->elemento);
        i++;
    }
}
int main(int argc, char** argv) {
    Lista lista;
    construir(lista);
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
    int n=2;
    cout<<"Se despachan"<<n<<"productos: ";
    despacharLote(arbol,n,lista);
    cout<<endl;
    cout<<"Arbol despues del despacho: ";
    recorrerPreOrden(arbol.arbolBinario);
    cout<<endl;
    return 0;
}

