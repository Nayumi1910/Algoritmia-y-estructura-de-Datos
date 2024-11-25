

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 31 de octubre de 2024, 11:54 AM
 */

#include <iostream>
#include <iomanip>
using namespace std;
int buscarSolo(char bocaditos[],int inicio,int fin){
    if(inicio==fin)return inicio;
    int medio=(inicio+fin)/2;
    if(medio%2==0){
        if(bocaditos[medio]==bocaditos[medio+1]){
            return buscarSolo(bocaditos,medio+2,fin);
        }else{
            return buscarSolo(bocaditos,inicio,medio);
        }
    }else{
       if(bocaditos[medio-1]==bocaditos[medio]){
           return buscarSolo(bocaditos,medio+1,fin);
       }else{
           return buscarSolo(bocaditos,inicio,medio-1);
       } 
    }
}
int buscarMayor(int precios[],int inicio,int fin){
    if(inicio==fin)return inicio;
    int medio=(inicio+fin)/2;
    if(precios[medio]>precios[medio-1] and precios[medio]>precios[medio+1]){
        return medio;
    }else{
        if(precios[medio]<precios[medio+1]){
            buscarMayor(precios,medio+1,fin);
        }else{
            buscarMayor(precios,inicio,medio-1);
        }
    }
}
int main(int argc, char** argv) {
    char bocaditos[][11]={{'O','O','C','C','A','A','E','E','R','R','R'}, 
                        {'C','C','A','A','R','R','E','E','B','B','0'}, 
                        {'R','R','E','E','C','C','F','F','A','A','0'},
                        {'E','E','F','F','A','A','A','B','B','R','R'}, 
                        {'C','C','C','A','A','R','R','O','O','E','E'}, 
                        {'O','O','C','C','A','A','R','R','E','E','0'}, 
                        {'A','A','F','F','R','R','E','E','O','O','0'},
                        {'E','E','A','A','O','O','B','B','F','F','0'}};
    for(int i=0;i<8;i++){
        int tam=sizeof(bocaditos[i])/sizeof(bocaditos[i][0]);
//        cout<<tam<<endl;
        if(bocaditos[i][10]!='0'){
            int pos=buscarSolo(bocaditos[i],0,tam-1);
            cout<<"La fila "<<i+1<<" tiene un "<<bocaditos[i][pos]
                    <<" adicional"<<endl;
        }
        
    }
    int precios[][5]={{1,2,3,2,1},
                        {2,3,2,2,1},
                        {1,2,2,5,3},
                        {2,5,3,3,1},
                        {2,2,3,2,1},
                        {1,2,3,2,1},
                        {3,5,2,1,1},
                        {2,3,2,1,1}};
    for(int i=0;i<8;i++){
        int posMayor=buscarMayor(precios[i],0,4);
        cout<<"En la fila "<<i+1<<", el pasajero del asiento "
                <<posMayor+1<<" tiene el bocadito más caro"
                " que sus 2 vecinos"<<endl;
    }
    return 0;
}

