

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 2 de diciembre de 2024, 12:25 AM
 */

#include <iostream>
#include <iomanip>
#include <valarray>

#include "ArbolB.h"
#include "funcionesAB.h"
using namespace std;
struct NodoArbol * crearNuevoNodo(struct NodoArbol * izquierda, int elemento,
        int bit,struct NodoArbol * derecha) {

    struct NodoArbol * nuevo = new struct NodoArbol;
    nuevo->derecha = derecha;
    nuevo->izquierda = izquierda;
    nuevo->elemento = elemento;
    nuevo->bit=bit;
    return nuevo;
}
void plantarArbolBinarioN(struct NodoArbol *& raiz, 
                    struct NodoArbol * izquierda, int elemento, int bit,
                    struct NodoArbol * derecha){
    
    struct NodoArbol * nuevoNodo = crearNuevoNodo(izquierda, elemento,bit, derecha);
    raiz = nuevoNodo;
}
void insertarCromo(NodoArbol *& raiz,int num,int bit){
    if(esNodoVacio(raiz)){
        raiz=crearNuevoNodo(nullptr,num,bit,nullptr);
        return;
    }
    insertarCromo(raiz->izquierda,num,0);
    insertarCromo(raiz->derecha,num,1);
}
int esHoja(NodoArbol *arbol){
    if(arbol!=nullptr and arbol->derecha==nullptr and
            arbol->izquierda==nullptr){
        return 1;
    }
    return 0;
}
void numeroCombinacionesRecursivo(NodoArbol *arbol,int &cont,int peso,
        int suma){
    if(arbol==nullptr)return;
    if(arbol->bit==1){
        suma+=arbol->elemento;
    }
    if(esHoja(arbol)){
        if(suma==peso)cont++;
        return;
    }
    numeroCombinacionesRecursivo(arbol->izquierda,cont,peso,suma);
    numeroCombinacionesRecursivo(arbol->derecha,cont,peso,suma);
}
int numeroCombinaciones(ArbolBinario &arbol,int peso){
    int cont=0;
    numeroCombinacionesRecursivo(arbol.raiz,cont,peso,0);
    return cont;
}
ArbolBinario construirArbol(int arr[],int n){
    ArbolBinario arbol;
    arbol.raiz=crearNuevoNodo(nullptr,0,0,nullptr);
    for(int i=0;i<n;i++){
        insertarCromo(arbol.raiz,arr[i],0);
    }
    return arbol;
}
int main(int argc, char** argv) {
    int arr[5]={10,50,20,30,40};
    int n=5;
    ArbolBinario arbol=construirArbol(arr,n);
    cout<<"Arbol: ";
    recorrerPreOrden(arbol);
    cout<<endl;
    int comb=numeroCombinaciones(arbol,70);
    cout<<"El numero de combinaciones es: "<<comb<<endl;
    return 0;
}

