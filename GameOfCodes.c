#include <stdio.h>
#include "GameOfCodes.h"
#include <time.h>
#define intentos 2 //Número de intentos para adivina el número

//PRESENTACIÓN
void presentacion()
{
	FILE *u;
	datos usuario;
	u = fopen ("Usuario.txt", "a");
	if (u==NULL){
		printf ("No se ha podido abrir el archivo.\n");
	}
	printf("Muy buenas !!! Soy el encargado de la gran sala de recreativos GAME OF CODES.\
	       \nMi nombre es Stark. Antes de empezar, necesito que introduzca algunos datos personales.\n");
	printf ("Introduzca su nombre:\n");
	scanf ("%s", usuario.nombre);
	fprintf (u,"Nombre del usuario: %s\n",usuario.nombre);
	printf ("Introduzca sus apellidos:\n");
	scanf (" %[^\n]", usuario.apellidos);
	fprintf (u,"Apellidos del usuario: %s\n",usuario.apellidos);
	printf ("Introduzca su edad:\n");
	scanf ("%d", &usuario.edad);
	fprintf (u,"Edad del usuario: %d\n",usuario.edad);
	printf ("Introduzca su sexo:\n");
	scanf ("%s", usuario.sexo);
	fprintf (u,"Sexo del usuario: %s\n",usuario.sexo);
	fclose(u);
	
	printf ("Muy bien %s %s!. Tienes ganas de divertirte? Porque ya estamos listos para empezar.\
	        \nEn el siguiente menu puedes seleccionar con que quieres divertirte.\n", usuario.nombre, usuario.apellidos);
	
}

//TRES EN RAYA
void loop (char c[3][3])
{
	int i,j,a;
	
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
		    	    jugador1 (c);
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
		        	jugador1 (c);
		        }
		
		        else {
		        	jugador2 (c);
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

void jugador1 (char c[3][3])
{
	int i,j,k;
	char aux;
	
	do{
		do{
			printf ("Turno del jugador 1: ");
			scanf (" %c", &aux);
		} while (aux<'1' || aux>'9');
		
		k=0;
		switch (aux)
		{
			case '1':
				i=0;
				j=0;
				if (c[i][j]=='X'||c[i][j]=='O'){
					k=1;
					printf ("La casilla esta ocupada, intentalo con otro numero.\n\n");
				}
				break;
				
			case '2':
				i=0;
				j=1;
				if (c[i][j]=='X'||c[i][j]=='O'){
					k=1;
					printf ("La casilla esta ocupada, intentalo con otro numero.\n\n");
				}
				break;
				
			case '3':
				i=0;
				j=2;
				if (c[i][j]=='X'||c[i][j]=='O'){
					k=1;
					printf ("La casilla esta ocupada, intentalo con otro numero.\n\n");
				}
				break;
				
			case '4':
				i=1;
				j=0;
				if (c[i][j]=='X'||c[i][j]=='O'){
					k=1;
					printf ("La casilla esta ocupada, intentalo con otro numero.\n\n");
				}
				break;
				
			case '5':
				i=1;
				j=1;
				if (c[i][j]=='X'||c[i][j]=='O'){
					k=1;
					printf ("La casilla esta ocupada, intentalo con otro numero.\n\n");
				}
				break;
				
			case '6':
				i=1;
				j=2;
				if (c[i][j]=='X'||c[i][j]=='O'){
					k=1;
					printf ("La casilla esta ocupada, intentalo con otro numero.\n\n");
				}
				break;
				
			case '7':
				i=2;
				j=0;
				if (c[i][j]=='X'||c[i][j]=='O'){
					k=1;
					printf ("La casilla esta ocupada, intentalo con otro numero.\n\n");
				}
				break;
				
			case '8':
				i=2;
				j=1;
				if (c[i][j]=='X'||c[i][j]=='O'){
					k=1;
					printf ("La casilla esta ocupada, intentalo con otro numero.\n\n");
				}
				break;
				
			case '9':
				i=2;
				j=2;
				if (c[i][j]=='X'||c[i][j]=='O'){
					k=1;
					printf ("La casilla esta ocupada, intentalo con otro numero.\n\n");
				}
				break;
		}
	} while (k==1);
	
	c[i][j]='X';
}

void jugador2 (char c[3][3])
{
	int i,j,k;
	char aux;
	
	do{
		do{
			printf ("Turno del jugador 2: ");
			scanf (" %c", &aux);
		} while (aux<'1' || aux>'9');
		
		k=0;
		switch (aux)
		{
			case '1':
				i=0;
				j=0;
				if (c[i][j]=='X'||c[i][j]=='O'){
					k=1;
					printf ("La casilla esta ocupada, intentalo con otro numero.\n\n");
				}
				break;
				
			case '2':
				i=0;
				j=1;
				if (c[i][j]=='X'||c[i][j]=='O'){
					k=1;
					printf ("La casilla esta ocupada, intentalo con otro numero.\n\n");
				}
				break;
				
			case '3':
				i=0;
				j=2;
				if (c[i][j]=='X'||c[i][j]=='O'){
					k=1;
					printf ("La casilla esta ocupada, intentalo con otro numero.\n\n");
				}
				break;
				
			case '4':
				i=1;
				j=0;
				if (c[i][j]=='X'||c[i][j]=='O'){
					k=1;
					printf ("La casilla esta ocupada, intentalo con otro numero.\n\n");
				}
				break;
				
			case '5':
				i=1;
				j=1;
				if (c[i][j]=='X'||c[i][j]=='O'){
					k=1;
					printf ("La casilla esta ocupada, intentalo con otro numero.\n\n");
				}
				break;
				
			case '6':
				i=1;
				j=2;
				if (c[i][j]=='X'||c[i][j]=='O'){
					k=1;
					printf ("La casilla esta ocupada, intentalo con otro numero.\n\n");
				}
				break;
				
			case '7':
				i=2;
				j=0;
				if (c[i][j]=='X'||c[i][j]=='O'){
					k=1;
					printf ("La casilla esta ocupada, intentalo con otro numero.\n\n");
				}
				break;
				
			case '8':
				i=2;
				j=1;
				if (c[i][j]=='X'||c[i][j]=='O'){
					k=1;
					printf ("La casilla esta ocupada, intentalo con otro numero.\n\n");
				}
				break;
				
			case '9':
				i=2;
				j=2;
				if (c[i][j]=='X'||c[i][j]=='O'){
					k=1;
					printf ("La casilla esta ocupada, intentalo con otro numero.\n\n");
				}
				break;
		}
	} while (k==1);
	
	c[i][j]='O';
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

//ADIVINA EL NÚMERO
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
		printf ("\nEscribe un numero:\n");
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
