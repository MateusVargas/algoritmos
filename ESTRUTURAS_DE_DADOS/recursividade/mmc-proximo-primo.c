#include <stdio.h>

int proximo_primo(int num,int numInc,int qtdDiv){
	if(qtdDiv==2 && numInc==0){
		return num;
	}
	if(numInc==0){
		num++;
		numInc=num;
		qtdDiv=0;
	}
	if(num % numInc == 0){
		qtdDiv++;
	}
	return proximo_primo(num,numInc-1,qtdDiv);
}

int mmc(int a,int b,int div,int result){
	if(a==1 && b==1){
		return result;
	}
	
	if(a%div !=0 && b%div !=0){
		while(a%div !=0 && b%div !=0){
			div=proximo_primo(div+1,div+1,0);
		}
	}
	
	if(a!=1 && a%div ==0){
		a = a/div;
	}
	if(b!=1 && b%div ==0){
		b = b/div;
	}
	
	result = result*div;
	return mmc(a,b,div,result);
}

int main(){
	printf("%d",mmc(121,2,2,1));
	//printf("%d",1%2);
	return 0;
}
