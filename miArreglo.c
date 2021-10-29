//llamamos a las librerias que usaremos
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//inicializacion de la funcion principal
int main() {
  //instrucción que inicializa el generador de números aleatorios
  srand (time(NULL));
  /*
  Se declara la variable t para hacer referencia al tamaño del arreglo
  Se declaran la variable de control opc para saber que opcion requiere el usuario
  Se declaran dos arreglos , uno entero y uno flotante ambos del tamaño de valor de "t"
  */
  int t=15,arreglo1[t],opc;
  float arreglo2[t];
  //Se crean dos variables de tipo entero para definir el rango de los numeros aleatorios que se generaran
  int menor=-100;
  int mayor=100;
  //inicializamos la estructura de control de tipo bucle
  opc=1;
  while (opc>0 & opc<3) {
    //Se pide el dato al usuario para saber como se llenara el arreglo
    printf("1:llenar arreglo manualmente\n2:llenar el arreglo con numeros aleatorios entre -100 y 100\n");
    scanf("%d",&opc );
    if (opc==1) {
      printf("<-- llenar manualmente -->\n");
      //Se inicializa la estructura repetitiva for para llenar el arreglo por medio del teclado
      for (int i = 0; i < t; i++) {
        printf("\narreglo[%d", i);
        printf("]=");
  	    scanf("%d", &arreglo1[i]);
        //Se llena un arreglo con la conversion del arreglo inicial de int a float
        arreglo2[i]=(float)arreglo1[i];
      }
    }
    if (opc==2) {
      printf("<-- llenar automaticamente -->\n");
      //se inicializa la estructura for para llenar el arreglo por medio de la funcion rand y con un intervalo de [-100 , 100]
      for (int i = 0; i < t; i++) {
        arreglo1[i]=menor+(rand()%(mayor-menor));
        //Se llena un arreglo con la conversion del arreglo inicial de int a float
        arreglo2[i]=(float)arreglo1[i];
      }
    }
    if (opc>=3 || opc<1) {
      printf("<-- Opcion no encontrada -->\n");
    }
    if (opc>=1 & opc<=2) {
      //Se imprime el arreglo inicial
      printf("ArregloOriginal[");
      for (int j = 0; j < t; j++) {
        printf("%d",arreglo1[j]);
        printf(",");
      }
      printf("]\n" );
      //Se imprime el arreglo inicial multiplicado por 2
      printf("ArregloMultiplicado[");
      for (int k = 0; k < t; k++) {
        printf("%d",arreglo1[k]*2);
        printf(",");
      }
      printf("]\n" );
      //Se imprime el arreglo inicial de tipo float divido entre 3
      printf("ArregloDividido[");
      for (int y = 0; y < t; y++) {
        printf("%f",arreglo2[y]/3);
        printf(",");
      }
      printf("]\n" );
      }
    }
  return 0;
}
