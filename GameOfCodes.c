#include <stdio.h>
#include "GameOfCodes.h"
#include <time.h>
#include <stdlib.h>
#define Max_Usuarios 4 //Maximo numero de usuarios que pueden registrarse
#define intentos 2 //Numero de intentos para adivinar el numero
#define Num 10
#define MaxNum_Caracteres 250

//PRESENTACION
void presentacion()
{
	FILE *u;
	datos aux[Max_Usuarios];
	datos *usuario[Max_Usuarios];
	int i, Num_Usuarios;
	u = fopen ("Usuario.txt", "a");
	if (u==NULL){
		printf ("No se ha podido abrir el archivo.\n");
	}
	printf("Muy buenas !!! Soy el encargado de la gran sala de recreativos GAME OF CODES.\
	       \nMi nombre es Stark. Antes de empezar, necesito que introduzca algunos datos personales.\n");
	
	for (i=0; i<Max_Usuarios; i++)
	usuario[i] = aux + i;
	
	printf ("Cuantas personas vais a jugar?\n");
	scanf ("%i", &Num_Usuarios);
	
	for (i=0; i<Num_Usuarios; i++)
	{
		printf ("Introduzca el nombre del usuario %i:  ", i+1);
		fflush(stdout);
		scanf ("%s", usuario[i]->nombre);
		fprintf (u, "Nombre del usuario %i: %s\n", i+1, usuario[i]->nombre);
		
		printf ("Introduzca los apellidos del usuario %i:  ", i+1);
		fflush(stdout);
		scanf (" %[^\n]", usuario[i]->apellidos);
		fprintf (u, "Apellidos del usuario %i: %s\n", i+1, usuario[i]->apellidos);
		
		printf ("Introduzca la edad del usuario %i:  ", i+1);
		fflush(stdout);
		scanf ("%d", &usuario[i]->edad);
		fprintf (u, "Edad del usuario %i: %d\n", i+1, usuario[i]->edad);
		
		printf ("Introduzca el sexo del usuario %i:  ", i+1);
		fflush(stdout);
		scanf ("%s", usuario[i]->sexo);
		fprintf (u, "Sexo del usuario %i: %s\n", i+1, usuario[i]->sexo);
		printf("\n");
	}
	
	printf ("Muy bien! Vuestro/s usuario/s es/son:\n");
	for (i=0; i<Num_Usuarios; i++)
	printf ("%s %s\n", usuario[i]->nombre, usuario[i]->apellidos);
	printf ("Parece que ya estamos listos.\
	        \nEn el siguiente menu puedes/podeis seleccionar con que divertirte/divertiros.\n");
}

//TRES EN RAYA
void loop (char c[3][3])
{
	int i,j,a,jug;
	
	do{
	Intro_Primera(c);
	
	printf ("TRES EN RAYA!!!!\n\n");
		
	do{
	printf ("Escoge una opcion (introduce el numero 1 o 2):\
		    \n 1) Jugar contra la maquina.\
			\n 2) Jugar con un amigo.\
			\n 3) Salir del juego.\n");
	scanf ("%i", &a);
	
	} while (a!=1 && a!=2 && a!=3);
	
	switch (a)
	{
		case 1:
			i=0;
	        do{
	        	tablero (c);
		
	    	    if (i % 2 == 0) {
			    jug=1;
		    	    jugador (c,jug);
	    	    }
		
		        else {
	         		maquina (c);
    		    }
		
         	    j = ganador (c);
    	    	i++;
	    	
        	} while (i<=8 && j==2);
	
        	
	        tablero (c);
	
	        if (j==0)
	        {
         		printf ("Enhorabuena!!! Has ganado.\n\n");
         	}
	        else if (j==1)
	        {
         		printf ("Lo siento, has perdido.\n\n");
	        }
	        else
	        {
	        	printf ("Has empatado.\n\n");
	        }
		break;
			
		case 2:
			i=0;
	        do{
		        tablero (c);
		
		        if (i % 2 == 0) {
				jug=1;
		        	jugador (c,jug);
		        }
		
		        else {
				jug=2;
		        	jugador (c,jug);
		        }
		
	           	j = ganador (c);
		        i++;
		
           	} while (i<=8 && j==2);
	
	        tablero (c);
	
	        if (j==0)
	        {
	        	printf ("Enhorabuena!!! Ha ganado el jugador 1.\n\n");
	        }
         	else if (j==1)
         	{
                printf ("Enhorabuena!!! Ha ganado el jugador 2.\n\n");
	        }
	        else
	        {
	        	printf ("Habeis empatado.\n\n");
	        }
	    break;
	}
	} while (a!=3);
}

void Intro_Primera (char c[3][3])
{
	int i,j;
	char aux;
	
	aux='1';
	for (i=0; i<3; i++)
	{
		for (j=0; j<3; j++)
		{
			c[i][j]=aux++;
		}
	}
}

void jugador (char c[3][3], int jug)
{
	int i;
	char signo, casilla;
	
	if (jug==1)
	signo = 'X';
	
	else
        signo = 'O';
		
	do{
		printf ("Turno del jugador %i: ",jug);
	        fflush(stdin);
		scanf ("%c", &casilla);
	}while (casilla<'1' || casilla>'9');
		
	casilla_ocupada(c,casilla,signo);
}

