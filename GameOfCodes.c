#include <stdio.h>
#include "GameOfCodes.h"
#include <time.h>
#include <stdlib.h>
#define Max_Usuarios 4 //Maximo numero de usuarios que pueden registrarse
#define intentos 2 //Numero de intentos para adivinar el numero

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
		
		printf ("Introduzca los apeliidos del usuario %i:  ", i+1);
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

void maquina (char c[3][3]) //el ordenador marcará casillas de forma aleatoria
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
	
	printf ("\nBIENVENIDO A PREGUNTADOS !!!\
	        \nPreguntados es un juego de cultura general, donde aleatoriamente se escogera un tema.\
			\nEl tema puede ser ciencia, historia, geografia o deportes.\
			\nDicho esto, empecemos.\n\n");
	
	do{	
	    srand(time(NULL));
	    t = rand()%4;
	
    	if (t==0)
    	P_Ciencia();
	
		else if(t==1)
		P_Deporte();	
	
    	else if(t==2)
    	P_Geografia();
    	
    	else
    	P_Historia();
    	
    	printf ("Parece que ya has terminado.\
		        \nTe gustaria volver a jugar (S/N)? Recuerda que te puede tocar un tema diferente.\n");
    	scanf (" %c", &k);
    }while (k=='s' || k=='S');
}

//Geografia
void P_Geografia()
{
int respuesta;
	char s;
	
	do{
	printf ("Tema escogido: GEOGRAFIA\n");
	geografia_q1();
	scanf ("%i", &respuesta);
	printf("\n");
	
	if (respuesta == 3)
	{
		printf ("CORRECTO !!! Pasas a la siguiente pregunta.\n");
		geografia_q2();
		scanf ("%i", &respuesta);
		printf("\n");
		
		if (respuesta == 3)
		{
			printf ("CORRECTO !!! Pasas a la siguiente pregunta.\n");
			geografia_q3();
			scanf ("%i", &respuesta);
			printf("\n");
			
			if (respuesta == 1)
			{
				printf ("CORRECTO !!! Pasas a la siguiente pregunta.\n");
				geografia_q4();
				scanf ("%i", &respuesta);
				printf("\n");
				
				if (respuesta == 2)
				{
					printf ("CORRECTA !!! Pasas a la siguiente.\n");
					geografia_q5();
					scanf ("%i", &respuesta);
					printf("\n");
					
					if (respuesta == 2)
					{
						printf ("CORRECTO !!! Pasas a la siguiente pregunta.\n");
						geografia_q6();
						scanf ("%i", &respuesta);
						printf("\n");
						
						if (respuesta == 3)
						{
							printf ("CORRECTO !!! Pasas a la siguiente pregunta.\n");
							geografia_q7();
							scanf ("%i", &respuesta);
							printf("\n");
							
							if (respuesta == 1)
							{
								printf ("CORRECTO !!! Pasas a la siguiente pregunta.\n");
								geografia_q8();
								scanf ("%i", &respuesta);
								printf("\n");
								
								if (respuesta == 1)
								{
									printf ("CORRECTO !!! Pasas a la siguiente pregunta.\n");
									geografia_q9();
									scanf ("%i", &respuesta);
									printf("\n");
									
									if (respuesta == 2)
									{
										printf ("CORRECTO !!! Pasas a la ultima pregunta.\n");
										geografia_q10();
										scanf ("%i", &respuesta);
										printf("\n");
										
										if (respuesta == 3)
										printf ("ENHORABUENA !!! HAS PASADO EL TEST DE GEOGRAFIA\n");
										
										else
                                     	{
                             	        	printf ("Lo siento, la respuesta es incorrecta.\n");
                            	        	printf ("Quieres volver a intentarlo? (S/N)\n");
                             	        	scanf (" %c", &s);
                                      	}
									}
									
									else
                                 	{
        	                        	printf ("Lo siento, la respuesta es incorrecta.\n");
        	                        	printf ("Quieres volver a intentarlo? (S/N)\n");
          	                         	scanf (" %c", &s);
                                	}
								}
								
								else
                            	{
        	                    	printf ("Lo siento, la respuesta es incorrecta.\n");
        	                      	printf ("Quieres volver a intentarlo? (S/N)\n");
          	                    	scanf (" %c", &s);
                            	}
							}
							
							else
                        	{
        	                	printf ("Lo siento, la respuesta es incorrecta.\n");
        	                	printf ("Quieres volver a intentarlo? (S/N)\n");
                	        	scanf (" %c", &s);
                        	}
						}
						
						else
                      	{
        	            	printf ("Lo siento, la respuesta es incorrecta.\n");
        	             	printf ("Quieres volver a intentarlo? (S/N)\n");
          	            	scanf (" %c", &s);
                    	}
					}
					
	  				else
                	{
        	        	printf ("Lo siento, la respuesta es incorrecta.\n");
        	        	printf ("Quieres volver a intentarlo? (S/N)\n");
          	        	scanf (" %c", &s);
                	}
				}
				
				else
            	{
        	    	printf ("Lo siento, la respuesta es incorrecta.\n");
             		printf ("Quieres volver a intentarlo? (S/N)\n");
                	scanf (" %c", &s);
             	}
			}
			
			else
        	{
        		printf ("Lo siento, la respuesta es incorrecta.\n");
        		printf ("Quieres volver a intentarlo? (S/N)\n");
          		scanf (" %c", &s);
         	}
		}
		
		else
    	{
    		printf ("Lo siento, la respuesta es incorrecta.\n");
    		printf ("Quieres volver a intentarlo? (S/N)\n");
    		scanf (" %c", &s);
    	}
	}
	
	else
	{
		printf ("Lo siento, la respuesta es incorrecta.\n");
		printf ("Quieres volver a intentarlo? (S/N)\n");
		scanf (" %c", &s);
	}
	} while (s=='s' || s=='S');
}

