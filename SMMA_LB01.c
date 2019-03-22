//Manuel Alejandro Sahagun Mendoza 349857
//Estructura con datos basicos del trabajador Arreglos y Archivos de Texto
//19 Mayo 2017
//SMMA_LB01
///////////////////////////////////////////////////////////////////////////////
					//Librerias utilizadas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/////////////////////////////////////////////////////////////////////////////
					//Variables definidas
#define N 300					//Definimos el tamaño del vector
#define C 10					//Definimos la cantidad de registros por tipeo

typedef struct _tdato {			//Estructura con los datos basicos
	int numt;					//del trabajador
	char nombre[10];
	char apellidoP[10];
	char apellidoM[10];
	int sexo;
	int edad; 
	} Tdat;
///////////////////////////////////////////////////////////////////////////////
				//Lista de prototipos
void numero(int *pos,Tdat *vec);
void randomNames(int *pos,Tdat *vec);
void randapePat(int *pos,Tdat *vec);
void randapeMat(int *pos,Tdat *vec);
void age(int *pos, Tdat *vec);
void programa1(int *pos,Tdat *V1);
void programa2(int *pos,Tdat *V1);				
void programa3(int *pos,Tdat *V1);
void programa4(int *pos,Tdat *V1);
void programa5(int *pos,Tdat *V1);
int programa6();

void menu(void);					//Funcion del MENU
///////////////////////////////////////////////////////////////////////////////
int main(int argc, char *argv[]) {	//Funcion principal

	menu();				//Mandamos llamar la funcion del MENU
	return 0;
}

void menu(void) {					//MENU
	
	Tdat V1[N],VAUX[N];				//Creamos un vector y otro auxiliar con 
									//los tipos de datos de la estructura Tdat
	int op,POS=0;		//Iniciamos un contador llamado PO para determinar las
  						//posiciones de los datos del vector y un operador para
	do{					//el menu
		system ("cls");				//Limpia pantalla
		printf("\n    M  E   N   U\n");	//Lista de funciones
		printf("\n1.- Agregar(10)");
		printf("\n2.- Buscar");
		printf("\n3.- Ordenar");
		printf("\n4.- Archivo de Texto");
		printf("\n5.- Imprimir Arreglo");
		printf("\n6.- Imprimir Archivo de Texto");
		printf("\n0.- SALIR");
	    printf("\n\n ...ESCOGE UNA OPCION...\n\n :");
        scanf ("%d",&op);	//Lectura de seleccion 
		switch(op)
	    	{
		  		case 1: programa1(&POS,&*V1);  break;
				case 2: programa2(&POS,&*V1);  break;
		  		case 3: programa3(&POS,&*V1);  break;
		  		case 4: programa4(&POS,&*V1);  break;
		  		case 5: programa5(&POS,&*V1);  break;
		  		case 6: programa6();  break;
			}
   	}while(op != 0); //Salir cuando el usuario presione "cero"
}

//Funcion que genera un numero de trabajador aleatorio (Sin repetir)
void numero(int *pos,Tdat *vec) {
	int x,i,j,dup,p;
	p = *pos;	//Depositamos el contador en una variable
	
	for(i=0; i<=(p); i++) 	//hacemos un bucle para generar numeros aleatorios
		{					//sin repetir
			x = (rand()% 299) + 1;	//numero aleatorio entre 1 y 300
			dup = 0; 
			for(j=0; j<=i; j++) {
				if(x == vec[j].numt)	//Condicion para verificar el duplucado
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
				vec[i].numt = x;	//trabajador
			}
		}	
}

//Funcion que genera nombres aleatorios
void randomNames(int *pos,Tdat *vec) {
	int x = 0, r = 0, i,p;
	p = *pos;	//Depositamos el contador en una variable 

	char nom[20][10] = 	//Nombres Masculinos
		{"MANUEL","CARLOS","FERMIN","FEDE","LUIS",
		"JOSE","ANTONIO","SANDRO","MARIO","LUCIO","DANIEL","LORENZO",
		"PEDRO","ANGEL","FABIAN","GIBRAN","ELVER","IGNACIO","MARTIN",
		"FENRI"};
	char nomf[20][10] = //Nombres Femeninos
		{"MIRANDA","SANDRA","MARIA","LUCIA","DIANA",
		"MARLA","CHUNLI","KARLA","JOSEFA","ANTONIA","DANIELA","LORE",
		"PETRA","ANGELA","PAMELA","LAURA","KATIA","SAMIS","ANALU",
		"KAREN"};


		x = (1 + (rand() % 2) - 1);		//Variable aleatoria para elegir sexo
		r = (1 + (rand() % 20) - 1);	//Seleccion de nombres aleatorios
		if (x == 1) {	// Si "x" es igual a "1" el nombre sera masculino
			strcpy(vec[p].nombre,nom[r]);	//la estructura recibe el nombre
			vec[p].sexo = 1;	//Le asiganmos un "1" para diferenciar genero
		}
		else {			// Si "x" es igual a "2" el nombre sera femenino
			strcpy(vec[p].nombre,nomf[r]);
			vec[p].sexo = 2;	//Diferenciar de genero
		}
}

