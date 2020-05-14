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
void Preguntados();
//Ciencia
void P_Ciencia();
void ciencia_q1(); //Muestra la primera pregunta
void ciencia_q2(); //Muestra la segunda pregunta
void ciencia_q3(); //Muestra la tercera pregunta
void ciencia_q4(); //Muestra la cuarta pregunta
void ciencia_q5(); //Muestra la quinta pregunta
void ciencia_q6(); //Muestra la sexta pregunta
void ciencia_q7(); //Muestra la septima pregunta
void ciencia_q8(); //Muestra la octava pregunta
void ciencia_q9(); //Muestra la novena pregunta
void ciencia_q10(); //Muestra la decima pregunta
//Geografia
void P_Geografia();
void geografia_q1(); //Muestra la primera pregunta
void geografia_q2(); //Muestra la segunda pregunta
void geografia_q3(); //Muestra la tercera pregunta
void geografia_q4(); //Muestra la cuarta pregunta
void geografia_q5(); //Muestra la quinta pregunta
void geografia_q6(); //Muestra la sexta pregunta
void geografia_q7(); //Muestra la septima pregunta
void geografia_q8(); //Muestra la octava pregunta
void geografia_q9(); //Muestra la novena pregunta
void geografia_q10(); //Muestra la decima pregunta
//Deporte
void P_Deporte();
void deporte_q1(); //Muestra la primera pregunta
void deporte_q2(); //Muestra la segunda pregunta
void deporte_q3(); //Muestra la tercera pregunta
void deporte_q4(); //Muestra la cuarta pregunta
void deporte_q5(); //Muestra la quinta pregunta
void deporte_q6(); //Muestra la sexta pregunta
void deporte_q7(); //Muestra la septima pregunta
void deporte_q8(); //Muestra la octava pregunta
void deporte_q9(); //Muestra la novena pregunta
void deporte_q10(); //Muestra la decima pregunta
//Historia
void P_Historia();
void historia_q1(); //Muestra la primera pregunta
void historia_q2(); //Muestra la segunda pregunta
void historia_q3(); //Muestra la tercera pregunta
void historia_q4(); //Muestra la cuarta pregunta
void historia_q5(); //Muestra la quinta pregunta
void historia_q6(); //Muestra la sexta pregunta
void historia_q7(); //Muestra la septima pregunta
void historia_q8(); //Muestra la octava pregunta
void historia_q9(); //Muestra la novena pregunta
void historia_q10(); //Muestra la decima pregunta

//BUSCAMINAS
void Buscaminas();
void modoFacil(); //presenta tablero de 8x8 y 4 minas
void modoDificil(); //presentatablero de 10x10 y 6 minas
void modoextremo(); //Presenta tablero de 12x12 y 8 minas
