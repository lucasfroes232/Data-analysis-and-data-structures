#include <stdbool.h>
typedef struct List{
	int info;
	struct List* next;
}List;

typedef struct stack{
	   List* top;
}Stack;

//cheia
bool fullStack(Stack* S){
	return false;
}
//vazia
bool emptyStack(Stack* S){
	bool aux=true;
	if(S->top->next != NULL) aux = false;
	return aux; 
}
//criar
void create (Stack* S){
	S->top = (List*)malloc(sizeof(List));
	if(S->top == NULL){
		printf("Memory Allocation Failed");
		exit(1);
	}
	S->top->next = NULL;
	S->top->info = -1;
};
//add
void push(Stack* S,int inf,bool *ok){
	if(fullStack(S)) ok = false;
	else{
		List* aux = (List*)malloc(sizeof(List));
		if(aux == NULL){
			printf("Memory Allocation Failed");
			exit(1);
		}
		aux->info = inf;
		aux->next = S->top;
		S->top = aux;
		ok = true;	
	}
}
//remover
void pop(Stack* S,int *inf,bool *ok){
	List* aux;
	if(emptyStack(S)) ok=false;
	else{
		*inf = S->top->info;
		aux = S->top;
		S->top = S->top->next;
		free(aux);
		ok = true;
	}
}
void printStack(Stack* S) {
    List* aux = S->top;
    printf("Stack: ");
    while (aux != NULL) {
        printf("%d ", aux->info);
        aux = aux->next;
    }
    printf("\n");
}

