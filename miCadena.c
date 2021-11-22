#include <stdio.h>

//Modelado funcion contarVocales
void contarVocales(char vocalMin,char vocalMay,char vocalAMin,char vocalAMay,char frase[],int *contV);

int main()
{
	//arreglo donde almacenaremos la frase
	char frase[200];

	//arreglo en donde almacenaremos las letras con acento
	char acentos[]={160,181,130,144,161,214,162,224,163,233};
      
    //arreglo donde almacenaremos las vocales 
	char vocales[]={97,65,101,69,105,71,111,79,117,85};

	//Definimos las variables de tipo int
	int contV=0,acum=0,contMay=0,contA=0,contP=1,contC=0,contE=0;

	//Creamos un arreglo de tipo char que almacenara todas las letras mayusculas
	char mayusculas[25];
	for (int i = 65; i < 91; ++i)
	{
		mayusculas[acum]=(char)i;
		acum=acum+1;
	}
	acum=0;

	//Pedimos la frase
	printf("\nIngrese la frase: ");
	scanf("%[^'\n']s", frase);
    
    //Definimos el rango de la frase
	if (frase[0] == '\0')
	{
		printf("Frase vacia");
	} else {
		while(frase[acum] != '\0'){
			//Mostramos la frase
			printf("%c",frase[acum]);
			
			//Ciclo for para contar las mayusculas de la frase
			for (int i = 0; i < 25; ++i)
			{
				if (frase[acum]==mayusculas[i])
				{
					contMay=contMay+1;
				}
			}

			if (frase[acum]==acentos[1] || frase[acum]==acentos[3] || frase[acum]==acentos[5] || frase[acum]==acentos[7] || frase[acum]==acentos[9])
			{
				contMay=contMay+1;
			}
		

			//Ciclo for para contar las vocales de la frase
			for (int i = 0; i < 10; ++i)
			{
				if (frase[acum]==acentos[i])
				{
					contA=contA+1;
				}
			}

			//Contamos el numero de palabras dentro de la frase
			if(frase[acum] == ' ' && frase[acum - 1] != ' '){
				contP=contP+1;
			}
		
			//Contamos los caracteres de toda la frase y los espacios dentro de la misma 
			contC=contC+1;
			if (frase[acum] == ' ')
			{
				contE=contE+1;
			}

				acum=acum+1;	
		}

		//Hacemos uso de la funcion contarVocales y mostramos el valor en pantalla
		contarVocales(vocales[0],vocales[1],acentos[0],acentos[1],frase,&contV);
		printf("\nEl numeros de vocales a es: %d",contV);
		contV=0;
		contarVocales(vocales[2],vocales[3],acentos[2],acentos[3],frase,&contV);
		printf("\nEl numeros de vocales e es: %d",contV);
		contV=0;
		contarVocales(vocales[4],vocales[5],acentos[4],acentos[5],frase,&contV);
		printf("\nEl numeros de vocales i es: %d",contV);
		contV=0;
		contarVocales(vocales[6],vocales[7],acentos[6],acentos[7],frase,&contV);
		printf("\nEl numeros de vocales o es: %d",contV);
		contV=0;
		contarVocales(vocales[8],vocales[9],acentos[8],acentos[9],frase,&contV);
		printf("\nEl numeros de vocales u es: %d",contV);
		
		//Mostramos el numero de mayusculas de la frase
		printf("\nEl numero de mayusculas en la frase es: %d",contMay);

		//Mostramos el numero de acentos de la frase
		printf("\nEl numero de acentos en la frase es: %d",contA);
		
		//Mostramos el numero de palabras de la frase
		printf("\nEl numero de palabras en la frase es: %d",contP);

		//Imprimimos el numero de caracteres sin contar los espacios
		printf("\nEl numero de caracteres sin contar los espacios es %d",contC-contE);

	}

	return 0;
}

void contarVocales(char vocalMin,char vocalMay,char vocalAMin,char vocalAMay,char frase[],int *contV){
	int cont=0;
	while(frase[cont] != '\0'){
		if (frase[cont]==vocalMin || frase[cont]==vocalMay || frase[cont]==vocalAMin || frase[cont]==vocalAMay)
		{
			*contV=*contV+1;
		}
		cont=cont+1;	
	}
}

