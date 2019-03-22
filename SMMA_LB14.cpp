//Manuel Alejandro Sahagun Mendoza 349857
//Implementar Eliminar
//18 noviembre 2017
//SMMA_LB14y15
#include <stdlib.h>
#include <stdio.h>
//Declaracion de estructura
typedef struct _tarbol{

	int dato;
	struct _tarbol *izq;
	struct _tarbol *der;
	struct _tarbol *pad;
}Tarbol;

typedef Tarbol *TarbolP;
//Declaracion de prototipos
void Menu();
TarbolP GenDatosP();
void ServicioP(TarbolP temp);
TarbolP BuscarP(TarbolP raiz, int num);
TarbolP AddTreeP(TarbolP *raiz,TarbolP *nuevo);
void DesplegarP(TarbolP raiz);
void InOrden(TarbolP temp);
void PreOrden(TarbolP temp);
void PosOrden(TarbolP temp);
void PushPila(TarbolP *pila, TarbolP nuevo);
TarbolP PopPila(TarbolP *pila);
int Vacio(TarbolP raiz);
void EliminarP(TarbolP *raiz, int num);
int EsHoja(TarbolP nodo);
TarbolP Buscar(TarbolP raiz,int num);
int Altura(TarbolP temp,int *nivel);
void auxAltura(TarbolP nodo, int a, int *altura);

//Funcion principal
int main(){

	Menu();

	return 0;
}
//Funcion de Menu
void Menu(){

	TarbolP nuevo=NULL,temp=NULL,raiz=NULL;
	int op,num,nivel=0;

	do{
		system ("cls");
		printf("\n M  E   N   U");
		printf("\n1.- Agregar");
		printf("\n2.- Buscar");
		printf("\n3.- Eliminar");
		printf("\n4.- Desplegar");
		printf("\n5.- Altura");
		printf("\n0.- Salir");
		printf("\nESCOGE UNA OPCION.");
		scanf ("%d",&op);
		switch(op)
		{
			///////////////////////////////////////////////////
			case 1:
				system("cls");
				nuevo = GenDatosP();
				temp = AddTreeP(&raiz,&nuevo);

				system("pause");
				break;
			///////////////////////////////////////////////////
			case 2:
				system("cls");
				printf("Ingrese el numero que desea buscar: ");
				scanf("%d",&num);
				temp = Buscar(raiz,num);
				if(!temp)
				{
					printf("\nNumero no encontrado...\n");
				}
				else
				{
					printf("\nValor encontrado [%d]\n",temp->dato);
				}
				system("pause");
				break;
			///////////////////////////////////////////////////
			case 3:
				system("cls");
				printf("Escriba el numero que desea eliminar: ");
				scanf("%d",&num);
				EliminarP(&raiz,num);
				system("pause");
				break;
			///////////////////////////////////////////////////
			case 4: DesplegarP(raiz); break;
			///////////////////////////////////////////////////
			case 5:
				system("cls");
				Altura(raiz,&nivel);
				printf("El nivel del arbol es: [%d]\n",nivel);
				system("pause");
				break;
			///////////////////////////////////////////////////
			case 0:

				break;
		}
	}while(op != 0);
}

