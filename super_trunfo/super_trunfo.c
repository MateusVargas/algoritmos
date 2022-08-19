#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


/*
testar com menos cartas:
trocar define tamanho pra 12 por exemplo:
na funcao setar_baralho comentar a definição das propriedades do indice 12 pra frente, ficando de 0 até 11
nas linhas 259 e 269 trocar parametro da funcao generate_random_number passando o numero definido no define TAMANHO ex:12
para gerar numeros aleatorios de 0 a 11
*/


#define TAMANHO 24

struct baralho{
    char flag;
    char nome[40];
    int is_super_trunfo;
    int forca;
    int habilidade;
    int inteligencia;
    int velocidade;
};

typedef struct baralho Baralho;


/*funcao que seta as cartas com valores de 1 a 10 para as propriedes das 24 cartas
e tambem atribui nome e flag para elas */
void setar_baralho(Baralho baralho[TAMANHO]){
    
    baralho[0].flag = 'A';
    strcpy(baralho[0].nome,"Thor");
    baralho[0].is_super_trunfo = 1;
    baralho[0].forca = 9;
    baralho[0].habilidade = 5;
    baralho[0].inteligencia = 5;
    baralho[0].velocidade = 3;
    
    baralho[1].flag = 'A';
    strcpy(baralho[1].nome,"Super – Homem");
    baralho[1].is_super_trunfo = 0;
    baralho[1].forca = 9;
    baralho[1].habilidade = 8;
    baralho[1].inteligencia = 8;
    baralho[1].velocidade = 10;
    
    baralho[2].flag = 'B';
    strcpy(baralho[2].nome,"Homem Aranha");
    baralho[2].is_super_trunfo = 0;
    baralho[2].forca = 3;
    baralho[2].habilidade = 5;
    baralho[2].inteligencia = 6;
    baralho[2].velocidade = 4;
    
    baralho[3].flag = 'A';
    strcpy(baralho[3].nome,"Batman");
    baralho[3].is_super_trunfo = 0;
    baralho[3].forca = 5;
    baralho[3].habilidade = 8;
    baralho[3].inteligencia = 7;
    baralho[3].velocidade = 2;
    
    baralho[4].flag = 'C';
    strcpy(baralho[4].nome,"Hulk");
    baralho[4].is_super_trunfo = 0;
    baralho[4].forca = 10;
    baralho[4].habilidade = 3;
    baralho[4].inteligencia = 1;
    baralho[4].velocidade = 2;
    
    baralho[5].flag = 'D';
    strcpy(baralho[5].nome,"Capitao America");
    baralho[5].is_super_trunfo = 0;
    baralho[5].forca = 4;
    baralho[5].habilidade = 5;
    baralho[5].inteligencia = 6;
    baralho[5].velocidade = 4;
    
    baralho[6].flag = 'B';
    strcpy(baralho[6].nome,"Papa-leguas");
    baralho[6].is_super_trunfo = 0;
    baralho[6].forca = 1;
    baralho[6].habilidade = 6;
    baralho[6].inteligencia = 10;
    baralho[6].velocidade = 10;
    
    baralho[7].flag = 'C';
    strcpy(baralho[7].nome,"Flash");
    baralho[7].is_super_trunfo = 0;
    baralho[7].forca = 2;
    baralho[7].habilidade = 3;
    baralho[7].inteligencia = 6;
    baralho[7].velocidade = 10;
    
    baralho[8].flag = 'D';
    strcpy(baralho[8].nome,"Pica-pau");
    baralho[8].is_super_trunfo = 0;
    baralho[8].forca = 3;
    baralho[8].habilidade = 7;
    baralho[8].inteligencia = 7;
    baralho[8].velocidade = 7;
    
    baralho[9].flag = 'A';
    strcpy(baralho[9].nome,"O Marinheiro Popeye");
    baralho[9].is_super_trunfo = 0;
    baralho[9].forca = 9;
    baralho[9].habilidade = 6;
    baralho[9].inteligencia = 1;
    baralho[9].velocidade = 1;
    
    baralho[10].flag = 'D';
    strcpy(baralho[10].nome,"Dick Vigarista pegue o pombo");
    baralho[10].is_super_trunfo = 0;
    baralho[10].forca = 2;
    baralho[10].habilidade = 2;
    baralho[10].inteligencia = 2;
    baralho[10].velocidade = 2;
    
    baralho[11].flag = 'C';
    strcpy(baralho[11].nome,"Tartarugas Ninja");
    baralho[11].is_super_trunfo = 0;
    baralho[11].forca = 4;
    baralho[11].habilidade = 5;
    baralho[11].inteligencia = 5;
    baralho[11].velocidade = 3;
    
    baralho[12].flag = 'B';
    strcpy(baralho[12].nome,"Homem de Ferro");
    baralho[12].is_super_trunfo = 0;
    baralho[12].forca = 6;
    baralho[12].habilidade = 5;
    baralho[12].inteligencia = 5;
    baralho[12].velocidade = 4;
    
    baralho[13].flag = 'B';
    strcpy(baralho[13].nome,"Gohan");
    baralho[13].is_super_trunfo = 0;
    baralho[13].forca = 6;
    baralho[13].habilidade = 3;
    baralho[13].inteligencia = 2;
    baralho[13].velocidade = 4;
    
    baralho[14].flag = 'B';
    strcpy(baralho[14].nome,"Mestre dos Magos");
    baralho[14].is_super_trunfo = 0;
    baralho[14].forca = 1;
    baralho[14].habilidade = 8;
    baralho[14].inteligencia = 8;
    baralho[14].velocidade = 1;
    
    baralho[15].flag = 'C';
    strcpy(baralho[15].nome,"Mulher-Gato");
    baralho[15].is_super_trunfo = 0;
    baralho[15].forca = 1;
    baralho[15].habilidade = 5;
    baralho[15].inteligencia = 8;
    baralho[15].velocidade = 1;
    
    baralho[16].flag = 'B';
    strcpy(baralho[16].nome,"Lanterna Verde");
    baralho[16].is_super_trunfo = 0;
    baralho[16].forca = 4;
    baralho[16].habilidade = 4;
    baralho[16].inteligencia = 4;
    baralho[16].velocidade = 3;
    
    baralho[17].flag = 'A';
    strcpy(baralho[17].nome,"Goku");
    baralho[17].is_super_trunfo = 0;
    baralho[17].forca = 9;
    baralho[17].habilidade = 6;
    baralho[17].inteligencia = 5;
    baralho[17].velocidade = 4;
    
    baralho[18].flag = 'D';
    strcpy(baralho[18].nome,"Wolverine");
    baralho[18].is_super_trunfo = 0;
    baralho[18].forca = 4;
    baralho[18].habilidade = 3;
    baralho[18].inteligencia = 3;
    baralho[18].velocidade = 3;
    
    baralho[19].flag = 'B';
    strcpy(baralho[19].nome,"Naruto");
    baralho[19].is_super_trunfo = 0;
    baralho[19].forca = 4;
    baralho[19].habilidade = 2;
    baralho[19].inteligencia = 5;
    baralho[19].velocidade = 2;
    
    baralho[20].flag = 'D';
    strcpy(baralho[20].nome,"Mulher Maravilha");
    baralho[20].is_super_trunfo = 0;
    baralho[20].forca = 2;
    baralho[20].habilidade = 5;
    baralho[20].inteligencia = 8;
    baralho[20].velocidade = 4;
    
    baralho[21].flag = 'C';
    strcpy(baralho[21].nome,"Pantera cor de rosa");
    baralho[21].is_super_trunfo = 0;
    baralho[21].forca = 1;
    baralho[21].habilidade = 9;
    baralho[21].inteligencia = 9;
    baralho[21].velocidade = 1;
    
    baralho[22].flag = 'A';
    strcpy(baralho[22].nome,"He-Man 'eu tenho a forca haha'");
    baralho[22].is_super_trunfo = 0;
    baralho[22].forca = 8;
    baralho[22].habilidade = 2;
    baralho[22].inteligencia = 2;
    baralho[22].velocidade = 2;
    
    baralho[23].flag = 'B';
    strcpy(baralho[23].nome,"Sonic");
    baralho[23].is_super_trunfo = 0;
    baralho[23].forca = 2;
    baralho[23].habilidade = 6;
    baralho[23].inteligencia = 10;
    baralho[23].velocidade = 9;
}