void geografia_q1()
{
	char pregunta1;
	FILE *q1;
	q1 = fopen ("Preguntados/P_Geografia/q1.txt", "r");
	if (q1==NULL){
		printf ("No se ha podido abrir el archivo.\n");
	}
	while (fscanf (q1, "%c", &pregunta1) != EOF)
	printf ("%c", pregunta1);
	printf ("\n");
	fclose(q1);
}

void geografia_q2()
{
	char pregunta2;
	FILE *q2;
	q2 = fopen ("Preguntados/P_Geografia/q2.txt", "r");
	if (q2==NULL){
		printf ("No se ha podido abrir el archivo.\n");
	}
	while (fscanf (q2, "%c", &pregunta2) != EOF)
	printf ("%c", pregunta2);
	printf("\n");
	fclose(q2);
}

void geografia_q3()
{
	char pregunta3;
	FILE *q3;
	q3 = fopen ("Preguntados/P_Geografia/q3.txt", "r");
	if (q3==NULL){
		printf ("No se ha podido abrir el archivo.\n");
	}
	while (fscanf (q3, "%c", &pregunta3) != EOF)
	printf ("%c", pregunta3);
	printf("\n");
	fclose(q3);
}

void geografia_q4()
{
	char pregunta4;
	FILE *q4;
	q4 = fopen ("Preguntados/P_Geografia/q4.txt", "r");
	if (q4==NULL){
		printf ("No se ha podido abrir el archivo.\n");
	}
	while (fscanf (q4, "%c", &pregunta4) != EOF)
	printf ("%c", pregunta4);
	printf("\n");
	fclose(q4);
}

void geografia_q5()
{
	char pregunta5;
	FILE *q5;
	q5 = fopen ("Preguntados/P_Geografia/q5.txt", "r");
	if (q5==NULL){
		printf ("No se ha podido abrir el archivo.\n");
	}
	while (fscanf (q5, "%c", &pregunta5) != EOF)
	printf ("%c", pregunta5);
	printf("\n");
	fclose(q5);
}

void geografia_q6()
{
	char pregunta6;
	FILE *q6;
	q6 = fopen ("Preguntados/P_Geografia/q6.txt", "r");
	if (q6==NULL){
		printf ("No se ha podido abrir el archivo.\n");
	}
	while (fscanf (q6, "%c", &pregunta6) != EOF)
	printf ("%c", pregunta6);
	printf("\n");
	fclose(q6);
}

void geografia_q7()
{
	char pregunta7;
	FILE *q7;
	q7 = fopen ("Preguntados/P_Geografia/q7.txt", "r");
	if (q7==NULL){
		printf ("No se ha podido abrir el archivo.\n");
	}
	while (fscanf (q7, "%c", &pregunta7) != EOF)
	printf ("%c", pregunta7);
	printf("\n");
	fclose(q7);
}

void geografia_q8()
{
	char pregunta8;
	FILE *q8;
	q8 = fopen ("Preguntados/P_Geografia/q8.txt", "r");
	if (q8==NULL){
		printf ("No se ha podido abrir el archivo.\n");
	}
	while (fscanf (q8, "%c", &pregunta8) != EOF)
	printf ("%c", pregunta8);
	printf("\n");
	fclose(q8);
}

