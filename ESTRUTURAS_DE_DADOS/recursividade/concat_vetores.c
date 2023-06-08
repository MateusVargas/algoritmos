#include <stdio.h>
#include <stdlib.h>

void concatenar(int v1[],int n1,int v2[],int n2,int v3[],int i,int j){
	
	if(i==(n1+n2)) return;
	
	if(i==n1){
		j=0;
	}
	if(i>=n1){
		v3[i]=v2[j];
	}
	else{
		v3[i]=v1[j];
	}
	
	concatenar(v1,n1,v2,n2,v3,i+1,j+1);
}

int main(){
	int n1,n2,*v1,*v2,*v3;
	scanf("%d %d",&n1,&n2);
	v1=(int*)malloc(n1*sizeof(int));
	v2=(int*)malloc(n2*sizeof(int));
	v3=(int*)malloc((n1+n2)*sizeof(int));
	for(int i=0;i<n1;i++){
		printf("v1[%d]=",i);
		scanf("%d",&v1[i]);
	}
	for(int i=0;i<n2;i++){
		printf("v2[%d]=",i);
		scanf("%d",&v2[i]);
	}
	concatenar(v1,n1,v2,n2,v3,0,0);
	for(int i=0;i<(n1+n2);i++){
		printf("%d\t",*(v3+i));
	}
	return 0;
}
