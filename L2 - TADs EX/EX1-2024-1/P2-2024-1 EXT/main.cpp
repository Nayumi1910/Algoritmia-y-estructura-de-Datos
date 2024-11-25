

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 6 de octubre de 2024, 12:30 PM
 */

#include <iostream>
#include <iomanip>

#include "Pila.h"
#include "funcionesPila.h"

using namespace std;


int main(int argc, char** argv) {
    Pila pila;
    construir(pila);
    int i=7;
    int indice=i;
    int arreglo[i]={100,80,60,70,60,75,85};
    int intervalos[i]={};
    int max=arreglo[i];
    int valor;
    while(1){
        //en caso de que se acaben las posibilidades
        if(i==0 and indice==0){
            //es el primer elemento, por lo que no tendra incrementos
            //antes que el
            intervalos[indice]=1;
            break;
        }
        //en caso sea el mas grande
        if(i<0){
            valor=desapilar(pila);
            intervalos[indice]=valor;
            i=indice;
            indice=indice-1;
            max=arreglo[indice];
        }else{
            if(esPilaVacia(pila)){
                apilar(pila,1);
            }else{
                if(arreglo[i]<max){
                    // en caso de que sea menor
                    valor=desapilar(pila);
                    apilar(pila,valor+1);
                }else{
                    valor=desapilar(pila);
                    intervalos[indice]=valor;
                    i=indice;
                    indice=indice-1;
                    max=arreglo[indice];
                }
            }
        }
        i--;
    }
    for(int i=0;i<7;i++){
        cout<<intervalos[i]<<" ";
    }
    return 0;
}

