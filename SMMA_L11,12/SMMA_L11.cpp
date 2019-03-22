//Manuel Alejandro Sahagun Mendoza 349857
//Tablas Hash con archivos binarios
//3 noviembre 2017
//SMMA_L11


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define TAM 35001 //tamaño del vector


typedef struct curp {
	char al[1];		//primera letra de apellido paterno
	char av[1];		//primera vocarl de apellido paterno
	char am[1];		//primera letra deapellido materno
	char no[1];		//primera letra de nombre
	char a[2];		//año
	char m[2];		//mes
	char d[2];		//dia
	char sex[1];	//genero
	char edo[2];	//entidad federativa
	char conp[1];	//consonante paterna
	char conm[1];	//consonante maternnna
	char conN[1];	//consonante nombre
	char ho[1];		//digito homogeneo
	char h2[1];		//digito homogeneo
} Cdat;

typedef struct alumno{
	Cdat CRP;
	int status;
	int sexo;
	long matricula;
	char nombre[10];
	char apellidoP[10];
	char apellidoM[10];
	char day[3];
	char month[3];
	char year[4];
	char estado[2];

} Tdat;

typedef struct _tdato{
	long dato;
	long index;
	struct _tdato *sig;
}Tdato; //Estructura del nodo, [dato/*sig]

typedef Tdato *Tnodo;
Tnodo hash[TAM];
Tdat lebin;
long k=1; 	//contador de registros

//son del tipo puntero
//prototipos de funciones
void menu(float reloj);
int LEBIN();
Tnodo GenDatos();
void PUSH_pila(Tnodo *hash, Tnodo *nuevo);
Tnodo Buscar(Tnodo hash, long buscar);
Tnodo Eliminar(Tnodo *lista,long valor);
int Estadisticas(Tnodo hash);
Tnodo POP_nodo(Tnodo *hash);
void servicio(Tnodo temp);
void statu(Tdat *aux);
void genmat(Tdat *aux);
void randomNames(Tdat *aux);
void randapePat(Tdat *aux);
void randapeMat(Tdat *aux);
void nacimiento(Tdat *aux);
void estad(Tdat *aux);
void creacurp(Tdat *aux);

int main(){

	long x;
	float reloj;

	clock_t start=clock();
  x = LEBIN();
	if(x < 0)
	{
			printf("\n El arvhico no existe o no se encuentra...\n");
			system("pause");
	}
	
	reloj = ((double)clock() - start) / CLOCKS_PER_SEC;
	menu(reloj);

return 0;
}

