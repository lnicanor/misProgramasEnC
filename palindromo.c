#include <stdio.h>

int main()
{
    //Definimos los arreglos para la frase inicial y la frase depurada, los arreglos para el abecedario en mayusculas y minusculas
    char frase[100],fraseSE[100],may[26],min[26];

    //Definimos los contadores que usaremos a lo largo del programa
    int i=0,minu=97,mayu=65,t=0,p=0,cont=0,acum=0,ace=0,k=0;

    //Pedimos la frase
    printf("Ingese una frase: \n");
    scanf("%[^\n]",frase);

    //Arreglo para los puntos
    char puntos[]={44,45,46,58,59,34};

    //Arreglo con de la letras con acentos
    char acentos[]={160,181,130,144,161,214,162,224,163,233};

    //Arreglo con las mismas letras del arreglo acentos pero sin acentos
    char sinacentos[]={97,65,101,69,105,73,111,79,117,85};

    //llenamos los arreglo de letras mayusculas y minusculas
    for (int i = 0; i < 26; ++i)
    {
        may[i]=mayu;
        min[i]=minu;
        mayu++;
        minu++;
    }
    i=0;
    //Depuramos la frase
    while (frase[i] !='\0'){

        //Cambiamos mayusculas por minusculas
        for (int r = 0; r < 26; ++r)
        {
            if (frase[i]==may[r] )
            {
                frase[i]=min[r];
            }
        }

        //Quitamos los signos de puntuacion
        for (int l= 0; l < 6; ++l)
        {
            if (frase[i]==puntos[l] )
            {
                frase[i]=' ';
                k++;
            }
        }

        //Cambiamos los acentos
        for (int q= 0; q < 6; ++q)
        {
            if (frase[i]==acentos[q] )
            {
                frase[i]=sinacentos[q];
                ace++;
            }
        }

        //Quitamos los espacios
        if (frase[i] != ' ')
        {
            fraseSE[t]=frase[i];
            t++;
        }

        i++;
    }

    //Checamos si la palabra es un palindromo o no
    p=t-1;
    for (int r = 0; r < t; ++r)
    {
        if (fraseSE[r]==fraseSE[p])
        {
            cont++;
        }
        p--;
    }

    //Mostramos los resultados
    printf("\nEl numero de caracteres sin contar espacios es: %d",t+k);

    printf("\nEl numero de caracteres contando espacios es: %d",i);

    printf("\nEl numero de acentos es: %d",ace);


    if (cont==t)
    {
        printf("\nLa frase es un palindromo");
    } else {
        printf("\nLa palabra no es un palindromo");
    }

    return 0;
}