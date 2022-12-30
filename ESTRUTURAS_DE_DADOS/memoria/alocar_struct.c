#include <stdio.h>
#include <stdlib.h>

struct pessoa{
	char nome[30];
	int idade;
	struct nascimento{
		int dia;
		int mes;
		int ano;
	} dt_nasc;
};

int main(){
	struct pessoa *p;//ponteiro para struct pessoa
	
	p=(struct pessoa*)malloc(sizeof(struct pessoa));
	//alocacao para o ponteiro da struct
	
	printf("nome:");
	fgets(p->nome,31,stdin);
	//por ser um ponteiro para uma struct, se deve usar ->(flecha) em vez do ponto
	
	printf("idade:");
	scanf("%d",&p->idade);
	
	printf("dia, mes e ano de nascimento:");
	scanf("%d %d %d",
		&p->dt_nasc.dia,
		&p->dt_nasc.mes,
		&p->dt_nasc.ano
	);
	
	printf("nome: %s",p->nome);
	printf("data nascimento: %d/%d/%d",p->dt_nasc.dia,p->dt_nasc.mes,p->dt_nasc.ano);
	
	free(p);
	
	return 0;
}
