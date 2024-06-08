//mergesort

#include <stdio.h>
#include <stdlib.h>

void intercala(int v[11], int inicio, int meio, int fim)
{
    int i, j, k, aux[11];
    i = inicio;
    j = meio+1;
    k = 0; // variavel pra controlar o indice pra inserir dentro de aux[]
    while(i <= meio && j <= fim)
    {
        if(v[i] <= v[j])
        {
            aux[k] = v[i];
            i++;
        }
        else
        {
            aux[k] = v[j];
            j++;
        }
    k++;
    }

    while(i <= meio)
    {
        aux[k] = v[i];
        i++;
        k++;
    }
    
    while(j<=fim)
    {
        aux[k] = v[j];
        j++;
        k++;
    }
    
    for(i = 0; i< (fim - inicio)+1; i++) //copia valores do vetor auxiliar para o original
    {
        v[inicio + i] = aux[i];
    }
}

void mergesort(int v[11],int inicio,int fim) // para dividir os elementos em subvetores
{
    int meio;
    if (inicio < fim)
    {
        meio = (inicio + fim)/2 ;
        mergesort(v,inicio,meio);
        mergesort(v,meio+1,fim);
        intercala(v, inicio, meio, fim);
    }
}

void imprime (int v[11])
{
    int i;
    for(i = 0; i < 11; i++)
    {
        printf(" %d ", v[i]);
    }
    printf("\n");
}

int main()
{
    int i;
    int aMerge[11] = {20, 31, 14, 8 , 92, 17, 11, 1, 0, 5, 4};
    printf("Nao ordenado: \t");
    imprime(aMerge);
    mergesort(aMerge, 0, 10);
    printf("Ordenado: \t");
    imprime(aMerge);
    printf("\n");
    return 0;
}