//Funcion que genera apellidos paternos aleatorios
void randapePat(int *pos,Tdat *vec) {
	int x,i,p;
	p = *pos;		//Depositamos el contador en una variable
	char apep[20][10] = 	//Apellidos
		{ "MENDOZA","MEJIA","CHUPI","ESPARZA","CARRIL","MONAREZ","GARCIA",
		"CADENA","PEREZ","CRUZ","CHICO","SANCHEZ","RAMIREZ","MONTES","SANCHEZ",
		"PEREZ","CURIEL","ZERTUS","GOMEZ","VARGAS"};
		
		x = (rand() % 20); //Elegimos un apellido
		strcpy(vec[p].apellidoP,apep[x]); 	//El apartado de la estructura 
											//recibe el apellido

}

//Funcion que genera apellidos maternos aleatorios
void randapeMat(int *pos,Tdat *vec) {
	int x,p,i;
	p = *pos;		//Depositamos el contador en una variable
	char apem[20][10] = 		//Apellidos
		{ "SAHAGUN","ARGAEZ","PEREZ","HENDO","MOXCA",
		"GONZALO","GUINO","CAROL","GUERRA","MONTES","CHUNLI","PARRA","CARDES",
		"RAMIR","VARGAS","TELLEZ","FOLGI","ODIN","PARKER","HERNANDEZ"};
	
		x = (rand() % 20);		//Elige un apellido aleatorio
		strcpy(vec[p].apellidoM,apem[x]);	//Se deposita el apellido en el 
											//apartado de la estructura
}

//Funcion que genera edades entre 18 y 65 años
void age(int *pos, Tdat *vec) {
	int x,p;
	p = *pos;		//Depositamos el contador en una variable
	x = (18 + rand()% 47);		//Edades aleatorias entre 18 y 65 años
	vec[p].edad = x;		//Depositamos la edad en la estructura
	(p) = 1 + (p);	//Aumentamos el contador en 1 para avanzar en el arreglo
	(*pos) = p;    //Asiganmos el nuevo valor del contador al contador original
}

/////////////////////////////////////////Lista de programas
void programa1(int *pos,Tdat *V1) {
	system("cls");
	
	Tdat vec[N];				//Vector Auxiliar
	int X=(*pos),i;  			//Contador para ubicar la posicion del vector
	
	for(i=(0); i<C; i++) {
		numero(&X,&*vec);		//Asiganmos un numero de empleado
		randomNames(&X,&*vec);	//Nombre Aleatorio
		randapePat(&X,&*vec);	//Apellido Paterno Aleatorio
		randapeMat(&X,&*vec);	//Apellido Materno Aleatorio
		age(&X,&*vec);			//Edad del trabajador
		/*Se manda un contador a cada funcion que dice en que posicion del 
		se encuentran*/
		V1[i+*pos] = vec[i+*pos]; 	/*Se adelanta la posicion en ambos vectores	
									para almacenar los datos en el lugar
									correcto*/
	}
	*pos = (*pos) + C;			//Aumentamos el contadore en 10 
	printf("\tSe han agregado 10 registros al arreglo\n");
	//printf("%d",X); 	//-->>	//Imprime la cantidad de datos que contiene el
	system("pause");			//Vector
}

void programa2(int *pos,Tdat *V1) {
	system("cls");
	int i,ubicado = 0,num;
	
	printf("\n Ingrese el numero de trabajador que desea buscar: ");
	scanf("%d",&num); 		//Leemos el numero seleccionado por el usuario
	
	for(i=0; i<(*pos); i++)		//Bucle para buscar en cada posicion 
		{
			if(V1[i].numt == num) 	//Si el numero de trabajador es igual al 
				{					//solicitado, imprime los datos
					ubicado  = 1;	//La bandera cambia de estado
					printf("\nMatricula:\t\t%d\n",V1[i].numt);
					printf("Nombre:\t\t\t%s\n",V1[i].nombre);
					printf("Apellido Paterno:\t%s\n",V1[i].apellidoP);
					printf("Apellido Materno:\t%s\n",V1[i].apellidoM);
					printf("(1:Hombre,2:Mujer):\t%d\n",V1[i].sexo);
				}
			}
			if(ubicado == 0)	//Si la bandera no cambia entonces el numero	
				{				//no se encuentra en el arreglo, imprimimos
					printf("El numero no se encuentra en el vector\n");
				}
	system("pause");
}

