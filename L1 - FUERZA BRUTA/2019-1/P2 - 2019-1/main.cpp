

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 6 de septiembre de 2024, 07:45 AM
 */

#include <iostream>
#include <iomanip>
#define N 5
using namespace std;

int verificar(int x,int y,char tablero[N][N],char palabra[3],
        int movimientos[4][2],int size, int n, char resultado[N][N]){
    int posI,posJ,j,cumple=0,k,l,s;
    if(palabra[0]!=tablero[x][y]){
        return 0;
    }
    for(int i=0;i<4;i++){
        posI=x+movimientos[i][0];
        posJ=y+movimientos[i][1];
        
        for(j=1;j<size;j++){
            if(posI<0 or posJ<0 or posI>n or posJ>n){
                    break;
            }
            if(palabra[j]!=tablero[posI][posJ]){
                break;
            }
            posI+=movimientos[i][0];
            posJ+=movimientos[i][1];
        }
        if(j==size){
            cumple=1;
       }
         
    }
    if(cumple==1)return 1;
    return 0;
    
    
}

int main(int argc, char** argv) {
    int n=5,m=3;
    char tablero[N][N]={{'H','G','A','M','E'},
                        {'D','Q','G','Z','R'},
                        {'A','M','E','N','H'},
                        {'A','G','E','N','H'},
                        {'T','R','W','I','P'}};
    char palabra[m]={'A','G','E'};
    char resultado[N][N]={
	{' ',' ',' ',' ',' '},
	{' ',' ',' ',' ',' '},
	{' ',' ',' ',' ',' '},
	{' ',' ',' ',' ',' '},
	{' ',' ',' ',' ',' '}
	};
    int movimientos[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(verificar(i,j,tablero,palabra,movimientos,m,n, resultado)){
                cout<<"La palabra se encuentras en: "
                        <<i+1<<","<<j+1<<endl;
            }
        }
    }
    return 0;
}

