#include <stdio.h>
#include <stdlib.h>
#include "StackList.h"
int main() {
    Stack minhaPilha;
    create(&minhaPilha);
    bool ok;
    int valor;

    // Testando empilhar e desempilhar
    push(&minhaPilha, 10, &ok);
    if (ok) {
        printf("Empilhamento bem-sucedido.\n");
    } else {
        printf("Falha ao empilhar.\n");
    }
		push(&minhaPilha, 20, &ok);
    printStack(&minhaPilha);

    pop(&minhaPilha, &valor, &ok);
    if (ok) {
        printf("Valor desempilhado: %d\n", valor);
    } else {
        printf("Falha ao desempilhar. Pilha vazia.\n");
    }
		printStack(&minhaPilha);
    return 0;
}
