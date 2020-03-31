//HEROES CONTRA VILLANOS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
	int salud;
	int fuerza;
	int curar;
	int magia;
}yo;

typedef struct{
	int salud;
	int fuerza;
}enemigo;

void heroesVSvillano();

int main ()
{
	heroesVSvillano();
	system ("pause");
	return 0;
}

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
