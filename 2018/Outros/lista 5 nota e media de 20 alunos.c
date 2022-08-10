#include <stdio.h>
#include <stdlib.h>
main()
{
	int i;
	float nota[2],media;
	for(i=0;i<20;i++){
	printf("informe a primeira nota do aluno: ",i);
	scanf("%f",&nota[0]);
	printf("informe a segunda nota do aluno: ");
	scanf("%f",&nota[1]);	
			
	media=(nota[0]+nota[1])/2;
	printf("media = %.2f\n\n",media);
		}
	system("pause");
}
