

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 1 de diciembre de 2024, 11:34 PM
 */

#include <iostream>
#include <iomanip>

#include "ArbolBinarioBusqueda.h"
#include "funcionesABB.h"
#include "funcionesArbolesBinarios.h"
#include "Cola.h"
#include "funcionesCola.h"
using namespace std;
int existe(NodoArbol *peach,NodoArbol *donkey){
    if(peach==nullptr)return 0;
    if(peach->elemento==donkey->elemento){
        peach->cantidad+=donkey->cantidad;
        return 1;
    }
    existe(peach->izquierda,donkey);
    existe(peach->derecha,donkey);
}
void fusionar(NodoArbol *peach,NodoArbol *donkey){
    if(donkey==nullptr or peach==nullptr)return;
    if(!existe(peach,donkey)){
        insertarRecursivo(peach,donkey->elemento,
                donkey->cantidad);
    }
    fusionar(peach,donkey->izquierda);
    fusionar(peach,donkey->derecha);
}
void recorrerPreOrdenIterativo(ArbolBinario peach){
    Cola cola;
    construir(cola);
    encolarNew(cola,peach.raiz);
    int nivel=0;
    while(!esColaVacia(cola)){
        int n=longitud(cola);
        cout<<"Nivel "<<nivel<<" :";
        for(int i=0;i<n;i++){
            NodoArbol *aux=desencolarNew(cola);
            imprimeNodo(aux);
            if(aux->izquierda!=nullptr){
                encolarNew(cola,aux->izquierda);
            }
            if(aux->derecha!=nullptr){
                encolarNew(cola,aux->derecha);
            }
        }
        nivel++;
        cout<<endl;
    }
}
int main(int argc, char** argv) {
    ArbolBinarioBusqueda peach,donkey;
    construir(peach);
    construir(donkey);
    //peach
    insertar(peach,52,2);
    insertar(peach,40,1);
    insertar(peach,25,3);
    insertar(peach,42,2);
    insertar(peach,60,1);
    cout<<"Ejercito de Peach: ";
    recorrerPreOrden(peach.arbolBinario);
    cout<<endl;
    //donkey
    insertar(donkey,65,1);
    insertar(donkey,25,1);
    insertar(donkey,12,2);
    insertar(donkey,34,1);
    insertar(donkey,75,2);
    insertar(donkey,70,1);
    cout<<"Ejercito de Donkey: ";
    recorrerPreOrden(donkey.arbolBinario);
    cout<<endl;
    fusionar(peach.arbolBinario.raiz,donkey.arbolBinario.raiz);
    cout<<"Ejercito de Peach fusionado: "<<endl;
    recorrerPreOrdenIterativo(peach.arbolBinario);
    cout<<endl;
    return 0;
}

