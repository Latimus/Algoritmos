//Manuel Alejandro Sahagun Mendoza 349857
//Pilas, colas, listas y listas circulares
//15 octubre 2017
//SMMA_L09

//Librerias incluidas
#include "menio.h"

//Prototipos de funciones
void pr11();


//Funcion principal
int main(int argc, char *argv[]) {
	
	pr11();

	return 0;
}

//Funcion de menu
void pr11(){
	
	Tnodo pila	=	NULL;
	Tnodo pilaaux = NULL;
	
	
	Tnodo cabeza=	NULL;
	Tnodo colaaux=	NULL;
	Tnodo ultcoaux= NULL;
	Tnodo ultimoC=	NULL;
	
	Tnodo lista	=	NULL;
	
	Tnodo listaLC=	NULL;
	Tnodo ultimoLC= NULL;

	TnodoD listaLD= NULL;
	TnodoD ultimoLD=NULL;

	TnodoD listaLDC=NULL;
	TnodoD ultimoLDC=NULL;
	
	TnodoD nuevoD=	NULL;
	Tnodo nuevo	=	NULL;
	TnodoD tempD=	NULL;
	Tnodo temp	=	NULL;

	FILE *arch	=	NULL;
	FILE *inst	=	NULL;
	char comando[100];
	int op,num,ret=0,i=0;//declaracion de variables

	do{
		LIMPIA;
		printf("\n\tM\tE\tN\tU");
		printf("\n1.- Comenzar");
		printf("\n0.- Salir\n");
		printf("\nElija una opcion...");
		scanf("%d",&op);
		switch(op)
		{
		case 1:

			LIMPIA;
			inst = fopen("Instrucciones.txt","r");
			if(!inst)
			{
				printf("\nEl archivo no se encuentra o no existe\n");
				break;
			}
			rewind(inst);
			while(!feof(inst))
			{
				temp = GenDatos();
				tempD=GenDatosD();
				fscanf(inst,"%s",comando);
				ret = stricmp(comando,"ADD");
				if(ret == 0)
				{
					fscanf(inst,"%d",&num);
					temp->dato = num;
					tempD->dat = num;
					nuevo = temp;
					nuevoD = tempD;
					temp = nuevo;
					tempD = nuevoD;
					
					nuevo = temp;
					PUSH_pila(&pila,&nuevo);
					servicio(temp);
					PAUSE;

					nuevo = temp;
					PUSH_cola(&cabeza,&ultimoC,&nuevo);
					servicio(temp);
					PAUSE;

					nuevo = temp;
					AgregarL(&lista,&nuevo);
					servicio(temp);
					PAUSE;

					nuevo = temp;
					AgregarLC(&listaLC,&nuevo,&ultimoLC);
					servicio(temp);
					PAUSE;

					nuevoD = tempD;

					AgregarLD(&listaLD,&nuevoD,&ultimoLD);
					servicioD(tempD);
					PAUSE;

					nuevoD = tempD;
					AgregarLDC(&listaLDC,&nuevoD);
					servicioD(tempD);
					PAUSE;
				}
				ret = stricmp(comando,"VIEW");
				if(ret == 0)
				{
					ImprimirL(lista);
					ImprimirLC(listaLC,ultimoLC);
					ImprimirLD(listaLD);
					ImprimirLDC(listaLDC);
				}//Seccion de ver en pantalla
				ret = stricmp(comando,"PRINT");
				if(ret == 0)
				{
					i++;
					if(i == 1)
					{
						arch = fopen("lista1.txt","a");
						temp = lista;
						while(temp->sig != NULL)
						{
							fprintf(arch,"%d\n",temp->dato);
							temp = temp->sig;
						}
						fclose(arch);

						arch = fopen("listaC1.txt","a");
						temp = listaLC;
						while(temp->sig != listaLC)
						{
							fprintf(arch,"%d\n",temp->dato);
							temp = temp->sig;
						}
						fclose(arch);
						
						arch = fopen("pila1.txt","a");
						pilaaux = pila;
						while(pilaaux != NULL)
						{
							temp = POP_pila(&pilaaux);
							fprintf(arch,"%d\n",temp->dato);
						}
						fclose(arch);
						
						arch = fopen("cola1.txt","a");
						colaaux = cabeza;
						ultcoaux = ultimoC;
						while(colaaux != NULL)
						{
							temp = POP_cola(&colaaux,&ultcoaux);
							fprintf(arch,"%d\n",temp->dato);
						}
						fclose(arch);
					}
					else if(i == 2)
					{
						arch = fopen("lista2.txt","a");
						temp = lista;
						while(temp->sig != NULL)
						{
							fprintf(arch,"%d\n",temp->dato);
							temp = temp->sig;
						}
						fclose(arch);

						arch = fopen("listaC2.txt","a");
						temp = listaLC;
						while(temp->sig != listaLC)
						{
							fprintf(arch,"%d\n",temp->dato);
							temp = temp->sig;
						}
						fclose(arch);
						
						arch = fopen("pila2.txt","a");
						pilaaux = pila;
						while(pilaaux != NULL)
						{
							temp = POP_pila(&pilaaux);
							fprintf(arch,"%d\n",temp->dato);
						}
						fclose(arch);
						
						arch = fopen("cola2.txt","a");
						colaaux = cabeza;
						ultcoaux = ultimoC;
						while(colaaux != NULL)
						{
							temp = POP_cola(&colaaux,&ultcoaux);
							fprintf(arch,"%d\n",temp->dato);
						}
						fclose(arch);
					}
					else
					{
						arch = fopen("lista3.txt","a");
						temp = lista;
						while(temp->sig != NULL)
						{
							fprintf(arch,"%d\n",temp->dato);
							temp = temp->sig;
						}
						fclose(arch);

						arch = fopen("listaC3.txt","a");
						temp = listaLC;
						while(temp->sig != listaLC)
						{
							fprintf(arch,"%d\n",temp->dato);
							temp = temp->sig;
						}
						fclose(arch);
						
						arch = fopen("pila3.txt","a");
						pilaaux = pila;
						while(pilaaux != NULL)
						{
							temp = POP_pila(&pilaaux);
							fprintf(arch,"%d\n",temp->dato);
						}
						fclose(arch);
						
						arch = fopen("cola3.txt","a");
						colaaux = cabeza;
						ultcoaux = ultimoC;
						while(colaaux != NULL)
						{
							temp = POP_cola(&colaaux,&ultcoaux);
							fprintf(arch,"%d\n",temp->dato);
						}
						fclose(arch);
					}

				}//Seccion de archivos
				ret = stricmp(comando,"ADDcola");
				if(ret == 0)
				{
					fscanf(inst,"%d",&temp->dato);
					nuevo = temp;
					PUSH_cola(&cabeza,&ultimoC,&nuevo);
				}
				ret = stricmp(comando,"ADDpila");
				if(ret == 0)
				{
					fscanf(inst,"%d",&temp->dato);
					nuevo = temp;
					PUSH_pila(&pila,&nuevo);
					servicio(temp);
					PAUSE;
				}
				ret = stricmp(comando,"DELETE");
				if(ret == 0)
				{
					fscanf(inst,"%d",&num);
					temp = EliminarL(&lista,num);
					servicio(temp);
					PAUSE;
					free(temp);
					temp = EliminarLC(&listaLC,&ultimoLC,num);
					servicio(temp);
					PAUSE;
					free(temp);
					tempD = EliminarLD(&listaLD,&ultimoLD,num);
					servicioD(tempD);
					PAUSE;
					free(tempD);
					tempD = EliminarLDC(&listaLDC,num);
					servicioD(tempD);
					PAUSE;
					free(tempD);
				}
				ret = stricmp(comando,"DELETElistaC");
				if(ret == 0)
				{
					fscanf(inst,"%d",&num);
					temp = EliminarLC(&listaLC,&ultimoLC,num);
					servicio(temp);
					PAUSE;
				}
				ret = stricmp(comando,"ADDlista");
				if(ret == 0)
				{
					fscanf(inst,"%d",&temp->dato);
					nuevo = temp;
					AgregarL(&lista,&nuevo);
					servicio(temp);
					PAUSE;
				}
				ret = stricmp(comando,"POPcola");
				if(ret == 0)
				{
					temp = POP_cola(&cabeza,&ultimoC);
					servicio(temp);
					PAUSE;
					free(temp);
				}
				ret = stricmp(comando,"POPpila");
				if(ret == 0)
				{
					temp = POP_pila(&pila);
					servicio(temp);
					PAUSE;
					free(temp);
				}
				ret = stricmp(comando,"DELETElista");
				if(ret == 0)
				{
					fscanf(inst,"%d",&num);
					temp = EliminarL(&lista,num);
					servicio(temp);
					PAUSE;
					free(temp);
				}
				ret = stricmp(comando,"EXIT");
				if(ret == 0)
				{
					fclose(inst);
					break;
				}
			}
		//	fclose(inst);
		//	PAUSE;

		break;	//case 1

		case 0: 
		
			while(pila)
			{
				temp = pila;
				pila = temp->sig;
				servicio(temp);
				free(temp);
			}				
			while(cabeza)
			{
				temp = cabeza;
				cabeza = temp->sig;
				servicio(temp);
				free(temp);
			}
			while(lista)
			{
			temp = lista;
			lista = temp->sig;
			servicio(temp);
			free(temp);
			}
			while(listaLC != ultimoLC)
			{
				temp = listaLC;
				listaLC = temp->sig;
				servicio(temp);
				free(temp);
			}
			if(listaLC)
			{
				temp = listaLC;
				servicio(temp);
				free(temp);
			}
			while(listaLD)
			{
				tempD = listaLD;
				listaLD = tempD->nex;
				servicioD(tempD);
				free(tempD);
			}
			if(listaLDC)
			{
				do
				{
					tempD = listaLDC;
					listaLDC = tempD->nex;
					servicioD(tempD);
					free(tempD);				
				}while(tempD->dat != listaLDC->dat);
			}
			break;	//case 0
		}
	}while(op!=0);

}