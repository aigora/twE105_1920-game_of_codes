#include "GameOfCodes.h"
#include <time.h>

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
	system ("cls");
	} while (a!=1 && a!=2 && a!=3);
	
	switch (a)
	{
		case 1:
			i=0;
	        do{
	        	system ("cls");
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
	
        	system ("cls");
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
	            system ("cls");
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
	
	        system ("cls");
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
