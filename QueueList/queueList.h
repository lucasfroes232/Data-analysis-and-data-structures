#include <stdbool.h>
#include <stdlib.h>
 typedef struct List
{
    int info;
    struct List* next;
}List;



typedef struct Queue
{
        List *first;
        List *last;
}Queue;


//full
bool fullQueue(Queue *q){

    return false;
}

//empty
bool emptyQueue(Queue *q){
    bool empty = false;
    if( q->first == NULL){
        empty = true;
    }
    return empty;
}

//create
void createQueue(Queue *q){
    q->first = NULL;
    q->last  = NULL;
}

//add
void pushQueue(Queue *q,int inf,bool *ok){
    if (fullQueue(q))   *ok = false;
    else{
        List *aux = (List*)malloc(sizeof(List));
        aux->next = NULL;
        aux->info = inf;
        if(emptyQueue(q)){
            q->first = aux;
            q->last = aux;
        }else{
            q->last->next = aux;
            q->last = aux;
        }
        *ok = true;
        
    }
}

//remove
void popQueue(Queue *q,int* inf,bool *ok){
    if(emptyQueue(q)) ok = false;
    else{
        List *aux;
        *inf = q->first->info;
        aux = q->first;
        q->first = q->first->next;
        free(aux);
        *ok = true;
    }

}
void printQueue(Queue *q){
    List *aux = q->first;
    printf("Queue: ");
    while(aux != NULL){
        printf("%d ",aux->info);
        aux = aux->next;
    }
    printf("\n");

}
