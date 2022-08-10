#include <stdio.h>
#include <stdlib.h>
int main ()

{
	float peso, aumento_de_peso, queda_de_peso;
	printf("informe seu peso: ");
	scanf("%f",&peso);
	aumento_de_peso = peso * 1.15;
	printf("se voce engordar 15 por cento seu peso sera de: %.2f kg \n",aumento_de_peso);
	queda_de_peso = peso * 0.80;
	printf("se voce emagrecer 20 por cento seu peso sera de: %.2f kg \n",queda_de_peso);
	
	system("pause");	
}
