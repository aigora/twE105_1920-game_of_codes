#include <stdio.h>
#include <time.h>
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



int main ()
{
	Preguntados();
	return 0;
}

void Preguntados()
{
	int t;
	char k;
	
	printf ("BIENVENIDO A PREGUNTADOS !!!\
	        \nPreguntados es un juego de cultura general, donde aleatoriamente se escogera un tema.\
			\nEl tema puede ser ciencia, historia, geografia o deportes.\
			\nDicho esto, empecemos.\n\n");
	
	do{	
	    srand(time(NULL));
	    t = rand()%3;
	
    	if (t==0)
    	P_Ciencia();
	
		else if(t==1)
		P_Deporte();	
	
    	else
    	P_Geografia();
    	
    	printf ("Parece que ya has terminado.\
		        \nTe gustaria volver a jugar (S/N)? Recuerda que te puede tocar un tema diferente.\n");
    	scanf (" %c", &k);
    }while (k=='s' || k=='S');
}

//Geografia
void P_Geografia()
{
int respuesta;
	char s;
	
	do{
	printf ("Tema escogido: GEOGRAFIA\n");
	geografia_q1();
	scanf ("%i", &respuesta);
	printf("\n");
	
	if (respuesta == 3)
	{
		printf ("CORRECTO !!! Pasas a la siguiente pregunta.\n");
		geografia_q2();
		scanf ("%i", &respuesta);
		printf("\n");
		
		if (respuesta == 3)
		{
			printf ("CORRECTO !!! Pasas a la siguiente pregunta.\n");
			geografia_q3();
			scanf ("%i", &respuesta);
			printf("\n");
			
			if (respuesta == 1)
			{
				printf ("CORRECTO !!! Pasas a la siguiente pregunta.\n");
				geografia_q4();
				scanf ("%i", &respuesta);
				printf("\n");
				
				if (respuesta == 2)
				{
					printf ("CORRECTA !!! Pasas a la siguiente.\n");
					geografia_q5();
					scanf ("%i", &respuesta);
					printf("\n");
					
					if (respuesta == 2)
					{
						printf ("CORRECTO !!! Pasas a la siguiente pregunta.\n");
						geografia_q6();
						scanf ("%i", &respuesta);
						printf("\n");
						
						if (respuesta == 3)
						{
							printf ("CORRECTO !!! Pasas a la siguiente pregunta.\n");
							geografia_q7();
							scanf ("%i", &respuesta);
							printf("\n");
							
							if (respuesta == 1)
							{
								printf ("CORRECTO !!! Pasas a la siguiente pregunta.\n");
								geografia_q8();
								scanf ("%i", &respuesta);
								printf("\n");
								
								if (respuesta == 1)
								{
									printf ("CORRECTO !!! Pasas a la siguiente pregunta.\n");
									geografia_q9();
									scanf ("%i", &respuesta);
									printf("\n");
									
									if (respuesta == 2)
									{
										printf ("CORRECTO !!! Pasas a la ultima pregunta.\n");
										geografia_q10();
										scanf ("%i", &respuesta);
										printf("\n");
										
										if (respuesta == 3)
										printf ("ENHORABUENA !!! HAS PASADO EL TEST DE GEOGRAFIA\n");
										
										else
                                     	{
                             	        	printf ("Lo siento, la respuesta es incorrecta.\n");
                            	        	printf ("Quieres volver a intentarlo? (S/N)\n");
                             	        	scanf (" %c", &s);
                                      	}
									}
									
									else
                                 	{
        	                        	printf ("Lo siento, la respuesta es incorrecta.\n");
        	                        	printf ("Quieres volver a intentarlo? (S/N)\n");
          	                         	scanf (" %c", &s);
                                	}
								}
								
								else
                            	{
        	                    	printf ("Lo siento, la respuesta es incorrecta.\n");
        	                      	printf ("Quieres volver a intentarlo? (S/N)\n");
          	                    	scanf (" %c", &s);
                            	}
							}
							
							else
                        	{
        	                	printf ("Lo siento, la respuesta es incorrecta.\n");
        	                	printf ("Quieres volver a intentarlo? (S/N)\n");
                	        	scanf (" %c", &s);
                        	}
						}
						
						else
                      	{
        	            	printf ("Lo siento, la respuesta es incorrecta.\n");
        	             	printf ("Quieres volver a intentarlo? (S/N)\n");
          	            	scanf (" %c", &s);
                    	}
					}
					
	  				else
                	{
        	        	printf ("Lo siento, la respuesta es incorrecta.\n");
        	        	printf ("Quieres volver a intentarlo? (S/N)\n");
          	        	scanf (" %c", &s);
                	}
				}
				
				else
            	{
        	    	printf ("Lo siento, la respuesta es incorrecta.\n");
             		printf ("Quieres volver a intentarlo? (S/N)\n");
                	scanf (" %c", &s);
             	}
			}
			
			else
        	{
        		printf ("Lo siento, la respuesta es incorrecta.\n");
        		printf ("Quieres volver a intentarlo? (S/N)\n");
          		scanf (" %c", &s);
         	}
		}
		
		else
    	{
    		printf ("Lo siento, la respuesta es incorrecta.\n");
    		printf ("Quieres volver a intentarlo? (S/N)\n");
    		scanf (" %c", &s);
    	}
	}
	
	else
	{
		printf ("Lo siento, la respuesta es incorrecta.\n");
		printf ("Quieres volver a intentarlo? (S/N)\n");
		scanf (" %c", &s);
	}
	} while (s=='s' || s=='S');
}

