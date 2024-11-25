

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 20 de septiembre de 2024, 01:55 PM
 */

#include <iostream>
#include <iomanip>
#include "Nodo.h"
#include "Lista.h"
#include "funcionesLista.h"
using namespace std;
void fucionar(Lista &L1,Lista &L2){
    //primero complejidad O(1)
    if(L1.cola->hora<L2.cabeza->hora){
        L1.cola->siguiente=L2.cabeza;
        L1.cola=L2.cola;
    }else if(L1.cabeza->hora>L2.cola->hora){
        L2.cola->siguiente=L1.cabeza;
        L1.cabeza=L2.cabeza;
    }else{
        Nodo *ini=nullptr;
        Nodo *fin=nullptr;
        while(!esListaVacia(L1) and !esListaVacia(L2)){
            if(L1.cabeza->hora<=L2.cabeza->hora){
                if(ini==nullptr){
                    ini=L1.cabeza;
                    fin=L1.cabeza;
                }else{
                    fin->siguiente=L1.cabeza;
                    fin=L1.cabeza;
                }
                L1.cabeza=L1.cabeza->siguiente;
            }
            else{
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
        while(!esListaVacia(L1)){
            if(ini==nullptr){
                ini=L1.cabeza;
                fin=L1.cabeza;
            }else{
                fin->siguiente=L1.cabeza;
                fin=L1.cabeza;
            }
            L1.cabeza=L1.cabeza->siguiente;
        }
        while(!esListaVacia(L2)){
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
//void fucionar(Lista &co1,Lista &co2){
//    if(co1.cabeza->hora>co2.cola->hora){
//        co2.cola->siguiente=co1.cabeza;
//        co1.cabeza=co2.cabeza;
//        co1.longitud+=co2.longitud;
//    }else if (co1.cola->hora<co2.cabeza->hora){
//        co1.cola->siguiente=co2.cabeza;
//        co1.cola=co2.cola;
//        co1.longitud+=co2.longitud;
//    }else{
//        //primero creamos nodos que nos ayuden a crear la lista
//        Nodo *ini, *fin;
//        ini=nullptr;
//        fin=nullptr;
//        while(!esListaVacia(co1) and !esListaVacia(co2)){
//            //verificamos 
//            if(co1.cabeza->hora<co2.cabeza->hora){
//                //verificamos si es el primer elemento
//                if(ini==nullptr){
//                    ini=co1.cabeza;
//                    fin=co1.cabeza;
//                }else{
//                    fin->siguiente=co1.cabeza;
//                    fin=co1.cabeza;
//                }
//                //avanzo la primera lista
//                co1.cabeza=co1.cabeza->siguiente;
//                //en caso sean iguales
//            }else if(co1.cabeza->hora==co2.cabeza->hora){
//                //verificamos el dia
//                if(co1.cabeza->dia<co2.cabeza->dia){
//                    if(ini==nullptr){
//                    ini=co1.cabeza;
//                    fin=co1.cabeza;
//                    }else{
//                        fin->siguiente=co1.cabeza;
//                        fin=co1.cabeza;
//                    }
//                    //avanzo la primera lista
//                    co1.cabeza=co1.cabeza->siguiente;
//                }else{
//                    //verificamos si es el primer elemento
//                    if(ini==nullptr){
//                        ini=co2.cabeza;
//                        fin=co2.cabeza;
//                    }else{
//                        fin->siguiente=co2.cabeza;
//                        fin=co2.cabeza;
//                    }
//                    co2.cabeza=co2.cabeza->siguiente;
//                    }
//            }else if(co1.cabeza->hora>co2.cabeza->hora){
//                //verificamos si es el primer elemento
//                if(ini==nullptr){
//                    ini=co2.cabeza;
//                    fin=co2.cabeza;
//                }else{
//                    fin->siguiente=co2.cabeza;
//                    fin=co2.cabeza;
//                }
//                co2.cabeza=co2.cabeza->siguiente;
//            }
//        }
//        //Ahora verificaremos si todos los elementos fueron sacados
//        while(!esListaVacia(co1)){
//            //verificamos 
//            if(ini==nullptr){
//                ini=co1.cabeza;
//                fin=co1.cabeza;
//            }else{
//                fin->siguiente=co1.cabeza;
//                fin=co1.cabeza;
//            }   
//            //avanzo la primera lista
//            co1.cabeza=co1.cabeza->siguiente;
//        }
//        while(!esListaVacia(co2)){
//            //verificamos 
//            if(ini==nullptr){
//                ini=co2.cabeza;
//                fin=co2.cabeza;
//            }else{
//                fin->siguiente=co2.cabeza;
//                fin=co2.cabeza;
//            }   
//            //avanzo la primera lista
//            co2.cabeza=co2.cabeza->siguiente;
//        }
//        
//        //despues de ello solo procedemos a llevar esa lista, a la lista 1
//        co1.cabeza=ini;
//        co1.cola=fin;
//    }
//}
int main(int argc, char** argv) {
    Lista lunes,martes,miercoles,jueves,viernes;
    construir(lunes);
    construir(martes);
    construir(miercoles);
    construir(jueves);
    construir(viernes);
    
    insertarAlFinal(lunes,8,1);
    insertarAlFinal(lunes,10,1);
    insertarAlFinal(lunes,12,1);
    insertarAlFinal(martes,9,2);
    insertarAlFinal(martes,11,2);
    insertarAlFinal(miercoles,8,3);
    insertarAlFinal(miercoles,9,3);
    insertarAlFinal(miercoles,10,3);
    insertarAlFinal(jueves,14,4);
    insertarAlFinal(jueves,15,4);
    insertarAlFinal(jueves,16,4);
    insertarAlFinal(viernes,17,5);
    insertarAlFinal(viernes,18,5);
    insertarAlFinal(viernes,19,5);
    cout<<"Lunes: ";
    imprime(lunes);
    cout<<"Martes: ";
    imprime(martes);
    cout<<"Miercoles: ";
    imprime(miercoles);
    cout<<"Jueves: ";
    imprime(jueves);
    cout<<"Viernes: ";
    imprime(viernes);
    
    fucionar(lunes,martes);
    imprime(lunes);
    fucionar(lunes,miercoles);
    imprime(lunes);
    fucionar(lunes,jueves);
    imprime(lunes);
    fucionar(lunes,viernes);
    
    cout<<"La salida de pedidos para el sabado: ";
    imprime(lunes);
    return 0;
}

