

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 2 de octubre de 2024, 09:16 PM
 */

#include <iostream>
#include <iomanip>

#include "Cola.h"
#include "funcionesCola.h"
#include "Pila.h"
#include "funcionesPila.h"
using namespace std;

void reinicia_cola(Cola &cola,int n,Pila &p1,Pila &p2){
    while(!esPilaVacia(p2)){
        int dato=desapilar(p2);
        apilar(p1,dato);
    }
//    cout<<"Pila 1: ";
//    imprimir(p1);
    //ordenar pila
    int devolver,datos;
    while(!esPilaVacia(p1)){
        //despailo el primer elememnto
        datos=desapilar(p1);
        //despues de ello, compruebo si la pila2 esta vacia o no
        //si esta vacia pues coloco el elemento,
        //ya que despues voy a compararlo
        if(esPilaVacia(p2)){
            apilar(p2,datos);
        }else{
            //en caso de que no este vacia, procedere a comparar
            if(datos%100<cima(p2)%100){
                //en caso de que el dato sea menor a la cima
                //se procedera a apilar
                apilar(p2,datos);
            }else{
                //en caso de que no sea menor, se procedera a desapilar
                // y apilar a la pila 1 a los elmentos menores
                while(datos%100>cima(p2)%100){
                    devolver=desapilar((p2));
                    apilar(p1,devolver);
                    if(esPilaVacia(p2))break;
                }
                //si se llega a la condicion o la pila 2 esta vacia
                //se procede a apilar el valor
                apilar(p2,datos);
            }
        }
        
    }
    
    //despues de ordenar,, como todo esta en la pila 2, lo pasaremos a la pila1
    while(!esPilaVacia(p2)){
        int valor=desapilar(p2);
        int n=0;
        while(!esPilaVacia(p2)){
            apilar(p1,valor);
            valor=desapilar(p2);
            n++;
        }
        for(int i=1;i<=n;i++){
            apilar(p2,desapilar(p1));
        }
        apilar(p1,valor);
    }
    
    //paso 3
    int azul=longitud(p1);
    int verde=longitud(p1);
    int anaranjado=cola.lista.longitud-longitud(p1);
    
    for(int i=0;i<anaranjado;i++){
        encolar(cola,desencolar(cola));
    }
    
    for(int i=0;i<azul;i++){
        apilar(p2,desencolar(cola));
    }
    
    for(int i=0;i<verde;i++){
        encolar(cola,desapilar(p1));
    }
    for(int i=0;i<anaranjado;i++){
        encolar(cola,desencolar(cola));
    }
    
}
void reclasifica_pilas(Pila &p1,Pila &p2){
    Cola aux;
    construir(aux);
    while(!esPilaVacia(p2)){
        int valor=desapilar(p2); 
        if(valor/100==2)apilar(p1,valor);
        else{
            encolar(aux,valor);
        }
    }
    while(!esColaVacia(aux)){
        int valor=desencolar(aux);
        apilar(p2,valor);
    }
}
int main(int argc, char** argv) {
    Cola cola;
    construir(cola);
    encolar(cola,206);
    encolar(cola,107);
    encolar(cola,208);
    encolar(cola,109);
    encolar(cola,210);
    encolar(cola,211);
    encolar(cola,112);
    encolar(cola,113);
    Pila pila1,pila2;
    construir(pila1);
    construir(pila2);
    apilar(pila2,203);
    apilar(pila2,204);
    apilar(pila1,101);
    apilar(pila1,102);
    apilar(pila1,105);
    cout<<"Inicial: "<<endl;
    cout<<"Cola: ";
    imprime(cola);
    cout<<"Pila 1: ";
    imprimir(pila1);
    cout<<"Pila 2: ";
    imprimir(pila2);
    int n=8;
    cout<<"Reinicia Cola:"<<endl;
    reinicia_cola(cola,n,pila1,pila2);
    cout<<"Cola: ";
    imprime(cola);
    cout<<"Pila 1: ";
    imprimir(pila1);
    cout<<"Pila 2: ";
    imprimir(pila2);
    cout<<"Reclasifica Cola:"<<endl;
    reclasifica_pilas(pila1,pila2);
    cout<<"Cola: ";
    imprime(cola);
    cout<<"Pila 1: ";
    imprimir(pila1);
    cout<<"Pila 2: ";
    imprimir(pila2);
    
    return 0;
}