void geografia_q9()
{
	char pregunta9;
	FILE *q9;
	q9 = fopen ("Preguntados/P_Geografia/q9.txt", "r");
	if (q9==NULL){
		printf ("No se ha podido abrir el archivo.\n");
	}
	while (fscanf (q9, "%c", &pregunta9) != EOF)
	printf ("%c", pregunta9);
	printf("\n");
	fclose(q9);
}

void geografia_q10()
{
	char pregunta10;
	FILE *q10;
	q10 = fopen ("Preguntados/P_Geografia/q10.txt", "r");
	if (q10==NULL){
		printf ("No se ha podido abrir el archivo.\n");
	}
	while (fscanf (q10, "%c", &pregunta10) != EOF)
	printf ("%c", pregunta10);
	printf("\n");
	fclose(q10);
}

//Ciencia
void P_Ciencia()
{
	int respuesta;
	char s;
	
	do{
	printf ("Tema escogido: CIENCIA\n");
	ciencia_q1();
	scanf ("%i", &respuesta);
	printf("\n");
	
	if (respuesta == 2)
	{
		printf ("CORRECTO !!! Pasas a la siguiente pregunta.\n");
		ciencia_q2();
		scanf ("%i", &respuesta);
		printf("\n");
		
		if (respuesta == 1)
		{
			printf ("CORRECTO !!! Pasas a la siguiente pregunta.\n");
			ciencia_q3();
			scanf ("%i", &respuesta);
			printf("\n");
			
			if (respuesta == 2)
			{
				printf ("CORRECTO !!! Pasas a la siguiente pregunta.\n");
				ciencia_q4();
				scanf ("%i", &respuesta);
				printf("\n");
				
				if (respuesta == 3)
				{
					printf ("CORRECTA !!! Pasas a la siguiente.\n");
					ciencia_q5();
					scanf ("%i", &respuesta);
					printf("\n");
					
					if (respuesta == 1)
					{
						printf ("CORRECTO !!! Pasas a la siguiente pregunta.\n");
						ciencia_q6();
						scanf ("%i", &respuesta);
						printf("\n");
						
						if (respuesta == 1)
						{
							printf ("CORRECTO !!! Pasas a la siguiente pregunta.\n");
							ciencia_q7();
							scanf ("%i", &respuesta);
							printf("\n");
							
							if (respuesta == 3)
							{
								printf ("CORRECTO !!! Pasas a la siguiente pregunta.\n");
								ciencia_q8();
								scanf ("%i", &respuesta);
								printf("\n");
								
								if (respuesta == 2)
								{
									printf ("CORRECTO !!! Pasas a la siguiente pregunta.\n");
									ciencia_q9();
									scanf ("%i", &respuesta);
									printf("\n");
									
									if (respuesta == 1)
									{
										printf ("CORRECTO !!! Pasas a la ultima pregunta.\n");
										ciencia_q10();
										scanf ("%i", &respuesta);
										printf("\n");
										
										if (respuesta == 3)
										printf ("ENHORABUENA !!! HAS PASADO EL TEST DE CIENCIA\n");
										
										else
                                     	{
                             	        	printf ("Lo siento, la respuesta es incorrecta.\n");
                            	        	printf ("Quieres volver a intentarlo? (S/N)\n");
                             	        	scanf (" %c", &s);
                                      	}
									}
									
									else
                                 	{
        	                        	printf ("Lo siento, la respuesta es incorrecta.\n");
        	                        	printf ("Quieres volver a intentarlo? (S/N)\n");
          	                         	scanf (" %c", &s);
                                	}
								}
								
								else
                            	{
        	                    	printf ("Lo siento, la respuesta es incorrecta.\n");
        	                      	printf ("Quieres volver a intentarlo? (S/N)\n");
          	                    	scanf (" %c", &s);
                            	}
							}
							
							else
                        	{
        	                	printf ("Lo siento, la respuesta es incorrecta.\n");
        	                	printf ("Quieres volver a intentarlo? (S/N)\n");
                	        	scanf (" %c", &s);
                        	}
						}
						
						else
                      	{
        	            	printf ("Lo siento, la respuesta es incorrecta.\n");
        	             	printf ("Quieres volver a intentarlo? (S/N)\n");
          	            	scanf (" %c", &s);
                    	}
					}
					
	  				else
                	{
        	        	printf ("Lo siento, la respuesta es incorrecta.\n");
        	        	printf ("Quieres volver a intentarlo? (S/N)\n");
          	        	scanf (" %c", &s);
                	}
				}
				
				else
            	{
        	    	printf ("Lo siento, la respuesta es incorrecta.\n");
             		printf ("Quieres volver a intentarlo? (S/N)\n");
                	scanf (" %c", &s);
             	}
			}
			
			else
        	{
        		printf ("Lo siento, la respuesta es incorrecta.\n");
        		printf ("Quieres volver a intentarlo? (S/N)\n");
          		scanf (" %c", &s);
         	}
		}
		
		else
    	{
    		printf ("Lo siento, la respuesta es incorrecta.\n");
    		printf ("Quieres volver a intentarlo? (S/N)\n");
    		scanf (" %c", &s);
    	}
	}
	
	else
	{
		printf ("Lo siento, la respuesta es incorrecta.\n");
		printf ("Quieres volver a intentarlo? (S/N)\n");
		scanf (" %c", &s);
	}
	} while (s=='s' || s=='S');
}

