#include <stdio.h>
#include <stdlib.h>
#include "GameOfCodes.h"

int main ()
{
	int a;
	char repet; //variable que evalua cuando se va a repetir el programa, tras haber jugado previamente
	char c[3][3];
	char nombre[20];
	
	presentacion();
	
	do{
		printf ("\nMENU PRINCIPAL\
		        \n Seleccione una opcion (1-5):\
		        \n 1) Tres en raya.\
				\n 2) Adivina el numero.\
				\n 3) Heroes.\
				\n 4) \
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
		printf("Genial!! Has terminado el juego, espero que te hayas divertido.\n Quieres jugar a otro juego?\t Pulsa '1'\n Prefieres salir del juego?\t Pulsa '0'");
		do
		{
			
		}
		while();
	} while (a!=5);
}
