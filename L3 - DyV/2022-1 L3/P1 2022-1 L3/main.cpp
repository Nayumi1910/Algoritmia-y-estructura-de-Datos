

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 28 de octubre de 2024, 03:12 PM
 */

#include <iostream>
#include <iomanip>
using namespace std;
int max(int a,int b){
    if(a>b){
        return a;
    }else{
        return b;
    }
}
int calculoIncrementosMedio(int *intervalos,int ini,int medio,int fin){
    int izq=1,der=1;
    if(intervalos[medio]>intervalos[medio+1]){
        return 1;//debido a que pasamos al siguiente
    }
    //contamos los menores que estan a la izq
    for(int i=medio;i>ini;i++){
        if(intervalos[i]>intervalos[i-1]){
            izq++;
        }else{
            break;
        }
    }
    //contamos los mayores a la dre
    for(int i=medio+1;i<fin;i++){
        if(intervalos[i]<intervalos[i+1]){
            der++;
        }else{
            break;
        }
    }
    return der+izq;
}
int calculoIncrementos(int *intervalos,int ini,int fin){
    if(ini==fin)return 1;
    int medio=(ini+fin)/2;
    int izq=calculoIncrementos(intervalos,ini,medio);
    int der=calculoIncrementos(intervalos,medio+1,fin);
    int centro=calculoIncrementosMedio(intervalos,ini,medio,fin);
    return max(max(izq,der),centro);
}
int main(int argc, char** argv) {
    int intervalos[]={10,20,15,10,12,10,13,18};
    int tam=sizeof(intervalos)/sizeof(intervalos[0]);
    int incrementos=calculoIncrementos(intervalos,0,tam-1);
    
    cout<<"Intervalo de: "<<incrementos<<endl;
    cout<<"Indice : "<<(double)incrementos/tam<<endl;
    return 0;
}

