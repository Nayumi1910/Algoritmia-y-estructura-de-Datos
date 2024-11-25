

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 11 de septiembre de 2024, 01:11 AM
 */

#include <iostream>
#include <iomanip>
#define M 5
using namespace std;
int maquinas[M][M]={{100,150,200},
                    {100,100,100},
                    {100,200,150}};
int buscarMayor(int n,int fil,int col){
    int max;
    if(col==n-1)return maquinas[fil][col];
    max=buscarMayor(n,fil,col+1);
    if(maquinas[fil][col]>=max){
        max=maquinas[fil][col];
    }
    return max;
}
int maquinasTrabajo(int n,int x,int y,int obreros[M]){
    int cant=0;
    int max;
    if(x==n or y==n)return cant;
    
    //primer
    cant=maquinasTrabajo(n,x+1,y,obreros);
    max=buscarMayor(n,x,0);
    if(x==2)obreros[2]=max;
    if(x==1)obreros[1]=max;
    if(x==0)obreros[0]=max;
    return max+cant;
}
int main(int argc, char** argv) {
    int n=3;
    int obreros[M];
    int max=maquinasTrabajo(n,0,0,obreros);
    cout<<"La maxima solucion: "<<max<<" piezas"<<endl;
    cout<<"Obrero 1:"<<obreros[0]<<endl;
    cout<<"Obrero 2:"<<obreros[1]<<endl;
    cout<<"Obrero 3:"<<obreros[2]<<endl;
    return 0;
}

