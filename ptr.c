
#include <stdio.h>

int main() {
  int a=5669, *puntero=&a;
  a=0;
  //modificar el contenido de la variable a mediante punteros
  *puntero=1000;
//  puntero=1000; warning
//  &puntero=1000; error
  printf("El contenido es: %d\n",a );
  printf("El contenido es: %d\n",&a );
  printf("El contenido es: %d\n",puntero );
  printf("El contenido es: %d\n",&puntero );
  printf("El contenido es: %d\n",*puntero );

  return 0;
}
