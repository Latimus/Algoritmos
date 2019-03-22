//Manuel Alejandro Sahagun Mendoza 349857
//Colas 01 B
//25 agosto 2017
//SMMA_L03

//Librerias incluidas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Definicion de constantes
#define N 500

//Tipo dato basico generico
typedef struct _tdato{
	
	int numt;
	char nombre[100];
	int sexo;
	int edad;
	struct _tdato *sig;	

}Tdato;

typedef Tdato *Tnodo;

//Prototipos de funciones

void menu();
Tnodo GenDatos(int *p,int v[]);
void PUSH_COLA(Tnodo *cabeza,Tnodo *ultimo,Tnodo *nuevo);
Tnodo POP_COLA(Tnodo *cabeza,Tnodo *ultimo);
void servicio_cola(Tnodo temp);
int numero(int *pos,int vec[]);
char *randomNames(int x);
int age();


//Funcion principal
int main(int argc, char *argv[]) {
	
	menu();

	return 0;
}

//Funcion de menu
void menu (){
	
	int op;
	int p=0;
	int v[N];
	 
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
					nuevo = GenDatos(&p,v);
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
//Manda llamar las demas funciones que generan datos para meter en la cola
Tnodo GenDatos(int *p,int v[]) {
	
	int y,x,t,e;
	char nomb[100];
	Tnodo temp = NULL;
	temp = (Tnodo)malloc(sizeof(Tdato));
	
	temp->sig = NULL;
	t = numero(&*p,&*v);
	temp->numt = t;		//matricula del alumno
	
	x = (1 + (rand() % 2) - 1);	//Variable aleatoria para elegir sexo
	temp->sexo = x;	
		
	strcpy(nomb,randomNames(x));
	strcpy(temp->nombre,nomb);
	
	e = age();
	temp->edad = e,
	//x =rand()%100;
	/*temp->tipo de dato = y	*/
				/*Meter los datos por medio de "GenDatos" con cada tipo	/
										/de dato de la estructura, mandar llamar las demas 		 	/
										/funciones dentro de esta...													 */					
	
	printf("\n\nALUMNO AGREGADO -> ");
	printf("\n\nMatricula: \t\t\t[%d]",temp->numt);
	printf("\nNombre: \t\t\t[%s]",temp->nombre);
	printf("\nEdad: \t\t\t\t[%d]",temp->edad);
	printf("\nSexo(1.-Hombre\t2.-Mujer): \t[%d]\n\n",temp->sexo);
	system("pause");
	return temp;	
}

//Agregar datos a la cola
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

//Quitar datos de la cola
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

//Da servicio a la cola
void servicio_cola(Tnodo temp) {

	system("cls");
	printf("-----------------------------------\n");
	printf("\nALUMNO BORRADO -> ");
	printf("\n\nMatricula: \t\t\t[%d]",temp->numt);
	printf("\nNombre: \t\t\t[%s]",temp->nombre);
	printf("\nEdad: \t\t\t\t[%d]",temp->edad);
	printf("\nSexo(1.-Hombre\t2.-Mujer): \t[%d]",temp->sexo);
	printf("\n-----------------------------------\n");
	system("pause");
}

//Funcion que genera matriculas Aleatorias
int numero(int *pos,int vec[]) {
		
		int x,i,j,dup,p=*pos;
	
		for(i=0; i<=(*pos); i++) 	//hacemos un bucle para generar numeros aleatorios
			{					//sin repetir
				x = (rand()% 299) + 1;	//numero aleatorio entre 1 y 300
				dup = 0;
				 
				for(j=0; j<=i; j++) {
					if(x == vec[j])	//Condicion para verificar el duplucado
						{					//Si se duplica la bandera cambia de estado
							dup = 1;
						}
					}
					if(dup == 1)			//Cuando la bandera esta en "1" disminuye
						{						//el contador del bucle para generar
							i--;				//un nuevo numero
						}
						else					//Si no, el numero es depositado en el 
						{						//apartado de la estructura de numero del 
							vec[i] = x;	//trabajador
						}
			}		
		(p) = 1 + (p);	//Aumentamos el contador en 1 para avanzar en el arreglo
		(*pos) = p;    //Asiganmos el nuevo valor del contador al contador original
		return x;
}

//Funcion que genera nombres y apellidos aleatorios
char *randomNames(int x) {
	int  r = 0;
	//p = *pos;	//Depositamos el contador en una variable 
	char name[100];
	char nom[20][10] = 	//Nombres Masculinos
		{"MANUEL ","CARLOS ","FERMIN ","FEDE ","LUIS ",
		"JOSE ","ANTONIO ","SANDRO ","MARIO ","LUCIO ","DANIEL ","LORENZO ",
		"PEDRO ","ANGEL ","FABIAN ","GIBRAN ","ELVER ","IGNACIO ","MARTIN ",
		"FENRI "};
	char nomf[20][10] = //Nombres Femeninos
		{"MIRANDA ","SANDRA ","MARIA ","LUCIA ","DIANA ",
		"MARLA ","CHUNLI ","KARLA ","JOSEFA ","ANTONIA ","DANIELA ","LORE ",
		"PETRA ","ANGELA ","PAMELA ","LAURA ","KATIA ","SAMIS ","ANALU ",
		"KAREN "};

	char apep[20][10] = 	//Apellidos
		{ "MENDOZA ","MEJIA ","CHUPI ","ESPARZA ","CARRIL ","MONAREZ ","GARCIA ",
		"CADENA ","PEREZ ","CRUZ ","CHICO ","SANCHEZ ","RAMIREZ ","MONTES ","SANCHEZ ",
		"PEREZ ","CURIEL ","ZERTUS ","GOMEZ ","VARGAS "};
		
	char apem[20][10] = 		//Apellidos
		{ "SAHAGUN","ARGAEZ","PEREZ","HENDO","MOXCA",
		"GONZALO","GUINO","CAROL","GUERRA","MONTES","CHUNLI","PARRA","CARDES",
		"RAMIR","VARGAS","TELLEZ","FOLGI","ODIN","PARKER","HERNANDEZ"};
		
		
		r = (1 + (rand() % 20) - 1);	//Seleccion de nombres aleatorios
		if (x == 1) {	// Si "x" es igual a "1" el nombre sera masculino
			strcpy(name,nom[r]);	//la estructura recibe el nombre

		}
		else {			// Si "x" es igual a "2" el nombre sera femenino
			strcpy(name,nomf[r]);

		}
		
		r = (rand() % 20); //Elegimos un apellido
		strcat(name,apep[r]); 	//El apartado de la estructura 
											//recibe el apellido
		
		r = (rand() % 20);		//Elige un apellido aleatorio
		strcat(name,apem[r]);	//Se deposita el apellido en el 
											//apartado de la estructura
		return name;
}

//Funcion que genera edades aleatorias
int age() {
	int x;
	
	x = (18 + rand()% 47);		//Edades aleatorias entre 18 y 65 años
	return x;

}

