#include <stdio.h>

int main() {
  int i1,i2,*ptrI=&i1;
  scanf("%d",&i1 );
  float f1,f2,*ptrF;
  char c1,*ptrC;
  void *ptrFlexible;
  ptrI=&i1;
  //ptrC=&i2;//error de incompatibilidad de tipos
  ptrFlexible=&c1;//utilizando un puntero flexible
  printf("contenido es: %d\n",i1);
  printf("contenido es: %d\n",*ptrI );
  printf("contenido es: %d\n",&ptrI );

  return 0;
}
