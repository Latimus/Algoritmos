//Manuel Alejandro Sahagun Mendoza 349857
//Listas Circulares B
//24 septiembre 2017
//SMMA_L04A

//Librerias incluidas
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

//Declaracion de constantes

#define PAUSE getch();
#define MSGE	printf("Presione cualquier tecla para continuar...");
#define LIMPIA system("cls");

//Tipo dato basico generico
typedef struct _tdato{
	
	long dato;
	char nombre[100];
	int sexo;
	int edad;
	struct _tdato *sig;	

}Tdato;

typedef Tdato *Tnodo;

//Prototipos de funciones
void menu();
Tnodo GenDatos(void);
void servicio(Tnodo temp);
Tnodo agregar(Tnodo *listaC, Tnodo *nuevo, Tnodo *ultimo);
void imprimir(Tnodo lista,Tnodo ultimo);
Tnodo buscar(Tnodo lista, Tnodo ultimo, int valor);
Tnodo eliminarLC(Tnodo *lista, Tnodo *ultimo, int valor);
char *randomNames(int x);
int age();

//Funcion principal
int main(int argc, char *argv[]) {
	
	menu();

	return 0;
}

//Funcion de menu
void menu (void){
	int op,m,n;
	
	Tnodo listaC = NULL;
	Tnodo nuevo = NULL;
	Tnodo temp = NULL;
	Tnodo ultimo = NULL;
	
	do
	{
		LIMPIA;
		printf("\n\tM\tE\tN\tU");
		printf("\n1.- Agregar");
		printf("\n2.- Elimina");
		printf("\n3.- Buscar");
		printf("\n4.- Imprimir");
		printf("\n0.- Salir\n");
		scanf("%d",&op);
		switch(op)
			{
			case 1:
				
					LIMPIA;
					nuevo = GenDatos();
					temp = agregar(&listaC,&nuevo,&ultimo);
					MSGE;
					PAUSE;
					break;
					
			case 2:
				
					LIMPIA;
					printf("\nIngrese la matricula que desea eliminar: ");
					scanf("%d",&m);
					temp = eliminarLC(&listaC,&ultimo,m);
					if(temp)
						{
								printf("-----------------------------------\n");
							  printf("Alumno eliminado\n");
								printf("Matricula: \t\t\t[%ld]",temp->dato);
								printf("\nNombre: \t\t\t[%s]",temp->nombre);
								printf("\nEdad: \t\t\t\t[%d]",temp->edad);
								if(temp->sexo == 1)
									{
										printf("\nSexo:\t\t\t\t[Masculino]\n");
									}
									else
									{
										printf("\nSexo:\t\t\t\t[Femenino]\n");
									}
								printf("-----------------------------------\n");
													}
						else
						{
							printf("\n\nEl alumno no esta inscrito al instituto o ha sido ");
							printf("dado de baja...\n");
						}
				
					MSGE;
					PAUSE;
					break;				
			case 3:
					LIMPIA;
					printf("\nIngrese la matricula que desea buscar: ");
					scanf("%d",&n);
					temp = buscar(listaC,ultimo,n);
					if(temp)
						{
								printf("-----------------------------------\n");
							  printf("----------Alumno encontrado--------\n");
								printf("\n\nMatricula: \t\t\t[%ld]",temp->dato);
								printf("\nNombre: \t\t\t[%s]",temp->nombre);
								printf("\nEdad: \t\t\t\t[%d]",temp->edad);
								if(temp->sexo == 1)
									{
										printf("\nSexo:\t\t\t\t[Masculino]\n");
									}
									else
									{
										printf("\nSexo:\t\t\t\t[Femenino]\n");
									}
								printf("-----------------------------------\n");
						}
						else
						{
							printf("\n\nEl alumno no esta inscrito al instituto o ha sido ");
							printf("dado de baja...\n");
						}
						MSGE;
						PAUSE;
				break;
				
			case 4:
				
					imprimir(listaC,ultimo);
					
				break;
				
			case 0: //Liberar memoria
							
					while(listaC != ultimo)
							{
								temp = listaC;
								listaC = temp->sig;
								servicio(temp);
								free(temp);
							}
							if(listaC)
								{
									temp = listaC;
									listaC = NULL;
									ultimo = NULL;
									servicio(temp);
									free(temp);
								}
							break;
			}

	}while(op!=0);
	MSGE;
	PAUSE;
}

