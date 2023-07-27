#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

int main(){
    ArvAvl *avl;//ponteiro p ponteir
    int N = 3, dados[3] = {9,5,7};
    int res;
    avl = cria_ArvAVL();
    
    printf("Inserindo os valores 9,5 e 7...\n");
    for(int i = 0;i<N;i++){
        res = insereAvl(avl,dados[i]);
    }

    printf("===AVL===\n");
    preOrdem_ArvAVL(avl);
    printf("\n");
    
    if(consultaAvl(avl,5)==1){
        printf("5 Esta na arvore\n");
    }
    printf("\n");
    printf("Removendo 5...\n");
    removeAvl(avl,5);
    printf("===AVL===\n");
    preOrdem_ArvAVL(avl);
    printf("\n");
    
    
}
