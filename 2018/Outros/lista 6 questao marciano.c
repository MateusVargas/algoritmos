#include <stdio.h>
main()
{
	int i,num;
	for (i=6;i>1;i--)
	{
	printf("em qual arvore esta o marciano? voce tem %d chance(s): ",i-1);
	scanf("%d",&num);
	if(num==26){
	printf("acertou!!!!!!!!!");break;
	}
	if(num<26)
	printf("errrroooouuu!!! mais pra cima\n");
	if(num>26)
	printf("errrroooouuu!!! mais pra baixo\n");
	}
	if(num!=26)
	printf("é uma pena, voce perdeu, o numero era 26");
}
