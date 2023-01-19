#include <stdio.h>
#include <stdlib.h>

// Creating structure
struct Node{
  int data;
  struct Node *next;
};

// Add new node at end of linked list
void insert(struct Node **head, int value){
    // Create dynamic node
    struct Node *node = (struct Node *) malloc (sizeof (struct Node));
    if (node == NULL){
        // checking memory overflow
        printf ("Memory overflow\n");
    }
    else{
        node->data = value;
        node->next = NULL;
        
        if (*head == NULL)
            *head = node;
            
        else{
	        struct Node *temp = *head;

	        // finding last node
	        while (temp->next != NULL){
	            temp = temp->next;
	        }

	        // adding node at last position
	        temp->next = node;
	    }
    }
}

// Displaying linked list element
void display(struct Node *head){
    if (head == NULL){
      printf ("Empty linked list");
      return;
    }
  
    struct Node *temp = head;
    printf ("\n Linked List :");
    
    while (temp != NULL){
        printf (" %d", temp->data);
        temp = temp->next;
    }
}

// Finding last node of linked list
struct Node *last_node(struct Node *head){
    struct Node *temp = head;
    while(temp != NULL && temp->next != NULL){
        temp = temp->next;
    }
    return temp;
}

// We are Setting the given last node position to its proper
// position
struct Node *partition(struct Node *first, struct Node *last){
    printf ("\nfirst %d, last %d", first->data, last->data);

    // Get first node of given linked list
    struct Node *pivot = first;
    struct Node *front = first;
    int temp = 0;
    while (front != NULL && front != last){
        printf ("\n\tfront->data %d, last->data %d", front->data, last->data);
        
        if (front->data < last->data){
	        pivot = first;

    	    printf ("\n\t\tpivot %d", pivot->data);
    
    	    // Swapping node values
    	    temp = first->data;
    	    first->data = front->data;
    	    front->data = temp;

	        printf ("\n\t\tfront->data %d, first->data %d", front->data,first->data);

	        // Visiting the next node
	        first = first->next;

	        printf ("\n\t\tfirst->data %d", first->data);
	        //printf("\n %d jjjgg",pivot->data);
	    }

        // Visiting the next node
        front = front->next;
        printf ("\n\tfront->data %d\n", front->data);
        //printf("\n%d ppp",pivot->data);

    }

    // Change last node value to current node
    temp = first->data;
    first->data = last->data;
    last->data = temp;
    
    printf ("\nfirst->data %d", first->data);
    printf ("\n%d ff", pivot->data);
    return pivot;
}

// Performing quick sort in the given linked list
void quick_sort (struct Node *first, struct Node *last){
    if(first == last)return;

    struct Node *pivot = partition(first, last);
    display (first);

    if (pivot != NULL && pivot->next != NULL){
        printf ("\t1111");
        quick_sort(pivot->next, last);
    }

    if (pivot != NULL && first != pivot){
        printf ("\t2222");
        quick_sort(first, pivot);
    }
}

// Driver's code
int main(){
    struct Node *head = NULL;

    // Create linked list
    insert(&head, 41);
    insert(&head, 5);
    insert(&head, 7);
    insert(&head, 22);
    insert(&head, 28);
    insert(&head, 63);
    insert(&head, 4);
    insert(&head, 8);
    insert(&head, 2);
    insert(&head, 11);
    printf("\n Before Sort ");
    display(head);

    // Function call
    quick_sort(head, last_node(head));
    printf("\n After Sort ");
    display(head);
    return 0;
}