void casilla_ocupada (char c[3][3], char aux, char signo)
{
	int i,j,k;
	
	do{
	  k=0;
		switch (aux)
		{
			case '1':
				i=0;
				j=0;
				if (c[i][j]=='X'||c[i][j]=='O'){
					k=1;
					printf ("La casilla esta ocupada, intentalo con otro numero: ");
					fflush(stdin);
					scanf ("%c", &aux);
				}
				break;
				
			case '2':
				i=0;
				j=1;
				if (c[i][j]=='X'||c[i][j]=='O'){
					k=1;
					printf ("La casilla esta ocupada, intentalo con otro numero: ");
					fflush(stdin);
					scanf ("%c", &aux);
				}
				break;
				
			case '3':
				i=0;
				j=2;
				if (c[i][j]=='X'||c[i][j]=='O'){
					k=1;
					printf ("La casilla esta ocupada, intentalo con otro numero: ");
					fflush(stdin);
					scanf ("%c", &aux);
				}
				break;
				
			case '4':
				i=1;
				j=0;
				if (c[i][j]=='X'||c[i][j]=='O'){
					k=1;
					printf ("La casilla esta ocupada, intentalo con otro numero: ");
					fflush(stdin);
					scanf ("%c", &aux);
				}
				break;
				
			case '5':
				i=1;
				j=1;
				if (c[i][j]=='X'||c[i][j]=='O'){
					k=1;
					printf ("La casilla esta ocupada, intentalo con otro numero: ");
					fflush(stdin);
					scanf ("%c", &aux);
				}
				break;
				
			case '6':
				i=1;
				j=2;
				if (c[i][j]=='X'||c[i][j]=='O'){
					k=1;
					printf ("La casilla esta ocupada, intentalo con otro numero: ");
					fflush(stdin);
					scanf ("%c", &aux);
				}
				break;
				
			case '7':
				i=2;
				j=0;
				if (c[i][j]=='X'||c[i][j]=='O'){
					k=1;
					printf ("La casilla esta ocupada, intentalo con otro numero: ");
					fflush(stdin);
					scanf ("%c", &aux);
				}
				break;
				
			case '8':
				i=2;
				j=1;
				if (c[i][j]=='X'||c[i][j]=='O'){
					k=1;
					printf ("La casilla esta ocupada, intentalo con otro numero: ");
					fflush(stdin);
					scanf ("%c", &aux);
				}
				break;
				
			case '9':
				i=2;
				j=2;
				if (c[i][j]=='X'||c[i][j]=='O'){
					k=1;
					printf ("La casilla esta ocupada, intentalo con otro numero: ");
					fflush(stdin);
					scanf ("%c", &aux);
				}
				break;
		}
	} while (k==1);
	
	c[i][j] = signo;
}

void maquina (char c[3][3]) //el ordenador marcarÃ¡ casillas de forma aleatoria
{
	int i,j,k;
	char aux;
	
	srand (time(NULL));
	do{
		i = rand() % 3;
	    j = rand() % 3;
	    k=0;
	    
	    if (c[i][j]=='X'|| c[i][j]=='O')
	    {
	    	k=1;
		}
	} while (k==1);
	
	c[i][j]='O';
}

void tablero (char c[3][3]) //El tablero se crea a partir de una matriz
{
	int i,j;
	
	for (i=0; i<3; i++)
	{
		for (j=0; j<3; j++)
		{
			if (j<2)
			{
				printf (" %c |", c[i][j]);
			}
			else
			{
				printf (" %c ", c[i][j]);
			}
		}
		if (i<2)
		{
			printf ("\n-----------\n");
		}
	}
	printf ("\n\n");
}

int ganador (char c[3][3])
{
	if (c[0][0]=='X'||c[0][0]=='O')
	{
		if (c[0][0]==c[0][1] && c[0][0]==c[0][2])
		{
			if (c[0][0]=='X')
			{
				return 0; //Gana el jugador 1
			}
			else {
				return 1; //Gana el jugador 2
			}
		}
		if (c[0][0]==c[1][0] && c[0][0]==c[2][0])
		{
			if (c[0][0]=='X')
			{
				return 0; //Gana el jugador 1
			}
			else {
				return 1; //Gana el jugador 2
			}
		}
	}
	
	if (c[1][1]=='X'||c[1][1]=='O')
	{
		if (c[1][1]==c[0][0] && c[1][1]==c[2][2])
		{
			if (c[1][1]=='X')
			{
				return 0; //Gana el jugador 1
			}
			else {
				return 1; //Gana el jugador 2
			}
		}
		if (c[1][1]==c[1][0] && c[1][1]==c[1][2])
		{
			if (c[1][1]=='X')
			{
				return 0; //Gana el jugador 1
			}
			else {
				return 1; //Gana el jugador 2
			}
		}
		if (c[1][1]==c[2][0] && c[1][1]==c[0][2])
		{
			if (c[1][1]=='X')
			{
				return 0; //Gana el jugador 1
			}
			else {
				return 1; //Gana el jugador 2
			}
		}
		if (c[1][1]==c[0][1] && c[1][1]==c[2][1])
		{
			if (c[1][1]=='X')
			{
				return 0; //Gana el jugador 1
			}
			else {
				return 1; //Gana el jugador 2
			}
		}
	}
	
	if (c[2][2]=='X' || c[2][2]=='O')
	{
		if (c[2][2]==c[2][0] && c[2][2]==c[2][1])
		{
			if (c[2][2]=='X')
			{
				return 0; //Gana el jugador 1
			}
			else {
				return 1; //Gana el jugador 2
			}
		}
		if (c[2][2]==c[0][2] && c[2][2]==c[1][2])
		{
			if (c[2][2]=='X')
			{
				return 0; //Gana el jugador 1
			}
			else {
				return 1; //Gana jugador 2
			}
		}
	}
    return 2;
}

