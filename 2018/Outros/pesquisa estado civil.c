#include <stdio.h>
#include <conio.h>
main()
{
	float mediav=0,p;
	int idade,estado_civil,cont1=0,cont2=0,cont3=0,cont4=0,cont5=0,somav=0;
	printf("informe a idade ou 0 para encerrar: ");
	scanf("%d",&idade);
	do
	{
		printf("informe o estado civil:\n1-casado\n2-solteiro\n3-viuvo\n4-desquitado ou separado\n");
		scanf("%d",&estado_civil);cont1++;
		if(estado_civil==1)cont2++;
		else if(estado_civil==2&&idade>30)cont3++;
		else if(estado_civil==3){cont4++;
		somav=somav+idade;
		mediav=somav/cont4;		
		}
		else if(estado_civil==4)cont5++;
		
		printf("informe a idade ou 0 para encerrar: ");
		scanf("%d",&idade);
		
	}while(idade!=0);
	
	p=(cont4*100)/cont1;
	
	printf("casados: %d\n",cont2);
	printf("solteiros com mais de 30 anos: %d\n",cont3);
	printf("media de idade de viuvos: %.2f\n",mediav);
	printf("percentual de desquitados: %.2f\n",p);
	
	getche();
}
