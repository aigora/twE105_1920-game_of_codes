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
				\n 2) \
				\n 3) \
				\n 4) \
				\n 5) Salir del programa.\n ");
		scanf ("%i", &a);
		
		switch (a)
		{
			case 1:
				system("cls");
				loop(c);
			break;
			
			case 2:
			break;
			
			case 3:
			break;
			
			case 4:
			break;
		}	
	} while (a!=5);
}
