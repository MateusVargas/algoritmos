#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct agenda{
	char nome[40];
	char email[40];
	int telefone;
};

typedef struct agenda Agenda;

//recebe um ponteiro de p_agenda e um ponteiro de total
//como p_agenda da main e um ponteiro entao sao 2 asteriscos
void alocar(Agenda **p_agenda,int *p_total);

void listar(Agenda *p_agenda,int total);
void excluir(Agenda **p_agenda,int *p_total);
void alterar(Agenda *p_agenda,int total);
void pesquisar(Agenda *p_agenda,int total);


int main(){
	Agenda *p_agenda;
	int total=0,opcao;
	
	p_agenda=(Agenda*)malloc(sizeof(Agenda));
	//alocando espaco pra posicao 0 do vetor de Agenda
	
	if(p_agenda==NULL){
		printf("erro de alocacao de memoria");
		exit(0);
	}
	
	do{
		fflush(stdin);
		printf("\n1 - Inclusao"); 
		printf("\n2 - Alteracao"); 
		printf("\n3 - Listar"); 
		printf("\n4 - Excluir"); 
		printf("\n5 - Pesquisar"); 
		printf("\n9 - Sair\n");
		scanf("%d",&opcao);
		
		if(opcao==1){
			/*algumas formas de manipular ponteiros */
			fflush(stdin);
			
			/*alocação de ponteiros em funções requer trabalhar com ponteiros para ponteiros*/
			printf("p_agenda: %x\n",p_agenda);
			alocar(&p_agenda,&total);
			
			printf("nome: ");
			getchar();
			fgets((p_agenda+total)->nome,41,stdin);
			/*endereço ponteiro inicial + x posições na memória, quando se trabalhar com o endereço, deve-se usar ->*/
			fflush(stdin);
			
			printf("email:");
			getchar();
			fgets((*(p_agenda+total)).email,41,stdin);
			/*endereço ponteiro inicial + x posições na memória, quando se trabalhar com ponteiro (conteúdo do endereço ou *), deve-se usar o . (ponto)*/
			fflush(stdin);
			
			printf("telefone:");
			scanf("%d",&p_agenda[total].telefone);
			fflush(stdin);
			
			total++;
		}
		else if(opcao==2){
			alterar(p_agenda,total);
		}
		else if(opcao==3){
			listar(p_agenda,total);
		}
		else if(opcao==4){
			excluir(&p_agenda,&total);
		}
		else if(opcao==5){
			pesquisar(p_agenda,total);
		}
		
	}while(opcao!=9);
	
	return 0;
}


void alocar(Agenda **p_agenda,int *p_total){
	//realloc recebe o ponteiro e o novo tamanho para realocacao
	printf("**p_agenda: %x\n",**p_agenda); //**p_agenda aponta pra &p_agenda, ou seja, pro endereco de memoria p_agenda
	printf("*p_agenda: %x\n",*p_agenda); //*p_agenda aponta pro valor do endereco que p_agenda guarda
	
	/*
	  (*p_agenda) porque **p_agenda e um ponteiro que tem o seu endereco de memoria normal, *p_agenda aponta pro endereco de p_agenda da funcao main entao se esta mexendo no endereco de p_agenda da funcao main
	*/
	
	/*
	 *p_total e um ponteiro para total da main, pois foi passado o endereco de total, entao na funcao deve ser recebido com um ponteiro, usando *p_total vai trazer o valor da variavel total da main.
	*/
	
	(*p_agenda)=(Agenda*)realloc(*p_agenda,(*p_total+1)*sizeof(Agenda*));
	
	if(*p_agenda==NULL){
		exit(0);
	}
}


void listar(Agenda *p_agenda,int total){
	for(int i=0;i<total;i++){
		printf("\nresgistro %d\n",i+1);
		printf("nome: %s",p_agenda[i].nome);
		printf("email: %s",p_agenda[i].email);
		printf("telefone: %d\n",p_agenda[i].telefone);
	}
}


void alterar(Agenda *p_agenda,int total){
	char op;
	char nome[40];
	int i;
	printf("digite o nome:");
	getchar();
	fgets(nome,41,stdin);
	
	for(i=0;i<total && strncmp(p_agenda[i].nome,nome,strlen(nome))!=0;i++);
	//strncmp compara um numero especifico de caracteres entre duas strings
	
	if(i>=total){
		printf("\nregistro nao encontrado");
	}
	else{
		printf("\n\nresgistro %d",i+1);
		printf("\nnome: %s",p_agenda[i].nome);
		printf("\nemail: %s",p_agenda[i].email);
		printf("\ntelefone: %d",p_agenda[i].telefone);
		printf("\nconfirma a alteracao?");
		scanf(" %c",&op);
		
		if(op=='S'||op=='s'){
			fflush(stdin);
			
			printf("nome: ");
			getchar();
			fgets((p_agenda+i)->nome,41,stdin);
			/*endereço ponteiro inicial + x posições na memória, quando se trabalhar com o endereço, deve-se usar ->*/
			fflush(stdin);
			
			printf("email:");
			getchar();
			fgets((*(p_agenda+i)).email,41,stdin);
			/*endereço ponteiro inicial + x posições na memória, quando se trabalhar com ponteiro (conteúdo do endereço ou *), deve-se usar o . (ponto)*/
			fflush(stdin);
			
			printf("telefone:");
			scanf("%d",&p_agenda[i].telefone);
			fflush(stdin);
		}
	}
}


void pesquisar(Agenda *p_agenda,int total){
	char op;
	char nome[40];
	int i=0;
	printf("digite o nome:");
	getchar();
	fgets(nome,41,stdin);
	
	for(i=0;i<total && strncmp(p_agenda[i].nome,nome,strlen(nome))!=0;i++);
	
	if(i>=total){
		printf("\nregistro nao encontrado");
	}
	else{
		do{
			printf("\n\nresgistro %d",i+1);
			printf("\nnome: %s",p_agenda[i].nome);
			printf("\nemail: %s",p_agenda[i].email);
			printf("\ntelefone: %d",p_agenda[i].telefone);
			printf("\nproximo?");
			scanf(" %c",&op);
			i++;
			
			if(i>=total){
				i=0;
			}
		}while(op=='S'||op=='s');
	}
}


void excluir(Agenda **p_agenda,int *p_total){
	char op;
	char nome[40];
	int i=0;
	printf("digite o nome:");
	getchar();
	fgets(nome,41,stdin);
	
	for(i=0;i<*p_total && strncmp((*p_agenda)[i].nome,nome,strlen(nome))!=0;i++);
	
	if(i>=*p_total){
		printf("\nregistro nao encontrado");
	}
	else{
		fflush(stdin);
		printf("\n\nresgistro %d",i+1);
		printf("\nnome: %s",(*p_agenda)[i].nome);
		printf("\nemail: %s",(*p_agenda)[i].email);
		printf("\ntelefone: %d",(*p_agenda)[i].telefone);
		printf("\nconfirma a alteracao?");
		scanf(" %c",&op);

		if(op=='S'||op=='s'){
			(*p_agenda)[i]=(*p_agenda)[(*p_total)-1];
			(*p_total)--;
			alocar(p_agenda,p_total);
		}
	}
}
