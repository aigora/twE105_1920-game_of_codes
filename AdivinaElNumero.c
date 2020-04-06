#include <stdio.h>
#define intentos 2 //número de intentos permitidos
#include <time.h>

void adivina();
float aleatorio (float n1, float n2, float n3, float n4, float n5);

int main ()
{
	adivina();
	system("pause");
	return 0;
}

void adivina()
{
    FILE *pf;
	int n=0, i=0;
	float n1, n2, n3, n4, n5, numero, tecleado;
	pf = fopen ("Numeros_Adivina.txt", "a");
	
	printf ("Introduce 5 numeros diferentes, por favor.\n");
	scanf ("%f %f %f %f %f", &n1, &n2, &n3, &n4, &n5);
	fprintf (pf, "Los numeros escogidos por el usuario son: %.2f, %.2f, %.2f, %.2f y %.2f\n", n1,n2,n3,n4,n5);
	
	printf ("Los numeros escogidos son los siguientes:\
	         \n %.2f  %.2f  %.2f  %.2f  %.2f\
			 \nAhora yo he escogido uno de esos numeros al azar.\
			 \nTE RETO A ADIVINARLO, BUENA SUERTE !!!\n", n1,n2,n3,n4,n5);
	
	numero = aleatorio(n1,n2,n3,n4,n5);
	fprintf (pf, "El numero escogido aleatoriamente ha sido el %.2f\n", numero);
	
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
