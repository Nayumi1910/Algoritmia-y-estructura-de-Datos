

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 25 de septiembre de 2024, 12:06 AM
 */

#include <iostream>
#include <iomanip>
#include "Pila.h"
#include "funcionesPila.h"
using namespace std;
void pasarPila(Pila &pila,Pila caja[4],int n,int c){
    int valor,i=0,cantE=0,cantP=0;
    while(true){
        if(i>3)break;
        valor=desapilar(caja[i]);
        apilar(pila,valor);
        cantE++;
        cantP++;
        if(cantP==c){
            i++;
            cantP=0;
        }
        if(cantE==n-1)break;
    }
}
void reordernar(Pila &pila,Pila caja[4],int n,int c){
    //tenemos un dato para el mayor, y otro para lo elmentos a 
    //desapilar
    if(n==1)return;
    int mayor, valor;
    int j=0,cant=0;
    //el mayor sera el primer elemento
    mayor=desapilar(pila);
    for(int i=1;i<n;i++){
        //desapilamos
        valor=desapilar(pila);

        //primero verificamos
        //si el nuevo elemento a desapilar es mayor
        if(valor>=mayor){
            //apilamos el antiguo mayor a una de las cajas
            apilar(caja[j],mayor);
            //actualizamos el nuevo mayor
            mayor=valor;
        }else{
            //en caso de que el mayor siga siendo el mismo
            //apilamos el otro elemento
            apilar(caja[j],valor);
        }
        //con cualquier de los dos, se agrega un nuevo elemento
        //por lo tanto
        cant++;

        //en caso de que la cant sea igual a la capacidad de cada
        //caja, procedemos a resetar y asignar la caja siguiente
        if(cant==c){
            j++;
            cant=0;
        }
        
    }
    
    //como ya tengo todos los elemento en las cajas, lo pasamos
    //de nuevo a la pila general
    pasarPila(pila,caja,n,c);
    //despues de pasar la Pila, realizamos la recursion para los demás
    //datos de la pila
    reordernar(pila,caja,n-1,c);
    //despues de llegar a la ultima recursion, apilamos el mayor
    apilar(pila,mayor);
    
}
void pasarAlasCajas(Pila &pila,Pila caja[4],int n,int c){
    int valor,i=0,cantP=0;
    while(!esPilaVacia(pila)){
        valor=desapilar(pila);
        apilar(caja[i],valor);
        cantP++;
        if(cantP==c){
            i++;
            cantP=0;
        }
        if(i>3)break;
    }
}

int main(int argc, char** argv) {
    Pila pila,caja[4];
    construir(pila);

    int n=10,c=3;
    for(int i=0;i<4;i++){
        construir(caja[i]);
    }
    //apilo los elementos
    apilar(pila,20110603);
    apilar(pila,20221006);
    apilar(pila,20220630);
    apilar(pila,20220918);
    apilar(pila,20221003);
    apilar(pila,20221106);
    apilar(pila,20220814);
    apilar(pila,20221212);
    apilar(pila,20221130);
    apilar(pila,20221224);
    cout<<"Pila principal: ";
    imprimir(pila);
    //ahora reordenamos todo
    reordernar(pila,caja,n,c);
//    cout<<"Pila principal: ";
//    imprimir(pila);
    pasarAlasCajas(pila,caja,n,c);
    cout<<"Pila 1: ";
    imprimir(caja[0]);
    cout<<"Pila 2: ";
    imprimir(caja[1]);
    cout<<"Pila 3: ";
    imprimir(caja[2]);
    cout<<"Pila 4: ";
    imprimir(caja[3]);
    
    return 0;
}