//Funcion para generar datos
TarbolP GenDatosP(){

	int x;
	TarbolP temp = NULL;
	temp = (TarbolP)malloc(sizeof(Tarbol));

	temp->pad = NULL;
	temp->der = NULL;
	temp->izq = NULL;
	//x =rand()%100;
	printf("Ingrese un numero entero: ");
	scanf("%d",&x);
	temp->dato = x;
	return temp;
}
//Funcion para dar servicio al nodo
void ServicioP(TarbolP temp){

	printf("-----------------------------------\n");
	printf("DATO -> [%d]\n",temp->dato);
	printf("-----------------------------------\n");
}
//Funcion para buscar nodos
TarbolP BuscarP(TarbolP raiz, int num){

	TarbolP temp=raiz;
	while(temp)
	{
		if(temp->dato == num)
		{
			return temp;
		}
		if(temp->dato <num)
		{
			temp = temp->izq;
		}
		else
		{
			temp = temp->der;
		}
	}
	return temp;
}
//Funcion para desvincular
void Desvincular(TarbolP *raiz,TarbolP *kill){

/*	TarbolP temp = NULL;
	if((!*kill->izq) && (!*kill->der))
	{

	}*/
}
//Funcion para agregar datos
TarbolP AddTreeP(TarbolP *raiz,TarbolP *nuevo){

	TarbolP temp=NULL,scout=NULL;

	if(!*raiz)
	{
		*raiz = *nuevo;
	}
	else
	{
		scout=*raiz;
		while(scout)
		{
			temp=scout;
			if(temp->dato == (*nuevo)->dato)
			{
				return temp;
			}
			if((*nuevo)->dato > temp->dato)
			{
				scout=scout->der;
			}
			else
			{
				scout=scout->izq;
			}
		}
		(*nuevo)->pad = temp;
		if((*nuevo)->dato > temp->dato)
		{
			temp->der = *nuevo;

		}
		else
		{
			temp->izq = *nuevo;
		}

	}
	return scout=NULL;
}
//Funcion InOrdern
void InOrden(TarbolP temp){

	if(temp->izq)
	{
		InOrden(temp->izq);
	}

	ServicioP(temp);

	if(temp->der)
	{
		InOrden(temp->der);
	}
}
//Funcion PosOrden
void PosOrden(TarbolP temp){

	if(temp->izq)
	{
		PosOrden(temp->izq);
	}

	if(temp->der)
	{
		PosOrden(temp->der);
	}

	ServicioP(temp);
}
//Funcion PreOrden
void PreOrden(TarbolP temp){

	ServicioP(temp);
	if(temp->izq)
	{
		PreOrden(temp->izq);
	}

	if(temp->der)
	{
		PreOrden(temp->der);
	}
}
//Funcion para Desplegar datos
void DesplegarP(TarbolP raiz){

	int op;
	TarbolP temp = NULL;
	if(raiz)
	{
		temp=raiz;
		do{
			system("cls");
			printf("DESPLEGAR\n");
			printf("\n1.-Inorden");
			printf("\n2.-Posorden");
			printf("\n3.-Preorden");
			printf("\n0.-Regresar\n");
			scanf("%d",&op);
			switch(op){
				case 1: InOrden(temp);  break;
				case 2: PosOrden(temp); break;
				case 3: PreOrden(temp); break;
			}
		}while(op!=0);
	}
	else
	{
		printf("\t\nEl arbol esta vacio, agregue un valor e intente de nuevo\n");
	}
	system("pause");
}
//Funcion Push Pila
void PushPila(TarbolP *pila, TarbolP nuevo){

	nuevo->der = *pila;
	*pila = nuevo;
	nuevo = NULL;
}
//Funcion Pop Pila
TarbolP PopPila(TarbolP *pila){

	TarbolP temp = NULL;

		temp = (*pila);
		*pila = temp->der;
		temp->der = NULL;

	return temp;
}
//Funcion para borrar
void EliminarP(TarbolP *raiz, int num){
	TarbolP padre = NULL;
	TarbolP actual = NULL;
	TarbolP nodo = NULL;
	int aux;

	actual = *raiz;
	//Mientras el arbol no este vacio
	while(!Vacio(actual))
	{
		if(num == actual->dato)	//Si el valor está en el nodo actual
		{
			if(EsHoja(actual))	//Y si es hoja, lo borramos
			{
				if(padre)	//Si tiene padre anulamos el puntero que le hace referencia
					if(padre->der == actual)
						padre->der = NULL;
					else if(padre->izq == actual)
						padre->izq = NULL;
					free(actual); //Borramos el nodo
					actual = NULL;
					return;
			}
			else //Si el valor está en el nodo actual, pero no es hoja
			{
				padre = actual;
				if(actual->der) //Buscar nodo más izquierdo de rama derecha
				{
					nodo = actual->der;
					while(nodo->izq)
					{
						padre = nodo;
						nodo = nodo->izq;
					}
				}
				else //O buscar nodo más derecho de rama izquierda
				{
					nodo = actual->izq;
					while(nodo->der)
					{
						padre = nodo;
						nodo = nodo->der;
					}
				}
				/*Se intercambian los valores del nodo a borrar.
				El nodo encontrado no tiene qué ser un nodo hoja*/
				aux = actual->dato;
				actual->dato = nodo->dato;
				nodo->dato = aux;
				actual = nodo;
			}
      }
      else //Si aun no encontramos el valor, seguimos recorriendo el arbol
	  {
         padre = actual;
         if(num > actual->dato)
			 actual = actual->der;
         else if(num < actual->dato)
			 actual = actual->izq;
      }
   }
}
//Funcion para determinar si esta vacio
int Vacio(TarbolP nodo){
   return nodo==NULL;
}
//Es hoja
int EsHoja(TarbolP nodo){
   return !nodo->der && !nodo->izq;
}
//Funcion para buscar en el arbol binario
TarbolP Buscar(TarbolP raiz,int num){

	TarbolP temp=NULL,scout=NULL;

	if(!raiz)
	{
		return scout;
	}
	else
	{
		scout=raiz;
		while(scout)
		{
			temp=scout;
			if(temp->dato == num)
			{
				return temp;
			}
			if(num > temp->dato)
			{
				scout=scout->der;
			}
			else
			{
				scout=scout->izq;
			}
		}
	}
}
//Funcion Auxiliar de altura
void auxAltura(TarbolP nodo, int a, int *altura){

   if(nodo->izq) auxAltura(nodo->izq, a+1, altura);
   if(nodo->der)   auxAltura(nodo->der, a+1, altura);
   if(EsHoja(nodo) && a > *altura) *altura = a;
}
//Funcion para calcular altura
int Altura(TarbolP temp,int *nivel){

	*nivel = 0;
    auxAltura(temp,0,nivel);
    return *nivel;

}
