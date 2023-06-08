#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
	int num;
	struct lista *prox;
} Lista;

Lista* inserir_inicio(Lista *l,int n){
	Lista *novo=(Lista*)malloc(sizeof(Lista));
	novo->num=n;
	novo->prox=l;
	return novo;
}

void imp(Lista *p){
	if(p==NULL) return;
	printf("%d\t",p->num);
	imp(p->prox);
	printf("\n");
}

Lista* intercalar(Lista **l1,Lista **l2){
	Lista *it_L1=*l1,*it_L2=*l2;
	Lista *l3,*aux_L1,*aux_L2;
	
	if(*l1==NULL) l3=*l2;
	else if(*l2==NULL) l3=*l1;
	else{
		l3=*l1;
		while(it_L1!=NULL && it_L2!=NULL){
			aux_L1=it_L1;
			aux_L2=it_L2;
			it_L1=it_L1->prox;
			it_L2=it_L2->prox;
			aux_L1->prox=aux_L2;
			
			if(!(it_L1==NULL && it_L2!=NULL)){
				aux_L2->prox=it_L1;
			}
		}
	}
	*l1=NULL;
	*l2=NULL;
	return l3;
}


Lista* intercalar2(Lista *itL1,Lista *itL2,Lista *auxL1,Lista *auxL2,Lista **l1,Lista **l2,Lista *l3,int i){
	if(*l1==NULL) return *l2;
	if(*l2==NULL) return *l1;
	if(itL1 == NULL || itL2 == NULL){
		*l1=NULL;
		*l2=NULL;
		return l3;
	}
	if(i==0) l3=*l1;
	auxL1=itL1;
	auxL2=itL2;
	itL1=itL1->prox;
	itL2=itL2->prox;
	auxL1->prox=auxL2;
	if(!(itL1==NULL && itL2!=NULL)){
		auxL2->prox=itL1;
	}
	return intercalar2(itL1,itL2,auxL1,auxL2,l1,l2,l3,i+1);
	
}

int main(){
	Lista *l1,*l2,*l3;
	l1=inserir_inicio(l1,5);
	l1=inserir_inicio(l1,4);
	l1=inserir_inicio(l1,3);
	l1=inserir_inicio(l1,2);
	l1=inserir_inicio(l1,12);
	l1=inserir_inicio(l1,16);
	l1=inserir_inicio(l1,19);
	
	l2=inserir_inicio(l2,8);
	l2=inserir_inicio(l2,7);
	l2=inserir_inicio(l2,9);
	imp(l1);
	imp(l2);
	
	l3=intercalar2(l1,l2,NULL,NULL,&l1,&l2,l3,0);
	imp(l3);
	return 0;
}
