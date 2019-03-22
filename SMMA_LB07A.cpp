//Manuel Alejandro Sahagun Mendoza 349857
//Listas doblemente ligadas
//29 septiembre 2017
//SMMA_L07

//Librerias incluidas
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//Declaracion de constantes

#define PAUSE getch();
#define MSGE	printf("Presione cualquier tecla para continuar...");
#define LIMPIA system("cls");

//Tipo dato basico generico
typedef struct _tdatoD{
	
	int dato;
	struct _tdatoD *sig;
	struct _tdatoD *ant;	

}TdatoD;

typedef TdatoD *TnodoD;

//Prototipos de funciones
void menu();
void servicioD(TnodoD temp);
TnodoD AgregarD(TnodoD *listaD,TnodoD *nuevo, TnodoD *ultimo);
TnodoD GenDatosD(void);
TnodoD BuscarD(TnodoD *listaD,TnodoD *ultimo, int valor);
void imprimir(TnodoD listaD);
TnodoD EliminarD(TnodoD *listaD, TnodoD *ultimo,int valor);


//Funcion principal
int main(int argc, char *argv[]) {
	
	menu();

	return 0;
}


//Funcion de menu
void menu (){
	int op,b,e;
	
	TnodoD listaD = NULL;
	TnodoD nuevo = NULL;
	TnodoD temp = NULL;
	TnodoD ultimo = NULL;
	
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
					temp = AgregarD(&listaD,&nuevo,&ultimo);
					if(temp)
						{
							printf("\nEl nodo esta repetido. Intente de nuevo...\n");
							free(temp);
						}
						printf("\n\nNumero encontrado: [%d]\n",ultimo->dato);
						printf("\n\nNumero encontrado: [%d]\n",listaD->dato);
					MSGE;
					PAUSE;
					
				break;
				
				case 2:
					
					LIMPIA;
					printf("\nIngrese el numero que desea eliminar: ");
					scanf("%d",&e);
					temp = EliminarD(&listaD,&ultimo,e);
					if(temp)
						{
							printf("\nDato eliminado[%d]\n",temp->dato);
							free(temp);
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
					scanf("%d",&b);
					temp = BuscarD(&listaD,&ultimo,b);
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
					
					imprimir(listaD);

				break;
					
				case 0: //Liberar memoria
					
					while(listaD)
						{
							temp = listaD;
							listaD = temp->sig;
							servicioD(temp);
							free(temp);
						}

				break;
			}

	}while(op!=0);
	MSGE;
	PAUSE;
}

//Funcion para dar servicio al nodo
void servicioD(TnodoD temp) {

	printf("-----------------------------------\n");
	printf("DATO -> [%d]\n",temp->dato);
	printf("-----------------------------------\n");
	
}

//Funcion para generar datos aleatorios
TnodoD GenDatosD(void) {
	
	int x;
	TnodoD temp = NULL;
	temp = (TnodoD)malloc(sizeof(TdatoD));
	
	temp->sig = NULL;
	x =rand()%100;
	//printf("Dame un numero: ");
	//scanf("%d",&x);
	temp->dato = x;
	printf("\n\n[%d] Ingresando Dato...\n\n",x);
	return temp;	
}

//Funcion de agregar
TnodoD AgregarD(TnodoD *listaD,TnodoD *nuevo, TnodoD *ultimo) {
	
	TnodoD temp = NULL, nodo = NULL;
	
	int lis,ult,resL,resU,valor;
	
	if(!(*listaD)) 
		{
			*listaD = *nuevo;
			*ultimo = *nuevo;
			*nuevo = NULL;	
		}
		else
		{
			if((*nuevo)->dato < (*listaD)->dato)
				{
					(*nuevo)->sig = *listaD;
					(*listaD)->ant = *nuevo;
					*listaD = *nuevo;
					*nuevo = NULL;
				}
				else
				{
						temp = *listaD;
						while(temp->sig && (temp->sig)->dato <= (*nuevo)->dato)
								{
									temp = temp->sig;
								}
								if(temp->dato == (*nuevo)->dato)
									{
										return *nuevo;
									}
								if(!(temp->sig))
									{
										(*nuevo)->sig = NULL;
 										(*nuevo)->ant = *ultimo;
										(*ultimo)->sig = *nuevo;
										*ultimo = *nuevo;
										*nuevo = NULL;
									}
									else
									{
										(*nuevo)->ant = temp;
										(*nuevo)->sig = temp->sig;
										temp->ant = *nuevo;
										temp->sig = *nuevo;
										temp = NULL;
									}
				}
		}	
	return nodo;
}

//Funcion de buscar
TnodoD BuscarD(TnodoD *listaD,TnodoD *ultimo, int valor) {
	TnodoD temp = NULL, nodo = NULL;
	int lis,ult,resL,resU;
	
	lis = (*listaD)->dato;
	ult = (*ultimo)->dato;
	resL = valor-lis;
	resU = ult-valor;
	
	//temp = listaD;
	//temp = ultimo;
	if(*listaD)
	{
			if(resL < resU)
				{
					temp = *listaD;
					while(temp->dato <= valor){
						if(temp->dato == valor)
							{
								return temp;	//Regresa el valor
							}
							temp = temp->sig;
					}
				}
				else
				{
					temp = *ultimo;
					while(temp->dato >= valor){
						if(temp->dato == valor)
						{
							return temp;
						}
						temp = temp->ant;
					}

				}
	}
	return nodo; //Regresa un nulo
}

//Imprimir Lista
void imprimir(TnodoD listaD){

		LIMPIA;
		TnodoD temp = NULL;
		temp = listaD;

		if(temp){
				printf("\n============Datos de la Lista================\n\n");
				while(temp != NULL) {
						servicioD(temp);
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

//Elimina un nodo de la lista
TnodoD EliminarD(TnodoD *listaD, TnodoD *ultimo,int valor){

	TnodoD nodo = NULL,temp = NULL;

		if(*listaD)
			{
				if((*listaD)->dato == valor)
					{
						if(!(*listaD)->sig)
							{
								nodo = *listaD;
								*listaD = NULL;
								*ultimo = NULL;
								
							}
							else
							{
								nodo = *listaD;
								*listaD = nodo->sig;
								nodo->sig = NULL;
							}
					}
					else
					{
						temp = *listaD;
						while(temp->sig && (temp->sig)->dato < valor)
							{
								temp = temp->sig;
							}
							
							if((temp->sig) && (temp->sig)->dato == valor)
							{
								nodo = temp->sig; //porque se detiene uno antes
								temp->sig = nodo->sig;
								nodo->sig = NULL;
							}
							else
							{


							}
					}
			}

	return nodo;
}
























