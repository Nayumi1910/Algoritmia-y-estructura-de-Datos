

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 25 de septiembre de 2024, 04:45 PM
 */

#include <iostream>
#include <iomanip>
#include "Lista.h"
#include "funcionesLista.h"
#include "Nodo.h"
using namespace std;

void volverLista(Nodo *actual,Lista &procesos,int t){
    int estado=actual->tiempo-t;
    if(estado>0){
        actual->tiempo=estado;
        insertarAlFinal(procesos,actual->tiempo,actual->numero);
    }else{
        cout<<"Se completo proceso #"<<actual->numero<<endl;
    }
}

int main(int argc, char** argv) {
    Lista procesos;
    construir(procesos);
    
    int numP, T, tiempo;
    cout<<"# de procesos: ";
    cin>>numP;
    cout<<"T: ";
    cin>>T;
    
    cout<<"Duraciones inciales de procesos:";
    int i;
    for(i=0;i<numP;i++){
        cin>>tiempo;
        insertarAlFinal(procesos,tiempo,i+1);
    }
    int confirmar;
    Nodo *actual=procesos.cabeza;
    while(!esListaVacia(procesos) and actual!=nullptr){
        cout<<"Se ejecuto el proceso "<<actual->numero<<endl;
        volverLista(actual,procesos,T);
        actual=actual->siguiente;
        eliminaCabeza(procesos);
        cout<<"Desea insertar un nuevo proceso?";
        cin>>confirmar;
        if(confirmar){
            cout<<"Indicar duracion de proceso "<<i+1;
            cin>>tiempo;
            insertarAlInicio(procesos,tiempo,i+1);
            actual=actual->siguiente;
            i++;
        }
    }
    return 0;
}

