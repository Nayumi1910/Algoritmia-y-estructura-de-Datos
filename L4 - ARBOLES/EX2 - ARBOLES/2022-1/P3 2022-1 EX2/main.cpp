

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 5 de diciembre de 2024, 02:57 PM
 */

#include <iostream>
#include <iomanip>

#include "ArbolBB.h"
#include "funcionesABB.h"
using namespace std;

int verificarCantidadPalabra(char *palabra,int n){
    int i=0;
    while(palabra[i]!=' '){
        i++;
    }
    if(i==n)return 1;
    return 0;
}
char buscarRecursivoLetra(struct NodoArbol * nodo,int num){
    if(nodo==nullptr)
        return 'X';
    if(nodo->elemento==num)
        return nodo->letra;
    if(nodo->elemento>num)
        return buscarRecursivoLetra(nodo->izquierda, num);
    else
        if(nodo->elemento<num)
            return buscarRecursivoLetra(nodo->derecha, num);
}
bool verificacion(int cont,char *palabra,NodoArbol *nodo, bool centinela=true,int i=1){
    if(i>cont)return centinela;
    if(buscarRecursivoLetra(nodo,i)){
        cout<<palabra[i]<<endl;
    }else{
        cout<<palabra[i]<<"(X)";
        centinela=false;
    }
}
void verificarLetra(NodoArbol *nodo,char *palabra,int cont, int n){
    if(cont>n){
        cout<<"Lo siento se acabaron los intentos"<<endl;
        return;
    }
    if(verificacion(cont,palabra,nodo)){
        cout<<"Felicitaciones"<<endl;
        return;
    }
    cout<<endl;
    verificarLetra(nodo,palabra,cont+1,n);
}
int main(int argc, char** argv) {
    ArbolBinarioBusqueda arbol;
    construir(arbol);
    int n=5;
    insertar(arbol,2,'E');
    insertar(arbol,4,'I');
    insertar(arbol,5,'O');
    insertar(arbol,3,'L');
    insertar(arbol,1,'H');
    cout<<"Bienvenido al juego"<<endl;
    cout<<"Tiene 5 intentos"<<endl;
    cout<<"Intento 1: ADORA"<<endl;
    char palabra[6]={'A','D','O','R','A',' '};
    int cont=1;
    if(verificarCantidadPalabra(palabra,n)){
        verificarLetra(arbol.arbolBinario.raiz,palabra,cont,n);
    }else{
        cout<<"La longitud de la palara es incorrecta"<<endl;
    }
    return 0;
}