void programa3(int *pos,Tdat *V1) {
	
	int tem,i,j;
			//Ordenamiento por burbuja
	for(i=1; i<(*pos); i++)
		{
			for(j=0; j<(*pos-i); j++)
				{
					if(V1[j].numt > V1[j+1].numt)  	//Si el numero acutal es
						{					//mayor al siguiente se realiza
							tem = V1[j].numt;	//el intercambio
							V1[j].numt = V1[j+1].numt;
							V1[j+1].numt = tem;
						}
				}
		}
	printf("Los datos ahora estan ordenados de menor a mayor...\n");	
	system("pause");
}

void programa4(int *pos,Tdat *V1) { 
	system("cls");
	FILE *arch = NULL;		//Creamos el fichero
	Tdat reg,v[N];			//Variable para depositar el arreglo con el formato
							// de la estructura
	int i;
	
	arch = fopen("Datos.txt","w");	//Abrimos el archivo de texto
	
	for(i=0; i<(*pos); i++)	//Bucle para recorrer el vector
		{
			reg = V1[i];		//deposita los datos del vector en la variable
			fprintf(arch,"%s %s %s %d %d %d\n",reg.nombre,
			reg.apellidoP,reg.apellidoM,reg.sexo,reg.edad,reg.numt);
		}//
		
		fclose(arch);		//Cierra el archivo de texto
		printf("Se ha generado un archivo de texto...\n");
		system("pause");
}

void programa5(int *pos,Tdat *V1) {
	system("cls");
	int i,x;
	x = *pos; 				//Deposita la posicion en una variable
							//esta posicion es el total de datos del arreglo
	for(i=0; i<(x); i++) 
		{		//Se imprimen los datos del arreglo estructurado
			printf("\nNumero de trabajador: \t%d",V1[i].numt);
			printf("\nNombre: \t\t%s\n",V1[i].nombre);
			printf("Apellido Paterno: \t%s\n",V1[i].apellidoP);
			printf("Apellido Materno: \t%s\n",V1[i].apellidoM);
			printf("Sexo (1=Homre,2=Mujer): %d\n",V1[i].sexo);
			printf("Edad: \t\t\t%d\n",V1[i].edad);			
		}
		system("pause");	
}

int programa6() {
	system("cls");
	FILE *arch = NULL; 	//Iniciamos un archivo tipo puntero
	Tdat reg,v[N];		//variables para depositar los datos del archivo
	int i=0, j, k=0;	//contadores que se utilizaran
	
	arch = fopen("Datos.txt","r"); 		//Abre el archivo de texto
	if(arch == NULL) 		//si no se encuentra o no existe muestra el 
	{						//el siguiente mensaje
		system("cls");
		printf("El archivo no se encuentra o no existe...\n\n");	
		system("pause");
		return -1;
	}
	
	rewind(arch);		//se regresa el puntero a la posicion inicial del 	
						//archivo de texto
	while(!feof(arch))
		{			//usamos un bucle para leer los datos del archivo
			fscanf(arch,"%s %s %s %d %d %d\n",reg.nombre,reg.apellidoM,
			reg.apellidoP,&reg.sexo,&reg.edad,&reg.numt);
			v[i++] = reg;		//se depositan los datos en el arreglo de tipo
		}						//"Tdat"

	printf("\tDatos del trabajador: \n\n"); //Encabezado
	for(j=0; j<i; j++)
	{			//imprime los datos de los trabajadores
		printf("\nNumero de trabador:\t%d\n",v[j].numt);
		printf("Nombre:\t\t\t%s\n",v[j].nombre);
		printf("Apellido Paterno:\t%s\n",v[j].apellidoP);
		printf("Apellido Materno:\t%s\n",v[j].apellidoM);
		printf("(1:Hombre,2:Mujer):\t%d\n",v[j].sexo);
		printf("Edad: \t\t\t%d\n",v[j].edad);				
	}
	fclose(arch);		//cerramos el archivo
	system("pause");
}

