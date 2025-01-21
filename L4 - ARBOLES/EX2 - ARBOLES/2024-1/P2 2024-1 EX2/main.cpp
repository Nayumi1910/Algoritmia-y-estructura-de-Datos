

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 6 de diciembre de 2024, 03:48 PM
 */

#include <iostream>
#include <iomanip>

#include "ArbolBB.h"
#include "funcionesABB.h"
#include "funcionesAB.h"
#include "Lista.h"
#include "funcionesCola.h"
using namespace std;

int verificarComb(NodoArbol *nodo,int combinaciones[][3],int nivel){
    int existe=0;
    for(int i=0;i<3;i++){
        if(nodo->elemento==combinaciones[i][nivel]){
            existe=1;
        }
    }
    return existe;
}

int main(int argc, char** argv) {
    int emociones[9]={1,2,3,4,5,6,7,8,9};
    int numEmo=9;
    int pesos[9][3]={{180,200,0},
                        {140,230,80},
                        {240,100,0},
                        {280,0,0},
                        {250,0,0},
                        {260,120,0},
                        {160,240,0},
                        {120,80,0},
                        {150,230,90}};
    ArbolBinarioBusqueda arbol;
    construir(arbol);
    insertar(arbol,180);
    insertar(arbol,120);
    insertar(arbol,250);
    insertar(arbol,100);
    insertar(arbol,150);
    insertar(arbol,80);
    insertar(arbol,90);
    insertar(arbol,140);
    insertar(arbol,160);
    insertar(arbol,230);
    insertar(arbol,280);
    insertar(arbol,200);
    insertar(arbol,240);
    insertar(arbol,260);
    int numComb=3;
    int combinaciones[3][3]={{6,9,2},{5,2,3},{3,8,9}};
    int alt=altura(arbol.arbolBinario);
    cout<<"Tiene "<<alt+1<<" niveles"<<endl;
    
    //vamos a buscar por niveles
    Cola cola;
    construir(cola);
    encolarNew(cola,arbol.arbolBinario.raiz);
    int cont=0,cant;
    while(!esColaVacia(cola)){
        int n=longitud(cola);
        cant=0;
        for(int i=0;i<n;i++){
            NodoArbol *nodo=desencolar(cola);
            if(verificarComb(nodo,combinaciones,cont,emociones,pesos)){
                cant=buscarCombinaciones(nodo,combinaciones,numComb);
            }
            if(nodo->izquierda!=nullptr){
                encolarNew(cola,nodo->izquierda);
            }
            if(nodo->derecha!=nullptr){
                encolarNew(cola,nodo->derecha);
            }
        }
        cont++;
        if(cont==(alt-numComb+1))break;
    }
        

    return 0;
}

