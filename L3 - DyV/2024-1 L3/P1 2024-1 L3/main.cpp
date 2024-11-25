

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 1 de noviembre de 2024, 09:10 PM
 */

#include <iostream>
#include <iomanip>
using namespace std;
int min(int a,int b){
    if(a<b){
        return a;
    }else{
        return b;
    }
}
int encontrarNegativoMedio(int paquete[],int ini,int med,int fin){
    int izq=999,der=99;
    int suma;
    suma=0;
    for(int i=med;i>=ini;i--){
        suma+=paquete[i];
        if(suma<izq){
            izq=suma;
        }
    }
    suma=0;
    for(int i=med+1;i<=fin;i++){
        suma+=paquete[i];
        if(suma<der){
            der=suma;
        }
    }
    return min(der,min(izq,der+izq));
//    return der+izq;
}
int encontrarNegativo(int paquete[],int ini,int fin){
    if(ini==fin)return 0;
    int medio=(ini+fin)/2;
    int izq=encontrarNegativo(paquete,ini,medio);
    int der=encontrarNegativo(paquete,medio+1,fin);
    int centro=encontrarNegativoMedio(paquete,ini,medio,fin);
    return min(min(der,izq),centro);
}
int main(int argc, char** argv) {
//    int paquete[]={2,5,-6,2,3,-1,-5,6};
    int paquete[]={2,-3,4,-5,-7};
//    int paquete[]={-4,5,6,-4,3,-1,-5,6};
    int n=8,m=5;
    int mayor=encontrarNegativo(paquete,0,m-1);
    cout<<mayor<<endl;
    return 0;
}

