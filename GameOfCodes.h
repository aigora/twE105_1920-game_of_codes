//PRESENTACION
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
void jugador (char c[3][3], int jug);
void casilla_ocupada (char c[3][3], char aux, char signo);
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

//PREGUNTADOS
#define Num 10
#define MaxNum_Caracteres 250
void Preguntados();
//Ciencia
void P_Ciencia();
void ciencia_preguntas (char preguntas[Num][MaxNum_Caracteres]);
void ciencia_respuestas (char respuestas[Num][MaxNum_Caracteres]);
void ciencia_respuesta_correcta (char respuesta_correcta[Num]);
//Geografia
void P_Geografia();
void geografia_preguntas (char preguntas[Num][MaxNum_Caracteres]);
void geografia_respuestas (char respuestas[Num][MaxNum_Caracteres]);
void geografia_respuesta_correcta (char respuesta_correcta[Num]);
//Deportes
void P_Deportes();
void deportes_preguntas (char preguntas[Num][MaxNum_Caracteres]);
void deportes_respuestas (char respuestas[Num][MaxNum_Caracteres]);
void deportes_respuesta_correcta (char respuesta_correcta[Num]);
//Historia
void P_Historia();
void historia_preguntas (char preguntas[Num][MaxNum_Caracteres]);
void historia_respuestas (char respuestas[Num][MaxNum_Caracteres]);
void historia_respuesta_correcta (char respuesta_correcta[Num]);

//BUSCAMINAS
void buscaminas();
void modoFacil(); //presenta tablero de 6x6 y 6 minas
void modoDificil(); //presentatablero de 9x9 y 9 minas
