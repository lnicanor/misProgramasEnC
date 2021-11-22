#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int tam,*ptr,*ptr2;
	printf("Ingrese el tamaño\n");
	scanf("%d",&tam);
	ptr=(int *)malloc(tam*sizeof(int));
	ptr2=(int *)calloc(tam,sizeof(int));
	ptr2=(int *)realloc(ptr2,15*sizeof(int));
	free(ptr);
	free(ptr2);
	return 0;
}