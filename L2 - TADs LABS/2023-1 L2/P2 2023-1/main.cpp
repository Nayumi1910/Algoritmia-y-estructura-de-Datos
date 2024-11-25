

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 10 de octubre de 2024, 10:57 AM
 */

#include <iostream>
#include <iomanip>
#include "Pila.h"
#include "funcionesPila.h"
using namespace std;

void hanoi(int n,Pila &origen,Pila &destino,Pila &auxiliar){
    if(n==1){
        apilar(destino,desapilar(origen));
        return;
    }
    hanoi(n-1,origen,auxiliar,destino);
    apilar(destino,desapilar(origen));
    hanoi(n-1,auxiliar,destino,origen);
}
int main(int argc, char** argv) {
    int p=7,c=5;
    Pila pila[p];
    
    for(int i=0;i<p;i++){
        construir(pila[i]);
    }
    Elemento e;
    e.anho=2010;
    e.peso=100;
    apilar(pila[0],e);
    e.anho=2010;
    e.peso=50;
    apilar(pila[0],e);
    e.anho=2010;
    e.peso=50;
    apilar(pila[0],e);
    cout<<"Pila 1: ";
    imprimir(pila[0]);
    e.anho=2021;
    e.peso=100;
    apilar(pila[1],e);
    e.anho=2021;
    e.peso=100;
    apilar(pila[1],e);
    e.anho=2021;
    e.peso=50;
    apilar(pila[1],e);
    e.anho=2021;
    e.peso=50;
    apilar(pila[1],e);
    cout<<"Pila 2: ";
    imprimir(pila[1]);
    e.anho=2018;
    e.peso=50;
    apilar(pila[2],e);
    e.anho=2018;
    e.peso=50;
    apilar(pila[2],e);
    e.anho=2018;
    e.peso=25;
    apilar(pila[2],e);
    e.anho=2018;
    e.peso=25;
    apilar(pila[2],e);
    e.anho=2018;
    e.peso=25;
    apilar(pila[2],e);
    cout<<"Pila 3: ";
    imprimir(pila[2]);
    e.anho=2015;
    e.peso=100;
    apilar(pila[3],e);
    e.anho=2015;
    e.peso=50;
    apilar(pila[3],e);
    e.anho=2015;
    e.peso=50;
    apilar(pila[3],e);
    cout<<"Pila 4: ";
    imprimir(pila[3]);
    e.anho=2020;
    e.peso=100;
    apilar(pila[4],e);
    e.anho=2020;
    e.peso=100;
    apilar(pila[4],e);
    cout<<"Pila 5: ";
    imprimir(pila[4]);
    e.anho=2019;
    e.peso=100;
    apilar(pila[5],e);
    e.anho=2019;
    e.peso=50;
    apilar(pila[5],e);
    e.anho=2019;
    e.peso=50;
    apilar(pila[5],e);
    e.anho=2019;
    e.peso=25;
    apilar(pila[5],e);
    cout<<"Pila 6: ";
    imprimir(pila[5]);
    e.anho=2022;
    e.peso=100;
    apilar(pila[6],e);
    e.anho=2022;
    e.peso=100;
    apilar(pila[6],e);
    cout<<"Pila 7: ";
    imprimir(pila[6]);
    int m=4,n=5;
    Pila destino[n];
    construir(destino[0]);
    cout<<endl;
    cout<<"Pila 1: ";
    imprimir(destino[0]);
    int arreglo[n]={4,5,3,0};   
    for(int i=1;i<n;i++){
        construir(destino[i]);
        int tam=longitud(pila[arreglo[i-1]]);
        hanoi(tam,pila[arreglo[i-1]],destino[i],destino[0]);
        cout<<"Pila "<<i+1<<": ";
        imprimir(destino[i]);
        
    }
    return 0;
}

