

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 23 de agosto de 2024, 05:25 PM
 */

#include <iostream>
#include <cmath>
#define N 4
#define M 16
using namespace std;

void cargabin(int i,int cromo[M], int num){
		//INICIAIZAMOS EL CROMO EN 0
		for(int j=0;j<num;j++){
			cromo[j]=0;
		}
		//PARA PASAR A BINARIO
		int digito;
		int indice=0;
		while(i>0){
			digito=i%2;
			i=i/2;
			cromo[indice]=digito;
			indice++;
		}
		
}

int main(){
    int n=4;
    int almacen[M]={7,17,14,19,9,12,11,8,8,6,10,12,18,7,15,11};

    int peso=23;

//	cout<<"Ingrese el peso del pedido: ";
//	cin>>peso;

    //PRIMERO CONVIERTO A CROMOSOMAS LOS DATOS
    int cromo[M];
    int combinaciones=pow(2,M);
    int solucion[100],cant=0;
    //CARGAMOS LAS COMBINACIONES

    for(int i=0;i<combinaciones;i++){
        cargabin(i,cromo,M);
        int pesoParcial=0;
        for(int k=0;k<M;k++){
            if(cromo[k]==1){
                pesoParcial=pesoParcial+almacen[k];
            }
        }
        if(peso==pesoParcial){
            solucion[cant]=i;
            cant++;
        }

    }

    //IMPRIMIR SOLUCIONES
    for(int i=0;i<cant;i++){
        cargabin(solucion[i],cromo,M);
        cout<<"Resultado "<<i+1<<": ";
        for(int k=0;k<M;k++){
            if(cromo[k]==1){
                cout<<almacen[k]<<" k ";
            }
        }
        cout<<"Ubicaciones"<<": ";
        for(int k=0;k<M;k++){
            if(cromo[k]==1){
                if(k/8==0){
                    cout<<"I";
                }else{
                    cout<<"D";
                }
                if((k/4)%2==0){
                    cout<<"A";
                }else{
                    cout<<"B";
                }
                cout<<(k%4)+1<<" ";
            }
        }
        cout<<endl;	
    }
    return 0;
}

