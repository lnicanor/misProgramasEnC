#include <stdio.h>
#include <math.h>
#include <errno.h>
#include <stdlib.h>
#define PI 3.141592654

//Modelado de la funcion calcularModulo
float calcularModulo(float mx,float my);

//Modelado de la funcion calcularAngulo
float calcularAngulo(float px,float py);

//Modelado de la funcion calcularDistancia
float calcularDistancia(float x1,float y1,float x2,float y2);

//Modelado de la funcion calcularPendiente
float calcularPendiente(float x1,float y1,float x2,float y2,float *px,float *py);

//Modelado de la funcion calcularEcuacionDeLaRecta
float calcularEcuacionDeLaRecta(float x1,float y1,float x2,float y2);

//Modelado de la funcion sumaAB
float sumaAB(float x1,float y1,float x2,float y2,float *x, float *y);

//Modelado de la funcion restaAB
float restaAB(float x1,float y1,float x2,float y2,float *x, float *y);

//Modelado de la multiplicacionde AB
float productoAB(float angA,float angB,float m1,float m2,float *pm,float *pang);

//Modelado de la division de A/B
float divisionAB(float angA,float angB,float m1,float m2,float *pm,float *pang);

int main()
{
    // Variables ingresadas
    float  x1, x2, y1, y2,angA,angB,m1,m2;

    // Punteros
    float px,py,p,x,y,pm,pang;

	//ingreso de datos por el usuario
    printf ("Ingresa el valor de x1: ");
    scanf ("%f", &x1);
    printf ("Ingresa el valor de y1: ");
    scanf ("%f", &y1);
    printf ("Ingresa el valor de x2: ");
    scanf ("%f", &x2);
    printf ("Ingresa el valor de y2: ");
    scanf ("%f", &y2);
    system("cls");
	
    //Coordenadas modulo y angulo del punto A
    angA=calcularAngulo(x1,y1);
    m1=calcularModulo(x1,y1);
	printf("Las coordenadas del punto A son (%.2f,%.2f), su modulo es %.2f, con un angulo de: %.2f\n",x1,y1,m1,angA);
    
    //Coordenadas modulo y angulo del punto B
    angB=calcularAngulo(x2,y2);
    m2=calcularModulo(x2,y2);
    printf("Las coordenadas del punto B son (%.2f,%.2f), su modulo es %.2f, con un angulo de: %.2f\n",x2,y2,m2,angB);
    
    //Distancia del punto A al B
    printf("La distancia del punto A al B es: %.2f\n",calcularDistancia(x1,y1,x2,y2));
    
    //Pendiente con respecto al punto A y B
    printf("La pendiente con respecto al punto A y B es: %.2f\n",calcularPendiente(x1,y1,x2,y2,&px,&py));
    
    //Ecuacion de la recta con respecto a los puntos A y B
    if (calcularPendiente(x1,y1,x2,y2,&px,&py)==0)
    {
        printf("La ecuacion de la recta con respecto a A y B es  x=%.2f\n",x1);
    }

    if (calcularPendiente(x1,y1,x2,y2,&px,&py)==1)
    {
        printf("La ecuacion de la recta con respecto a A y B es  y=%.2f\n",y1);
    }

    if (calcularPendiente(x1,y1,x2,y2,&px,&py)!=1 || calcularPendiente(x1,y1,x2,y2,&px,&py)!=1 )
    {
        if (calcularEcuacionDeLaRecta(x1,y1,x2,y2)>0)
        {
            printf("La ecuacion de la recta con respecto a los puntos A y B es y=%.2fx + %.2f\n",calcularPendiente(x1,y1,x2,y2,&px,&py),calcularEcuacionDeLaRecta(x1,y1,x2,y2));
        } else {
            printf("La ecuacion de la recta con respecto a los puntos A y B es y=%.2fx  %.2f\n",calcularPendiente(x1,y1,x2,y2,&px,&py),calcularEcuacionDeLaRecta(x1,y1,x2,y2));
        }
    }

    //Suma de A+B
    sumaAB(x1,y1,x2,y2,&x,&y);
    printf("La suma de A + B =%.2f + %.2fi\n",x,y);
    
    //Resta de A-B
    restaAB(x1,y1,x2,y2,&x,&y);
    printf("La resta de A - B =%.2f  %.2fi\n",x,y);

    //Producto AB
    productoAB(angA,angB,m1,m2,&pm,&pang);
    printf("El producto de AB en coordenadas polares =%.2f ,%.2f grados\n",pm,pang);

    //Division AB
    divisionAB(angA,angB,m1,m2,&pm,&pang);
    printf("La divisionAB de A/B en coordenadas polares =%.2f ,%.2f grados\n",pm,pang);

    return 0;
}

//Funcion calcularModulo
float calcularModulo (float mx,float my){
    float modulo = sqrt(pow(mx,2)+pow(my,2));
    return modulo;
}

//Funcion calcularAngulo
float calcularAngulo(float px,float py){
    float angulo=atan(py/px)*180/PI;
    return angulo;
}

//Funcion calcularDistancia
float calcularDistancia(float x1,float y1,float x2,float y2){
    float  distancia=sqrt(pow((x2-x1),2)+pow((y2-y1),2));
    return distancia;
}

//Funcion calcularPendiente
float calcularPendiente(float x1,float y1,float x2,float y2,float *px,float *py){
    *py=y2-y1;
    *px=x2-x1;

    float pendiente=(*py / *px);

    //Condicional ecuacion de la recta x=x1 
    if (*px==0)
    {
        pendiente=0;
    }
    //Condicional ecuacion de la recta y=y1
    if (*py==0)
    {
        pendiente=1;
    }
    return pendiente;
}

//Funcion calcularEcuacionDeLaRecta 
float calcularEcuacionDeLaRecta(float x1,float y1,float x2,float y2){
   float m=((y2-y1)/(x2-x1));
   float ECRI;
    ECRI = (m*(x1*-1))+y1;
   
   return ECRI;
}

//Funcion sumaAB
float sumaAB(float x1,float y1,float x2,float y2,float *x, float *y){
    *x=x1+x2;
    *y=y1+y2;
    return 0;
}

//Funcion restaAB
float restaAB(float x1,float y1,float x2,float y2,float *x, float *y){
    *x=x1-x2;
    *y=y1-y2;
    return 0;
}

//Funcion productoAB
float productoAB(float angA,float angB,float m1,float m2,float *pm,float *pang){
   *pm=m1*m2;
   *pang=angA+angB;
   return 0;
}

//Funcion divisionAB
float divisionAB(float angA,float angB,float m1,float m2,float *pm,float *pang){
   *pm=m1/m2;
   *pang=angA-angB;
   return 0;
}





