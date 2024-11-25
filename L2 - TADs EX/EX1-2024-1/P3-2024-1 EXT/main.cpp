

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 6 de octubre de 2024, 08:12 PM
 */

#include <iostream>
#include <iomanip>
#include "Cola.h"
#include "Nodo.h"
#include "funcionesCola.h"
#include "funcionesLista.h"
using namespace std;
int convertir(hora dato){
    int hh=dato.hora;
    int min=dato.min;
    return hh*60+min;
}
void ordenarCola(Cola &cola, Elemento dato){
    Nodo *nodo=crearNodo(dato,nullptr);
    if(esColaVacia(cola)){
        cola.lista.cabeza=nodo;
        cola.lista.cola=nodo;
    }else{
        Nodo *recorrer=cola.lista.cabeza;
        Nodo *ant=nullptr;
        while(recorrer!=nullptr){
            int horaDato=convertir(dato.inicio);
            int horaCola=convertir(recorrer->elemento.inicio);
            if(horaCola>horaDato){
                break;
            }
            ant=recorrer;
            recorrer=recorrer->siguiente;
        }
        if(ant!=nullptr){
            ant->siguiente=nodo;
            nodo->siguiente=recorrer;
        }else{
            nodo->siguiente=recorrer;
            cola.lista.cabeza=nodo;
        }
    }
    cola.lista.longitud++;
}

void actualizarDatos(Cola &cola,Elemento dato){
    Nodo *recorrer=cola.lista.cabeza;
    while(recorrer!=nullptr){
        if(recorrer->elemento.numVuelo==dato.numVuelo){
            recorrer->elemento.fin=dato.fin;
            return;
        }
        recorrer=recorrer->siguiente;
    }
    
}
void reOrdenarCola(Cola &cola){
    int n=cola.lista.longitud;
    if(esColaVacia(cola))return;
//    int hora1,hora2;
//    Elemento mayor,aux;
    for(int i=n;i>0;i--){
        Elemento mayor=desencolar(cola);
        int hora1=convertir(mayor.fin);
//        cout<<hora1<<endl;
//        imprime(cola);
        for(int j=1;j<n;j++){
            Elemento aux=desencolar(cola);
            int hora2=convertir(aux.fin);
//            cout<<hora2<<endl;
//            imprime(cola);
            if(hora1>=hora2){
                encolar(cola,aux);
//                imprime(cola);
            }else{
                encolar(cola,mayor);
                mayor=aux;
                hora1=hora2;
//                imprime(cola);
            }
            
        }
        encolar(cola,mayor);
        
    }
}

int main(int argc, char** argv) {
    Cola cola;
    construir(cola);
    Elemento dato;
    dato.numVuelo=2101;
    dato.inicio.hora=0;
    dato.inicio.min=55;
    dato.fin.hora=0;
    dato.fin.min=55;
    ordenarCola(cola,dato);
    dato.numVuelo=1102;
    dato.inicio.hora=1;
    dato.inicio.min=45;
    dato.fin.hora=1;
    dato.fin.min=45;
    ordenarCola(cola,dato);
    dato.numVuelo=4111;
    dato.inicio.hora=0;
    dato.inicio.min=30;
    dato.fin.hora=0;
    dato.fin.min=30;
    ordenarCola(cola,dato);
    dato.numVuelo=2105;
    dato.inicio.hora=1;
    dato.inicio.min=22;
    dato.fin.hora=1;
    dato.fin.min=22;
    ordenarCola(cola,dato);
    dato.numVuelo=3108;
    dato.inicio.hora=5;
    dato.inicio.min=25;
    dato.fin.hora=5;
    dato.fin.min=25;
    ordenarCola(cola,dato);
    
    cout<<"HORA DE LLEGADA: "<<endl;
    imprime(cola);
    dato.numVuelo=2101;
    dato.inicio.hora=0;
    dato.inicio.min=55;
    dato.fin.hora=0;
    dato.fin.min=15;
    actualizarDatos(cola,dato);
    dato.numVuelo=2105;
    dato.inicio.hora=1;
    dato.inicio.min=22;
    dato.fin.hora=2;
    dato.fin.min=10;
    actualizarDatos(cola,dato);
    cout<<"HORA DE LLEGADA ACTUALIZADA: "<<endl;
    imprime(cola);
//    cout<<longitud(cola)<<endl;
    reOrdenarCola(cola);
    cout<<"NUEVA HORA DE LLEGADA: "<<endl;
    imprime(cola);
    return 0;
}

