//Estructura de datos 
//Examen Segunda parcial 

#include <stdio.h>
int arreglo[10];
int indexmin=0;

void intercambio(int *a, int *b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
void problema(int min, int i, int j, int arreglo[]){
	int n=20;
	for(j=i+1; j=n; j++)
	{
		if (arreglo[j]<arreglo[min]){
			min=j;
		}
	}
	if (indexmin !=1){
		intercambio(&arreglo[min], &arreglo[i]);
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
	int n=0;
	int t=10;
	int num=0;

	leer_archivo(arreglo,t);
	pantalla(arreglo,t);
	problema(n,t);
	pantalla(arreglo,t);
}