//ADIVINA EL NUMERO
void adivina()
{
    FILE *pf;
	int n=0, i=0;
	float n1, n2, n3, n4, n5, numero, tecleado;
	pf = fopen ("Usuario.txt", "a");
	fprintf (pf, "\nADIVINA EL NUMERO\n");
	
	printf ("Introduce 5 numeros diferentes, por favor.\n");
	scanf ("%f %f %f %f %f", &n1, &n2, &n3, &n4, &n5);
	fprintf (pf, "Los numeros escogidos por el usuario son: %.2f, %.2f, %.2f, %.2f y %.2f\n", n1,n2,n3,n4,n5);
	
	printf ("Los numeros escogidos son los siguientes:\
	         \n %.2f  %.2f  %.2f  %.2f  %.2f\
			 \nAhora yo he escogido uno de esos numeros al azar.\
			 \nTE RETO A ADIVINARLO EN MAXIMO DOS INTENTOS, BUENA SUERTE !!!\n", n1,n2,n3,n4,n5);
	
	numero = aleatorio(n1,n2,n3,n4,n5);
	fprintf (pf, "El numero escogido aleatoriamente ha sido el %.2f\n", numero);
	fclose(pf);
	
	do{
		i++;
		do{
		printf ("\nEscribe un numero de los que has introducido antes:\n");
		scanf ("%f", &tecleado);
		} while (tecleado != n1 && tecleado != n2 && tecleado != n3 && tecleado != n4 && tecleado != n5);
		
		if (numero > tecleado)
		printf ("El numero es incorrecto. Pero te dare una pista: el numero seleccionado es mayor.\n");
		else if (numero < tecleado)
		printf ("El numero es incorrecto. Pero te dare una pista: el numero seleccionado es menor.\n");
		else{
			printf ("\nENHORABUENA !!! HAS ADIVINADO EL NUMERO EN %i INTENTO/S.\n", i);
			break;
		}
		if (i >= intentos)
		{
			printf ("\nLo siento, se te han acabado los intentos.\n");
			printf ("El numero era el %.2f\n", numero);
			break;
		}
	} while(1);
}

float aleatorio (float n1, float n2, float n3, float n4, float n5)
{
	srand(time(NULL));
	float nx;
	nx = rand()%5;
	if (nx==0)
	nx=n1;
	else if (nx==1)
	nx=n2;
	else if (nx==2)
	nx=n3;
	else if (nx==3)
	nx=n4;
	else
	nx=n5;
	return nx;
}

//HEROES
void heroesVSvillano()
{
	int per, op, pegar, curar, magia, aleatorio;
	yo heroe;
	enemigo ordenador;
	ordenador.salud = 350;
	ordenador.fuerza = 50;
	
	do{
	printf ("Elige a un HEROE:\
	         \n 1) Clasico (Tiene un ataque y una curacion de 50 puntos).\
			 \n 2) Fortachon (Tiene un ataque de 100 puntos y una curacion de 25 puntos).\
			 \n 3) Curandera (Tiene un ataque de 25 puntos y una curacion de 100 puntos).\
			 \n 4) Mago (Te lo juegas todo a una carta. El mago puede matar al villano de un solo golpe.\
			 \n Sin embargo, si falla, morira con un solo golpe).\n");
	scanf ("%i", &per);
	} while (per!=1 && per!=2 && per!=3 && per!=4);
	
	if (per==1){
		heroe.salud = 200;
		heroe.fuerza = 50;
		heroe.curar = 50;
	}
	else if (per==2){
		heroe.salud = 200;
		heroe.fuerza = 100;
		heroe.curar = 25;
	}
	else if(per==3){
		heroe.salud = 200;
		heroe.fuerza = 25;
		heroe.curar = 100;
	}
	else if(per==4){
		heroe.salud = 50;
		heroe.magia = 350;
	}
	
	if (per==4)
	{
    	srand(time(NULL));
    	aleatorio = rand()%2; // Si sale 0 pierdes, si sale 1 ganas
    	if (aleatorio==0)
    	{
    		printf ("\nTurno del villano:\n");
            pegar = ordenador.fuerza;
            printf ("Te han herido %i puntos\n", pegar);
            heroe.salud -= pegar;
            printf ("Tu salud es de %i\n", heroe.salud);
            printf ("\nOHH NOOO !!! HAS PERDIDO.\n\n");
		}
		else if (aleatorio==1)
		{
			magia = heroe.magia;
  	    	printf ("\nHas herido a tu enemigo %i puntos\n", magia);
            ordenador.salud -= magia;
            printf ("La salud del villano es: %i puntos\n", ordenador.salud);
            printf ("\nENHORABUENA !!! HAS GANADO.\n\n");
		}
	}
	
	else
	{
	    do{
    	    printf ("\nEl villano tiene una vida de %i puntos.\n", ordenador.salud);
    		do{
    			printf ("Elige una opcion (1 o 2):\
    			        \n 1) Atacar.\
    					\n 2) Curar.\n");
    			scanf ("%i", &op);
    		} while (op!=1 && op!=2);
		
    		if (ordenador.salud > 0)
    		{
    			switch (op)
    			{
    				case 1:
    					pegar = heroe.fuerza;
    	        		printf ("\nHas herido a tu enemigo %i puntos\n", pegar);
    	        		ordenador.salud -= pegar;
    	        		printf ("La salud del villano es: %i puntos\n", ordenador.salud);
    	        		break;
	    		
    	    		case 2:
    	    			curar = heroe.curar;
    	    			printf ("\nHas elevado tu vida %i puntos\n", curar);
    	    			heroe.salud += curar;
    	    			printf ("Tu salud es de: %i puntos\n", heroe.salud);
    	    			break;
    			}
		
    			if (ordenador.salud > 0)
    			{
    				printf ("\nTurno del villano:\n");
            	    pegar = ordenador.fuerza;
                	printf ("Te han herido %i puntos\n", pegar);
                	heroe.salud -= pegar;
                	printf ("Tu salud es de %i\n", heroe.salud);
    			}
    			else{
    				printf ("\nENHORABUENA !!! HAS GANADO.\n\n");
    			}
	    	}   
	    } while(heroe.salud>0 && ordenador.salud>0);
	    if (heroe.salud<=0)
    	printf("\nOHH NOOO !!! HAS PERDIDO.\n\n");
	}
}

