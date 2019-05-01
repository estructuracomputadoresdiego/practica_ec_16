#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void inicializa(int *matriz, int filas, int columnas);
int media(int *matriz, int filas, int columnas);
void imprimerMatriz(int *matriz, int filas, int columnas);
char sacarLetra(char *cadena, int posicion);

int main(int argc, char const *argv[]){
	
	srand(time(NULL));

	if (argc < 3){
		printf(" El número de argumentos adecuado sería ejeutar el programa como ./programa 3 5\n");
		exit(-1);
	}

	int filas = atoi(argv[1]);
	int columnas = atoi(argv[2]);
	int posicion;

	int* matriz;
	matriz = (int*)malloc(sizeof(int)*filas*columnas);

	char* cad;
	cad = (char*)malloc(sizeof(char)*100);

	inicializa(matriz, filas, columnas);

	printf("La matriz es: \n\n");

	imprimerMatriz(matriz, filas,columnas);

	printf("La media de la matriz es %d\n", media(matriz, filas, columnas));

	printf("Introduce una cadena de maximo 99 caracteres\n");

	fgets(cad, 99, stdin);

	do{
		printf("\nIntroduce la posicion de la letra que quieres obtener\n");
		scanf("%d", &posicion);
		if (posicion < 1 || posicion > 99){
			printf("\nEl numero introducido debe estar entre 1 y 99\n");
		}
	} while (posicion < 1 || posicion > 99);

	printf("\nLa letra en la posicion %d es '%c'\n",posicion, sacarLetra(cad, posicion));

	free(matriz);
	free(cad);
	return 0;
}

void inicializa(int *matriz, int filas, int columnas){

	int random;

	for (int i = 0; i < filas; ++i){
		for (int j = 0; j < columnas; ++j){

			random = 3+rand()%(7+1-3);
			*(matriz+filas*i+j) = random;
		}
	}
}

int media(int *matriz, int filas, int columnas){

	int suma = 0;
	int media;

	for (int i = 0; i < filas; ++i){
		for (int j = 0; j < columnas; ++j){

			suma = suma + *(matriz+filas*i+j);
		}
	}

	media = suma/(filas*columnas);

	return media;
}

void imprimerMatriz(int *matriz, int filas, int columnas){


	for (int i = 0; i < filas; ++i){
		for (int j = 0; j < columnas; ++j){

			printf("\t%d", *(matriz+filas*i+j));
		}
		printf("\n");
	}
	printf("\n");
}

char sacarLetra(char *cadena, int posicion){

	char salida;

	posicion --;

	salida = *(cadena+posicion);

	return salida;
}