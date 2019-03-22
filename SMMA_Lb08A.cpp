//Manuel Alejandro Sahagun Mendoza 349857
//Listas doblemente ligadas
//29 septiembre 2017
//SMMA_L07

//Librerias incluidas
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//Declaracion de constantes

#define PAUSE _getch();
#define MSGE printf("Presione cualquier tecla para continuar...");
#define LIMPIA system("cls");

//Tipo dato basico generico
typedef struct _tdatoD{

	int dato;
	struct _tdatoD *sig;
	struct _tdatoD *ant;

}TdatoD;

typedef TdatoD *TnodoD;

//Prototipos de funciones
void menu(void);
void servicioD(TnodoD temp);
TnodoD GenDatosD(void);
TnodoD AgregarLDC(TnodoD *listaD,TnodoD *nuevo);
TnodoD BuscarLDC(TnodoD *listaD,int valor);
void Imprimir(TnodoD listaD);
TnodoD EliminarLDC(TnodoD *listaD,int valor);

//Funcion principal
int main(int argc, char *argv[]) {

	menu();

	return 0;
}

//Funcion de Menu
void menu(void){
	int op,b,e;

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
								printf("\nel dato esta repetido [%d]\n",temp->dato);
								free(temp);
							}
					MSGE;
					PAUSE;
				break;

				case 2:
					LIMPIA;
					printf("\nIngrese el numero que desea eliminar: ");
					scanf("%d",&e);
					temp = EliminarLDC(&listaD,e);
					if(temp)
					{
						printf("\nDato eliminado[%d]\n",temp->dato);
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
						scanf("%d",&b);
						temp = BuscarLDC(&listaD,b);
						if(temp)
						{
							printf("\n\nNumero encontrado: [%d]\n",temp->dato);
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
void servicioD(TnodoD temp)
{
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
TnodoD BuscarLDC(TnodoD *listaD,int valor){
	
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
TnodoD EliminarLDC(TnodoD *listaD,int valor){
	
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