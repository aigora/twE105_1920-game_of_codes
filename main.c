#include <stdio.h>
#include <stdlib.h>
#include "GameOfCodes.h"

int main ()
{
	int a;
	char c[3][3];
	char nombre[20];
	
	presentacion();
	
	do{
		printf ("\nMENU PRINCIPAL\
		        \n Seleccione una opcion (1-5):\
		        \n 1) Tres en raya.\
				\n 2) Adivina el numero.\
				\n 3) Heroes.\
				\n 4) Preguntados.\ 
			        //Preguntados: juego de responder preguntas de cultura generl sobre diversos temas.
			        // Seguramente añadiremos más juegos
				\n 5) Salir del programa.\n ");
		scanf ("%i", &a);
		
		switch (a)
		{
			case 1:
				loop(c);
			break;
			
			case 2:
				adivina();
			break;
			
			case 3:
				heroesVSvillano();
			break;
			
			case 4:
				// función referida al juego 4
			break;
		}	
	} while (a!=5);
}
