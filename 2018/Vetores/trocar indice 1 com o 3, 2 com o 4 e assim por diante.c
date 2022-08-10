#include <stdio.h>
#include <conio.h>

int muda_vetor(int vet[])
{
	int i,aux;
	printf("\nindice 1° trocado com o 3°, 2° com 4°, 5° com o 7° e 6° com o 8°\n");
	for(i=1;i<=4;i=i+2)
	{
		aux=vet[i+0];
		vet[i+0]=vet[3];
		vet[3]=aux;
				
		aux=vet[i+1];
		vet[i+1]=vet[4];
		vet[4]=aux;
		
		aux=vet[i+4];
		vet[i+4]=vet[7];
		vet[7]=aux;
			
		aux=vet[i+5];
		vet[i+5]=vet[8];
		vet[8]=aux;		
	}
	
	for(i=1;i<=8;i++)
	printf("%d\t",vet[i]);	
}

main()
{
	int i,vet[8];
	printf("dados do vetor\n");	
	for(i=1;i<=8;i++)
	{
		printf("v[%d]= ",i);
		scanf("%d",&vet[i]);
	}
	for(i=1;i<=8;i++)
	{	
		printf("%d\t",vet[i]);
	}	
	muda_vetor(vet);
		
	getche();
}
