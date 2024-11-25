

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 30 de octubre de 2024, 08:08 PM
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
int encontrarM(int empresa[],int inicio,int medio,int fin){
    int der,izq;
    for(int i=medio;i>=inicio;i--){
        if(empresa[i]<empresa[i-1]){
            der=empresa[i-1];
        }else{
            der=empresa[i];
            break;
        }
    }
    for(int i=medio+1;i<=fin;i++){
        if(empresa[i]<empresa[i+1]){
            izq=empresa[i+1];
        }else{
            izq=empresa[i];
            break;
        }
    }
    return max(der,izq);
}
int encontrarPicosM(int empresa[],int inicio,int medio,int fin,
        int horas[],int mayor){
    int der=0,izq=0;
    for(int i=medio;i>=inicio;i--){
        if(empresa[i]==mayor){
            der++;
            horas[i]=1;
        }else{
            break;
        }
    }
    for(int i=medio+1;i<=fin;i++){
        if(empresa[i]==mayor){
            izq++;
//           horas[i]=1;
        }else{
            break;
        }
    }
    return der+izq;
}

int encontrarPicos(int empresa[],int inicio,int fin,int horas[],int mayor){
    if(inicio==fin){
//        if(empresa[inicio]==mayor){
//            horas[inicio]=1;
//        }
        return 0;
    }
   int medio=(inicio+fin)/2;
   int izq=encontrarPicos(empresa,inicio,medio,horas,mayor);
   int der=encontrarPicos(empresa,medio+1,fin,horas,mayor);
   int centro=encontrarPicosM(empresa,inicio,medio,fin,horas,mayor);
   return max(max(izq,der),centro);
}
int encontrarMayor(int empresa[],int inicio,int fin){
    if(inicio>=fin){
        return 0;
    }
    int medio=(inicio+fin)/2;
    int izq=encontrarMayor(empresa,inicio,medio);
    int der=encontrarMayor(empresa,medio+1,fin);
    int centro=encontrarM(empresa,inicio,medio,fin);
    return max(max(izq,der),centro);
}

int main(int argc, char** argv) {
//    int horas[]={2,3,4,5,6,7,8,9,10,11};
    int empresa1[]={15,12,10,17,15,18,18,18,12,16};
    int empresa2[]={14,17,17,17,17,12,14,14,12,12};
    int empresa3[]={16,18,20,20,15,18,16,18,18,16};
    int n=10;

    int mayor,pico1,pico2,pico3;
    mayor=encontrarMayor(empresa1,0,n-1);
    cout<<"Mayor 1: "<<mayor<<endl;
    int horas[n];
    for(int i=0;i<n;i++)horas[i]=0;
    pico1=encontrarPicos(empresa1,0,n-1,horas,mayor);
    cout<<"Las horas picos son: "<<pico1<<endl;
    for(int i=0;i<n;i++){
        if(horas[i]==1){
            cout<<i+14<<" ";
        }
    }
    cout<<endl;
    for(int i=0;i<n;i++)horas[i]=0;
    mayor=encontrarMayor(empresa2,0,n-1);
    cout<<"Mayor 2: "<<mayor<<endl;
    pico2=encontrarPicos(empresa2,0,n-1,horas,mayor);
    cout<<"Las horas picos son: "<<pico2<<endl;
    for(int i=0;i<n;i++){
        if(horas[i]==1){
            cout<<i+14<<" ";
        }
    }
    cout<<endl;
    int mayor3;
    for(int i=0;i<n;i++)horas[i]=0;
    mayor3=encontrarMayor(empresa3,0,n-1);
    cout<<"Mayor 3: "<<mayor3<<endl;
    pico3=encontrarPicos(empresa3,0,n-1,horas,mayor);
    cout<<"Las horas picos son: "<<pico3<<endl;
    for(int i=0;i<n;i++){
        if(horas[i]==1){
            cout<<i+14<<" ";
        }
    }
    cout<<endl;
    
    return 0;
}

