/* 
 * File:   funcionesLista.h
 * Author: ANA RONCAL
 *
 * Created on 1 de setiembre de 2024, 22:27
 */

#ifndef FUNCIONESLISTA_H
#define FUNCIONESLISTA_H

void construir(struct Lista &);
const bool esListaVacia(const struct Lista &);
int longitud(const struct Lista &);

//void insertarAlInicio(struct Lista &, Elemento);
void insertarAlFinal(struct Lista &, Elemento);
//void insertarEnOrden(struct Lista &, int);

struct Nodo * crearNodo(Elemento elemento, struct Nodo *);
//struct Nodo * obtenerUltimoNodo(const struct Lista &);
//struct Nodo * obtenerNodoAnterior(const struct Lista &, Elemento);
//struct Nodo * seEncuentra(const struct Lista &, int);
Elemento retornaCabeza(const struct Lista & lista);

//void eliminaNodo(struct Lista &, int);
void eliminaCabeza(struct Lista &);
//void eliminaCola(struct Lista);
//
//void destruir(struct Lista &);
void imprime(const struct Lista &);

#endif /* FUNCIONESLISTA_H */