void geografia_q1()
{
	char pregunta1;
	FILE *q1;
	q1 = fopen ("Preguntados/P_Geografia/q1.txt", "r");
	if (q1==NULL){
		printf ("No se ha podido abrir el archivo.\n");
	}
	while (fscanf (q1, "%c", &pregunta1) != EOF)
	printf ("%c", pregunta1);
	printf ("\n");
	fclose(q1);
}

void geografia_q2()
{
	char pregunta2;
	FILE *q2;
	q2 = fopen ("Preguntados/P_Geografia/q2.txt", "r");
	if (q2==NULL){
		printf ("No se ha podido abrir el archivo.\n");
	}
	while (fscanf (q2, "%c", &pregunta2) != EOF)
	printf ("%c", pregunta2);
	printf("\n");
	fclose(q2);
}

void geografia_q3()
{
	char pregunta3;
	FILE *q3;
	q3 = fopen ("Preguntados/P_Geografia/q3.txt", "r");
	if (q3==NULL){
		printf ("No se ha podido abrir el archivo.\n");
	}
	while (fscanf (q3, "%c", &pregunta3) != EOF)
	printf ("%c", pregunta3);
	printf("\n");
	fclose(q3);
}

void geografia_q4()
{
	char pregunta4;
	FILE *q4;
	q4 = fopen ("Preguntados/P_Geografia/q4.txt", "r");
	if (q4==NULL){
		printf ("No se ha podido abrir el archivo.\n");
	}
	while (fscanf (q4, "%c", &pregunta4) != EOF)
	printf ("%c", pregunta4);
	printf("\n");
	fclose(q4);
}

void geografia_q5()
{
	char pregunta5;
	FILE *q5;
	q5 = fopen ("Preguntados/P_Geografia/q5.txt", "r");
	if (q5==NULL){
		printf ("No se ha podido abrir el archivo.\n");
	}
	while (fscanf (q5, "%c", &pregunta5) != EOF)
	printf ("%c", pregunta5);
	printf("\n");
	fclose(q5);
}

void geografia_q6()
{
	char pregunta6;
	FILE *q6;
	q6 = fopen ("Preguntados/P_Geografia/q6.txt", "r");
	if (q6==NULL){
		printf ("No se ha podido abrir el archivo.\n");
	}
	while (fscanf (q6, "%c", &pregunta6) != EOF)
	printf ("%c", pregunta6);
	printf("\n");
	fclose(q6);
}

void geografia_q7()
{
	char pregunta7;
	FILE *q7;
	q7 = fopen ("Preguntados/P_Geografia/q7.txt", "r");
	if (q7==NULL){
		printf ("No se ha podido abrir el archivo.\n");
	}
	while (fscanf (q7, "%c", &pregunta7) != EOF)
	printf ("%c", pregunta7);
	printf("\n");
	fclose(q7);
}

void geografia_q8()
{
	char pregunta8;
	FILE *q8;
	q8 = fopen ("Preguntados/P_Geografia/q8.txt", "r");
	if (q8==NULL){
		printf ("No se ha podido abrir el archivo.\n");
	}
	while (fscanf (q8, "%c", &pregunta8) != EOF)
	printf ("%c", pregunta8);
	printf("\n");
	fclose(q8);
}