void menu(float reloj){

	int 	op; //operador del switch
	long	buscar=0; //variable para buscar en la funcion de Buscar() y Eliminar()
	long	residuo=0; //variable para recojer el dato del modulo de "k"%TAM
	long	i=0; //contador para ciclo for en case: 4
	long	j=0; //variable para recibir el numero de datos que contiene cada indice en el case:4
	long  binlong;
	
	FILE *arch = NULL;
	Tdat aux;

	Tnodo temp = NULL;
	Tnodo nuevo = NULL;
	Tnodo pila = NULL; //se meten los datos en forma de pila

	  do{
      system ("cls");
      printf("%d Registros Cargados\n",k);
      printf("\n 	M  E   N   U\n");
	 	 	printf("\n1.- Agregar");
	 	 	printf("\n2.- Buscar y conteo");
	 	 	printf("\n3.- Eliminar\n");
			printf("\n	E S T A D I S T I C A S\n");
			printf("\n4.- Visualizar Nodos");
	 	 	printf("\n5.- Tiempo de carga");
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

				arch = fopen("Datos.dat","rb");
				if(arch == NULL)
				{
					printf("El archivo no se encuentra o no existe...\n\n");
					system("pause");
					break;
				}
				binlong = temp->index;
				fread(&lebin,sizeof(Tdat)*binlong,1,arch);
				
				printf("(Acitvo:1,Inactivo:0):\t%d\n",lebin.status);
				printf("Matricula:\t\t%d\n",lebin.matricula);
				printf("Nombre:\t\t\t%s\n",lebin.nombre);
				printf("Apellido Paterno:\t%s\n",lebin.apellidoP);
				printf("Apellido Materno:\t%s\n",lebin.apellidoM);
				printf("Fecha de Nacimiento:\t%s ",lebin.day);
				printf("%s ",lebin.month);
				printf("%s \n",lebin.year);
				printf("(1:Hombre,2:Mujer):\t%d\n",lebin.sexo);
				printf("Lugar de nacimiento:\t%s\n\n\n",lebin.estado);
				printf("CURP: %s\n\n",
				lebin.CRP.al, lebin.CRP.av, lebin.CRP.am, lebin.CRP.no, lebin.CRP.a,
				lebin.CRP.m, lebin.CRP.d, lebin.CRP.sex, lebin.CRP.edo, lebin.CRP.conp,
				lebin.CRP.conm, lebin.CRP.conN, lebin.CRP.ho, lebin.CRP.h2);
				//printf("\n%d\n",ftell(arch));
				


			}
			else //si el temporal tiene un NULL, entonces no encontro el dato 
			{
				printf("El elemento [%d] no se encuentra...\n",buscar);
			}
			fclose(arch);
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
			 
		 case 5:
		 	system("cls");
		 	
		 	printf("\nTiempo transcurrido: %f Segundos",reloj);
		 	
		 	system("pause");
		 	break;
		 case 0:
			 system("cls");
			 printf("Liberando Memoria\n");
			  clock_t start = clock();
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
			printf("Tiempo transcurrido: %f segundos",((double)clock()-start)/CLOCKS_PER_SEC);

			system("pause");
		  break;
		}
   }while(op != 0);
}

Tnodo GenDatos(){
	
	int x=0;
	Tnodo temp = NULL;
	Tdat aux;
	FILE *arch = NULL;

	
	temp = (Tnodo)malloc(sizeof(Tdato)); //reservamos el espacio de memoria de la estructura Tdato
	temp->sig = NULL; //nos aseguramos que el nodo generado no apunte a ningun lado
	statu(&aux);
	genmat(&aux);
	randomNames(&aux);
	randapePat(&aux);
	randapeMat(&aux);
	nacimiento(&aux);
	estad(&aux);
	creacurp(&aux);
	temp->dato = aux.matricula;
	temp->index = k++;

	arch = fopen("Datos.dat","ab+");
	fwrite(&aux,sizeof(Tdat),1,arch);
	fclose(arch);

	//printf("Ingrese un dato: "); //si se desea añadir datos manualmente
	//scanf("%d",&x);
	//x=(rand()%100)+1; // si se desea añadir datos aleatoriamente
	//temp->dato = x; //asignamos el nuevo dato al nodo [x/*]

	return temp;
}

void PUSH_pila(Tnodo *hash, Tnodo *nuevo){
	
	(*nuevo)->sig = *hash; 
	*hash = *nuevo; 
	*nuevo = NULL;
}

Tnodo Buscar(Tnodo hash,long buscar){
	Tnodo temp = NULL,nodo = NULL;
	long m = 1;
	if(hash)
	{
		temp = hash;
		while(temp->sig && temp->dato != buscar)
		{
			temp=temp->sig;
			m++;
		}
		if(temp->dato == buscar)
		{
			printf("\t\n\n[%d] Saltos al buscar el nodo\n\n",m);
			return temp;
		}
	}
	return nodo;
}

