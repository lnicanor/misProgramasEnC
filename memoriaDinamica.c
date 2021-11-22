#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
	
	//Definimos la variable que indicara el tamaño de arreglo 1 y definimos los punteros que aputaran a los arreglos que se crearan
	int tam,*ptr,*ptr2;
	
	//instrucción que inicializa el generador de números aleatorios
	srand (time(NULL));

	//Definimos el numero menor de numeros aleatorios posibles
	int menor=-1000;

	//Definimos el numero mayor de numeros aleatorios posibles
	int mayor=1000;

	//Definimos una variable la cual contara el numero de pares dentro de arreglo 1
	//Esta misma variable aumentara el tamaño del arreglo con la funcion "realloc" de ser necesario
	int par=0;

	//Pedimos el tamaño del arreglo 1
	printf("Ingrese la dimension del Arreglo\n");
	scanf("%d",&tam);

	//Generamos un arreglo con la dimesion del dato que se pidio (tam) en la dirreccion de memoria de ptr con la ayuda de la funcion malloc
    ptr=(int *)malloc(tam*sizeof(int));
    
    //Generamos un arreglo de dimension 1 en la direccion de memoria de ptr2, con ayuda de la funcion calloc misma que inicializa todos los valores del arreglo en 0
    ptr2=(int *)calloc(1,sizeof(int));

    //Iniciamos un ciclo for para realizar el llenado del arreglo 1, saber cuales son los numeros pares,llenar el arreglo dos con los numeros pares
    for (int i = 0; i < tam; i++) {
    	
    	//Llenamos el arreglo con un numero aleatorio entre -1000 y 1000
        ptr[i]=menor+(rand()%(mayor-menor));

        //Condicional para saber si el numero es par
        if ( ptr[i] % 2 == 0 ){
        	par++;

        	//Redimensionamos el arreglo 2 para almacenar el numero par
            ptr2=(int *)realloc(ptr2,par*sizeof(int));
            
            //Le damos el valor del numero par el arreglo 2
            ptr2[par-1]=ptr[i];
        }
    }

    //Imprimimos la dimension de arreglo 1 y los datos que contiende dicho arreglo
    printf("La dimension del arreglo 1 es :%d y los datos que contiene son:\n",tam);
    for (int i = 0; i < tam; ++i){
    	printf("%d, ",ptr[i]);
    }

    //Imprimimos la dimension de arreglo 2 y los datos que contiende dicho arreglo
    printf("\n\nEste arreglo contiene los numeros pares del arreglo 1\n");
    printf("La dimension de este arreglo es:%d y los datos que contiene son:\n",par);
    for (int i = 0; i < par; ++i){
    	printf("%d,",ptr2[i]);
    }
    printf("\n\n");

    //Liberamos el espacio usado para el arreglo 1
    printf("Liberamos el espacio usado del arreglo 1\n");
    free(ptr);

    //Liberemos el espacio usado para el arreglo 2
    printf("Liberamos el espacio usado del arreglo 2\n", );
	free(ptr2);

	return 0;
}