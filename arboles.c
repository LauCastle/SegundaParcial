//Estructura de datos

#include <stdio.h>
#include <stdlib.h>

struct nodo{
	struct nodo* hijo_izq;
	struct nodo* hijo_der;

	int info;
};


struct nodo* nuevoNodo(int dato){
	size_t tam_nodo = sizeof(struct nodo);

	struct nodo* nuevo_nodo = (struct nodo*) malloc(tam_nodo); //malloc/memory allocation = alojar en memoria
	
	nuevo_nodo-> info = dato;
	nuevo_nodo-> hijo_izq = NULL;
	nuevo_nodo-> hijo_der = NULL;

	return nuevo_nodo;
}
void insertarNodo(struct nodo* nd, int dato)
{
	if (dato > nd -> info){
		if(nd -> hijo_der == NULL){
			nd-> hijo_der=nuevoNodo(dato);
		} else{
		insertarNodo(nd->hijo_der, dato);
		}
	}else{
	if(nd->hijo_izq==NULL){
		nd-> hijo_izq=nuevoNodo(dato);
	}else{
		insertarNodo(nd->hijo_izq, dato);
	}
	}
}
int main()
{
	struct nodo* raiz=NULL;
	raiz = nuevoNodo(8);
	insertarNodo(raiz,3);
	insertarNodo(raiz,20);

	return 0;
}
