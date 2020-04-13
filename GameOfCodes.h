//PRESENTACIÓN
typedef struct{
	char nombre[10];
	char apellidos[20];
	int edad;
	char sexo[10];
}datos;

void presentacion();

//TRES EN RAYA
void loop (char c[3][3]);
void Intro_Primera (char c[3][3]);
void tablero (char c[3][3]);
void jugador1 (char c[3][3]);
void jugador2 (char c[3][3]);
void maquina (char c[3][3]);
int ganador (char c[3][3]);

//ADIVINA EL NUMERO
void adivina();
float aleatorio (float n1, float n2, float n3, float n4, float n5);

//HEROES
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