// gera numero aleatorio entre 0 e o limite passado por parametro
int generate_random_number(int limite){
    return rand()%limite;
}



/*
a struct baralho tem 24 cartas, o indices vão de 0 a 23,
esses indices 0 até 23 precisam ser distribuidos aleatoriamente para as listas de 12 cartas dos JOGADORES
a ideia então foi gerar numeros entre 0 e 23 em uma ordem aleatoria e adicionar num vetor
então os valores no vetor ficariam por exemplo 4,6,20,0,5,18,21... ou seja os indices da struct baralho
que precisam ser adicionados no baralho de cada jogador (indice 0 até 23) ficariam embaralhados dentro vetor
e na hora de distribuir as cartas em vez de ser baralho_j1[i] = baralho[i] ficaria
baralho_j1[i]=baralho[vetor_indices[i]] pois o vetor_indices na posicao 0 tem um valor entre 0 e 23 aleatorio
por exemplo: vetor_indices[0] = 14 então baralho_j1[i]=baralho[vetor_indices[i]] seria o mesmo que fazer
baralho_j1[i]=baralho[14] fazendo com que a distribuição de cartas seja aleatoria a cada execucao do algoritmo
*/
void embaralhar_indices(int vetor_indices[TAMANHO]){
    int numero_gerado;
    
    //preenche vetor com valor padrao para evitar problemas com valores aleatorios
    for(int i=0;i<TAMANHO;i++){
        vetor_indices[i]=-1;
    }
    
    //gera numero aleatorio entre 0 e 23 e verifica se não é repetido, se for gera até não ser repetido
    for(int i=0;i<TAMANHO;i++){
        char ja_foi_gerado='n';
        numero_gerado = generate_random_number(24);
        
        for(int j=0;j<TAMANHO;j++){
            if(numero_gerado==vetor_indices[j]){
                ja_foi_gerado='s';
            }
        }
        
        while(ja_foi_gerado=='s'){
            ja_foi_gerado='n';
            numero_gerado = generate_random_number(24);

            for(int k=0;k<TAMANHO;k++){
                if(numero_gerado==vetor_indices[k]){
                    ja_foi_gerado='s';
                }
            }
        }

        vetor_indices[i]=numero_gerado;
    }
}


