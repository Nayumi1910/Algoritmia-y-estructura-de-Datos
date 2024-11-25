

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 10 de octubre de 2024, 11:34 PM
 */

#include <iostream>
#include <iomanip>
#include <cstring>
#include "Cola.h"
#include "funcionesCola.h"
#include "Nodo.h"
#include "funcionesLista.h"
#define actual 2024
using namespace std;
int retornaPrioridad(Fecha fecha){
    int year=2024-fecha.aa;
    if(year>=80){
        return 1;
    }else if(year<80 and year>=10){
        return 3;
    }else{
        return 2;
    }
}
void encolarOrdenaro(Cola &cola,Elemento e){
    Nodo *nodo=crearNodo(e,nullptr);
    int prioridad=retornaPrioridad(e.fecha);
    if(esColaVacia(cola)){
        cola.lista.cabeza=nodo;
        cola.lista.cola=nodo;
        if(prioridad==1){
            cola.lista.mayores=nodo;
        }
        if(prioridad==2){
            cola.lista.medios=nodo;
        }
    }else{
        if(prioridad==1){
            if(cola.lista.mayores==nullptr){
                nodo->siguiente=cola.lista.cabeza;
                cola.lista.cabeza=nodo;
            }else{
                if(cola.lista.mayores->siguiente==nullptr){
                    cola.lista.mayores->siguiente=nodo;
                    cola.lista.cola=nodo;
                }else{
                    nodo->siguiente=cola.lista.mayores->siguiente;
                    cola.lista.mayores->siguiente=nodo;
                }
            }
            cola.lista.mayores=nodo;
        }else if(prioridad==2){
            if(cola.lista.medios==nullptr){
                int dato=retornaPrioridad(cola.lista.cola->elemento.fecha);
                if(dato==1){
                    cola.lista.cola->siguiente=nodo;
                    cola.lista.cola=nodo;
                }
                if(dato==3){
                    if(cola.lista.mayores==nullptr){
                        nodo->siguiente=cola.lista.cabeza;
                        cola.lista.cabeza=nodo;
                    }else{
                       nodo->siguiente=cola.lista.mayores->siguiente;
                        cola.lista.mayores->siguiente=nodo; 
                    }
                }
            }else{
                if(cola.lista.medios==cola.lista.cola){
                    cola.lista.medios->siguiente=nodo;
                    cola.lista.cola=nodo;
                }else{
                    nodo->siguiente=cola.lista.medios->siguiente;
                    cola.lista.medios->siguiente=nodo;
                }
            }
            cola.lista.medios=nodo;
        }else{
            cola.lista.cola->siguiente=nodo;
            cola.lista.cola=nodo;
        }
    }
    cola.lista.longitud++;
}
int main(int argc, char** argv) {
    Cola cola;
    construir(cola);
    Elemento e;
    e.fecha.dd=30;
    e.fecha.mm=05;
    e.fecha.aa=1943;
    strcpy(e.codigo,"BXQ778");
    encolarOrdenaro(cola,e);
    e.fecha.dd=20;
    e.fecha.mm=04;
    e.fecha.aa=2014;
    strcpy(e.codigo,"HRP112");
    encolarOrdenaro(cola,e);
    e.fecha.dd=26;
    e.fecha.mm=06;
    e.fecha.aa=1975;
    strcpy(e.codigo,"PRL625");
    encolarOrdenaro(cola,e);
    e.fecha.dd=22;
    e.fecha.mm=10;
    e.fecha.aa=1949;
    strcpy(e.codigo,"MKP157");
    encolarOrdenaro(cola,e);
    e.fecha.dd=13;
    e.fecha.mm=05;
    e.fecha.aa=2020;
    strcpy(e.codigo,"ARH749");
    encolarOrdenaro(cola,e);
    e.fecha.dd=14;
    e.fecha.mm=02;
    e.fecha.aa=1930;
    strcpy(e.codigo,"HRQ931");
    encolarOrdenaro(cola,e);
    cout<<"Cola:";
    imprime(cola);
    return 0;
}

