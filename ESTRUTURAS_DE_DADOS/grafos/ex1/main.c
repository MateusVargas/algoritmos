/******************************************************************************

Analisando os conceitos estudados, crie um diagrama de um grafo que representa um contexto qualquer a sua escolha (deve existir!);
Defina se é um grafo orientado ou não-orientado;
Desenvolva um algoritmo em C para representar o grafo através de sua matriz de adjacência;
Detalhe: lembre-se que um grafo pode ganhar nós ao longo do tempo.

*******************************************************************************/
#include <stdio.h>

#define TOTAL_CIDADES 7

void check(int mat[TOTAL_CIDADES][TOTAL_CIDADES], char cidade[30], int i){
    
    for(int j=0;j<TOTAL_CIDADES;j++){
        if(mat[i][j]==1){
            //0- são martinho da serra
            if(j==0){
                printf("< %s, são martinho da serra >\n",cidade);
            }
            //1- itaara
            else if(j==1){
                printf("< %s, itaara >\n",cidade);
            }
                
            //2 - ivorá
            else if(j==2){
                printf("< %s, ivorá >\n",cidade);
            }
                
            //3 - silveira martins
            else if(j==3){
                printf("< %s, silveira martins >\n",cidade);
            }
                
            //4 - santa maria
            else if(j==4){
                printf("< %s, santa maria >\n",cidade);
            }
                
            //5 - são pedro
            else if(j==5){
                printf("< %s, são pedro >\n",cidade);
            }
                
            //6 - formigueiro
            else{
                printf("< %s, formigueiro >\n",cidade);
            }
        }
    }
}

int main()
{
    int i, fim=0;
    int mat[TOTAL_CIDADES][TOTAL_CIDADES];
    
    /*
    0 - são martinho da serra
    1 - itaara
    2 - ivorá
    3 - silveira martins
    4 - santa maria
    5 - são pedro
    6 - formigueiro
    */
    
    
    for(i=0;i<TOTAL_CIDADES;i++){
        
        for(int j=0;j<TOTAL_CIDADES;j++){
            
            //0 - são martinho da serra
            if(i==0){
                if(j==5 || j==4 || j==1)
                    mat[i][j] = 1;
                else
                    mat[i][j] = 0;
            }
            
            //1 - itaara
            else if(i==1){
                if(j==4 || j==0)
                    mat[i][j] = 1;
                else
                    mat[i][j] = 0;
            }
            
            //2 - ivorá
            else if(i==2){
                if(j==3)
                    mat[i][j] = 1;
                else
                    mat[i][j] = 0;
            }
            
            //3 - silveira martins
            else if(i==3){
                if(j==4 || j==2)
                    mat[i][j] = 1;
                else
                    mat[i][j] = 0;
            }
            
            //4 - santa maria
            else if(i==4){
                 if(j!=2)
                    mat[i][j] = 1;
                else
                    mat[i][j] = 0;
            }
            
            //5 - são pedro
            else if(i==5){
                if(j==4 || j==0)
                    mat[i][j] = 1;
                else
                    mat[i][j] = 0;
            }
            
            //6 - formigueiro
            else{
                if(j==4)
                    mat[i][j] = 1;
                else
                    mat[i][j] = 0;
            }
        }
        
    }
    
    
    for(int i=0;i<TOTAL_CIDADES;i++){
        for(int j=0;j<TOTAL_CIDADES;j++){
            printf("%d\t",mat[i][j]);
        }
        printf("\n");
    }

    
    while(fim!=1){
        printf("\n\n0 - são martinho da serra\n1 - itaara\n2 - ivorá\n3 - silveira martins\n4 - santa maria\n5 - são pedro\n6 - formigueiro\n");
        scanf("%d",&i);
        
        //0-são martinho da serra
        if(i==0){
            check(mat,"são martinho da serra",i);
        }
        
        //1- itaara
        else if(i==1){
            check(mat,"itaara",i);
        }
            
        //2 - ivorá
        else if(i==2){
            check(mat,"ivorá",i);
        }
            
        //3 - silveira martins
        else if(i==3){
            check(mat,"silveira martins",i);
        }
            
        //4 - santa maria
        else if(i==4){
            check(mat,"santa maria",i);
        }
            
        //5 - são pedro
        else if(i==5){
            check(mat,"são pedro",i);
        }
            
        //6 - formigueiro
        else{
            check(mat,"formigueiro",i);
        }
        
        printf("1 pra encerrar: ");
        scanf("%d",&fim);
    }
    
    return 0;
}