//PREGUNTADOS
void Preguntados()
{
	int t;
	char k;
	
	printf ("BIENVENIDO A PREGUNTADOS !!!\
	        \nPreguntados es un juego de cultura general, donde aleatoriamente se escogera un tema.\
			\nEl tema puede ser ciencia, historia, geografia o deportes.\
			\nDicho esto, empecemos.\n\n");
	
	do{	
	    srand(time(NULL));
	    t = rand()%4;
	
    	if (t==0)
    	P_Ciencia();
	
		else if(t==1)
		P_Deportes();	
	
    	else if(t==2)
    	P_Geografia();
    	
    	else
    	P_Historia();
    	
    	printf ("\nTe gustaria volver a jugar (S/N)? Recuerda que te puede tocar un tema diferente.\n");
    	scanf (" %c", &k);
    }while (k=='s' || k=='S');
}

//Ciencia
void P_Ciencia()
{
	int i,j;
	char preguntas[Num][MaxNum_Caracteres];
	char respuestas[Num][MaxNum_Caracteres];
	char respuesta_correcta[Num];
	char respuesta;
	
    ciencia_preguntas(preguntas);
    ciencia_respuestas(respuestas);
    ciencia_respuesta_correcta(respuesta_correcta);
    
	printf ("TEMA ESCOGIDO: CIENCIA\n");
	
	for (i=0; i<Num; i++)
	{
		printf ("\n%s\n", preguntas[i]);
		printf ("%s\n", respuestas[i]);
		scanf (" %c", &respuesta);
		
		if (respuesta != respuesta_correcta[i])
		{
			printf ("Lo siento, has fallado...");
			break;
		}
	}
	printf ("\nHas terminado. Espero que hayas acertado muchas!\n");
}

void ciencia_preguntas (char preguntas[Num][MaxNum_Caracteres])
{
	int N=0;
	FILE *q;
	
	q = fopen ("Preguntados/P_Ciencia/cuestiones.txt", "r");
	if (q==NULL){
		printf ("No se ha podido abrir el archivo.\n");
	}
	
	while (fscanf (q, " %[^\n]", preguntas[N]) != EOF)
	N++;
	fclose(q);
}

void ciencia_respuestas (char respuestas[Num][MaxNum_Caracteres])
{
	int N=0;
	FILE *r;
	
	r = fopen("Preguntados/P_Ciencia/respuestas.txt", "r");
	if (r==NULL){
		printf ("No se ha podido abrir el archivo.\n");
	}
	
	while (fscanf (r, " %[^\n]", respuestas[N]) != EOF)
	N++;
	fclose(r);
}

void ciencia_respuesta_correcta (char respuesta_correcta[Num])
{
	int N=0;
	FILE *rc;
	
	rc = fopen ("Preguntados/P_Ciencia/respuesta_correcta.txt", "r");
	if (rc==NULL){
		printf ("No se ha podido abrir el archivo.\n");
	}
	
	while (fscanf (rc, "%c", &respuesta_correcta[N]) != EOF)
	N++;
	fclose(rc);
}

//Geografia
void P_Geografia()
{
	int i,j;
	char preguntas[Num][MaxNum_Caracteres];
	char respuestas[Num][MaxNum_Caracteres];
	char respuesta_correcta[Num];
	char respuesta;
	
    geografia_preguntas(preguntas);
    geografia_respuestas(respuestas);
    geografia_respuesta_correcta(respuesta_correcta);
    
	printf ("TEMA ESCOGIDO: GEOGRAFIA\n");
	
	for (i=0; i<Num; i++)
	{
		printf ("\n%s\n", preguntas[i]);
		printf ("%s\n", respuestas[i]);
		scanf (" %c", &respuesta);
		
		if (respuesta != respuesta_correcta[i])
		{
			printf ("Lo siento, has fallado...");
			break;
		}
	}
	printf ("\nHas terminado. Espero que hayas acertado muchas!\n");
}

