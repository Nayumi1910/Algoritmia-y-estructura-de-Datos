/* 
 * File:   Nodo.h
 * Author: ANA RONCAL
 * Created on 18 de septiembre de 2023, 05:55 PM
 */

#ifndef NODO_H
#define NODO_H
struct Elemento{
    int dato;
    char tiempo[15];
    char dni[10];
    double monto;
    char estado;
};
struct NodoArbol{
    Elemento elemento;  //Este dato representa el Elemento
    struct NodoArbol * izquierda;  //puntero al hijo izquierdo
    struct NodoArbol * derecha;   //puntero al hijo derecho
};

#endif /* NODO_H */