void ciencia_q1()
{
	char pregunta1;
	FILE *q1;
	q1 = fopen ("Preguntados/P_Ciencia/q1.txt", "r");
	if (q1==NULL){
		printf ("No se ha podido abrir el archivo.\n");
	}
	while (fscanf (q1, "%c", &pregunta1) != EOF)
	printf ("%c", pregunta1);
	printf ("\n");
	fclose(q1);
}

void ciencia_q2()
{
	char pregunta2;
	FILE *q2;
	q2 = fopen ("Preguntados/P_Ciencia/q2.txt", "r");
	if (q2==NULL){
		printf ("No se ha podido abrir el archivo.\n");
	}
	while (fscanf (q2, "%c", &pregunta2) != EOF)
	printf ("%c", pregunta2);
	printf("\n");
	fclose(q2);
}

void ciencia_q3()
{
	char pregunta3;
	FILE *q3;
	q3 = fopen ("Preguntados/P_Ciencia/q3.txt", "r");
	if (q3==NULL){
		printf ("No se ha podido abrir el archivo.\n");
	}
	while (fscanf (q3, "%c", &pregunta3) != EOF)
	printf ("%c", pregunta3);
	printf("\n");
	fclose(q3);
}

void ciencia_q4()
{
	char pregunta4;
	FILE *q4;
	q4 = fopen ("Preguntados/P_Ciencia/q4.txt", "r");
	if (q4==NULL){
		printf ("No se ha podido abrir el archivo.\n");
	}
	while (fscanf (q4, "%c", &pregunta4) != EOF)
	printf ("%c", pregunta4);
	printf("\n");
	fclose(q4);
}

void ciencia_q5()
{
	char pregunta5;
	FILE *q5;
	q5 = fopen ("Preguntados/P_Ciencia/q5.txt", "r");
	if (q5==NULL){
		printf ("No se ha podido abrir el archivo.\n");
	}
	while (fscanf (q5, "%c", &pregunta5) != EOF)
	printf ("%c", pregunta5);
	printf("\n");
	fclose(q5);
}

void ciencia_q6()
{
	char pregunta6;
	FILE *q6;
	q6 = fopen ("Preguntados/P_Ciencia/q6.txt", "r");
	if (q6==NULL){
		printf ("No se ha podido abrir el archivo.\n");
	}
	while (fscanf (q6, "%c", &pregunta6) != EOF)
	printf ("%c", pregunta6);
	printf("\n");
	fclose(q6);
}

void ciencia_q7()
{
	char pregunta7;
	FILE *q7;
	q7 = fopen ("Preguntados/P_Ciencia/q7.txt", "r");
	if (q7==NULL){
		printf ("No se ha podido abrir el archivo.\n");
	}
	while (fscanf (q7, "%c", &pregunta7) != EOF)
	printf ("%c", pregunta7);
	printf("\n");
	fclose(q7);
}

void ciencia_q8()
{
	char pregunta8;
	FILE *q8;
	q8 = fopen ("Preguntados/P_Ciencia/q8.txt", "r");
	if (q8==NULL){
		printf ("No se ha podido abrir el archivo.\n");
	}
	while (fscanf (q8, "%c", &pregunta8) != EOF)
	printf ("%c", pregunta8);
	printf("\n");
	fclose(q8);
}

