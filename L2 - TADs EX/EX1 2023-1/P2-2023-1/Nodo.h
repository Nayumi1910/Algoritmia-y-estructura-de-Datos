/* 
 * File:   Nodo.h
 * Author: ANA RONCAL
 * Created on 12 de septiembre de 2023, 09:31 PM
 */

#ifndef NODO_H
#define NODO_H
struct Elemento{
    char codigo[10];
    int prioridad;
};
struct Nodo{
    Elemento elemento;
    struct Nodo * siguiente;
};

#endif /* NODO_H */

