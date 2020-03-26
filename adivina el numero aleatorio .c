#include <stdio.h>
#include <stdlib.h> //para srand() y rand()
#include <time.h> //para time()
void main()
{
	int numero,tecleado;
do
{
	srand(time(NULL));//inicializar semilla aleatoria
	numero=rand()%100;//generar numero aleatorio
 do
 { 
 printf("Intenta adivinar un numero entre el 1 y el 100: ");
 scanf("%d",&tecleado); 
 
	 if(numero<tecleado)
	 {
 			printf("El numero tecleado es mayor que el pensado, sigue intentando\n");
	 }
 	if(numero>tecleado)
		{
			printf("El numero tecleado es menor que el pensado, sigue intentando\n");
		}
	}while(numero!=tecleado);
   printf("FELICIDADES,has acertado\n");
   }while(1);
}