void geografia_q9()
{
	char pregunta9;
	FILE *q9;
	q9 = fopen ("Preguntados/P_Geografia/q9.txt", "r");
	if (q9==NULL){
		printf ("No se ha podido abrir el archivo.\n");
	}
	while (fscanf (q9, "%c", &pregunta9) != EOF)
	printf ("%c", pregunta9);
	printf("\n");
	fclose(q9);
}

void geografia_q10()
{
	char pregunta10;
	FILE *q10;
	q10 = fopen ("Preguntados/P_Geografia/q10.txt", "r");
	if (q10==NULL){
		printf ("No se ha podido abrir el archivo.\n");
	}
	while (fscanf (q10, "%c", &pregunta10) != EOF)
	printf ("%c", pregunta10);
	printf("\n");
	fclose(q10);
}


//Ciencia
void P_Ciencia()
{
	int respuesta;
	char s;
	
	do{
	printf ("Tema escogido: CIENCIA\n");
	ciencia_q1();
	scanf ("%i", &respuesta);
	printf("\n");
	
	if (respuesta == 2)
	{
		printf ("CORRECTO !!! Pasas a la siguiente pregunta.\n");
		ciencia_q2();
		scanf ("%i", &respuesta);
		printf("\n");
		
		if (respuesta == 1)
		{
			printf ("CORRECTO !!! Pasas a la siguiente pregunta.\n");
			ciencia_q3();
			scanf ("%i", &respuesta);
			printf("\n");
			
			if (respuesta == 2)
			{
				printf ("CORRECTO !!! Pasas a la siguiente pregunta.\n");
				ciencia_q4();
				scanf ("%i", &respuesta);
				printf("\n");
				
				if (respuesta == 3)
				{
					printf ("CORRECTA !!! Pasas a la siguiente.\n");
					ciencia_q5();
					scanf ("%i", &respuesta);
					printf("\n");
					
					if (respuesta == 1)
					{
						printf ("CORRECTO !!! Pasas a la siguiente pregunta.\n");
						ciencia_q6();
						scanf ("%i", &respuesta);
						printf("\n");
						
						if (respuesta == 1)
						{
							printf ("CORRECTO !!! Pasas a la siguiente pregunta.\n");
							ciencia_q7();
							scanf ("%i", &respuesta);
							printf("\n");
							
							if (respuesta == 3)
							{
								printf ("CORRECTO !!! Pasas a la siguiente pregunta.\n");
								ciencia_q8();
								scanf ("%i", &respuesta);
								printf("\n");
								
								if (respuesta == 2)
								{
									printf ("CORRECTO !!! Pasas a la siguiente pregunta.\n");
									ciencia_q9();
									scanf ("%i", &respuesta);
									printf("\n");
									
									if (respuesta == 1)
									{
										printf ("CORRECTO !!! Pasas a la ultima pregunta.\n");
										ciencia_q10();
										scanf ("%i", &respuesta);
										printf("\n");
										
										if (respuesta == 3)
										printf ("ENHORABUENA !!! HAS PASADO EL TEST DE CIENCIA\n");
										
										else
                                     	{
                             	        	printf ("Lo siento, la respuesta es incorrecta.\n");
                            	        	printf ("Quieres volver a intentarlo? (S/N)\n");
                             	        	scanf (" %c", &s);
                                      	}
									}
									
									else
                                 	{
        	                        	printf ("Lo siento, la respuesta es incorrecta.\n");
        	                        	printf ("Quieres volver a intentarlo? (S/N)\n");
          	                         	scanf (" %c", &s);
                                	}
								}
								
								else
                            	{
        	                    	printf ("Lo siento, la respuesta es incorrecta.\n");
        	                      	printf ("Quieres volver a intentarlo? (S/N)\n");
          	                    	scanf (" %c", &s);
                            	}
							}
							
							else
                        	{
        	                	printf ("Lo siento, la respuesta es incorrecta.\n");
        	                	printf ("Quieres volver a intentarlo? (S/N)\n");
                	        	scanf (" %c", &s);
                        	}
						}
						
						else
                      	{
        	            	printf ("Lo siento, la respuesta es incorrecta.\n");
        	             	printf ("Quieres volver a intentarlo? (S/N)\n");
          	            	scanf (" %c", &s);
                    	}
					}
					
	  				else
                	{
        	        	printf ("Lo siento, la respuesta es incorrecta.\n");
        	        	printf ("Quieres volver a intentarlo? (S/N)\n");
          	        	scanf (" %c", &s);
                	}
				}
				
				else
            	{
        	    	printf ("Lo siento, la respuesta es incorrecta.\n");
             		printf ("Quieres volver a intentarlo? (S/N)\n");
                	scanf (" %c", &s);
             	}
			}
			
			else
        	{
        		printf ("Lo siento, la respuesta es incorrecta.\n");
        		printf ("Quieres volver a intentarlo? (S/N)\n");
          		scanf (" %c", &s);
         	}
		}
		
		else
    	{
    		printf ("Lo siento, la respuesta es incorrecta.\n");
    		printf ("Quieres volver a intentarlo? (S/N)\n");
    		scanf (" %c", &s);
    	}
	}
	
	else
	{
		printf ("Lo siento, la respuesta es incorrecta.\n");
		printf ("Quieres volver a intentarlo? (S/N)\n");
		scanf (" %c", &s);
	}
	} while (s=='s' || s=='S');
}

