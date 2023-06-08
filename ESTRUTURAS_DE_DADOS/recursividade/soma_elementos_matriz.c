#include <stdio.h>
#include <stdlib.h>

int soma(int mat[3][3],int i,int j){
	if(i==0&&j<0){
		return 0;
	}
	if(j<0){
		i--;
		j=2;
	}
	printf("[%d] [%d] = %d\n",i,j,mat[i][j]);
	return mat[i][j]+soma(mat,i,j-1);
}

int main(){
	int mat[3][3]={2,3,5,8,10,11,1,6,4};
	printf("soma %d",soma(mat,2,2));
	return 0;
}
