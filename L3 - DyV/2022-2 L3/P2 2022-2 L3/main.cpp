

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 28 de octubre de 2024, 06:20 PM
 */

#include <iostream>
#include <iomanip>
using namespace std;
void encontrarMinas(int matriz[],int inicio,int fin,int &col,int &max){
    if(inicio>=fin){
        if(matriz[inicio]>max){
            max=matriz[inicio];
            col=inicio;
        }
        return;
    }
    int medio=(inicio+fin)/2;
    if(matriz[medio]<matriz[medio+1]){
        encontrarMinas(matriz,medio+1,fin,col,max);
    }else{
        encontrarMinas(matriz,inicio,medio,col,max);
    }
}
int encontrarFila(int matriz[][7],int col,int inicio,int fin,int max){
    if(inicio>=fin)return inicio;
    int medio=(inicio+fin)/2;
    if(matriz[medio][col-1]==max){
        return medio;
    }else{
        if(matriz[medio][col-1]<matriz[medio+1][col-1]){
            encontrarFila(matriz,col,medio+1,fin,max);
        }else{
            encontrarFila(matriz,col,inicio,medio,max);
        }
    }
}
void robotMinas(int matriz[][7],int col,int fil){
    int max=0,n;
    for(int i=0;i<fil;i++){
        encontrarMinas(matriz[i],0,col-1,n,max);
    }
    cout<<"La bomba maxima es: "<<max<<endl;
    cout<<"En la columna: "<<n<<endl;
    cout<<"La fila de mayor impacto: "<<encontrarFila(matriz,col,0,fil-1,max)<<endl;
}
int main(int argc, char** argv) {
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

