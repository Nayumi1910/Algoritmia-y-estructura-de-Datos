

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 4 de octubre de 2024, 04:16 PM
 */

#include <iostream>
#include <iomanip>
#include <codecvt>

#include "Cola.h"
#include "funcionesCola.h"
#include "Pila.h"
#include "funcionesPila.h"
using namespace std;

void hanoi(int n,Pila &pila,Pila &p1,Pila &p2,int dato){
    if(n==1){
        if(cima(pila)<dato){
            apilar(p1,desapilar(pila));
        }
        return;
    }
    hanoi(n-1,pila,p2,p1,dato);
    if(cima(pila)<dato and cima(pila)!=-1){
        apilar(p1,desapilar(pila));
    }
    hanoi(n-1,p2,p1,pila,dato);
}
int main(int argc, char** argv) {
    Cola cola;
    construir(cola);
    encolar(cola,2);
    encolar(cola,8);
    encolar(cola,10);
    encolar(cola,8);
    encolar(cola,5);
    encolar(cola,3);
    cout<<"Cola: ";
    imprime(cola);
    
    Pila origen,p1,p2;
    construir(origen);
    construir(p1);
    construir(p2);
    int len,aux,aux2;
    while(!esColaVacia(cola)){
        len=longitud(origen);
        if(esPilaVacia(origen)){
            apilar(origen,desencolar(cola));
        }else if(len==1){
            aux=desapilar(origen);
            aux2=desencolar(cola);
            if(aux<aux2){
                apilar(origen,aux2);
                apilar(origen,aux);
            }else{
                apilar(origen,aux);
                apilar(origen,aux2);
            }
        }else{
            aux=desencolar(cola);
            aux2=cima(origen);
            if(aux<aux2){
                apilar(origen,aux);
            }else{
                apilar(p1,aux);
                hanoi(longitud(origen),origen,p1,p2,aux);
                apilar(origen,aux);
                hanoi(longitud(p1),p1,origen,p2,aux);
                while(!esPilaVacia(p2)){
                    apilar(origen,desapilar(p2));
                }
            }
        }
        
    }
    cout<<"Pila:";
    imprimir(origen);
    return 0;
}

