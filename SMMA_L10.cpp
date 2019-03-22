#include <stdio.h>
#include <stdlib.h>

#define TAM 13 //tamaño del vector

typedef struct _tdato{
	int dato;
	struct _tdato *sig;
}Tdato; //Estructura del nodo, [dato/*sig]

typedef Tdato *Tnodo; 
Tnodo hash[TAM],lista= NULL;		//son del tipo puntero
//prototipos de funciones
void menu();
Tnodo GenDatos();
void PUSH_pila(Tnodo *hash, Tnodo *nuevo);
Tnodo Buscar(Tnodo hash, int buscar);
Tnodo Eliminar(Tnodo *lista,int valor);
int Estadisticas(Tnodo hash);
Tnodo POP_nodo(Tnodo *hash);
void servicio(Tnodo temp);

int main(){

	menu();

return 0;
}

void menu(){

	int op; //operador del switch
	int	buscar=0; //variable para buscar en la funcion de Buscar() y Eliminar()
	int	residuo=0; //variable para recojer el dato del modulo de "k"%TAM
	int	i=0; //contador para ciclo for en case: 4
	int	j=0; //variable para recibir el numero de datos que contiene cada indice en el case:4

	Tnodo temp = NULL;
	Tnodo nuevo = NULL;
	Tnodo pila = NULL; //se meten los datos en forma de pila

	  do{
      system ("cls");
      printf("\n M  E   N   U");
	  printf("\n1.- Agregar");
	  printf("\n2.- Buscar");
	  printf("\n3.- Eliminar");
	  printf("\n4.- Estadisticas");
	  printf("\n0.- Salir");
	  printf("\nESCOGE UNA OPCION:\n");
      scanf ("%d",&op);
	  switch(op)
	    {
		  case 1:
			  system("cls"); 
			  nuevo = GenDatos(); //se genera un dato a gusto o aleatorio segun sea el caso
			  residuo=nuevo->dato%TAM;	//obtenemos el modulo del dato generado contra el numero 
										//de datos del vector
			  PUSH_pila(&hash[residuo],&nuevo);	//metemos el dato al vector "hash" en forma de pila
			  system("pause");
			  break;
		 case 2:
			system("cls");
			printf("Ingrese el elemento que desea buscar: ");
			scanf("%d",&buscar);
			residuo = buscar%TAM;	//obtenemos el modulo del dato se que desea buscar contra el 
									//tamaño del vector
			temp = Buscar(hash[residuo],buscar);//la funcion de buscar retorna el nodo 
												//con el valor encontrado
			if(temp) //si temporal tiene algo, es poque encontro el valor deseado, entonces se imprime
			{		 //usando la variable resudio como indice y la variable buscar como el dato 
				printf("Dato encontrado en el indice [%d], Dato: [%d]...\n",residuo,buscar);
			}
			else //si el temporal tiene un NULL, entonces no encontro el dato 
			{
				printf("El elemento [%d] no se encuentra...\n",buscar);
			}
			
			system("pause");
			break;
		 case 3:
			 system("cls");
			 printf("Ingrese el elemento que desea eliminar: ");
			 scanf("%d",&buscar);
			 residuo = buscar%TAM; //obtenemos el modulo del dato que desea eliminar contra
								   //el tamaño del vector
			 temp = Eliminar(&hash[residuo],buscar); //temp recibe el nodo que se desea eliminar
			 if(temp != NULL)	//si temp es diferente de NULL entonces ha encontrado el dato 
			 {
				 printf("Dato eliminado en el indice [%d], Dato: [%d]...\n",residuo,buscar);
				 free(temp); //se imprime el indice y el dato y despues se libera la memoria 
			 }						//borrando el dato
			 else
			 {		//si la funcion Eliminar nos regresa un NULL, entonces el dato no se encuentra
				printf("El elemento [%d] no se encuentra...\n",buscar);
			 }
			 
			 system("pause");
			 break;
		 case 4:
			 system("cls");
			 printf("\tEstadisticas\n\n");
			 for(hash[i=0];i<=TAM;i++) //se usa un ciclo for para recorrer el vector de tamaño conocido
			 {						//desde la posicion 0 hasta la posicion 13 por eso se usa "<="
				j = Estadisticas(hash[i]); //j recibe el numero de saltos que da en cada indice 
				if(j>0)						//asi conocemos cuantos datos tiene cada indice
				{
					printf("Indice: [%d]\tNumero de Datos: [%d]\n",i,j);//se imprime el indice y el dato
				}														//en cada iteracion
				else
				{
					printf("Indice: [/]\n");
				}
			 }														
			 system("pause");
			 break;
		 case 0:
			 system("cls");
			 printf("Liberando Memoria\n");
			 for(hash[i=0];i<=TAM;i++)
			 {
				 temp = POP_nodo(&hash[i]);
				 if(temp)
				 {
					 servicio(temp);
					 free(temp);
					 i--;
				 }
			 }
			 system("pause");
			 break;
		}
   }while(op != 0);
}

Tnodo GenDatos(){
	
	int x=0;
	Tnodo temp = NULL;
	temp = (Tnodo)malloc(sizeof(Tdato)); //reservamos el espacio de memoria de la estructura Tdato
	temp->sig = NULL; //nos aseguramos que el nodo generado no apunte a ningun lado
	printf("Ingrese un dato: "); //si se desea añadir datos manualmente 
	scanf("%d",&x);
	//x=(rand()%100)+1; // si se desea añadir datos aleatoriamente
	temp->dato = x; //asignamos el nuevo dato al nodo [x/*]

	return temp;
}

void PUSH_pila(Tnodo *hash, Tnodo *nuevo){
	
	(*nuevo)->sig = *hash; 
	*hash = *nuevo; 
	*nuevo = NULL;
}

Tnodo Buscar(Tnodo hash,int buscar)	{
	Tnodo temp = NULL,nodo = NULL;

	if(hash)
	{
		temp = hash;
		while(temp->sig && temp->dato != buscar)
		{
			temp=temp->sig;
		}
		if(temp->dato == buscar)
			return temp;
	}
	return nodo;
}

Tnodo Eliminar(Tnodo *lista,int valor){
	
	Tnodo temp = NULL, nodo = NULL;
	
	if(*lista)
	{
		if((*lista)->dato == valor)
		{
			nodo = *lista;
			*lista = nodo->sig;
			nodo->sig = NULL;
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
	else
	{
	return nodo;
	}
}

int Estadisticas(Tnodo hash){

	int j=0;

	if(hash != NULL) //si la tabla tiene datos entonces se realiza el ciclo while
	{
		while(hash != NULL) //mientras el indice de la tabla contenga datos
		{					//se recorrera la lista de nodos
			hash = hash->sig;
			j++; //contador de nodos
		}
		return j; 
	}
	else //si la tabla no contiene nodos entonces regresa un 0
	{
		return 0;
	}	
}

Tnodo POP_nodo(Tnodo *hash){
	
	Tnodo temp = NULL;
	if(*hash)
		{	
			temp = (*hash);
			*hash = (temp)->sig;
			temp->sig = NULL;
		}
	return temp;
}
void servicio(Tnodo temp) {

	printf("-----------------------------------\n");
	printf("DATO -> [%d]\n",temp->dato);
	printf("-----------------------------------\n");
	
}