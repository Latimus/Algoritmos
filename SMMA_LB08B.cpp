//Manuel Alejandro Sahagun Mendoza 349857
//Listas doblemente ligadas
//08 octubre 2017
//SMMA_L08B

//Librerias incluidas
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

//Declaracion de constantes

#define PAUSE getch();
#define MSGE printf("\nPresione cualquier tecla para continuar...");
#define LIMPIA system("cls");

//Tipo dato basico generico
typedef struct _tdatoD{

	long dato;
	char nombre[100];
	int sexo;
	int edad;
	struct _tdatoD *sig;
	struct _tdatoD *ant;

}TdatoD;

typedef TdatoD *TnodoD;

//Prototipos de funciones
void menu(void);
void servicioD(TnodoD temp);
TnodoD GenDatosD(void);
TnodoD AgregarLDC(TnodoD *listaD,TnodoD *nuevo);
TnodoD BuscarLDC(TnodoD *listaD,long valor);
void Imprimir(TnodoD listaD);
TnodoD EliminarLDC(TnodoD *listaD,long valor);
char *randomNames(int x);
int age(void);

//Funcion principal
int main(int argc, char *argv[]) {

	menu();

	return 0;
}

//Funcion de Menu
void menu(void){
	int op;
	long b,e;

	TnodoD listaD = NULL;
	TnodoD nuevo = NULL;
	TnodoD temp = NULL;

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
						nuevo = GenDatosD();
						temp = AgregarLDC(&listaD,&nuevo);
						if(temp)
							{
								printf("\nNo se pudo ingresar el dato,");
								printf("\nel dato esta repetido [%ld]\n",temp->dato);
								free(temp);
							}
					MSGE;
					PAUSE;
				break;

				case 2:
					LIMPIA;
					printf("\nIngrese el numero que desea eliminar: ");
					scanf("%ld",&e);
					temp = EliminarLDC(&listaD,e);
					if(temp)
					{
						printf("\nDato eliminado[%ld]\n",temp->dato);
					}
					else
					{
						printf("\nEl dato no se encuentra en la lista\n");
					}
					MSGE;
					PAUSE;
				break;

				case 3:
					
					LIMPIA;
					printf("\nIngrese el valor que desea buscar: ");
						scanf("%ld",&b);
						temp = BuscarLDC(&listaD,b);
						if(temp)
						{
							printf("\n\nNumero encontrado: [%ld]\n",temp->dato);
						}
						else
						{
							printf("\n\nEl numero no se encuentra en la lista...\n");
							printf("o la lista esta vacia\n");
						}
		 				MSGE;
						PAUSE;

				break;

				case 4:
					
					Imprimir(listaD);

				break;

				case 0: //Liberar memoria

					if(listaD)
					{
						do
						{
							temp = listaD;
							listaD = temp->sig;
							servicioD(temp);
							free(temp);	
							
						}while(temp->dato != listaD->dato);
					}

				break;
			}
	}while(op!=0);
	MSGE;
	PAUSE;
}

//Servicio
void servicioD(TnodoD temp) {

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
//Funcion para generar datos aleatorios
TnodoD GenDatosD(void) {
	
	int x,e;
	long t;
	char nomb[100];
	TnodoD temp = NULL;
	temp = (TnodoD)malloc(sizeof(TdatoD));
	
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

//Agregar nodos
TnodoD AgregarLDC(TnodoD *listaD,TnodoD *nuevo){

	TnodoD temp = NULL, nodo = NULL;
	
	if(!(*listaD))
		{
			*listaD = *nuevo;
			(*listaD)->sig = *listaD;
			(*listaD)->ant = *listaD;

		}
		else
			{
				if((*nuevo)->dato < (*listaD)->dato)
					{
						(*nuevo)->sig = *listaD;
						(*nuevo)->ant = (*listaD)->ant;
						((*listaD)->ant)->sig = *nuevo;
						(*listaD)->ant = *nuevo;
						*listaD = *nuevo;
						
					}
				else if((*nuevo)->dato > ((*listaD)->ant)->dato)
				{
					(*nuevo)->ant = (*listaD)->ant;
					(*nuevo)->sig = *listaD;
					((*listaD)->ant)->sig = *nuevo;
					(*listaD)->ant = *nuevo;
				}
				else
				{
					temp = *listaD;
					while((temp->sig)->dato < (*nuevo)->dato )
					{
						temp = temp->sig;
					}
					if((temp->sig)->dato == (*nuevo)->dato)
						{
							return *nuevo;
						}
						if((temp->sig)->dato != (*nuevo)->dato)
						{
								(*nuevo)->sig = temp->sig;
								(*nuevo)->ant = temp;
								temp->sig = *nuevo;
								(temp->sig)->ant = *nuevo;
						}
						else
						{
							return *nuevo;
						}
				}
			}
	
	 return nodo;
}

//Busca un nodo
TnodoD BuscarLDC(TnodoD *listaD,long valor){
	
	TnodoD temp = NULL,nodo = NULL;
	temp = *listaD;
	if(temp)
		{
		if(valor - temp->dato < (temp->ant)->dato - valor)
		{
			while(temp != *listaD && temp->dato != valor)
			{
				temp = temp->sig;
			}
		}
		else
		{
			while(temp != *listaD && temp->dato != valor)
			{
				temp = temp->ant;
			}
		}
		if(temp->dato == valor)
		{
			return temp;
		}
		else
		{
			return nodo;
		}
	}
	else
	{
		return nodo;
	}

}

//Imrpime la lista
void Imprimir(TnodoD listaD){

		LIMPIA;
		TnodoD temp = NULL;
 		temp = listaD;

		if(temp)
		{
			printf("\n============Datos de la Lista================\n\n");
			do
			{
				servicioD(temp);
				temp = temp->sig;
			}while(temp != listaD);
		}
		else
		{
			printf("\n La lista esta vacia\n");
		}

		MSGE;
		PAUSE;
}

//Elimina un nodo
TnodoD EliminarLDC(TnodoD *listaD,long valor){
	
	TnodoD temp = NULL,nodo = NULL;

	if(*listaD)
	{
		if((*listaD)->dato == valor)
		{
			if((*listaD)->dato == ((*listaD)->ant)->dato)
			{
				nodo = *listaD;
				*listaD = NULL;
				return nodo;
			}
			else 
			{
				nodo = *listaD;
				*listaD = (*listaD)->sig;
				(*listaD)->ant = nodo->ant;
				(nodo->ant)->sig = *listaD;
				nodo->sig = NULL;
				nodo->ant = NULL;
				return nodo;
			}
		}
		else
		{
			temp = *listaD;
			while(temp->sig != ((*listaD)->ant)->sig && ((temp->sig)->dato) < valor)
			{
				temp = temp->sig;
			}
			if((temp->sig)->dato == valor)
			{
				if(valor != ((*listaD)->ant)->dato)//entre 2 nodos
				{
					nodo = temp->sig;
					temp->sig = nodo->sig;
					(nodo->sig)->ant = temp;
					nodo->sig = NULL;
					nodo->ant = NULL;
					return nodo;
				}
				else		/// ultimo nodo
				{
					nodo = (*listaD)->ant;					
					(*listaD)->ant = temp;
					((*listaD)->ant)->sig = *listaD;
					nodo->sig = NULL;
					nodo->ant = NULL;
					return nodo;
				}/////////////////////////////////////////////////////
			}
			else
			{
				return nodo;
			}
		}
	}
	return temp;
}


//Genera nombres aleatorios y les asgina sexo
char *randomNames(int x) {
	int  r = 0;
	 
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



