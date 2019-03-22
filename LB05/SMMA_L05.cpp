//Manuel Alejandro Sahagun Mendoza 349857
//Pilas, Colas y Listas (mensaje descifrado)
//15 septiembre 2017
//SMMA_L05

//Librerias incluidas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Tipo dato basico generico
typedef struct _tdato{
	
	int dato;
	char oculto[20];
	struct _tdato *sig;	

}Tdato;

typedef Tdato *Tnodo;

//Prototipos de funciones
void menu();
void PUSH_pila(Tnodo *pila, Tnodo *nuevo);
Tnodo POP_pila(Tnodo *pila);
void servicio_pila(Tnodo temp);
void servicio_lista(Tnodo temp);
void servicio_pila2(Tnodo temp);
void imprimir(Tnodo lista);
Tnodo agregar(Tnodo *lista, Tnodo *nuevo);
Tnodo GenDatos();

//Funcion principal
int main(int argc, char *argv[]) {
	
	menu();

	return 0;
}

//Funcion de menu
void menu (){
	int op,i=0,j=0;
	char aux[20];

	Tnodo pila = NULL;
	Tnodo picla = NULL;
	Tnodo nuevo = NULL;
	Tnodo lista = NULL;
	Tnodo temp = NULL;
	FILE *arch = NULL, *cla = NULL;
	
	do
	{
		system("cls");
		printf("\n\tM\tE\tN\tU");
		printf("\n1.- Decifrar");
		printf("\n2.- Imprimir Mensaje oculto");
		printf("\n0.- Salir\n");
		scanf("%d",&op);
		switch(op)
			{
			case 1:
				////////////////////////Seccion del ARCH
				arch = fopen("Importante.txt","r");
				if(arch == NULL) {
					printf("\nEl archivo no se encuentra o no existe\n");
					break;
				}
				
				rewind(arch);
				
				while(!feof(arch))
					{
						temp =	GenDatos();
						fscanf(arch,"%s",temp->oculto);
						nuevo = temp;
						PUSH_pila(&pila,&nuevo);

						servicio_pila(temp);
						
						}
						
					fclose(arch);
					////////////////////////////////////Termina ARCH
					////////////////////////////////////Comienza CLA
					cla = fopen("clave.txt","r");
					
					if(cla == NULL) {
						printf("\nEl archivo no se encuentra o no existe\n");
						break;
					}
					
					rewind(cla);
					
					while(!feof(cla))
						{
							temp = GenDatos();
							fscanf(cla,"%d",&temp->dato);
							nuevo = temp;
							PUSH_pila(&picla,&nuevo);
							servicio_pila2(temp);
						}
					fclose(cla);
					////////////////////////////////////Termina CLA
					////////////////////////////////////Comienza el desencripte
					nuevo = NULL;
					
							while(picla)
								{
									//temp = NULL;
									temp = POP_pila(&picla); //depositamos el valor de la clave
									j=temp->dato; //le damos el valor de la clave a una variable
									for(i=0;i<j;i++) //ciclamos el numero de POP de la PILA
										{			//liberamos memoria al princpio para no borrar el 
												temp = NULL;	//ultimo dato extraido
												temp = POP_pila(&pila);
										}
									nuevo = temp;
									temp = POP_pila(&picla);
									nuevo->dato = temp->dato;
									temp = NULL;
									temp = agregar(&lista,&nuevo);		
								}
					//////////////////////////////////Aqui esta el BREAK
				break;
				
				case 2:
					imprimir(lista);
				break;
					//Liberar memoria
				case 0: 
				
						while(pila)
						{
								temp = pila;
								pila = temp->sig;
								servicio_pila(temp);
								free(temp);
						}
						
						while(picla)
						{
								temp = picla;
								picla = temp->sig;
								servicio_pila2(temp);
								free(temp);
						}
						while(lista)
							{
								temp = lista;
								lista = temp->sig;
								servicio_lista(temp);
								free(temp);
							}
						break;
			}
	}while(op!=0);
}

//Funcion Push de la pila
void PUSH_pila(Tnodo *pila, Tnodo *nuevo) {
		
		(*nuevo)->sig = *pila;
		*pila = *nuevo;
		*nuevo = NULL;
	
}

//Funcion Pop de la pila
Tnodo POP_pila(Tnodo *pila) {
	
	Tnodo temp = NULL;
	if(*pila)
		{	
			temp = (*pila);
			*pila = (temp)->sig;
			temp->sig = NULL;
		}
	return temp;
}

//Servicio Pila
void servicio_pila(Tnodo temp) {

	system("cls");
	printf("Liberando memoria\n");
	printf("-----------------------------------\n");
	printf("DATO -> [%s]\n",temp->oculto);
	printf("-----------------------------------\n");
	
}

//Servicio Pila2
void servicio_pila2(Tnodo temp) {

	system("cls");
	printf("Liberando memoria\n");
	printf("-----------------------------------\n");
	printf("DATO -> [%d]\n",temp->dato);
	printf("-----------------------------------\n");
	
}

//Genera el espacio de memoria de Temp
Tnodo GenDatos() {
		
	Tnodo temp = NULL;
	temp = (Tnodo)malloc(sizeof(Tdato));
	printf("\n\nEspacio de memoria reservado...\n\n");
	return temp;
}

//Agrega datos a una lista
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

//Imprime la lista
void imprimir(Tnodo lista) {
		
		system("cls");
		Tnodo temp = NULL;
		temp = lista;
		
		if(temp){		
				printf("\n============Mensaje oculto================\n\n");
				while(temp != NULL) {
						servicio_lista(temp);
						
						temp = temp->sig;
				}
		}
		else
		{
			printf("\nLa lista esta vacia...\n");	
		}
		printf("\n\n");
		system("pause");
}

//Da servicio a la lista
void servicio_lista(Tnodo temp) {

	
	printf("%s ",temp->oculto);
	
	
}

