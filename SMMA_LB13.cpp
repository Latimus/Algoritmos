//Manuel Alejandro Sahagun Mendoza 349857
//Arboles Binarios inorden,preorden,postorden
//12 noviembre 2017
//SMMA_LB13

#include<stdlib.h>
#include<stdio.h>
//Estructura del nodo
typedef struct _tdato{

	int dato;
	struct _tdato *der;
	struct _tdato *izq;

}Tnodo;

typedef Tnodo *Tarbol;

//Prototipos de funciones
void Menu();
void servicio(Tarbol temp);
Tarbol GenDatos();
Tarbol AddTree(Tarbol *raiz,Tarbol *nuevo);
void InOrden(Tarbol temp);
void PosOrden(Tarbol temp);
void PreOrden(Tarbol temp);
Tarbol Buscar(Tarbol raiz,int num);
void Desplegar(Tarbol raiz);
int ContarHojas(Tarbol temp,int *hojas);
int NumeroNodos(Tarbol raiz, int *nodos);
int Altura(Tarbol temp,int *nivel);
int EsHoja(Tarbol temp);
void auxContador(Tarbol temp, int *c);
void auxContarHojas(Tarbol temp,int *c);
void auxAltura(Tarbol nodo, int a, int *altura);
int EsHoja(Tarbol r);
//void Liberar(Tarbol aux);

//Funcion principal
int main(){

	Menu();

	return 0;
}
//Funcion de Menu
void Menu(){

	Tarbol nuevo=NULL,temp=NULL,raiz=NULL;
	int op,num,hojas=0,nodos=0,nivel=0;
	
	do{
		system ("cls");
		printf("\n M  E   N   U");
		printf("\n1.- Agregar");
		printf("\n2.- Buscar");
		printf("\n3.- Desplegar");
		printf("\n4.- Contar Hojas"); 
		printf("\n5.- Contar Nodos");
		printf("\n6.- Altura");
		printf("\n0.- Salir");
		printf("\nESCOGE UNA OPCION.");
		scanf ("%d",&op);
		switch(op)
		{
			///////////////////////////////////////////////////
			case 1: 
				system("cls");
				nuevo = GenDatos();
				temp = AddTree(&raiz,&nuevo);
				if(!temp)
				{
					printf("Valor agregado [%d]\n",nuevo->dato);
				}
				else
				{
					printf("Valor Repetido [%d]\n",temp->dato);
				}
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
			case 3: Desplegar(raiz); break;
			///////////////////////////////////////////////////
			case 4: 
				system("cls");
				ContarHojas(raiz,&hojas); 
				printf("El numero de hojas es: [%d]\n",hojas);
				system("pause");
				break;
			///////////////////////////////////////////////////
			case 5:
				system("cls");
				NumeroNodos(raiz,&nodos);
				printf("El numero de nodos es: [%d]\n",nodos);
				system("pause");
				break;
			///////////////////////////////////////////////////
			case 6:
				system("cls");
				Altura(raiz,&nivel);
				printf("El nivel del arbol es: [%d]\n",nivel);
				system("pause");
				break;
			///////////////////////////////////////////////////
			case 0:
				/*system("cls");
				if(raiz)
				{
					Liberar(raiz);
				}
				system("pause");*/
				break;
		}
	}while(op != 0);
}
//Funcion para agregar datos
Tarbol AddTree(Tarbol *raiz,Tarbol *nuevo){

	Tarbol temp=NULL,scout=NULL;

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
void InOrden(Tarbol temp){

	if(temp->izq)
	{
		InOrden(temp->izq);
	}

	servicio(temp);

	if(temp->der)
	{
		InOrden(temp->der);
	}
}
//Funcion PosOrden
void PosOrden(Tarbol temp){
	
	if(temp->izq)
	{
		PosOrden(temp->izq);
	}

	if(temp->der)
	{
		PosOrden(temp->der);
	}

	servicio(temp);
}
//Funcion PreOrden
void PreOrden(Tarbol temp){
	
	servicio(temp);
	if(temp->izq)
	{
		PreOrden(temp->izq);
	}

	if(temp->der)
	{
		PreOrden(temp->der);
	}
}
//Funcuon para generar datos
Tarbol GenDatos(){

	int x;
	Tarbol temp = NULL;
	temp = (Tarbol)malloc(sizeof(Tnodo));

	temp->der = NULL;
	temp->izq = NULL;
	//x =rand()%100;
	printf("Ingrese un numero entero: ");
	scanf("%d",&x);
	temp->dato = x;
	return temp;
}
//Funcion para dar servicio al nodo
void servicio(Tarbol temp){

	printf("-----------------------------------\n");
	printf("DATO -> [%d]\n",temp->dato);
	printf("-----------------------------------\n");
}

//Funcion para buscar en el arbol binario
Tarbol Buscar(Tarbol raiz,int num){

	Tarbol temp=NULL,scout=NULL;

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
//Funcion para Desplegar datos
void Desplegar(Tarbol raiz){
	
	int op;
	Tarbol temp=NULL;
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
//Funcion para Contar Hojas
int ContarHojas(Tarbol temp,int *hojas){

	*hojas = 0;
	auxContarHojas(temp,hojas);
	return *hojas;
}
//Funcion para Contar Nodos
int NumeroNodos(Tarbol raiz, int *nodos){
   
   *nodos = 0;
   auxContador(raiz,nodos);
   return *nodos;
}
//Funcion para calcular la altura del arbol
int Altura(Tarbol temp,int *nivel){
	
	*nivel = 0; /* (1) */
    auxAltura(temp,0,nivel);
    return *nivel;

}

//Funciones Aux
void auxContador(Tarbol temp, int *c){
   (*c)++; /* Acción: incrementar número de nodos. (Preorden) */
   if(temp->izq) auxContador(temp->izq, c); /* Rama izquierda */
   if(temp->der)   auxContador(temp->der, c);   /* Rama derecha */
}
void auxContarHojas(Tarbol temp,int *c){

    if(temp->izq)	auxContador(temp->izq,c); /* Rama izquierda */
    if(temp->der)	auxContador(temp->der,c);   /* Rama derecha */
	if(!temp->der && !temp->izq) (*c)++;
}
void auxAltura(Tarbol nodo, int a, int *altura){
   /* (2) Cada vez que llamamos a auxAltura pasamos como parámetro a+1 */
   if(nodo->izq) auxAltura(nodo->izq, a+1, altura); /* Rama izquierda */
   if(nodo->der)   auxAltura(nodo->der, a+1, altura);   /* Rama derecha */
   if(EsHoja(nodo) && a > *altura) *altura = a; /* Proceso (Postorden)  (3) */
}
//Funcion para determinar si un nodo es hoja
int EsHoja(Tarbol r){
   return !r->der && !r->izq;
}

//Funcion para liberar memoria
/*void Liberar(Tarbol aux){
	
	if((aux)->izq)
	{
		Liberar(aux->izq);
	}

	if(aux->der)
	{
		Liberar(aux->der);
	}
	
	servicio(aux);
	free(aux);
}*/