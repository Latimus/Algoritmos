//Manuel Alejandro Sahagun Mendoza 349857
//Listas A
//10 septiembre 2017
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
void servicio(Tnodo temp);
Tnodo agregar(Tnodo *lista, Tnodo *nuevo);
void imprimir(Tnodo lista);
Tnodo buscar(Tnodo lista, int valor);
Tnodo eliminar(Tnodo *lista, int valor);


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
								printf("\n\nNumero encontrado: [%d]\n",temp->dato);
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
Tnodo GenDatos(void) {
	
	int x;
	Tnodo temp = NULL;
	temp = (Tnodo)malloc(sizeof(Tdato));
	
	temp->sig = NULL;
	x =rand()%100;
	temp->dato = x;
	printf("\n\n[%d] DATO agregado...\n\n",x);
	return temp;	
}

void servicio(Tnodo temp) {

	printf("-----------------------------------\n");
	printf("DATO -> [%d]\n",temp->dato);
	printf("-----------------------------------\n");
	
}

Tnodo agregar(Tnodo *lista, Tnodo *nuevo) {
	
	Tnodo temp = NULL;
	
	if(!*lista || (*nuevo)->dato < (*lista)->dato)
		{
			(*nuevo)->sig = *lista;
			*lista = *nuevo;
		}
		else
		{
			temp = *lista;	
			while(temp->sig && (temp->sig)->dato <= (*nuevo)->dato)
				{
						temp = temp->sig; //Avanzar puntero
				}
					
			if(temp->dato != (*nuevo)->dato)
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
					while(temp->dato <= valor) {
						if(temp->dato == valor)
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
		
		if(temp->dato == valor)
			{
				*lista = (*lista)->sig;
				free(temp);
			}
			else
			{
				while((temp->sig)->dato != valor) //Mientras que lista tengo algo
					{
							temp = temp->sig;
					}
					
				aux = temp->sig;
				temp->sig = (temp->sig)->sig;
				free(aux);
			}
			
		return *lista;
}











