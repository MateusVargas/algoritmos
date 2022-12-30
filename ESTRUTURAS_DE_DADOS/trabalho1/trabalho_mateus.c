//nome: mateus cardoso
//ordem de insercao: sempre o ultimo app inserido
//vai pro fim da lista de apps da aba
//tipo de dados nome app: string

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APP 4

struct app{
	char *nome;
	struct app *prox;
};

struct aba{
	int num;
	struct app *apps;
	int total_apps;
	struct aba *anterior;
	struct aba *proximo;
};

typedef struct app App;
typedef struct aba Aba;



//procura por um app na lista de apps da aba
App* buscar_app(Aba *aba, char pesquisa[20]){
    App *iterator_apps = aba->apps;

    while(iterator_apps != NULL && strcmp(pesquisa, iterator_apps->nome) != 0){
        iterator_apps = iterator_apps->prox;
    }

    return iterator_apps;
}



//cria primeira aba, ou adiciona uma nova aba vazia
Aba* criar_aba(Aba *aba, int *num_aba){

	Aba *iterator = aba;
	Aba *novo=(Aba*)malloc(sizeof(Aba));

	novo->num = ++(*num_aba);
	novo->apps=NULL;
	novo->total_apps = 0;

	if(aba==NULL){
		novo->anterior=NULL;
		novo->proximo=NULL;
		aba=novo;
	}
	else{

		while(iterator->proximo!=NULL){
			iterator=iterator->proximo;
		}

		iterator->proximo=novo;
		novo->anterior=iterator;
		novo->proximo=NULL;
	}
	return aba;
}





/*
adiciona um app na ultima aba
se a aba esta vazia no caso de ser a primeira
adiciona um app nela.
se a aba tiver cheia, cria uma nova aba e adiciona
o app nela.
se nao estiver vazia nem cheia adiciona o app no fim.
e retorna a aba onde foi inserido o app
*/
Aba* add_app_ultima_aba(Aba *aba, int *num_aba){
    App *iterator = aba->apps;

	App *novo=(App*)malloc(sizeof(App));
	novo->nome=(char*)malloc(20*sizeof(char));

	printf("nome: ");
	getchar();
	gets(novo->nome);

	novo->prox = NULL;

	if(aba->proximo == NULL){

		if(aba->apps==NULL){
			aba->apps=novo;
		}
		else if(aba->total_apps == MAX_APP){
			aba = criar_aba(aba, num_aba);

			aba = aba->proximo;
			//printf("ant %x",(*aba)->anterior);
			aba->apps = novo;
		}
		else{
			while(iterator->prox != NULL){
				iterator=iterator->prox;
			}
			iterator->prox = novo;
		}

		aba->total_apps++;
	}

	else{
	    //procurar ultima aba e inserir no final dela
	    Aba *iterator_aba = aba;

	    while(iterator_aba->proximo!=NULL){
	        iterator_aba = iterator_aba->proximo;
	    }

	    if(iterator_aba->total_apps == MAX_APP){
	    	iterator_aba = criar_aba(iterator_aba,num_aba);

	    	iterator_aba = iterator_aba->proximo;
	        iterator_aba->apps = novo;
	        iterator_aba->total_apps++;

	        aba = iterator_aba;
	    }
	    else{
	        iterator = iterator_aba->apps;
	        while(iterator->prox != NULL){
	            iterator = iterator->prox;
	        }

	        iterator->prox = novo;
	        iterator_aba->total_apps++;

	        aba = iterator_aba;
	    }


	}

	return aba;
}




void imprimir_apps_aba(App *app){
	if(app==NULL){
		return;
	}
	//printf("\t - %s, %x, prox %x\n",app->nome,app,app->prox);
	printf("\t - %s\n",app->nome);
	imprimir_apps_aba(app->prox);
}




void imprimir_aba(Aba *aba){
	printf("\n\nABA Atual: %d\n",aba->num);
	printf("Total de Apps: %d\n",aba->total_apps);

	if(aba->apps==NULL){
		printf("Nenhum App nesta aba\n\n");
	}
	else{
		printf("Aplicativos:\n");
		imprimir_apps_aba(aba->apps);
		printf("\n\n");
	}
}




