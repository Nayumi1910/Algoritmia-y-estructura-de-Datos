

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 5 de septiembre de 2024, 06:21 PM
 */

#include <iostream>
#include <iomanip>
#define MAXC 10
#define MAXF 4
using namespace std;

void actualizaPalabraAux(char palabra[3],char aux[3],int size){
    for(int i=0;i<size;i++){
        aux[i]=palabra[i];
    }
}
int evaluar(char letra,char aux[3],int size){
    for (int i=0; i<size; i++){
        if (aux[i]==letra){
            aux[i] = ' ';
            return 1;
        }
    }
    return 0;

}
int verificar(char dato[MAXF][MAXC],char palabra[3],int movimiento[MAXF][2],
        int x, int y){
    int size=3,pertenece;
    char aux[3];
    actualizaPalabraAux(palabra,aux,size);
    char letra=dato[x][y];
    pertenece=evaluar(letra,aux,size);
    int posI,posJ,cumple=0;
    
    if(pertenece){
        
        //buscamos la palabra
        for(int i=0;i<4;i++){
            posI=x+movimiento[i][0];
            posJ=y+movimiento[i][1];
            
            if(posI<=0 or posJ<=MAXC or posI<=MAXF){
                letra=dato[posI][posJ];
                pertenece=evaluar(letra,aux,size);
                if(pertenece){
                    cumple=1;
                    for(int j=2;j<size;j++){
                        posI+=movimiento[i][0];
                        posJ+=movimiento[i][1];
                        if(posI<=0 or posJ<=MAXC or posI<=MAXF){
                            letra=dato[posI][posJ];
                            pertenece=evaluar(letra,aux,size);
                            if(pertenece==0){
                                cumple=0;
                                break;
                            }
                        }
                        else{
                            cumple=0;
                            break;
                        }
                    }
                    if(cumple){
                        return 1;
                    }
                }
            }
            
           
        }
        return cumple;
    }
    
}
int main(int argc, char** argv) {
    int n=4,m=10;
    char dato[MAXF][MAXC]={{'H','C','H','B','Y','S','O','S','O','H'},
    {'S','C','S','S','Y','Q','O','S','Z','K'},
    {'O','P','N','Y','O','K','F','H','C','K'},
    {'O','B','N','I','Y','S','P','O','O','K'}};
    char palabra[3]={'H','S','O'};
    int movimiento[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(verificar(dato,palabra,movimiento,i,j)){
                cout<<"En la posicion: "<<i<<" , "<<j<<endl;
            }
        }
    }
    
    return 0;
}

