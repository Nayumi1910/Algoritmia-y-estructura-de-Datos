

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 12 de septiembre de 2024, 09:25 PM
 */

#include <iostream>
#include <iomanip>
#define M 10
using namespace std;



void llenarRecursivo(int matriz[M][M],int fil,int col,int pro,int cont){
    //caso base, hasta que agotemos los productos
    if(pro<=0){
        if(pro==0)cout<<"Se pudo"<<endl;
        else cout<<"No se pudo"<<endl;
        return;
    }
    //lo divimos en dos partes, cuando sea columna par
    //o cuando sea impar

    if(col%2!=0){
        if(fil==0)pro=pro+1;
        for(int i=0;i<=(cont/2);i++){
            if(matriz[fil][(col/2)+i]==0 and pro>0 
                    and ((col/2)+i)<col){
                matriz[fil][(col/2)+i]=5;
                pro--;
            }
            if(matriz[fil][(col/2)-i]==0 and pro>0
                    and ((col/2)-i)>=0){
                matriz[fil][(col/2)-i]=5;
               pro--;
            }
            
        }
    }else{
        if(fil==0)pro=pro+2;
        int a=col/2, b=(col/2)-1;
        for(int i=0;i<=(cont/2);i++){
            if(matriz[fil][a+i]==0 and pro>0 and ((col/2)+i)<col){
                matriz[fil][a+i]=5;
                pro--;
            }
            if(matriz[fil][b-i]==0 and pro>0 and ((col/2)-i)>=0){
                matriz[fil][b-i]=5;
                pro--;
            }
            
        }
    }
    llenarRecursivo(matriz,fil+1,col,pro,cont+2);
}
int main(int argc, char** argv) {
    int f=6,c=6,p=27;
    int matriz[M][M]={{0,0,0,0,0,0},
                    {0,0,0,0,0,0},
                    {0,0,0,1,0,0},
                    {0,1,0,0,0,0},
                    {0,0,0,0,1,0},
                    {0,0,0,0,0,0}};
    int inicio=1;
    llenarRecursivo(matriz,0,c,p,inicio);
    for(int i=0;i<f;i++){
        for(int j=0;j<c;j++){
            cout<<matriz[i][j];
        }
        cout<<endl;
    }
    return 0;
    
}

