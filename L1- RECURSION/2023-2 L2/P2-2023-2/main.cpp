

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 9 de septiembre de 2024, 04:20 PM
 */

#include <iostream>
#include <iomanip>
#define M 8
using namespace std;

int servidor[M][M]={{0,0,0,0,0,0,0},
                    {10,0,20,30,0,20,40},
                    {0,0,0,0,0,100,0},
                    {0,0,0,0,0,80,0},
                    {50,10,5,10,0,100,4},
                    {100,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0}};
int encontrar(int nServidores,int fil,int col){
    int cantNservidor=0,cantEnviadoPaqtes=0;
    int servidorLocalizado;
    //esto es en el caso si skineer no esta en linea
    if(fil==nServidores and col== nServidores) return 0;
    
    //recorro cada columna para ver si tiene la cnatidad de
    //0 igual al numero de servidores
    //para que si esto pasa retorne 
    for(int i=0;i<nServidores;i++){
        if(servidor[i][col]==0) cantNservidor++; 
    }
    
    if(cantNservidor == nServidores){
        for(int i=0;i<nServidores;i++){
            if(servidor[col][i]!=0 and servidor[col][col]==0 ){
                cantEnviadoPaqtes++;
            }    
        }
    }
    
    if(cantNservidor ==nServidores and cantEnviadoPaqtes == nServidores-1 ){
        return col+1;
    }
    servidorLocalizado = encontrar(nServidores,fil+1,col+1);
    
    return servidorLocalizado; 
}
int main(int argc, char** argv) {
    int n=7;
    int encontro=encontrar(n,0,0);
    if(encontro){
        cout<<"Se encontro a SKYNERD en la posicion "<<encontro<<endl;
    }else{
        cout<<"No se encontro a SKYNERD"<<endl;
    }
    return 0;
}

