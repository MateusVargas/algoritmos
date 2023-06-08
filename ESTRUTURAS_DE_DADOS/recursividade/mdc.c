#include <stdio.h>

int mdc(int x,int y){
	printf("x %d y %d\n",x,y);
	if(y==0){
		return x;
	}
	return mdc(y,x%y);
}
int main(){
	printf("%d",mdc(4,8));
	printf("\n%d",4%8);
};
