#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
main()
{
	setlocale(LC_ALL,"portuguese");
	int i,pot,cont1=0;
	
	for (i=15;i<101;i++){
	
	printf("o quadrado de %d: ",i);
		
	pot=i*i;
	
	printf("é %d\n",pot);
	}
	
	system("pause");
}
