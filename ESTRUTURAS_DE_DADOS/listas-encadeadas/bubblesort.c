// C program to sort Linked List
// using Bubble Sort
// by swapping nodes
 
#include <stdio.h>
#include <stdlib.h>
 


/* structure for a node */
struct Node {
    int data;
    struct Node* next;
} Node;
 
 
 
/*Function to swap the nodes */
struct Node* swap(struct Node* ptr1, struct Node* ptr2)
{
    struct Node* tmp = ptr2->next;
    
    ptr2->next = ptr1;
    ptr1->next = tmp;
    
    printf("ptr1: %x\n",ptr1);
    printf("ptr1->next: %x\n",ptr1->next);
    printf("ptr2: %x\n",ptr2);
    printf("ptr2->next: %x\n",ptr2->next);
   
    return ptr2;
}
 
 
 
/* Function to print the list */
void printList(struct Node* n)
{
    while (n != NULL) {
        printf("end: %x, valor: %d, prox: %x\n", n,n->data,n->next);
        n = n->next;
    }
    printf("\n");
}
 
 
 
/* Function to sort the list */
int bubbleSort(struct Node** head, int count){
    struct Node** h;
    int i, j, swapped;
 
    for (i=0; i<=count; i++) {
        h = head;
        swapped = 0;
        //printf("***h: %x, ***head: %x\n",*h,*head);
 
        for (j=0; j<count-i-1; j++) {
            struct Node* p1 = *h;
            struct Node* p2 = p1->next;
 
            if (p1->data > p2->data) {
                /* update the link after swapping */
                printf("trocando %d com %d\n",p1->data,p2->data);
                printf("*h: %x, *head: %x\n",*h,*head);
                
                *h = swap(p1, p2);
                
                printf("*h: %x, *head: %x\n",*h,*head);
                
                swapped = 1;
            }
 
            h = &(*h)->next;
            
            printf("lista apos troca:\n");
            printList(*head);
            
            printf("*h: %x, *head: %x\n\n\n",*h,*head);
        }
 
        /* break if the loop ended without any swap */
        if (swapped == 0){
            break;
        }
    }
}
 

 
void inserir_fim(struct Node** start_ref, int data)
{
	struct Node *iterator;
    struct Node* ptr1
        = (struct Node*)malloc(sizeof(struct Node));
 
 
    ptr1->data = data;
    ptr1->next = NULL;
 
 	if(*start_ref==NULL){
 		*start_ref=ptr1;
 	}
 	else{
 		iterator=*start_ref;
 		
 		while(iterator->next!=NULL){
 			iterator=iterator->next;
 		}
 		
 		iterator->next=ptr1;
 	}
}
 
 
int main(){
    int arr[] = { 60, 7, 30, 4, 10 };
    int list_size, i;
 
    /* start with empty linked list */
    struct Node* start = NULL;
    list_size = sizeof(arr) / sizeof(arr[0]);
 
    
    /* Create linked list from the array arr[] */
    for (i = 0; i < list_size; i++){
        inserir_fim(&start, arr[i]);
 	}
 	
 	printf("inicio: %x\n",start);
 	
    /* print list before sorting */	
    printf("Linked list before sorting\n");
    printList(start);
 
    /* sort the linked list */
    bubbleSort(&start, list_size);
 
 	printf("inicio: %x\n",start);
 	
    /* print list after sorting */
    printf("Linked list after sorting\n");
    printList(start);
 
    return 0;
}