/*
lista: 41 5 7 22 28 63 4 8 2 11

1a execucao quick_sort:
quick_sort(41,11)
    if first == last false
    
    pivot = partition(41,11)
        
        partition(41,11)
            pivot = 41
            front = 41
            first = 41
            last = 11
            while(front != NULL && front != last)
                if (front->data < last->data) //41 < 11 false
                front = front->next; //front = 5
                
                if (front->data < last->data) 5 < 11 true
                    pivot = 41
                    
                    //acontece apenas uma troca de valores, os apontementos de *prox nao sao mexidos
                    
                    first = 5
                    front = 41
                    
                    pivot = 5, pois ele guarda o endereco de first, e a propriedade data dele foi trocada entao como pivot aponta pro endereco de first ele tbm vera a mudanca
                    
                    first = first->next; //first = 41
                    
                front = front->next; //front = 7
                
                //lista ao final da iteracao: 5,41,7,22,28,63,4,8,2,11
                
                if (front->data < last->data) 7 < 11 true
                    pivot = 41
                    
                    //troca apenas os valores de 41 com 7, os apontementos nao troca
                    
                    first = 7
                    front = 41
                    
                    pivot = 7, pois ele guarda o endereco de first, e a propriedade data dele foi trocada entao como pivot aponta pro endereco de first ele tbm vera a mudanca
                    
                    first = first->next; //first = 41
                    
                front = front->next; //front = 22
                
                //lista ao final da iteracao: 5,7,41,22,28,63,4,8,2,11
                
                
                if (front->data < last->data) 22 < 11 false
                front = front->next; //front = 28
                //lista ao final da iteracao: 5,7,41,22,28,63,4,8,2,11
                
                if (front->data < last->data) 28 < 11 false
                front = front->next; //front = 63
                //lista ao final da iteracao: 5,7,41,22,28,63,4,8,2,11
                
                if (front->data < last->data) 63 < 11 false
                front = front->next; //front = 4
                //lista ao final da iteracao: 5,7,41,22,28,63,4,8,2,11
                
                
                if (front->data < last->data) 4 < 11 true
                    pivot = 41
                    
                    //troca apenas os valores de 41 com 4, os apontementos nao troca
                    
                    first = 4
                    front = 41
                    
                    pivot = 4, pois ele guarda o endereco de first, e a propriedade data dele foi trocada entao como pivot aponta pro endereco de first ele tbm vera a mudanca

                    first = first->next; //first = 22
                    
                front = front->next; //front = 8
                
                //lista ao final da iteracao: 5,7,4,22,28,63,41,8,2,11
                
                
                if (front->data < last->data) 8 < 11 true
                    pivot = 22
                    
                    first = 8
                    front = 22
                    
                    pivot = 8, pois ele guarda o endereco de first, e a propriedade data dele foi trocada entao como pivot aponta pro endereco de first ele tbm vera a mudanca

                    first = first->next; //first = 28
                    
                front = front->next; //front = 2
                
                //lista ao final da iteracao: 5,7,4,8,28,63,41,22,2,11
                
                
                if (front->data < last->data) 2 < 11 true
                    pivot = 28
                    
                    first = 2
                    front = 28
                    
                    pivot = 2, pois ele guarda o endereco de first, e a propriedade data dele foi trocada entao como pivot aponta pro endereco de first ele tbm vera a mudanca
                    
                    first = first->next; //first = 63
                    
                front = front->next; //front = 11
                
                //lista ao final da iteracao: 5,7,4,8,2,63,41,22,28,11
                
            front = last; sai do while
            first = last //first = 11
            last = first //last = 63
        return pivot; return 2
        //lista ao final da chamada a funcao: 5,7,4,8,2,11,41,22,28,63
                
                
                
    volta pra 1a execucao:
    
    if (pivot != NULL && pivot->next != NULL) true
    
    
    --------------------------------------------------------------------------------
    
    
    2a execucao quick_sort:
    quick_sort(11, 63);
    
    if (first == last) false
    
	    partition(11, 63)
	        pivot = 11
            front = 11
            first = 11
            last = 63
            while(front != NULL && front != last)
            
                if (front->data < last->data) //11 < 63 true
                    pivot = 11
                    
                    //acontece apenas uma troca de valores, os apontementos de *prox nao sao mexidos
                    
                    first = 11
                    front = 11
                    
                    pivot = 11, pois ele guarda o endereco de first, e a propriedade data dele foi trocada entao como pivot aponta pro endereco de first ele tbm vera a mudanca
                    
                    first = first->next; //first = 41
                    
                front = front->next; //front = 41
                
                //lista ao final da chamada a funcao: 5,7,4,8,2,11,41,22,28,63
                
                
                if (front->data < last->data) 41 < 63 true
                    pivot = 41
                    
                    //acontece apenas uma troca de valores, os apontementos de *prox nao sao mexidos
                    
                    first = 41
                    front = 41
                    
                    pivot = 41, pois ele guarda o endereco de first, e a propriedade data dele foi trocada entao como pivot aponta pro endereco de first ele tbm vera a mudanca
                    
                    first = first->next; //first = 22
                    
                front = front->next; //front = 22
                //lista ao final da chamada a funcao: 5,7,4,8,2,11,41,22,28,63
                
                
                
                if (front->data < last->data) 22 < 63 true
                    pivot = 22
                    
                    //acontece apenas uma troca de valores, os apontementos de *prox nao sao mexidos
                    
                    first = 22
                    front = 22
                    
                    pivot = 22, pois ele guarda o endereco de first, e a propriedade data dele foi trocada entao como pivot aponta pro endereco de first ele tbm vera a mudanca
                    
                    first = first->next; //first = 28
                    
                front = front->next; //front = 28
                //lista ao final da chamada a funcao: 5,7,4,8,2,11,41,22,28,63
                
                
                if (front->data < last->data) 28 < 63 true
                    pivot = 28
                    
                    //acontece apenas uma troca de valores, os apontementos de *prox nao sao mexidos
                    
                    first = 28
                    front = 28
                    
                    pivot = 28, pois ele guarda o endereco de first, e a propriedade data dele foi trocada entao como pivot aponta pro endereco de first ele tbm vera a mudanca
                    
                    first = first->next; //first = 63
                    
                front = front->next; //front = 63
                //lista ao final da chamada a funcao: 5,7,4,8,2,11,41,22,28,63
                
                
            front = last; sai do while
            first = last //first = 63
            last = first //last = 28
        return pivot; return 28
        //lista ao final da chamada a funcao: 5,7,4,8,2,11,41,22,28,63
        
        
    volta pra 2a execucao:
    if (pivot != NULL && pivot->next != NULL) true
    
    
    
    --------------------------------------------------------------------------------
    
    
    
    3a execucao quick_sort:
    quick_sort(28, 28);
    
    if (first == last) true return execucao anterior (2a)
    
    
    
    --------------------------------------------------------------------------------
    
    
    
    continuacao 2a execucao:
    
    entra no segundo if
    if (pivot != NULL && first != pivot) true
    
    
    
    --------------------------------------------------------------------------------
    
    
    
    4a execucao quick_sort:
    quick_sort(11, 28);
    
    if (first == last) false
    
	    partition(11, 28)
	        pivot = 11
            front = 11
            first = 11
            last = 28
            while(front != NULL && front != last)
            
                if (front->data < last->data) //11 < 28 true
                    pivot = 11
                    
                    //acontece apenas uma troca de valores, os apontementos de *prox nao sao mexidos
                    
                    first = 11
                    front = 11
                    
                    pivot = 11, pois ele guarda o endereco de first, e a propriedade data dele foi trocada entao como pivot aponta pro endereco de first ele tbm vera a mudanca
                    
                    first = first->next; //first = 41
                    
                front = front->next; //front = 41
                
                //lista ao final da chamada a funcao: 5,7,4,8,2,11,41,22,28,63
                
                
                if (front->data < last->data) 41 < 28 true
                front = front->next; //front = 22    
                //lista ao final da chamada a funcao: 5,7,4,8,2,11,41,22,28,63
                
                
                
                if (front->data < last->data) 22 < 28 true
                    pivot = 41
                    
                    //acontece apenas uma troca de valores, os apontementos de *prox nao sao mexidos
                    
                    first = 22
                    front = 41
                    
                    pivot = 22, pois ele guarda o endereco de first, e a propriedade data dele foi trocada entao como pivot aponta pro endereco de first ele tbm vera a mudanca
                    
                    first = first->next; //first = 41
                    
                front = front->next; //front = 28
                //lista ao final da chamada a funcao: 5,7,4,8,2,11,22,41,28,63
                
            front = last; sai do while
            first = last //first = 28
            last = first //last = 41
        return pivot; return 22
        //lista ao final da chamada a funcao: 5,7,4,8,2,11,22,28,41,63
        
        
        volta pra 4a execucao:
        if (pivot != NULL && pivot->next != NULL) true
        
        
        
        --------------------------------------------------------------------------------
        
        
        
        5a execucao quick_sort:
        quick_sort(28, 41);  //last eh 41 pois foi alterado na linha 488, alteracoes numa propriedade dum ponteiro e nao diretamente na variavel refletem fora da funC'C#o
        
        if (first == last) false
        
            partition(28, 41)
	        pivot = 28
            front = 28
            first = 28
            last = 41
            while(front != NULL && front != last)
            
                if (front->data < last->data) //28 < 41 true
                    pivot = 28
                    
                    //acontece apenas uma troca de valores, os apontementos de *prox nao sao mexidos
                    
                    first = 28
                    front = 28
                    
                    pivot = 28, pois ele guarda o endereco de first, e a propriedade data dele foi trocada entao como pivot aponta pro endereco de first ele tbm vera a mudanca
                    
                    first = first->next; //first = 41
                    
                front = front->next; //front = 41
                
                //lista ao final da chamada a funcao: 5,7,4,8,2,11,22,28,41,63
                
            front = last; sai do while
            first = last //first = 41
            last = first //last = 41
            return pivot; return 28
            //lista ao final da chamada a funcao: 5,7,4,8,2,11,22,28,41,63
        
        volta pra 5a execucao:
        if (pivot != NULL && pivot->next != NULL) true
        
        
        
        --------------------------------------------------------------------------------
        
        
        
        6a execucao quick_sort:
        quick_sort(41, 41);  //last eh 41 pois foi alterado na linha 532, alteracoes numa propriedade dum ponteiro e nao diretamente na variavel refletem fora da funcao
        
        if (first == last) true return execucao anterior (5a)
        
        
        
        --------------------------------------------------------------------------------
        
        
        
        
        continuacao 5a execucao:
    
        segundo if
        if (pivot != NULL && first != pivot) false //first = 28 pivot = 28
        return execucao anterior (4a)
        
        
        
        
        --------------------------------------------------------------------------------
        
        
        
        
        continuacao 4a execucao:
        entra no segundo if
        if (pivot != NULL && first != pivot) true //first = 11 pivot = 22
        
        
        
        --------------------------------------------------------------------------------
        
        
        
        7a execucao quick_sort:
        quick_sort(11, 22);
        
        if (first == last) false
        
            partition(11, 22)
    	        pivot = 11
                front = 11
                first = 11
                last = 22
                while(front != NULL && front != last)
                
                    if (front->data < last->data) //11 < 22 true
                        pivot = 11
                        
                        //acontece apenas uma troca de valores, os apontementos de *prox nao sao mexidos
                        
                        first = 11
                        front = 11
                        
                        pivot = 11, pois ele guarda o endereco de first, e a propriedade data dele foi trocada entao como pivot aponta pro endereco de first ele tbm vera a mudanca
                        
                        first = first->next; //first = 22
                        
                    front = front->next; //front = 22
                    
                    //lista ao final da chamada a funcao: 5,7,4,8,2,11,22,28,41,63
                    
                front = last; sai do while
                first = last //first = 22
                last = first //last = 22
            return pivot; return 11
            //lista ao final da chamada a funcao: 5,7,4,8,2,11,22,28,41,63
            
            
        volta pra 4a execucao:
        encerra 4a execucao e volta pra execucao anterior (2a)
        
        
        
        --------------------------------------------------------------------------------
        
        
        
        continuacao 2a execucao:
        encerra 2a execucao e volta pra execucao anterior (1a)
        
        
        
        --------------------------------------------------------------------------------
        
        
        
        
        continuacao 1a execucao:
    
        entra no segundo if
        if (pivot != NULL && first != pivot) true
        
        
        
        
        --------------------------------------------------------------------------------
        
        
        8a execucao quick_sort:
        quick_sort (first, pivot); //quick_sort(5,2) o first no inicio da primeira execucao era 41 mas nas recursoes seguintes esse valor foi alterado e vale 5 no momento

        if (first == last) false
        
            partition(5, 2)
    	        pivot = 5
                front = 5
                first = 5
                last = 2
                while(front != NULL && front != last)
                
                    if (front->data < last->data) //5 < 2 false
                    front = front->next; //front = 7
                    //lista ao final da chamada a funcao: 5,7,4,8,2,11,22,28,41,63
                    
                    if (front->data < last->data) //7 < 2 false
                    front = front->next; //front = 4
                    //lista ao final da chamada a funcao: 5,7,4,8,2,11,22,28,41,63
                    
                    if (front->data < last->data) //4 < 2 false
                    front = front->next; //front = 8
                    //lista ao final da chamada a funcao: 5,7,4,8,2,11,22,28,41,63
                    
                    if (front->data < last->data) //8 < 2 false
                    front = front->next; //front = 2
                    //lista ao final da chamada a funcao: 5,7,4,8,2,11,22,28,41,63
                    
                front = last; sai do while
                first = last //first = 2 ,essa alteracao em first reflete em pivot pois first nao passou a apontar pro prox dele em nenhum momento durante a execucao da funcao
                last = first //last = 5
            return pivot; return 2
            //lista ao final da chamada a funcao: 2,7,4,8,5,11,22,28,41,63
            
            
        volta pra 8a execucao:
        if (pivot != NULL && pivot->next != NULL) true
                
              
                
        
        --------------------------------------------------------------------------------
        
        
        
        
        9a execucao quick_sort:
        quick_sort(7,5)

        if (first == last) false
    
	    partition(7, 5)
	        pivot = 7
            front = 7
            first = 7
            last = 5
            
            while(front != NULL && front != last)
            
                if (front->data < last->data) 7 < 5 true
                front = front->next; //front = 4    
                //lista ao final da chamada a funcao: 2,7,4,8,5,11,22,28,41,63
                
                
                if (front->data < last->data) 4 < 5 true
                    pivot = 7
                    
                    //acontece apenas uma troca de valores, os apontementos de *prox nao sao mexidos
                    
                    first = 4
                    front = 7
                    
                    pivot = 4, pois ele guarda o endereco de first, e a propriedade data dele foi trocada entao como pivot aponta pro endereco de first ele tbm vera a mudanca
                    
                    first = first->next; //first = 7
                    
                front = front->next; //front = 8
                //lista ao final da chamada a funcao: 2,4,7,8,5,11,22,41,28,63
                
                
                if (front->data < last->data) 8 < 5 false
                front = front->next; //front = 5    
                //lista ao final da chamada a funcao: 2,4,7,8,5,11,22,41,28,63
                
                
            front = last; sai do while
            first = last //first = 5
            last = first //last = 7
        return pivot; return 4
        //lista ao final da chamada a funcao: 2,4,5,8,7,11,22,41,28,63
        
        
        volta pra 9a execucao:
        if (pivot != NULL && pivot->next != NULL) true
        
        
        
        
        --------------------------------------------------------------------------------
        
        
        
        
        10a execucao quick_sort:
        quick_sort(5,7)
        
        if (first == last) false
        
        partition(5, 7)
	        pivot = 5
            front = 5
            first = 5
            last = 7
            
            while(front != NULL && front != last)
            
                if (front->data < last->data) 5 < 7 true
                    pivot = 5
                    
                    //acontece apenas uma troca de valores, os apontementos de *prox nao sao mexidos
                    
                    first = 5
                    front = 5
                    
                    pivot = 4, pois ele guarda o endereco de first, e a propriedade data dele foi trocada entao como pivot aponta pro endereco de first ele tbm vera a mudanca
                    
                    first = first->next; //first = 8
                    
                front = front->next; //front = 8
                //lista ao final da chamada a funcao: 2,4,5,8,7,11,22,41,28,63
                
                
                if (front->data < last->data) 8 < 7 false
                front = front->next; //front = 7    
                //lista ao final da chamada a funcao: 2,4,5,8,7,11,22,41,28,63
                
                
            front = last; sai do while
            first = last //first = 7
            last = first //last = 8
        return pivot; return 5
        //lista ao final da chamada a funcao: 2,4,5,7,8,11,22,41,28,63
        
        
        volta pra 10a execucao:
        if (pivot != NULL && pivot->next != NULL) true
        
        
        
        
        
        --------------------------------------------------------------------------------
        
        
        
        
        
        11a execucao quick_sort:
        quick_sort(7,8)
        
        if (first == last) false
        
        partition(7, 8)
            pivot = 7
            front = 7
            first = 7
            last = 8
            
            while(front != NULL && front != last)
            
                if (front->data < last->data) 7 < 8 true
                    pivot = 7
                    
                    //acontece apenas uma troca de valores, os apontementos de *prox nao sao mexidos
                    
                    first = 7
                    front = 7
                    
                    pivot = 7, pois ele guarda o endereco de first, e a propriedade data dele foi trocada entao como pivot aponta pro endereco de first ele tbm vera a mudanca
                    
                    first = first->next; //first = 8
                    
                front = front->next; //front = 8
                //lista ao final da chamada a funcao: 2,4,5,7,8,11,22,41,28,63
                
            front = last; sai do while
            first = last //first = 8
            last = first //last = 8
        return pivot; return 7
        //lista ao final da chamada a funcao: 2,4,5,7,8,11,22,41,28,63
        
        
        volta pra 11a execucao:
        if (pivot != NULL && pivot->next != NULL) true
        
        
        
        
        
        --------------------------------------------------------------------------------
        
        
        
        
        
        12a execucao quick_sort:
        quick_sort(8,8)
        
        if (first == last) true retorna pra 11a execucao
        
        
        
        
        
        --------------------------------------------------------------------------------
        
        
        
        
        continuacao 11a execucao:
    
        segundo if
        if (pivot != NULL && first != pivot) false first = 7, pivot = 7 retorna pra 10a execucao
        
        
        
        
        
        --------------------------------------------------------------------------------
        
        
        
        
        
        continuacao 10a execucao:
        segundo if
        if (pivot != NULL && first != pivot) false first = 5, pivot = 5 retorna pra 9a execucao
        
        
        
        
*/