void ciencia_q9()
{
	char pregunta9;
	FILE *q9;
	q9 = fopen ("Preguntados/P_Ciencia/q9.txt", "r");
	if (q9==NULL){
		printf ("No se ha podido abrir el archivo.\n");
	}
	while (fscanf (q9, "%c", &pregunta9) != EOF)
	printf ("%c", pregunta9);
	printf("\n");
	fclose(q9);
}

void ciencia_q10()
{
	char pregunta10;
	FILE *q10;
	q10 = fopen ("Preguntados/P_Ciencia/q10.txt", "r");
	if (q10==NULL){
		printf ("No se ha podido abrir el archivo.\n");
	}
	while (fscanf (q10, "%c", &pregunta10) != EOF)
	printf ("%c", pregunta10);
	printf("\n");
	fclose(q10);
}

//Deporte
void P_Deporte()
{
	int respuesta;
	char s;
	
	do{
	printf ("Tema escogido: DEPORTE\n");
	deporte_q1();
	scanf ("%i", &respuesta);
	printf("\n");
	
	if (respuesta == 1)
	{
		printf ("CORRECTO !!! Pasas a la siguiente pregunta.\n");
		deporte_q2();
		scanf ("%i", &respuesta);
		printf("\n");
		
		if (respuesta == 3)
		{
			printf ("CORRECTO !!! Pasas a la siguiente pregunta.\n");
			deporte_q3();
			scanf ("%i", &respuesta);
			printf("\n");
			
			if (respuesta == 1)
			{
				printf ("CORRECTO !!! Pasas a la siguiente pregunta.\n");
				deporte_q4();
				scanf ("%i", &respuesta);
				printf("\n");
				
				if (respuesta == 2)
				{
					printf ("CORRECTA !!! Pasas a la siguiente.\n");
					deporte_q5();
					scanf ("%i", &respuesta);
					printf("\n");
					
					if (respuesta == 1)
					{
						printf ("CORRECTO !!! Pasas a la siguiente pregunta.\n");
						deporte_q6();
						scanf ("%i", &respuesta);
						printf("\n");
						
						if (respuesta == 3)
						{
							printf ("CORRECTO !!! Pasas a la siguiente pregunta.\n");
							deporte_q7();
							scanf ("%i", &respuesta);
							printf("\n");
							
							if (respuesta == 2)
							{
								printf ("CORRECTO !!! Pasas a la siguiente pregunta.\n");
								deporte_q8();
								scanf ("%i", &respuesta);
								printf("\n");
								
								if (respuesta == 3)
								{
									printf ("CORRECTO !!! Pasas a la siguiente pregunta.\n");
									deporte_q9();
									scanf ("%i", &respuesta);
									printf("\n");
									
									if (respuesta == 2)
									{
										printf ("CORRECTO !!! Pasas a la ultima pregunta.\n");
										deporte_q10();
										scanf ("%i", &respuesta);
										printf("\n");
										
										if (respuesta == 2)
										printf ("ENHORABUENA !!! HAS PASADO EL TEST DE DEPORTE\n");
										
										else
                                     	{
                             	        	printf ("Lo siento, la respuesta es incorrecta.\n");
                            	        	printf ("Quieres volver a intentarlo? (S/N)\n");
                             	        	scanf (" %c", &s);
                                      	}
									}
									
									else
                                 	{
        	                        	printf ("Lo siento, la respuesta es incorrecta.\n");
        	                        	printf ("Quieres volver a intentarlo? (S/N)\n");
          	                         	scanf (" %c", &s);
                                	}
								}
								
								else
                            	{
        	                    	printf ("Lo siento, la respuesta es incorrecta.\n");
        	                      	printf ("Quieres volver a intentarlo? (S/N)\n");
          	                    	scanf (" %c", &s);
                            	}
							}
							
							else
                        	{
        	                	printf ("Lo siento, la respuesta es incorrecta.\n");
        	                	printf ("Quieres volver a intentarlo? (S/N)\n");
                	        	scanf (" %c", &s);
                        	}
						}
						
						else
                      	{
        	            	printf ("Lo siento, la respuesta es incorrecta.\n");
        	             	printf ("Quieres volver a intentarlo? (S/N)\n");
          	            	scanf (" %c", &s);
                    	}
					}
					
	  				else
                	{
        	        	printf ("Lo siento, la respuesta es incorrecta.\n");
        	        	printf ("Quieres volver a intentarlo? (S/N)\n");
          	        	scanf (" %c", &s);
                	}
				}
				
				else
            	{
        	    	printf ("Lo siento, la respuesta es incorrecta.\n");
             		printf ("Quieres volver a intentarlo? (S/N)\n");
                	scanf (" %c", &s);
             	}
			}
			
			else
        	{
        		printf ("Lo siento, la respuesta es incorrecta.\n");
        		printf ("Quieres volver a intentarlo? (S/N)\n");
          		scanf (" %c", &s);
         	}
		}
		
		else
    	{
    		printf ("Lo siento, la respuesta es incorrecta.\n");
    		printf ("Quieres volver a intentarlo? (S/N)\n");
    		scanf (" %c", &s);
    	}
	}
	
	else
	{
		printf ("Lo siento, la respuesta es incorrecta.\n");
		printf ("Quieres volver a intentarlo? (S/N)\n");
		scanf (" %c", &s);
	}
	} while (s=='s' || s=='S');
}

