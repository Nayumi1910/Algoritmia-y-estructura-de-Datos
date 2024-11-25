

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 4 de septiembre de 2024, 03:08 PM
 */

#include <iostream>
#include <iomanip>
#include <cmath>
#define N 10
using namespace std;

void cargabin(int num,int cromo[N],int n){
    for(int i=0;i<n;i++){
        cromo[i]=0;
    }
    int i=0,aux;
    while(num>0){
        aux=num%2;
        num=num/2;
        cromo[i]=aux;
        i++;
    }
}
void ordenar(int robots[N],int n){
    for(int i=0;i<n-1;i++){
        for(int j=i;j<n;j++){
            if(robots[j]>robots[i]){
                int aux=robots[i];
                robots[i]=robots[j];
                robots[j]=aux;
            }
        }
    }
}
int main(int argc, char** argv) {
    int robots[N]={77,82,81,90,92,75};
    int camino[2][N]={{100,90,95,85,105},{90,98,75,96,93}};
    int n=5,m=6;
    //ordenar el robot que pesa más
    ordenar(robots,6);
    //validamos si todos pasan
    int j=0,k=0,cant=0;
    while(1){
        int max=robots[0],pos;
        for(int i=0;i<m;i++){
            if(robots[i]>max){
                max=robots[i];
                pos=i;
            }
        }
        int pesoValido=1;
        
        for(int i=0;i<n;i++){
            if(max>camino[0][i] and max>camino[1][i]){
                pesoValido=0;
            }
        }
        if(pesoValido)break;
        
        cout<<"Se elimino el robot "<<pos+1<<" que pesaba "
                <<max<<endl;
        //actualizamos
        for(int i=pos;i<m;i++){
            robots[i]=robots[i+1];
        }
        m--;
    }
    int robMax=robots[0];
 
    int comb=pow(2,n);
    int cromo[N],solucion[N],cantidad=0,validar;
    for(int i=0;i<comb;i++){
        cargabin(i,cromo,n);
        validar=1;
        for(int j=0;j<n;j++){
            //por la izquierda
            if(cromo[j]==0){
                if(camino[0][j]<robMax)validar=0;
            }else{ //por la derecha
                if(camino[1][j]<robMax)validar=0;
            }
            
        }
        if(validar){
            solucion[cantidad]=i;
            cantidad++;
        }
    }
    for(int i=0;i<cantidad;i++){
        cargabin(solucion[i],cromo,n);
        cout << "Solución " << cantidad << ":" << endl;
        for(int j=0;j<n;j++){
           cout << "Nivel "<< j+1 <<" "; 
        }
        cout<<endl;
        for(int nivel = 0; nivel < n; nivel++) {
            if(cromo[nivel] == 0) cout << " izquierda ";
            else cout << " derecha ";
        }
        cout << endl << endl;
    }

    return 0;
}

