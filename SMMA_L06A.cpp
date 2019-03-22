//Manuel Alejandro Sahagun Mendoza 349857
//Listas Circulares A
//24 septiembre 2017
//SMMA_L04A

//Librerias incluidas
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//Declaracion de constantes

#define PAUSE getch();
#define MSGE	printf("Presione cualquier tecla para continuar...");
#define LIMPIA system("cls");

//Tipo dato basico generico
typedef struct _tdato{
	
	int dato;
	struct _tdato *sig;	

}Tdato;

typedef Tdato *Tnodo;

//Prototipos de funciones
void menu();
Tnodo GenDatos(void);
Tnodo agregar(Tnodo *listaC, Tnodo *nuevo, Tnodo *ultimo);
void imprimir(Tnodo lista,Tnodo ultimo);
Tnodo eliminarLC(Tnodo *lista, Tnodo *ultimo, int valor);
Tnodo buscar(Tnodo lista, Tnodo ultimo, int valor);
void servicio(Tnodo temp);

//Funcion principal
int main(int argc, char *argv[]) {
	
	menu();

	return 0;
}

//Funcion de menu
void menu (){
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
					printf("\nIngrese el numero que desea eliminar: ");
					scanf("%d",&m);
					temp = eliminarLC(&listaC,&ultimo,m);
					if(temp)
						{
							printf("\nDato eliminado[%d]\n",temp->dato);
						}
						else
						{
							printf("El dato no se encuentra en la lista");
						}
				
					MSGE;
					PAUSE;
					break;				
			case 3:
					LIMPIA;
					printf("\nIngrese el numero que desea buscar: ");
					scanf("%d",&n);
					temp = buscar(listaC,ultimo,n);
					if(temp)
						{
							printf("\n\nNumero encontrado: [%d]\n",temp->dato);
						}
						else
						{
							printf("\n\nEl numero no se encuentra en la lista...\n");
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

//Funcion para generar datos aleatorios
Tnodo GenDatos(void) {
	
	int x;
	Tnodo temp = NULL;
	temp = (Tnodo)malloc(sizeof(Tdato));
	
	temp->sig = NULL;
	x =rand()%100;
	//printf("Dame un numero: ");
	//scanf("%d",&x);
	temp->dato = x;
	printf("\n\n[%d] DATO agregado...\n\n",x);
	return temp;	
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

//Servicio a la Lista Circular
void servicio(Tnodo temp) {

	printf("-----------------------------------\n");
	printf("DATO -> [%d]\n",temp->dato);
	printf("-----------------------------------\n");
	
}

//Imrpime la lista
void imprimir(Tnodo lista,Tnodo ultimo) {
		
		LIMPIA;
		Tnodo temp = NULL;
		temp = lista;
		
		if(temp){		
				printf("\n============Datos de la Lista================\n\n");
				 do{
						servicio(temp);
						temp = temp->sig;
			 }while(temp != lista);
		}
		else
		{
			printf("\nLa lista esta vacia...\n");	
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





