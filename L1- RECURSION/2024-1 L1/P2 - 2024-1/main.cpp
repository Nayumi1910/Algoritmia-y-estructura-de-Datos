

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 6 de septiembre de 2024, 05:31 PM
 */

#include <iostream>
#include <iomanip>
#define N 10
using namespace std;
int tablero[N][N]={{0,0,0,1,0,1},
                        {0,0,1,0,0,0},
                        {0,1,0,0,0,1},
                        {1,0,0,0,0,0},
                        {0,1,0,0,0,0},
                        {0,0,0,0,1,0}};
//int encontrar(int x,int y,int n,int m,int posX,
//        int posY){
//    int cont=0;
//    //caso base
//    if(posX+x>n or x-posX<0 or y+posY>m or y-posY<0){
//        return cont;
//    }
//    if(tablero[x][y] and posX==x and posY==y)cont++;
//    //por la derecha-abajo
//    for(int i=x;i<x+posX;i++){
//        cont+=tablero[i][y+posY];
//    }
//    //por abajo-izquierda
//    for(int j=y+posY;j>y-posY;j--){
//        cont+=tablero[x+posX][j];
//    }
//    //por izquierda-arriba
//    for(int i=x+posX;i>x-posX;i--){
//        cont+=tablero[i][y-posY];
//    }
//    //por derecha-arriba
//    for(int j=y-posY;j<y+posY;j++){
//        cont+=tablero[x-posX][j];
//    }
//    
//    return cont+=encontrar(x,y,n,m,posX+1,posY+1);
//    
//}


int encontrar(int x,int y,int fil,int col,int posX,int posY){
    if(posX+x>fil or posY+y>col or x-posX<0 or y-posY<0)return 0;
    int cont=0;
    if(tablero[x][y] and posX==x and posY==y)cont++;
    //a la derecha-abajo
    for(int i=x;i<=posX+x;i++){
        cont+=tablero[i][y+posY];
    }
    //abajo-izquierda
    for(int i=y;i>=y-posY;i--){
        cont+=tablero[x+posX][i];
    }
    //izquierda-arriba
    for(int i=x;i>=x-posX;i--){
        cont+=tablero[i][y-posY];
    }
    //arriba-derecha
    for(int i=y;i<=y+posY;i++){
        cont+=tablero[x-posX][i];
    }
    return cont+=encontrar(x,y,fil,col,posX+1,posY+1);
}
int main(int argc, char** argv) {
    int n=6,m=6;
    
    int x=3,y=2;
    int cont;
    cont=encontrar(x,y,n,m,1,1);
    cout<<"La cantidad de minas es: "<<cont;
    return 0;
}

