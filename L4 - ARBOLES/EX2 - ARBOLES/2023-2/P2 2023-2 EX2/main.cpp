

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 6 de diciembre de 2024, 02:23 PM
 */

#include <iostream>
#include <iomanip>

#include "funcionesArbolesBinarios.h"
#include "ArbolBinarioBusqueda.h"
#include "funcionesArbolesBB.h"
using namespace std;
int verificarLetra(char letra,char *palabra){
    int existe=0;
    for(int i=0;palabra[i]!='\0';i++){
        if(letra==palabra[i]){
            existe=1;
            break;
        }
    }
    return existe;
}
int existe(char *palabra,char *aux,int pos){
    char auxE[6];
    for(int i=0;i<pos;i++)auxE[i]=aux[i];
    int existe,cont=0;
    for(int i=0;palabra[i]!='\0';i++){
        cont++;
        existe=0;
        for(int j=0;j<pos;j++){
            if(auxE[j]==palabra[i]){
                existe=1;
                auxE[j]=' ';
                break;
            }
        }
        if(existe!=1){
            break;
        }
    }
    if(existe==1 and cont==pos){
        return 1;
    }else{
        return 0;
    }
}
int validarPalabra(NodoArbol *nodo,char palabra[],char aux[],int pos){
    if(nodo==nullptr)return 0;
    if(verificarLetra(nodo->letra,palabra)==1){
        aux[pos++]=nodo->letra;
    }else{
        return 0;
    }
    if(nodo->izquierda==nullptr and nodo->derecha==nullptr){
        if(existe(palabra,aux,pos)==1){
            return 1;
        }else{
            return 0;
        }
    }
    return validarPalabra(nodo->izquierda,palabra,aux,pos) + 
           validarPalabra(nodo->derecha,palabra,aux,pos);
}
int main(int argc, char** argv) {
    ArbolBinarioBusqueda arbol;
    construir(arbol);
    insertar(arbol,30,'L');
    insertar(arbol,20,'D');
    insertar(arbol,40,'I');
    insertar(arbol,15,'E');
    insertar(arbol,23,'N');
    insertar(arbol,22,'C');
    insertar(arbol,25,'A');
    insertar(arbol,24,'F');
    insertar(arbol,38,'C');
    insertar(arbol,37,'C');
    insertar(arbol,36,'O');
    insertar(arbol,45,'N');
    insertar(arbol,43,'A');
    insertar(arbol,42,'F');
    insertar(arbol,44,'T');
    char palabra[6][8]={{'H','I','J','O','\0'},
                        {'F','I','N','A','L','\0'},
                        {'M','U','N','D','O','\0'},
                        {'D','E','L','\0'},
                        {'D','I','A','\0'},
                        {'C','I','C','L','O','\0'}};
    int cantPalabras=6;
    char aux[7];
    for(int i=0;i<cantPalabras;i++){
        int validar=validarPalabra(arbol.arbolBinario.raiz,palabra[i],aux,0);
        if(validar==1){
            for(int j=0;palabra[i][j]!='\0';j++){
                cout<<palabra[i][j];
            }
            cout<<endl;
        }
        
    }
    return 0;
}

