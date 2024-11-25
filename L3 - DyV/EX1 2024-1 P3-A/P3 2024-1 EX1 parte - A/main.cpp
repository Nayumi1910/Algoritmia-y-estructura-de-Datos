

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 1 de noviembre de 2024, 08:24 PM
 */

#include <iostream>
#include <iomanip>
using namespace std;
void imprimir(int numId[],int impacto[],int riesgo[],int n){
    for(int i=0;i<n;i++){
        cout<<numId[i]<<"-"<<impacto[i]<<"-"<<riesgo[i]<<" ";
    }
    cout<<endl;
}
void ordenarRiegosMedio(int numId[],int impacto[],int riesgo[],
        int inicio,int medio,int fin){
    int p1,p2;
    p1=medio-inicio+1;
    p2=fin-medio;
    int P[p1+1],P1[p1+1],P2[p1+1];
    int Q[p2+1],Q1[p2+1],Q2[p2+1];
    for(int i=inicio;i<=medio;i++){
        P[i-inicio]=numId[i];
        P1[i-inicio]=impacto[i];
        P2[i-inicio]=riesgo[i];
    }
    P2[p1]=1000;
    for(int i=medio+1;i<=fin;i++){
        Q[i-medio-1]=numId[i];
        Q1[i-medio-1]=impacto[i];
        Q2[i-medio-1]=riesgo[i];
    }
    Q2[p1]=1000;
    int p,q;
    p=q=0;
    for(int i=inicio;i<=fin;i++){
        if(P2[p]<Q2[q]){
            numId[i]=P[p];
            impacto[i]=P1[p];
            riesgo[i]=P2[p];
            p++;
        }else{
            numId[i]=Q[q];
            impacto[i]=Q1[q];
            riesgo[i]=Q2[q];
            q++;
        }
    }
    
}
void ordenarImpactoMedio(int numId[],int impacto[],int riesgo[],
        int inicio,int medio,int fin){
    int p1,p2;
    p1=medio-inicio+1;
    p2=fin-medio;
    int P[p1+1],P1[p1+1],P2[p1+1];
    int Q[p2+1],Q1[p2+1],Q2[p2+1];
    for(int i=inicio;i<=medio;i++){
        P[i-inicio]=numId[i];
        P1[i-inicio]=impacto[i];
        P2[i-inicio]=riesgo[i];
    }
    P1[p1]=1000;
    for(int i=medio+1;i<=fin;i++){
        Q[i-medio-1]=numId[i];
        Q1[i-medio-1]=impacto[i];
        Q2[i-medio-1]=riesgo[i];
    }
    Q1[p1]=1000;
    int p,q;
    p=q=0;
    for(int i=inicio;i<=fin;i++){
        if(P1[p]<Q1[q]){
            numId[i]=P[p];
            impacto[i]=P1[p];
            riesgo[i]=P2[p];
            p++;
        }else{
            numId[i]=Q[q];
            impacto[i]=Q1[q];
            riesgo[i]=Q2[q];
            q++;
        }
    }
    
}
void ordenarIDMedio(int numId[],int impacto[],int riesgo[],
        int inicio,int medio,int fin){
    int p1,p2;
    p1=medio-inicio+1;
    p2=fin-medio;
    int P[p1+1],P1[p1+1],P2[p1+1];
    int Q[p2+1],Q1[p2+1],Q2[p2+1];
    for(int i=inicio;i<=medio;i++){
        P[i-inicio]=numId[i];
        P1[i-inicio]=impacto[i];
        P2[i-inicio]=riesgo[i];
    }
    P[p1]=1000;
    for(int i=medio+1;i<=fin;i++){
        Q[i-medio-1]=numId[i];
        Q1[i-medio-1]=impacto[i];
        Q2[i-medio-1]=riesgo[i];
    }
    Q[p1]=1000;
    int p,q;
    p=q=0;
    for(int i=inicio;i<=fin;i++){
        if(P[p]<Q[q]){
            numId[i]=P[p];
            impacto[i]=P1[p];
            riesgo[i]=P2[p];
            p++;
        }else{
            numId[i]=Q[q];
            impacto[i]=Q1[q];
            riesgo[i]=Q2[q];
            q++;
        }
    }
    
}
void ordenarRiegos(int numId[],int impacto[],int riesgo[],
        int inicio,int fin){
    if(inicio==fin)return;
    int medio=(inicio+fin)/2;
    ordenarRiegos(numId,impacto,riesgo,inicio,medio);
    ordenarRiegos(numId,impacto,riesgo,medio+1,fin);
    ordenarRiegosMedio(numId,impacto,riesgo,inicio,medio,fin);
}
void ordenarImpacto(int numId[],int impacto[],int riesgo[],
        int inicio,int fin){
    if(inicio==fin)return;
    int medio=(inicio+fin)/2;
    ordenarImpacto(numId,impacto,riesgo,inicio,medio);
    ordenarImpacto(numId,impacto,riesgo,medio+1,fin);
    ordenarImpactoMedio(numId,impacto,riesgo,inicio,medio,fin);
}
void ordenarID(int numId[],int impacto[],int riesgo[],
        int inicio,int fin){
    if(inicio==fin)return;
    int medio=(inicio+fin)/2;
    ordenarID(numId,impacto,riesgo,inicio,medio);
    ordenarID(numId,impacto,riesgo,medio+1,fin);
    ordenarIDMedio(numId,impacto,riesgo,inicio,medio,fin);
}
int main(int argc, char** argv) {
    int numId[]={4,1,5,7,6,3,2};
    int impacto[]={1,2,3,2,3,2,1};
    int riesgo[]={3,4,9,2,6,6,2};
    int n=7;
    ordenarRiegos(numId,impacto,riesgo,0,n-1);
    imprimir(numId,impacto,riesgo,n);
    ordenarImpacto(numId,impacto,riesgo,0,n-1);
    imprimir(numId,impacto,riesgo,n);
    ordenarID(numId,impacto,riesgo,0,n-1);
    imprimir(numId,impacto,riesgo,n);
    return 0;
}