void geografia_preguntas (char preguntas[Num][MaxNum_Caracteres])
{
	int N=0;
	FILE *q;
	
	q = fopen ("Preguntados/P_Geografia/cuestiones.txt", "r");
	if (q==NULL){
		printf ("No se ha podido abrir el archivo.\n");
	}
	
	while (fscanf (q, " %[^\n]", preguntas[N]) != EOF)
	N++;
	fclose(q);
}

void geografia_respuestas (char respuestas[Num][MaxNum_Caracteres])
{
	int N=0;
	FILE *r;
	
	r = fopen("Preguntados/P_Geografia/respuestas.txt", "r");
	if (r==NULL){
		printf ("No se ha podido abrir el archivo.\n");
	}
	
	while (fscanf (r, " %[^\n]", respuestas[N]) != EOF)
	N++;
	fclose(r);
}

void geografia_respuesta_correcta (char respuesta_correcta[Num])
{
	int N=0;
	FILE *rc;
	
	rc = fopen ("Preguntados/P_Geografia/respuesta_correcta.txt", "r");
	if (rc==NULL){
		printf ("No se ha podido abrir el archivo.\n");
	}
	
	while (fscanf (rc, "%c", &respuesta_correcta[N]) != EOF)
	N++;
	fclose(rc);
}

//Deportes
void P_Deportes()
{
	int i,j;
	char preguntas[Num][MaxNum_Caracteres];
	char respuestas[Num][MaxNum_Caracteres];
	char respuesta_correcta[Num];
	char respuesta;
	
    deportes_preguntas(preguntas);
    deportes_respuestas(respuestas);
    deportes_respuesta_correcta(respuesta_correcta);
    
	printf ("TEMA ESCOGIDO: DEPORTES\n");
	
	for (i=0; i<Num; i++)
	{
		printf ("\n%s\n", preguntas[i]);
		printf ("%s\n", respuestas[i]);
		scanf (" %c", &respuesta);
		
		if (respuesta != respuesta_correcta[i])
		{
			printf ("Lo siento, has fallado...");
			break;
		}
	}
	printf ("\nHas terminado. Espero que hayas acertado muchas!\n");
}

void deportes_preguntas (char preguntas[Num][MaxNum_Caracteres])
{
	int N=0;
	FILE *q;
	
	q = fopen ("Preguntados/P_Deportes/cuestiones.txt", "r");
	if (q==NULL){
		printf ("No se ha podido abrir el archivo.\n");
	}
	
	while (fscanf (q, " %[^\n]", preguntas[N]) != EOF)
	N++;
	fclose(q);
}

void deportes_respuestas (char respuestas[Num][MaxNum_Caracteres])
{
	int N=0;
	FILE *r;
	
	r = fopen("Preguntados/P_Deportes/respuestas.txt", "r");
	if (r==NULL){
		printf ("No se ha podido abrir el archivo.\n");
	}
	
	while (fscanf (r, " %[^\n]", respuestas[N]) != EOF)
	N++;
	fclose(r);
}

void deportes_respuesta_correcta (char respuesta_correcta[Num])
{
	int N=0;
	FILE *rc;
	
	rc = fopen ("Preguntados/P_Deportes/respuesta_correcta.txt", "r");
	if (rc==NULL){
		printf ("No se ha podido abrir el archivo.\n");
	}
	
	while (fscanf (rc, "%c", &respuesta_correcta[N]) != EOF)
	N++;
	fclose(rc);
}

//Historia
void P_Historia()
{
	int i,j;
	char preguntas[Num][MaxNum_Caracteres];
	char respuestas[Num][MaxNum_Caracteres];
	char respuesta_correcta[Num];
	char respuesta;
	
    historia_preguntas(preguntas);
    historia_respuestas(respuestas);
    historia_respuesta_correcta(respuesta_correcta);
    
	printf ("TEMA ESCOGIDO: HISTORIA\n");
	
	for (i=0; i<Num; i++)
	{
		printf ("\n%s\n", preguntas[i]);
		printf ("%s\n", respuestas[i]);
		scanf (" %c", &respuesta);
		
		if (respuesta != respuesta_correcta[i])
		{
			printf ("Lo siento, has fallado...");
			break;
		}
	}
	printf ("\nHas terminado. Espero que hayas acertado muchas!\n");
}

void historia_preguntas (char preguntas[Num][MaxNum_Caracteres])
{
	int N=0;
	FILE *q;
	
	q = fopen ("Preguntados/P_Historia/cuestiones.txt", "r");
	if (q==NULL){
		printf ("No se ha podido abrir el archivo.\n");
	}
	
	while (fscanf (q, " %[^\n]", preguntas[N]) != EOF)
	N++;
	fclose(q);
}

void historia_respuestas (char respuestas[Num][MaxNum_Caracteres])
{
	int N=0;
	FILE *r;
	
	r = fopen("Preguntados/P_Historia/respuestas.txt", "r");
	if (r==NULL){
		printf ("No se ha podido abrir el archivo.\n");
	}
	
	while (fscanf (r, " %[^\n]", respuestas[N]) != EOF)
	N++;
	fclose(r);
}

void historia_respuesta_correcta (char respuesta_correcta[Num])
{
	int N=0;
	FILE *rc;
	
	rc = fopen ("Preguntados/P_Historia/respuesta_correcta.txt", "r");
	if (rc==NULL){
		printf ("No se ha podido abrir el archivo.\n");
	}
	
	while (fscanf (rc, "%c", &respuesta_correcta[N]) != EOF)
	N++;
	fclose(rc);
}

