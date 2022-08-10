#include <stdio.h>
#include <conio.h>
#define tamanho 50

int i;

int le_vetor(int v[tamanho],int num)
{
	for(i=0;i<num;i++)
	{	
	printf("V[%d]= ",i);
	scanf("%d",&v[i]);
}	
	
}

int escreve_vetor(int v[tamanho],int num)
{
	printf("\n");	
	for(i=0;i<num;i++)
	{
	printf("%d\t",v[i]);
}

}

int troca_vetor(int v[],int num)
{
	printf("\n");
	int aux,i;
	for(i=0;i<num;i=i+2)
	{
		aux=v[i];
		v[i]=v[i+1];
		v[i+1]=aux;
	}
	printf("vetor com os indices impares trocados com os pares\n");
	for(i=0;i<num;i++)
	printf("%d\t",v[i]);
}

main()
{
	int vetor[tamanho],numero;
	printf("qual o tamanho do vetor: ");
	scanf("%d",&numero);
	
	le_vetor(vetor,numero);	
	escreve_vetor(vetor,numero);
	troca_vetor(vetor,numero);
	
	getche();
}
