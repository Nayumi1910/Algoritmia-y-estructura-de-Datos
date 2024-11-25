

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 9 de septiembre de 2024, 03:07 PM
 */

#include <iostream>
#include <iomanip>
#define M 10
#define ROBOTS 4
using namespace std;
int ciudad[M][M]={{0,0,42,0,0,0,0,35,0,0},
                  {0,0,0,0,0,0,0,0,0,0},
                  {0,27,0,0,0,0,50,0,0,0},
                  {0,0,30,0,0,0,0,0,0,0},
                  {0,0,0,0,38,0,0,42,0,0},
                  {15,0,0,50,0,0,0,50,0,0},
                  {0,0,0,0,0,0,0,0,0,0},
                  {0,0,0,0,50,0,37,0,0,0},
                  {0,18,0,17,0,0,0,0,50,0},
                  {0,0,0,0,0,0,0,0,0,0}};
int tableroSol[M][M];
int poderes[M]={75,58,65,80};
int direccion[M]={1,0,1,1};
int movimientos[ROBOTS][2]={{0,1},
                            {1,0},
                            {0,1},
                            {0,1}
                                };
int robotActual=0;
int flag=1;
bool encontrar(int posX,int posY){
    int x,y;
    x=posX+movimientos[robotActual][0];
    y=posY+movimientos[robotActual][1];
    
    if(flag){
        tableroSol[posX][posY]=robotActual+1;
        flag=0;
    }
    if(ciudad[x][y]==0){
        tableroSol[x][y]=robotActual+1;
    }
    else{
        if(poderes[robotActual]>=ciudad[x][y]){
            poderes[robotActual]=poderes[robotActual]-ciudad[x][y];
            tableroSol[x][y]=robotActual+1;
            if(ciudad[x][y]==50){
                return true;
            }
        }else{
            robotActual++;
            x=posX;
            y=posY;
        }
    }
    if(robotActual==ROBOTS-1 and poderes[ROBOTS-1]<=0)return 0;
    
    encontrar(x,y);
    return true;
}
int main(int argc, char** argv) {
    
    int n=10,m=4;
    int x=0,y=0;
    
    if(encontrar(0,0))cout<<"Las tortugas lograron vencer a SuperFly"<<endl;
    else cout<<"Las tortugas no lograron vencer a SuperFly"<<endl;
    
    for(int i=0;i<M;i++){
        for(int j=0;j<M;j++){
            if(tableroSol[i][j]==1)cout<<setw(3)<<"L";
            else if(tableroSol[i][j]==2)cout<<setw(3)<<"R";
            else if(tableroSol[i][j]==3)cout<<setw(3)<<"D";
            else if(tableroSol[i][j]==4)cout<<setw(3)<<"A";
            else cout << setw(3) << tableroSol[i][j];
        }
        cout << endl;
    }

    
    return 0;
}

