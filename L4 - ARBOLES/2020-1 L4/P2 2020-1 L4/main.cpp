

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 4 de noviembre de 2024, 10:39 PM
 */

#include <iostream>
#include <iomanip>

#include "ArbolBinarioBusqueda.h"
#include "funcionesABB.h"
#include "funcionesArbolesBinarios.h"
using namespace std;
int existe(NodoArbol *nodo,Elemento dato){
    if(nodo==nullptr)return 0;
    if(nodo->elemento.dato==dato.dato){
        nodo->elemento.cant+=dato.cant;
        return 1;
    }
    if(dato.dato<nodo->elemento.dato){
        return existe(nodo->izquierda,dato);
    }else{
        return existe(nodo->derecha,dato);
    }
}
void fusionarAux(ArbolBinarioBusqueda &destino,NodoArbol *nodo){
    if(nodo==nullptr){
        return;
    }
    fusionarAux(destino,nodo->izquierda);
    if(!existe(destino.arbolBinario.raiz,nodo->elemento)){
        insertar(destino,nodo->elemento);
    }
    fusionarAux(destino,nodo->derecha);
}

void fusionarAlmacenes(ArbolBinarioBusqueda &destino,ArbolBinarioBusqueda &emisor){
    fusionarAux(destino,emisor.arbolBinario.raiz);
}

int main(int argc, char** argv) {
    ArbolBinarioBusqueda arbol1,arbol2;
    construir(arbol1);
    construir(arbol2);
    Elemento dato;
    dato.dato=20170620;
    dato.cant=20;
    insertar(arbol1,dato);
    dato.dato=20170810;
    dato.cant=20;
    insertar(arbol1,dato);
    dato.dato=20180211;
    dato.cant=20;
    insertar(arbol1,dato);
    dato.dato=20180409;
    dato.cant=10;
    insertar(arbol1,dato);
    dato.dato=20170811;
    dato.cant=5;
    insertar(arbol2,dato);
    dato.dato=20180211;
    dato.cant=10;
    insertar(arbol2,dato);
    dato.dato=20180410;
    dato.cant=15;
    insertar(arbol2,dato);
    
    cout<<"Arbol 1:";
    recorrerEnOrden(arbol1.arbolBinario);
    cout<<endl;
    cout<<"Arbol 2:";
    recorrerEnOrden(arbol2.arbolBinario);
    cout<<endl;
    
    int num1=numeroNodos(arbol1.arbolBinario);
    int num2=numeroNodos(arbol2.arbolBinario);
    cout<<num1<<" "<<num2<<endl;
    cout<<"Arbol destino:";
    if(num1>num2){
        fusionarAlmacenes(arbol1,arbol2);
        recorrerEnOrden(arbol1.arbolBinario);
    cout<<endl;
    }else{
        fusionarAlmacenes(arbol2,arbol1);
        recorrerEnOrden(arbol2.arbolBinario);
    }
    return 0;
}

