/* Desarrollar un  codigo c que permita declarar un arreglo de 4 elementos
te tipo entero llenandolos del uno al 1 eh imprimiendo dichos elementos asi como sus direcciones de memoria
Que se declare un arreglo bidimensional de 3 filas y dos columnas de tipo entero llenandolo con valores del un
al 6 imprimiendo su contenido y la direccion de memoria de cada elemento
*/
#include <stdio.h>
int main() {
  int a=5,b=10,c=15,d=20,arreglo1[4],arreglo2[3][2],y=1,*ptru=&a,*ptr1=&arreglo1[0],*ptr2=&arreglo2[0][0];
  //Mostramos el valor de las variables unitarias y mostramos su posicion de memoria
  printf("Las variables unitarias originales son: \n");
  printf("El valor de la variable a es: %d y su posicion de memoria es:%p\n",a,&a );
  printf("El valor de la variable b es: %d y su posicion de memoria es:%p\n",b,&b );
  printf("El valor de la variable c es: %d y su posicion de memoria es:%p\n",c,&c );
  printf("El valor de la variable d es: %d y su posicion de memoria es:%p\n",d,&d );
  //Modificamos el valor de las variable unitarias
  for (int x = 0; x < 4; x++) {
     *ptru=*ptru*2;
     ptru--;
  }
  //Mostramos el nuevo valor de las variables unitarias y mostramos su posicion de memoria
  printf("Las variables unitarias * 2 son: \n");
  printf("El valor de la variable a es: %d y su posicion de memoria es:%p\n",a,&a );
  printf("El valor de la variable b es: %d y su posicion de memoria es:%p\n",b,&b );
  printf("El valor de la variable c es: %d y su posicion de memoria es:%p\n",c,&c );
  printf("El valor de la variable d es: %d y su posicion de memoria es:%p\n",d,&d );
  //Llenamos el arreglo1 con valores del 1 al 4
  printf("El arreglo1 original es: \n");
  for (int x = 0; x < 4; x++) {
     arreglo1[x]=x+1;
     printf("arreglo1[%d]=%d y su direccion de memoria es=%p\n",x,arreglo1[x],&arreglo1[x]);
  }
  //Llenamos el arreglo con valores del 1 al 6
  printf("El arreglo2 original es: \n");
  for (int j = 0; j < 3; j++) {
    for (int x = 0; x < 2; x++) {
      arreglo2[j][x]=y;
      y++;
      printf("arreglo2[%d][%d]=%d y su direccion de memoria es=%p\n",j,x,arreglo2[j][x],&arreglo2[j][x]);
    }
  }
  //Multiplicamos el valor de la variable a la que hace referencia el puntero * 2 y mostramos el valor en pantalla
  printf("El arreglo1 Multiplicado * 2 mediante aritmetica de punteros es: \n");
  for (int x = 0 ; x < 4 ; x++) {
     *ptr1=arreglo1[x]*2;
     ptr1++;
     printf("arreglo1[%d]=%d y su direccion de memoria es=%p\n",x,arreglo1[x],&arreglo1[x]);
  }
  //Multiplicamos el valor de la variable a la que hace referencia el puntero * 2 y mostramos el valor en pantalla
  printf("El arreglo2 Multiplicado * 2 mediante aritmetica de punteros es: \n");
  for (int j = 0; j < 3; j++) {
    for (int x = 0; x < 2; x++) {
      *ptr2=arreglo2[j][x]*2;
      ptr2++;
      printf("arreglo2[%d][%d]=%d y su direccion de memoria es=%p\n",j,x,arreglo2[j][x],&arreglo2[j][x]);
    }
  }


  return 0;
}
