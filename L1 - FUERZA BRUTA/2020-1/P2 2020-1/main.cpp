

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 20 de agosto de 2024, 10:11 PM
 */

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int n=4,r=2;
    int matriz[4][3]={{1,1,1},{0,2,4},{0,1,4},{0,4,2}};
    int numPos=5;
    int posiciones[5][2]={{2,1},{2,0},{2,1},{3,1},{3,2}};
    double x,y;
    double distancia;
    for(int i=0;i<n;i++){
        for(int k=0;k<numPos;k++){
            if(matriz[i][0]==1){
                x=matriz[i][1]-posiciones[k][0];
                y=matriz[i][2]-posiciones[k][1];
                distancia=sqrt(x*x+y*y);
                if(distancia<=r){
                    cout<<"Persona podria haberse contagiado en su movimiento "
                            <<k+1<<" por la persona "<<i+1<<" con un nivel de "
                            "cercania de "<<distancia<<endl;
                }
            }
        }
    }
    
    return 0;
}