void deporte_q1()
{
	char pregunta1;
	FILE *q1;
	q1 = fopen ("Preguntados/P_Deportes/q1.txt", "r");
	if (q1==NULL){
		printf ("No se ha podido abrir el archivo.\n");
	}
	while (fscanf (q1, "%c", &pregunta1) != EOF)
	printf ("%c", pregunta1);
	printf ("\n");
	fclose(q1);
}

void deporte_q2()
{
	char pregunta2;
	FILE *q2;
	q2 = fopen ("Preguntados/P_Deportes/q2.txt", "r");
	if (q2==NULL){
		printf ("No se ha podido abrir el archivo.\n");
	}
	while (fscanf (q2, "%c", &pregunta2) != EOF)
	printf ("%c", pregunta2);
	printf("\n");
	fclose(q2);
}

void deporte_q3()
{
	char pregunta3;
	FILE *q3;
	q3 = fopen ("Preguntados/P_Deportes/q3.txt", "r");
	if (q3==NULL){
		printf ("No se ha podido abrir el archivo.\n");
	}
	while (fscanf (q3, "%c", &pregunta3) != EOF)
	printf ("%c", pregunta3);
	printf("\n");
	fclose(q3);
}

void deporte_q4()
{
	char pregunta4;
	FILE *q4;
	q4 = fopen ("Preguntados/P_Deportes/q4.txt", "r");
	if (q4==NULL){
		printf ("No se ha podido abrir el archivo.\n");
	}
	while (fscanf (q4, "%c", &pregunta4) != EOF)
	printf ("%c", pregunta4);
	printf("\n");
	fclose(q4);
}

void deporte_q5()
{
	char pregunta5;
	FILE *q5;
	q5 = fopen ("Preguntados/P_Deportes/q5.txt", "r");
	if (q5==NULL){
		printf ("No se ha podido abrir el archivo.\n");
	}
	while (fscanf (q5, "%c", &pregunta5) != EOF)
	printf ("%c", pregunta5);
	printf("\n");
	fclose(q5);
}

void deporte_q6()
{
	char pregunta6;
	FILE *q6;
	q6 = fopen ("Preguntados/P_Deportes/q6.txt", "r");
	if (q6==NULL){
		printf ("No se ha podido abrir el archivo.\n");
	}
	while (fscanf (q6, "%c", &pregunta6) != EOF)
	printf ("%c", pregunta6);
	printf("\n");
	fclose(q6);
}

void deporte_q7()
{
	char pregunta7;
	FILE *q7;
	q7 = fopen ("Preguntados/P_Deportes/q7.txt", "r");
	if (q7==NULL){
		printf ("No se ha podido abrir el archivo.\n");
	}
	while (fscanf (q7, "%c", &pregunta7) != EOF)
	printf ("%c", pregunta7);
	printf("\n");
	fclose(q7);
}

void deporte_q8()
{
	char pregunta8;
	FILE *q8;
	q8 = fopen ("Preguntados/P_Deportes/q8.txt", "r");
	if (q8==NULL){
		printf ("No se ha podido abrir el archivo.\n");
	}
	while (fscanf (q8, "%c", &pregunta8) != EOF)
	printf ("%c", pregunta8);
	printf("\n");
	fclose(q8);
}

void deporte_q9()
{
	char pregunta9;
	FILE *q9;
	q9 = fopen ("Preguntados/P_Deportes/q9.txt", "r");
	if (q9==NULL){
		printf ("No se ha podido abrir el archivo.\n");
	}
	while (fscanf (q9, "%c", &pregunta9) != EOF)
	printf ("%c", pregunta9);
	printf("\n");
	fclose(q9);
}

