

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 6 de septiembre de 2024, 10:56 AM
 */

#include <cstdlib>
#include <iostream>
#include <cmath>
#define SIZE 12
#define COL 5
#define SIZEG 3
#define ARMASG 4
using namespace std;

/*
 * 
 */

int cargaBin(int cromosoma[SIZE],int base,int n, int size){
    int i;
    for (i=0; i<size; i++){
        cromosoma[i] = 0;
    }
    i = 0;
    while (n>0){
        cromosoma[i++] = n%base;
        n = n/base;
    }
}

void imprimeSolucion(int cromosoma[SIZE], int cantArmas, char letraArmas[SIZE], int cantGuerreros, int guerreros[SIZEG][ARMASG]){
    for (int i=1; i<=cantGuerreros; i++){
        /*Imprimimos la mochila para cada guerrero*/
        cout << "Guerrero " << i << endl;
        cout << "Poder: " << guerreros[i-1][0] << endl;
        cout << "Armas en mochila: ";
        for (int j=0; j<cantArmas; j++){
            if (cromosoma[j]==i){
                cout << letraArmas[j] << " ";
            }
        }
        cout << endl;
    }
}

int validaSolucion(int cromosoma[SIZE],int guerreros[SIZEG][ARMASG],int cantGuerreros, int cantArmas, int armas[SIZE][COL]){
    int poderes[SIZEG], cumpleRequisitos, estado, cumpleCategoria, cumpleTipo, cumplePoderes;
    for (int i=0; i<cantGuerreros; i++){
        poderes[i] = 0;
    }
    /*Sumamos los poderes*/
    for (int i=0; i<cantArmas; i++){
        if (cromosoma[i]>0){
            poderes[cromosoma[i]-1] = poderes[cromosoma[i]-1] + armas[i][0];            
        }
    }
    /*Validamos los poderes*/
    cumplePoderes = 1;
    for (int i=0; i<cantGuerreros; i++){
        if (poderes[i]<guerreros[i][0]){
            cumplePoderes = 0;
            break;
        }
    }
    /*Validamos los requisitos de cada arma*/
    cumpleRequisitos = 1;
    for (int i=0; i<cantArmas; i++){
        if (cromosoma[i]>0){
            estado = cromosoma[i];
            for (int j=2; armas[i][j]>0; j++){
                if (cromosoma[armas[i][j] - 1]!=estado){
                    cumpleRequisitos = 0;
                    break;
                }
            }
        }
        if (cumpleRequisitos==0){
            break;
        }
    }
    /*Validamos que todas las armas de cada guerrero sean del tipo de categoria*/
    cumpleCategoria = 1;
    for (int i=0; i<cantArmas; i++){
        if (cromosoma[i]>0){
            cumpleTipo = 0;
            for (int j=1; guerreros[cromosoma[i]-1][j]>0; j++){
                if (armas[i][1]==guerreros[cromosoma[i]-1][j]){
                   cumpleTipo = 1; 
                }
            }
            if (cumpleTipo==0){
                cumpleCategoria = 0;
                break;
            }
        }
    }
    if (cumpleCategoria==1 && cumpleRequisitos==1 && cumplePoderes==1){
        return 1;
    }
    return 0;
}

int main(int argc, char** argv) {
    char letraArmas[SIZE] = {'Z','P','R','D','E','F','G','H','I','J','K','L'};
    int armas[SIZE][COL] = {{60,3,0,0,0},
                            {80,1,1,0,0},
                            {38,2,0,0,0},
                            {25,2,3,0,0},
                            {49,2,0,0,0},
                            {57,1,0,0,0},
                            {68,3,0,0,0},
                            {35,2,1,5,0},
                            {62,2,3,0,0},
                            {42,2,0,0,0},
                            {36,1,1,0,0},
                            {54,3,0,0,0}};
    int cromosoma[SIZE];
    int guerreros[SIZEG][ARMASG] = {{120,2,0,0},
                                    {160,1,3,0},
                                    {80,3,0,0}};
    int cantGuerreros = 3;
    int cantArmas = 12, esSolucion;
    
    int base = cantGuerreros+1;
    int cantCombinaciones = (int)pow(base,cantArmas);
    for (int i=1; i<cantCombinaciones; i++){
        cargaBin(cromosoma,base,i,cantArmas);
        esSolucion = validaSolucion(cromosoma,guerreros,cantGuerreros,cantArmas,armas);
        if (esSolucion){
            imprimeSolucion(cromosoma,cantArmas,letraArmas,cantGuerreros,guerreros);
            break;
        }
    }
    return 0;
}
