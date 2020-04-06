//PRESENTACIÓN
#include <stdio.h>

typedef struct{
	char nombre[10];
	char apellidos[20];
	int edad;
	char sexo[10];
}datos;

void presentacion();

int main ()
{
	presentacion();
	system("pause");
	return 0;
}

void presentacion()
{
	FILE *u;
	datos usuario;
	u = fopen ("Usuario.txt", "a");
	if (u==NULL){
		printf ("No se ha podido abrir el archivo.\n");
	}
	printf("Muy buenas !!! Soy el encargado de la gran sala de recreativos GAME OF CODES.\
	       \nMi nombre es Stark. Antes de empezar, necesito que introduzca algunos datos personales.\n");
	printf ("Introduzca su nombre:\n");
	scanf ("%s", usuario.nombre);
	fprintf (u,"Nombre del usuario: %s\n",usuario.nombre);
	printf ("Introduzca sus apellidos:\n");
	scanf (" %[^\n]", usuario.apellidos);
	fprintf (u,"Apellidos del usuario: %s\n",usuario.apellidos);
	printf ("Introduzca su edad:\n");
	scanf ("%d", &usuario.edad);
	fprintf (u,"Edad del usuario: %d\n",usuario.edad);
	printf ("Introduzca su sexo:\n");
	scanf ("%s", usuario.sexo);
	fprintf (u,"Sexo del usuario: %s\n",usuario.sexo);
	
	printf ("Muy bien %s %s!. Tienes ganas de divertirte? Porque ya estamos listos para empezar.\
	        \nEn el siguiente menu puedes seleccionar con que quieres divertirte.\n", usuario.nombre, usuario.apellidos);
	
}
