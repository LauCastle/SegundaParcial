//Estructura de datos 
//Examen Segunda parcial 

#include <stdio.h>
#include <stdlib.h> //faltó agregar libreria

int arreglo[10], n=10;//faltó

void intercambio(int *a, int *b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
void problema(int n, int arreglo[]){
	for(int i=0; i<n; i++){
	 	int min=i; //faltó declarar
	
		for(int j=i+1; j<=n; j++)
		{
			if (arreglo[j] < arreglo[min]){
				min=j;
			}
		}
		if (min !=i){
			intercambio(&arreglo[min], &arreglo[i]);
		}
	}
}

void leer_archivo(){
	FILE* archivo;
	char texto[20];
	char c;
	int j=0;
	int i=0;

	archivo = fopen("datos.txt", "rt");
	do{
		c =fgetc(archivo);
		if(c == ','){
			arreglo[j]= atoi(texto);
			j++;
			for(int z=0; z<i; z++)
				texto[z]=0;
			i=0;
			continue;
		}
		texto[i] = c;
		i++;
	}while(c!=EOF);
}

void pantalla(int arreglo[], int n){
	for(int j=0; j<n-1; j++)
		printf("%d, ", arreglo[j]);
	printf("%d\n", arreglo[n-1]);
}

void main(){
	
	leer_archivo();

	pantalla(arreglo,n);
	problema(n,arreglo);
	pantalla(arreglo,n);

}
