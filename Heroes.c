//HEROES CONTRA VILLANOS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
	int salud;
	int fuerza;
	int curar;
	int magia;
}heroe;

typedef struct{
	int salud;
	int fuerza;
}enemigo;

heroe usuario;
enemigo maquina;

void heroesVSvillano();
void clasico();
void fortachon();
void curandera();
void mago();
void villano();

int main ()
{
	heroesVSvillano();
	system ("pause");
	return 0;
}

void heroesVSvillano ()
{
	int per, op, pegar, curar, magia, aleatorio;
	villano();
	
	do{
	printf ("Elige a un HEROE:\
	         \n 1) Clasico (Tiene un ataque y una curacion de 50 puntos).\
			 \n 2) Fortachon (Tiene un ataque de 100 puntos y una curacion de 25 puntos).\
			 \n 3) Curandera (Tiene un ataque de 25 puntos y una curacion de 100 puntos).\
			 \n 4) Mago (Te lo juegas todo a una carta. El mago puede matar al villano de un solo golpe.\
			 \n Sin embargo, si falla, morira con un solo golpe).\n");
	scanf ("%i", &per);
	} while (per!=1 && per!=2 && per!=3 && per!=4);
	
	if (per==1)
	clasico();
	else if (per==2)
	fortachon();
	else if(per==3)
	curandera();
	else if(per==4)
	mago();
	
	if (per==4)
	{    	
    	srand(time(NULL));
    	aleatorio = rand()%2; // Si sale 0 pierdes, si sale 1 ganas
    	if (aleatorio==0)
    	{
    		printf ("\nTurno del villano:\n");
            pegar = maquina.fuerza;
            printf ("Te han herido %i puntos\n", pegar);
            usuario.salud -= pegar;
            printf ("Tu salud es de %i\n", usuario.salud);
            printf ("\nOHH NOOO !!! HAS PERDIDO.\n\n");
		}
		else if (aleatorio==1)
		{
			magia = usuario.magia;
  	    	printf ("\nHas herido a tu enemigo %i puntos\n", magia);
            maquina.salud -= magia;
            printf ("La salud del villano es: %i puntos\n", maquina.salud);
            printf ("\nENHORABUENA !!! HAS GANADO.\n\n");
		}
	}
	
	else
	{
	    do{
    	    printf ("\nEl villano tiene una vida de: %i.\n", maquina.salud);
    		do{
    			printf ("Elige una opcion (1 o 2):\
    			        \n 1) Atacar.\
    					\n 2) Curar.\n");
    			scanf ("%i", &op);
    		} while (op!=1 && op!=2);
		
    		if (maquina.salud > 0)
    		{
    			switch (op)
    			{
    				case 1:
    					pegar = usuario.fuerza;
    	        		printf ("\nHas herido a tu enemigo %i puntos\n", pegar);
    	        		maquina.salud -= pegar;
    	        		printf ("La salud del villano es: %i puntos\n", maquina.salud);
    	        		break;
	    		
    	    		case 2:
    	    			curar = usuario.curar;
    	    			printf ("\nHas elevado tu vida %i puntos\n", curar);
    	    			usuario.salud += curar;
    	    			printf ("Tu salud es de: %i puntos\n", usuario.salud);
    	    			break;
    			}
		
    			if (maquina.salud > 0)
    			{
    				printf ("\nTurno del villano:\n");
            	    pegar = maquina.fuerza;
                	printf ("Te han herido %i puntos\n", pegar);
                	usuario.salud -= pegar;
                	printf ("Tu salud es de %i\n", usuario.salud);
    			}
    			else{
    				printf ("\nENHORABUENA !!! HAS GANADO.\n\n");
    			}
	    	}   
	    } while(usuario.salud>0 && maquina.salud>0);
	    if (usuario.salud<=0)
    	printf("\nOHH NOOO !!! HAS PERDIDO.\n\n");
	}
}

void clasico()
{
	usuario.salud = 200;
	usuario.fuerza = 50;
	usuario.curar = 50;
}

void fortachon()
{
	usuario.salud = 200;
	usuario.fuerza = 100;
	usuario.curar = 25;
}

void curandera()
{
	usuario.salud = 200;
	usuario.fuerza = 25;
	usuario.curar = 100;
}

void mago()
{
	usuario.salud = 50;
	usuario.magia = 350;
}

void villano()
{
	maquina.salud = 350;
	maquina.fuerza = 50;
}
