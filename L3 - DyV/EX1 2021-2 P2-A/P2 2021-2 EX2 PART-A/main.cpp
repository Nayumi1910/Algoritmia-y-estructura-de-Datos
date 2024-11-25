

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 1 de noviembre de 2024, 12:19 PM
 */

#include <iostream>
#include <iomanip>
using namespace std;

int cuentaceros(int arr[],int ini,int fin, int cont){
    if(ini>fin)return cont;
    int medio=(ini+fin)/2;
    if(arr[medio]==0){
        //es el arreglo, el inicio, ya quea la derecha existen varios 0 
        // entonces a la dereha sigue buscando si hay mas 0
        //contamos todo lo que hay a la derecha 
        cuentaceros(arr,ini, medio-1,cont+ fin-medio+1);
    }else{
        cuentaceros(arr,medio+1,fin,cont);
    }
    
}
int cuentaUnos(int arr[],int ini,int fin, int cont){
    if(ini>fin)return cont;
    int medio=(ini+fin)/2;
    if(arr[medio]==1){
        //es el arreglo, el inicio, ya quea la derecha existen varios 0 
        // entonces a la dereha sigue buscando si hay mas 0
        //contamos todo lo que hay a la derecha 
        cuentaUnos(arr,ini, medio-1,cont+fin-medio+1);
    }else{
        cuentaUnos(arr,medio+1,fin,cont);
    }
    
}

int main(int argc, char** argv) {
    int bandeja1[]={0,0,1,1,1,1,1};
    int bandeja2[]={1,1,1,1,1,0,0};
    int bandeja3[]={1,1,1,1,1,1,0};
    int bandeja4[]={1,1,1,0,0,0,0};
    int m=7;

    cout<<"La bandeja 1 tiene: "<<cuentaUnos(bandeja1,0,m-1,0)<<endl;

    cout<<"La bandeja 2 tiene: "<<m-cuentaceros(bandeja2,0,m-1,0)<<endl;

    cout<<"La bandeja 3 tiene: "<<m-cuentaceros(bandeja3,0,m-1,0)<<endl;

    cout<<"La bandeja 4 tiene: "<<m-cuentaceros(bandeja4,0,m-1,0)<<endl;



    return 0;
}

