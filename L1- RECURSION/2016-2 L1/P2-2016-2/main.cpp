

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 11 de septiembre de 2024, 12:01 AM
 */

#include <iostream>
#include <iomanip>
#define M 4
using namespace std;

int matriz[M][M]={{3,-2,4},
                    {1,-2,3}};

int maximizar(int n,int m,int x,int y){
    int derecha=-10000,abajo=-1000;

    if(x==n-1 and y==m-1)return matriz[x][y];
    if(y<m-1){
        derecha=maximizar(n,m,x,y+1);
    }
    if(x<n-1){
        abajo=maximizar(n,m,x+1,y);
    }
    if(derecha>abajo){
        return matriz[x][y]+derecha;
    }else{
        return matriz[x][y]+abajo;
    }
}
int main(int argc, char** argv) {
    int n=2,m=3;
    int max;
    max=maximizar(n,m,0,0);
    cout<<"La maximización es: "<<max<<endl;
    return 0;
}