//remove um app da aba
Aba* remover_app_aba(Aba *aba, App *app_remover, int *num_aba){
    App *iterator_app = aba->apps;
    App *anterior = NULL;

    while(iterator_app != NULL && strcmp(iterator_app->nome,app_remover->nome) !=0){
        anterior = iterator_app;
        iterator_app = iterator_app->prox;
    }

    if(aba->total_apps == 1){

        /*
        se o app a ser apagado é o unico da aba,
        entao verifica se existem abas anteriores
        se sim a aba eh apagada junto com o app,
        senão, então a aba é a primeira nesse caso
        só apaga o app
        */

        if(aba->anterior == NULL){
            free(aba->apps);
            aba->apps = NULL;
            aba->total_apps = 0;
        }
        else{
            aba = aba->anterior;
            free(aba->proximo);
            aba->proximo = NULL;
            (*num_aba)--;
        }
    }
    else{

        /*
        se a aba tiver mais de um app, entao
        verifica se ele é o primeiro, o ultimo
        ou se esta no meio para reorganizar
        os apontamentos e depois decrementa o
        total de apps da aba.
        */

        if(anterior == NULL){
            aba->apps = iterator_app->prox;
        }
        else if(iterator_app->prox == NULL){
            anterior->prox = NULL;
        }
        else{
            anterior->prox = iterator_app->prox;
        }

        free(iterator_app);
        aba->total_apps--;

    }

    return aba;
}



/*
adiciona no fim da lista de apps o
primeiro app da proxima aba
*/
Aba* mover_apps_abas(Aba *aba, int *num_aba){
    App *iterator_apps = aba->apps;
    App *novo_prim_app_aba_atual = aba->apps->prox;

    Aba *aux_prox_aba = aba->proximo;

    /*
    se a aba for a ultima, e tiver soh 1 app ela
    eh apagada, se tiver mais de um muda o ponteiro
    do primeiro app
    */
    if(aba->proximo == NULL){
    	if(aba->total_apps==1){

    		aba = aba->anterior;
    		free(aba->proximo);
    		aba->proximo = NULL;
    		(*num_aba)--;
    	}
    	else{
    		iterator_apps->prox=NULL;
    		aba->apps = novo_prim_app_aba_atual;
    		aba->total_apps--;
    	}

    }
    else{

    	/*
    	senao for a ultima aba, entao procura
    	o ultimo app dela e faz ele pontar pro
    	primeiro da aba seguinte, depois refaz
    	o primeiro app da aba atual pra apontar
    	pro prox do primeiro, pois o primeiro
    	dessa aba esta sendo apontado pela aba
    	anterior
    	*/

	    while(iterator_apps->prox != NULL){
	        iterator_apps = iterator_apps->prox;
	    }

	    iterator_apps->prox = aux_prox_aba->apps;

	    aba->apps->prox=NULL;
	    aba->apps = novo_prim_app_aba_atual;
    }

    return aba;
}



