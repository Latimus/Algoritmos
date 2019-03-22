//librerias que seran utilizadas
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

//Declaracion de constantes
#define PAUSE	getch();
#define MSGE	printf("Presione cualquier tecla para continuar...");
#define LIMPIA	system("cls");
//Tipo dato basico generico
typedef struct _tdato{ //estructura que sera usada en pilas, colas, listas
						//y listas circulares
	int dato;
	struct _tdato *sig;	

}Tdato;

typedef Tdato *Tnodo; //Dato generico

typedef struct _tdat{
	int dat;
	struct _tdat *nex;
	struct _tdat *ant;
}Tdat;

typedef Tdat *TnodoD; //Dato generico para listas dobles y dobles circulares

Tnodo GenDatos();
TnodoD GenDatosD();
void servicio(Tnodo temp);
void servicioD(TnodoD tempD);

void PUSH_pila(Tnodo *pila, Tnodo *nuevo);
Tnodo POP_pila(Tnodo *pila);

void PUSH_cola(Tnodo *cabeza,Tnodo *ultimo,Tnodo *nuevo);
Tnodo POP_cola(Tnodo *cabeza,Tnodo *ultimo);

Tnodo AgregarL(Tnodo *lista,Tnodo *nuevo);
Tnodo EliminarL(Tnodo *lista, int valor);
void ImprimirL(Tnodo lista);

Tnodo AgregarLC(Tnodo *lista, Tnodo *nuevo, Tnodo *ultimo);
Tnodo EliminarLC(Tnodo *lista, Tnodo *ultimo, int valor);
void ImprimirLC(Tnodo lista,Tnodo ultimo);

TnodoD AgregarLD(TnodoD *lista,TnodoD *nuevo, TnodoD *ultimo);
TnodoD EliminarLD(TnodoD *listaD, TnodoD *ultimo,int valor);
void ImprimirLD(TnodoD listaD);

TnodoD AgregarLDC(TnodoD *listaD,TnodoD *nuevo);
TnodoD EliminarLDC(TnodoD *listaD,int valor);
void ImprimirLDC(TnodoD listaD);


Tnodo GenDatos(){
		
	Tnodo temp = NULL;
	temp = (Tnodo)malloc(sizeof(Tdato));
	printf("\n\nEspacio de memoria reservado...\n\n");
	return temp;
}
TnodoD GenDatosD(){
		
	TnodoD temp = NULL;
	temp = (TnodoD)malloc(sizeof(Tdat));
	printf("\n\nEspacio de memoria reservado...\n\n");
	return temp;
}
void servicio(Tnodo temp){
	
	printf("-----------------------------------\n");
	printf("DATO -> [%d]\n",temp->dato);
	printf("-----------------------------------\n");
}
void servicioD(TnodoD tempD)
{
	printf("-----------------------------------\n");
	printf("DATO -> [%d]\n",tempD->dat);
	printf("-----------------------------------\n");
}
void PUSH_pila(Tnodo *pila, Tnodo *nuevo){
	
	(*nuevo)->sig = *pila;
	*pila = *nuevo;
	*nuevo = NULL;
}

Tnodo POP_pila(Tnodo *pila){
	
	Tnodo temp = NULL;
	if(*pila)
		{	
			temp = (*pila);
			*pila = (temp)->sig;
			temp->sig = NULL;
		}
	return temp;
}

void PUSH_cola(Tnodo *cabeza,Tnodo *ultimo,Tnodo *nuevo){
	
	if(*cabeza)
	{
		(*ultimo)->sig = *nuevo;
	}
	else
	{
		*cabeza = *nuevo;	
	}
	
	*ultimo = *nuevo;
	*nuevo = NULL;				
}
Tnodo POP_cola(Tnodo *cabeza,Tnodo *ultimo){
		
	Tnodo temp = NULL;

	if(*cabeza)
	{	
		if(*cabeza == *ultimo)
		{
			temp = *ultimo;
			*cabeza = NULL;
			*ultimo = NULL;
		}
		else
		{
			temp = *cabeza;
			*cabeza = (temp)->sig;
			temp->sig = NULL;
		}
	}

	return temp;
}
Tnodo AgregarL(Tnodo *lista, Tnodo *nuevo)
      {
          Tnodo temp=NULL,nodo=NULL;
          temp=*lista;
          if(temp && (*nuevo)->dato>=(temp->dato))
            {
            while(temp->sig && (temp->sig)->dato < (*nuevo)->dato )
                 {
                   
                   temp=(temp->sig);
                   
                 }
                 if((*nuevo)->dato==(temp->dato))
                   {
                                   
                                  return *nuevo;
                   }
                    
                   (*nuevo)->sig=(temp->sig);
                   (temp->sig)=*nuevo;
                   return nodo;
            }
           
           (*nuevo)->sig=*lista;
           *lista=*nuevo;
           return nodo; 
                     
      }
