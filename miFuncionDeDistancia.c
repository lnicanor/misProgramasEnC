//Incluimos las librerias
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>
//Modelado de la funcion
float calcularDistancia(float x1, float y1, float x2, float y2);

int main ()
{
  //Declaramos las variables que llenara el usuario
    float  x1, x2, y1, y2;
  //ingreso de datos por el usuario
    printf ("Ingresa el valor de x1: ");
    scanf ("%f", &x1);
    printf ("Ingresa el valor de y1: ");
    scanf ("%f", &y1);
    printf ("Ingresa el valor de x2: ");
    scanf ("%f", &x2);
    printf ("Ingresa el valor de y2: ");
    scanf ("%f", &y2);
    //Mostramos las coordenadas de los puntos
    printf("Las coordenadas del punto 1 son ( %.1f",x1);
    printf(",%.1f",y1);
    printf(")\n");
    printf("Las coordenadas del punto 1 son ( %.1f",x2);
    printf(",%.1f",y2);
    printf(")\n");
    //Calculamos la distancia entre ambas coordenadas y posteriormente la mostramos en pantalla
    printf ("La distancia entre ambos puntos es: %.2f\n",calcularDistancia(x1,y1,x2,y2));
    return 0;
}
//Calculamos la distancia por medio la funciones calcularDistancia a la que le enviamos los valores x1,y1,x2,y2
float calcularDistancia(float x1, float y1, float x2, float y2){
  float  distancia=sqrt(pow((x2-x1),2)+pow((y2-y1),2));
  return distancia;
}
