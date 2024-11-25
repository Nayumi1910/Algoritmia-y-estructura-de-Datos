

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 24 de octubre de 2024, 05:06 PM
 */

#include <iostream>
#include <iomanip>
#define N 15
using namespace std;
int buscarNumeroDer(int productos[],int stock[],int inicio,int fin,int pro){
    int cont=0;
    if(inicio>fin)return cont;
    int medio=(inicio+fin)/2;
    if(productos[medio]==pro){
        cout<<medio<<" ";
        cont+=stock[medio];
    }else{
        if(productos[medio]<pro){
            buscarNumeroDer(productos,stock,inicio,medio-1,pro);
        }else{
            buscarNumeroDer(productos,stock,medio+1,fin,pro);
        }
    }
}
int buscarNumeroIzq(int productos[],int stock[],int inicio,int fin,int pro){
    int cont=0;
    if(inicio>fin)return cont;
    int medio=(inicio+fin)/2;
    if(productos[medio]==pro){
        cout<<medio<<" ";
        cont+=stock[medio];
    }else{
        if(productos[medio]>pro){
            buscarNumeroIzq(productos,stock,inicio,medio-1,pro);
        }else{
            buscarNumeroIzq(productos,stock,medio+1,fin,pro);
        }
    }
}
int buscoCumbre(int productos[],int inicio,int fin){
    if(inicio>fin)return inicio;
    int medio=(inicio+fin)/2;
    if(productos[medio]<productos[medio+1]){
        buscoCumbre(productos,medio+1,fin);
    }else{
        buscoCumbre(productos,inicio,medio-1);
    }
}
int main(int argc, char** argv) {
    int productos[]={10,15,20,80,1000,200,100,50,20,10};
    int stock[]={20,20,30,10,10,10,20,20,20,10};
    int n=10,pro=20;
    
    int posCumbre=buscoCumbre(productos,0,n-1);
    cout<<productos[posCumbre]<<endl;
    
    //ahora sumamos la cantidad
    int suma=0;
    cout<<"Las posiciones son: ";
    suma+=buscarNumeroIzq(productos,stock,0,posCumbre-1,pro);
    suma+=buscarNumeroDer(productos,stock,posCumbre+1,n-1,pro);
    cout<<endl;
    cout<<"La suma del stock de "<<pro<<" es: "<<suma<<endl;
    return 0;
}

