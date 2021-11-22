/*
Manejo de hasta 100 contactos por medio de una estructura con los siguientes elementos:
Id, nombre, aPaterno, aMaterno, domicilio, RFC, numMovil, numFijo, email, fb y tw.
Desarrollar las siguientes funciones:
• Nuevo contacto. <------------ECHO-------------->
• Buscar contacto por nombre.
• Modificar contacto.
• Eliminar contacto.
 */
#include <stdio.h>

//estructura contactos
struct contacto {
	int id;
	char nombre[25];
	char aPaterno[25];
	char aMaterno[25];
	char domicilio[200];
	char rfc[18];
	char numMovil[25];
	char numFijo[25];
	char email[100];
	char fb[60];
	char tw[60];
	};

//Definimos el maximo de contactos
struct contacto personas[100];

//Definimos una variable global para entrar a 
struct contacto *persona;

struct contacto *p_recorrido;

//Modelado de la funcion nuevoContacto
void nuevoContacto(int id);

//Modelado de la funcion buscarContacto
void buscarContacto(int id,char nombre[],int *res);

//Modelado de la funcion eliminar
void elminarContacto(int *res, int id);


int main(){
	//ID
	int id=0;
	//MENU
	int opc;
	//Variable temporal para buscar el nombre
	char n[25];
	//Variable para saber si el nombre fue encontrado
	int res;


	do
	{	
		printf("\n\nIngrese la opcion a realizar\n");
		printf("1:Agregar un nuevo contacto\n");
		printf("2:Buscar contacto por nombre\n");
		printf("3:Modificar contacto\n");
		printf("4:Eliminar contacto\n");
		printf("5:Salir del programa\n");
		scanf("%d",&opc);

			switch (opc)
			{
			//Agregamos nuevo contacto
		    case 1:
			    //Llamamos a la funcion nuevo contacto y le mandamos el id
			    nuevoContacto(id);
			    id++; 
			    fflush(stdin);
			break;

			//Buscamos contacto
			case 2:
				fflush(stdin);
				printf("Ingrese el nombre:");
			    scanf("%[^'\n']s", n);
			    fflush(stdin);
			    printf("Los datos del contacto son:\n");
			    buscarContacto(id,n,&res);
			    if (res==404)
			    {
			    	printf("El contacto no existe\n");
			    }
			break;

			case 3:
				fflush(stdin);
				printf("Ingrese el nombre:");
			    scanf("%[^'\n']s", n);
			    fflush(stdin);
			    printf("Los datos del contacto son:\n");
			    buscarContacto(id,n,&res);
			    if (res==404)
			    {
			    	printf("El contacto no existe\n");
			    }
			    if (res!=404)
			    {
			    	printf("\n\nIngrese los nuevos datos para el contacto\n\n\n");
			    	nuevoContacto(res);
			    	printf("Contacto Moficado\n\n");
			    }
			break;

			case 4:
				fflush(stdin);
				printf("Ingrese el nombre:");
			    scanf("%[^'\n']s", n);
			    fflush(stdin);
			    printf("Datos del contacto a Eliminar:\n");
			    buscarContacto(id,n,&res);
			    elminarContacto(&res,id);
			    id--;
			break;
			//Salir del programa
			case 5:
		    	printf("ADIOS\n");
			break;


		    default:
		    printf("Opcion no encontrada\n");
			}
	} while (opc!=5);	
	return 0;
}

void nuevoContacto(int id){
    persona = &personas[id];
    persona->id=id+1;
    fflush(stdin);
    printf("Nombre:");
    scanf("%[^'\n']s", persona->nombre);
    fflush(stdin);
    printf("Apellido Paterno:");
    scanf("%[^'\n']s", persona->aPaterno);
    fflush(stdin);
    printf("Apellido Materno:");
    scanf("%[^'\n']s", persona->aMaterno);
    fflush(stdin);
    printf("Domicilio:");
    scanf("%[^'\n']s", persona->domicilio);
    fflush(stdin);
    printf("RFC:");
    scanf("%[^'\n']s", persona->rfc);
    fflush(stdin);
    printf("Numero Movil:");
    scanf("%[^'\n']s", persona->numMovil);
    fflush(stdin);
    printf("Numero Fijo:");
    scanf("%[^'\n']s", persona->numFijo);
    fflush(stdin);
    printf("Email:");
    scanf("%[^'\n']s", persona->email);
    fflush(stdin);
    printf("Facebook:");
    scanf("%[^'\n']s", persona->fb);
    fflush(stdin);
    printf("Twitter:");
    scanf("%[^'\n']s", persona->tw);
    fflush(stdin);
    printf("Contacto Guardado\n\n");
};

