#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main()
{
	int i;
	char sexo;
	float alt,somam=0,soma=0,media=0,mediam=0,cont1=0,maior,cont2=0;
	for(i=1;i<6;i++)
	{
	printf("informe a altura da pessoa %d: ",i);
	scanf("%f",&alt);cont1++;
	if (alt==0)
		maior=alt;
		else
			if(alt>maior)
			maior=alt;
		
	printf("informe o sexo da pessoa:\n F-feminino\n M-masculino\n");
	scanf("%s",&sexo);
		if(sexo != 'M' && sexo != 'F')
		printf("opcao invalida.");
		else
			if(sexo=='F'){
				cont2++;
		
		somam=somam+alt;
		mediam=somam/cont2;
		}
		
		soma=soma+alt;
		media=soma/cont1;
}
	
	printf("media de altura: %.2f\n",media);
	printf("maior altura: %.2f\n",i,maior);
	printf("media de altura das mulheres: %.2f\n",mediam);
	
	system("pause");
}
