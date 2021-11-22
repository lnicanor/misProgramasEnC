#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
	int tam,*ptr,*ptr2;
	srand (time(NULL));
	//Se crean dos variables de tipo entero para definir el rango de los numeros aleatorios que se generaran
	int menor=-1000;
	int mayor=1000;
	int par=0;

	printf("Ingrese la dimension del Arreglo\n");
	scanf("%d",&tam);
    ptr=(int *)malloc(tam*sizeof(int));
    ptr2=(int *)calloc(1,sizeof(int));
    for (int i = 0; i < tam; i++) {
        ptr[i]=menor+(rand()%(mayor-menor));
        if ( ptr[i] % 2 == 0 ){
            ptr2=(int *)realloc(ptr2,par*sizeof(int));
            ptr2[par-1]=ptr[i];
        }
    }

   printf("La dimension del arreglo 1 es :%d y los datos que contiene son:\n",tam);
    for (int i = 0; i < tam; ++i)
    {
    	printf("%d, ",ptr[i]);
    }

    printf("\n\nEste arreglo contiene los numeros pares del arreglo 1\n");
    printf("La dimension de este arreglo es:%d y los datos que contiene son:\n",par);
    for (int i = 0; i < par; ++i)
    {
    	printf("%d,",ptr2[i]);
    }
    printf("\n\n");

    printf("Liberamos el espacio usado del arreglo 1\n");
    free(ptr);
    printf("Liberamos el espacio usado del arreglo 2\n", );
	free(ptr2);

	return 0;
}