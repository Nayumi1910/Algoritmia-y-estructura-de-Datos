

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 24 de octubre de 2024, 05:40 PM
 */

#include <iostream>
#include <iomanip>
using namespace std;
int encontrarTriple(int productos[],int stock[],int inicio,int fin){
    if(inicio==fin){
        cout<<"Son del producto :"<<productos[inicio]<<endl;
        cout<<"Las cajas se encuentran en las posiciones: "
                <<inicio-2<<" "<<inicio-1<<" "<<inicio<<endl;
        return stock[inicio-2]+stock[inicio-1]+stock[inicio];
    }
    int medio=(inicio+fin)/2;
    if(medio%2==0){
        if(productos[medio]==productos[medio+1]){
            encontrarTriple(productos,stock,medio+2,fin);
        }else{
            encontrarTriple(productos,stock,inicio,medio);
        }
    }else{
        if(productos[medio]==productos[medio-1]){
            encontrarTriple(productos,stock,medio+1,fin);
        }else{
            encontrarTriple(productos,stock,inicio,medio-1);
        }
    }
}

int main(int argc, char** argv) {
    int productos[]={1,1,2,2,4,4,5,5,5,6,6};
    int stock[]={20,20,30,10,10,10,20,20,20,10,10};
    int n=11;  
    int stk=encontrarTriple(productos,stock,0,n-1);
    cout<<"Su stock suma : "<<stk<<endl;
    return 0;
}

