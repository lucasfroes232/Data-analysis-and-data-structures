/******************************************************************************
*******************************************************************************/
#include <stdio.h>
#include "Fila.h"
//prototipos
void trocar(tFila *,tFila *);
void mostrar(tFila);
int main()
{
    //variaveis locais
    tFila f1;
    tFila f2;
    int elem,deuCerto;

    //criar filas
    criar(&f1);
    criar(&f2);
    
    //testar se estão vazias
    if(vazia(&f1)){
        printf("fila F1 vazia\n");
    }
    if(vazia(&f2)){
        printf("fila F2 vazia\n");
    }
    
    //inserir
    inserir(&f1,1,&deuCerto);
    inserir(&f2,2,&deuCerto);
    //mostrar
    mostrar(f1);
    mostrar(f2);
    //trocar
    trocar(&f1,&f2);
    //mostrar dps de trocar
    mostrar(f1);
    mostrar(f2);
    //retirar
    retirar(&f1,&elem,&deuCerto);
    retirar(&f2,&elem,&deuCerto);
    //mostrar dps de retirar
    mostrar(f1);
    mostrar(f2);
    return 0;
}
//mostrar tFila
void mostrar(tFila f){
    int aux=0;
    int flag,elem;
    
    if(vazia(&f)==0){
        while(aux != f.nroElementos){
            retirar(&f,&elem,&flag);
            printf("elemento %d : %d\n",aux,elem);
            inserir(&f,elem,&flag);
            aux = aux + 1;
        }
    }else
        printf("vazio\n");
}
//trocar elementos de 2 filas
void trocar(tFila *f1,tFila *f2){
    int deuCerto,elem;
    tFila filaAux;
    while(vazia(&f1) != 1){
        retirar(&f1,&elem,&deuCerto);
        inserir(&filaAux,elem,&deuCerto);
    }
    while(vazia(&f2) != 1){
        retirar(&f2,&elem,&deuCerto);
        inserir(&f1,elem,&deuCerto);
    }
    while(vazia(&filaAux) != 1){
        retirar(&filaAux,&elem,&deuCerto);
        inserir(&f2,elem,&deuCerto);
    }
}
