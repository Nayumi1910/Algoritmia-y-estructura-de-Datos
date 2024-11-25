

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 30 de octubre de 2024, 09:25 AM
 */

#include <iostream>
#include <iomanip>
using namespace std;
void guardarArr(int matriz[][6],int arr[],int m,int n){
    int k=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            arr[k]=matriz[i][j];
            k++;
        }
    }
}
void ordenarMedio(int registro[],int instrucciones[],int inicio,
        int medio,int fin){
    int p1,p2;
    p1=medio-inicio+1;
    p2=fin-medio;
    int P[p1+1],P1[p1+1],Q[p2+1],Q1[p2+1];
    for(int i=inicio;i<=medio;i++){
        P[i-inicio]=registro[i];
        P1[i-inicio]=instrucciones[i];
    }
    P[p1]=1000;
    for(int i=medio+1;i<=fin;i++){
        Q[i-medio-1]=registro[i];
        Q1[i-medio-1]=instrucciones[i];
    }
    Q[p2]=1000;
    int q,p;
    q=p=0;
    for(int i=inicio;i<=fin;i++){
        if(P[p]<Q[q]){
            registro[i]=P[p];
            instrucciones[i]=P1[p];
            p++;
        }else{
            registro[i]=Q[q];
            instrucciones[i]=Q1[q];
            q++;
        }
    }
}
void ordenarArr(int registro[],int intrucciones[],int inicio,int fin){
    if(inicio==fin)return;
    int medio=(inicio+fin)/2;
    ordenarArr(registro,intrucciones,inicio,medio);
    ordenarArr(registro,intrucciones,medio+1,fin);
    ordenarMedio(registro,intrucciones,inicio,medio,fin);
}
void imprimirArr(int arr[],int num){
    for(int i=0;i<num;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
//int encontrarPositivo(int arr[],int inicio,int fin){
//    if(inicio>=fin)return -1;
//    int medio=(inicio+fin)/2;
//    if(arr[medio]>0){
//        return medio;
//    }else{
//        
//    }
//}
int contarVirusMedio(int registro[],int instrucciones[],int inicio,
        int medio,int fin,int virus){
    int der=0,izq=0;
    for(int i=medio;i>=inicio;i--){
        if(registro[i]==virus){
            der+=instrucciones[i];
        }
    }
    for(int i=medio+1;i<=fin;i++){
        if(registro[i]==virus){
            izq+=instrucciones[i];
        }
    }
    return izq+der;
}
int max(int a,int b){
    if(a>b){
        return a;
    }else{
        return b;
    }
}
int contarVirus(int registro[],int instrucciones[],int inicio,
        int fin,int virus){
    if(inicio==fin){
        return 0;
    }
    int medio=(inicio+fin)/2;
    int izq=contarVirus(registro,instrucciones,inicio,medio,virus);
    int der=contarVirus(registro,instrucciones,medio+1,fin,virus);
    int centro=contarVirusMedio(registro,instrucciones,inicio,medio,fin,virus);
    return max(max(izq,der),centro);
}
int encontrarPos(int registro[],int ini,int fin){
    if(ini>=fin)return fin;
    int medio=(ini+fin)/2;
    if(registro[medio]>0){
        encontrarPos(registro,ini,medio);
    }else{
        encontrarPos(registro,medio+1,fin);
    }
}
int main(int argc, char** argv) {
    int n=5,m=6;
    int matrizRegistro[][6]={{-1,-2,-3,-4,-5,-6},
                            {-7,-8,1,-9,2,-10},
                            {-11,1,2,-12,-13,-14},
                            {-15,-16,-17,1,-18,-19},
                            {-20,1,2,-21,-22,-23}};
    int matrizInstrucciones[][6]={{10,5,8,9,8,1},
                                {10,5,2,8,2,3},
                                {4,2,1,4,8,1},
                                {1,2,4,3,5,3},
                                {8,3,3,8,5,3}};
    int num=n*m;
    int arrRegistro[num],arrInstrucciones[num];
    guardarArr(matrizRegistro,arrRegistro,m,n);
    cout<<"Registro antes: ";
    imprimirArr(arrRegistro,num);
    guardarArr(matrizInstrucciones,arrInstrucciones,m,n);
    cout<<"Instrucciones antes: ";
    imprimirArr(arrInstrucciones,num);
    ordenarArr(arrRegistro,arrInstrucciones,0,num-1);
    cout<<"Registro ordenado: ";
    imprimirArr(arrRegistro,num);
    cout<<"Instrucciones ordenado: ";
    imprimirArr(arrInstrucciones,num);
    int posIni=encontrarPos(arrRegistro,0,num-1);
//    cout<<posIni<<endl;
    int virus1=1,virus2=2;
    int cont1=contarVirus(arrRegistro,arrInstrucciones,posIni,num-1,virus1);
    int cont2=contarVirus(arrRegistro,arrInstrucciones,posIni,num-1,virus2);
    cout<<"El virus de registro "<<virus1<<",se obtiene "<<cont1
            <<" coincidencias en total"<<endl;
    cout<<"El virus de registro "<<virus2<<",se obtiene "<<cont2
            <<" coincidencias en total"<<endl;
    return 0;
}

