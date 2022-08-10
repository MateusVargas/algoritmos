#include <stdio.h>

float peso(float alt, float sexo)
{
	float peso_ideal;
	if(sexo==1)
	{
	peso_ideal=(72.7*alt)-58;
	printf("peso ideal: %.2f Kg",peso_ideal);
	}
	else if(sexo==2)
	{
	peso_ideal=(62.1*alt)-44.7;
	printf("peso ideal: %.2f Kg",peso_ideal);
	}
}
main()
{
	float alt,sexo;
	printf("informe a altura: ");
	scanf("%f",&alt);
	printf("informe o sexo:\t1-masculino\t2-feminino\n");
	scanf("%f",&sexo);
	peso(alt,sexo);
}
