#include <stdio.h>
#include <conio.h>
main()
{
	int mat[10][10],i,j;
	for(i=0;i<10;i++)
	{	
		for(j=0;j<10;j++)
		{
			mat[0][i]=1;	mat[5][i]=6;
			mat[1][i]=2;	mat[6][i]=7;
			mat[2][i]=3;	mat[7][i]=8;
			mat[3][i]=4;	mat[8][i]=9;
			mat[4][i]=5;	mat[9][i]=10;	
		}	
	}

	for(i=0;i<10;i++)
	{
	for(j=0;j<10;j++)
	printf("%d\t",mat[i][j]);
	printf("\n");
	}
	getche();
}
