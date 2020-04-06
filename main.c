#include <stdio.h>
#include "GameOfCodes.h"

int main ()
{
	int a;
	char c[3][3];
	
	do{	
		printf ("MENU PRINCIPAL\
		        \n Seleccione una opcion (1-5):\
		        \n 1) Tres en raya.\
			\n 2) Adivina el numero.\
			\n 3) Heroes.\
			\n 4) Proximos juegos. \
				\n 5) Salir del programa.\n ");
		scanf ("%i", &a);
		
		switch (a)
		{
			case 1:
				system("cls");
				loop(c);
			break;
			
			case 2:
				//funcion referida al juego de adivina el numero
			break;
			
			case 3:
				//funcion referida al juego de heroes
			break;
			
			case 4:
				//función referida a próximo juego.
			break;
		}	
	} while (a!=5);
}
