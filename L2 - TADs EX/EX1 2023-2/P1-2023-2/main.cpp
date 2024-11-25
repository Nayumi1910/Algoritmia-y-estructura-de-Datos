

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 2 de octubre de 2024, 11:45 AM
 */

#include <iostream>
#include <iomanip>
#include <cmath>
#include "Lista.h"
#include "funcionesLista.h"
#include "Nodo.h"
#define M 9
using namespace std;

void ordenarMenorMayor(Lista &lista){
    Nodo *recorrido = lista.cabeza;
    while(recorrido!=nullptr){
        Nodo *siguiente= recorrido->siguiente;
        int aux= recorrido->elemento;
        while(siguiente!=nullptr){
            int aux2 = siguiente->elemento;
            if(aux>siguiente->elemento){
                recorrido->elemento = siguiente->elemento;
                siguiente->elemento = aux;
                aux= aux2;
            }
            siguiente=siguiente->siguiente;
        }
        recorrido=recorrido->siguiente;
    }  
}
void ordenarMayorMenor(Lista &lista){
    Nodo *recorrido = lista.cabeza;
    while(recorrido!=nullptr){
        Nodo *siguiente= recorrido->siguiente;
        int aux= recorrido->elemento;
        while(siguiente!=nullptr){
            int aux2 = siguiente->elemento;
            if(aux<siguiente->elemento){
                recorrido->elemento = siguiente->elemento;
                siguiente->elemento = aux;
                aux= aux2;
            }
            siguiente=siguiente->siguiente;
        }
        recorrido=recorrido->siguiente;
    }
}
void fusionar(Lista &L1,Lista &L2){
    ordenarMenorMayor(L1);
//    imprime(L1);
    ordenarMayorMenor(L2);
//    imprime(L2);
    int i=L1.longitud;
    while(!esListaVacia(L2)){
        if(i!=0){
            int dato2=retornaCabeza(L1);
            insertarAlFinal(L1,dato2);
            L1.cabeza=L1.cabeza->siguiente;
            i--;
        }
        int dato=retornaCabeza(L2);
        insertarAlFinal(L1,dato);
        L2.cabeza=L2.cabeza->siguiente;
//        imprime(L1);
    }
}
void cargaBin(int num,int cromo[],int n,int base){
    for(int i=0;i<n;i++){
        cromo[i]=0;
    }
    int i=0,aux;
    while(num>0){
        aux=num%base;
        num=num/base;
        cromo[i]=aux;
        i++;
    }
}
void imprimir(int c[],int num,Lista camion[]){
    if(num>1){
        for(int i=1;i<num;i++){
            fusionar(camion[c[0]],camion[c[i]]);
        }
    }
    imprime(camion[c[0]]);
}
int main(int argc, char** argv) {
    int cant=5;
    int L=34,R=24,D=12,MA=30;
    Lista camion[cant];
    for(int i=0;i<cant;i++){
        construir(camion[i]);
    }
    //Primer camion
    insertarAlFinal(camion[0],8);
    insertarAlFinal(camion[0],9);
    cout<<"Camion 1: ";
    imprime(camion[0]);
    //segundo 
    insertarAlFinal(camion[1],15);
    insertarAlFinal(camion[1],9);
    cout<<"Camion 2: ";
    imprime(camion[1]);
    //tercero
    insertarAlFinal(camion[2],3);
    insertarAlFinal(camion[2],6);
    cout<<"Camion 3: ";
    imprime(camion[2]);
    //cuarto
    insertarAlFinal(camion[3],1);
    insertarAlFinal(camion[3],6);
    insertarAlFinal(camion[3],8);
    insertarAlFinal(camion[3],4);
    insertarAlFinal(camion[3],6);
    cout<<"Camion 4: ";
    imprime(camion[3]);
    //quinto
    insertarAlFinal(camion[4],5);
    insertarAlFinal(camion[4],6);
    insertarAlFinal(camion[4],3);
    cout<<"Camion 5: ";
    imprime(camion[4]);
    
    int cromo[cant];
    //como son 4 tortugas, cada una puede tener 5 camiones
    int combinaciones=pow(4,cant);
    int sumaL,cantL;
    int sumaR,cantR;
    int sumaD,cantD;
    int sumaMA,cantMA;
    int mComb=-1;
    
    for(int i=0;i<combinaciones;i++){
        cargaBin(i,cromo,cant,4);
        sumaL=sumaD=sumaR=sumaMA=0;
        cantL=cantMA=cantD=cantR=0;
        for(int j=0;j<cant;j++){
            if(cromo[j]==0){
                sumaL+=camion[j].suma;
                cantL++;
            }
            if(cromo[j]==1){
                sumaR+=camion[j].suma;
                cantR++;
            }
            if(cromo[j]==2){
                sumaD+=camion[j].suma;
                cantD++;
            }
            if(cromo[j]==2){
                sumaMA+=camion[j].suma;
                cantMA++;
            }
        }
        if(sumaD!=0 and sumaL!=0 and sumaMA!=0 and 
                sumaR!=0 and sumaD<=D and sumaL<=L and
                sumaMA<=MA and sumaR<=R){
            mComb=i;
            break;
        }
    }
    cout<<"Resultado: "<<endl;
    if(mComb!=-1){
        cout<<"Las tortuNinjas completaron su misión"<<endl;
    }else{
        cout<<"No completaron la misión"<<endl;
    }
    cout<<cantD<<endl;
    cout<<cantL<<endl;
    cout<<cantR<<endl;
    cout<<cantMA<<endl;
    //ahora se imprimira 
    int a=0,b=0,c=0,d=0;
    int c1[cant],c2[cant],c3[cant],c4[cant];
    cargaBin(mComb,cromo,cant,4);
    for(int i=0;i<cant;i++){
        if(cromo[i]==0){
            c1[a]=i;
            a++;
        }
        if(cromo[i]==1){
            c2[b]=i;
            b++;
        }
        if(cromo[i]==2){
            c3[c]=i;
            c++;
        }
        if(cromo[i]==3){
            c4[d]=i;
            d++;
        }
    }
    cout<<"Leonardo: ";
    imprimir(c1,a,camion);
    cout<<"Rafael: ";
    imprimir(c2,b,camion);
    cout<<"Donatelo: ";
    imprimir(c3,c,camion);
    cout<<"Miguel Angel: ";
    imprimir(c4,d,camion);
    
    return 0;
}