void deporte_q10()
{
	char pregunta10;
	FILE *q10;
	q10 = fopen ("Preguntados/P_Deportes/q10.txt", "r");
	if (q10==NULL){
		printf ("No se ha podido abrir el archivo.\n");
	}
	while (fscanf (q10, "%c", &pregunta10) != EOF)
	printf ("%c", pregunta10);
	printf("\n");
	fclose(q10);
}

//Historia
void P_Historia()
{
	int respuesta;
	char s;
	
	do{
	printf ("Tema escogido: HISTORIA\n");
	historia_q1();
	scanf ("%i", &respuesta);
	printf("\n");
	
	if (respuesta == 1)
	{
		printf ("CORRECTO !!! Pasas a la siguiente pregunta.\n");
		historia_q2();
		scanf ("%i", &respuesta);
		printf("\n");
		
		if (respuesta == 3)
		{
			printf ("CORRECTO !!! Pasas a la siguiente pregunta.\n");
			historia_q3();
			scanf ("%i", &respuesta);
			printf("\n");
			
			if (respuesta == 1)
			{
				printf ("CORRECTO !!! Pasas a la siguiente pregunta.\n");
				historia_q4();
				scanf ("%i", &respuesta);
				printf("\n");
				
				if (respuesta == 3)
				{
					printf ("CORRECTA !!! Pasas a la siguiente.\n");
					historia_q5();
					scanf ("%i", &respuesta);
					printf("\n");
					
					if (respuesta == 2)
					{
						printf ("CORRECTO !!! Pasas a la siguiente pregunta.\n");
						historia_q6();
						scanf ("%i", &respuesta);
						printf("\n");
						
						if (respuesta == 3)
						{
							printf ("CORRECTO !!! Pasas a la siguiente pregunta.\n");
							historia_q7();
							scanf ("%i", &respuesta);
							printf("\n");
							
							if (respuesta == 1)
							{
								printf ("CORRECTO !!! Pasas a la siguiente pregunta.\n");
								historia_q8();
								scanf ("%i", &respuesta);
								printf("\n");
								
								if (respuesta == 2)
								{
									printf ("CORRECTO !!! Pasas a la siguiente pregunta.\n");
									historia_q9();
									scanf ("%i", &respuesta);
									printf("\n");
									
									if (respuesta == 1)
									{
										printf ("CORRECTO !!! Pasas a la ultima pregunta.\n");
										historia_q10();
										scanf ("%i", &respuesta);
										printf("\n");
										
										if (respuesta == 2)
										printf ("ENHORABUENA !!! HAS PASADO EL TEST DE HISTORIA\n");
										
										else
                                     	{
                             	        	printf ("Lo siento, la respuesta es incorrecta.\n");
                            	        	printf ("Quieres volver a intentarlo? (S/N)\n");
                             	        	scanf (" %c", &s);
                                      	}
									}
									
									else
                                 	{
        	                        	printf ("Lo siento, la respuesta es incorrecta.\n");
        	                        	printf ("Quieres volver a intentarlo? (S/N)\n");
          	                         	scanf (" %c", &s);
                                	}
								}
								
								else
                            	{
        	                    	printf ("Lo siento, la respuesta es incorrecta.\n");
        	                      	printf ("Quieres volver a intentarlo? (S/N)\n");
          	                    	scanf (" %c", &s);
                            	}
							}
							
							else
                        	{
        	                	printf ("Lo siento, la respuesta es incorrecta.\n");
        	                	printf ("Quieres volver a intentarlo? (S/N)\n");
                	        	scanf (" %c", &s);
                        	}
						}
						
						else
                      	{
        	            	printf ("Lo siento, la respuesta es incorrecta.\n");
        	             	printf ("Quieres volver a intentarlo? (S/N)\n");
          	            	scanf (" %c", &s);
                    	}
					}
					
	  				else
                	{
        	        	printf ("Lo siento, la respuesta es incorrecta.\n");
        	        	printf ("Quieres volver a intentarlo? (S/N)\n");
          	        	scanf (" %c", &s);
                	}
				}
				
				else
            	{
        	    	printf ("Lo siento, la respuesta es incorrecta.\n");
             		printf ("Quieres volver a intentarlo? (S/N)\n");
                	scanf (" %c", &s);
             	}
			}
			
			else
        	{
        		printf ("Lo siento, la respuesta es incorrecta.\n");
        		printf ("Quieres volver a intentarlo? (S/N)\n");
          		scanf (" %c", &s);
         	}
		}
		
		else
    	{
    		printf ("Lo siento, la respuesta es incorrecta.\n");
    		printf ("Quieres volver a intentarlo? (S/N)\n");
    		scanf (" %c", &s);
    	}
	}
	
	else
	{
		printf ("Lo siento, la respuesta es incorrecta.\n");
		printf ("Quieres volver a intentarlo? (S/N)\n");
		scanf (" %c", &s);
	}
	} while (s=='s' || s=='S');
}