//Funciones
Tnodo GenDatos(void) {
	
	int x,e;
	long t;
	char nomb[100];
	Tnodo temp = NULL;
	temp = (Tnodo)malloc(sizeof(Tdato));
	
	temp->sig = NULL;
	t = (25000 + rand()%6000);
	temp->dato = t;
	
	x = (1 + (rand() % 2));	//Variable aleatoria para elegir sexo
	temp->sexo = x;	
	
	strcpy(nomb,randomNames(x));
	strcpy(temp->nombre,nomb);
	
	e = age();
	temp->edad = e;//1 hombre 2 mujer
	
	printf("\n\nALUMNO AGREGADO -> ");
	printf("\n\nMatricula: \t\t\t[%ld]",temp->dato);
	printf("\nNombre: \t\t\t[%s]",temp->nombre);
	printf("\nEdad: \t\t\t\t[%d]",temp->edad);
	if(temp->sexo == 1)
		{
			printf("\nSexo:\t\t\t\t[Masculino]\n");
		}
		else
		{
			printf("\nSexo:\t\t\t\t[Femenino]\n");
		}
	
	return temp;	
}

//Funcion que genera nombres y apellidos aleatorios
char *randomNames(int x) {
	int  r = 0;
	//p = *pos;	//Depositamos el contador en una variable 
	char name[100];
	char nom[20][10] = 	//Nombres Masculinos
		{"MANUEL ","CARLOS ","FERMIN ","FEDE ","LUIS ",
		"JOSE ","ANTONIO ","SANDRO ","MARIO ","LUCIO ","DANIEL ","LORENZO ",
		"PEDRO ","ANGEL ","FABIAN ","GIBRAN ","ELVER ","IGNACIO ","MARTIN ",
		"FENRI "};
	char nomf[20][10] = //Nombres Femeninos
		{"MIRANDA ","SANDRA ","MARIA ","LUCIA ","DIANA ",
		"MARLA ","CHUNLI ","KARLA ","JOSEFA ","ANTONIA ","DANIELA ","LORE ",
		"PETRA ","ANGELA ","PAMELA ","LAURA ","KATIA ","SAMIS ","ANALU ",
		"KAREN "};

	char apep[20][10] = 	//Apellidos
		{ "MENDOZA ","MEJIA ","CHUPI ","ESPARZA ","CARRIL ","MONAREZ ","GARCIA ",
		"CADENA ","PEREZ ","CRUZ ","CHICO ","SANCHEZ ","RAMIREZ ","MONTES ","SANCHEZ ",
		"PEREZ ","CURIEL ","ZERTUS ","GOMEZ ","VARGAS "};
		
	char apem[20][10] = 		//Apellidos
		{ "SAHAGUN","ARGAEZ","PEREZ","HENDO","MOXCA",
		"GONZALO","GUINO","CAROL","GUERRA","MONTES","CHUNLI","PARRA","CARDES",
		"RAMIR","VARGAS","TELLEZ","FOLGI","ODIN","PARKER","HERNANDEZ"};
		
		
		r = (1 + (rand() % 20) - 1);	//Seleccion de nombres aleatorios
		if (x == 1) {	// Si "x" es igual a "1" el nombre sera masculino
			strcpy(name,nom[r]);	//la estructura recibe el nombre

		}
		else {			// Si "x" es igual a "2" el nombre sera femenino
			strcpy(name,nomf[r]);

		}
		
		r = (rand() % 20); //Elegimos un apellido
		strcat(name,apep[r]); 	//El apartado de la estructura 
											//recibe el apellido
		
		r = (rand() % 20);		//Elige un apellido aleatorio
		strcat(name,apem[r]);	//Se deposita el apellido en el 
											//apartado de la estructura
		return name;
}

//Funcion que genera edades aleatorias
int age(void) {
	int x;
	
	x = (18 + rand()% 47);		//Edades aleatorias entre 18 y 65 años
	return x;

}

