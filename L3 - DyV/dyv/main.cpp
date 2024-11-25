

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 21 de octubre de 2024, 11:15 AM
 */

#include <iostream>
#include <iomanip>
using namespace std;

int cuentaceros(int arr[],int ini,int fin, int cont){
    if(ini>fin)return cont;
    int medio=(ini+fin)/2;
    if(arr[medio]==0){
        cuentaceros(arr,ini,medio-1,cont+fin-medio+1);
    }else{
        cuentaceros(arr,medio+1,fin,cont);
    }
    
}
int cuentaUno(int arr[],int ini,int fin, int cont){
    if(ini>fin)return cont;
    int medio=(ini+fin)/2;
    //complejidad log n
    if(arr[medio]==1){
        cuentaUno(arr,medio+1,fin,cont + medio-ini+1);
    }else{
        cuentaUno(arr,ini,medio-1,cont);
    }
}
int buscarMaximo(int arr[],int ini,int fin,int maximo){
    if(ini>fin)return 0;
    int medio=(ini+fin)/2;
    
    if(arr[medio]>arr[medio-1] and arr[medio]>arr[medio+1]){
        return arr[medio];
    }else{
        if(arr[medio]<arr[medio+1]){
            buscarMaximo(arr,medio+1,fin,maximo);
        }else{
            buscarMaximo(arr,ini,medio-1,maximo);
        }
    }
    
}
int buscarMenor(int arr[],int ini,int fin){
    if(ini>fin)return arr[fin];
    int medio=(ini+fin)/2;
    
    if(arr[medio]>arr[medio-1]){
        buscarMenor(arr,ini,medio-1);
    }else{
        buscarMenor(arr,medio+1,fin);
    }

}
int buscarSolo(int arr[],int ini,int fin){
    if(ini==fin)return ini;
    int medio=(ini+fin)/2;
    if(medio%2==0){
        if(arr[medio]==arr[medio+1]){
            buscarSolo(arr,medio+2,fin);
        }else{
            buscarSolo(arr,ini,medio);
        }
    }else{
        if(arr[medio]==arr[medio-1]){
            buscarSolo(arr,medio+1,fin);
        }else{
            buscarSolo(arr,ini,medio-1);
        }
    }
}
int max(int a,int b){
    if(a>b){
        return a;
    }else{
        return b;
    }
}
int sumaMaximaMedio(int arr[],int ini,int med,int fin){
    int izq=0,der=0;
    for(int i=med;i>ini;i--){
        izq+=arr[i];
    }
    for(int i=med+1;i<fin;i++){
        der+=arr[i];
    }
    return izq+der+1;
}
int sumaMaxima(int arr[],int ini,int fin){
    if(ini==fin)return 0;
    int medio=(ini+fin)/2;
    int izq=sumaMaxima(arr,ini,medio);
    int der=sumaMaxima(arr,medio+1,fin);
    int centro=sumaMaximaMedio(arr,ini,medio,fin);
    return max(max(izq,der),centro);
}
int busquedaBinaria(int arr[],int ini,int fin,int dato){
    if(ini>fin)return -1;
    int medio=(ini+fin)/2;
    if(arr[medio]==dato){
        return medio+1;
    }else{
        if(arr[medio]>dato){
            busquedaBinaria(arr,ini,medio-1,dato);
        }else{
            busquedaBinaria(arr,medio+1,fin,dato);
        }
    }
}
int main(int argc, char** argv) {
//    int arr[]={1,1,1,0,0,0,0};
//    int n=sizeof(arr)/sizeof(arr[0]);
//    
//    cout<<cuentaceros(arr,0,n-1,0)<<endl;
//    
//    cout<<cuentaUno(arr,0,n-1,0)<<endl;
//    
//    int intervalo[]={1,10,20,80,100,200,400,500};
//    int m=sizeof(intervalo)/sizeof(arr[0]);
//    
//    cout<<buscarMaximo(intervalo,0,m-1,0)<<endl;
//    cout<<buscarMenor(intervalo,0,m-1)<<endl;
//    
//    int numeros[]={1,1,3,3,4,5,5,7,7,8,8};
//    int p=sizeof(numeros)/sizeof(numeros[0]);
//    cout<<buscarSolo(numeros,0,n-1)<<endl;
//    int num[]={5,6,1,2,3,4};
//    int w=sizeof(num)/sizeof(num[0]);
//    cout<<buscarMenor(num,0,w-1)<<endl;
    
    int arreglo[]={-2,-5,6,-2,-3,1,5,-6};
    int tam=sizeof(arreglo)/sizeof(arreglo[0]);
    cout<<sumaMaxima(arreglo,0,tam-1)<<endl;
    
    int arr1[]={2,3,4,5,6,7,10,11};
    int a=8;
    cout<<busquedaBinaria(arr1,0,a-1,4)<<endl;
    return 0;
}