void ciencia_q1()
{
	char pregunta1;
	FILE *q1;
	q1 = fopen ("Preguntados/P_Ciencia/q1.txt", "r");
	if (q1==NULL){
		printf ("No se ha podido abrir el archivo.\n");
	}
	while (fscanf (q1, "%c", &pregunta1) != EOF)
	printf ("%c", pregunta1);
	printf ("\n");
	fclose(q1);
}

void ciencia_q2()
{
	char pregunta2;
	FILE *q2;
	q2 = fopen ("Preguntados/P_Ciencia/q2.txt", "r");
	if (q2==NULL){
		printf ("No se ha podido abrir el archivo.\n");
	}
	while (fscanf (q2, "%c", &pregunta2) != EOF)
	printf ("%c", pregunta2);
	printf("\n");
	fclose(q2);
}

void ciencia_q3()
{
	char pregunta3;
	FILE *q3;
	q3 = fopen ("Preguntados/P_Ciencia/q3.txt", "r");
	if (q3==NULL){
		printf ("No se ha podido abrir el archivo.\n");
	}
	while (fscanf (q3, "%c", &pregunta3) != EOF)
	printf ("%c", pregunta3);
	printf("\n");
	fclose(q3);
}

void ciencia_q4()
{
	char pregunta4;
	FILE *q4;
	q4 = fopen ("Preguntados/P_Ciencia/q4.txt", "r");
	if (q4==NULL){
		printf ("No se ha podido abrir el archivo.\n");
	}
	while (fscanf (q4, "%c", &pregunta4) != EOF)
	printf ("%c", pregunta4);
	printf("\n");
	fclose(q4);
}

void ciencia_q5()
{
	char pregunta5;
	FILE *q5;
	q5 = fopen ("Preguntados/P_Ciencia/q5.txt", "r");
	if (q5==NULL){
		printf ("No se ha podido abrir el archivo.\n");
	}
	while (fscanf (q5, "%c", &pregunta5) != EOF)
	printf ("%c", pregunta5);
	printf("\n");
	fclose(q5);
}

void ciencia_q6()
{
	char pregunta6;
	FILE *q6;
	q6 = fopen ("Preguntados/P_Ciencia/q6.txt", "r");
	if (q6==NULL){
		printf ("No se ha podido abrir el archivo.\n");
	}
	while (fscanf (q6, "%c", &pregunta6) != EOF)
	printf ("%c", pregunta6);
	printf("\n");
	fclose(q6);
}

void ciencia_q7()
{
	char pregunta7;
	FILE *q7;
	q7 = fopen ("Preguntados/P_Ciencia/q7.txt", "r");
	if (q7==NULL){
		printf ("No se ha podido abrir el archivo.\n");
	}
	while (fscanf (q7, "%c", &pregunta7) != EOF)
	printf ("%c", pregunta7);
	printf("\n");
	fclose(q7);
}

void ciencia_q8()
{
	char pregunta8;
	FILE *q8;
	q8 = fopen ("Preguntados/P_Ciencia/q8.txt", "r");
	if (q8==NULL){
		printf ("No se ha podido abrir el archivo.\n");
	}
	while (fscanf (q8, "%c", &pregunta8) != EOF)
	printf ("%c", pregunta8);
	printf("\n");
	fclose(q8);
}

void ciencia_q9()
{
	char pregunta9;
	FILE *q9;
	q9 = fopen ("Preguntados/P_Ciencia/q9.txt", "r");
	if (q9==NULL){
		printf ("No se ha podido abrir el archivo.\n");
	}
	while (fscanf (q9, "%c", &pregunta9) != EOF)
	printf ("%c", pregunta9);
	printf("\n");
	fclose(q9);
}

