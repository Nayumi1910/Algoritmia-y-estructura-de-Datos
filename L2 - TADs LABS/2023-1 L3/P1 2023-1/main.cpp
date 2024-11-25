

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 9 de octubre de 2024, 10:59 PM
 */

#include <iostream>
#include <iomanip>
#include "Pila.h"
#include "funcionesPila.h"
using namespace std;

void unirPila(Pila &p1,Pila &p2){
    while(!esPilaVacia(p2)){
        apilar(p1,desapilar(p2));
    }
}
//void ordenarPila(Pila &p1,Pila &p2, int n){
//    if(n==0)return;
//    int max=desapilar(p1);
//    for(int i=1;i<n;i++){
//        int aux=desapilar(p1);
//        if(aux<max){
//            apilar(p2,aux);
//        }else{
//            apilar(p2,max);
//            max=aux;
//        }
//    }
//    apilar(p1,max);
//    while(!esPilaVacia(p2)){
//        apilar(p1,desapilar(p2));
//    }
//    ordenarPila(p1,p2,n-1);
//}
//void encontrarMaximo(Pila &p1, Pila &p2, int &max, int n) {
//    if (n == 0) return;
//
//    int aux = desapilar(p1);
//    if (aux > max) {
//        apilar(p2, max);
//        max = aux;
//    } else {
//        apilar(p2, aux);
//    }
//
//    encontrarMaximo(p1, p2, max, n - 1);
//}
//void ordenarPila(Pila &p1,Pila &p2, int n){
//    if(n==0)return;
//    int max=desapilar(p1);
//    encontrarMaximo(p1,p2,max,n-1);
//    apilar(p1,max);
//    while(!esPilaVacia(p2)){
//        apilar(p1,desapilar(p2));
//    }
//    ordenarPila(p1,p2,n-1);
//}
void ordenarPila(Pila &p1,Pila &p2,int n){
    int max;
    while(p1.lista.longitud!=0){
        max=desapilar(p1);
        while(p2.lista.longitud!=0 and p2.lista.cabeza->elemento>max){
            apilar(p1,desapilar(p2));
        }
        apilar(p2,max);
        
    }
    while(p2.lista.longitud!=0){
        apilar(p1,desapilar(p2));
    }
}
void pasarPila(Pila &p1,Pila &p2){
    int dato;
    if(p1.lista.longitud==0){
        return;
    }
    dato=desapilar(p1);
    pasarPila(p1,p2);
    apilar(p2,dato);
}
int main(int argc, char** argv) {
    Pila kupa1,kupa2;
    construir(kupa1);
    apilar(kupa1,85);
    apilar(kupa1,15);
    apilar(kupa1,56);
    apilar(kupa1,30);
    apilar(kupa1,27);
    cout<<"Robot Kupa 1: ";
    imprimir(kupa1);
    construir(kupa2);
    apilar(kupa2,45);
    apilar(kupa2,22);
    apilar(kupa2,68);
    apilar(kupa2,20);
    cout<<"Robot Kupa 2: ";
    imprimir(kupa2);
    
    //Parte A
    unirPila(kupa1,kupa2);
    cout<<"Robot Kupa unido: ";
    imprimir(kupa1);
    //Parte B
    Pila aux;
    construir(aux);
    int n=longitud(kupa1);
    ordenarPila(kupa1,aux,n);
    cout<<"Robot Kupa ordenado: ";
    imprimir(kupa1);
    //Parte C
    Pila champi;
    construir(champi);
    pasarPila(kupa1,champi);
    cout<<"Robot Kupa pasa a mundo champiñon: ";
    imprimir(champi);
    return 0;
}

