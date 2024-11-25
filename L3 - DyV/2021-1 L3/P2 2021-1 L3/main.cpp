

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 27 de octubre de 2024, 11:31 AM
 */

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <regex>
using namespace std;
void merge(int *lote,int ini,int medio,int fin){
    int p1,p2;
    p1=medio-ini+1;
    p2=fin-medio;
    int P[p1+1],Q[p2+1];
    for(int i=ini;i<=medio;i++){
        P[i-ini]=lote[i];
    }
    for(int i=medio+1;i<=fin;i++){
        Q[i-medio-1]=lote[i];
    }
    P[p1]=10000;
    Q[p2]=10000;
    int p,q;
    q=p=0;
    for(int i=ini;i<=fin;i++){
        if(P[p]<Q[q]){
            lote[i]=P[p];
            p++;
        }else{
            lote[i]=Q[q];
            q++;
        }
    }
}
void mergeSort(int *lote,int ini,int fin){
    if(ini==fin)return;
    int medio=(ini+fin)/2;
    mergeSort(lote,ini,medio);
    mergeSort(lote,medio+1,fin);
    merge(lote,ini,medio,fin);
}
int cuentaCero(int *lote,int ini,int fin,int cont){
    if(ini>fin)return cont;
    int medio=(ini+fin)/2;
    if(lote[medio]==0){
        return cuentaCero(lote,medio+1,fin,medio+1);
    }else{
        return cuentaCero(lote,ini,medio-1,cont);
    }
}
int main(int argc, char** argv) {
    int m=6,n=8;
    double p=0.7;
    int lote[][8]={{0,0,0,1,1,0,-1,-1},
                    {1,0,1,1,1,0,1,0},
                    {0,1,1,1,1,1,1,1},
                    {1,1,1,1,1,0,1,-1},
                    {1,0,0,0,0,1,-1,-1},
                    {1,1,0,1,0,1,1,-1}};
    cout<<" LOTE "<<" ESTADO "<<endl;
    for(int i=0;i<m;i++){
        mergeSort(lote[i],0,n-1);
        int cont=cuentaCero(lote[i],0,n-1,0);
        int unos=n-cont;
//        cout<<cont;
        double pi=(1.0)*unos/n;
        if(pi>=p){
            cout<<pi<<" Aprobado"<<endl;
        }else{
            cout<<pi<<" Rechazado"<<endl;
        }

    }
    return 0;
}