void buscarContacto(int id,char n[],int *res){
	//Definimos un acumulador para navegar entre los nombres de la estructura
	int t=0;
	/*Definimos dos variables acumludaoras para verificar que ambos arreglos , el de la estructura y el de la busqueda sean
	  iguales
	*/
	int i=0,j=0;
	//Definmos una variable para saber si ambas frases son exactamente iguales
	int c=0;

	//Creamos un ciclo do while que se repetira el numero de personass registradas en la estructura
	do
	{
		//Aniddamos dos ciclos while para evaluar si ambas frases son iguales
		while(n[j]!='\0'){
			persona=&personas[t];
			while(persona->nombre[i]!='\0'){
				if (n[j]==persona->nombre[i])
				{
					c++;
				}
				i++;
				j++;
			}
			i=0;
		}

		//Si ambas frases son iguales mostramos en pantalla el contacto, sino escribimos que el contacto no existe 
		if (j==c)
		{
			persona=&personas[t];
			printf("ID:%d\n",persona->id);
			printf("Nombre:%s %s %s\n",persona->nombre,persona->aPaterno,persona->aMaterno);
			printf("Domicilio:%s\n",persona->domicilio);
			printf("RFC:%s\n",persona->rfc);
			printf("Numero Movil:%s\n",persona->numMovil);
			printf("Numero Fijo:%s\n",persona->numFijo);
			printf("Email:%s\n",persona->email);
			printf("Facebook:%s\n",persona->fb);
			printf("Twitter:%s\n",persona->tw);
			*res=t;
			t=id-1;
		} else{ 
			*res=404;
		}
		j=0;
		c=0;
		t++;
	} while (t!=id);	
};

void elminarContacto(int *res,int id){
	
		for (int j = *res; j < id; ++j)
		{
			//Obtenemos la direccion de memoria del dato que vamos a eliminar
			persona=&personas[j]; 
			//Obtenemos la direccion de memoroa del dato que vamos a recorrorer a la posicion del dato eliminado
			p_recorrido=&personas[j+1];
			//Vaciamos todos los datos del contacto a eliminar
			persona->nombre[0]='\0';
			persona->aPaterno[0]='\0';
			persona->aMaterno[0]='\0';
			persona->domicilio[0]='\0';
			persona->rfc[0]='\0';
			persona->numMovil[0]='\0';
			persona->numFijo[0]='\0';
			persona->email[0]='\0';
			persona->fb[0]='\0';
			persona->tw[0]='\0';

			//Le pasamos el nombre a recorrer
			int i=0;
			while(p_recorrido->nombre[i]!='\0'){
				persona->nombre[i]=p_recorrido->nombre[i];
				i++;
			}
			persona->nombre[i]='\0';
			//Le pasamos el apellido paterno a recorrer
			i=0;
			while(p_recorrido->aPaterno[i]!='\0'){
				persona->aPaterno[i]=p_recorrido->aPaterno[i];
				i++;
			}
			persona->aPaterno[i]='\0';
			//Le pasamos el apellido materno a recorrer
			i=0;
			while(p_recorrido->aMaterno[i]!='\0'){
				persona->aMaterno[i]=p_recorrido->aMaterno[i];
				i++;
			}
			persona->domicilio[i]='\0';
			//Le pasamos el domicilio a recorrer
			i=0;
			while(p_recorrido->domicilio[i]!='\0'){
				persona->domicilio[i]=p_recorrido->domicilio[i];
				i++;
			}
			persona->domicilio[i]='\0';
			//Le pasamos el rfc a recorrer
			i=0;
			while(p_recorrido->rfc[i]!='\0'){
				persona->rfc[i]=p_recorrido->rfc[i];
				i++;
			}
			persona->rfc[i]='\0';
			//Le pasamos el numero movil a recorrer
			i=0;
			while(p_recorrido->numMovil[i]!='\0'){
				persona->numMovil[i]=p_recorrido->numMovil[i];
				i++;
			}
			persona->numMovil[i]='\0';
			//Le pasamos el numero fijo a recorrer
			i=0;
			while(p_recorrido->numFijo[i]!='\0'){
				persona->numFijo[i]=p_recorrido->numFijo[i];
				i++;
			}
			persona->numFijo[i]='\0';
			//Le pasamos el email a recorrer
			i=0;
			while(p_recorrido->email[i]!='\0'){
				persona->email[i]=p_recorrido->email[i];
				i++;
			}
			persona->email[i]='\0';
			//Le pasamos el facebook a recorrer
			i=0;
			while(p_recorrido->fb[i]!='\0'){
				persona->fb[i]=p_recorrido->fb[i];
				i++;
			}
			persona->fb[i]='\0';
			//Le pasamos el twitter a recorrer
			i=0;
			while(p_recorrido->tw[i]!='\0'){
				persona->tw[i]=p_recorrido->tw[i];
				i++;
			}
			persona->tw[i]='\0';
			}
	printf("\n\nContacto Eliminado\n\n");
};
