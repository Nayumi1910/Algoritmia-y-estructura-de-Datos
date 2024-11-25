

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 30 de septiembre de 2024, 07:23 PM
 */

#include <iostream>
#include <iomanip>

#include "Lista.h"
#include "funcionesLista.h"
#include "Nodo.h"
using namespace std;
void insertarA(struct Lista & tad, int elemento) {
    // Si la lista está vacía, se inserta al inicio
    if (esListaVacia(tad)) {
        Nodo* nuevoNodo = new Nodo;
        nuevoNodo->elemento = elemento;
        nuevoNodo->siguiente = nullptr;
        tad.cabeza = nuevoNodo;
        tad.cola = nuevoNodo;
    } else {
        Nodo* aux = tad.cabeza;
        Nodo* anterior = nullptr;

        // Buscar la posición correcta para insertar el nuevo nodo
        while (aux != nullptr && aux->elemento < elemento) {
            anterior = aux;
            aux = aux->siguiente;
        }

        Nodo* nuevoNodo = new Nodo;
        nuevoNodo->elemento = elemento;

        // Si el nuevo nodo se inserta al principio
        if (anterior == nullptr) {
            nuevoNodo->siguiente = tad.cabeza;
            tad.cabeza = nuevoNodo;
            if (tad.cola == nullptr) {  // Si la lista solo tenía un elemento
                tad.cola = nuevoNodo;
            }
        }
        // Si el nuevo nodo se inserta al final o en medio
        else {
            nuevoNodo->siguiente = anterior->siguiente;
            anterior->siguiente = nuevoNodo;

            // Si se inserta al final
            if (nuevoNodo->siguiente == nullptr) {
                tad.cola = nuevoNodo;
            }
        }
    }
    tad.longitud++;
}
void formarGrupos(Lista &lista, Lista &L1, Lista &L2,
        Lista &L3, int &n1, int &n2, int &n3){
    Nodo *nodo=lista.cabeza;
    while(nodo!=nullptr){
        int valor=nodo->elemento%10;
        int dato=nodo->elemento/10;
//        cout<<valor<<" "<<dato<<endl;
        if(valor==1){
            insertarA(L3,dato);
            n1+=dato;
        }
        if(valor==2){
            insertarA(L2,dato);
            n2+=dato;
        }
        if(valor==3){
            insertarA(L1,dato);
            n3+=dato;
        }
        nodo=nodo->siguiente;
    }

}
void fusionar(Lista &peach,Lista &donkey){
    while(!esListaVacia(donkey)){
        int dato=retornaCabeza(donkey);
        insertarA(peach,dato);
        donkey.cabeza=donkey.cabeza->siguiente;
    }
}
int main(int argc, char** argv) {
    Lista bowser,peach,donkey, lista;
    construir(lista);
    construir(bowser);
    construir(peach);
    construir(donkey);
    int n=2;
    int cant=12;
    int nivel1=0,nivel2=0,nivel3=0;
    insertarAlInicio(lista,241);
    insertarAlInicio(lista,391);
    insertarAlInicio(lista,841);
    insertarAlInicio(lista,561);
    insertarAlInicio(lista,103);
    insertarAlInicio(lista,653);
    insertarAlInicio(lista,352);
    insertarAlInicio(lista,851);
    insertarAlInicio(lista,262);
    insertarAlInicio(lista,123);
    insertarAlInicio(lista,182);
    insertarAlInicio(lista,723);
    cout<<"Lista de guerreros: ";
    imprime(lista);
    formarGrupos(lista,donkey,peach,bowser,nivel1,nivel2,nivel3);
    cout<<"Ejercitos formados: "<<endl;
    cout<<"Ejercito 1- Bowser: ";
    imprime(bowser);
    cout<<"Nivel de ataque total del ejercitos 1: "<<nivel1<<endl;
    cout<<"Ejercito 2- Peach: ";
    imprime(peach);
    cout<<"Nivel de ataque total del ejercitos 2: "<<nivel2<<endl;
    cout<<"Ejercito 3- Donkey: ";
    imprime(donkey);
    cout<<"Nivel de ataque total del ejercitos 3: "<<nivel3<<endl;
    int flag =0, termino=0;
    while(true){ 
        int i=0;
        if(esListaVacia(bowser) or esListaVacia(peach)){
            cout<<"Nivel de ataque total del ejercitos 1: "<<nivel1<<endl;
            cout<<"Nivel de ataque total del ejercitos 2: "<<nivel2<<endl;
            if(nivel1==0){
                cout<<"Gano Peach"<<endl;
            }
            if(nivel2==0){
                cout<<"Gano Bowser"<<endl;
            }
            break;
        }
        
        cout<<"Inicia batalla:"<<endl;
        cout<<"Ejercito 1- Bowser: ";
        imprime(bowser);
        cout<<"Ejercito 2- Peach: ";
        imprime(peach);
        Nodo *bows=bowser.cabeza;
        Nodo *pea=peach.cabeza;
        while(true){
            
            if(i==n){
                cout<<"Nivel de ataque total del ejercitos 1: "<<nivel1<<endl;
                cout<<"Nivel de ataque total del ejercitos 2: "<<nivel2<<endl;
                if(flag==0 and nivel2<nivel1){
                   cout<<"El ejército de DonKey Kong se une al ejército de Peach"<<endl;
                   fusionar(peach,donkey);
                   nivel2+=nivel3;
                   flag=1; 
                }
                else if(flag==1 and i==n){
                    cout<<"Ya no se puede unir nadie al ejército de Peach. "<<endl;
                }
                break;
            }
            cout<<"Pelea "<<i+1<<": "<<bows->elemento<<" vs "
                    <<pea->elemento<<", gana ";
            if(bows->elemento>pea->elemento){
                cout<<bows->elemento<<endl;
                if(bows->siguiente==nullptr){
                    nivel2-=pea->elemento;
                    peach.cabeza=peach.cabeza->siguiente;
                    pea=peach.cabeza;
                    if(pea==nullptr){
                        break;
                    } 
                    break;
                }
                bows=bows->siguiente; 
                nivel2-=pea->elemento;
                peach.cabeza=peach.cabeza->siguiente;
                pea=peach.cabeza;
                if(pea==nullptr){
                    break;
                }  
            }else{
                cout<<pea->elemento<<endl;
                if(pea->siguiente==nullptr){
                    nivel1-=bows->elemento;
                    bowser.cabeza=bowser.cabeza->siguiente;
                    bows=bowser.cabeza;
                    bows=bowser.cabeza;
                    if(bows==nullptr){
                        break;
                    } 
                    break;
                }
                pea=pea->siguiente; 
                nivel1-=bows->elemento;
                bowser.cabeza=bowser.cabeza->siguiente;
                bows=bowser.cabeza;
                if(bows==nullptr){
                    break;
                } 
            }
            
            i++;
        }
        
    }

    return 0;
}