Tnodo Eliminar(Tnodo *lista,long valor){
	
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

void servicio(Tnodo temp){

	printf("-----------------------------------\n");
	printf("DATO -> [%d]\n",temp->dato);
	printf("-----------------------------------\n");
	
}

int LEBIN(){
	FILE *arch = NULL;
	Tdat rag;
	Tnodo temp = NULL;
	long residuo;
	long i=0,j;

	arch = fopen("Datos.dat","rb");
	if(arch == NULL)
	{
		printf("El archivo no se encuentra o no existe...\n\n");
		return -1;
	}

	fseek(arch,0,SEEK_SET);

	while(!(feof(arch)))
	{
		temp = NULL;
		temp = (Tnodo)malloc(sizeof(Tdato));
		temp->sig = NULL;
		temp->index = k++;
		fread(&rag,sizeof(Tdat),1,arch);
		residuo = rag.matricula%TAM;
		temp->dato = rag.matricula;
		PUSH_pila(&hash[residuo],&temp);
	}
	
	fclose(arch);
}

//Funcion que agrega un status = 1 al registro
void statu(Tdat *aux){

	aux->status = 1;
}

//Funcion que genera Matriculas aleatorias sin repetir
void genmat(Tdat *aux){
	long i, j, dup;
	long ale,und;

		und = ((rand() % 30000) + 1);
		ale = (300000 + rand() % 333999);
		ale = ale +und;
		

			aux->matricula = ale;

		
}

//Funcion que genera nombres aleatorios
void randomNames(Tdat *aux){
	int x, r = 0;

	char nom[20][10] = {"MANUEL","CARLOS","FERMIN","FEDE","LUIS",
	"JOSE","ANTONIO","SANDRO","MARIO","LUCIO","DANIEL","LOGAN",
	"PEDRO","ANGEL","FABIO","FABIAN","ELVER","NACHO","MARTIN",
	"FERNI"};
	char nomf[20][10] = {"MIRIS","SANDRA","MARIA","LUCIA","DIANA",
	"MARLA","CHUNLI","KARLA","ROBIN","NAMI","DANI","LORE",
	"PETRA","ANGELA","PAMELA","LAURA","KATIA","SAMIS","ANALU","KAREN"};


		r = (rand()%20)+1;
		x = ((rand()%2));
		if(x == 1)
		{
			aux->sexo = 1;
			strcpy(aux->nombre,nom[r]);
		}
		else
		{
			strcpy(aux->nombre,nomf[r]);
	 		aux->sexo = 2;
		}
}

//Funcion que genera apellidos paternos aleatorios
void randapePat(Tdat *aux){
	int x;

	char apep[20][10] = { "MENDOZA","MEJIA","CHUPI","ESPARZA",
	"CARRIL","MONREZ","GARCIA","CARDENA","PEREZ","CRUZ","CHICO",
	"SANCHEZ","RAMIREZ","MONTES","SANCHEZ","PEREZ","CURIEL","ZERTUS",
	"GOMEZ","VARGAS" };

	  //Semilla aleatoria
		x = (rand() % 20)+1;
		strcpy(aux->apellidoP,apep[x]);
}

//Funcion que genera apellidos maternos aleatorios
void randapeMat(Tdat *aux){
	int x;

	char apem[20][10] = { "SAHAGUN","ARGAEZ","PEREZ","HENDO","MOXCA",
		"GONZALO","GUINO","CAROL","GUERRA", "MONTES","RUTA",
		"PARRA","CARDES","RAMIR","VARGAS","TELLEZ","FOGLI","ODINO",
		"PARKER","GALARGA"};

		x = (rand() % 20)+1;
		strcpy(aux->apellidoM,apem[x]);
}

//Funcioon que genera fechas de nacimiento aleatorias
void nacimiento(Tdat *aux){
    int d,m,a = 0;
    char dia[3],mes[3],anio[4];

	a = ((rand()% 12) + 1988);		//Añadimos el año

	if((a%4==0) && (a%100==0)) {	//Verificar si es bisiesto
		m = (rand()%11)+1;			//
		if(m == 2) {  				//
        	d = (rand()%28)+1;  	//
     		}						//
     	else {						//
        	d = (rand()%30)+1;  	//
    		}						//
	}								//
	else if (a%400==0)				//
	{								//
		m = (rand()%11)+1;			//
		if(m == 2) {  				// Si es bisiesto y es febrero
			d = (rand()%28)+1;  	// Febrero puede tener 29 dias...
     		}
     	else {
        	d = (rand()%30)+1;
     		}
	}
	else {
     	m = (rand()%11)+1;
     	if(m == 2) {
        d = (rand()%27)+1;
     	}
     	else {
        	d = (rand()%30)+1;
     	}
	}

	itoa(a,anio,10);
	itoa(m,mes,10);
	itoa(d,dia,10);

	strcpy(aux->year,anio);
	strcpy(aux->month,mes);
	strcpy(aux->day,dia);
}

//Funcion que5agrega5un Esta5o de la Republica
void estad(Tdat *aux){
	int E;
	char es[5];
	//srand(time(NULL));

	E = (rand()%32)+1;
	switch(E) {
		case 1: strcpy(es,"AS");  break;
		case 2: strcpy(es,"BC");  break;
		case 3: strcpy(es,"BS");  break;
		case 4: strcpy(es,"CC");  break;
		case 5: strcpy(es,"CL");  break;
		case 6: strcpy(es,"CM");  break;
		case 7: strcpy(es,"CS");  break;
		case 8: strcpy(es,"CH");  break;
		case 9: strcpy(es,"DF");  break;
		case 10: strcpy(es,"DG"); break;
		case 11: strcpy(es,"GT"); break;
		case 12: strcpy(es,"GR"); break;
		case 13: strcpy(es,"HG"); break;
		case 14: strcpy(es,"JC"); break;
		case 15: strcpy(es,"MC"); break;
		case 16: strcpy(es,"MN"); break;
		case 17: strcpy(es,"MS"); break;
		case 18: strcpy(es,"NT"); break;
		case 19: strcpy(es,"NL"); break;
		case 20: strcpy(es,"OC"); break;
		case 21: strcpy(es,"PL"); break;
		case 22: strcpy(es,"QT"); break;
		case 23: strcpy(es,"QR"); break;
		case 24: strcpy(es,"SP"); break;
		case 25: strcpy(es,"SL"); break;
		case 26: strcpy(es,"SR"); break;
		case 27: strcpy(es,"TC"); break;
		case 28: strcpy(es,"TS"); break;
		case 29: strcpy(es,"TL"); break;
		case 30: strcpy(es,"VZ"); break;
		case 31: strcpy(es,"YN"); break;
		case 32: strcpy(es,"ZS"); break;
		case 33: strcpy(es,"NE"); break;
	}
	strcpy(aux->estado,es);
}

//Generar Curp
void creacurp(Tdat *aux){
	//srand(time(NULL));
	Cdat reg;
	char temp[10],recibe[10],vali[10];
	int i,j,tam,tem = 0,con = 0;

	strcpy(recibe,aux->apellidoP);		//Recibe Apellido Paterno

	temp[0] = recibe[0];
	strcpy(reg.al,temp);	//Captura Primer Letra Ape Pat

	strcpy(recibe,aux->apellidoP);		//Recibe el apellido paterno

	i=0;						//Ubica la primer vocal
	if(recibe[0] == 'A' || recibe[0] == 'E' || recibe[0] == 'I'
		|| recibe[0] == 'O' || recibe[0] == 'U') {		 //primera es vocal
		j=1;
		while((recibe[j] != 'A') && (recibe[j] != 'E') &&
			(recibe[j] != 'I') && (recibe[j] != 'O') && (recibe[j] != 'U')){
			j++;
			temp[0] = recibe[j];
		}
	}
	else {
		while((recibe[i] != 'A') && (recibe[i] != 'E') && (recibe[i] != 'I') &&
			(recibe[i] != 'O') && (recibe[i] != 'U')) {
			i++;
			temp[0] = recibe[i];
		}
	}

	strcpy(reg.av,temp);	//Captura Primer Vocal Ape Pat

	strcpy(recibe,aux->apellidoM);		//Recibe Apellido Materno
	temp[0] = recibe[0];
	strcpy(reg.am,temp);	//Captura la primer letra del apellido materno

	strcpy(recibe,aux->nombre);			//Recibe el nombre
	temp[0] = recibe[0];
	strcpy(reg.no,temp);	//Captura La primer letra del nombre

	strcpy(recibe,aux->year);			//Recibe el año
	temp[0] = recibe[2];
	temp[1] = recibe[3];
	strcpy(reg.a,temp);		//Captura año

	strcpy(recibe,aux->month);			//Recibe el mes
	tem = atoi(recibe);

	if(tem < 10) {
		temp[0] = 48;
		temp[1] = recibe[0];
	}
	else {
		temp[0]	= recibe[0];
		temp[1] = recibe[1];
	}
	strcpy(reg.m,temp);		//Captura mes

	strcpy(recibe,aux->day);			//Recibe el dia
	tem = atoi(recibe);

	if(tem < 10) {
		temp[0] = 48;
		temp[1] = recibe[0];
	}
	else {
		temp[0] = recibe[0];
		temp[1] = recibe[1];
	}
	strcpy(reg.d,temp);		//Caputra dia

	tem = aux->sexo;					//Recibe sexo en *int

	if(tem == 1) {
		temp[0] = 'H';
	}
	else {
		temp[0]	= 'M';
	}
	strcpy(reg.sex,temp);	//Captura sexo

	strcpy(temp,aux->estado);	//Captura la Entidad Federativa
	strcpy(reg.edo,temp);//////////************************************////////

	strcpy(recibe,aux->apellidoP);		//Recibe el apellido paterno
	i=1;
	while (recibe[i] != 'B' && recibe[i] != 'C' && recibe[i] != 'D' &&
		recibe[i] != 'F' && recibe[i] != 'G' && recibe[i] != 'H' &&
		recibe[i] != 'J' && recibe[i] != 'K' && recibe[i] != 'L' &&
		recibe[i] != 'M' && recibe[i] != 'N' && recibe[i] != 'P' &&
		recibe[i] != 'Q' && recibe[i] != 'R' && recibe[i] != 'S' &&
		recibe[i] != 'T' && recibe[i] != 'V' && recibe[i] != 'W' &&
		recibe[i] != 'X' && recibe[i] != 'Y' && recibe[i] != 'Z') {
		i++;
		temp[0] = recibe[i];
	}
	strcpy(reg.conp,temp);	//Captura la segunda consonante del apellido paterno

	strcpy(recibe,aux->apellidoM);		//Recibe el apellio Materno

	i=1;
	while (recibe[i] != 'B' && recibe[i] != 'C' && recibe[i] != 'D' &&
		recibe[i] != 'F' && recibe[i] != 'G' && recibe[i] != 'H' &&
		recibe[i] != 'J' && recibe[i] != 'K' && recibe[i] != 'L' &&
		recibe[i] != 'M' && recibe[i] != 'N' && recibe[i] != 'P' &&
		recibe[i] != 'Q' && recibe[i] != 'R' && recibe[i] != 'S' &&
		recibe[i] != 'T' && recibe[i] != 'V' && recibe[i] != 'W' &&
		recibe[i] != 'X' && recibe[i] != 'Y' && recibe[i] != 'Z') {
		i++;
		temp[0] = recibe[i];
	}

	strcpy(reg.conm,temp);	//Caputra la segunda consonante del apellio materno

	strcpy(recibe,aux->nombre);		//Recibe el nombre

	i=1;
	while (recibe[i] != 'B' && recibe[i] != 'C' && recibe[i] != 'D' &&
		recibe[i] != 'F' && recibe[i] != 'G' && recibe[i] != 'H' &&
		recibe[i] != 'J' && recibe[i] != 'K' && recibe[i] != 'L' &&
		recibe[i] != 'M' && recibe[i] != 'N' && recibe[i] != 'P' &&
		recibe[i] != 'Q' && recibe[i] != 'R' && recibe[i] != 'S' &&
		recibe[i] != 'T' && recibe[i] != 'V' && recibe[i] != 'W' &&
		recibe[i] != 'X' && recibe[i] != 'Y' && recibe[i] != 'Z') {
		i++;
		temp[0] = recibe[i];
	}

	strcpy(reg.conN,temp);	//Captura la segunda consonante del nombre

	strcpy(recibe,aux->year);	//recibe el año
	tem = atoi(recibe);
	if(tem < 1999) {
		temp[0] = (48+(rand()%9));
	}
	else {
		tam = (65+(rand()%35));
		switch(tam) {
			case 65: strcpy(temp,"A"); break;
			case 66: strcpy(temp,"B"); break;
			case 67: strcpy(temp,"C"); break;
			case 68: strcpy(temp,"D"); break;
			case 69: strcpy(temp,"E"); break;
			case 70: strcpy(temp,"F"); break;
			case 71: strcpy(temp,"G"); break;
			case 72: strcpy(temp,"H"); break;
			case 73: strcpy(temp,"I"); break;
			case 74: strcpy(temp,"J"); break;
			case 75: strcpy(temp,"K"); break;
			case 76: strcpy(temp,"L"); break;
			case 77: strcpy(temp,"M"); break;
			case 78: strcpy(temp,"N"); break;
			case 79: strcpy(temp,"O"); break;
			case 80: strcpy(temp,"P"); break;
			case 81: strcpy(temp,"Q"); break;
			case 82: strcpy(temp,"R"); break;
			case 83: strcpy(temp,"S"); break;
			case 84: strcpy(temp,"T"); break;
			case 85: strcpy(temp,"U"); break;
			case 86: strcpy(temp,"V"); break;
			case 87: strcpy(temp,"W"); break;
			case 88: strcpy(temp,"X"); break;
			case 89: strcpy(temp,"Y"); break;
			case 90: strcpy(temp,"Z"); break;
		}
	}
	strcpy(reg.ho,temp);	//Caputra homoclave segun el año

	//recibe[0] = reg.al;

	temp[0] = 48;
	strcpy(reg.h2,temp);	//Caputra homoclave 2

	aux->CRP = reg;
}

/*	printf("\tDatos del Alumno: \n\n");
	for(j=0; j<(i-1); j++) {

		printf("(Acitvo:1,Inactivo:0):\t%d\n",vectorExmp[j].status);
		printf("Matricula:\t\t%d\n",vectorExmp[j].matricula);
		printf("Nombre:\t\t\t%s\n",vectorExmp[j].nombre);
		printf("Apellido Paterno:\t%s\n",vectorExmp[j].apellidoP);
		printf("Apellido Materno:\t%s\n",vectorExmp[j].apellidoM);
		printf("Fecha de Nacimiento:\t%s ",vectorExmp[j].day);
		printf("%s ",vectorExmp[j].month);
		printf("%s \n",vectorExmp[j].year);
		printf("(1:Hombre,2:Mujer):\t%d\n",vectorExmp[j].sexo);
		printf("Lugar de nacimiento:\t%s\n\n\n",vectorExmp[j].estado);
		printf("CURP: %s\n\n",
		vectorExmp[j].CRP.al,vectorExmp[j].CRP.av,vectorExmp[j].CRP.am,
		vectorExmp[j].CRP.no,vectorExmp[j].CRP.a,vectorExmp[j].CRP.m,
		vectorExmp[j].CRP.d,vectorExmp[j].CRP.sex,vectorExmp[j].CRP.edo,
		vectorExmp[j].CRP.conp,vectorExmp[j].CRP.conm,vectorExmp[j].CRP.conN,
		vectorExmp[j].CRP.ho,vectorExmp[j].CRP.h2);
		//printf("\n%d\n",ftell(arch));
		k++;
	}  */



