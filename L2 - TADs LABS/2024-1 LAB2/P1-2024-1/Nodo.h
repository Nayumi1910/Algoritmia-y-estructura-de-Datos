/* 
 * File:   Nodo.h
 * Author: ANA RONCAL
 * Created on 12 de septiembre de 2023, 09:31 PM
 */

#ifndef NODO_H
#define NODO_H
struct Fecha{
    int dd;
    int mm;
    int aa;
};
struct Elemento{
    Fecha fecha;
    char codigo[8];
};
struct Nodo{
    Elemento elemento;
    struct Nodo * siguiente;
};

#endif /* NODO_H */

