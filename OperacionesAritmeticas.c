#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//inicializacion de la funcion principal
int main() {
int a,b,c,d,e;
int *ptr1=&a;
int *ptr2=&b;
int *ptr3=&c;
int *ptr4=&d;
for (int x = 6; x < 10; x++) {
   *ptr1=x;
   ptr1--;
}

printf("la direccion de memoria de a es:%d\n",&a );
printf("la direccion de memoria de b es:%d\n",&b );
printf("la direccion de memoria de c es:%d\n",&c );
printf("la direccion de memoria de d es:%d\n",&d );
printf("El valor de a es: %d\n",a );
printf("El valor de b es: %d\n",b );
printf("El valor de c es: %d\n",c );
printf("El valor de d es: %d\n",d );

  return 0;
}
