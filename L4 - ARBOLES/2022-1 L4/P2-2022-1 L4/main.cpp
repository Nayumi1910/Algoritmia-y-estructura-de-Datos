

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 3 de diciembre de 2024, 11:53 AM
 */

#include <iostream>
#include <iomanip>

#include "ArbolBinario.h"
#include "funcionesArbolesBinarios.h"
#include "ArbolBinarioBusqueda.h"
#include "funcionesABB.h"
using namespace std;
struct NodoArbol * crearNuevoNodoArbol(struct NodoArbol * izquierdo, 
                               int elemento,int cant, struct NodoArbol * derecho){
    struct NodoArbol * nuevoNodo = new struct NodoArbol;
    nuevoNodo->elemento = elemento;
    nuevoNodo->cantidad=cant;
    nuevoNodo->izquierda = izquierdo;
    nuevoNodo->derecha = derecho;
    return nuevoNodo;
}

void despachar(ArbolBinarioBusqueda &arbol,int cant){
    if(esArbolVacio(arbol.arbolBinario))return;
    int resto=0;
    while(1){
        NodoArbol *aux=minimoArbol(arbol.arbolBinario.raiz);
//        imprimeNodo(aux);
//        cout<<endl;
        if(resto==0 ){
            if(aux->cantidad==cant){
                eliminarNodo(arbol,aux->elemento);
            }else{
                if(aux->cantidad>cant){
                    aux->cantidad-=cant;
                }else{
                    resto=cant-aux->cantidad;
                    eliminarNodo(arbol,aux->elemento);  
                }
            }
        }else{
            if(aux->cantidad==resto){
                eliminarNodo(arbol,aux->elemento);
                resto=0;
            }else{
                if(aux->cantidad>resto){
                    aux->cantidad-=resto;
                    resto=0;
                }else{
                    resto=resto-aux->cantidad;
                    eliminarNodo(arbol,aux->elemento);
                }
            }
        }
        if(resto==0 )break;
    }
}
int main(int argc, char** argv) {
    ArbolBinarioBusqueda arbol;
    construir(arbol);
    insertar(arbol,20220815,40);
    insertar(arbol,20220930,30);
    insertar(arbol,20220710,50);
    insertar(arbol,20220720,50);
    insertar(arbol,20220630,50);
    insertar(arbol,20220624,40);
    insertar(arbol,20220615,40);
    insertar(arbol,20220618,40);
    cout<<"Arbol: ";
    recorrerPreOrden(arbol.arbolBinario);
    cout<<endl;
    int d1=20;
    despachar(arbol,d1);
    cout<<"Arbol 1: ";
    recorrerPreOrden(arbol.arbolBinario);
    cout<<endl;
    int d2=40;
    despachar(arbol,d2);
    cout<<"Arbol 2: ";
    recorrerPreOrden(arbol.arbolBinario);
    cout<<endl;
    int d3=200;
    despachar(arbol,d3);
    cout<<"Arbol 3: ";
    recorrerPreOrden(arbol.arbolBinario);
    cout<<endl;
    return 0;
}

