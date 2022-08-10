#include <stdio.h>
#include <conio.h>
int main ()
{
	int i,num,maior;
	for(int i=1;i<26;i++){
		printf("escreva o %d ° numero: ",i);
		scanf("%d",&num);
		
		if(i==1)
			maior=num;
			
			else
				if(num>maior)
					maior=num;
					
	}
	printf("maior numero: %d",maior);
	
	getche();
	
}
