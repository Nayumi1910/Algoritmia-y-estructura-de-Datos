

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 10 de septiembre de 2024, 05:36 PM
 */

#include <iostream>
#include <iomanip>
#define MAX 6
using namespace std;
int tablero[MAX][MAX]={{0,0,0,1,0},
                        {0,0,0,0,0},
                        {1,0,0,0,0},
                        {0,1,0,0,0},
                        {0,0,0,0,0},
                        {0,1,0,0,0}};
int recursividad(int col,int fil,int max,int min,int x){
    int cant=0;
    if(max<min or max>col){
        return 0;
    }
    for(int i=0;i<max;i++){
        if(tablero[x][i]==0){
            tablero[x][i]=5;
            cant++;
        }
    }
    cant+=recursividad(col,fil,max-1,min,x+1);

    
    for(int i=0;i<max;i++){
        if(tablero[fil-(x+1)][i]==0){
            tablero[fil-(x+1)][i]=5;
            cant++;
        }
    }
    return cant;
    
    
}
int main(int argc, char** argv) {
    int n=5,m=6;
    int max=5,min=3,pro=24;
    int cont;
    cont=recursividad(n,m,max,min,0);
    cout<<"Ubicaciones: "<<cont<<endl;
    if(cont==pro){
        cout<<"Se pudo"<<endl;
    }else{
        cout<<"No se pudo"<<endl;
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<tablero[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

