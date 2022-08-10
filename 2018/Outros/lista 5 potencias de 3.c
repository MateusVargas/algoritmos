#include <stdio.h>
#include <conio.h>
#include <math.h>
main()
{
	int pot;
	for(int i=0;i<16;i++)
	{
	pot=pow(3,i);
	printf("3 elavado a %d = %d\n",i,pot);
	}
}
