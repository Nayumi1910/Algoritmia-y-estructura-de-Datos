

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 25 de septiembre de 2024, 02:14 PM
 */

#include <iostream>
#include <iomanip>

#include "funcionesCola.h"
#include "funcionesLista.h"
#include "Nodo.h"
#include "Cola.h"
#include "Lista.h"
using namespace std;

void encolarPrioridad(Cola &cola,int dato){
    Nodo *nodo=crearNodo(dato,nullptr);
    //primero vemos si es el primer elemento
    if(esColaVacia(cola)){
        //como es el primer nodo, entonces la cola y cabeza en ese nodo
        cola.lista.cabeza=nodo;
        cola.lista.cola=nodo;
        //si el elemento es V=1 es VIP
        if(nodo->elemento/10==1){
            cola.lista.vip=nodo;
        }
        //si el elemento es C=2 es Cliente
        if(nodo->elemento/10==2){
            cola.lista.cliente=nodo;
        }
        
    }else{
        //en caso de que no sean el primer elemento
        
        //vemos que tipo de prioridad tiene
        if(nodo->elemento/10==1){
            //en caso de que sea VIP
            //en caso de que sea el primer elemento de VIP
            if(cola.lista.vip==nullptr){
                // como ya existe una cabeza y no hay elemento en VIP
                //este pasa directamente a ser la cabeza y 1er elem VIP
                nodo->siguiente=cola.lista.cabeza;
                cola.lista.cabeza=nodo;
                cola.lista.vip=nodo;
            }else{
                //en caso de que no sea el primer elemento de vip
                if(cola.lista.vip->siguiente==nullptr){
                    //en caso solo exista la cola vip
                    cola.lista.cola=nodo;
                }else{
                    nodo->siguiente=cola.lista.vip->siguiente;
                }
                cola.lista.vip->siguiente=nodo;
                cola.lista.vip=nodo;
                
            }
            
        }else if(nodo->elemento/10==2){
            //primero veremos si existe nodos en la cola de Clientes
            if(cola.lista.cliente==nullptr){
                //en caso de que la cola vip sea el ultimo nodo de la cola
                if(cola.lista.cola->elemento/10==1){
                    cola.lista.cola->siguiente=nodo;
                    cola.lista.cola=nodo;
                    cola.lista.cliente=nodo;
                }
                if(cola.lista.cola->elemento/10==3){
                    //en caso de solo exista la cola de no clientes
                    if(cola.lista.vip==nullptr){
                        nodo->siguiente=cola.lista.cabeza->siguiente;
                        cola.lista.cabeza=nodo;
                        cola.lista.cliente=nodo;
                        
                    }else{
                        //en caso de que si exista cola vip
                        nodo->siguiente=cola.lista.vip->siguiente;
                        cola.lista.vip->siguiente=nodo;
                        cola.lista.cliente=nodo;
                    }
                }
                
            }else{
                //en caso de que si existan elementos
                if(cola.lista.cliente==cola.lista.cola){
                    //en caso de que el nodo cliente sea la cola de 
                    //la cola
                    cola.lista.cliente->siguiente=nodo;
                    cola.lista.cliente=nodo;
                    cola.lista.cola=nodo;
                }else{
                    //en caso de que no sea la cola
                    nodo->siguiente=cola.lista.cliente->siguiente;
                    cola.lista.cliente->siguiente=nodo;
                    cola.lista.cliente=nodo;
                }
                    
            }
        }else{
            //Si el no cliente, solo se aumenta la cola
            cola.lista.cola->siguiente=nodo;
            cola.lista.cola=nodo;
        }
    }
    cola.lista.longitud++;
}
int main(int argc, char** argv) {
    Cola cola;
    construir(cola);
    //V=1, C=2, N=3
    encolarPrioridad(cola,11);
    encolarPrioridad(cola,31);
    encolarPrioridad(cola,32);
    encolarPrioridad(cola,12);
    encolarPrioridad(cola,21);
    encolarPrioridad(cola,22);
    encolarPrioridad(cola,23);
    encolarPrioridad(cola,33);
    encolarPrioridad(cola,13);
    
    //mostramos la cola
    cout<<"La cola se muestra asi:";
    imprime(cola);
    
    int valor1,valor2;
    valor1=desencolar(cola);
    valor2=desencolar(cola);
    
    //mostramos la cola
    cout<<"Despues de atender a dos clientes:";
    imprime(cola);
    return 0;
}

