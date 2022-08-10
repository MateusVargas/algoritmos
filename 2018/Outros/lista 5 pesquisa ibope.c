#include <stdio.h>
#include <conio.h>
#include <string.h>
main()
{
	float cont1=0,cont2=0,cont3=0,cont4=0,p1,p2;
	char sexo;
	int i,sn;
	for(i=0;i<10;i++)
	{
	printf("voce gostou do produto?\n 1-sim      2-nao\n");
	scanf("%d",&sn);
		if(sn!=1&&sn!=2)
		printf("opcao invlida");
		
	printf("informe seu sexo:\n F-feminino  M-masculino\n\n");
	scanf("%s",&sexo);	
		if(sexo!='F'&&sexo!='M')
		printf("opcao invalida");
		
		
		if(sn==1)cont1++;
		else
			if(sn==2)cont2++;
		
		if(sn==1&&sexo=='F')cont3++;
		else if(sn==2&&sexo=='M')cont4++;
		
		p1=(cont3/10)*100;
		p2=(cont4/10)*100;
	}
	printf("total de pessoas que responderam sim: %.0f\n",cont1);
	printf("total de pessoas que responderam nao: %.0f\n",cont2);
	printf("porcentagem de mulheres que responderam sim: %.2f",p1);
	printf("\nporcentagem de homens que responderam nao: %.2f",p2);
	
	
	getch();
}