int main(){
	Aba *primeira_aba = NULL, *aba_atual = NULL;
	App *encontrado = NULL;
	int op, num_aba = 0;
	char pesquisa[20];

	primeira_aba = criar_aba(primeira_aba, &num_aba);
	aba_atual = primeira_aba;

	//printf("primeira_aba %x\n",primeira_aba);
	//printf("aba_atual %x",aba_atual);

	do{
		imprimir_aba(aba_atual);

		printf("1-aba anterior\n");
		printf("2-proxima aba\n");
		printf("3-adicionar app\n");
		printf("4-remover app\n");
		printf("9-sair\n");
		scanf("%d",&op);

		switch(op){
			case 1:
				if(aba_atual->anterior==NULL){
					printf("\nNAO HA ABA ANTERIOR\n\n");
				}
				else{
					aba_atual=aba_atual->anterior;
				}
				break;

			case 2:
				if(aba_atual->proximo==NULL){
					printf("\nNAO HA PROXIMA ABA\n\n");
				}
				else{
					aba_atual=aba_atual->proximo;
				}
				break;

			case 3:
				aba_atual=add_app_ultima_aba(aba_atual, &num_aba);
				break;

            case 4:
                printf("nome: ");
                getchar();
                gets(pesquisa);

                encontrado = buscar_app(aba_atual,pesquisa);

                if(encontrado == NULL){

                    /*
                    se nao achar o app na aba atual
                    procura nas outras abas/telas
                    e se achar pergunta se quer
                    apagar o app, se apagar refaz
                    os apontamentos das abas seguintes
                    a aba onde estava o app
                    */

                    Aba *iterator_aba = primeira_aba;
                    App *iterator_app = NULL;
                    int achou = 0;


                    //procura nas outras abas o app
                    while(iterator_aba!=NULL){

                    	iterator_app=iterator_aba->apps;

                    	while(iterator_app!=NULL){

                    		if(strcmp(pesquisa,iterator_app->nome)==0){
                    			achou=1;
                    			encontrado=iterator_app;
                    		}

                    		iterator_app=iterator_app->prox;
                    	}

                    	if(achou){
                    		break;
                    	}

                    	iterator_aba=iterator_aba->proximo;

                    }


                    if(encontrado==NULL){
                    	printf("app nao encontrado\n\n");
                    }
                    else{
                    	int confirmar;

                    	printf("app foi achado na aba: %d, digite 1 pra apagar: ",iterator_aba->num);
                    	scanf("%d",&confirmar);

                    	if(confirmar==1){

                    		Aba *salvar_aba_atual=aba_atual;

                    		/*
                    		se achou o app na ultima
                    		aba entao vai apagar ele
                    		e nao precisa reorganizar
                    		as outras abas/telas
                    		*/

                    		if(iterator_aba->proximo==NULL){

                    			iterator_aba=remover_app_aba(iterator_aba,encontrado,&num_aba);

                    		}

                    		else{

                    			/*
                    			se achou o app em
                    			outra aba que nao
                    			a ultima, refaz os
                    			apontamentos pra que
                    			o ultimo app aponte
                    			pro primeiro da
                    			proxima, e o primeiro
                    			da proxima passe a ser
                    			o que antes era o
                    			segundo
                    			*/

                    			if(aba_atual->proximo==NULL && aba_atual->total_apps==1){
                    				aba_atual=aba_atual->anterior;
                    			}


                    			/*
                    			remove o app da aba
                    			e comeca a refazer os
                    			apontamentos daquela
                    			aba em diante
                    			*/

                    			iterator_aba=remover_app_aba(iterator_aba,
                    			encontrado,
                    			&num_aba);

                    			iterator_app=iterator_aba->apps;

                    			while(iterator_app->prox!=NULL){
                    				iterator_app=iterator_app->prox;
                    			}

                    			iterator_app->prox=iterator_aba->proximo->apps;

                    			iterator_aba->total_apps++;

                    			iterator_aba=iterator_aba->proximo;

                    			while(iterator_aba!=NULL){

                    				iterator_aba=mover_apps_abas(iterator_aba,&num_aba);

                    				iterator_aba=iterator_aba->proximo;

                    			}

                    		}

                    	}

                    }

                }
                else{

                    /*se estiver na ultima aba,
                    entao vai apagar um app da
                    ultima aba e nao precisa
                    reorganizar as outras
                    */
                    if(aba_atual->proximo == NULL){
                        aba_atual = remover_app_aba(aba_atual,encontrado, &num_aba);
                    }
                    else{

                        /*
                        vai apagar um app de uma
                        aba que nao é a ultima,
                        entao é preciso reorganizar
                        todas as abas seguintes
                        */
                        Aba *salvar_aba_atual = aba_atual;

                        App *iterator_app = NULL;

                        aba_atual = remover_app_aba(aba_atual, encontrado, &num_aba);

                        iterator_app = aba_atual->apps;

                        /*
                        depois de remover o app da
                        aba, busca o ultimo app da
                        aba atual e faz ele apontar
                        pro primeiro app da proxima
                        aba.
                        */
                        while(iterator_app->prox!=NULL){
                            iterator_app=iterator_app->prox;
                        }

                        Aba *aba_aux = aba_atual->proximo;

                        iterator_app->prox = aba_aux->apps;

                        aba_atual->total_apps++;
                        aba_atual = aba_atual->proximo;

                        /*
                        percorre todas as abas
                        seguintes até a ultima
                        fazendo com que o ultimo
                        app da aba aponte pro
                        primeiro da app da aba
                        seguinte. e muda o primeiro
                        app da aba porque ele
                        passou pra aba anterior
                        entao o primeiro da aba
                        sera primeiro->prox.
                        quando chegar na ultima aba
                        verifica se ela so tem 1 app
                        se tiver soh 1 ele foi pra
                        aba anterior, nesse caso
                        apaga a aba, senao aponta
                        primeiro app da aba pra
                        primeiro->prox.
                        */
                        while(aba_atual != NULL){
                            aba_atual = mover_apps_abas(aba_atual, &num_aba);
                            aba_atual = aba_atual->proximo;
                        }

                        aba_atual = salvar_aba_atual;
                    }

                }

                break;

            case 9:
                printf("saindo...\n");
                break;

            default:
                printf("opcao invalida\n\n");

		}

	}while(op!=9);


	return 0;
}

