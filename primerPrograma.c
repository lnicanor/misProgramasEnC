//importaciones
#include <stdio.h>

//funcion principal
int main()
{
  //Declaramos la variables
  int d1,d2,d3,s,m;
  float p;
    printf( "Ingrese el dato 1:\n" );
    scanf("%d",&d1 );
    printf( "Ingrese el dato 2:\n" );
    scanf("%d",&d2 );
    printf( "Ingrese el dato 3:\n" );
    scanf("%d",&d3);
    //Realizamos las operaciones;
    s=d1+d2+d3;
    m=d1*d2*d3;
    p=s/3;
    printf("La suma es: %d\t\n",s);
    printf("El producto es: %d\t\n",m);
    printf("El promedio es;: %f\t\n",p);

    return 0;
}