//gera um numero de 0 a 3, cada numero identifica uma caracteristica
int sortear_caracteristica(int jogador){
    jogador == 1 ? printf("JOGADOR 1 ESCOLHEU: ") : printf("JOGADOR 2 ESCOLHEU: ");
    return generate_random_number(4);
}


/* imprime as cartas dos jogadores, caso seja passado 1 no parametro show 
é feita uma impressao simplificada só com os nomes das cartas para não poluir a tela*/
void imprimir(
    Baralho baralho_j1[TAMANHO], 
    Baralho baralho_j2[TAMANHO], 
    Baralho mesa[TAMANHO],
    int qtd_cartas_j1, 
    int qtd_cartas_j2,
    int tamanho_mesa,
    int show
){
    printf("\n\n################## CARTAS DOS JOGADORES ####################\n\n");
    
    if(show==1){
        printf("###### CARTAS JOGADOR 1 ######\n\n");
        printf("------- JOGADOR 1 POSSUI %d CARTAS -------\n\n",qtd_cartas_j1);
    
        for(int i=0;i<qtd_cartas_j1;i++){
            printf("Nome: %s\n",baralho_j1[i].nome);
        }
        
        printf("\n\n###### CARTAS JOGADOR 2 ######\n\n");
        printf("------- JOGADOR 2 POSSUI %d CARTAS -------\n\n",qtd_cartas_j2);
         
        for(int i=0;i<qtd_cartas_j2;i++){
            printf("Nome: %s\n",baralho_j2[i].nome);
        }
        
        printf("\n\n");
    }
    else{
        printf("###### CARTAS JOGADOR 1 ######\n\n");
        printf("------- JOGADOR 1 POSSUI %d CARTAS -------\n\n",qtd_cartas_j1);
    
        for(int i=0;i<qtd_cartas_j1;i++){
            printf("Nome: %s\n",baralho_j1[i].nome);
            printf("Flag: %c\n",baralho_j1[i].flag);
            printf("Super-trunfo? ");
            baralho_j1[i].is_super_trunfo == 0 ? printf("NAO\n") : printf("SIM\n");
            printf("Força: %d\n",baralho_j1[i].forca);
            printf("Habilidade: %d\n",baralho_j1[i].habilidade);
            printf("Inteligencia: %d\n",baralho_j1[i].inteligencia);
            printf("Velocidade: %d\n",baralho_j1[i].velocidade);
            
            printf("\n\n");
        }
        
        printf("###### CARTAS JOGADOR 2 ######\n\n");
        printf("------- JOGADOR 2 POSSUI %d CARTAS -------\n\n",qtd_cartas_j2);
         
        for(int i=0;i<qtd_cartas_j2;i++){
            printf("Nome: %s\n",baralho_j2[i].nome);
            printf("Flag: %c\n",baralho_j2[i].flag);
            printf("Super-trunfo? ");
            baralho_j2[i].is_super_trunfo == 0 ? printf("NAO\n") : printf("SIM\n");
            printf("Força: %d\n",baralho_j2[i].forca);
            printf("Habilidade: %d\n",baralho_j2[i].habilidade);
            printf("Inteligencia: %d\n",baralho_j2[i].inteligencia);
            printf("Velocidade: %d\n",baralho_j2[i].velocidade);
            
            printf("\n\n");
        }
        
    }

    printf("\n\n####### CARTAS NA MESA #######\n\n");
    printf("Total de Cartas na mesa: %d\n\n",tamanho_mesa);

    for(int i=0;i<tamanho_mesa;i++){
        printf("Nome: %s\n",mesa[i].nome);
    }
    
    printf("#################################\n\n");
}


