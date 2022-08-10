/*Implemente um programa em C que que dada a matriz MxM, escreva os 
seguintes subprogramas: 
a) uma função que devolve o maior dos elementos contidos na matriz; 
b) uma função que identifica se um determinado valor (passado como 
parâmetro) está contido na matriz; 
c) um procedimento que recebe esta matriz e devolve os elementos contidos 
em sua diagonal principal, copiados para um vetor.*/
#include <stdio.h>
#include <conio.h>

int i,j;

int maior_num(int mat[3][3])
{
	int maior=0;
	
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
	if(mat[i][j]>maior){
	maior=mat[i][j];
	}
	
	}
}
		
	printf("\nmaior elemento da matriz: %d\n",maior);
	
}

int verifica(int mat[3][3],int v)
{
	int cont1=0;
	
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
	if(mat[i][j]==v)
	cont1++;
		}
}

	if(cont1==0)
	printf("\n numero %d nao esta na matriz\n",v);
	else
	printf("\n numero %d esta contido na matriz\n",v);

}

int diagonal(int mat[3][3])
{
	int vet[3];
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(i==j)	
			vet[i]=mat[i][j];
		}
	}
	
	printf("\ndiagonal principal\n");
	
	for(i=0;i<3;i++)
	printf("%d\t",vet[i]);
}

main()
{
	int mat[3][3],valor;
	
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
	printf("[%d][%d]= ",i,j);
	scanf("%d",&mat[i][j]);
		}
	}
	
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		printf("%d\t",mat[i][j]);
		printf("\n");
	}
	
	printf("digite um numero: ");
	scanf("%d",&valor);
	
	
	maior_num(mat);
	verifica(mat,valor);
	diagonal(mat);
	
	getche();
}
