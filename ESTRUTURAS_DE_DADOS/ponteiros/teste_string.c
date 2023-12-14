#include <stdio.h>
#include <string.h>
int main(){
	//char letra[10],aux;
	char frase[50]={"bom dia, hoje e domingo"};
	int esp=0;
	int aux_esp1=0,aux_esp2=0;
	int vet[50],aux_i=0;
	char palavra[20];
	
	for(int i=0;i<strlen(frase);i++){
		if(frase[i]==' '){
			esp++;
			vet[esp-1]=i;
		}
	}
	//printf("%d",vet[0]);
	int mat[esp+1][50],ind_matriz=0;
	
	
	for(int i=0;i<strlen(frase);i++){
		int ind=0;
		if(frase[i]==' '){
			//aux_esp2=i;
			for(int j=aux_esp1;j<vet[aux_i];j++){
				palavra[ind]=frase[j];
				ind++;
			}
			
			aux_esp1=vet[aux_i];
			strcpy(mat[ind_matriz],palavra);
			ind_matriz++;
			palavra[0]='\0';
			
			aux_i++;
			//printf("iy%d",vet[aux_i]);
			if(aux_i==esp){
				char g[20];
				int y=0;
				for(int j=vet[aux_i-1];j<strlen(frase);j++){
					g[y]=frase[j];
					y++;
				}
				strcpy(mat[ind_matriz],g);
			}
			
		
			
		}
	}
	
	puts(mat[4]);
	
	//printf("%d",strlen(letra));
	//printf("%d",strcmp(letra,"r"));
	/*for(int i=0;i<10;i++){
		printf("letra[%d]: ",i);
		//getchar();
		scanf("%c",&letra[i]);
	}
	for(int i=0;i<10;i++){
		for(int j=0;j<i;j++){
			if(letra[i]<letra[j]){
				aux=letra[j];
				letra[j]=letra[i];
				letra[i]=aux;
			}
		}
	}
	puts(letra);*/
}
