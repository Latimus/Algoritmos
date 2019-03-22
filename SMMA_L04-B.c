//Manuel Alejandro Sahagun Mendoza 349857
//Listas B
//10 septiembre 2017
//SMMA_L04B

//Librerias incluidas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

//Declaracion de constantes

#define PAUSE getch();
#define MSGE	printf("Presione cualquier tecla para continuar...");
#define LIMPIA system("cls");

//Tipo dato basico generico
typedef struct _tdato{
	
	int numt;
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
Tnodo agregar(Tnodo *lista, Tnodo *nuevo);
void imprimir(Tnodo lista);
Tnodo buscar(Tnodo lista, int valor);
Tnodo eliminar(Tnodo *lista, int valor);
char *randomNames();
int age();


//Funcion principal
int main(int argc, char *argv[]) {
	
	menu();

	return 0;
}

//Funcion de menu
void menu (){
	int op,n,m;
	
	Tnodo lista = NULL;
	Tnodo nuevo = NULL;
	Tnodo temp = NULL;
	
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
					temp = agregar(&lista,&nuevo);
					MSGE;
					PAUSE;
					
					break;
				
			case 2:
					LIMPIA;
					printf("\nIngrese el numero que desea eliminar: ");
					scanf("%d",&m);
					eliminar(&lista,m);
					printf("\nDato eliminado\n");
				
					MSGE;
					PAUSE;
					break;
			
			case 3:
						LIMPIA;
						printf("\nIngrese el numero que desea buscar: ");
						scanf("%d",&n);
						temp = buscar(lista,n);
						if(temp)
							{
								printf("\n\nALUMNO ENCONTRADO -> ");
								printf("\n\nMatricula: \t\t\t[%d]",temp->numt);
								printf("\nNombre: \t\t\t[%s]",temp->nombre);
								printf("\nEdad: \t\t\t\t[%d]",temp->edad);
								printf("\nSexo(1.-Hombre\t2.-Mujer): \t[%d]\n\n",temp->sexo);
								PAUSE;
														}
							else
								{
									printf("\n\nNumero no econtrado...\n");
								}
						MSGE;
						PAUSE;
					break;
					
			case 4:
					
						imprimir(lista);
					break;
			 			
					
			case 0: 
					while(lista)
							{
								temp = lista;
								lista = temp->sig;
								servicio(temp);
								free(temp);
							}
							break;
			}

	}while(op!=0);
	printf("\nMemoria Liberada...\n");
	MSGE;
	PAUSE;
}

//Funciones
Tnodo GenDatos() {
	
	int x,t,e;
	char nomb[100];
	Tnodo temp = NULL;
	temp = (Tnodo)malloc(sizeof(Tdato));
	
	temp->sig = NULL;
	t = rand()%500+1;
	temp->numt = t;
	
	x = (1 + (rand() % 2));	//Variable aleatoria para elegir sexo
	temp->sexo = x;	
	
	strcpy(nomb,randomNames(x));
	strcpy(temp->nombre,nomb);
	
	e = age();
	temp->edad = e;
	
	printf("\n\nALUMNO AGREGADO -> ");
	printf("\n\nMatricula: \t\t\t[%d]",temp->numt);
	printf("\nNombre: \t\t\t[%s]",temp->nombre);
	printf("\nEdad: \t\t\t\t[%d]",temp->edad);
	printf("\nSexo(1.-Hombre\t2.-Mujer): \t[%d]\n\n",temp->sexo);
	PAUSE;
	return temp;	
}

void servicio(Tnodo temp) {

	printf("-----------------------------------\n");
	printf("\n\nALUMNO AGREGADO -> ");
	printf("\n\nMatricula: \t\t\t[%d]",temp->numt);
	printf("\nNombre: \t\t\t[%s]",temp->nombre);
	printf("\nEdad: \t\t\t\t[%d]",temp->edad);
	printf("\nSexo(1.-Hombre\t2.-Mujer): \t[%d]\n\n",temp->sexo);
	printf("-----------------------------------\n");
	
}

Tnodo agregar(Tnodo *lista, Tnodo *nuevo) {
	
	Tnodo temp = NULL;
	
	if(!*lista || (*nuevo)->numt < (*lista)->numt)
		{
			(*nuevo)->sig = *lista;
			*lista = *nuevo;
		}
		else
		{
			temp = *lista;	
			while(temp->sig && (temp->sig)->numt <= (*nuevo)->numt)
				{
						temp = temp->sig; //Avanzar puntero
				}
					
			if(temp->numt != (*nuevo)->numt)
				{
					(*nuevo)->sig = temp->sig;
					temp->sig = *nuevo;
					temp = NULL;
					return temp; //Regresa un nulo
				}
			return *nuevo;
		}
}

void imprimir(Tnodo lista) {
		
		LIMPIA;
		Tnodo temp = NULL;
		temp = lista;
		
		if(temp){		
				printf("\n============Datos de la Lista================\n\n");
				while(temp != NULL) {
						servicio(temp);
						temp = temp->sig;
				}
		}
		else
		{
			printf("\nLa lista esta vacia...\n");	
		}
		MSGE;
		PAUSE;
}

Tnodo buscar(Tnodo lista, int valor) {
		Tnodo temp = NULL, nodo = NULL;
		temp = lista;
	
		if(lista)
			{
					while(temp->numt <= valor) {
						if(temp->numt == valor)
							{
								return temp;	//Regresa el valor
							}
							temp = temp->sig;
					}
			}
			
		
		return nodo; //Regresa un nulo
}

Tnodo eliminar(Tnodo *lista, int valor) {
		Tnodo temp = *lista;
		Tnodo aux = NULL;	
		
		if(temp->numt == valor)
			{
				*lista = (*lista)->sig;
				free(temp);
			}
			else
			{
				while((temp->sig)->numt != valor) //Mientras que lista tengo algo
					{
							temp = temp->sig;
					}
					
				aux = temp->sig;
				temp->sig = (temp->sig)->sig;
				free(aux);
			}
			
		return *lista;
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
int age() {
	int x;
	
	x = (18 + rand()% 47);		//Edades aleatorias entre 18 y 65 años
	return x;

}






