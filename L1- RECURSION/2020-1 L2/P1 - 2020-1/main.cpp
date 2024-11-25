

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 10 de septiembre de 2024, 03:12 PM
 */

#include <iostream>
#include <iomanip>
#define MAX 6
using namespace std;
int tableroSol[MAX][MAX];
void solucionMonticulo(int tablero[MAX][MAX],int col,int fil,int posX,int posY){
    int cont=0;
    //caso base por si pasa los bordes
    if(posX>fil or posY>col){
        return;
    }
    if(posY==col-1){//condición especial, "caso base", cuando al terminar el remolino se queda con una fila
        for(int i=posX;i<fil;i++)	
                cout << tablero[i][posY] << " ";
        return;
    }
    if(posX==fil-1){//condición especial, "caso base", cuando al terminar el remolino se queda con una columna
        for(int i=posY;i<col;i++)	
                cout << tablero[posX][i] << " ";
        return;
    }
    //la derecha
    for(int i=posY;i<col-1;i++){
        cout<<tablero[posX][i]<<" ";
    }

    //abajo
    for(int i=posX;i<fil-1;i++){
        cout<<tablero[i][col-1]<<" ";
    }

    //izquieda
    for(int i=col-1;i>posY;i--){
        cout<<tablero[fil-1][i]<<" ";
    }

    //arriba
    for(int i=fil-1;i>posX;i--){
        cout<<tablero[i][posY]<<" ";
    }

    solucionMonticulo(tablero,col-1,fil-1,posX+1,posY+1);
}

int main(int argc, char** argv) {
    int n=6,m=6,cont=1;
    int tablero[MAX][MAX];
    for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			tablero[i][j] = cont;
			cont++;
		}
	}
    solucionMonticulo(tablero,n,m,0,0);

    return 0;
}

