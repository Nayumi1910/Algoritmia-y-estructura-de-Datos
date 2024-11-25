/* 
 * File:   Lista.h
 * Author: ANA RONCAL
 * Created on 12 de septiembre de 2023, 09:32 PM
 */

#ifndef LISTA_H
#define LISTA_H
#include "Nodo.h"

struct Lista{
    struct Nodo * cabeza;
    struct Nodo * cola;
    struct Nodo * subida;
    struct Nodo * bajada;
    int longitud;
};

#endif /* LISTA_H */

