

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 8 de octubre de 2024, 09:29 AM
 */

#include <iostream>
#include <iomanip>

#include "Pila.h"
#include "funcionesPila.h"
#define N 10
using namespace std;

void submarinoOn(Pila &pila,int arreglo[],int mov){
    int i;
    int top=mov+1;//siempre es una posicion más
    int flag=0,temp=0;
    i=0;
    while(i<top){
        if((i==0 and arreglo[i]==1)or i==top-1){
            cout<<i+1<<" ";
            i++;
            continue;
        }
        if(arreglo[i]==1 and flag==0){
            cout<<i+1<<" ";
            i++;
        }else{
            if(esPilaVacia(pila)){
                apilar(pila,i+1);
                temp=0;
                i++;
                flag=1;
                continue;
            }else if(temp==0){
                apilar(pila,i+1);
            }
            if(arreglo[i]==1){
                temp=1;
                cout<<desapilar(pila)<<" ";
                if(esPilaVacia(pila)){
                    flag=0;
                    i++;
                }
            }else{
                i++;
            }
        }
    }
}
void submarinoOn2(Pila &pila,int arreglo[],int mov){
    int n=1;
    int top=mov+1;
    int i=0;
    int flag=0,temp=0;
    while(n<=top){
        apilar(pila,n);
        if(n==top){
            while(!esPilaVacia(pila)){
                cout<<desapilar(pila)<<" ";
            }
        }
        if(arreglo[i]==1 and pila.lista.longitud==1){
            cout<<desapilar(pila)<<" ";
        }else if(arreglo[i]==1 and pila.lista.longitud>1){
            while(!esPilaVacia(pila)){
                cout<<desapilar(pila)<<" ";
            }
        }
        i++;
        n++;
    }
}
int rec=0;
void submarinoRex(int arreglo[],int mov, int index, int baja){
    if(index>mov)return;
    if(arreglo[index]==1 or index==mov){
        cout<<index+1<<" ";
        rec=index;
        if(baja<1){
            submarinoRex(arreglo,mov,index+1,baja);
        }else{
            return;
        }
    }else{
        submarinoRex(arreglo,mov,index+1,baja+1);
        cout<<index+1<<" ";
        if(baja<1){
            submarinoRex(arreglo,mov,rec+1,baja);
        }
    }
}

int main(int argc, char** argv) {
    //subida es 1, bajada es 0
//    int arreglo[N]={1,1,1,0,1};
//    int mov=5;
//    int arreglo[N]={0,0,1};
//    int mov=3;
    int arreglo[N]={1,0,1,0,0,1,1};
    int mov=7;
    Pila pila;
    construir(pila);
    submarinoOn(pila,arreglo,mov);
    cout<<endl;
    submarinoOn2(pila,arreglo,mov);
    cout<<endl;
    submarinoRex(arreglo,mov,0,0);
    return 0;
}