//BUSCAMINAS
void buscaminas()
{
	char e;
	printf("Hola!!, preparado para jugar al Buscaminas?\n");
	printf("Te explicare en que consiste: te apareceran tableros diferentes, en funcion de la dificultad que elijas\n");
	printf("OJO!, por el tablero hay escondidas minas. Si tocas una de ellas, habras perdido\n");
	printf("Tu objetivo es recorrer el tablero entero sin encontrar ninguna mina\n");
	printf("Buena suerte!!");
	printf("Selecciona un modo de juego:\n");
	printf("(F)Facil\n(D)Dificil\n");
	scanf(" %c", &e);
	switch(e) //segun la eleccion del jugador, el modo es facil, dificil o extremo
	{
		case 'F':
		case 'f':
			modoFacil();
		break;
		
		case 'D':
		case 'd':
			modoDificil();
		break;
	}
}

void modoFacil()
{
	int i, j;
	int t;
	int v1[2], v2[2], v3[2], v4[2], v5[2], v6[2];
	int tablero[6][6]; //tablero de minas
	int tJug[6][6]; //tablero que ve el jugador
	int jx, jy; //variables que recogen la posicion donde se mueve el jugador
	int result;
	char m; //identifica minas
	int nIntentos=0; //contabiliza los intentos
	
	printf("Has elegido modo facil, por lo que tu tablero(6x6)es este:...\n");
	
	//Este bucle permite crear el tablero inicial(8x8)
	for(i=0; i<6; i++)
	{
		for(j=0; j<6; j++)
		{
			tablero[i][j]=0;
			printf("/ ");
				if(j==5)
					printf("\n");
		}
	}
	printf("Recuerda de tienes 6 minas que evitar... que empiece el juego!!\n");
	sleep(2);
	//Se crea aqui el tablero que vera el jugador(sin las minas)
	for(i=0; i<6; i++)
	{
		for(j=0; j<6; j++)
		{
			tJug[i][j]=0;
		}
	}
	//se generan numeros aleatorios para las posiciones de las minas, en vectores
	srand(time(NULL)); //genera posiciones aleatorias para los valores 'x' e 'y' de cada mina
	v1[0]=rand()%6;
	v1[1]=rand()%6;
	
	//permite asegurarse de que las minas no esten en la misma posicion
	//reescribe el vector v2, hasta que su componente 'x' o 'y' sea distinta a la del vector 1
	do{
		v2[0]=rand()%6;
		v2[1]=rand()%6;
	}while(v2[0]==v1[0] && v2[1]==v1[1]);
	
	//reescribe el vector v3, hasta que sus componente 'x' o 'y' sean distintas a las del vector 1 y 2
	do{
		v3[0]=rand()%6;
		v3[1]=rand()%6;
	}while((v3[0]==v1[0] && v3[1]==v1[1]) || (v3[0]==v2[0] && v3[1]==v2[1]));
	
	//reescribe el vector v4, hasta que sus componente 'x' o 'y' sean distintas a las del vector 1, 2 y 3
	do{
		v4[0]=rand()%6;
		v4[1]=rand()%6;
	}while((v4[0]==v1[0] && v4[1]==v1[1]) || (v4[0]==v2[0] && v4[1]==v2[1]) || (v4[0]==v3[0] && v4[1]==v3[1]));
	
	//reescribe el vector v5, hasta que sus componente 'x' o 'y' sean distintas a las del vector 1, 2, 3 y 4
	do{
		v5[0]=rand()%6;
		v5[1]=rand()%6;
	}while((v5[0]==v1[0] && v5[1]==v1[1]) || (v5[0]==v2[0] && v5[1]==v2[1]) || (v5[0]==v3[0] && v5[1]==v3[1]) || (v5[0]==v4[0] && v5[1]==v4[1]));
	
	//reescribe el vector v6, hasta que sus componente 'x' o 'y' sean distintas a las del vector 1, 2, 3, 4 y 5
	do{
		v6[0]=rand()%6;
		v6[1]=rand()%6;
	}while((v6[0]==v1[0] && v6[1]==v1[1]) || (v6[0]==v2[0] && v6[1]==v2[1]) || (v6[0]==v3[0] && v6[1]==v3[1]) || (v6[0]==v4[0] && v6[1]==v4[1]) || (v6[0]==v5[0] && v6[1]==v5[1]));
	
	//x1 = rand()%8;
    //y1 = rand()%8; ... asi hasta 12 posiciones, 6 vectores
    
    tablero[v1[0]][v1[1]] = 9; //Se inicializa un 'flag' para las minas
    tablero[v2[0]][v2[1]] = 9;
    tablero[v3[0]][v3[1]] = 9;
    tablero[v4[0]][v4[1]] = 9;
    tablero[v5[0]][v5[1]] = 9;
    tablero[v6[0]][v6[1]] = 9;

	//TABLERO DE LAS MINAS(El usuario no puede verlo)\
    for(i=0; i<N; i++)\
    {\
    	for(j=0; j<N; j++)\
    	{\
    		printf("%i ", tablero[i][j]);\
    		if(j==7)\
				printf("\n");\
		}\
	}\
	
    //TABLERO QUE VE EL JUGADOR\
    for(i=0; i<N; i++)\
    {\
    	for(j=0; j<N; j++)\
    	{\
    		printf("%i ", tJug[i][j]);\
    		if(j==7)\
				printf("\n");\
		}\
	}\
    
    //Pedir al jugador que introduzca las coordenadas(x, y) de donde quiera caer. 'x' e 'y' estan entre 0 y 5
	printf("Introduce las coordenadas 'x' e 'y' del lugar del tablero donde quieras caer(entre 0 y 5)\n");
	do
	{
		printf("\n");
		scanf(" %i %i", &jx, &jy);
		printf("\n");
		//Se comprueba si el punto introducido por el jugador coincide con una mina
	    if(( (jx==v1[0]) && (jy==v1[1]) || (jx==v2[0]) && (jy==v2[1]) || (jx==v3[0]) && (jy==v3[1]) || (jx==v4[0]) && (jy==v5[1]) || (jx==v5[0]) && (jy==v4[1]) || (jx==v6[0]) && (jy==v6[1]) ))
	    {
	    	for(i=0; i<6; i++) //dibuja el tablero, con las minas
	    	{
		    	for(j=0; j<6; j++)
		    	{
		    		printf("%i ", tablero[i][j]);
		    		if(j==5)
						printf("\n");
				}
			}
	    	printf("Que pena, has encontrado una mina(en el tablero puedes ver donde estaba cada mina)... has perdido. Hasta pronto!!\n");
	    	result='m';//si coincide, result lo almacena como 'm'. cuando result = 'm', el jugador habrá perdido
		}
		else
		{
			tJug[jx][jy] = 1;
			for(i=0; i<6; i++) //dibuja el tablero, sin las minas
	    	{
		    	for(j=0; j<6; j++)
		    	{
		    		printf("%i ", tJug[i][j]);
		    		if(j==5)
						printf("\n");
				}
			}
			nIntentos++; //va sumando cada vez que el jugador rellena un hueco del tablero sin perder, cuando nIntentos=8x8-4(minas), el jugador habra ganado
			if (nIntentos==60)
			{
				printf("ENHORABUENA, no has tocado ninguna mina en todo el tablero... HAS GANADO LA PARTIDA\n");
			}
			else
			{
				printf("\nBien!, no has tocado ninguna mina, sigues jugando\n");
				printf("Introduce las coordenadas de una nueva posicion en el tablero(entre 0 y 7)\n");	
			}
		}
	}while(result!='m');	   
}

