/* 
 * Nombre:   Karolyn Nayumi Aquiño Torres
 * Codigo:   20203608
 */

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;
#include "ArbolBinario.h"
#include "ArbolBinarioBusqueda.h"
#include "Cola.h"
#include "Lista.h"
#include "Nodo.h"
#include "funcionesArbolesBB.h"
#include "funcionesArbolesBinarios.h"
#include "funcionesCola.h"

void recorrePorAmplitudItera(struct ArbolBinario arbol){
    if(esArbolVacio(arbol))return;
    Cola cola;
    construir(cola);
    NodoArbol *nodo;
    encolar(cola,arbol.raiz);
    while(!esColaVacia(cola)){
        nodo=desencolar(cola);
        imprimeNodo(nodo); 
        if(!esNodoVacio(nodo->izquierda)){
            encolar(cola,nodo->izquierda);
        }
        if(!esNodoVacio(nodo->derecha)){
            encolar(cola,nodo->derecha);
        }
    }
}
void validacionIngresoProducto(struct ArbolBinario arbol,int calidad){
    if(esArbolVacio(arbol))return;
    Cola cola;
    construir(cola);
    NodoArbol *nodo;
    int limiteAux,cant=0;
    encolar(cola,arbol.raiz);
    while(!esColaVacia(cola)){
        nodo=desencolar(cola);
        if(nodo->nivel==calidad-1){
            limiteAux=nodo->nivel*2;
        }
        if(nodo->nivel==calidad){
            cant++;
        }else{
            if(nodo->nivel==calidad+1){
                break;
            }
        }
        if(!esNodoVacio(nodo->izquierda)){
            encolar(cola,nodo->izquierda);
        }
        if(!esNodoVacio(nodo->derecha)){
            encolar(cola,nodo->derecha);
        }
    }
    if(cant==limiteAux){
        cout<<"No es posible"<<endl;
    }else{
        if(cant<limiteAux){
            cout<<"Si hay espacio"<<endl;
        }
    }
    
}

bool buscar(struct NodoArbol *nodo, int codigo) {
    if(nodo==nullptr)return false;
    if(nodo->elemento==codigo)return true;
    if(codigo<nodo->elemento){
        return buscar(nodo->izquierda,codigo);
    }else{
        return buscar(nodo->derecha,codigo);
    }
}

int validarActualizacion(struct ArbolBinarioBusqueda arbol, int codigoActual, int nuevoCodigo){
    if(esArbolVacio(arbol))return 0;
    if(buscar(arbol.arbolBinario.raiz,nuevoCodigo))return 0;
    
    NodoArbol *padre=nullptr,*actual=arbol.arbolBinario.raiz;
    while(actual!=nullptr and actual->elemento!=codigoActual){
        padre=actual;
        if(codigoActual<actual->elemento){
            actual=actual->izquierda;
        }else{
            actual=actual->derecha;
        }
    }
    if(actual==nullptr)return 0;
    
    if(padre!=nullptr){
        if((padre->izquierda==actual and nuevoCodigo>padre->elemento)
                or (padre->derecha==actual and nuevoCodigo<padre->elemento)){
            return 0;
        }
    }
    if((actual->izquierda!=nullptr and nuevoCodigo<
            maximoNodo(actual->izquierda)) or (actual->derecha!=nullptr
            and nuevoCodigo>minimoNodo(actual->derecha))){
        return 0;
    }
    return 1;
}

int main(int argc, char** argv) {
    struct ArbolBinarioBusqueda arbol;
    construir(arbol);
    insertar(arbol,10,1);
    insertar(arbol,5,2);
    insertar(arbol,20,2);
    insertar(arbol,21,3);
    insertar(arbol,2,3);
    insertar(arbol,6,3);
    recorrerPreOrden(arbol.arbolBinario);
    cout<<endl;
    cout<<"Recorrido por Amplitud: "<<endl;
    recorrePorAmplitudItera(arbol.arbolBinario);
    cout<<endl;
    int calidad = 3;
    validacionIngresoProducto(arbol.arbolBinario,calidad);
    int codigoActual = 5,nuevoCodigo = 7;
    int valido = validarActualizacion(arbol,codigoActual,nuevoCodigo);
    if(valido==1){
        cout<<"Se puede actualizar"<<endl;
    }else{
        cout<<"No se puede actualizar"<<endl;
    }
    return 0;
}

