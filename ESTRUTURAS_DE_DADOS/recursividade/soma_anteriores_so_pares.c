#include <stdio.h>

int func(int num, int num2, int i, int soma){

    if(i==(num-1)){
        return soma;    
    }
    
    if(num2%2==0){
        soma+=num2;
    }
    
    i++;
    
    num2--;
    
    func(num,num2,i,soma);
}

int main()
{
    printf("%d",func(5,5,0,0));

    return 0;
}
