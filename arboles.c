//Estructura de datos

#include <stdio.h>
#include <stdlib.h>

struct nodo{
	struct nodo* hijo_izq;
	struct nodo* hijo_der;

	int info;
}

struct nodo* nuevoNodo(int dato){
	size_t tam_nodo = sizeof(struct nodo);

	struct nodo* nuevo_nodo = (struct nodo*) malloc(tam_nodo); //malloc/memory allocation = alojar en memoria
	
	nuevo_nodo-> info = dato;
	nuevo_nodo-> hijo_izq = NULL;
	nuevo_nodo-> hijo_der = NULL;

	return nuevo_nodo;
}


