

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 23 de septiembre de 2024, 10:53 PM
 */

#include <iostream>
#include <iomanip>
#define N 10
#include "Pila.h"
#include "funcionesPila.h"
using namespace std;

//void detectarContagios(int intervalos[N],int contagios[N]){
//    int aux; 
//    int i=7;//i es el contador que recorrera todo el arreglo
//    int indice=i;//indice refiere al primer elemento a analizarse
//    int max=intervalos[i];//almacena el elemento del indice
//    Pila pila;
//    construir(pila);
//    while(1){
//        if(i == 0 && indice == 0){ //si el indice y el contador es 0 se acaba el while
//            contagios[indice] = 0; //ademas al ser el primero, su intervalo es 0
//            break; 
//        }
//        if(i<0){ //si el indice es menor que 0 es decir, si ya se acabo de analizar el maximo con los anteriores
//            aux = desapilar(pila);  //se hace pop de la pila que habia almacenado aquellos datos/aquel dato de la respuesta
//            contagios[indice] = aux; //el elemento pila que es un entero se almacena en el arreglo de val_crec/respuestas
//            i = indice;//el i procede a tomar el valor del indice y luego será restado en -1 saliendo de esta condicional, asi los dos marcaran el mismo inicio
//            indice = indice - 1; //el indice retrocedera en uno para marcar el nuevo inicio
//            max = intervalos[indice]; //el maximo se actualiza para realizar las siguientes comparaciones
//        }else{
//            if(i == indice){ //si el indice es igual que i
//                apilar(pila, 0);  //se coloca 0 en la pila
//            }else{ //sino se analizan dos casos
//                if(intervalos[i] < max){ //cuando el valor maximo o primero es mayor que el elemento del arreglo
//                    aux = desapilar(pila);  //se hace pop al elemento de la pila
//                    apilar(pila, aux + 1); //se hace push del elemento de la pila +1, ya que se acumula un incremento
//                }else{ //cuando el valor maximo es menor que el elemento del arreglo
//                    aux = desapilar(pila); //se hace pop del elemento de la pila, es decir hasta donde llego en acumulaciones
//                    contagios[indice] = aux; //se coloca como respuesta aquel valor
//                    i = indice;  //se resetean las variables
//                    indice = indice - 1;  //se resetean las variables
//                    max = intervalos[indice];  //se resetean las variables
//                }
//            } 
//        }
//        i--; 
//    }
//
//}
void detectarContagios(int intervalos[N],int aux[N]){
    //primero construyo la pila
    Pila pila;
    construir(pila);
    int i=7;
    int indice=i,dato;
    //ya que el ultimo valor toma ello, por mientras
    int max=intervalos[i];
    while(1){
        //caso base
        if(i==0 and indice==0){
            //ya que el primer valor, siempre tomara 0
            aux[indice]=0;
            break;
        }
        //i se tomara como un comtador
        //en caso termine de recorrer la lista, se pasara
        //al otro dato de la lista
        if(i<0){
            dato=desapilar(pila);
            aux[indice]=dato;
            i=indice;
            indice=indice-1;
            //modificamos el maximo valor tambiem
            max=intervalos[indice];
        }else{
            if(i==indice){
                //en caso sea le primer elemento
                apilar(pila,0);
            }else{
                if(intervalos[i]<max){
                    // en caso de que sea menor,
                    //se sigue apilando
                    dato=desapilar(pila);
                    apilar(pila,dato+1);
                }else{
                    //en caso de que no, se guarda en 
                    //el arreglo auxiliar, y se pasa al
                    //siguiente dato
                    dato=desapilar(pila);
                    aux[indice]=dato;
                    i=indice;
                    indice=indice-1;
                    max=intervalos[indice];
                }
            }
            
        }
        i--;
    }
}
int main(int argc, char** argv) {
    int intervalos[N]={10,20,15,10,12,10,13,18};
    int aux[N]={};
    detectarContagios(intervalos,aux);
    for(int i=0;i<8;i++){
        cout<<aux[i]<<" ";
    }
    return 0;
}

