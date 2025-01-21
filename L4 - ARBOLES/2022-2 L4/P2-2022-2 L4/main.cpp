

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 2 de diciembre de 2024, 10:37 AM
 */

#include <iostream>
#include <iomanip>

#include "ArbolBB.h"
#include "funcionesABB.h"
#include "funcionesAB.h"
using namespace std;
int existe(NodoArbol *destino,NodoArbol *emisor){
    if(destino==nullptr)return 0;
    if(destino->elemento==emisor->elemento){
        destino->cant+=emisor->cant;
        return 1;
    }
    existe(destino->izquierda,emisor);
    existe(destino->derecha,emisor);
}
void fusionarArboles(NodoArbol *destino,NodoArbol *emisor){
    if(emisor==nullptr)return;
    if(!existe(destino,emisor)){
        insertarRecursivo(destino,emisor->elemento,emisor->cant);
    }
    fusionarArboles(destino,emisor->izquierda);
    fusionarArboles(destino,emisor->derecha);
}

int main(int argc, char** argv) {
    ArbolBinarioBusqueda emisor,destino;
    construir(destino);
    construir(emisor);
    //emisor
    insertar(emisor,20170811,5);
    insertar(emisor,20180211,10);
    insertar(emisor,20180410,15);
    //destino
    insertar(destino,20170620,20);
    insertar(destino,20170810,20);
    insertar(destino,20180211,20);
    insertar(destino,20180409,10);
    
    cout<<"Emisor: "<<endl;
    cout<<"Pre orden:";
    recorrerPreOrden(emisor.arbolBinario);cout<<endl;
    cout<<"Pos orden: ";
    recorrerPostOrden(emisor.arbolBinario);cout<<endl;
    cout<<"Destino: "<<endl;
    cout<<"Pre orden:";
    recorrerPreOrden(destino.arbolBinario);cout<<endl;
    cout<<"Pos orden: ";
    recorrerPostOrden(destino.arbolBinario);cout<<endl;
    fusionarArboles(destino.arbolBinario.raiz,
            emisor.arbolBinario.raiz);
    cout<<"Destino fusionado: "<<endl;
    cout<<"Pre orden:";
    recorrerPreOrden(destino.arbolBinario);cout<<endl;
    cout<<"Pos orden: ";
    recorrerPostOrden(destino.arbolBinario);cout<<endl;
    return 0;
}