void historia_q1()
{
	char pregunta1;
	FILE *q1;
	q1 = fopen ("Preguntados/P_Historia/q1.txt", "r");
	if (q1==NULL){
		printf ("No se ha podido abrir el archivo.\n");
	}
	while (fscanf (q1, "%c", &pregunta1) != EOF)
	printf ("%c", pregunta1);
	printf ("\n");
	fclose(q1);
}

void historia_q2()
{
	char pregunta2;
	FILE *q2;
	q2 = fopen ("Preguntados/P_Historia/q2.txt", "r");
	if (q2==NULL){
		printf ("No se ha podido abrir el archivo.\n");
	}
	while (fscanf (q2, "%c", &pregunta2) != EOF)
	printf ("%c", pregunta2);
	printf ("\n");
	fclose(q2);
}

void historia_q3()
{
	char pregunta3;
	FILE *q3;
	q3 = fopen ("Preguntados/P_Historia/q3.txt", "r");
	if (q3==NULL){
		printf ("No se ha podido abrir el archivo.\n");
	}
	while (fscanf (q3, "%c", &pregunta3) != EOF)
	printf ("%c", pregunta3);
	printf ("\n");
	fclose(q3);
}

void historia_q4()
{
	char pregunta4;
	FILE *q4;
	q4 = fopen ("Preguntados/P_Historia/q4.txt", "r");
	if (q4==NULL){
		printf ("No se ha podido abrir el archivo.\n");
	}
	while (fscanf (q4, "%c", &pregunta4) != EOF)
	printf ("%c", pregunta4);
	printf ("\n");
	fclose(q4);
}

void historia_q5()
{
	char pregunta5;
	FILE *q5;
	q5 = fopen ("Preguntados/P_Historia/q5.txt", "r");
	if (q5==NULL){
		printf ("No se ha podido abrir el archivo.\n");
	}
	while (fscanf (q5, "%c", &pregunta5) != EOF)
	printf ("%c", pregunta5);
	printf ("\n");
	fclose(q5);
}

void historia_q6()
{
	char pregunta6;
	FILE *q6;
	q6 = fopen ("Preguntados/P_Historia/q6.txt", "r");
	if (q6==NULL){
		printf ("No se ha podido abrir el archivo.\n");
	}
	while (fscanf (q6, "%c", &pregunta6) != EOF)
	printf ("%c", pregunta6);
	printf ("\n");
	fclose(q6);
}

void historia_q7()
{
	char pregunta7;
	FILE *q7;
	q7 = fopen ("Preguntados/P_Historia/q7.txt", "r");
	if (q7==NULL){
		printf ("No se ha podido abrir el archivo.\n");
	}
	while (fscanf (q7, "%c", &pregunta7) != EOF)
	printf ("%c", pregunta7);
	printf ("\n");
	fclose(q7);
}

void historia_q8()
{
	char pregunta8;
	FILE *q8;
	q8 = fopen ("Preguntados/P_Historia/q8.txt", "r");
	if (q8==NULL){
		printf ("No se ha podido abrir el archivo.\n");
	}
	while (fscanf (q8, "%c", &pregunta8) != EOF)
	printf ("%c", pregunta8);
	printf ("\n");
	fclose(q8);
}

void historia_q9()
{
	char pregunta9;
	FILE *q9;
	q9 = fopen ("Preguntados/P_Historia/q9.txt", "r");
	if (q9==NULL){
		printf ("No se ha podido abrir el archivo.\n");
	}
	while (fscanf (q9, "%c", &pregunta9) != EOF)
	printf ("%c", pregunta9);
	printf ("\n");
	fclose(q9);
}

void historia_q10()
{
	char pregunta10;
	FILE *q10;
	q10 = fopen ("Preguntados/P_Historia/q10.txt", "r");
	if (q10==NULL){
		printf ("No se ha podido abrir el archivo.\n");
	}
	while (fscanf (q10, "%c", &pregunta10) != EOF)
	printf ("%c", pregunta10);
	printf ("\n");
	fclose(q10);
}

//BUSCAMINAS
void Buscaminas();
{
	
}

