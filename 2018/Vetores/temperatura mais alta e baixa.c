#include <stdio.h>
#include <conio.h>
main()
{
	int i,diamax,diamin;
	float temp[10],tmax,tmin;
	
	for(i=0;i<10;i++)
	{
	printf("informe a temperatura do dia %d: ",i+1);
	scanf("%f",&temp[i]);
	}
		
	tmax=temp[0];
	tmin=temp[0];
	diamin=i+1;
	diamax=i+1;
	
	for(i=0;i<10;i++)
	{
		if(temp[i]>tmax)
		{
		tmax=temp[i];
		diamax=i+1;
	}
		if(temp[i]<tmin)
		{
		tmin=temp[i];
		diamin=i+1;
	}
}
	printf("maior temperatura: dia %d , %.2f C°\n",diamax,tmax);
	printf("menor temperatura: dia %d , %.2f C°\n",diamin,tmin);
	
	getche();
}
