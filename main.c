#include <stdio.h>
#include <stdlib.h>
#include "GameOfCodes.h"

int main ()
{
	int a;
	int repet; //variable que evalua cuando se va a repetir el programa, tras haber jugado previamente
	char c[3][3];
	
	presentacion();
	
	do{
		printf ("\nMENU PRINCIPAL\
		        \n Seleccione una opcion:\
		        \n 1) Tres en raya.\
				\n 2) Adivina el numero.\
				\n 3) Heroes.\
				\n 4) Preguntados.\
				\n 5) Buscaminas.\
				\n Otro) Salir del programa.\n ");
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
				Preguntados();
				break;
			case 5:
				buscaminas(); 
			break;
				
			default:
				printf("Has escogido salir del juego. Hasta pronto !!!");
				sleep(1);
				exit(-1);
		}
		sleep(3);
		printf("Genial!! Has terminado el juego, espero que te hayas divertido.\n Quieres jugar a otro juego?\t Pulsa '1'\n Prefieres salir del juego?\t Pulsa '0'\n");
		do //segun la opcion que escoja el jugador, el programa se repite o no
		{
			scanf(" %i", &repet);
			switch(repet)
			{
				case 1: //si se escoge esta opcion(1), se repite la posibilidad de escoger juego
					printf("Estupendo, a que juego prefieres jugar ahora?\n");
					a!=7;
					repet!=6;
				break;
				case 0://si se escoge esta opcion(0), se finaliza el programa
					printf("Espero que te hayas divertido. Hasta pronto !!!\n");
					exit(-1); //permite salir del programa
				break;
				default:
					printf("No te he entendido, repite la opcion por favor: ");
					//a=5;
					repet=6;
				break;	
			}
		}while(repet==6);
	} while (a!=7);
}
