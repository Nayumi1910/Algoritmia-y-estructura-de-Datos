

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 6 de diciembre de 2024, 07:47 PM
 */

#include <iostream>
#include <iomanip>

using namespace std;
int max(int a,int b){
    if(a>b){
        return a;
    }else{
        return b;
    }
}
int encontrarMayor(int matriz[],int ini,int fin,int &col){
    if(ini>fin){
        col=fin;
        return matriz[fin];
    }
    int medio=(ini+fin)/2;
    if(matriz[medio]>=matriz[medio-1]){
        encontrarMayor(matriz,medio+1,fin,col);
    }else{
        encontrarMayor(matriz,ini,medio-1,col);
    }

}


int main(int argc, char** argv) {
//    int dias[]={98,95,92,89,91,92,89,89,92,93,94,92
//            ,91,90,88,88,88,89,90,91,88,88,90,90,92,89,90,88,90,91};
//    int n=sizeof(dias)/sizeof(dias[0]);
    int matriz[][7]={{0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0},
                    {0,0,0,0,1,1,1},
                    {0,0,0,0,1,2,2},
                    {0,0,0,0,1,2,3},
                    {0,0,0,0,1,2,2},
                    {0,0,0,0,1,1,1},
                    {0,0,0,0,0,0,0}};
    int n=7,m=10;
    robotMinas(matriz,n,m);
    return 0;
}

