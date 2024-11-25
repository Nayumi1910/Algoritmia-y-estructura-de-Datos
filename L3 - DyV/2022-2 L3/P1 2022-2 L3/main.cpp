    

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 28 de octubre de 2024, 04:23 PM
 */

#include <iostream>
#include <iomanip>
using namespace std;
int max(int a,int b){
    if(b<a){
        return a;
    }else{
        return b;
    }
}
int intervaloMedio(int *paciente,int inicio,int medio,int fin){
    int izq=0,der=0,i;
    for(i=medio;i>inicio;i--){
        if(paciente[i]==paciente[i-1]){
            izq++;
        }else{
            break;
        }
    }
    for(i=medio;i<fin;i++){
        if(paciente[i+1]==paciente[i]){
            der++;
        }else{
            break;
        }
    }
    return der+izq+1;
}

int buscarMenor(int *paciente,int inicio,int fin){
    if(inicio==fin)return paciente[inicio];
    int medio=(inicio+fin)/2;
    if(fin-inicio==1){
        if(paciente[inicio]<paciente[fin]){
            return paciente[inicio];
        }else{
            return paciente[fin];
        }
    }
    if(paciente[medio]<paciente[medio+1] and medio+1<=fin){
        return buscarMenor(paciente,inicio,medio);
    }else{
        return buscarMenor(paciente,medio+1,fin);
    }
}
int intervalosMax(int *paciente,int inicio,int fin,int menor,
        int intervalosDias[],int dias[]){
    if(inicio==fin){
        if(paciente[inicio]==menor){
            intervalosDias[inicio]=dias[inicio];
        }
        return 1;
    }
    int medio=(inicio+fin)/2;
    int izq=intervalosMax(paciente,inicio,medio,menor,intervalosDias,dias);
    int der=intervalosMax(paciente,medio+1,fin,menor,intervalosDias,dias);
    int centro=intervaloMedio(paciente,inicio,medio,fin);
    return max((izq,der),centro);
}
int main(int argc, char** argv) {
    int paciente[]={98,95,92,89,91,92,89,89,92,93,94,92
            ,91,90,88,88,88,89,90,91,88,88,90,90,92,89,90,88,90,91};
    int cant=30;
    int menor=buscarMenor(paciente,0,cant-1);
//    cout<<menor<<endl;
    int dias[cant],intervalosDias[cant];
    for(int i=0;i<cant;i++)dias[i]=i+1;
    for(int i=0;i<cant;i++)intervalosDias[i]=0;
    int numMax=intervalosMax(paciente,0,cant-1,menor,intervalosDias,dias);
    cout<<"El numero menor es: "<<menor<<endl;
    int cont=0;
    cout<<"El rango de dias es: ";
    for(int i=0;i<cant;i++){
        if(intervalosDias[i]!=0 and cont<numMax){
            cout<<intervalosDias[i]<<" ";
            cont++;
        }
    }
    return 0;
}

