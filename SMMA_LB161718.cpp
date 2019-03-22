/*Manuel Alejandro Sahagun Mendoza 349857
Arobles binarios AVl
03 diciembre 2017
SMMA LB16,17,18*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/// FE = hD-hI
/// Estructura para usar e
typedef struct _tarbolAVL
{
    int dato;
    struct _tarbolAVL *der;
    struct _tarbolAVL *izq;
    struct _tarbolAVL *pad;
    int hI;
    int hD;
    int FE;

}TarbolAVL;

typedef TarbolAVL *TAVLtree;

void Menu();
void Flash(TAVLtree *nodo,TAVLtree padre);
TAVLtree Agregar(TAVLtree *raiz, TAVLtree *nuevo);
void Flash(TAVLtree *nodo,TAVLtree padre);
void DesplegarP(TAVLtree raiz);
TAVLtree FEquilibrio(TAVLtree *);
void Libera(TAVLtree *temp);
TAVLtree BuscarAVL(TAVLtree raiz, int num);
TAVLtree GenDatos();
void DesplegarAVL(TAVLtree raiz);
void Balanceo(TAVLtree *_nodo);
void InOrden(TAVLtree temp);
void PreOrden(TAVLtree temp);
void PosOrden(TAVLtree temp);
void ServicioAVL(TAVLtree temp);
void RSD(TAVLtree *nodo);
void RSI(TAVLtree *nodo);

int main()
{
    Menu();
    return 0;
}

void Menu()
{
    int op,num;
    TAVLtree nuevo = NULL;
    TAVLtree temp = NULL;
    TAVLtree raiz = NULL;

    do
    {
        system("cls");
        printf("MENU");
        printf("\n1.-Agregar");
        printf("\n2.-Eliminar");
        printf("\n3.-Buscar");
        printf("\n4.-Desplegar");
        printf("\n0.-Salir");
        printf("\n Elige una opcion: ");
        scanf("%d",&op);
        switch(op)
        {
        case 1 :
            nuevo = GenDatos();
            temp = Agregar(&raiz,&nuevo);
            if(temp)
            {
                printf("\nDato repetido [%d]",temp->dato);
            }
            else
            {
                printf("\nDato agregado\n");	
            }
			system("pause");
            break;
		case 2:
			system("cls");
			printf("\nUnder Construction...\n");
			system("pause");
			break;
		case 3: 
			system("cls");
			printf("Ingrese el numero que desea buscar\n");
			scanf("%d",&num);
			temp = BuscarAVL(raiz,num);
			if(!temp)
			{
				printf("\nNumero no encontrado\n");
			}
			else
			{
				printf("\nNumero encontrado [%d]\n",temp->dato);
			}
			system("pause");
			break;
		case 4: DesplegarAVL(raiz); break;
		case 0: 
			if(raiz)
				Libera(&raiz);
			break;

        }

    }while(op!=0);
}

TAVLtree Agregar(TAVLtree *raiz, TAVLtree *nuevo)
{
    TAVLtree temp = NULL, scout = NULL;
    int i = 0;

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
				scout = scout->der;
			}
			else
			{
				scout = scout->izq;
			}
			i++;

		}
		(*nuevo)->pad = temp;
		if((*nuevo)->dato > temp->dato)
		{
			temp->der = *nuevo;
			Balanceo(&*nuevo);
		}
		else
		{
			temp->izq = *nuevo;
			Balanceo(&*nuevo);
		}

	}
	return scout=NULL;
}
/// Funcion para cacular el factor de equilibrio (recalcula el FE)
TAVLtree FEquilibrio(TAVLtree *nuevo)
{
    int i=0;
    TAVLtree temp = NULL;
    TAVLtree padre = NULL;
    padre = (*nuevo)->pad;
    temp = *nuevo;

    do
    {

        if( padre->dato > temp->dato)
        {
            (padre)->hI++;
        }
        else
        {
            (padre)->hD++;
        }

        temp = temp->pad;
        temp->FE = temp->hD - temp->hI;

        if(abs(temp->FE) == 2)
        {
            return temp;
        }

        i++;
    }while(temp->pad != NULL && i<3);

    return temp;
}
/// Funcion para generar datos
TAVLtree GenDatos()
{
	int x;
	TAVLtree temp = NULL;
	temp = (TAVLtree)malloc(sizeof(TarbolAVL));

	temp->pad = NULL;
	temp->der = NULL;
	temp->izq = NULL;
	temp->FE = 0;
	temp->hI = 0;
	temp->hD = 0;
	//x =rand()%100;
	printf("Ingrese un numero entero: ");
	scanf("%d",&x);
	temp->dato = x;
	return temp;
}
/// Funcion de flash
void Flash(TAVLtree *nodo,TAVLtree padre)   ///el segundo parametro puede ser NULL dependiendo del tipo de flaseho
{                                           ///que nececitemos
    (*nodo)->pad = padre;
    (*nodo)->der = NULL;
    (*nodo)->izq = NULL;
    (*nodo)->hI = 0;
    (*nodo)->hD = 0;
    (*nodo)->FE = 0;
}
/// Rotacion simple a la derecha
void RSD(TAVLtree *nodo)
{
    TAVLtree temp = (*nodo)->izq;
	TAVLtree padre = (*nodo)->pad;

	if(padre)
		padre->izq = temp;
	temp->pad = padre;
	temp->der = *nodo;
    Flash(&*nodo,temp);
    FEquilibrio(&temp);



}
/// Rotacion simple a la izquierda
void RSI(TAVLtree *nodo)
{
    TAVLtree temp = (*nodo)->der;
    TAVLtree padre = (*nodo)->pad;
	
	if(padre)	 
		padre->der = temp;
    temp->pad = padre;
    temp->izq = *nodo;
    Flash(&*nodo,temp);
    FEquilibrio(&temp);
}
/// Funcion para balancear el arbol
void Balanceo(TAVLtree *_nodo)
{
    TAVLtree temp = NULL,nodo = NULL,ndoiz = NULL,ndoder = NULL;
    nodo = *_nodo;
    temp = FEquilibrio(&nodo);
    nodo = temp;
    ndoiz = nodo->izq;
    ndoder = nodo->der;

    if(nodo)
    {
        if(nodo->FE == -2 && ndoiz->FE == -1)
        {
            RSD(&nodo);
        }
        if(nodo->FE == 2 && ndoder->FE == 1)
        {
            RSI(&nodo);
        }
        if(nodo->FE == -2 && ndoder->FE == 1)
        {
            RSI(&nodo->izq);
            RSD(&nodo);
        }
        if(nodo->FE == 2 && ndoiz->FE == -1)
        {
            RSD(&nodo->der);
            RSI(&nodo);
        }

    }
}
///Funcion para dar servicio al nodo
void ServicioAVL(TAVLtree temp)
{
	printf("-----------------------------------\n");
	printf("DATO -> [%d]\n",temp->dato);
	printf("-----------------------------------\n");
}
///Funcion para buscar nodos
TAVLtree BuscarAVL(TAVLtree raiz, int num)
{
	TAVLtree temp=raiz;
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
///Funcion InOrden
void InOrden(TAVLtree temp)
{
	if(temp->izq)
	{
		InOrden(temp->izq);
	}

	ServicioAVL(temp);
	system("pause");

	if(temp->der)
	{
		InOrden(temp->der);
	}
}
///Funcion PosOrden
void PosOrden(TAVLtree temp)
{
	if(temp->izq)
	{
		PosOrden(temp->izq);
	}

	if(temp->der)
	{
		PosOrden(temp->der);
	}

	ServicioAVL(temp);
	system("pause");
}
///Funcion PreOrden
void PreOrden(TAVLtree temp)
{
	ServicioAVL(temp);

	if(temp->izq)
	{
		PreOrden(temp->izq);
	}

	if(temp->der)
	{
		PreOrden(temp->der);
	}
	system("pause");
}
///Funcion para Desplegar datos
void DesplegarAVL(TAVLtree raiz)
{
	int op;
	TAVLtree temp = NULL;

	if(raiz)
	{
		temp = raiz;
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
///Limpiar arbol
void Libera(TAVLtree *temp)
{
	TAVLtree _temp = *temp;
	if(_temp->izq)
	{
		Libera(&_temp->izq);
	}

	if(_temp->der)
	{
		Libera(&_temp->der);
	}
	ServicioAVL(_temp);
	free(_temp);
}