Tnodo EliminarL(Tnodo *lista, int valor) {
		
	Tnodo temp = NULL;
	Tnodo nodo = NULL;	
	
	if(*lista)
	{
		if((*lista)->dato == valor)
		{
			nodo = *lista;
			*lista = nodo->sig;
			nodo->sig = NULL;
			return nodo;
		}
		else
		{
			temp = *lista;
			while(temp->sig && (temp->sig)->dato < valor)
			{
			temp = temp->sig;
			}
			if(temp->sig && (temp->sig)->dato == valor)
			{
				nodo = temp->sig;
				temp->sig = nodo->sig;
				nodo->sig = NULL;
				return nodo;	
			}
			else
			{
				return nodo;
			}
		}
	}
	return temp;
}
void ImprimirL(Tnodo lista) {
		
		Tnodo temp = NULL;
		temp = lista;
		
		if(temp)
		{		
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
Tnodo AgregarLC(Tnodo *lista, Tnodo *nuevo, Tnodo *ultimo){
	
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
				while((temp->sig)->dato < (*nuevo)->dato)
				{
					temp = temp->sig;
				}
				if((temp->sig)->dato != (*nuevo)->dato)
				{
					(*nuevo)->sig = temp->sig;
					temp->sig = *nuevo;
					*nuevo = NULL;
				}
				else
				{
					return *nuevo; 
				}	
			}		
		}
	}
	return nodo;
}
Tnodo EliminarLC(Tnodo *lista, Tnodo *ultimo, int valor){
	
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



void ImprimirLC(Tnodo lista,Tnodo ultimo) {
		
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
TnodoD AgregarLD(TnodoD *listaD,TnodoD *nuevo, TnodoD *ultimo) {
	
	TnodoD temp = NULL, nodo = NULL;
	
	//int lis,ult,resL,resU,valor;
	
	if(!(*listaD)) 
		{
			*listaD = *nuevo;
			*ultimo = *nuevo;
			*nuevo = NULL;	
		}
		else
		{
			if((*nuevo)->dat < (*listaD)->dat)
				{
					(*nuevo)->nex = *listaD;
					(*listaD)->ant = *nuevo;
					*listaD = *nuevo;
					*nuevo = NULL;
				}
				else if((*nuevo)->dat > (*listaD)->dat)
				{
					(*nuevo)->nex = *ultimo;
					(*ultimo)->ant = *nuevo;
					*ultimo = *nuevo;
					
				}
				else
				{
						temp = *listaD;
						while((temp->nex) && (temp->nex)->dat <= (*nuevo)->dat)
								{
									temp = temp->nex;
								}
								if(temp->dat == (*nuevo)->dat)
									{
										return *nuevo;
									}
								if(!(temp->nex))
									{
										(*nuevo)->nex = NULL;
 										(*nuevo)->ant = *ultimo;
										(*ultimo)->nex = *nuevo;
										*ultimo = *nuevo;
										*nuevo = NULL;
									}
									else
									{
										(*nuevo)->ant = temp;
										(*nuevo)->nex = temp->nex;
										temp->ant = *nuevo;
										temp->nex = *nuevo;
										temp = NULL;
									}
				}
		}	
	return nodo;
}
TnodoD EliminarLD(TnodoD *listaD, TnodoD *ultimo,int valor){

	TnodoD nodo = NULL,temp = NULL;

	if(*listaD)
	{
		if((*listaD)->dat == valor)
		{
			if(!(*listaD)->nex)
			{
				nodo = *listaD;
				*listaD = NULL;
				*ultimo = NULL;					
			}
			else
			{
				nodo = *listaD;
				*listaD = nodo->nex;
				nodo->nex = NULL;							
			}
		}
		else
		{
			temp = *listaD;
			while(temp->nex && (temp->nex)->dat < valor)
			{
				temp = temp->nex;
			}				
			if((temp->nex) && (temp->nex)->dat == valor)
			{
				nodo = temp->nex; //porque se detiene uno antes
				temp->nex = nodo->nex;
				nodo->nex = NULL;
			}
		}
	}
	return nodo;
}

void ImprimirLD(TnodoD listaD){

	TnodoD temp = NULL;
	temp = listaD;
	if(temp)
	{
		printf("\n============Datos de la Lista================\n\n");
		while(temp != NULL)
		{
			servicioD(temp);
			temp = temp->nex;
		}
	}
	else
	{
		printf("\nLa lista esta vacia...\n");
	}
	MSGE;
	PAUSE;
}
TnodoD AgregarLDC(TnodoD *listaD,TnodoD *nuevo){

	TnodoD temp = NULL, nodo = NULL;
	
	if(!(*listaD))
		{
			*listaD = *nuevo;
			(*listaD)->nex = *listaD;
			(*listaD)->ant = *listaD;

		}
		else
			{
				if((*nuevo)->dat < (*listaD)->dat)
					{
						(*nuevo)->nex = *listaD;
						(*nuevo)->ant = (*listaD)->ant;
						((*listaD)->ant)->nex = *nuevo;
						(*listaD)->ant = *nuevo;
						*listaD = *nuevo;
						
					}
				else if((*nuevo)->dat > ((*listaD)->ant)->dat)
				{
					(*nuevo)->ant = (*listaD)->ant;
					(*nuevo)->nex = *listaD;
					((*listaD)->ant)->nex = *nuevo;
					(*listaD)->ant = *nuevo;
				}
				else
				{
					temp = *listaD;
					while((temp->nex)->dat < (*nuevo)->dat )
					{
						temp = temp->nex;
					}
					if((temp->nex)->dat == (*nuevo)->dat)
						{
							return *nuevo;
						}
						if((temp->nex)->dat != (*nuevo)->dat)
						{
								(*nuevo)->nex = temp->nex;
								(*nuevo)->ant = temp;
								temp->nex = *nuevo;
								(temp->nex)->ant = *nuevo;
						}
						else
						{
							return *nuevo;
						}
				}
			}
	
	 return nodo;
}
TnodoD EliminarLDC(TnodoD *listaD,int valor){
	
	TnodoD temp = NULL,nodo = NULL;

	if(*listaD)
	{
		if((*listaD)->dat == valor)
		{
			if((*listaD)->dat == ((*listaD)->ant)->dat)
			{
				nodo = *listaD;
				*listaD = NULL;
				return nodo;
			}
			else 
			{
				nodo = *listaD;
				*listaD = (*listaD)->nex;
				(*listaD)->ant = nodo->ant;
				(nodo->ant)->nex = *listaD;
				nodo->nex = NULL;
				nodo->ant = NULL;
				return nodo;
			}
		}
		else
		{
			temp = *listaD;
			while(temp->nex != ((*listaD)->ant)->nex && ((temp->nex)->dat) < valor)
			{
				temp = temp->nex;
			}
			if((temp->nex)->dat == valor)
			{
				if(valor != ((*listaD)->ant)->dat)//entre 2 nodos
				{
					nodo = temp->nex;
					temp->nex = nodo->nex;
					(nodo->nex)->ant = temp;
					nodo->nex = NULL;
					nodo->ant = NULL;
					return nodo;
				}
				else		/// ultimo nodo
				{
					nodo = (*listaD)->ant;					
					(*listaD)->ant = temp;
					((*listaD)->ant)->nex = *listaD;
					nodo->nex = NULL;
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
void ImprimirLDC(TnodoD listaD){

		TnodoD temp = NULL;
 		temp = listaD;

		if(temp)
		{
			printf("\n============Datos de la Lista================\n\n");
			do
			{
				servicioD(temp);
				temp = temp->nex;
			}while(temp != listaD);
		}
		else
		{
			printf("\n La lista esta vacia\n");
		}

		MSGE;
		PAUSE;
}