

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 1 de noviembre de 2024, 09:35 PM
 */

#include <iostream>
#include <iomanip>
using namespace std;
int encontrarInicio(int arr[],int inicio,int fin){
    if(inicio==fin)return inicio;
    int medio=(inicio+fin)/2;
    if(arr[medio]==0 and arr[medio]<arr[medio+1]){
        return medio;
    }else{
        if(arr[medio]<arr[medio+1]){
            encontrarInicio(arr,inicio,medio-1);
        }else{
            encontrarInicio(arr,medio+1,fin);
        }
    }
}
int encontrarPotencia(int arr[],int inicio,int fin){
//    if(inicio==fin)return arr[inicio];
    int medio=(inicio+fin)/2;
    if(arr[medio]>arr[medio-1] and arr[medio]>arr[medio+1]){
//        cout<<medio<<endl;
        return arr[medio];
    }else{
        if(arr[medio]>=arr[medio-1]){
            encontrarPotencia(arr,medio,fin);
        }else{
            encontrarPotencia(arr,inicio,medio);
        }
    }
}
int main(int argc, char** argv) {
    int arreglo[]={0,-1,0,-1,0,1,1,2,2,3,2,2,1,1};
    int n=14;
    //primeor encontramos la posicion inicial
    int posIni=encontrarInicio(arreglo,0,n-1);
    //despues encontramos la potencia maxima
    int potencia=encontrarPotencia(arreglo,posIni,n-1);
    cout<<"La radiacion empieza a "<<posIni+1<<" km."<<endl;
    cout<<"Potencia maxima "<<potencia<<" megatones"<<endl;
    return 0;
}

