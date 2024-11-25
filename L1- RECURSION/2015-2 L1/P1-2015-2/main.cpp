

/* 
 * Proyect: $(project.name)
 * File:   main.cpp
 * Author: Karolyn Nayumi Aquiño Torres
 * Codigo: 20203608
 *
 * Created on 10 de septiembre de 2024, 08:42 PM
 */

#include <iostream>
#include <iomanip>
using namespace std;


void triangulo(int a,int b){
    if(a>b)return;
    
    for(int i=0;i<a;i++){
        cout<<"*";
    }
    cout<<endl;
    triangulo(a+1,b);
    for(int i=0;i<a;i++){
        cout<<"*";
    }
    cout<<endl;
}
int main(int argc, char** argv) {
    int a=3,b=5;
    triangulo(a,b);
    return 0;
}