/*
adiciona a carta do adversário no final da lista de cartas do vencedor
coloca a carta na posicao[0] do vencedor pra ultima posicao do baralho dele
verifica se tem cartas na mesa e se tiver adiciona todas elas para o vencedor
*/
void adicionar_carta_adversario(
    Baralho baralho_jogador_vencedor[TAMANHO],
    Baralho baralho_jogador_perdedor[TAMANHO],
    Baralho mesa[TAMANHO],
    int qtd_cartas_baralho_vencedor,
    int qtd_cartas_baralho_perdedor,
    int qtd_cartas_na_mesa
){
    //adiciona a carta do perdedor no final do baralho do vencedor
    baralho_jogador_vencedor[qtd_cartas_baralho_vencedor-1] = baralho_jogador_perdedor[0];
    
    //salva a carta do vencedor na posicao 0, pois ela sera sobrescrita no for abaixo
    Baralho baralho_aux = baralho_jogador_vencedor[0];
    
    for(int i=0;i<qtd_cartas_baralho_vencedor;i++){
        baralho_jogador_vencedor[i] = baralho_jogador_vencedor[i+1];
    }

    //adiciona na ultima posicao do baralho do vencedor a carta que estava na posicao 0
    baralho_jogador_vencedor[qtd_cartas_baralho_vencedor-1] = baralho_aux;

    for(int i=0;i<qtd_cartas_baralho_perdedor;i++){
        baralho_jogador_perdedor[i] = baralho_jogador_perdedor[i+1];
    }
    
    if(qtd_cartas_na_mesa>0){
        
        //se qtd_cartas_baralho_vencedor for 12 e qtd_cartas_na_mesa for 4, entao o for comeca em 12 e
        //vai até 12+4=16, e adiciona no baralho do vencedor nos indices 12,13,14 e 15 as cartas da mesa
        for(int i=qtd_cartas_baralho_vencedor;i<qtd_cartas_baralho_vencedor+qtd_cartas_na_mesa;i++){
            baralho_jogador_vencedor[i] = mesa[i-qtd_cartas_baralho_vencedor];
        }
        
        qtd_cartas_baralho_vencedor+=qtd_cartas_na_mesa;
        
    }
    
}



//adiciona as cartas da rodada na struct mesa em caso de empate, 
//se for a ultima carta do jogador não adiciona pra que ele não fique sem cartas
void adicionar_carta_na_mesa(
    Baralho mesa[TAMANHO],
    Baralho baralho_jogador_1[TAMANHO],
    Baralho baralho_jogador_2[TAMANHO],
    int qtd_cartas_na_mesa,
    int qtd_cartas_j1,
    int qtd_cartas_j2
){
    if(qtd_cartas_j1>1){
        mesa[qtd_cartas_na_mesa] = baralho_jogador_1[0];
        
        //a carta do jogador que foi adicionada na mesa é tirada do baralho dele
        for(int i=0;i<qtd_cartas_j1;i++){
            baralho_jogador_1[i] = baralho_jogador_1[i+1];
        }
    }
    
    if(qtd_cartas_j2>1){
        if(qtd_cartas_j1>1){
            mesa[qtd_cartas_na_mesa+1] = baralho_jogador_2[0];
        }
        else{
            mesa[qtd_cartas_na_mesa] = baralho_jogador_2[0];
        }
        
        for(int i=0;i<qtd_cartas_j2;i++){
            baralho_jogador_2[i] = baralho_jogador_2[i+1];
        }
    }
}


