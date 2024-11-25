

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 22 de septiembre de 2024, 08:16 AM
 */

#include <iostream>
#include <iomanip>
#include "Pila.h"
#include "funcionesPila.h"
#define N 10
using namespace std;

int tablero[N][N]={{5,6,3,2,1},
                    {2,1,2,3,6},
                    {3,0,1,4,5},
                    {4,5,1,2,2},
                    {3,7,2,3,1}};

int robotApilador(int x,int y,int n,int tam, int dis){
    if(x>=tam or y>=tam)return -1;
    if(tablero[x][y]==n and x!=0 and y!=0){
        return dis;
    }
    //nos dirigimos a la derecha
    int derecha=robotApilador(x,y+1,n,tam,dis+1);
    //nos dirigimos hacia abajo
    int abajo=robotApilador(x+1,y,n,tam,dis+1);
    //comparamos valores, y de acuerdo a eso, vemos cual retorna
    if(derecha==-1)return abajo;
    if(abajo==-1)return derecha;
    if(derecha>abajo){
        return derecha;
    }else{
        return abajo;
    }
}
//void funsionarPilas(Pila &p1,Pila &p2){
//    Pila aux;
//    construir(aux);
//    while(!esPilaVacia(p1) and !esPilaVacia(p2)){
//        if(cima(p1)>cima(p2)){
//            apilar(aux,desapilar(p1));
//        }else{
//            apilar(aux,desapilar(p2));
//        }
//    }
//    while(!esPilaVacia(p1)){
//        apilar(aux,desapilar(p1));
//    }
//    while(!esPilaVacia(p2)){
//        apilar(aux,desapilar(p2));
//    }
//    //volvemos a la pila 1
//    while(!esPilaVacia(aux)){
//        apilar(p1,desapilar(aux));
//    }
//}
void funsionarPilas(Pila &p1,Pila &p2){
    int valor1, valor2,auxi,f1=1,f2=1;
    Pila aux;
    construir(aux);
    while(true){
        
        if(esPilaVacia(p1) and f1){
            valor1=0;
        }
        if(esPilaVacia(p2) and f2){
            valor2=0;
        }
        if(esPilaVacia(p1) and esPilaVacia(p2) and valor1==0
                and valor2==0){
            break;
        }
        if(!esPilaVacia(p1) and f1)valor1=desapilar(p1);
        if(!esPilaVacia(p2) and f2)valor2=desapilar(p2);
        
        cout<<valor1<<" "<<valor2<<endl;
        
        if(valor1>valor2){
            auxi=valor1;
            f1=1;
            f2=0;
        }else{
            auxi=valor2;
            f1=0;
            f2=1;
        }
        apilar(aux,auxi);
    }
    while(!esPilaVacia(aux)){
        auxi=desapilar(aux);
        apilar(p1,auxi);
    }
}
int main(int argc, char** argv) {
    Pila p,u;
    //construyo las pilas 
    construir(p);
    construir(u);
    //coloco los datos de cada pila
    apilar(p,1);
    apilar(p,3);
    apilar(p,4);
    apilar(p,5);
    apilar(u,2);
    apilar(u,5);
    apilar(u,6);
    
    //primero, realizo una función recursiva
    int n=5,t=4,m=5;
    int pasos=robotApilador(0,0,n,m,0);
    if(pasos!=-1){
        cout<<"El mejor espacio esta a "<<pasos<<" pasos de distancia"
                "y acepta pilas de tamaño "<<n<<endl;
    }else{
        cout<<"No se encontro"<<endl;
    }
    
    //despues de encontrar la posicion, se procede a unir las pilas
    funsionarPilas(p,u);
    imprimir(p);
    return 0;
}

