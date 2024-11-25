

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 26 de septiembre de 2024, 01:08 PM
 */

#include <iostream>
#include <iomanip>
#include "Pila.h"
#include "funcionesPila.h"
#define N 11
using namespace std;

int calcularFrecMaxima(int frecuencias[N],int n,int *duracion,
        double *area){
    int i=0,freMax,frec,indice,duraActual;
    double areaActual,areMax=0;
    Pila pila;
    construir(pila);
    while(i<n){
        //en caso de que sea el primer elemento d ela pila o
        //en caso de que el el valor que esta en la pila, debe ser menor
        if(esPilaVacia(pila) or frecuencias[cima(pila)]<=frecuencias[i]){
            apilar(pila,i);
            i++;
        }else{
            indice=desapilar(pila);
            frec=frecuencias[indice];
            //si la pila esta vacia, significa que volvemos al 
            //primer elemento
            if(esPilaVacia(pila)){
                areaActual=frec*i;
                duraActual=i;
            }else{
                //en caso de que no, se va planteado el area y duracion
                // en la posicion donde se encuentra la pila
                areaActual=frec*(i-indice);
                duraActual=i-indice;
            }
            //acumulamos el area y frecuencia maxima, asi como 
            //la duracion
            if(areMax<areaActual){
                areMax=areaActual;
                freMax=frec;
                *duracion=duraActual;
                *area=areMax;
            }
        }
    }
    while(!esPilaVacia(pila)){
        indice=desapilar(pila);
        frec=frecuencias[indice];
        if(esPilaVacia(pila)){
            areaActual=frec*i;
            duraActual=i;
        }else{
            areaActual=frec*(i-indice);
            duraActual=i-indice;
        }
        if(areMax<areaActual){
            areMax=areaActual;
            freMax=frec;
            *duracion=duraActual;
            *area=areMax;
        }
    }
    return freMax;
}

int main(int argc, char** argv) {
    int frecuencias[N]={1,2,1,4,5,6,4,5,2,2,1};
    int duracion=0;
    double area;
    cout << "La frecuencia maxima es: " 
            << calcularFrecMaxima(frecuencias,N,&duracion,&area) 
            << endl;
	cout << "La duracion es: " << duracion << endl;
	cout << "El area es: " << area;

    
    return 0;
}

