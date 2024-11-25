

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 7 de octubre de 2024, 03:20 PM
 */

#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include "funcionesLista.h"
#include "Lista.h"
#include "Nodo.h"
using namespace std;
void fusionar(Lista &L1,Lista &L2){
    Nodo *ini=nullptr,*fin=nullptr;
    while(L1.cabeza!=nullptr and L2.cabeza!=nullptr){
        if(L1.cabeza->elemento<=L2.cabeza->elemento){
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
    if(L1.cabeza==nullptr and L2.cabeza!=nullptr){
        while(L2.cabeza!=nullptr){
            fin->siguiente=L2.cabeza;
            fin=L2.cabeza;
            L2.cabeza=L2.cabeza->siguiente;
        }
    }else if(L1.cabeza!=nullptr and L2.cabeza==nullptr){
        while(L1.cabeza!=nullptr){
        fin->siguiente=L1.cabeza;
        fin=L1.cabeza;
        L1.cabeza=L1.cabeza->siguiente;
        }
    }
    L1.cabeza=ini;
    L1.cola=fin;
    L1.longitud+=L2.longitud;
}
void cargabin(int num,int cromo[],int n){
    for(int i=0;i<n;i++){
        cromo[i]=0;
    }
    int aux,i=0;
    while(num>0){
        aux=num%2;
        num=num/2;
        cromo[i]=aux;
        i++;
    }
}
int buscarPosicion(char productos[],int cantLista,char tipo){
    for(int i=0;i<cantLista;i++){
        if(productos[i]==tipo)return i;
    }

}
int verificar(Lista *listas,int cantLista,char tiposSeleccionados[],
        int cantTipos[],int maxTipos[],char productos[], int cant,
        Lista *formula){
    int cumple=0;
    int solucion[cant];
    for(int i=0;i<cant;i++){
        int pos=buscarPosicion(productos,cantLista,tiposSeleccionados[i]);
        int tam=longitud(listas[pos]);
        int comb=pow(2,tam);
        int cromo[tam];
        int suma;
        for(int k=0;k<comb;k++){
            cargabin(k,cromo,tam);
            Nodo *recorrer=listas[pos].cabeza;
            suma=0;
            int cantA=0;
            for(int j=0;j<tam;j++){
                if(cromo[j]==1){
                    suma+=recorrer->elemento;
                    cantA++;
                }
                recorrer=recorrer->siguiente;
            }
            if(cantA==cantTipos[i] and suma<=maxTipos[i]){
                solucion[i]=k;
                cumple=1;
            }
        }
    }
    
    for(int i=0;i<cant;i++){
        int pos=buscarPosicion(productos,cantLista,tiposSeleccionados[i]);
        int tam=longitud(listas[pos]);
        int cromo[tam];
        cargabin(solucion[i],cromo,tam);
        Nodo *recorrer=listas[pos].cabeza;
        for(int k=0;k<tam;k++){
            if(cromo[k]==1){
                insertarAlFinal(formula[i],recorrer->elemento);
            }
            recorrer=recorrer->siguiente;
        }
    }
    
    for(int i=0;i<cant;i++){
        cout<<"Calorias de los productos "<<tiposSeleccionados[i]<<":";
        imprime(formula[i]);
    }
    return cumple;
}

int main(int argc, char** argv) {
  
    ifstream arch("datos.txt",ios::in);
    if(!arch.is_open()){
        cout<<"Error de archivo"<<endl;
        exit(1);
    }
    int n;
    arch>>n;
    Lista listas[n];
    for(int i=0;i<n;i++){
        construir(listas[i]);
    }
    //leer cada lista
    char productos[n];
    int i=0,dato;
    for(int i=0;i<n;i++){
        arch>>productos[i];
//        if(productos[i]=='-')break;
        while(1){
            arch>>dato;
            if(dato==0)break;
            insertarAlFinal(listas[i],dato);
        }
    }
    for(int i=0;i<n;i++){
        cout<<"Tipo "<<productos[i]<<": "<<endl;
        imprime(listas[i]);
    }
    
    //Ahora se ingresará la formula 
    char tipo;
    char tiposSeleccionados[n];
    int cantTipos[n],maxTipos[n];
    int cant=0;
    while(1){
        arch>>tipo;
        if(tipo=='-')break;
        tiposSeleccionados[cant]=tipo;
        arch>>cantTipos[cant]>>maxTipos[cant];
        cant++;
    }
    
    //Ahora imprimimos esa informacion para verificar
    for(int i=0;i<cant;i++){
        cout<<"Tipo de Producto: "<<tiposSeleccionados[i]<<endl;
        cout<<"Cantidad de Productos del tipo "<<tiposSeleccionados[i]<<":"
                <<cantTipos[i]<<endl;;
        cout<<"Total de calorias maxima de todos los productos: "
                <<maxTipos[i]<<endl;;
    }
    //creamos formular par almacenar
    Lista formula[cant];
    for(int i=0;i<cant;i++){
        construir(formula[i]);
    }
    //con toda la informacion leida, procedemos a hacer el inciso B
    int existe=verificar(listas,n,tiposSeleccionados,cantTipos,maxTipos
    ,productos,cant, formula);
    
    if(existe){
        cout<<"Si existe la combinacion de la formula"<<endl;
    }else{
        cout<<"No existe la combinacion"<<endl;
    }
    
    //Las formulas obtenidas las combinamos
    cout<<"La formula obtenida es: ";
    if(cant==1){
        imprime(formula[cant]);
    }else{
        for(int i=1;i<cant;i++){
            fusionar(formula[0],formula[i]);
        }
        imprime(formula[0]);
    }
    
    
    return 0;
}

