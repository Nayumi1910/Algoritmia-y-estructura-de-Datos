

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 28 de octubre de 2024, 03:40 PM
 */

#include <iostream>
#include <iomanip>
using namespace std;
int calcularW(int iniL,int finL,int iniW,int finW,int iniH,int finH,
        int meteoro[][4]){
    int peso=0;
    int i,j;
    for(i=iniW;i<=finW;i++){
        for(j=iniL;j<=finL;j++){
            peso+=meteoro[i][j];
        }
    }
    return peso;
}
void busquedaBinaria(int meteoro[][4],int iniL,int finL,int iniW,
        int finW,int iniH,int finH,int posicion[]){
    if((iniH==finH) and (iniL==finL) and (iniW==finW)){
        posicion[0]=iniL;
        posicion[1]=iniW;
        posicion[2]=iniH;
        return;
    }
    int auxIniL=iniL;
    int auxFinL=finL;
    int medioL=(iniL+finL)/2;
    if(iniL!=finL){
        int w1=calcularW(iniL,medioL,iniW,finW,iniH,finH,meteoro);
        int w2=calcularW(medioL+1,finL,iniW,finW,iniH,finH,meteoro);
        if(w1>w2){
            auxFinL=medioL;
        }else{
            auxIniL=medioL+1;
        }
    }
    int auxIniW=iniW;
    int auxFinW=finW;
    int medioW=(iniW+finW)/2;
    if(iniW!=finW){
        int w_1=calcularW(auxIniL,auxFinL,iniW,medioW,iniH,finH,meteoro);
        int w_2=calcularW(auxIniL,auxFinL,medioW+1,finW,iniH,finH,meteoro);
        if(w_1>w_2){
            auxFinW=medioW;
        }else{
            auxIniW=medioW+1;
        }
    }
    busquedaBinaria(meteoro,auxIniL,auxFinL,auxIniW,auxFinW,0,
            0,posicion);
    
}

int main(int argc, char** argv) {
    int l=4,w=3,h=2;
    int meteoro[3][4]={{1,0,0,0},
                    {0,0,0,0},
                    {0,0,0,0}};
    int posicion[3];
    busquedaBinaria(meteoro,0,l-1,0,w-1,0,0,posicion);
    cout<<"Posicion: ("<<posicion[0]+1<<","<<posicion[1]+1<<","<<h<<")"<<endl;
    return 0;
}

