

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 10 de octubre de 2024, 09:11 AM
 */

#include <iostream>
#include <iomanip>

#include "Lista.h"
#include "funcionesLista.h"
#include "Nodo.h"
using namespace std;

void fusionar(Lista &L1,Lista &L2){
    if(L1.cola->elemento>L2.cabeza->elemento){
        L1.cola->siguiente=L2.cabeza;
        L1.cola=L2.cola;
    }else if(L2.cola->elemento>L1.cabeza->elemento){
        L2.cola->siguiente=L1.cabeza;
        L1.cabeza=L2.cabeza;
    }else{
        Nodo *ini=nullptr;
        Nodo *fin=nullptr;
        while(L2.cabeza!=nullptr and L1.cabeza!=nullptr){
            if(L1.cabeza->elemento>=L2.cabeza->elemento){
                if(ini==nullptr){
                    ini=L1.cabeza;
                    fin=L1.cabeza;
                }else{
                    fin->siguiente=L1.cabeza;
                    fin=L1.cabeza;
                }
                L1.cabeza=L1.cabeza->siguiente;
            }else{
                if(ini==nullptr){
                    ini=L2.cabeza;
                    fin=L2.cabeza;
                }else{
                    fin->siguiente=L2.cabeza;
                    fin=L2.cabeza;
                }
                L2.cabeza=L2.cabeza->siguiente;
            }
        }
        while(L1.cabeza!=nullptr){
            if(ini==nullptr){
                ini=L1.cabeza;
                fin=L1.cabeza;
            }else{
                fin->siguiente=L1.cabeza;
                fin=L1.cabeza;
            }
            L1.cabeza=L1.cabeza->siguiente;
        }
        while(L2.cabeza!=nullptr){
            if(ini==nullptr){
                ini=L2.cabeza;
                fin=L2.cabeza;
            }else{
                fin->siguiente=L2.cabeza;
                fin=L2.cabeza;
            }
            L2.cabeza=L2.cabeza->siguiente; 
        }
        L1.cabeza=ini;
        L1.cola=fin;
    }
    L1.longitud+=L2.longitud;
}

int main(int argc, char** argv) {
    Lista listaA,listaB,listaC,listaD,listaE;
    construir(listaA);
    insertarAlFinal(listaA,15);
    insertarAlFinal(listaA,13);
    insertarAlFinal(listaA,12);
    insertarAlFinal(listaA,11);
    cout<<"Lista A: ";
    imprime(listaA);
    construir(listaB);
    insertarAlFinal(listaB,20);
    insertarAlFinal(listaB,19);
    cout<<"Lista B: ";
    imprime(listaB);
    construir(listaC);
    insertarAlFinal(listaC,18);
    insertarAlFinal(listaC,17);
    insertarAlFinal(listaC,16);
    cout<<"Lista C: ";
    imprime(listaC);
    construir(listaD);
    insertarAlFinal(listaD,17);
    insertarAlFinal(listaD,15);
    insertarAlFinal(listaD,14);
    insertarAlFinal(listaD,13);
    insertarAlFinal(listaD,12);
    cout<<"Lista D: ";
    imprime(listaD);
    construir(listaE);
    insertarAlFinal(listaE,14);
    insertarAlFinal(listaE,12);
    insertarAlFinal(listaE,10);
    insertarAlFinal(listaE,8);
    cout<<"Lista E: ";
    imprime(listaE);
    
    fusionar(listaA,listaB);
    cout<<"Fuiono A y B: ";
    imprime(listaA);
    fusionar(listaA,listaC);
    cout<<"Fuiono A y C: ";
    imprime(listaA);
    fusionar(listaA,listaD);
    cout<<"Fuiono A y D: ";
    imprime(listaA);
    fusionar(listaA,listaE);
    cout<<"Fuiono A y E: ";
    imprime(listaA);
    return 0;
}

