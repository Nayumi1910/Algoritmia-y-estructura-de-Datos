

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 23 de octubre de 2024, 08:40 AM
 */

#include <iostream>
#include <iomanip>
using namespace std;
void merge(int matriz[][4],int inicio,int medio,int fin){
    int l1,l2,i;
    int p=0,q=0;
    l1=medio-inicio+1;
    l2=fin-medio;
    int P[l1+1];
    int P1[l1+1];
    int P2[l1+1];
    int P3[l1+1];
    int Q[l2+1];
    int Q1[l2+1];
    int Q2[l2+1];
    int Q3[l2+1];
    
    //copiar arreglos
    for(i=inicio;i<=medio;i++){
        P[i-inicio]=matriz[i][0];
        P1[i-inicio]=matriz[i][1];
        P2[i-inicio]=matriz[i][2];
        P3[i-inicio]=matriz[i][3];
    }
    P[l1]=10000;
    P1[l1]=10000;
    P2[l1]=10000;
    P3[l1]=10000;
    for(i=medio+1;i<=fin;i++){
        Q[i-medio-1]=matriz[i][0];
        Q1[i-medio-1]=matriz[i][1];
        Q2[i-medio-1]=matriz[i][2];
        Q3[i-medio-1]=matriz[i][3];
    }
    Q[l2]=10000;
    Q1[l2]=10000;
    Q2[l2]=10000;
    Q3[l2]=10000;
    
    for(i=inicio;i<=fin;i++){
        if(P2[p]<Q2[q] or (P2[p]==Q2[q] and P1[p]<=Q1[q])){
            matriz[i][0]=P[p];
            matriz[i][1]=P1[p];
            matriz[i][2]=P2[p];
            matriz[i][3]=P3[p];
            p++;
        }else{
            matriz[i][0]=Q[q];
            matriz[i][1]=Q1[q];
            matriz[i][2]=Q2[q];
            matriz[i][3]=Q3[q];
            q++;
        }
    }
}
void mergeSort(int matriz[][4],int inicio,int fin){
    if(inicio==fin)return;
    int medio=(inicio+fin)/2;
    
    mergeSort(matriz,inicio,medio);
    mergeSort(matriz,medio+1,fin);
    merge(matriz,inicio,medio,fin);
}
int cantidadConsultores(int matriz[][4],int inicio,int fin,int cant,
        int nivel, int tiempo){
    if(inicio>fin)return cant;
    int medio=(inicio+fin)/2;
    if((matriz[medio][2]==nivel) and (matriz[medio][1]>=tiempo)){
        cantidadConsultores(matriz,inicio,medio-1,cant+fin-medio+1,nivel,tiempo);
    }else{
        cantidadConsultores(matriz,medio+1,fin,cant,nivel,tiempo);
    }
}
int main(int argc, char** argv) {
    int tiempo=5,nivel=2,p=12;
    int matriz[][4]={{1320,10,2,5},
                {1317,12,3,8},
                {1021,10,3,7},
                {1909,3,2,6},
                {1000,10,2,6},
                {1989,2,1,3},
                {1590,5,1,4},
                {1489,4,1,4}};
    int n=sizeof(matriz)/sizeof(matriz[0]);
//    cout<<n<<endl;
    //imprimo
    cout<<"ANTES DE ORDENAR:"<<endl;
    for(int i=0;i<8;i++){
        cout<<matriz[i][0]<<" "<<matriz[i][1]<<" "
                <<matriz[i][2]<<" "<<matriz[i][3]<<endl;
    }
    //primero lo ordeno 
    mergeSort(matriz,0,n-1);
    //imprimo
    cout<<"DESPUES DE ORDENAR:"<<endl;
    for(int i=0;i<8;i++){
        cout<<matriz[i][0]<<" "<<matriz[i][1]<<" "
                <<matriz[i][2]<<" "<<matriz[i][3]<<endl;
    }
    //PARTE C
    int cant=cantidadConsultores(matriz,0,n-1,0,nivel,tiempo);
    cout<<"La cantidad de personas que pueden cumplir: "<<cant<<endl;
    
    //Parte D
    int suma=0;
    cout<<"Consultores:"<<endl;
    for(int i=n-cant;i<n;i++){
        if(matriz[i][3]+suma<=p and matriz[i][1]>=tiempo){
            cout<<matriz[i][0]<<" "<<matriz[i][1]<<" "
                <<matriz[i][2]<<" "<<matriz[i][3]<<endl;
            suma+=matriz[i][3];
        }
    }
    
    return 0;
}

