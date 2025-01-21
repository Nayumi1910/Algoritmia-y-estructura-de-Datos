/* 
 * File:   funcionesCola.h
 * Author: ANA RONCAL
 * Created on 12 de septiembre de 2023, 09:32 PM
 */

#ifndef FUNCIONESCOLA_H
#define FUNCIONESCOLA_H

#include "NodoArbol.h"


void construir(struct Cola & cola);
bool esColaVacia(const struct Cola & cola);
void encolar(struct Cola & cola, NodoArbol *nodo);
NodoArbol *desencolar(struct Cola & cola);
int longitud(struct Cola cola);
void imprime(const struct Cola & cola);
void destruirCola(struct Cola & cola);

#endif /* FUNCIONESCOLA_H */