/*
iteracoes:

comeca chamando funcao mergesort() passando o vetor e a 1a e ultima posicao

1a execucao mergesort():
	int meio;
    if (inicio < fim) true (0 < 10){
        meio = (0 + 10)/2; // meio = 5
        
        //inicia 2a execucao mergesort()
        mergesort(v,0,5);
        
        //depois que a 2a execucao terminou:
        
        //inicia 13a execucao mergesort()
        mergesort(v, meio+1, fim); 
        //mergesort(v, 6, 10);
        
        //depois que a 13a execucao terminou:
        //inicia 10a execucao funcao intercala()
        intercala(v, inicio, meio, fim);
        //intercala(v, 0, 5, 10);
        
        //depois que 10a execucao de intercala acabou, volta 
        //encerra 1a execucao e retorna o vetor ordenado pra main()
    }


        
2a execucao mergesort(): inicio=0, fim=5
	int meio;
    if (inicio < fim) true (0 < 5){
        meio = (0 + 5)/2; // meio = 2
        
        //inicia 3a execucao mergesort()
        mergesort(v,0,2);
        
        //depois que a 3a execucao terminou:
        
        //inicia 8a execucao mergesort()
        mergesort(v, meio+1, fim); 
        //mergesort(v, 3, 5);
       
       
        //depois que a 8a execucao terminou:
        //inicia 5a execucao funcao intercala()
        intercala(v, inicio, meio, fim);
        //intercala(v, 0, 2, 5);
        
        //depois que 5a execucao de intercala acabou, volta 
        //encerra 2a execucao e volta pra 1a execucao
    }

  
    
    
    
3a execucao mergesort(): inicio=0, fim=2
	int meio;
    if (inicio < fim) true (0 < 2){
        meio = (0 + 2)/2; // meio = 1
        
        //inicia 4a execucao mergesort()
        mergesort(v,0,1);
        
        
        //depois que a 4a execucao terminou:
        
        //inicia 7a execucao mergesort()
        mergesort(v, meio+1, fim); 
        //mergesort(v, 2, 2);
        
        
        //depois que a 7a execucao terminou:
        //inicia 2a execucao funcao intercala()
        intercala(v, inicio, meio, fim);
        //intercala(v, 0, 1, 2);
        
        //depois que 2a execucao de intercala acabou, volta 
        //encerra 3a execucao e volta pra 2a execucao
    }

   
    
    
    
4a execucao mergesort(): inicio=0, fim=1
	int meio;
    if (inicio < fim) true (0 < 1){
        meio = (0 + 1)/2; // meio = 0
        
        //inicia 5a execucao mergesort()
        mergesort(v,0,0);
        
        //depois que a 5a execucao terminou:
        
        
        //inicia 6a execucao
        mergesort(v, meio+1, fim); 
        //mergesort(v, 1, 1);
        
        
        //depois que a 6a execucao terminou:
        //inicia 1a execucao funcao intercala()
        intercala(v, inicio, meio, fim);
        //intercala(v, 0, 0, 1);
        
        
        //depois que 1a execucao de intercala acabou, volta 
        //encerra 4a execucao e volta pra 3a execucao
    }


    
    
    
5a execucao mergesort(): inicio=0, fim=0
	int meio;
    if (0 < 0) false 
    // volta pra 4a execucao

    
6a execucao mergesort(): inicio=1, fim=1
	int meio;
    if (1 < 1) false 
    // volta pra 4a execucao
    
    
7a execucao mergesort(): inicio=2, fim=2
	int meio;
    if (inicio < fim) false (2 < 2){
    // volta pra 3a execucao
      
    
    
 8a execucao mergesort(): inicio=3, fim=5
	int meio;
    if (inicio < fim) true (3 < 5){
        meio = (3 + 5)/2; // meio = 4
        
        //inicia 9a execucao mergesort()
        mergesort(v,3,4);
        
		//depois que a 9a execucao terminou:
        
        //inicia 12a execucao mergesort()
        mergesort(v, meio+1, fim); 
        //mergesort(v, 5, 5);
        
        //depois que a 12a execucao terminou:
        //inicia 4a execucao funcao intercala()
        intercala(v, inicio, meio, fim);
        //intercala(v, 3, 4, 5);
    	
    	//depois que 4a execucao de intercala acabou, volta 
        //encerra 8a execucao e volta pra 2a execucao
    }
  
     
    
 9a execucao mergesort(): inicio=3, fim=4
	int meio;
    if (inicio < fim) true (3 < 4){
    meio = (3 + 4)/2; // meio = 3
        
        //inicia 10a execucao mergesort()
        mergesort(v,3,3);
    	
        //depois que a 10a execucao terminou:
        
        //inicia 11a execucao mergesort()
        mergesort(v, meio+1, fim); 
        //mergesort(v, 4, 4);
    	
    	
    	//depois que a 11a execucao terminou:
        //inicia 3a execucao funcao intercala()
        intercala(v, inicio, meio, fim);
        //intercala(v, 3, 3, 4);
    	
        //depois que 3a execucao de intercala acabou, volta 
        //encerra 9a execucao e volta pra 8a execucao
    }
      
    
 
10a execucao mergesort(): inicio=3, fim=3
	int meio;
    if (inicio < fim) false (3 < 3){
    // volta pra 9a execucao  
    
    	
  
11a execucao mergesort(): inicio=4, fim=4
	int meio;
    if (inicio < fim) false (4 < 4){
    // volta pra 9a execucao  
    	
  
    	  	
12a execucao mergesort(): inicio=5, fim=5
	int meio;
    if (inicio < fim) false (5 < 5){
    // volta pra 8a execucao   	
    	
    	
13a execucao mergesort(): inicio=6, fim=10
	int meio;
    if (inicio < fim) true (6 < 10){
    	meio = (6 + 10)/2; // meio = 8
   
    	 //inicia 14a execucao mergesort()
    	mergesort(v,6,8);
    	
    	//depois que a 14a execucao terminou:
        
        //inicia 19a execucao mergesort()
        mergesort(v, meio+1, fim); 
        //mergesort(v, 9, 10); 
    	
    	//depois que a 19a execucao terminou:
        //inicia 9a execucao funcao intercala()
        intercala(v, inicio, meio, fim);
        //intercala(v, 6, 8, 10);
    	
    	//depois que 9a execucao de intercala acabou, volta 
        //encerra 13a execucao e volta pra 1a execucao	
  
   
    	 	   
14a execucao mergesort(): inicio=6, fim=8
	int meio;
    if (inicio < fim) true (6 < 8){
    	meio = (6 + 8)/2; // meio = 7
   
    	//inicia 15a execucao mergesort()
    	mergesort(v,6,7);
    	
    	//depois que a 15a execucao terminou:
        
        //inicia 18a execucao mergesort()
        mergesort(v, meio+1, fim); 
        //mergesort(v, 8, 8); 
    	
    	//depois que a 18a execucao terminou:
        //inicia 7a execucao funcao intercala()
        intercala(v, inicio, meio, fim);
        //intercala(v, 6, 7, 8);
    	
    	//depois que 7a execucao de intercala acabou, volta 
        //encerra 14a execucao e volta pra 13a execucao	
  
    	  	       	
15a execucao mergesort(): inicio=6, fim=7
	int meio;
    if (inicio < fim) true (6 < 7){
    	meio = (6 + 7)/2; // meio = 6
   
    	//inicia 16a execucao mergesort()
    	mergesort(v,6,6); 
    	
    	//depois que a 16a execucao terminou:
        
        //inicia 17a execucao mergesort()
        mergesort(v, meio+1, fim); 
        //mergesort(v, 7, 7); 	
    	
    	//depois que a 17a execucao terminou:
        //inicia 6a execucao funcao intercala()
        intercala(v, inicio, meio, fim);
        //intercala(v, 6, 6, 7);
    	
    	//depois que 6a execucao de intercala acabou, volta 
        //encerra 15a execucao e volta pra 14a execucao
   
    	 		
16a execucao mergesort(): inicio=6, fim=6
	int meio;
    if (inicio < fim) false (6 < 6){
    // volta pra 15a execucao   	
    	  	
    	
17a execucao mergesort(): inicio=7, fim=7
	int meio;
    if (inicio < fim) false (7 < 7){
    // volta pra 15a execucao   	
    	    	
    	
18a execucao mergesort(): inicio=8, fim=8
	int meio;
    if (inicio < fim) false (8 < 8){
    // volta pra 14a execucao  
 
    	   	
19a execucao mergesort(): inicio=9, fim=10
	int meio;
    if (inicio < fim) true (9 < 10){
    	meio = (9 + 10)/2; // meio = 9
   
    	//inicia 20a execucao mergesort()
    	mergesort(v,9,9);
    	
    	//depois que a 20a execucao terminou:
        
        //inicia 21a execucao mergesort()
        mergesort(v, meio+1, fim); 
        //mergesort(v, 10, 10); 
    	
    	//depois que a 21a execucao terminou:
        //inicia 8a execucao funcao intercala()
        intercala(v, inicio, meio, fim);
        //intercala(v, 9, 9, 10);
    	
    	//depois que 8a execucao de intercala acabou, volta 
        //encerra 19a execucao e volta pra 13a execucao	    	
    	
   
 20a execucao mergesort(): inicio=9, fim=9
	int meio;
    if (inicio < fim) false (9 < 9){
    // volta pra 19a execucao    	
 
    	   	 	
21a execucao mergesort(): inicio=10, fim=10
	int meio;
    if (inicio < fim) false (10 < 10){
    // volta pra 19a execucao    	
    	 	    	   	    	
--------------------------------------------------------
    
    
    
    
    
    
    
    
 
1a execucao funcao intercala(): inicio: 0, meio: 0, fim: 1
void intercala(int v[11], int inicio, int meio, int fim)
{
	
    int i, j, k, aux[11]; // aux eh um vetor auxiliar
    
    i = inicio; // i=0
    j = meio+1; // j=0+1, j=1
    k = 0;
    
    
    
    1a execucao while:
    //while(0 <= 0 && 1 <= 1)
    
    2a execucao while:
    //while(1 <= 0 && 1 <= 1) false, sai do loop
    
    while(i <= meio && j <= fim)
    {
        if(v[i] <= v[j]) //v[0] <= v[1], 20 <= 31 true
        {
            aux[k] = v[i]; //aux[0] = v[0], aux[0]=20
            i++; //i=1
        }
        else
        {
            aux[k] = v[j];
            j++;
        }
    	k++; //k=1
    }

    
    1a execucao while:
    //while(1 <= 0) false
    while(i <= meio)
    {
        aux[k] = v[i];
        i++;
        k++;
    }
    
    
    1a execucao while:
    //while(1 <= 1) true
    
    2a execucao while:
    //while(2 <= 1) false, sai fora
    while(j<=fim)
    {
        aux[k] = v[j]; //aux[1] = v[1], aux[1]=31
        j++; //j=2
        k++; //k=2
    }
    
    
    
    
    vetor aux[] esta assim: {20,31}
    
    
    
    
    for(i = 0; i< (fim - inicio)+1; i++) //copia valores do vetor auxiliar para o original
    {
        v[inicio + i] = aux[i];
    }
    
    1a execucao for:
    for(i = 0; i< (1 - 0)+1; i++)
    {
        v[0] = aux[0]; // v[0] = 20
    }
    
    2a execucao for:
    for(i = 1; i< (1 - 0)+1; i++)
    {
        v[1] = aux[1]; // v[1] = 31
    }
    
    3a execucao i=2 sai do loop
    ao final as 2 primeiras posicoes estao ordenadas 20,31
} 
    
   
   
   
   
   
   
   
   
   
   
    
    
   
   
   
2a execucao funcao intercala(): inicio: 0, meio: 1, fim: 2
void intercala(int v[11], int inicio, int meio, int fim){
	
    int i, j, k, aux[11]; // aux eh um vetor auxiliar
    
    i = inicio; // i=0
    j = meio+1; // j=1+1, j=2
    k = 0;
    
    
    while(i <= meio && j <= fim)
    {
        if(v[i] <= v[j]){
            aux[k] = v[i];
            i++;
        }
        else
        {
            aux[k] = v[j];
            j++;
        }
    	k++;
    }
    
    
    1a execucao while:
    //while(0 <= 1 && 2 <= 2) true
    
    while(i <= meio && j <= fim)
    {
        if(v[i] <= v[j]) //v[0] <= v[2], 20 <= 14 false, entra no else
        {
            aux[k] = v[i];
            i++;
        }
        else
        {
            aux[k] = v[j]; //aux[0] = v[2], aux[0]=14
            j++; //j=3
        }
    	k++; //k=1
    }
    
    2a execucao while:
    //while(0 <= 1 && 3 <= 2) false, sai do loop
    
    

    

    
    while(i <= meio)
    {
        aux[k] = v[i];
        i++;
        k++;
    }
    
    1a execucao while:
    //while(0 <= 1) true
    while(i <= meio)
    {
        aux[k] = v[i]; // aux[1]=v[0], aux[1]=20
        i++; //i=1
        k++; //k=2
    }
    
    2a execucao while:
    //while(1 <= 1) true
    while(i <= meio)
    {
        aux[k] = v[i]; // aux[2]=v[1], aux[2]=31
        i++; //i=2
        k++; //k=3
    }
    
    3a execucao while:
    //while(2 <= 1) false, sai fora
    
    
    
    
    
    
    
    
    
    while(j<=fim)
    {
        aux[k] = v[j];
        j++;
        k++;
    }
    
    1a execucao while:
    //while(3 <= 2) false, sai fora
    
    
    
    
    vetor aux[] esta assim: {14,20,31}
    
    
    
    
    for(i = 0; i< (fim - inicio)+1; i++) //copia valores do vetor auxiliar para o original
    {
        v[inicio + i] = aux[i];
    }
    
    1a execucao for:
    for(i = 0; i< (2 - 0)+1; i++)
    {
        v[0] = aux[0]; // v[0] = 14
    }
    
    2a execucao for:
    for(i = 1; i< (2 - 0)+1; i++)
    {
        v[1] = aux[1]; // v[1] = 20
    }
    
    3a execucao for:
    for(i = 2; i< (2 - 0)+1; i++)
    {
        v[2] = aux[2]; // v[2] = 31
    }
    
    4a execucao i=3 sai do loop
    ao final as 3 primeiras posicoes estao ordenadas 14,20,31
} 
     
   
   
   
   
   
   
   
   
   
   
   
   
    
    
    
3a execucao funcao intercala(): inicio: 3, meio: 3, fim: 4
void intercala(int v[11], int inicio, int meio, int fim){
	
    int i, j, k, aux[11]; // aux eh um vetor auxiliar
    
    i = inicio; // i=3
    j = meio+1; // j=3+1, j=4
    k = 0;
    
    
    while(i <= meio && j <= fim)
    {
        if(v[i] <= v[j]){
            aux[k] = v[i];
            i++;
        }
        else
        {
            aux[k] = v[j];
            j++;
        }
    	k++;
    }
    
    
    1a execucao while:
    //while(3 <= 3 && 4 <= 4) true
    
    while(i <= meio && j <= fim)
    {
        if(v[i] <= v[j]) //v[3] <= v[4], 8 <= 92 true
        {
            aux[k] = v[i]; //aux[0] = v[3], aux[0] = 8
            i++; //i=4
        }
        else
        {
            aux[k] = v[j];
            j++;
        }
    	k++; //k=1
    }
    
    2a execucao while:
    //while(4 <= 3 && 4 <= 4) false, sai do loop
    
    

    

    
    while(i <= meio)
    {
        aux[k] = v[i];
        i++;
        k++;
    }
    
    1a execucao while:
    //while(4 <= 3) false, sai fora
    
    
    
    
    
    
    
    
    
    while(j<=fim)
    {
        aux[k] = v[j];
        j++;
        k++;
    }
    
    1a execucao while:
    //while(4 <= 4) true
    while(j<=fim)
    {
        aux[k] = v[j]; //aux[1]=v[4], aux[1]=92
        j++; //j=5
        k++; //k=2
    }
    
    2a execucao while:
    //while(5 <= 4) false
   
    
    
    
    
    vetor aux[] esta assim: {8,92}
    
    
    
    
    
    for(i = 0; i< (fim - inicio)+1; i++) //copia valores do vetor auxiliar para o original
    {
        v[inicio + i] = aux[i];
    }
    
    1a execucao for:
    for(i = 0; i< (4 - 3)+1; i++)
    {
        v[3] = aux[0]; // v[3] = 8
    }
    
    2a execucao for:
    for(i = 1; i< (4 - 3)+1; i++)
    {
        v[4] = aux[1]; // v[4] = 92
    }
    
    
    3a execucao i=3 sai do loop
    ao final o vetor esta assim 14,20,31,8,92,17,11,1,0,5,4
} 
   
    
    
 
 
 
 
 
 
 
 
 
 
 
 
 
4a execucao funcao intercala(): inicio: 3, meio: 4, fim: 5
void intercala(int v[11], int inicio, int meio, int fim){
	
    int i, j, k, aux[11]; // aux eh um vetor auxiliar
    
    i = inicio; // i=3
    j = meio+1; // j=4+1, j=5
    k = 0;
    
    
    while(i <= meio && j <= fim)
    {
        if(v[i] <= v[j]){
            aux[k] = v[i];
            i++;
        }
        else
        {
            aux[k] = v[j];
            j++;
        }
    	k++;
    }
    
    
    1a execucao while:
    //while(3 <= 4 && 5 <= 5) true
    
    while(i <= meio && j <= fim)
    {
        if(v[i] <= v[j]) //v[3] <= v[5], 8 <= 17 true
        {
            aux[k] = v[i]; //aux[0] = v[3], aux[0] = 8
            i++; //i=4
        }
        else
        {
            aux[k] = v[j];
            j++;
        }
    	k++; //k=1
    }
    
    2a execucao while:
    //while(4 <= 4 && 5 <= 5) true
    while(i <= meio && j <= fim)
    {
        if(v[i] <= v[j]) //v[4] <= v[5], 92 <= 17 false, entra no else
        {
            aux[k] = v[i];
            i++;
        }
        else
        {
            aux[k] = v[j]; aux[1]=v[5], aux[1]=17
            j++; //j=6
        }
    	k++; //k=2
    }
    
    3a execucao while:
    //while(4 <= 4 && 6 <= 5) false

    

    
    
    
    
    
    while(i <= meio)
    {
        aux[k] = v[i];
        i++;
        k++;
    }
    
    1a execucao while:
    //while(4 <= 4) true
    while(i <= meio)
    {
        aux[k] = v[i]; //aux[2]=v[4], aux[2]=92
        i++; //i=5
        k++; //k=3
    }
    
    2a execucao while:
    //while(5 <= 4) false
    
    
    
    
    
    
    
    while(j<=fim)
    {
        aux[k] = v[j];
        j++;
        k++;
    }
    
    1a execucao while:
    //while(6 <= 5) false
   
    
    
    
    vetor aux[] esta assim: {8,17,92}
    
    
    
    
    
    for(i = 0; i< (fim - inicio)+1; i++) //copia valores do vetor auxiliar para o original
    {
        v[inicio + i] = aux[i];
    }
    
    1a execucao for:
    for(i = 0; i< (5 - 3)+1; i++)
    {
        v[3] = aux[0]; // v[3] = 8
    }
    
    2a execucao for:
    for(i = 1; i< (5 - 3)+1; i++)
    {
        v[4] = aux[1]; // v[4] = 17
    }
    
    3a execucao for:
    for(i = 2; i< (5 - 3)+1; i++)
    {
        v[5] = aux[2]; // v[5] = 92
    }
    
    4a execucao i=3 sai do loop
    ao final o vetor esta assim 14,20,31,8,17,92,11,1,0,5,4
} 
   
   
   
  
  
  
  
  
  
  
  
  
  
  
  
 
 
  
  
  
5a execucao funcao intercala(): inicio: 0, meio: 2, fim: 5
void intercala(int v[11], int inicio, int meio, int fim){
	
    int i, j, k, aux[11]; // aux eh um vetor auxiliar
    
    i = inicio; // i=0
    j = meio+1; // j=2+1, j=3
    k = 0;
    
    
    while(i <= meio && j <= fim)
    {
        if(v[i] <= v[j]){
            aux[k] = v[i];
            i++;
        }
        else
        {
            aux[k] = v[j];
            j++;
        }
    	k++;
    }
    
    
    1a execucao while:
    //while(0 <= 2 && 3 <= 5) true
    
    while(i <= meio && j <= fim)
    {
        if(v[i] <= v[j]) //v[0] <= v[3], 14 <= 8 false
        {
            aux[k] = v[i];
            i++;
        }
        else
        {
            aux[k] = v[j]; //aux[0] = v[3], aux[0]=8
            j++; //j=4
        }
    	k++; //k=1
    }
    
    2a execucao while:
    //while(0 <= 2 && 4 <= 5) true
    while(i <= meio && j <= fim)
    {
        if(v[i] <= v[j]) //v[0] <= v[4], 14 <= 17 true
        {
            aux[k] = v[i]; //aux[1]=v[0], aux[1]=14
            i++; //i=1
        }
        else
        {
            aux[k] = v[j];
            j++;
        }
    	k++; //k=2
    }
    
    3a execucao while:
    //while(1 <= 2 && 4 <= 5) true
	while(i <= meio && j <= fim)
    {
        if(v[i] <= v[j]) //v[1] <= v[4], 20 <= 17 false
        {
            aux[k] = v[i];
            i++;
        }
        else
        {
            aux[k] = v[j]; //aux[2] = v[4], aux[2]=17
            j++; //j=5
        }
    	k++; //k=3
    }
    
	4a execucao while:
    //while(1 <= 2 && 5 <= 5) true
    while(i <= meio && j <= fim)
    {
        if(v[i] <= v[j]) //v[1] <= v[5], 20 <= 92 true
        {
            aux[k] = v[i]; //aux[3]=v[1], aux[3]=20
            i++; //i=2
        }
        else
        {
            aux[k] = v[j];
            j++;
        }
    	k++; //k=4
    }
    
    5a execucao while:
    //while(2 <= 2 && 5 <= 5) true
    while(i <= meio && j <= fim)
    {
        if(v[i] <= v[j]) //v[2] <= v[5], 31 <= 92 true
        {
            aux[k] = v[i]; //aux[4]=v[2], aux[4]=31
            i++; //i=3
        }
        else
        {
            aux[k] = v[j];
            j++;
        }
    	k++; //k=5
    }
    
    6a execucao while:
    //while(3 <= 2 && 5 <= 5) false
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    while(i <= meio)
    {
        aux[k] = v[i];
        i++;
        k++;
    }
    
    1a execucao while:
    //while(3 <= 2) false
    

    
    
    
    
    
    
    
    
    while(j<=fim)
    {
        aux[k] = v[j];
        j++;
        k++;
    }
    
    1a execucao while:
    //while(5 <= 5) true
    while(j<=fim)
    {
        aux[k] = v[j]; //aux[5]=v[5], aux[5]=92
        j++; //j=6
        k++; //k=6
    }
    
    2a execucao while:
    //while(6 <= 5) false
    
    
    
    
    vetor aux[] esta assim: {8,14,17,20,31,92}
    
    
    
    
    
    for(i = 0; i< (fim - inicio)+1; i++) //copia valores do vetor auxiliar para o original
    {
        v[inicio + i] = aux[i];
    }
    
    1a execucao for:
    for(i = 0; i< (5 - 0)+1; i++)
    {
        v[0] = aux[0]; // v[0] = 8
    }
    
    2a execucao for:
    for(i = 1; i< (5 - 0)+1; i++)
    {
        v[1] = aux[1]; // v[1] = 14
    }
    
    3a execucao for:
    for(i = 2; i< (5 - 0)+1; i++)
    {
        v[2] = aux[2]; // v[2] = 17
    }
    
    4a execucao for:
    for(i = 3; i< (5 - 0)+1; i++)
    {
        v[3] = aux[3]; // v[2] = 20
    }
    
    5a execucao for:
    for(i = 4; i< (5 - 0)+1; i++)
    {
        v[4] = aux[4]; // v[4] = 31
    }
    
    6a execucao for:
    for(i = 5; i< (5 - 0)+1; i++)
    {
        v[5] = aux[5]; // v[5] = 92
    }
    
    7a execucao i=6 sai do loop
    ao final o vetor esta assim 8,14,17,20,31,92,11,1,0,5,4
} 
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
  
  
   
   
   
6a execucao funcao intercala(): inicio: 6, meio: 6, fim: 7
void intercala(int v[11], int inicio, int meio, int fim){
	
    int i, j, k, aux[11]; // aux eh um vetor auxiliar
    
    i = inicio; // i=6
    j = meio+1; // j=6+1, j=7
    k = 0;
    
    
    while(i <= meio && j <= fim)
    {
        if(v[i] <= v[j]){
            aux[k] = v[i];
            i++;
        }
        else
        {
            aux[k] = v[j];
            j++;
        }
    	k++;
    }
    
    
    1a execucao while:
    //while(6 <= 6 && 7 <= 7) true
    
    while(i <= meio && j <= fim)
    {
        if(v[i] <= v[j]) //v[6] <= v[7], 11 <= 1 false
        {
            aux[k] = v[i];
            i++;
        }
        else
        {
            aux[k] = v[j]; //aux[0] = v[7], aux[0]=1
            j++; //j=8
        }
    	k++; //k=1
    }
    
    2a execucao while:
    //while(6 <= 6 && 8 <= 7) false
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    while(i <= meio)
    {
        aux[k] = v[i];
        i++;
        k++;
    }
    
    1a execucao while:
    //while(6 <= 6) true
    while(i <= meio) {
        aux[k] = v[i]; //aux[1]=v[6], aux[1]=11
        i++; //i=7
        k++; //k=2
    }

    2a execucao while:
    //while(7 <= 6) false
    
    
    
    
    
    
    
    
    
    while(j<=fim)
    {
        aux[k] = v[j];
        j++;
        k++;
    }
    
    1a execucao while:
    //while(8 <= 7) false
    
    
    
    
    vetor aux[] esta assim: {1,11}
    
    
    
    
    
    for(i = 0; i< (fim - inicio)+1; i++) //copia valores do vetor auxiliar para o original
    {
        v[inicio + i] = aux[i];
    }
    
    1a execucao for:
    for(i = 0; i< (7 - 6)+1; i++)
    {
        v[6] = aux[0]; // v[6] = 1
    }
    
    2a execucao for:
    for(i = 1; i< (7 - 6)+1; i++)
    {
        v[7] = aux[1]; // v[7] = 11
    }
    
    3a execucao i=2 sai do loop
    ao final o vetor esta assim 8,14,17,20,31,92,1,11,0,5,4
} 















7a execucao funcao intercala(): inicio: 6, meio: 7, fim: 8
void intercala(int v[11], int inicio, int meio, int fim){
	
    int i, j, k, aux[11]; // aux eh um vetor auxiliar
    
    i = inicio; // i=6
    j = meio+1; // j=7+1, j=8
    k = 0;
    
    
    while(i <= meio && j <= fim)
    {
        if(v[i] <= v[j]){
            aux[k] = v[i];
            i++;
        }
        else
        {
            aux[k] = v[j];
            j++;
        }
    	k++;
    }
    
    
    1a execucao while:
    //while(6 <= 7 && 8 <= 8) true
    
    while(i <= meio && j <= fim)
    {
        if(v[i] <= v[j]) //v[6] <= v[8], 1 <= 0 false
        {
            aux[k] = v[i];
            i++;
        }
        else
        {
            aux[k] = v[j]; //aux[0] = v[8], aux[0]=0
            j++; //j=9
        }
    	k++; //k=1
    }
    
    2a execucao while:
    //while(6 <= 7 && 9 <= 8) false
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    while(i <= meio)
    {
        aux[k] = v[i];
        i++;
        k++;
    }
    
    1a execucao while:
    //while(6 <= 7) true
    while(i <= meio) {
        aux[k] = v[i]; //aux[1]=v[6], aux[1]=1
        i++; //i=7
        k++; //k=2
    }

    2a execucao while:
    //while(7 <= 7) true
    while(i <= meio) {
        aux[k] = v[i]; //aux[2]=v[7], aux[2]=11
        i++; //i=8
        k++; //k=3
    }
    
    3a execucao while:
    //while(8 <= 7) false
    
    
    
    
    
    
    
    
    
    
    while(j<=fim)
    {
        aux[k] = v[j];
        j++;
        k++;
    }
    
    1a execucao while:
    //while(9 <= 8) false
    
    
    
    
    vetor aux[] esta assim: {0,1,11}
    
    
    
    
    
    for(i = 0; i< (fim - inicio)+1; i++) //copia valores do vetor auxiliar para o original
    {
        v[inicio + i] = aux[i];
    }
    
    1a execucao for:
    for(i = 0; i< (8 - 6)+1; i++)
    {
        v[6] = aux[0]; // v[6] = 0
    }
    
    2a execucao for:
    for(i = 1; i< (8 - 6)+1; i++)
    {
        v[7] = aux[1]; // v[7] = 1
    }
    
    3a execucao for:
    for(i = 2; i< (8 - 6)+1; i++)
    {
        v[8] = aux[2]; // v[8] = 11
    }
    
    4a execucao i=3 sai do loop
    ao final o vetor esta assim 8,14,17,20,31,92,0,1,11,5,4
} 


  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
8a execucao funcao intercala(): inicio: 9, meio: 9, fim: 10
void intercala(int v[11], int inicio, int meio, int fim){
	
    int i, j, k, aux[11]; // aux eh um vetor auxiliar
    
    i = inicio; // i=9
    j = meio+1; // j=9+1, j=10
    k = 0;
    
    
    while(i <= meio && j <= fim)
    {
        if(v[i] <= v[j]){
            aux[k] = v[i];
            i++;
        }
        else
        {
            aux[k] = v[j];
            j++;
        }
    	k++;
    }
    
    
    1a execucao while:
    //while(9 <= 9 && 10 <= 10) true
    
    while(i <= meio && j <= fim)
    {
        if(v[i] <= v[j]) //v[9] <= v[10], 5 <= 4 false
        {
            aux[k] = v[i];
            i++;
        }
        else
        {
            aux[k] = v[j]; //aux[0] = v[10], aux[0]=4
            j++; //j=11
        }
    	k++; //k=1
    }
    
    2a execucao while:
    //while(9 <= 9 && 11 <= 10) false
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    while(i <= meio)
    {
        aux[k] = v[i];
        i++;
        k++;
    }
    
    1a execucao while:
    //while(9 <= 9) true
    while(i <= meio) {
        aux[k] = v[i]; //aux[1]=v[9], aux[1]=5
        i++; //i=10
        k++; //k=2
    }

    2a execucao while:
    //while(10 <= 9) false
    
    
    
    
    
    
    
    
    
    
    while(j<=fim)
    {
        aux[k] = v[j];
        j++;
        k++;
    }
    
    1a execucao while:
    //while(11 <= 10) false
    
    
    
    
    vetor aux[] esta assim: {4,5}
    
    
    
    
    
    for(i = 0; i< (fim - inicio)+1; i++) //copia valores do vetor auxiliar para o original
    {
        v[inicio + i] = aux[i];
    }
    
    1a execucao for:
    for(i = 0; i< (10 - 9)+1; i++)
    {
        v[9] = aux[0]; // v[9] = 4
    }
    
    2a execucao for:
    for(i = 1; i< (10 - 9)+1; i++)
    {
        v[10] = aux[1]; // v[10] = 5
    }
    
    3a execucao i=2 sai do loop
    ao final o vetor esta assim 8,14,17,20,31,92,0,1,11,4,5
} 

















9a execucao funcao intercala(): inicio: 6, meio: 8, fim: 10
void intercala(int v[11], int inicio, int meio, int fim){
	
    int i, j, k, aux[11]; // aux eh um vetor auxiliar
    
    i = inicio; // i=6
    j = meio+1; // j=8+1, j=9
    k = 0;
    
    
    while(i <= meio && j <= fim)
    {
        if(v[i] <= v[j]){
            aux[k] = v[i];
            i++;
        }
        else
        {
            aux[k] = v[j];
            j++;
        }
    	k++;
    }
    
    
    1a execucao while:
    //while(6 <= 8 && 9 <= 10) true
    
    while(i <= meio && j <= fim)
    {
        if(v[i] <= v[j]) //v[6] <= v[9], 0 <= 4 true
        {
            aux[k] = v[i]; //aux[0]=v[6], aux[0]=0
            i++; //i=7
        }
        else
        {
            aux[k] = v[j];
            j++;
        }
    	k++; //k=1
    }
    
    2a execucao while:
    //while(7 <= 8 && 9 <= 10) true
    while(i <= meio && j <= fim)
    {
        if(v[i] <= v[j]) //v[7] <= v[9], 1 <= 4 true
        {
            aux[k] = v[i]; //aux[1]=v[7], aux[1]=1
            i++; //i=8
        }
        else
        {
            aux[k] = v[j];
            j++;
        }
    	k++; //k=2
    }
    
    3a execucao while:
    //while(8 <= 8 && 9 <= 10) true
    while(i <= meio && j <= fim)
    {
        if(v[i] <= v[j]) //v[8] <= v[9], 11 <= 4 false
        {
            aux[k] = v[i];
            i++;
        }
        else
        {
            aux[k] = v[j]; //aux[2]=v[9], aux[2]=4
            j++; //j=10
        }
    	k++; //k=3
    }
    
    4a execucao while:
    //while(8 <= 8 && 10 <= 10) true
    while(i <= meio && j <= fim)
    {
        if(v[i] <= v[j]) //v[8] <= v[10], 11 <= 5 false
        {
            aux[k] = v[i];
            i++;
        }
        else
        {
            aux[k] = v[j]; //aux[3]=v[10], aux[3]=5
            j++; //j=11
        }
    	k++; //k=4
    }
    
    5a execucao while:
    //while(8 <= 8 && 11 <= 10) false
    
    
    
    
    
    
    
    
    
    
    
    while(i <= meio)
    {
        aux[k] = v[i];
        i++;
        k++;
    }
    
    1a execucao while:
    //while(8 <= 8) true
    while(i <= meio) {
        aux[k] = v[i]; //aux[4]=v[8], aux[4]=11
        i++; //i=9
        k++; //k=5
    }

    2a execucao while:
    //while(9 <= 8) false
    
    
    
    
    
    
    
    
    
    
    while(j<=fim)
    {
        aux[k] = v[j];
        j++;
        k++;
    }
    
    1a execucao while:
    //while(11 <= 10) false
    
    
    
    
    vetor aux[] esta assim: {0,1,4,5,11}
    
    
    
    
    
    for(i = 0; i< (fim - inicio)+1; i++) //copia valores do vetor auxiliar para o original
    {
        v[inicio + i] = aux[i];
    }
    
    1a execucao for:
    for(i = 0; i< (10 - 6)+1; i++)
    {
        v[6] = aux[0]; // v[6] = 0
    }
    
    2a execucao for:
    for(i = 1; i< (10 - 6)+1; i++)
    {
        v[7] = aux[1]; // v[7] = 1
    }
    
    3a execucao for:
    for(i = 2; i< (10 - 6)+1; i++)
    {
        v[8] = aux[2]; // v[8] = 4
    }
    
    4a execucao for:
    for(i = 3; i< (10 - 6)+1; i++)
    {
        v[9] = aux[3]; // v[9] = 5
    }
    
    5a execucao for:
    for(i = 4; i< (10 - 6)+1; i++)
    {
        v[10] = aux[4]; // v[10] = 11
    }
    
    
    6a execucao i=5 sai do loop
    ao final o vetor esta assim 8,14,17,20,31,92,0,1,4,5,11
} 


















10a execucao funcao intercala(): inicio: 0, meio: 5, fim: 10
void intercala(int v[11], int inicio, int meio, int fim){
	
    int i, j, k, aux[11]; // aux eh um vetor auxiliar
    
    i = inicio; // i=0
    j = meio+1; // j=5+1, j=6
    k = 0;
    
    
    while(i <= meio && j <= fim)
    {
        if(v[i] <= v[j]){
            aux[k] = v[i];
            i++;
        }
        else
        {
            aux[k] = v[j];
            j++;
        }
    	k++;
    }
    
    
    1a execucao while:
    //while(0 <= 5 && 6 <= 10) true
    
    while(i <= meio && j <= fim)
    {
        if(v[i] <= v[j]) //v[0] <= v[6], 8 <= 0 false
        {
            aux[k] = v[i];
            i++;
        }
        else
        {
            aux[k] = v[j]; //aux[0]=v[6], aux[0]=0
            j++; //j=7
        }
    	k++; //k=1
    }
    
    2a execucao while:
    //while(0 <= 5 && 7 <= 10) true
    while(i <= meio && j <= fim)
    {
        if(v[i] <= v[j]) //v[0] <= v[7], 8 <= 1 false
        {
            aux[k] = v[i];
            i++;
        }
        else
        {
            aux[k] = v[j]; //aux[1]=v[7], aux[1]=1
            j++; //j=8
        }
    	k++; //k=2
    }
    
    3a execucao while:
    //while(0 <= 5 && 8 <= 10) true
    while(i <= meio && j <= fim)
    {
        if(v[i] <= v[j]) //v[0] <= v[8], 8 <= 4 false
        {
            aux[k] = v[i];
            i++;
        }
        else
        {
            aux[k] = v[j]; //aux[2]=v[8], aux[2]=4
            j++; //j=9
        }
    	k++; //k=3
    }
    
    4a execucao while:
    //while(0 <= 5 && 9 <= 10) true
    while(i <= meio && j <= fim)
    {
        if(v[i] <= v[j]) //v[0] <= v[9], 8 <= 5 false
        {
            aux[k] = v[i];
            i++;
        }
        else
        {
            aux[k] = v[j]; //aux[3]=v[9], aux[3]=5
            j++; //j=10
        }
    	k++; //k=4
    }
    
    5a execucao while:
    //while(0 <= 5 && 10 <= 10) true
    while(i <= meio && j <= fim)
    {
        if(v[i] <= v[j]) //v[0] <= v[10], 8 <= 11 true
        {
            aux[k] = v[i]; //aux[4]=v[0], aux[4]=8
            i++; //i=1
        }
        else
        {
            aux[k] = v[j];
            j++;
        }
    	k++; //k=5
    } 
    
    6a execucao while:
    //while(1 <= 5 && 10 <= 10) true
    while(i <= meio && j <= fim)
    {
        if(v[i] <= v[j]) //v[1] <= v[10], 14 <= 11 false
        {
            aux[k] = v[i];
            i++;
        }
        else
        {
            aux[k] = v[j]; //aux[5]=v[10], aux[5]=11
            j++; //j=11
        }
    	k++; //k=6
    }
    
    7a execucao while:
    //while(1 <= 5 && 11 <= 10) false
    
    
    
    
    
    
    
    
    
    while(i <= meio)
    {
        aux[k] = v[i];
        i++;
        k++;
    }
    
    1a execucao while:
    //while(1 <= 5) true
    while(i <= meio) {
        aux[k] = v[i]; //aux[6]=v[1], aux[6]=14
        i++; //i=2
        k++; //k=7
    }

    2a execucao while:
    //while(2 <= 5) true
    while(i <= meio) {
        aux[k] = v[i]; //aux[7]=v[2], aux[7]=17
        i++; //i=3
        k++; //k=8
    }
    
    3a execucao while:
    //while(3 <= 5) true
    while(i <= meio) {
        aux[k] = v[i]; //aux[8]=v[3], aux[8]=20
        i++; //i=4
        k++; //k=9
    }
    
    4a execucao while:
    //while(4 <= 5) true
    while(i <= meio) {
        aux[k] = v[i]; //aux[9]=v[4], aux[9]=31
        i++; //i=5
        k++; //k=10
    }
    
    5a execucao while:
    //while(5 <= 5) true
    while(i <= meio) {
        aux[k] = v[i]; //aux[10]=v[5], aux[10]=92
        i++; //i=6
        k++; //k=11
    }
    
    5a execucao while:
    //while(6 <= 5) false
    
    
    
    
    
    
    
    
    
    
    while(j<=fim)
    {
        aux[k] = v[j];
        j++;
        k++;
    }
    
    1a execucao while:
    //while(11 <= 10) false
    
    
    
    
    vetor aux[] esta assim: {0,1,4,5,8,11,14,17,20,31,92}
    
    
    
    
    
    for(i = 0; i< (fim - inicio)+1; i++) //copia valores do vetor auxiliar para o original
    {
        v[inicio + i] = aux[i];
    }
    
    1a execucao for:
    for(i = 0; i< (10 - 0)+1; i++)
    {
        v[0] = aux[0]; // v[0] = 0
    }
    
    2a execucao for:
    for(i = 1; i< (10 - 0)+1; i++)
    {
        v[1] = aux[1]; // v[1] = 1
    }
    
    3a execucao for:
    for(i = 2; i< (10 - 0)+1; i++)
    {
        v[2] = aux[2]; // v[2] = 4
    }
    
    4a execucao for:
    for(i = 3; i< (10 - 0)+1; i++)
    {
        v[3] = aux[3]; // v[3] = 5
    }
    
    5a execucao for:
    for(i = 4; i< (10 - 0)+1; i++)
    {
        v[4] = aux[4]; // v[4] = 8
    }
    
    5a execucao for:
    for(i = 5; i< (10 - 0)+1; i++)
    {
        v[5] = aux[5]; // v[5] = 11
    }
    
    6a execucao for:
    for(i = 6; i< (10 - 0)+1; i++)
    {
        v[6] = aux[6]; // v[6] = 14
    }
    
    7a execucao for:
    for(i = 7; i< (10 - 0)+1; i++)
    {
        v[7] = aux[7]; // v[7] = 17
    }
    
    8a execucao for:
    for(i = 8; i< (10 - 0)+1; i++)
    {
        v[8] = aux[8]; // v[8] = 20
    }
    
    9a execucao for:
    for(i = 9; i< (10 - 0)+1; i++)
    {
        v[9] = aux[9]; // v[9] = 31
    }
    
    10a execucao for:
    for(i = 10; i< (10 - 0)+1; i++)
    {
        v[10] = aux[10]; // v[10] = 92
    }
    
    11a execucao i=11 sai do loop
    AO FINAL O VETOR ESTA ORDENADO 0,1,4,5,8,11,14,17,20,31,92
}
       
*/
