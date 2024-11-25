

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 25 de septiembre de 2024, 11:54 PM
 */

#include <iostream>
#include <iomanip>
#include "Lista.h"
#include "funcionesLista.h"
#include "Nodo.h"
using namespace std;
//void fusionar(Lista &l1,Lista &l2){
//    //primero vemos si la cola y cabeza se pueden fusional asi no más
//    if(l1.cola->hora<l2.cabeza->hora){
//        l1.cola->siguiente=l2.cabeza;
//        l1.cola=l2.cola;
//    }else if(l2.cola->hora<l1.cabeza->hora){
//        l2.cola->siguiente=l1.cabeza;
//        l1.cabeza=l2.cabeza;
//    }else{
//        //en caso de que las listas se deban fusionar
//        Nodo *ini=nullptr,*fin=nullptr;
//        
//        while(!esListaVacia(l1) and !esListaVacia(l2)){
//           
//            if(l1.cabeza->hora<=l2.cabeza->hora){
//                if(ini==nullptr){
//                    ini=l1.cabeza;
//                    fin=l1.cabeza;
//                }else{
//                    fin->siguiente=l1.cabeza;
//                    fin=l1.cabeza;
//                }
//                l1.cabeza=l1.cabeza->siguiente;
//            }else{
//                if(ini==nullptr){
//                    ini=l2.cabeza;
//                    fin=l2.cabeza;
//                }else{
//                    fin->siguiente=l2.cabeza;
//                    fin=l2.cabeza;
//                }
//                l2.cabeza=l2.cabeza->siguiente;
//            }
//        }
//        while(!esListaVacia(l2)){
//                if(ini==nullptr){
//                    ini=l2.cabeza;
//                    fin=l2.cabeza;
//                }else{
//                    fin->siguiente=l2.cabeza;
//                    fin=l2.cabeza;
//                }
//                l2.cabeza=l2.cabeza->siguiente;
//        }
//        while(!esListaVacia(l1)){
//                if(ini==nullptr){
//                    ini=l1.cabeza;
//                    fin=l1.cabeza;
//                }else{
//                    fin->siguiente=l1.cabeza;
//                    fin=l1.cabeza;
//                }
//                l1.cabeza=l1.cabeza->siguiente;
//        }
//        l1.cabeza=ini;
//        l1.cola=fin;
//    }
//    
//}
void fusionar(Lista &L1,Lista &L2){
    if(L1.cola->hora<L2.cabeza->hora){
        L1.cola->siguiente=L2.cabeza;
        L1.cola=L2.cola;
    }else if(L1.cabeza->hora>L2.cola->hora){
        L2.cola->siguiente=L1.cabeza;
        L1.cabeza=L2.cabeza;
    }else{
        Nodo *ini=nullptr,*fin=nullptr;
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
int main(int argc, char** argv) {
    Lista lunes, martes, miercoles, jueves, viernes;
    construir(lunes);
    insertarAlFinal(lunes,8,6);
    insertarAlFinal(lunes,10,14);
    insertarAlFinal(lunes,12,1);
    construir(martes);
    insertarAlFinal(martes,9,3);
    insertarAlFinal(martes,11,8);
    construir(miercoles);
    insertarAlFinal(miercoles,8,2);
    insertarAlFinal(miercoles,9,5);
    insertarAlFinal(miercoles,10,10);
    construir(jueves);
    insertarAlFinal(jueves,14,13);
    insertarAlFinal(jueves,15,9);
    insertarAlFinal(jueves,16,11);
    construir(viernes);
    insertarAlFinal(viernes,17,4);
    insertarAlFinal(viernes,18,12);
    insertarAlFinal(viernes,19,7);
    
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
    
    //procedemos a fusionar listas
    fusionar(lunes,martes);
    cout<<"Fusion 1: ";
    imprime(lunes);
    fusionar(lunes,miercoles);
    cout<<"Fusion 2: ";
    imprime(lunes);
    fusionar(lunes,jueves);
    cout<<"Fusion 3: ";
    imprime(lunes);
    fusionar(lunes,viernes);
    cout<<"Fusion 4: ";
    imprime(lunes);
    return 0;
}

