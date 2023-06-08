#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_MAXIMO 10
struct queue
{
int itens[TAMANHO_MAXIMO];
int front,rear;
};

int empty(struct queue * pq)
{
if( pq->front == pq->rear )
{
return 1;
}
return 0;
}
void enqueue(struct queue * pq, int x)
{
/* Inversão das posições dos ponteiros. Se o inal do vetor já foi
alcançado, então retorna-se ao início do vetor */
if( pq->rear == TAMANHO_MAXIMO-1)
{
pq->rear = 0;
}
else
{
pq->rear++;
}
if( pq->rear == pq->front )
{
printf("\nEstouro da ila");
exit(1);
}
pq->itens[pq->rear] = x;
return;
}
int size(struct queue * pq)
{
/* se o inal da ila ainda não alcançou o inal do vetor... */

if( pq->front <= pq->rear)
{
return pq->rear - pq->front; /* ... então o tamanho da ila é o inal
da ila menos o início da ila... */
}
/* ... se não, quer dizer que o ponteiro de inal da ila já alcançou o inal do vetor
e foi reposicionado para o início do vetor, então o tamanho da ila é a quantidade
de itens que ainda restam até chegar ao inal do vetor somando itens que estão
no início do vetor */
return pq->rear + pq->front;
}

int front(struct queue * pq)
{
return pq->itens[pq->front+1];
}
int dequeue(struct queue * pq)
{
int x, i;
if( empty(pq) )
{
printf("\nFila vazia");
exit(1);
}
/* Inversão das posições dos ponteiros. Se o inal do vetor já foi alcançado,
então retorna-se ao início do vetor */
if( pq->front == TAMANHO_MAXIMO - 1)
{
pq->front = 0;
}
else
{
pq->front++;
}
return (pq->itens[ pq->front ]);
}
int main(void)
{
struct queue q;
q.front = -1;
q.rear = -1;

enqueue(&q,1);
enqueue(&q,2);
enqueue(&q,3);
enqueue(&q,4);
enqueue(&q,5);
enqueue(&q,6);
enqueue(&q,7);
enqueue(&q,8);
enqueue(&q,9);

printf("\nTamanho da ila %d", size(&q));
printf("\nProximo da ila %d", front(&q));
printf("\nTirando da ila %d", dequeue(&q));
printf("\nTirando da ila %d", dequeue(&q));
printf("\nTirando da ila %d", dequeue(&q));

printf("\nProximo da ila %d", front(&q));
printf("\nTirando da ila %d", dequeue(&q));
printf("\nTamanho da ila %d", size(&q));

enqueue(&q,10);
enqueue(&q,11);
enqueue(&q,12);

printf("\nTamanho da ila %d", size(&q));
printf("\nProximo da ila %d", front(&q));

enqueue(&q,13);

printf("\nTirando da ila %d", dequeue(&q));

enqueue(&q,67);

printf("\nTamanho da ila %d", size(&q));

/*enqueue(&q,1);
enqueue(&q,2);
enqueue(&q,3);
enqueue(&q,4);

printf("\nTamanho da ila %d", size(&q));
printf("\nProximo da ila %d", front(&q));
printf("\nTirando da ila %d", dequeue(&q));
printf("\nTirando da ila %d", dequeue(&q));
printf("\nTirando da ila %d", dequeue(&q));
printf("\nProximo da ila %d", front(&q));
printf("\nTirando da ila %d", dequeue(&q));
printf("\nTamanho da ila %d", size(&q));
enqueue(&q,5);
enqueue(&q,6);
enqueue(&q,7);
enqueue(&q,8);
enqueue(&q,9);
printf("\nTamanho da ila %d", size(&q));
printf("\nProximo da ila %d", front(&q));
printf("\nTirando da ila %d", dequeue(&q));
printf("\nTirando da ila %d", dequeue(&q));
printf("\nTirando da ila %d", dequeue(&q));
printf("\nTirando da ila %d", dequeue(&q));
printf("\nProximo da ila %d", front(&q));
printf("\nTirando da ila %d", dequeue(&q));
printf("\nTamanho da ila %d", size(&q));
enqueue(&q,10);
enqueue(&q,11);
enqueue(&q,12);
enqueue(&q,13);
enqueue(&q,14);
enqueue(&q,15);
enqueue(&q,16);
enqueue(&q,17);
enqueue(&q,18);
printf("\nTamanho da ila %d", size(&q));
printf("\nProximo da ila %d", front(&q));
printf("\nTirando da ila %d", dequeue(&q));
printf("\nTirando da ila %d", dequeue(&q));
printf("\nTirando da ila %d", dequeue(&q));
printf("\nTirando da ila %d", dequeue(&q));
printf("\nTirando da ila %d", dequeue(&q));
printf("\nProximo da ila %d", front(&q));
printf("\nTirando da ila %d", dequeue(&q));
printf("\nTirando da ila %d", dequeue(&q));
printf("\nTirando da ila %d", dequeue(&q));
printf("\nTamanho da ila %d", size(&q));
printf("\nTirando da ila %d", dequeue(&q));
printf("\nTamanho da ila %d", size(&q));

printf("\nFila vazia %d", empty(&q));

enqueue(&q,20);
enqueue(&q,21);
enqueue(&q,22);
enqueue(&q,23);
enqueue(&q,24);
enqueue(&q,25);
printf("\nTamanho da ila %d", size(&q));
printf("\nProximo da ila %d", front(&q));
printf("\nTirando da ila %d", dequeue(&q));
printf("\nProximo da ila %d", front(&q));
printf("\nTirando da ila %d", dequeue(&q));

printf("\nTirando da ila %d", dequeue(&q));
printf("\nTirando da ila %d", dequeue(&q));
printf("\nTamanho da ila %d", size(&q));
printf("\nTirando da ila %d", dequeue(&q));
printf("\nTamanho da ila %d", size(&q));
printf("\nTirando da ila %d", dequeue(&q));
printf("\nTamanho da ila %d", size(&q));

printf("\nFila vazia %d", empty(&q));*/

printf("\n");
return 0;
}

