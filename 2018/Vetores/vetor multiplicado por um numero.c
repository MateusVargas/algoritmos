/*02 - Escreva um programa que leia um vetor a de N números reais, (N<=100) e um outro real k e contrua e imprima um outro vetor b cujos elementos são os respectivos elementos de a multiplicados por k. Por exemplo: a = {1,2,3}, k = 5, b = {5,10,15}*/

#include <stdio.h>
#include <conio.h>
int i;
main()
{
	int vetA[5],vetB[5];
	float k;
	
	printf("informe o vetor A\n");
	for(i=0;i<5;i++)
	{
		printf("vetA[%d]= ",i+1);
		scanf("%d",&vetA[i]);
	
	}
	
	printf("valor de K: ");
	scanf("%f",&k);
	
	for(i=0;i<5;i++)
	{
		vetB[i]=vetA[i]*k;
	
	}
	
	for(i=0;i<5;i++)
		printf("vetB= %d\n",vetB[i]);
			
}
