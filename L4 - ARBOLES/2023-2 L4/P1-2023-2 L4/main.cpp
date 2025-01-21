

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 29 de noviembre de 2024, 09:50 AM
 */

#include <iostream>
#include <iomanip>

#include "ArbolBinarioBusqueda.h"
#include "funcionesArbolesBB.h"
#include "funcionesArbolesBinarios.h"
using namespace std;

int calcularAltura(NodoArbol* nodo) {
    if (nodo == nullptr)
        return 0;
    else {
        int alturaIzq = calcularAltura(nodo->izquierda);  // Calcula la altura del sub rbol izquierdo
        int alturaDer = calcularAltura(nodo->derecha);  // Calcula la altura del sub rbol derecho
        return maximo(alturaIzq, alturaDer) + 1;  // Retorna la altura m xima entre los sub rboles izquierdo y derecho, m s 1 (altura del nodo actual)
    }
}
NodoArbol *rotarDerecha(NodoArbol *nodo){
    NodoArbol *nodoIzq=nodo->izquierda;
    nodo->izquierda=nodo->derecha;
    nodoIzq->derecha=nodo;
    return nodoIzq;
}
NodoArbol *rotarIzquierda(NodoArbol *nodo){
    NodoArbol *nodoDer=nodo->derecha;
    nodo->derecha=nodo->izquierda;
    nodoDer->izquierda=nodo;
    return nodoDer;
}
NodoArbol *rotarDobleDer(NodoArbol *nodo){
    nodo->izquierda=rotarIzquierda(nodo->izquierda);
    return rotarDerecha(nodo);
}
NodoArbol *rotarDobleIzq(NodoArbol *nodo){
    nodo->derecha=rotarDerecha(nodo->derecha);
    return rotarIzquierda(nodo);
}
NodoArbol *balancearNodo(NodoArbol *nodo){
    int alturaI=calcularAltura(nodo->izquierda);
    int alturaD=calcularAltura(nodo->derecha);
    int diferencia=alturaI-alturaD;
    
    if(diferencia>1){
        if(calcularAltura(nodo->izquierda->izquierda)>=
                calcularAltura(nodo->izquierda->derecha)){
            nodo=rotarDerecha(nodo);
        }else{
            nodo=rotarDobleDer(nodo);
        }
    }else if(diferencia<-1){
        if(calcularAltura(nodo->derecha->derecha)>=
                calcularAltura(nodo->derecha->izquierda)){
            nodo=rotarIzquierda(nodo);
        }else{
            nodo=rotarDobleIzq(nodo);
        }
    }
    return nodo;
}
NodoArbol *balancear(NodoArbol *arbol){
    if(arbol==nullptr)return nullptr;
    
    arbol->izquierda=balancear(arbol->izquierda);
    arbol->derecha=balancear(arbol->derecha);
    arbol=balancearNodo(arbol);
    
    return arbol;
}
void recorrerPorNivelRecursivo(NodoArbol *raiz,int i){
    if(esNodoVacio(raiz))return;
    if(i==0){
        imprimeNodo(raiz);
    }else if(i>0){
        recorrerPorNivelRecursivo(raiz->izquierda,i-1);
        recorrerPorNivelRecursivo(raiz->derecha,i-1);
    }
}
void recorrerPorNivel(ArbolBinarioBusqueda &arbol){
    int h=altura(arbol.arbolBinario);
    for(int i=0;i<=h;i++){
        cout<<"Nivel "<<i<<" :";
        recorrerPorNivelRecursivo(arbol.arbolBinario.raiz,i);
        cout<<endl;
    }
}
//void plantarArbolBalanceado(struct ArbolBinarioBusqueda &arbol,int codigos[],
//        int posIni,int posFin){
//    //CASO BASE
//    if(posIni<=posFin){
//        int posMed=(posIni+posFin)/2;
//
//        insertar(arbol,codigos[posMed]);
//        plantarArbolBalanceado(arbol,codigos,posIni,posMed-1);    
//        plantarArbolBalanceado(arbol,codigos,posMed+1,posFin);  
//    }
//      
//}
void colocarArr(NodoArbol *raiz,int arreglo[],int &index){
    if(raiz==nullptr)return;
    colocarArr(raiz->izquierda,arreglo,index);
    arreglo[index++]=raiz->elemento;
    colocarArr(raiz->derecha,arreglo,index);
}
NodoArbol *construirBalanceo(int arreglo[],int ini,int fin){
    if(ini>fin)return nullptr;
    int medio=(ini+fin)/2;
    NodoArbol *nodo=crearNuevoNodoArbol(nullptr,arreglo[medio],nullptr);
    //construimos los subarboles
    nodo->izquierda=construirBalanceo(arreglo,ini,medio-1);
    nodo->derecha=construirBalanceo(arreglo,medio+1,fin);
    return nodo;
}
int encontrarAncestro(NodoArbol *nodo,int valor1,int valor2){
    //caso base
    if(esNodoVacio(nodo))return -1;
    if(nodo->elemento==valor1 or nodo->elemento==valor2){
        return 0;
    }
    if(nodo->elemento==valor1 and nodo->elemento==valor2){
        return -1;
    }
    int izq=encontrarAncestro(nodo->izquierda,valor1,valor2);
    int der=encontrarAncestro(nodo->derecha,valor1,valor2);
    if(izq==0 and der==0){
        return nodo->elemento;
    }
    else if(izq==-1 and der==-1){
        return -1;
    }
    else if(izq>0){
        return izq;
    }
    else if(der>0){
        return der;
    }
    else{
        return 0;
    }
    
}
NodoArbol *balanceoABB(NodoArbol *raiz){
    int n=numeroNodosRecursivo(raiz);
    int arreglo[n],index=0;
    colocarArr(raiz,arreglo,index);
    NodoArbol *balanceador=construirBalanceo(arreglo,0,n-1);
    return balanceador;
}
int busca_primer_ancestro_comun(ArbolBinarioBusqueda &arbol,
        int valor1,int valor2){
    if(!esArbolVacio(arbol)){
        encontrarAncestro(arbol.arbolBinario.raiz,valor1,valor2);
    }
}
void plantarArbolBalanceado( ArbolBinarioBusqueda &arbol,int codigos[],
        int posIni,int posFin){
    //CASO BASE
    if(posIni<=posFin){
        int posMed=(posIni+posFin)/2;

        insertar(arbol,codigos[posMed]);
        plantarArbolBalanceado(arbol,codigos,posIni,posMed-1);    
        plantarArbolBalanceado(arbol,codigos,posMed+1,posFin);  
    }
      
}
void devolverCodigoRecursivo(struct NodoArbol *nodo,int codigos[],int &index){
    //CASO BASE
    if(esNodoVacio(nodo))return;
    //Recorre en orden
    devolverCodigoRecursivo(nodo->izquierda,codigos,index);
    codigos[index++]=nodo->elemento;
    devolverCodigoRecursivo(nodo->derecha,codigos,index);
}
void devolverCodigo(struct ArbolBinarioBusqueda &arbol,int codigos[]){
    int index=0;
    if(!esArbolVacio(arbol)){
        devolverCodigoRecursivo(arbol.arbolBinario.raiz,codigos,index);
    }
}
int main(int argc, char** argv) {
    int n=8;
    int codigos[n]={3,1,5,2,4,8,13,18};
    ArbolBinarioBusqueda arbol,arbol2;
    construir(arbol2);
    construir(arbol);
    insertar(arbol,3);
    insertar(arbol,1);
    insertar(arbol,5);
    insertar(arbol,2);
    insertar(arbol,4);
    insertar(arbol,8);
    insertar(arbol,13);
    insertar(arbol,18);
    
    cout<<"Arbol : ";
    recorrerPreOrden(arbol.arbolBinario);
    cout<<endl;
    cout<<"Arbol por nivel: "<<endl;
    recorrerPorNivel(arbol);
    cout<<endl;
//    arbol.arbolBinario.raiz=balancear(arbol.arbolBinario.raiz);
    arbol.arbolBinario.raiz=balanceoABB(arbol.arbolBinario.raiz);
    //Devolver el codigo del arbol (en orden) al arreglo
//    devolverCodigo(arbol,codigos);
//    //Plantar arbol token (DyV)
//    plantarArbolBalanceado(arbol2,codigos,0,n-1);//ABB
    cout<<endl<<"Segundo arbol: Arbol Balanceado (token)"<<endl;
    cout<<"En Orden: ";
    recorrerEnOrden(arbol.arbolBinario);
    cout<<endl;
    cout<<"Por nivel: "<<endl;
    recorrerPorNivel(arbol);

//    cout<<"Arbol balanceado: ";
//    recorrerPreOrden(arbol.arbolBinario);
//    cout<<endl;
    cout<<endl<<"Primer ancestro comun: "
        <<busca_primer_ancestro_comun(arbol,8,2);
    return 0;
}