//funcao onde roda o jogo
void play(
    Baralho baralho_jogador_1[TAMANHO],
    Baralho baralho_jogador_2[TAMANHO],
    int total_cartas_baralho_j1,
    int total_cartas_baralho_j2,
    int embaralhar_indices_baralho[TAMANHO]
){
    Baralho mesa[TAMANHO];
    int jogador_escolhe=1, rodada=1, indice_inserir_mesa=0, total_cartas_na_mesa=0, caracteristica_escolhida, i=0;
    //char vencedor[10];
    
    imprimir(
        baralho_jogador_1,
        baralho_jogador_2,
        mesa,
        total_cartas_baralho_j1,
        total_cartas_baralho_j2,
        total_cartas_na_mesa,
        0
    );
    
    
    printf("\n\npressione ENTER para iniciar");
    getchar();
    
    printf("\n\n");
    
    //se o total de cartas de um jogador ficar igual a zero sai do while e acaba o jogo
    while(total_cartas_baralho_j1>0 && total_cartas_baralho_j2>0){
            printf("\n\n\n####################  %d° RODADA  #################\n\n\n",rodada);
        
            /*
                0: Força
                1: Habilidade
                2: Inteligencia
                3: Velocidade
            */
            caracteristica_escolhida = sortear_caracteristica(jogador_escolhe);
            if(caracteristica_escolhida==0) printf("Força\n");
            else if(caracteristica_escolhida==1) printf("Habilidade\n");
            else if(caracteristica_escolhida==2) printf("Inteligencia\n");
            else printf("Velocidade\n");
            
            
            printf("\n\nDUELO:\n\n");
            
            printf("CARTA JOGADOR 1:\n");
            printf("Nome: %s\n",baralho_jogador_1[0].nome);
            printf("Flag: %c\n",baralho_jogador_1[0].flag);
            
            printf("Super-trunfo: ");
            baralho_jogador_1[0].is_super_trunfo == 1 ? printf("SIM\n") : printf("NAO\n");
            
            caracteristica_escolhida==0
                ? printf("--------------\nForca: %d\n--------------\n",baralho_jogador_1[0].forca) 
                : printf("Forca: %d\n",baralho_jogador_1[0].forca);
                
            caracteristica_escolhida==1 
                ? printf("--------------\nHabilidade: %d\n--------------\n",baralho_jogador_1[0].habilidade) 
                : printf("Habilidade: %d\n",baralho_jogador_1[0].habilidade);
                
            caracteristica_escolhida==2 
                ? printf("--------------\nInteligencia: %d\n--------------\n",baralho_jogador_1[0].inteligencia)
                : printf("Inteligencia: %d\n",baralho_jogador_1[0].inteligencia);
            
            caracteristica_escolhida==3
                ? printf("--------------\nVelocidade: %d\n--------------\n",baralho_jogador_1[0].velocidade)
                : printf("Velocidade: %d\n",baralho_jogador_1[0].velocidade);
            
            printf("\n\tVS.\n");
            
            printf("\nCARTA JOGADOR 2:\n");
            printf("Nome: %s\n",baralho_jogador_2[0].nome);
            printf("Flag: %c\n",baralho_jogador_2[0].flag);
            
            printf("Super-trunfo: ");
            baralho_jogador_2[0].is_super_trunfo == 1 ? printf("SIM\n") : printf("NAO\n");
            
            caracteristica_escolhida==0
                ? printf("--------------\nForca: %d\n--------------\n",baralho_jogador_2[0].forca)
                : printf("Forca: %d\n",baralho_jogador_2[0].forca);
                
            caracteristica_escolhida==1
                ? printf("--------------\nHabilidade: %d\n--------------\n",baralho_jogador_2[0].habilidade)
                : printf("Habilidade: %d\n",baralho_jogador_2[0].habilidade);
            
            caracteristica_escolhida==2
                ? printf("--------------\nInteligencia: %d\n--------------\n",baralho_jogador_2[0].inteligencia)
                : printf("Inteligencia: %d\n",baralho_jogador_2[0].inteligencia);
            
            caracteristica_escolhida==3
                ? printf("--------------\nVelocidade: %d\n--------------\n",baralho_jogador_2[0].velocidade)
                : printf("Velocidade: %d\n",baralho_jogador_2[0].velocidade);
            
            /*
                verifica se a carta da rodada é Super-trunfo em algum dos jogadores, se sim, verifica se o adversário
                tem uma carta do tipo A, se ele tiver, o jogador que tiver a carta Super-trunfo perde,
                senão for tipo A a carta do adversário, ele ganha, se nao houver carta Super-trunfo na rodada
                começa a comparar a caracteristica escolhida pelo jogador
            */
            if(baralho_jogador_1[0].is_super_trunfo==1){
                    
                if(baralho_jogador_2[0].flag=='A'){
                    
                    //incrementa o total de cartas do jogador vencedor, chama a funcao
                    //pra adicionar a carta do perdedor no baralho do vencedor e
                    //retirar do baralho do perdedor, e depois decrementa o total de cartas do perdedor
                    
                    total_cartas_baralho_j2++;
                    
                    adicionar_carta_adversario(
                        baralho_jogador_2,
                        baralho_jogador_1,
                        mesa,
                        total_cartas_baralho_j2,
                        total_cartas_baralho_j1,
                        total_cartas_na_mesa
                    );
                    
                    if(total_cartas_na_mesa>0){
                        total_cartas_baralho_j2+=total_cartas_na_mesa;
                        total_cartas_na_mesa = 0;
                    }
                        
                    total_cartas_baralho_j1--;
                       
                    jogador_escolhe=2;
                    
                    printf("\nVENCEDOR: JOGADOR 2 POIS ELE TEM UMA CARTA 'A' QUE VENCE A CARTA 'SUPER-TRUNFO'\n");
                }
                else{
        
                    total_cartas_baralho_j1++;
                    
                    adicionar_carta_adversario(
                        baralho_jogador_1,
                        baralho_jogador_2,
                        mesa,
                        total_cartas_baralho_j1,
                        total_cartas_baralho_j2,
                        total_cartas_na_mesa
                    );
                    
                    //se tiver cartas na mesa, soma o total de cartas do jogador com o total_cartas_na_mesa
                    //e depois zera o total_cartas_na_mesa, e depois decrementa o total de cartas do perdedor
                    if(total_cartas_na_mesa>0){
                        total_cartas_baralho_j1+=total_cartas_na_mesa;
                        total_cartas_na_mesa = 0;
                    }
                        
                    total_cartas_baralho_j2--;
                        
                    jogador_escolhe=1;
                    printf("\nVENCEDOR: JOGADOR 1 POIS ELE TEM UMA CARTA 'SUPER-TRUNFO'\n");
                }
                
            }
            else if(baralho_jogador_2[0].is_super_trunfo==1){
                    
                if(baralho_jogador_1[0].flag=='A'){
                    
                    total_cartas_baralho_j1++;
                    
                    adicionar_carta_adversario(
                        baralho_jogador_1,
                        baralho_jogador_2,
                        mesa,
                        total_cartas_baralho_j1,
                        total_cartas_baralho_j2,
                        total_cartas_na_mesa
                    );
                    
                    if(total_cartas_na_mesa>0){
                        total_cartas_baralho_j1+=total_cartas_na_mesa;
                        total_cartas_na_mesa = 0;
                    }
                        
                    total_cartas_baralho_j2--;
                        
                    jogador_escolhe=1;
                    
                    printf("\nVENCEDOR: JOGADOR 1 POIS ELE TEM UMA CARTA 'A' QUE VENCE A CARTA 'SUPER-TRUNFO'\n");
                }
                else{
                    
                    total_cartas_baralho_j2++;
                    
                    adicionar_carta_adversario(
                        baralho_jogador_2,
                        baralho_jogador_1,
                        mesa,
                        total_cartas_baralho_j2,
                        total_cartas_baralho_j1,
                        total_cartas_na_mesa
                    );
                    
                    if(total_cartas_na_mesa>0){
                        total_cartas_baralho_j2+=total_cartas_na_mesa;
                        total_cartas_na_mesa = 0;
                    }
                    
                    total_cartas_baralho_j1--;
                        
                    jogador_escolhe=2;
                    printf("\nVENCEDOR: JOGADOR 2 POIS ELE TEM UMA CARTA 'SUPER-TRUNFO'\n");
                }
                
            }
            
            
            else{
                
                if(caracteristica_escolhida==0){
                    
                    if(baralho_jogador_1[0].forca > baralho_jogador_2[0].forca){
                        
                        total_cartas_baralho_j1++;
                        
                        adicionar_carta_adversario(
                            baralho_jogador_1,
                            baralho_jogador_2,
                            mesa,
                            total_cartas_baralho_j1,
                            total_cartas_baralho_j2,
                            total_cartas_na_mesa
                        );
                        
                        if(total_cartas_na_mesa>0){
                            total_cartas_baralho_j1+=total_cartas_na_mesa;
                            total_cartas_na_mesa = 0;
                        }
                        
                        total_cartas_baralho_j2--;
                        
                        jogador_escolhe=1;
                        
                        printf("\nVENCEDOR: JOGADOR 1\n");
                        
                    }
                    else if(baralho_jogador_1[0].forca < baralho_jogador_2[0].forca){
                        
                        total_cartas_baralho_j2++;
                        
                        adicionar_carta_adversario(
                            baralho_jogador_2,
                            baralho_jogador_1,
                            mesa,
                            total_cartas_baralho_j2,
                            total_cartas_baralho_j1,
                            total_cartas_na_mesa
                        );
                        
                        if(total_cartas_na_mesa>0){
                            total_cartas_baralho_j2+=total_cartas_na_mesa;
                            total_cartas_na_mesa = 0;
                        }
                        
                        total_cartas_baralho_j1--;
                       
                        jogador_escolhe=2;
                        
                        printf("\nVENCEDOR: JOGADOR 2\n");
                    }
                    else{
                        
                        adicionar_carta_na_mesa(
                            mesa,
                            baralho_jogador_1,
                            baralho_jogador_2,
                            total_cartas_na_mesa,
                            total_cartas_baralho_j1,
                            total_cartas_baralho_j2
                        );
                        
                        if(total_cartas_baralho_j1>1){
                            total_cartas_na_mesa++;
                            total_cartas_baralho_j1--;
                        }
                        if(total_cartas_baralho_j2>1){
                            total_cartas_na_mesa++;
                            total_cartas_baralho_j2--;
                        }
                        
                        printf("\nEMPATE\n");
                    }
                    
                }
                else if(caracteristica_escolhida==1){
                    
                    if(baralho_jogador_1[0].habilidade > baralho_jogador_2[0].habilidade){
                        
                        total_cartas_baralho_j1++;
                        
                        adicionar_carta_adversario(
                            baralho_jogador_1,
                            baralho_jogador_2,
                            mesa,
                            total_cartas_baralho_j1,
                            total_cartas_baralho_j2,
                            total_cartas_na_mesa
                        );
                        
                        if(total_cartas_na_mesa>0){
                            total_cartas_baralho_j1+=total_cartas_na_mesa;
                            total_cartas_na_mesa = 0;
                        }
                        
                        total_cartas_baralho_j2--;
                        
                        jogador_escolhe=1;
                        
                        printf("\nVENCEDOR: JOGADOR 1\n");
                    }
                    else if(baralho_jogador_1[0].habilidade < baralho_jogador_2[0].habilidade){
                        
                        total_cartas_baralho_j2++;
                        
                        adicionar_carta_adversario(
                            baralho_jogador_2,
                            baralho_jogador_1,
                            mesa,
                            total_cartas_baralho_j2,
                            total_cartas_baralho_j1,
                            total_cartas_na_mesa
                        );
                        
                        if(total_cartas_na_mesa>0){
                            total_cartas_baralho_j2+=total_cartas_na_mesa;
                            total_cartas_na_mesa = 0;
                        }
                    
                        total_cartas_baralho_j1--;
                        
                        jogador_escolhe=2;
                        
                        printf("\nVENCEDOR: JOGADOR 2\n");
                    }
                    else{
                        
                        adicionar_carta_na_mesa(
                            mesa,
                            baralho_jogador_1,
                            baralho_jogador_2,
                            total_cartas_na_mesa,
                            total_cartas_baralho_j1,
                            total_cartas_baralho_j2
                        );
                        
                        if(total_cartas_baralho_j1>1){
                            total_cartas_na_mesa++;
                            total_cartas_baralho_j1--;
                        }
                        if(total_cartas_baralho_j2>1){
                            total_cartas_na_mesa++;
                            total_cartas_baralho_j2--;
                        }
                        
                        printf("\nEMPATE\n");
                    }
                    
                }
                else if(caracteristica_escolhida==2){
                    
                    if(baralho_jogador_1[0].inteligencia > baralho_jogador_2[0].inteligencia){
                        
                        total_cartas_baralho_j1++;
                        
                        adicionar_carta_adversario(
                            baralho_jogador_1,
                            baralho_jogador_2,
                            mesa,
                            total_cartas_baralho_j1,
                            total_cartas_baralho_j2,
                            total_cartas_na_mesa
                        );
                        
                        if(total_cartas_na_mesa>0){
                            total_cartas_baralho_j1+=total_cartas_na_mesa;
                            total_cartas_na_mesa = 0;
                        }
                        
                        total_cartas_baralho_j2--;
                        
                        jogador_escolhe=1;
                        
                        printf("\nVENCEDOR: JOGADOR 1\n");
                    }
                    else if(baralho_jogador_1[0].inteligencia < baralho_jogador_2[0].inteligencia){
                        
                        total_cartas_baralho_j2++;
                        
                        adicionar_carta_adversario(
                            baralho_jogador_2,
                            baralho_jogador_1,
                            mesa,
                            total_cartas_baralho_j2,
                            total_cartas_baralho_j1,
                            total_cartas_na_mesa
                        );
                        
                        if(total_cartas_na_mesa>0){
                            total_cartas_baralho_j2+=total_cartas_na_mesa;
                            total_cartas_na_mesa = 0;
                        }
                        
                        total_cartas_baralho_j1--;
                        
                        jogador_escolhe=2;
                        
                        printf("\nVENCEDOR: JOGADOR 2\n");
                    }
                    else{
                        
                        adicionar_carta_na_mesa(
                            mesa,
                            baralho_jogador_1,
                            baralho_jogador_2,
                            total_cartas_na_mesa,
                            total_cartas_baralho_j1,
                            total_cartas_baralho_j2
                        );
                        
                        if(total_cartas_baralho_j1>1){
                            total_cartas_na_mesa++;
                            total_cartas_baralho_j1--;
                        }
                        if(total_cartas_baralho_j2>1){
                            total_cartas_na_mesa++;
                            total_cartas_baralho_j2--;
                        }
                        
                        printf("\nEMPATE\n");
                    }
                    
                }
                else{
                    
                    if(baralho_jogador_1[0].velocidade > baralho_jogador_2[0].velocidade){
                        
                        total_cartas_baralho_j1++;
                        
                        adicionar_carta_adversario(
                            baralho_jogador_1,
                            baralho_jogador_2,
                            mesa,
                            total_cartas_baralho_j1,
                            total_cartas_baralho_j2,
                            total_cartas_na_mesa
                        );
                        
                        if(total_cartas_na_mesa>0){
                            total_cartas_baralho_j1+=total_cartas_na_mesa;
                            total_cartas_na_mesa = 0;
                        }
                        
                        total_cartas_baralho_j2--;
                        
                        jogador_escolhe=1;
                        
                        printf("\nVENCEDOR: JOGADOR 1\n");
                    }
                    else if(baralho_jogador_1[0].velocidade < baralho_jogador_2[0].velocidade){
                        
                        total_cartas_baralho_j2++;
                        
                        adicionar_carta_adversario(
                            baralho_jogador_2,
                            baralho_jogador_1,
                            mesa,
                            total_cartas_baralho_j2,
                            total_cartas_baralho_j1,
                            total_cartas_na_mesa
                        );
                        
                        if(total_cartas_na_mesa>0){
                            total_cartas_baralho_j2+=total_cartas_na_mesa;
                            total_cartas_na_mesa = 0;
                        }
                        
                        total_cartas_baralho_j1--;
                        
                        jogador_escolhe=2;
                        
                        printf("\nVENCEDOR: JOGADOR 2\n");
                    }
                    else{
                        
                        adicionar_carta_na_mesa(
                            mesa,
                            baralho_jogador_1,
                            baralho_jogador_2,
                            total_cartas_na_mesa,
                            total_cartas_baralho_j1,
                            total_cartas_baralho_j2
                        );
                        
                        //decrementa o total de cartas dos 2 baralhos se não for a ultima carta que o jogador tiver
                        if(total_cartas_baralho_j1>1){
                            total_cartas_na_mesa++;
                            total_cartas_baralho_j1--;
                        }
                        if(total_cartas_baralho_j2>1){
                            total_cartas_na_mesa++;
                            total_cartas_baralho_j2--;
                        }
                        
                        printf("\nEMPATE\n");
                    }
                    
                }
            }
            
            
            imprimir(
                baralho_jogador_1,
                baralho_jogador_2,
                mesa,
                total_cartas_baralho_j1,
                total_cartas_baralho_j2,
                total_cartas_na_mesa,
                1
            );
            
            
            if(total_cartas_baralho_j1==0){
                printf("\n\n----------- FIM DE JOGO ------------\n\n");
                printf("VENCEDOR JOGADOR 2");
            }
            if(total_cartas_baralho_j2==0){
                printf("\n\n----------- FIM DE JOGO ------------\n\n");
                printf("VENCEDOR JOGADOR 1");
            }
            
            getchar();
        
            //i++;
            rodada++;
        
    }
    
    //printf("\n\n----------- FIM DE JOGO ------------\n\n");
    //printf("VENCEDOR: %s",vencedor);
}


