//Manuel Alejandro Sahagun Mendoza 349857
//Colas 01 A
//25 agosto 2017
//SMMA_L03

//Librerias incluidas
#include <stdio.h>
#include <stdlib.h>

//Tipo dato basico generico
typedef struct _tdato{
	
	int dato;
	struct _tdato *sig;	

}Tdato;

typedef Tdato *Tnodo;

//Prototipos de funciones
void menu();
Tnodo GenDatos(void);
void PUSH_COLA(Tnodo *cabeza,Tnodo *ultimo,Tnodo *nuevo);
Tnodo POP_COLA(Tnodo *cabeza,Tnodo *ultimo);
void servicio_cola(Tnodo temp);

//Funcion principal
int main(int argc, char *argv[]) {
	
	menu();
	Tnodo GenDatos(void);

	return 0;
}

//Funcion de menu
void menu (){
	int op;

	Tnodo cabeza = NULL;
	Tnodo nuevo = NULL;
	Tnodo ultimo = NULL;
	Tnodo temp = NULL;
	
	do
	{
		system("cls");
		printf("\n\tM\tE\tN\tU");
		printf("\n1.- Agregar");
		printf("\n2.- Borrar");
		printf("\n0.- Salir\n");
		scanf("%d",&op);
		switch(op)
			{
			case 1:
					nuevo = GenDatos();
					PUSH_COLA(&cabeza,&ultimo,&nuevo);
					break;
				
			case 2:
					temp = POP_COLA(&cabeza,&ultimo);
					if(temp)
						{
							servicio_cola(temp);
							free(temp);
						}
						else
						{
								printf("La cola esta vacia...\n");
								system("pause");
						}
						break;
					
			case 0: 
					while(cabeza)
							{
								temp = cabeza;
								cabeza = temp->sig;
								servicio_cola(temp);
								free(temp);
							}
							break;	
			}

	}while(op!=0);
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
	system("pause");
	return temp;	
}

void PUSH_COLA(Tnodo *cabeza,Tnodo *ultimo,Tnodo *nuevo) {
	
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

Tnodo POP_COLA(Tnodo *cabeza,Tnodo *ultimo) {
		
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

void servicio_cola(Tnodo temp) {

	system("cls");
	printf("-----------------------------------\n");
	printf("DATO -> [%d]\n",temp->dato);
	printf("-----------------------------------\n");
	system("pause");
}



