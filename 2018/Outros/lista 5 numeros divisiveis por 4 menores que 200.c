#include <stdio.h>
#include <conio.h>
main()
{
	int i;
	printf("numeros divisiveis por 4 e menores que 200: ");
	for (i=0;i<201;i++)
	if (i%4==0)
	printf("%d\n",i);
	
	getche();
}
