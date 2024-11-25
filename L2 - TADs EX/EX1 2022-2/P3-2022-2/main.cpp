

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 26 de septiembre de 2024, 07:13 PM
 */

#include <iostream>
#include <iomanip>

#include "Lista.h"
#include "funcionesLista.h"
#include "funcionesCola.h"
#include "Nodo.h"
#include "Cola.h"
using namespace std;

void cribaLista(Lista &lista,int n){
    Cola cola;
    construir(cola);
    Nodo *recorrer=lista.cabeza;
    for(int i=0;i<n;i++)recorrer=recorrer->siguiente;
    if(recorrer==nullptr)return;
    int dato=recorrer->elemento;
    recorrer=recorrer->siguiente;
    while(recorrer!=nullptr){
        int datoN=recorrer->elemento;
        recorrer=recorrer->siguiente;
        if(datoN%dato==0){
            encolar(cola,datoN);
            eliminar(lista,datoN);
        }
        
    }
    cout<<"Numero procesado "<<dato<<" :";
    imprime(cola);
    cribaLista(lista,n+1);
}
int main(int argc, char** argv) {
    Lista lista;
    construir(lista);
    int n=15;
    for(int i=1;i<n;i++){
        insertarAlFinal(lista,i+1);
    }
    cout<<"Lista: ";
    imprime(lista);
    int arr[6]={2,3,5,7,11,13};
    cribaLista(lista,0);
    cout<<"Lista procesada: ";
    imprime(lista);
    return 0;
}