void ciencia_q10()
{
	char pregunta10;
	FILE *q10;
	q10 = fopen ("Preguntados/P_Ciencia/q10.txt", "r");
	if (q10==NULL){
		printf ("No se ha podido abrir el archivo.\n");
	}
	while (fscanf (q10, "%c", &pregunta10) != EOF)
	printf ("%c", pregunta10);
	printf("\n");
	fclose(q10);
}


//Deporte
void P_Deporte()
{
	int respuesta;
	char s;
	
	do{
	printf ("Tema escogido: DEPORTE\n");
	deporte_q1();
	scanf ("%i", &respuesta);
	printf("\n");
	
	if (respuesta == 1)
	{
		printf ("CORRECTO !!! Pasas a la siguiente pregunta.\n");
		deporte_q2();
		scanf ("%i", &respuesta);
		printf("\n");
		
		if (respuesta == 3)
		{
			printf ("CORRECTO !!! Pasas a la siguiente pregunta.\n");
			deporte_q3();
			scanf ("%i", &respuesta);
			printf("\n");
			
			if (respuesta == 1)
			{
				printf ("CORRECTO !!! Pasas a la siguiente pregunta.\n");
				deporte_q4();
				scanf ("%i", &respuesta);
				printf("\n");
				
				if (respuesta == 2)
				{
					printf ("CORRECTA !!! Pasas a la siguiente.\n");
					deporte_q5();
					scanf ("%i", &respuesta);
					printf("\n");
					
					if (respuesta == 1)
					{
						printf ("CORRECTO !!! Pasas a la siguiente pregunta.\n");
						deporte_q6();
						scanf ("%i", &respuesta);
						printf("\n");
						
						if (respuesta == 3)
						{
							printf ("CORRECTO !!! Pasas a la siguiente pregunta.\n");
							deporte_q7();
							scanf ("%i", &respuesta);
							printf("\n");
							
							if (respuesta == 2)
							{
								printf ("CORRECTO !!! Pasas a la siguiente pregunta.\n");
								deporte_q8();
								scanf ("%i", &respuesta);
								printf("\n");
								
								if (respuesta == 3)
								{
									printf ("CORRECTO !!! Pasas a la siguiente pregunta.\n");
									deporte_q9();
									scanf ("%i", &respuesta);
									printf("\n");
									
									if (respuesta == 2)
									{
										printf ("CORRECTO !!! Pasas a la ultima pregunta.\n");
										deporte_q10();
										scanf ("%i", &respuesta);
										printf("\n");
										
										if (respuesta == 2)
										printf ("ENHORABUENA !!! HAS PASADO EL TEST DE DEPORTE\n");
										
										else
                                     	{
                             	        	printf ("Lo siento, la respuesta es incorrecta.\n");
                            	        	printf ("Quieres volver a intentarlo? (S/N)\n");
                             	        	scanf (" %c", &s);
                                      	}
									}
									
									else
                                 	{
        	                        	printf ("Lo siento, la respuesta es incorrecta.\n");
        	                        	printf ("Quieres volver a intentarlo? (S/N)\n");
          	                         	scanf (" %c", &s);
                                	}
								}
								
								else
                            	{
        	                    	printf ("Lo siento, la respuesta es incorrecta.\n");
        	                      	printf ("Quieres volver a intentarlo? (S/N)\n");
          	                    	scanf (" %c", &s);
                            	}
							}
							
							else
                        	{
        	                	printf ("Lo siento, la respuesta es incorrecta.\n");
        	                	printf ("Quieres volver a intentarlo? (S/N)\n");
                	        	scanf (" %c", &s);
                        	}
						}
						
						else
                      	{
        	            	printf ("Lo siento, la respuesta es incorrecta.\n");
        	             	printf ("Quieres volver a intentarlo? (S/N)\n");
          	            	scanf (" %c", &s);
                    	}
					}
					
	  				else
                	{
        	        	printf ("Lo siento, la respuesta es incorrecta.\n");
        	        	printf ("Quieres volver a intentarlo? (S/N)\n");
          	        	scanf (" %c", &s);
                	}
				}
				
				else
            	{
        	    	printf ("Lo siento, la respuesta es incorrecta.\n");
             		printf ("Quieres volver a intentarlo? (S/N)\n");
                	scanf (" %c", &s);
             	}
			}
			
			else
        	{
        		printf ("Lo siento, la respuesta es incorrecta.\n");
        		printf ("Quieres volver a intentarlo? (S/N)\n");
          		scanf (" %c", &s);
         	}
		}
		
		else
    	{
    		printf ("Lo siento, la respuesta es incorrecta.\n");
    		printf ("Quieres volver a intentarlo? (S/N)\n");
    		scanf (" %c", &s);
    	}
	}
	
	else
	{
		printf ("Lo siento, la respuesta es incorrecta.\n");
		printf ("Quieres volver a intentarlo? (S/N)\n");
		scanf (" %c", &s);
	}
	} while (s=='s' || s=='S');
}