//Funcion para dar servicio al nodo
void servicio(Tnodo temp) {

	printf("-----------------------------------\n");
	printf("Matricula: \t\t\t[%ld]",temp->dato);
	printf("\nNombre: \t\t\t[%s]",temp->nombre);
	printf("\nEdad: \t\t\t\t[%d]",temp->edad);
	if(temp->sexo == 1)
		{
			printf("\nSexo:\t\t\t\t[Masculino]\n");
		}
		else
		{
			printf("\nSexo:\t\t\t\t[Femenino]\n");
		};
	printf("-----------------------------------\n");
	
}

//Agregar dato a la lista Circular
Tnodo agregar(Tnodo *lista, Tnodo *nuevo, Tnodo *ultimo) {
	
	Tnodo temp = NULL;
	Tnodo nodo = NULL;
	
	if(!*lista)
		{
			*lista = *nuevo;
			*ultimo = *nuevo;
			(*ultimo)->sig = *lista;
			*nuevo = NULL;
		}
		else
		{
			if((*nuevo)->dato < (*lista)->dato)
				{
					(*nuevo)->sig = *lista;
					*lista = *nuevo;
					(*ultimo)->sig = *lista;
				}
				else
				{
					if((*nuevo)->dato > (*ultimo)->dato)
						{
							(*nuevo)->sig = *lista;
							(*ultimo)->sig = *nuevo;
							*ultimo = *nuevo;
						}
						else
						{
							temp = *lista;
							while((temp->sig)->dato < (*nuevo)->dato){
								temp = temp->sig;
							}
							if((temp->sig)->dato != (*nuevo)->dato)//*************
								{
									(*nuevo)->sig = temp->sig;
									temp->sig = *nuevo;
									*nuevo = NULL;
								}
								else
								{
									return *nuevo; //NULL
								}	
						}		
				}
		}
	return nodo;
}

//Imrpime la lista
void imprimir(Tnodo lista,Tnodo ultimo) {
		
		LIMPIA;
		Tnodo temp = NULL;
		temp = lista;
		
		if(temp){		
				printf("\n============Alimnos Registrados================\n\n");
				 do{
						servicio(temp);
						temp = temp->sig;
			 }while(temp != lista);
		}
		else
		{
			printf("\nNo hay alumnos registrados...\n");	
		}
		MSGE;
		PAUSE;
}

//Elimina nodo
Tnodo eliminarLC(Tnodo *lista, Tnodo *ultimo, int valor) {
		Tnodo temp = NULL;
		Tnodo nodo = NULL;	
		
		if(*lista)
			{
				if((*lista)->dato == valor)
					{
						if(*lista == *ultimo)
							{
								nodo = *lista;
								*lista = NULL;
								*ultimo = NULL;
								nodo->sig = NULL;
							}
							else
							{
								nodo = *lista;
								*lista = (*lista)->sig;
								(*ultimo)->sig = *lista;
								nodo->sig = NULL;
							}

					}
					else
					{
						temp = *lista;
						while(temp->sig != (*ultimo)->sig && (temp->sig)->dato < valor)
							{
								temp = temp->sig;
							}
							if(temp->sig && (temp->sig)->dato == valor)
							{
								if(valor != (*ultimo)->dato)
									{
										nodo = temp->sig;
										temp->sig = nodo->sig;
										nodo->sig = NULL;
										return nodo;
									}
									else
									{
										nodo = *ultimo;
										*ultimo = temp;
										(*ultimo)->sig = *lista;
										nodo->sig = NULL;
										return nodo;
									}
							}
							else
							{
								return nodo;
							}
					}
			}
			return nodo;
}

//Buscar
Tnodo buscar(Tnodo lista, Tnodo ultimo, int valor) {
		Tnodo temp = NULL;
		Tnodo nodo = NULL;
		temp = lista;
		
		if(lista) //Si lista tiene algo
			{	
				do{
					if(temp->dato == valor)
						{
							return temp;	
						}
						temp = temp->sig;
					}while(lista != temp);
			}
	//si no lo encuentra regresa un NULL
	return nodo;
}


















