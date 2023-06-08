#include <stdio.h>
#include <stdlib.h>

struct lista{
	int num;
	struct lista *prox;
};
typedef struct lista Lista;


Lista* inserir(Lista *inicio,int x){
	Lista *novo=(Lista*)malloc(sizeof(Lista));
	novo->num=x;
	novo->prox=inicio;
	return novo;
}


Lista* intersec(Lista *l1,Lista *l2){
	Lista *l3=NULL;
	
	if(l1!=NULL&&l2!=NULL){
		Lista *itL1=l1,*itL2=l2,*novo,*aux,*itL3;
		int existe=0;
		
		while(itL1!=NULL){
			
			itL2=l2;
			
			while(itL2!=NULL){
				existe=0;
				
				if(itL1->num==itL2->num){
					if(l3==NULL){
						novo=(Lista*)malloc(sizeof(Lista));
						novo->num=itL1->num;
						novo->prox=NULL;
						l3=novo;
						aux=novo;
					}
					else{
						itL3=l3;
						while(itL3!=NULL){
							if(itL3->num==itL1->num){
								existe=1;
							}
							itL3=itL3->prox;
						}
						if(!existe){
							novo=(Lista*)malloc(sizeof(Lista));
							novo->num=itL1->num;
							novo->prox=NULL;
							aux->prox=novo;
							aux=novo;
						}
						
					}
					
				}
				
				itL2=itL2->prox;
			}
			
			itL1=itL1->prox;
		}
		
		
	}
	return l3;
}

void imp(Lista *p){
	if(p==NULL) return;
	printf("%d\t",p->num);
	imp(p->prox);
	printf("\n");
}

int main(){
	Lista *l1,*l2,*l3;
	l1=inserir(l1,3);
	l1=inserir(l1,9);
	l1=inserir(l1,7);
	l1=inserir(l1,15);
	
	l2=inserir(l2,8);
	l2=inserir(l2,9);
	l2=inserir(l2,3);
	l2=inserir(l2,3);
	l2=inserir(l2,15);
	imp(l1);
	imp(l2);
	
	l3=intersec(l1,l2);
	imp(l3);
	
	return 0;
}