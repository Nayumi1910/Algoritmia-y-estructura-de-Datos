

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 25 de noviembre de 2024, 02:41 PM
 */

#include <iostream>
#include <iomanip>

#include "ArbolBinarioBusqueda.h"
#include "funcionesABB.h"
#include "funcionesArbolesBinarios.h"
using namespace std;

int esMismoTime(char time1[],char time2[],int tam){
    for(int i=0;i<tam;i++){
        if(time1[i]!=time2[i]){
            return 0;
        }
    }
    return 1;
}
int existe(NodoArbol *nodo,Elemento dato){
    int resultado=0;
    if(nodo==nullptr){
        return resultado;
    }
    if(nodo!=nullptr and esMismoTime(nodo->elemento.tiempo,dato.tiempo,8)){
        return 1;
    }
    if(dato.monto<nodo->elemento.monto){
        resultado=existe(nodo->izquierda,dato);
    }else{
        resultado=existe(nodo->derecha,dato);
    }
    return resultado;
}
int esPosibleInsertar(ArbolBinarioBusqueda &arbol,Elemento &dato,
        char iniTime[]){
    if(esMismoTime(dato.tiempo,iniTime,8)){
        if(existe(arbol.arbolBinario.raiz,dato)){
            return 0;
        }else{
            return 1;
        }
    }else{
        return 0;
    }
}
void consolidar(NodoArbol *&arbol){
    if(arbol!=nullptr){
        arbol->elemento.estado='P';
        consolidar(arbol->izquierda);
        consolidar(arbol->derecha);
    }
}
int main(int argc, char** argv) {
    
    ArbolBinarioBusqueda arbol;
    construir(arbol);
    char opcion;
    char iniTime[10];
    int cant =0;
    do{
        Elemento dato;
        cout<<"Ingresar fecha: ";
        cin>>dato.tiempo;
        cout<<"Ingresar DNI: ";
        cin>>dato.dni;
        if(cant==0){
            for(int i=0;i<8;i++){
                iniTime[i]=dato.tiempo[i];
            }
        }
        if(esPosibleInsertar(arbol,dato,iniTime)){
            cout<<"Ingrese el numero de acciones: ";
            cin>>dato.dato;
            cout<<"Monto de compra: ";
            cin>>dato.monto;
            dato.estado='R';
            insertar(arbol,dato);
            cant++;
        }else{
            cout<<"No es posible"<<endl;
        }
        
    }while(opcion=='s' or opcion=='S');
    //consolidamos
    consolidar(arbol.arbolBinario.raiz);
    recorrerPreOrden(arbol.arbolBinario);
    return 0;
}

