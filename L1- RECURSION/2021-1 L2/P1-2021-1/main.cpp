

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 11 de septiembre de 2024, 02:16 PM
 */

#include <iostream>
#include <iomanip>
#include <ratio>
#define M 10
#define N 10
using namespace std;

int encuentraMayor(int x,int codigo[M][M],int fin){
    int op1,op2;
    if(fin==1)return codigo[x][fin-1];
    op1=codigo[x][fin-1];
    op2=encuentraMayor(x,codigo,fin-1);
    if(op1>op2){
        return op1;
    }else{
        return op2;
    }
}
int buscaNumero(int x,int codigo[M][M],int col,int maximo){
    if(col==0)return -1;
    if(codigo[x][col-1]==maximo)return col-1;
    else return buscaNumero(x,codigo,col-1,maximo);
}
void recursividad(int i,int ini,int x,int codigo[M][M]
        ,int col){
    //debemos ubicar el mayor numero y su pos, de esta
    //forma reubicarlo
    int maximo,posY;
    if(i<ini){
        //encontramos el mayor
        maximo=encuentraMayor(x,codigo,col);
        //buscamos su ubicacion
        posY=buscaNumero(x,codigo,col,maximo);
        codigo[x][posY]=-1;
        //lo imprimimos, hasta que llege a ini
        cout<<maximo<<" ";
        recursividad(i+1,ini,x,codigo,col);
    }
}
void pintado(int x,int ini,int maxi,int mini,int codigo[M][M],
        int fil,int col,int flag, int cont){
        //caso base
    if(ini>=mini){
        cont++;
        //aqui sera desde el 0 hasta llegar a ini
       recursividad(0,ini,x,codigo,col);
       cout<<endl;
       //como sabemos que ini es mayor de min, ahora
       //verificamos si es menos que max
       if(ini<maxi and flag==0){
           pintado(x+1,ini+1,maxi,mini,codigo,fil,col,0,cont);
       }else if(ini==maxi and flag==0){
           pintado(x+1,ini,maxi,mini,codigo,fil,col,1,cont);
       }else if(ini==maxi and flag==1){
           pintado(x+1,ini-1,maxi,mini,codigo,fil,col,1,cont);
       }else{
           pintado(x+1,ini-1,maxi,mini,codigo,fil,col,1,cont);
       }
    }
    
}
int main(int argc, char** argv) {
    int m=8,i=6,n=4,d=10,p=8;
    int codigo[M][M]={{1,2,3,4,5,6,7,8},
                    {1,2,3,4,5,6,7,8},
                    {1,2,3,4,5,6,7,8},
                    {1,2,3,4,5,6,7,8},
                    {1,2,3,4,5,6,7,8},
                    {1,2,3,4,5,6,7,8},
                    {1,2,3,4,5,6,7,8},
                    {1,2,3,4,5,6,7,8},
                    {1,2,3,4,5,6,7,8},
                    {1,2,3,4,5,6,7,8}};
    int cont=0;
    pintado(0,i,m,n,codigo,d,p,0,cont);
    cout<<"Durara: "<<cont<<endl;
    return 0;
}

