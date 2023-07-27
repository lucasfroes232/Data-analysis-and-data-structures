/******************************************************************************
*******************************************************************************/

//BIbliotecas
#include <stdio.h>
#include "Pilha.h"

//Prototipos
void mostraPilha(tPilha);
int main()
{   
    //variaveis locais
    tPilha pilha;
    int flag;
    int elemento;
    
    //cria pilha teste
    cria(&pilha);
    
    //inicia variavel para teste de funcoes
    elemento = 1;
    
    //testes das funcoes
    if(vazia(&pilha) == 1)
        printf("Vazio");
        
    if(cheio(&pilha) == 1)
        printf("Cheio");
        
    empilha(&pilha,elemento,&flag);
    if(flag==1)
        printf("empilhou\n");
    
    mostraPilha(pilha);
    topoPilha(pilha);
    
    desempilha(&pilha,elemento,&flag);
    if(flag==1)
        printf("desempilhou\n");
    return 0;
}

//mostra elementos
void mostraPilha(tPilha p){
    for(int i=0;i<p.topo;i++){
        printf("%d\n",p.elementos[i]);
    }
}

//consulta topo da pilha
void topoPilha(tPilha p ){
    printf("elemento no topo: %d\n",p.topo);
}
