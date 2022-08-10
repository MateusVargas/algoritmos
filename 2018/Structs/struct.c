#include <stdio.h>

struct Data
{
int aux;
int arr;
};

int main() {
	int vet[30];
	int k = 16;
	int arr[] = {7,2,6,12,4,5,8,8,9,1};
	struct Data d1[30];
	int countStruct=0;
	
	for(int i=0; i<10; i++){
		int aux = arr[i];
		for(int j=0; j<10; j++){
			//printf("%d + %d = %d\n",arr[j],aux,arr[j]+aux);
			if(arr[j]+aux == k && i != j){
				
			for(int c=0;c<countStruct;c++){
				if(d1[c].aux == aux && d1[c].arr == arr[j]){
					;
					}
				
			}

				d1[countStruct].aux = aux;
				d1[countStruct].arr = arr[j];
				countStruct++;
		
			    
			  
			}
				//}
			//printf("%d + %d\n",arr[j],aux);
			
		}
	}
	
	for (int i=0; i<countStruct; i++){
       printf("%d, %d\n", d1[i].aux, d1[i].arr);
	}
	/*for(int i=0;i<30;i++){
		printf("%d",vet[i]);
	}*/
}
