/******************************************************************************

Conan é um importante membro do Clube Atlético de Desrugenstein, que possui um time de futebol de campo profissional: 
ele é o responsável pelo gramado do campo onde ocorrem os jogos em casa. Em 2048 anos de história, o campo do CAD sempre esteve em perfeitas condições para os jogos, graças a Conan. 
Ele já ganhou vários prêmios por isso, sendo o mais importante deles o "Grama de Ouro", prêmio que ganhou 1024 vezes.

Amanhã acontecerá a final do campeonato Universal de futebol, e o CAD é um dos finalistas. Como o jogo será em casa, Conan foi ver o estado do gramado e reparar se necessário. 
Chegando lá, entrou em desespero ao ver várias schweisen no campo, estragando todo o gramado!!

Sendo assim, Conan precisa de sua ajuda para determinar quanto irá gastar com deswevileutssen para matar todas as schweisen. Cada deswevileutssen mata uma schwisen. 
Conan pode lhe mandar mensagens de dois tipos: dizendo que encontrou algumas schweisen, ou perguntando quanto ele vai gastar para matar certas schweisen.


A entrada possui vários casos de teste. A primeira linha de um caso de teste contém 3 inteiros X (≤ 1000), Y (≤ 1000) e P (≤ 10), 
que representam, respectivamente, o tamanho (X e Y) do campo e o preço de cada deswevileutssen. 
A próxima linha contém um inteiro Q (≤ 10000). As próximas Q linhas representam mensagens de Conan para você, e estão em uma das duas seguintes formas:

- A N X Y - “Achei N (≤ 10) schweisen em (X,Y) - (0 ≤ X < Largura), (0 ≤ Y < Altura)”

- P X Y Z W - “Quanto vou gastar para matar todas as schweisen na área retangular de (X,Y) até (Z,W)?”

Considere que no início nenhuma schweisen foi vista.

A entrada termina quando X, Y e P são iguais a 0.

Para cada mensagem do tipo "P", imprima o valor que responde a pergunta feita. Deixe uma linha em branco após cada caso de teste, inclusive após o último.

Exemplo de Entrada	Exemplo de Saída
2 2 10              140
7                   270
A 5 1 1
A 9 1 0
A 2 0 0
P 1 0 1 1
A 4 0 1
A 7 1 0
P 0 1 1 0
0 0 0
*******************************************************************************/

#include <stdio.h>

int main()
{
    int linhas = 0, colunas = 0, preco = 0, total_mensagens = 0;
    
    while(1){
        scanf("%d %d %d",&linhas, &colunas, &preco);
        scanf("%d",&total_mensagens);
        
        int matriz[linhas][colunas];
        
        for(int i=0;i<linhas;i++){
            for(int j=0;j<colunas;j++){
                matriz[i][j]=0;
            }
        }
        
        for(int i=0; i<total_mensagens; i++){
            char tipo_mensagem;
            int total_pragas, x, y, z, w;
            
            scanf(" %c", &tipo_mensagem);
            
            if(tipo_mensagem == 'A'){
                scanf("%d %d %d",&total_pragas, &x, &y);
                matriz[x][y] += total_pragas;
            }
            else if(tipo_mensagem == 'P'){
                int total_a_pagar = 0;
                int inicio_linha, fim_linha, inicio_coluna, fim_coluna;
                
                scanf("%d %d %d %d",&x, &y, &z, &w);
                
                if(x < z){
                    inicio_linha = x;
                    fim_linha = z;
                }
                else{
                    inicio_linha = z;
                    fim_linha = x;
                }
                
                if(y < w){
                    inicio_coluna = y;
                    fim_coluna = w;
                }
                else{
                    inicio_coluna = w;
                    fim_coluna = y;
                }
                
                //printf("%d %d %d %d",inicio_linha, fim_linha, inicio_coluna, fim_coluna);
                for(int i = inicio_linha; i <= fim_linha; i++){
                    
                    for(int j = inicio_coluna; j <= fim_coluna; j++){
                        //printf("\t22 -> %d\n",matriz[i][j]);
                        total_a_pagar += preco * matriz[i][j];
                        //printf("[%d][%d] = %d, %d\n",i,j,matriz[i][j], preco * matriz[i][j]);
                    }
                    
                }
                
                printf("%d\n",total_a_pagar);
                
            }
            else if(tipo_mensagem == '0' && x == 0 && y == 0){
                break;
            }
        }
        printf("\n");
    }
    return 0;
}



