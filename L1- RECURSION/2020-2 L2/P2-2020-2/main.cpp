

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 11 de septiembre de 2024, 10:55 AM
 */

#include <iostream>
#include <iomanip>
#define MAX 10
using namespace std;
int tablero[MAX][MAX]={{0,0,0,1,0,1},
                        {0,0,1,0,0,0},
                        {0,1,0,0,0,1},
                        {1,0,0,0,0,0},
                        {0,1,0,0,0,0},
                        {0,0,0,0,1,0}};
//int mov[4][2]={{-1,0},
//                {0,1},
//                {1,0},
//                {0,-1}};
int robotSonda(int n,int m,int x,int y,int dirX,int dirY,int posX,int posY){
    int cant=0;
    //caso base
    if(x>=n or y>=m or x<0 or y<0)return 0;
    //en caso de que e sla posición exista alguna unidad
    if(tablero[x][y] and posX==0 and posY==0)cant++;
    
    //contamos lo que exista en las posiciones donde
    //se encuentra el robot 
    // como en cualquiera de las 4 posiciones, solo una ser
    //diferente de 0, la de 0 solo se contara 1 vez
    if(posX==0){
       //contamos las dos partes
        for(int i=x+1;i<n;i++){
            cant=cant+tablero[i][y];
        }
        for(int i=0;i<x;i++){
            cant=cant+tablero[i][y];
        }
    }
    if(posY==0){
        for(int i=y+1;i<m;i++){
            cant=cant+tablero[x][i];
        }
        for(int i=0;i<y;i++){
            cant=cant+tablero[x][i];
        }
    }
    cant+=robotSonda(n,m,x+dirX,y+dirY,dirX,dirY,dirX,dirY);
    return cant;
}
int main(int argc, char** argv) {
    int n=6,m=6;
    int x=3,y=2;
    // maxfil,maxcol,x,y,dirX,dirY(en este caso derecho),posX, posY
    int cant=robotSonda(n,m,x,y,0,1,0,0);
    cout<<"El resultado es: "<<cant<<endl;
    return 0;
}

