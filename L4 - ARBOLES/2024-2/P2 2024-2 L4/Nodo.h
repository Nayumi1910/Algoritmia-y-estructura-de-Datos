/* 
 * File:   Nodo.h
 * Author: ANA RONCAL
 *
 * Created on 1 de setiembre de 2024, 20:43
 */

#ifndef NODO_H
#define NODO_H
struct Elemento{
    int age;
    int cant;
};
/*Nodo esta formado por Elemento y un puntero al siguiente Nodo*/
struct Nodo {
    Elemento elemento; /*Dato que cambia por double, char, struct Elemento*/
    struct Nodo * siguiente; /*puntero a una variable de tipo struct Nodo*/
};

#endif /* NODO_H */