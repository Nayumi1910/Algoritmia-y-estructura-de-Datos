

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 12 de septiembre de 2024, 07:52 PM
 */

#include <iostream>
#include <iomanip>
#define M 10
using namespace std;

void imprimir(int fin,char c){
    for(int i=0;i<fin;i++)cout<<c;
    cout<<endl;
}
void produccion(int n,int m,int a,int crecimiento,int cantidad){
    
    if(a==0 or (a==0 and cantidad>m))return;
    cout<<"Entrada"<<endl;
    if(a==1 or cantidad>m)return;
    if(a>=2){
        imprimir(cantidad,'*');
        if(a>2){
            if(a!=3){
               imprimir(cantidad,'*');
               a=a-3;
            }else return;
        }else a=0;
    }
    if(cantidad==n)crecimiento=1;
    if(crecimiento==1)cantidad++;
    else cantidad--; 
    produccion(n,m,a,crecimiento,cantidad);
}
int main(int argc, char** argv) {
    int n=3,m=7,a=14;
    
    cout<<"Para N="<<n<<" M="<<m<<" A="<<a<<endl;
    imprimir(M,'=');
    produccion(n,m,a,0,m);   
    imprimir(M,'=');
    return 0;
}

