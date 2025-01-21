

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 26 de noviembre de 2024, 12:19 PM
 */

#include <iostream>
#include <iomanip>

#include "ArbolBinarioBusqueda.h"
using namespace std;
void construirNew(struct ArbolBinario & arbol){
    arbol.raiz = nullptr;
}
void construirNewABB(struct ArbolBinarioBusqueda & arbol){
    construirNew(arbol.arbolBinario);
}
bool esNodoVacioNew(struct NodoArbol * nodo){
    return nodo == nullptr;
}
bool esArbolVacioNew(const struct ArbolBinario & arbol){
    return esNodoVacioNew(arbol.raiz);
}

void imprimeNodoNew(struct NodoArbol * nodo){
    cout<<"("<<nodo->campo1<<" "<<nodo->elemento<<" "
            <<nodo->campo3<<") ";

}
void imprimeRaizNew(const struct ArbolBinario & arbol){
    imprimeNodoNew(arbol.raiz);
}
void recorrerEnPreOrdenRecursivoNew(struct NodoArbol * nodo){
    if(not esNodoVacioNew(nodo)){
        imprimeNodoNew(nodo);
        recorrerEnPreOrdenRecursivoNew(nodo->izquierda);
        recorrerEnPreOrdenRecursivoNew(nodo->derecha);
    }
}

/*recorrido descendente, se lleva a cabo visitando cada nodo, seguido de sus hijos,
 luego todos los restantes, comenzando por la ra�z*/
void recorrerPreOrdenNew(const struct ArbolBinario & arbol){
    if (not esArbolVacioNew(arbol)){
        recorrerEnPreOrdenRecursivoNew(arbol.raiz);
    }
}
struct NodoArbol * crearNuevoNodoArbolNew(struct NodoArbol * arbolIzquierdo, 
                               int campo1,
                    int campo2,int campo3,  struct NodoArbol * arbolDerecho){
    struct NodoArbol * nuevoNodo = new struct NodoArbol;
    nuevoNodo->elemento = campo2;
    nuevoNodo->campo1=campo1;
    nuevoNodo->campo3=campo3;
    nuevoNodo->izquierda = arbolIzquierdo;
    nuevoNodo->derecha = arbolDerecho;
    return nuevoNodo;
}

void plantarArbolBB(struct NodoArbol *& arbol, 
                    struct NodoArbol * arbolIzquierdo, int campo1,
                    int campo2,int campo3, 
                    struct NodoArbol * arbolDerecho){
    
    struct NodoArbol * nuevoNodo = new struct NodoArbol;
    nuevoNodo->elemento = campo2;
    nuevoNodo->campo1 = campo1;
    nuevoNodo->campo3 = campo3;
    nuevoNodo->izquierda = arbolIzquierdo;
    nuevoNodo->derecha = arbolDerecho;
    arbol = nuevoNodo;
}

void insertarRecursivoNew(struct NodoArbol *& raiz, int campo1,
        int campo2,int campo3){
    if(raiz==nullptr)
        plantarArbolBB(raiz, nullptr, campo1,campo2,campo3, nullptr);
    else
        if (raiz->campo1 > campo1 or (raiz->campo1==campo1 and
                raiz->elemento!=campo2))
            insertarRecursivoNew(raiz->izquierda, campo1,campo2,campo3);
        else
            if(raiz->campo1 < campo1)
                insertarRecursivoNew(raiz->derecha, campo1,campo2,campo3);
            else
                cout<<endl<<"El elemento "<< campo2 <<" ya se encuentra en el árbol"<< endl;
}

void insertarNew(struct ArbolBinarioBusqueda & arbol, int campo1,
        int campo2,int campo3){
    insertarRecursivoNew(arbol.arbolBinario.raiz, campo1,campo2,campo3);
}
int verificaInsertar(NodoArbol *nodo,NodoArbol *verificador){
    if(nodo==nullptr)return 1;
    
    if(nodo->campo1 < verificador->campo1){
        verificaInsertar(nodo->derecha,verificador);
    }else{
        if(nodo->campo1 > verificador->campo1){
            verificaInsertar(nodo->izquierda,verificador);
        }else{
            if(nodo->elemento > verificador->elemento){
                verificaInsertar(nodo->izquierda,verificador);
            }else{
                if(nodo->elemento < verificador->elemento){
                    verificaInsertar(nodo->derecha,verificador);
                }else{
                    return 0;
                }
            }
        }
    }

    
}
void verificar(ArbolBinarioBusqueda &arbol,NodoArbol *verificador){
    int validar=verificaInsertar(arbol.arbolBinario.raiz,verificador);
    if(validar==1){
        cout<<"Ok"<<endl;
    }else{
        cout<<"Cannot insert duplicate key"<<endl;
    }
}
int existe(NodoArbol *nodo,int num){
    if(nodo==nullptr)return 1;
    if(nodo->campo1==num or nodo->elemento==num){
        return 0;
    }
    existe(nodo->izquierda,num);
    existe(nodo->derecha,num);
}
int verificarActualizar(NodoArbol *nodo,int num){
    if(nodo==nullptr)return 1;
    if(!existe(nodo,num)){
        return 0;
    }
    verificarActualizar(nodo->izquierda,num);
    verificarActualizar(nodo->derecha,num);
    
}
void actualizar(ArbolBinarioBusqueda &arbol,int num){
	int validacion=verificarActualizar(arbol.arbolBinario.raiz,num);
	if(validacion==1){
            cout<<"Ok"<<endl;
	}
	else{
            cout<<"Violation of Primary Key constraint on update"<<endl;
	}
}

int main(int argc, char** argv) {
    ArbolBinarioBusqueda arbol;
    construirNewABB(arbol);
    insertarNew(arbol,10,8,5);
    insertarNew(arbol,8,20,6);
    insertarNew(arbol,15,10,3);
    insertarNew(arbol,5,10,3);
    insertarNew(arbol,10,1,7);
    insertarNew(arbol,16,8,7);
    cout<<"Arbol: ";
    recorrerPreOrdenNew(arbol.arbolBinario);
    cout<<endl;
    NodoArbol *verificador=crearNuevoNodoArbolNew(nullptr,5,10,6,nullptr);
    verificar(arbol,verificador);
    
    int nuevoCampo1=15,c1=5,c2=10,c3=3;
    actualizar(arbol,nuevoCampo1);
    return 0;
}