int main()
{
    srand(time(0));
    
    Baralho baralho[TAMANHO], baralho_jogador_1[TAMANHO], baralho_jogador_2[TAMANHO], mesa[TAMANHO];
    int total_cartas_baralho_j1=0, total_cartas_baralho_j2=0, total_cartas_na_mesa=0;
    int embaralhar_indices_baralho[TAMANHO];
    
    setar_baralho(baralho);
    
    embaralhar_indices(embaralhar_indices_baralho);
    
    printf("\n\n");
    
    //distribui as cartas para os jogadores meio a meio, nos indices pares
    //distribui pro jogador1 e nos impares pro jogador2 com isso cada jogador tera metade do total de cartas
    int cont_j1=0,cont_j2=0;
    for(int i=0;i<TAMANHO;i++){
        if(i%2==0){
            baralho_jogador_1[cont_j1]=baralho[embaralhar_indices_baralho[i]];
            cont_j1++;
            total_cartas_baralho_j1++;
        }
        else{
            baralho_jogador_2[cont_j2]=baralho[embaralhar_indices_baralho[i]];
            cont_j2++;
            total_cartas_baralho_j2++;
        }
    }
    
    play(
        baralho_jogador_1,
        baralho_jogador_2,
        total_cartas_baralho_j1,
        total_cartas_baralho_j2,
        embaralhar_indices_baralho
    );

    return 0;
}

