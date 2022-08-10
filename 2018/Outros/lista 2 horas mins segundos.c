#include <stdio.h>
#include <conio.h>

int main ()
{
	int hora, minuto, segundo;
	printf("digite a hora: ");
	scanf("%i",&hora);
	printf("digite os minutos: ");
	scanf("%i",&minuto);
	printf("digite os segundos: ");
	scanf("%i",&segundo);
	printf("horario de brasilia: %i:%i:%i",hora,minuto,segundo);
	
	if (hora < 0||hora > 23){
		printf("hora invalida \n");
	}
	else if (minuto <0||minuto > 59){
		printf("minuto invalido \n");
	}
	else if (segundo < 0||segundo>59){
		printf("segundo invalido");
	}	
	getche();
}