void modoDificil()
{
	int i, j;
	int t;
	int v1[2], v2[2], v3[2], v4[2], v5[2], v6[2], v7[2], v8[2], v9[2];
	int tablero[9][9]; //tablero de minas
	int tJug[9][9]; //tablro que ve el jugador
	int jx, jy; //variables que recogen la posicion donde se mueve el jugador
	int result;
	char m; //identifica minas
	int nIntentos=0; //contabiliza los intentos
	
	printf("Has elegido modo dificil, por lo que tu tablero(9x9)es este:...\n");
	
	//Este bucle permite crear el tablero inicial(10x10)
	for(i=0; i<9; i++)
	{
		for(j=0; j<9; j++)
		{
			tablero[i][j]=0;
			printf("/ ");
				if(j==8)
					printf("\n");
		}
	}
	printf("Recuerda de tienes 9 minas que evitar... que empiece el juego!!\n");
	sleep(2);
	//Se crea aqui el tablero que vera el jugador(sin las minas)
	for(i=0; i<9; i++)
	{
		for(j=0; j<9; j++)
		{
			tJug[i][j]=0;
		}
	}
	//se generan numeros aleatorios para las posiciones de las minas, en vectores
	srand(time(NULL)); //genera posiciones aleatorias para los valores 'x' e 'y' de cada mina
	v1[0]=rand()%9;
	v1[1]=rand()%9;
	
	//permite asegurarse de que las minas no esten en la misma posicion
	//reescribe el vector v2, hasta que su componente 'x' o 'y' sea distinta a la del vector 1
	do{
		v2[0]=rand()%9;
		v2[1]=rand()%9;
	}while(v2[0]==v1[0] && v2[1]==v1[1]);
	
	//reescribe el vector v3, hasta que sus componente 'x' o 'y' sean distintas a las del vector 1 y 2
	do{
		v3[0]=rand()%9;
		v3[1]=rand()%9;
	}while((v3[0]==v1[0] && v3[1]==v1[1]) || (v3[0]==v2[0] && v3[1]==v2[1]));
	
	//reescribe el vector v4, hasta que sus componente 'x' o 'y' sean distintas a las del vector 1, 2 y 3
	do{
		v4[0]=rand()%9;
		v4[1]=rand()%9;
	}while((v4[0]==v1[0] && v4[1]==v1[1]) || (v4[0]==v2[0] && v4[1]==v2[1]) || (v4[0]==v3[0] && v4[1]==v3[1]));
	
	//reescribe el vector v5, hasta que sus componente 'x' o 'y' sean distintas a las del vector 1, 2, 3 y 4
	do{
		v5[0]=rand()%9;
		v5[1]=rand()%9;
	}while((v5[0]==v1[0] && v5[1]==v1[1]) || (v5[0]==v2[0] && v5[1]==v2[1]) || (v5[0]==v3[0] && v5[1]==v3[1]) || (v5[0]==v4[0] && v5[1]==v4[1]));
	
	//reescribe el vector v6, hasta que sus componente 'x' o 'y' sean distintas a las del vector 1, 2, 3, 4 y 5
	do{
		v6[0]=rand()%9;
		v6[1]=rand()%9;
	}while((v6[0]==v1[0] && v6[1]==v1[1]) || (v6[0]==v2[0] && v6[1]==v2[1]) || (v6[0]==v3[0] && v6[1]==v3[1]) || (v6[0]==v4[0] && v6[1]==v4[1]) || (v6[0]==v5[0] && v6[1]==v5[1]));
	
	//reescribe el vector v7, hasta que sus componente 'x' o 'y' sean distintas a las del vector 1, 2, 3, 4, 5 y 6
	do{
		v7[0]=rand()%9;
		v7[1]=rand()%9;
	}while((v7[0]==v1[0] && v7[1]==v1[1]) || (v7[0]==v2[0] && v7[1]==v2[1]) || (v7[0]==v3[0] && v7[1]==v3[1]) || (v7[0]==v4[0] && v7[1]==v4[1]) || 
	(v7[0]==v5[0] && v7[1]==v5[1]) || (v7[0]==v6[0] && v7[1]==v6[1]) );
	
	//reescribe el vector v8, hasta que sus componente 'x' o 'y' sean distintas a las del vector 1, 2, 3, 4, 5, 6 y 7
	do{
		v8[0]=rand()%9;
		v8[1]=rand()%9;
	}while((v8[0]==v1[0] && v8[1]==v1[1]) || (v8[0]==v2[0] && v8[1]==v2[1]) || (v8[0]==v3[0] && v8[1]==v3[1]) || (v8[0]==v4[0] && v8[1]==v4[1]) || 
	(v8[0]==v5[0] && v8[1]==v5[1]) || (v8[0]==v6[0] && v8[1]==v6[1]) || (v8[0]==v7[0] && v8[1]==v7[1]));
	
	//reescribe el vector v9, hasta que sus componente 'x' o 'y' sean distintas a las del vector 1, 2, 3, 4, 5, 6, 7 y 8
	do{
		v9[0]=rand()%9;
		v9[1]=rand()%9;
	}while((v9[0]==v1[0] && v9[1]==v1[1]) || (v9[0]==v2[0] && v9[1]==v2[1]) || (v9[0]==v3[0] && v9[1]==v3[1]) || (v9[0]==v4[0] && v9[1]==v4[1]) || 
	(v9[0]==v5[0] && v9[1]==v5[1]) || (v9[0]==v6[0] && v9[1]==v6[1]) || (v9[0]==v7[0] && v9[1]==v7[1]) || (v9[0]==v7[0] && v9[1]==v7[1]));
    
    tablero[v1[0]][v1[1]] = 9; //Se inicializa un 'flag' para las minas
    tablero[v2[0]][v2[1]] = 9;
    tablero[v3[0]][v3[1]] = 9;
    tablero[v4[0]][v4[1]] = 9;
    tablero[v5[0]][v5[1]] = 9;
    tablero[v6[0]][v6[1]] = 9;
    tablero[v7[0]][v7[1]] = 9;
    tablero[v8[0]][v8[1]] = 9;
    tablero[v9[0]][v9[1]] = 9;
    
    //Pedir al jugador que introduzca las coordenadas(x, y) de donde quiera caer. 'x' e 'y' estan entre 0 y 8
	printf("Introduce las coordenadas 'x' e 'y' del lugar del tablero donde quieras caer(entre 0 y 8)\n");
	do
	{
		printf("\n");
		scanf(" %i %i", &jx, &jy);
		printf("\n");
		//Se comprueba si el punto introducido por el jugador coincide con una mina
	    if(( (jx==v1[0]) && (jy==v1[1]) || (jx==v2[0]) && (jy==v2[1]) || (jx==v3[0]) && (jy==v3[1]) || (jx==v4[0]) && (jy==v4[1]) || (jx==v5[0]) && (jy==v5[1]) || 
		(jx==v6[0]) && (jy==v6[1]) || (jx==v7[0]) && (jy==v7[1]) || (jx==v8[0]) && (jy==v8[1]) || (jx==v9[0]) && (jy==v9[1]) ))
	    {
	    	for(i=0; i<9; i++) //dibuja el tablero, con las minas
	    	{
		    	for(j=0; j<9; j++)
		    	{
		    		printf("%i ", tablero[i][j]);
		    		if(j==8)
						printf("\n");
				}
			}
	    	printf("Que pena, has encontrado una mina(en el tablero puedes ver donde estaba cada mina)... has perdido. Hasta pronto!!\n");
	    	result='m';//si coincide, result lo almacena como 'm'. cuando result = 'm', el jugador habrá perdido
		}
		else
		{
			tJug[jx][jy] = 1;
			for(i=0; i<9; i++) //dibuja el tablero, sin las minas
	    	{
		    	for(j=0; j<9; j++)
		    	{
		    		printf("%i ", tJug[i][j]);
		    		if(j==8)
						printf("\n");
				}
			}
			nIntentos++; //va sumando cada vez que el jugador rellena un hueco del tablero sin perder, cuando nIntentos=8x8-4(minas), el jugador habra ganado
			if (nIntentos==72)
			{
				printf("ENHORABUENA, no has tocado ninguna mina en todo el tablero... HAS GANADO LA PARTIDA\n");
			}
			else
			{
				printf("\nBien!, no has tocado ninguna mina, sigues jugando\n");
				printf("Introduce las coordenadas de una nueva posicion en el tablero(entre 0 y 8)\n");	
			}
		}
	}while(result!='m');	   
}

