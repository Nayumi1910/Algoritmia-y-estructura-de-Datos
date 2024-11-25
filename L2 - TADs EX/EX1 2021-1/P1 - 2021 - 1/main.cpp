

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 24 de septiembre de 2024, 06:41 PM
 */

#include <iostream>
#include <iomanip>
#include "Cola.h"
#include "Pila.h"
#include "funcionesCola.h"
#include "funcionesPila.h"
#include "Nodo.h"
using namespace std;
void reclasificar(Pila &pila,Pila &p1,Pila &p2){
    while(pila.lista.cabeza!=nullptr){
        int valor=pila.lista.cabeza->elemento/100;
        if(valor==1){
            apilar(p1,desapilar(pila));
        }else{
            apilar(p2,desapilar(pila));
        }
    }

}
void reordenar(Cola &cola,Pila &p1,Pila &p2){
    int valor;
    Pila aux;
   construir(aux);
   //Primero pasamos toda la cola a la pila auxiliar
   while(cola.lista.cabeza!=nullptr){
       valor=desencolar(cola);
       apilar(aux,valor);
   }
   cout<<"Robot aux: ";
    imprimir(aux);
    //volvemos a encolar
    while(aux.lista.cabeza!=nullptr){
        valor=desapilar(aux);
        encolar(cola,valor);
    }
    cout<<"Cola: ";
    imprime(cola);
   //con la cola ya revertida, procedemos a encolar los datos que estan
    //en las pilas aux, y apilamos en la auxliar los datos de la cola
    //todo hasta que las pilas esten vacias
    int v1,v2;
    while(1){
        if(p1.lista.cabeza==nullptr and p2.lista.cabeza==nullptr){
            break;
        }
        if(p2.lista.cabeza==nullptr and p1.lista.cabeza!=nullptr){
            apilar(aux,desencolar(cola));
            encolar(cola,desapilar(p1));
            cout<<"Cola 1: ";
            imprime(cola);
        }else if(p1.lista.cabeza==nullptr and p2.lista.cabeza!=nullptr){
            apilar(aux,desencolar(cola));
            encolar(cola,desapilar(p2));
            cout<<"Cola 2: ";
            imprime(cola);
        }else{
            v1=p1.lista.cabeza->elemento%100;
            v2=p2.lista.cabeza->elemento%100;
            if(v1>v2){
                apilar(aux,desencolar(cola));
                encolar(cola,desapilar(p1));
            }else{
                apilar(aux,desencolar(cola));
                encolar(cola,desapilar(p2));
            }
            cout<<"Cola 3: ";
            imprime(cola);
        }
    }
    cout<<"Robot aux: ";
    imprimir(aux);
    cout<<"Cola: ";
    imprime(cola);
    //reclasificamos en las pilas 1 y 2 los elementos que 
    //quedaron en la pila auxiliar
    reclasificar(aux,p1,p2);
    //cambiamos de posicion, por lo que volvemos a pasar los
    //elementos a la pila auxiliar
     while(cola.lista.cabeza!=nullptr){
       valor=desencolar(cola);
       apilar(aux,valor);
   }
   cout<<"Robot aux: ";
    imprimir(aux);
    //volvemos a encolar
    while(aux.lista.cabeza!=nullptr){
        valor=desapilar(aux);
        encolar(cola,valor);
    }
    cout<<"Cola: ";
    imprime(cola);
   
}

int main(int argc, char** argv) {
    Cola cola;
    construir(cola);
    //los elementos A=1, P=2
    encolar(cola,100);
    encolar(cola,101);
    encolar(cola,202);
    encolar(cola,203);
    encolar(cola,104);
    encolar(cola,205);
    encolar(cola,206);

    cout<<"Cola original: ";
    imprime(cola);
    
    //Se realiza la retención 
    Pila pila1,pila2;
    construir(pila1);
    construir(pila2);
    int n=7;
    apilar(pila1,desencolar(cola));
    apilar(pila1,desencolar(cola));
    apilar(pila2,desencolar(cola));
    apilar(pila2,desencolar(cola));
    apilar(pila1,desencolar(cola));
    encolar(cola,107);
    encolar(cola,108);
    encolar(cola,209);
    encolar(cola,110);
    encolar(cola,211);
    cout<<"Cola despues de la retencion: ";
    imprime(cola);
    cout<<"Primer Robot: ";
    imprimir(pila1);
    cout<<"Segundo Robot: ";
    imprimir(pila2);
    
    reordenar(cola,pila1,pila2);
    cout<<"Cola despues del reordenamiento: ";
    imprime(cola);
    cout<<"Primer Robot: ";
    imprimir(pila1);
    cout<<"Segundo Robot: ";
    imprimir(pila2);

    return 0;
}