void deporte_q1()
{
	char pregunta1;
	FILE *q1;
	q1 = fopen ("Preguntados/P_Deportes/q1.txt", "r");
	if (q1==NULL){
		printf ("No se ha podido abrir el archivo.\n");
	}
	while (fscanf (q1, "%c", &pregunta1) != EOF)
	printf ("%c", pregunta1);
	printf ("\n");
	fclose(q1);
}

void deporte_q2()
{
	char pregunta2;
	FILE *q2;
	q2 = fopen ("Preguntados/P_Deportes/q2.txt", "r");
	if (q2==NULL){
		printf ("No se ha podido abrir el archivo.\n");
	}
	while (fscanf (q2, "%c", &pregunta2) != EOF)
	printf ("%c", pregunta2);
	printf("\n");
	fclose(q2);
}

void deporte_q3()
{
	char pregunta3;
	FILE *q3;
	q3 = fopen ("Preguntados/P_Deportes/q3.txt", "r");
	if (q3==NULL){
		printf ("No se ha podido abrir el archivo.\n");
	}
	while (fscanf (q3, "%c", &pregunta3) != EOF)
	printf ("%c", pregunta3);
	printf("\n");
	fclose(q3);
}

void deporte_q4()
{
	char pregunta4;
	FILE *q4;
	q4 = fopen ("Preguntados/P_Deportes/q4.txt", "r");
	if (q4==NULL){
		printf ("No se ha podido abrir el archivo.\n");
	}
	while (fscanf (q4, "%c", &pregunta4) != EOF)
	printf ("%c", pregunta4);
	printf("\n");
	fclose(q4);
}

void deporte_q5()
{
	char pregunta5;
	FILE *q5;
	q5 = fopen ("Preguntados/P_Deportes/q5.txt", "r");
	if (q5==NULL){
		printf ("No se ha podido abrir el archivo.\n");
	}
	while (fscanf (q5, "%c", &pregunta5) != EOF)
	printf ("%c", pregunta5);
	printf("\n");
	fclose(q5);
}

void deporte_q6()
{
	char pregunta6;
	FILE *q6;
	q6 = fopen ("Preguntados/P_Deportes/q6.txt", "r");
	if (q6==NULL){
		printf ("No se ha podido abrir el archivo.\n");
	}
	while (fscanf (q6, "%c", &pregunta6) != EOF)
	printf ("%c", pregunta6);
	printf("\n");
	fclose(q6);
}

void deporte_q7()
{
	char pregunta7;
	FILE *q7;
	q7 = fopen ("Preguntados/P_Deportes/q7.txt", "r");
	if (q7==NULL){
		printf ("No se ha podido abrir el archivo.\n");
	}
	while (fscanf (q7, "%c", &pregunta7) != EOF)
	printf ("%c", pregunta7);
	printf("\n");
	fclose(q7);
}

void deporte_q8()
{
	char pregunta8;
	FILE *q8;
	q8 = fopen ("Preguntados/P_Deportes/q8.txt", "r");
	if (q8==NULL){
		printf ("No se ha podido abrir el archivo.\n");
	}
	while (fscanf (q8, "%c", &pregunta8) != EOF)
	printf ("%c", pregunta8);
	printf("\n");
	fclose(q8);
}

void deporte_q9()
{
	char pregunta9;
	FILE *q9;
	q9 = fopen ("Preguntados/P_Deportes/q9.txt", "r");
	if (q9==NULL){
		printf ("No se ha podido abrir el archivo.\n");
	}
	while (fscanf (q9, "%c", &pregunta9) != EOF)
	printf ("%c", pregunta9);
	printf("\n");
	fclose(q9);
}

void deporte_q10()
{
	char pregunta10;
	FILE *q10;
	q10 = fopen ("Preguntados/P_Deportes/q10.txt", "r");
	if (q10==NULL){
		printf ("No se ha podido abrir el archivo.\n");
	}
	while (fscanf (q10, "%c", &pregunta10) != EOF)
	printf ("%c", pregunta10);
	printf("\n");
	fclose(q10);
}
